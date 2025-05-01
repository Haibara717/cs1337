#include "Complex.h"
// PURPOSE: Returns the conjugate of this Complex number
// INPUT : this (a + bi)
// OUTPUT: (a - bi)


// Parametrized constructor: constructs Complex from two doubles (real and imaginary parts)
Complex::Complex(double rreal, double imag) {
  real = rreal;
  imaginary = imag;
}
// Constructor from string input: parses a string like "10.1 20.2"
Complex::Complex(string input) {
  real = imaginary = 0; //additional safety!
  istringstream(input) >> real >> imaginary;
}
// Destructor: used to show when an object is destroyed
Complex::~Complex()
{
    cout <<"Destructor called" << endl;
}

// Getter for real part
double Complex::getReal() {
    return real;
}
// Getter for imaginary part
double Complex::getImaginary() {
    return imaginary;
}

// Setter for real part
void Complex::setReal(double rreal) {
    real = rreal;
}
// Setter for imaginary part
void Complex::setImaginary(double imag) {
    imaginary = imag;
}


// Operator overloading for + : adds two Complex numbers and returns a new Complex
Complex Complex::operator+(const Complex &second) const {
    return Complex(real + second.real, imaginary + second.imaginary);
}
// Operator overloading for += : adds another Complex to this object
void Complex::operator+=(const Complex &second) {
    real += second.real;
    imaginary += second.imaginary;
}

// Overloaded ~ operator: returns the complex conjugate (a, b) → (a, -b)
Complex Complex::operator~() {
    return Complex(real, -imaginary);
}

// Overload input operator >> : allows cin >> Complex
istream& operator>>(istream& input, Complex &object) {
    input >> object.real >> object.imaginary;
    return input;
}

// Overload output operator << : allows cout << Complex
ostream& operator<<(ostream& output, const Complex &object) {
  output << "(" << object.real << ","
                << object.imaginary << ")";
  return output;
}
