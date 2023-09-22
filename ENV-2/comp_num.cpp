#include <iostream>
#include "comp_num.h" 

ComplexNumber::ComplexNumber(): real_number(0), imaginary_number(1) {}

  ComplexNumber::ComplexNumber(int r, int im): real_number(r), imaginary_number(im) {}
  ComplexNumber::ComplexNumber(const ComplexNumber& cn): real_number(cn.GetRealNumber()), imaginary_number(cn.GetImaginaryNumber()) {} 

int ComplexNumber::GetRealNumber() const {
  return real_number;
}

int ComplexNumber::GetImaginaryNumber() const {
  return imaginary_number;
}

void ComplexNumber::SetRealNumber(int r) {
  real_number = r;
} 

void ComplexNumber::SetImaginaryNumber(int im) {
  imaginary_number = im;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber& cn) {
  ComplexNumber temp(this->real_number - cn.real_number, this->imaginary_number - cn.imaginary_number);
  return temp;
}

ComplexNumber ComplexNumber::operator*(int n) {
  ComplexNumber temp(this->real_number*n, this->imaginary_number*n);
  return temp;
}

int ComplexNumber::absolute() {
  return sqrt(pow(real_number, 2) + pow(imaginary_number, 2));
}

 /* ComplexNumber operator+(ComplexNumber& c1, ComplexNumber& c2) {
  ComplexNumber result(c1.GetRealNumber() + c2.GetRealNumber(), c1.GetImaginaryNumber() + c2.GetImaginaryNumber());
  return result;
} */
