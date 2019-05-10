//https://www.hackerrank.com/challenges/for-loop-in-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	char *output[11] = {"even","odd","one","two","three","four","five","six","seven","eight","nine"};
    
    for(int i=a;i<=b;i++){
        if(i>9){
            printf("%s\n",output[i%2]);
        }
        else{
            printf("%s\n",output[i+1]);
        }
    }

    return 0;
}
