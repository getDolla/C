#include <stdio.h>
#include <stdlib.h>

int[] sievePrime(int n) {
  int arrayNums[n];
  int i;
  for( i = 0; i <= n; i++ ) {
    arrayNums[i] = i;
  }

  int p = 2;
  while( (p*p) <= n ) {
    i = 0;
    while( i <= p ) {
      
