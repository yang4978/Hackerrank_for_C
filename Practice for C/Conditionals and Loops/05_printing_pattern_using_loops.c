//https://www.hackerrank.com/challenges/printing-pattern-2/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	for(int i=1;i<=n;i++){
          for(int j=n;j>=n+1-i;j--){
              printf("%d ",j);
          }
          for(int j=n-i;j>=1;j--){
              printf("%d ",n+1-i);
          }
          for(int j=1;j<=n-i;j++){
              printf("%d ",n+1-i);
          }
          for(int j=n-i+2;j<=n;j++){
              printf("%d ",j);
          }
          printf("\n");
      }
    
    for(int i=n-1;i>=1;i--){
        for(int j=n;j>=n+1-i;j--){
              printf("%d ",j);
          }
          for(int j=n-i;j>=1;j--){
              printf("%d ",n+1-i);
          }
          for(int j=1;j<=n-i;j++){
              printf("%d ",n+1-i);
          }
          for(int j=n-i+2;j<=n;j++){
              printf("%d ",j);
          }
          printf("\n");
    }

      
    return 0;
}

