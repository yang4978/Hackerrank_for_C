//https://www.hackerrank.com/challenges/printing-tokens-/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    int i=0;
    int temp=0;
    while(i<strlen(s)){
        if(s[i]==' '){
            printf("\n");
        }
        else{
            printf("%c", s[i]);
        }
        i++;
    }
    return 0;
}

