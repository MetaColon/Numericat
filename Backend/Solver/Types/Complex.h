#ifndef BACKEND_COMPLEX_H
#define BACKEND_COMPLEX_H

typedef struct Complex{
    double real;
    double imaginary;
} Complex;

Complex sumComplex(Complex a, Complex b);
Complex subtractComplex(Complex a, Complex b);
Complex multiplyComplex(Complex a, Complex b);
Complex divideComplex(Complex a, Complex b);
Complex powerComplex(Complex a, Complex b);
Complex expComplex(Complex b);
double absSquareComplex(Complex c);
void printComplex(Complex c);

#define COMPLEX(r,i) ((Complex) {.real = (r), .imaginary = (i)})

#endif //BACKEND_COMPLEX_H
