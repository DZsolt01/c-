//
// Created by Home on 10/28/2021.
//

#include "Polynomial.h"

//2 1 3 0 -> 0 * x^3 + 3 * x^2 + x + 2
//-->
//0 3 1 2

// 3 2 1
// 1 2 3

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree;
    this->coefficients = new double [degree];

    if(coefficients != nullptr){
        for(int i = 0; i < capacity; ++i){
            this->coefficients[i] = coefficients[degree - (i + 1)];
        }
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[this->capacity];
    for(int i = 0; i < capacity; ++i){
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete[] this->coefficients;
}

int Polynomial::degree() const {
    for(int i = capacity -1; i > 0; --i){
        if(coefficients[i] != 0){
            return i;
        }
    }
    return 0;
}
// 1 2 3 x^2 + 2x + 3 // 3 2 1
double Polynomial::evaluate(double x) const {
    int deg = this->degree();
    double result = this->coefficients[deg];
    for (int i = deg-1; i >= 0; i--) {
        result = result * x + this->coefficients[i];
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    auto *mCoefficients = new double [this->degree()];

    for(int i = degree(); i > 0; --i){
        mCoefficients[i-1] = coefficients[i] * i;
    }

    return {degree(), mCoefficients};
}

double Polynomial::operator[](int index) const {
    if(index < 0 || index > degree()){
        throw out_of_range("Nincs ilyen index!");
    }
    return coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    return Polynomial(0, nullptr);
}

Polynomial operator +(const Polynomial &a, const Polynomial &b) {
    Polynomial result (max(a.capacity, b.capacity), nullptr);

    for (int i = 0; i < result.capacity; i++) {
        if(a.degree() < i){
            result.coefficients[i] = b[i];
        }
        else if(b.degree() < i){
            result.coefficients[i] = a[i];
        }
        else{
            result.coefficients[i] = a[i] + b[i];
        }
    }
    return result;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial result (max(a.capacity, b.capacity), nullptr);

    for (int i = 0; i < result.capacity; i++) {
        if(a.degree() < i){
            result.coefficients[i] = -b[i];
        }
        else if(b.degree() < i){
            result.coefficients[i] = a[i];
        }
        else{
            result.coefficients[i] = a[i] - b[i];
        }
    }
    return result;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    Polynomial result (max(a.capacity, b.capacity), nullptr);

    for (int i = 0; i < result.capacity; i++) {
        if(a.degree() < i){
            result.coefficients[i] = b[i];
        }
        else if(b.degree() < i){
            result.coefficients[i] = a[i];
        }
        else{
            result.coefficients[i] = a[i] * b[i];
        }
    }
    return result;
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    what.printPolynomial(out);
    return out;
}

void Polynomial::printPolynomial(ostream & os) const {
    for(int i = degree(); i >= 0; --i){
        os << coefficients[i] << "*x^" << i  << " + ";
    }
    os << endl;
}


