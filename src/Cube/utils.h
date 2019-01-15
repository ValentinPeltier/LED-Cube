#ifndef UTILS_H
#define UTILS_H

template<typename T, size_t N>
void shuffle(T (&arr)[N]) {
  for(int i = N-1; i > 0; i--) {
    int j = random(i + 1);

    T tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
}

#endif