//https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double triangle_area(triangle tr){
    double p =(tr.a+tr.b+tr.c)/2.0;
    double result = sqrt(p*(p-tr.a)*(p-tr.b)*(p-tr.c));
    return result;
}

void sort_by_area(triangle* tr, int n) {
	for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(triangle_area(tr[i])>triangle_area(tr[j])){
                triangle temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
