#include "cmath"

class ComplexNumber{
private:
  int real_number;
  int imaginary_number;

public:
  ComplexNumber();
  ComplexNumber(int r, int im);
  ComplexNumber(const ComplexNumber& cn);

  int GetRealNumber() const;
  int GetImaginaryNumber() const;

  void SetRealNumber(int r);
  void SetImaginaryNumber(int im);

  ComplexNumber operator-(ComplexNumber& cn);

  ComplexNumber operator*(int n);

  int absolute();

  friend ComplexNumber operator+(ComplexNumber& c1, ComplexNumber& c2);
};

