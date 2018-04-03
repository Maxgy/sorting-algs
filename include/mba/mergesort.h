// Copyright  2018  Maxwell Anderson

#ifndef INCLUDE_MERGESORT_H_
#define INCLUDE_MERGESORT_H_

#include <vector>

namespace mba {
template <typename T, typename U>
void Merge(std::vector<T> &vec, const U start, const U mid, const U end) {
  std::vector<T> tmp_vec(end + 1);
  U first {start};
  U second {mid + 1};
  U i {start};
  while (first <= mid && second <= end) {
    if (vec[first] <= vec[second]) {
      tmp_vec[i] = vec[first];
      first++;
    } else {
      tmp_vec[i] = vec[second];
      second++;
    }
    i++;
  }
  if (first > mid) {
    for (U x {second}; x <= end; ++x) {
      tmp_vec[i] = vec[x];
      i++;
    }
  } else {
    for (U x {first}; x <= mid; ++x) {
      tmp_vec[i] = vec[x];
      i++;
    }
  }
  for (U x {start}; x <= end; ++x) {
    vec[x] = tmp_vec[x];
  }
}

template <typename T, typename U>
void MergeSort(std::vector<T> &vec, const U start, const U end) {
  if (start < end) {
    U mid = (start + end) / 2;
    MergeSort(vec, start, mid);
    MergeSort(vec, mid + 1, end);
    Merge(vec, start, mid, end);
  }
}
}  // namespace mba

#endif  // INCLUDE_MERGESORT_H_
