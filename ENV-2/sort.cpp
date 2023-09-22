#include "sort.h"

void sort(std::vector<ComplexNumber>& v) {
  std::size_t size = v.size();
  for (std::size_t i = 0; i < size - 1; ++i) {
    bool swapped = false; 
    for (std::size_t j = 0; j < size - i - 1; ++j) {
      if (v[j].absolute() > v[j+1].absolute()) {
        ComplexNumber temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}