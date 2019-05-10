//https://www.hackerrank.com/challenges/permutations-of-strings/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Algorithm :

// 1) Find longest non-increasing suffix in the array.

// 2) If the whole array is non-increasing sequence of strings, next permutation isn't possible.

// 3) Otherwise, "key" is the string just before the suffix.

// 4) Find the rightmost string in prefix, which is lexicographically larger than key.

// 5) Swap key with this string.

// 6) Reverse the suffix.


int next_permutation(int n, char **s)
{
        int i = n-1;
    while(i>0 && strcmp(s[i-1],s[i])>=0){
        i--;
    }

    if(i<=0){
        return 0;
    }

    int j = n-1;
    while(j>0 && strcmp(s[i-1],s[j])>=0){
        j--;
    }

    char *temp = s[i-1];
    s[i-1] = s[j];
    s[j] = temp;

    int k = n-1;
    while(k>i){
        temp = s[i];
        s[i] = s[k];
        s[k] = temp;
        i++;
        k--;
    }
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
