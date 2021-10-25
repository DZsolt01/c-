#include "Matrix.h"
#include <ctime>

Matrix::Matrix(int rows, int cols){
    this->mRows = rows;
    this->mCols = cols;
    this->mElements = new double *[mRows];
    for(int i = 0; i < rows; ++i){
        this->mElements[i] = new double[cols];
    }
}

Matrix::~Matrix(){
    if(this->mElements != nullptr){
        for(int i = 0; i < mRows; ++i){ 
            delete[] mElements[i];
        }
    }

    delete[] mElements;
}

Matrix::Matrix(const Matrix &copy){
    this->mRows = copy.mRows;
    this->mCols = copy.mCols;
    this->mElements = new double *[mRows];
    for(int i = 0; i < mRows; ++i){ 
        mElements[i] = new double[mCols];
        for(int j = 0; j < mCols; ++j){
            mElements[i][j] = copy.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& what)
{
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
}

void Matrix::fillMatrix(double value){
    for(int i = 0; i < mRows; ++i){
        for(int j = 0; j < mCols; ++j){
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b){
    srand(time(nullptr));
    for(int i = 0; i < mRows; ++i){
        for(int j = 0; j < mCols; ++j){
            mElements[i][j] = rand() % (b - a) + a;
        }
    }
}

void Matrix::printMatrix(ostream &os) const{
    for(int i = 0; i < mRows; i++){
        for(int j = 0; j < mCols; ++j){
            if(j > 0){
                os << " ";
            }
            os << mElements[i][j];
        }
        os << endl;
    }
}

Matrix operator+(const Matrix &x, const Matrix &y){
    if(x.mRows != y.mRows || x.mCols != y.mCols){
        throw out_of_range("Nem osszeadhato matrixok");
    }
    Matrix result(x.mRows, x.mCols);
    for(int i = 0; i < result.mRows; ++i){
        for(int j = 0; j < result.mCols; ++j){
            result.mElements[i][j] = x[i][j] + y[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix &x, const Matrix &y){
    if(x.mRows != y.mCols){
        throw out_of_range("Nem megfelelo dimenziok!");
    }
    Matrix result(x.mRows, x.mCols);
    for(int i = 0; i < result.mRows; ++i){
        for(int j = 0; j < result.mCols; ++j){
            for(int k = 0; k < result.mCols; ++k){
                result.mElements[i][j] += x[i][k] * y[k][i];
            }
        }
    }
    return result;
}

ostream &operator<<(ostream &os, const Matrix &mat){
    mat.printMatrix(os);
    return os;
}
istream &operator>>(istream& is, Matrix& mat){
    for(int i = 0; i < mat.mRows; ++i){
        for(int j = 0; j < mat.mCols; ++j){
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

Matrix &Matrix::operator=(const Matrix &copy){
    if(mRows != copy.mRows || mCols != copy.mCols){
        throw out_of_range("Nem jok a dimenziok!");
    }
    if(this == &copy){
        return *this;
    }
    for(int i = 0; i < mRows; ++i){
        for(int j = 0; j < mCols; ++j){
            mElements[i][j] = copy.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&copy){
    if(mRows != copy.mRows || mCols != copy.mCols){
        throw out_of_range("Nem jok a dimenziok!");
    }
    if(this == &copy){
        return *this;
    }
    for(int i = 0; i < mRows; ++i){
        for(int j = 0; j < mCols; ++j){
            mElements[i][j] = copy.mElements[i][j];
        }
    }
    for(int i = 0; i < mRows; ++i){
        delete[] copy.mElements[i];
    }
    delete[] copy.mElements;
    copy.mRows = 0;
    copy.mCols = 0;

    return *this;
}
double *Matrix::operator[](int index){
    if(index < 0 || index >= mRows){
        throw out_of_range("Nem letezo index!");
    }
    return mElements[index];
}

double *Matrix::operator[](int index) const{
    if(index < 0 || index >= mRows){
        throw out_of_range("Nem letezo index!");
    }
    return mElements[index];
}

bool Matrix::isSquare() const {
    return false;
}
