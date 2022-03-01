// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (0 == n) {
    return 1;
  }
  if (1 == n) {
    return value;
  } else {
    return value*pown(value, n-1);
  }
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  } else {
    return n*fact(n-1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  if (count < 1) {
    return 1;
  } else {
    return calcItem(x, count) + expn(x, count - 1);
  }
}

double sinn(double x, uint16_t count) {
  double sin = 0;
  for (int i = count; i > 0; i--) {
    sin += pown((-1), i-1)*(pown(x, 2*i-1)/fact(2*i-1));
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double res = 0;
  for (int i = count; i > 0; i--) {
    res += pown((-1), i-1)*(pown(x, 2*i-2)/fact(2*i-2));
  }
  return res;
}
