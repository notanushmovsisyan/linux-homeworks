#include <iostream>
#include "sort.h"

int main() {
  std::vector<ComplexNumber> v;
  v.push_back(ComplexNumber(4, 5));
  v.push_back(ComplexNumber(2, 3));
  v.push_back(ComplexNumber(2, 2));
  v.push_back(ComplexNumber(4, 4));
  sort(v);

  for(std::size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i].GetRealNumber() << ", " << v[i].GetImaginaryNumber() << " ";
    std::cout << "absolute=" <<v[i].absolute() << std::endl;
  }
}