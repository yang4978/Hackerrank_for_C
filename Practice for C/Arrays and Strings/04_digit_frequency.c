//https://www.hackerrank.com/challenges/frequency-of-digits-1/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]",s); 
    int num[10];
    for(int i=0;i<10;i++){
        num[i] = 0;
    }

    for(int i=0;i<strlen(s);i++){
        if(s[i]-'0'<=9){
            num[s[i]-'0']++;
        }
    }

    for(int i=0;i<10;i++){
        printf("%d ",num[i]);
    }

    return 0;
}
