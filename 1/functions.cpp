#include "functions.h"

int countBits(int number){
    int res = 0;
    while(number > 0){
        res += number & 1;
        number >>= 1;
    }
    return res;
}

bool setBit(int& number, int order){
    if(order > 31 || order < 0){
        return false;
    }
    number |= 1 << order;
    return true;
}

double mean(double array[], int numElements){
    if(numElements == 0){
        return NAN;
    }
    double sum = 0;
    for(int i = 0; i < numElements; ++i){
        sum += array[i];
    }
    return sum / numElements;
}
double stddev(double array[], int numElements){
    double avg = mean(array, numElements);
    double sum = 0;
    for(int i = 0; i < numElements; ++i){
        sum += (array[i] - avg) * (array[i] - avg);
    }
    return sqrt(sum / numElements);
}
pair<double, double> max2(double array[], int numElements){
    pair<double, double> p;
    p.first = NAN;
    p.second = NAN;
    if(numElements == 0){
        return p;
    }
    p.first = p.second = array[0];
    if(numElements == 1){    
        return p;
    }
    for(int i = 1; i < numElements; ++i){
        if(array[i] > p.second){
            p.first = p.second;
            p.second = array[i];
        }
    }
    return p;
}