// Copyright  2018  Maxwell Anderson

#ifndef INCLUDE_SPLIT_H_
#define INCLUDE_SPLIT_H_

#include <string>
#include <vector>

namespace mba {
std::vector<std::string> Split(const std::string str, const char spacer) {
  std::vector<std::string> vec;
  std::string tmpstr = str + spacer;
  std::string::size_type tmpstr_size {tmpstr.size()};
  int32_t start {0};
  for (int32_t x {0}; x < tmpstr_size; ++x) {
    if (tmpstr[x] == spacer) {
      vec.push_back(tmpstr.substr(start, x-start));
      start = x + 1;
    }
  }
  return vec;
}
}  // namespace mba

#endif  // INCLUDE_SPLIT_H_
