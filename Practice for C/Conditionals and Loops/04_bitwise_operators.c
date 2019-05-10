//https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int x,int y){
    return x>y?x:y;
}


void calculate_the_maximum(int n, int k) {
  int and_max=0;
  int or_max=0;
  int xor_max=0;
  for(int i=1;i<n;i++){
      for(int j=i+1;j<=n;j++){
          if((i&j)<k){
              and_max = max((i&j),and_max);
          }
          if((i|j)<k){
              or_max = max((i|j),or_max);
          }
          if((i^j)<k){
              xor_max = max((i^j),xor_max);
          }
      }
  }
  printf("%d\n%d\n%d",and_max,or_max,xor_max);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
