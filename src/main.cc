// Copyright  2018  Maxwell Anderson

#include <iostream>
#include <string>
#include <vector>
#include "include/split.h"
#include "include/mergesort.h"

int main() {
  std::string input;
  while (true) {
    std::cout << "Enter a space separated list of values to sort:\n>>> ";
    std::getline(std::cin, input);
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(32767);
    } else {
      break;
    }
  }

  std::vector<std::string> strvec { mba::Split(input, ' ') };
  std::vector<std::string>::size_type strvec_size { strvec.size() };
  std::vector<double> vec;
  for (int32_t x {0}; x < strvec_size; ++x) {
    try {
      vec.push_back(std::stod(strvec[x]));
    } catch (std::invalid_argument) {
      std::cout << "Exception caught: Invalid values!\n";
      exit(EXIT_FAILURE);
    }
  }
  std::vector<double>::size_type vec_size { vec.size() };

  std::cout << "\nOriginal vector:\n\t";
  for (auto &x : vec) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  mba::MergeSort(vec, (int32_t) 0, (int32_t) vec_size - 1);

  std::cout << "\nSorted vector:\n\t";
  for (auto &x : vec) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return 0;
}
