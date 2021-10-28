//
// Created by Home on 10/28/2021.
//

#include "Polynomial.h"

//2 1 3 0 -> 0 * x^3 + 3 * x^2 + x + 2
//-->
//0 3 1 2

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree+1;
    this->coefficients = new double [degree+1];
    for(int i = 0; i < capacity; ++i){
        this->coefficients[i] = coefficients[degree-i];
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
    for(int i = capacity-1; i > 0; --i){
        if(coefficients[i] != 0){
            return i;
        }
    }
    return 0;
}

double Polynomial::evaluate(double x) const {
    int deg = this->degree();
    double result = this->coefficients[deg];
    for (int i = deg - 1; i >= 0; i--) {
        result = result * x + this->coefficients[i];
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    auto *mCoefficients = new double [this->degree() - 1];
    for(int i = 0, j = degree() - 1; i < degree() - 2; ++i, --j){
        mCoefficients[i] = coefficients[i] * j + coefficients[i+1];
    }
    return {degree()-1, mCoefficients};
}

double Polynomial::operator[](int index) const {
    return 0;
}

Polynomial operator-(const Polynomial &a) {
    return Polynomial(0, nullptr);
}

Polynomial operator +(const Polynomial &a, const Polynomial &b) {
    Polynomial result(max(a.degree(), b.degree()), nullptr);
    for (int i = 0; i < result.capacity; i++) {
        result.coefficients[i] = a[i] + b[i];
    }
    return result;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    return Polynomial(0, nullptr);
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    return Polynomial(0, nullptr);
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    return out;
}


