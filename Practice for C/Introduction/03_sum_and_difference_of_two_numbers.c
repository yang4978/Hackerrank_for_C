//https://www.hackerrank.com/challenges/sum-numbers-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int int_a,int_b;
    float float_a,float_b;

    scanf("%d %d",&int_a,&int_b);
    scanf("%f %f",&float_a,&float_b);
    
    printf("%d %d\n",int_a+int_b,int_a-int_b);
	printf("%.1f %.1f\n",float_a+float_b, float_a-float_b);
    
    return 0;
}

