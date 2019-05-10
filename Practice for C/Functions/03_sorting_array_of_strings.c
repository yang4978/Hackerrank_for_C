//https://www.hackerrank.com/challenges/sorting-array-of-strings/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b)>0;
    // int len_min;
    // int flag;
    // if(strlen(a)<strlen(b)){
    //     len_min = strlen(a);
    //     flag = 0;
    // }
    // else{
    //     len_min = strlen(b);
    //     flag = 1;
    // }

    // for(int i=0;i<len_min;i++){
    //     if(a[i]<b[i]){
    //         return 0;
    //     }
    //     else if(a[i]>b[i]){
    //         return 1;
    //     }
    // }
    // return flag;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a,b)<=0;
    // int len_min;
    // int flag;
    // if(strlen(a)<strlen(b)){
    //     len_min = strlen(a);
    //     flag = 1;
    // }
    // else{
    //     len_min = strlen(b);
    //     flag = 0;
    // }

    // for(int i=0;i<len_min;i++){
    //     if(a[i]>b[i]){
    //         return 0;
    //     }
    //     else if(a[i]<b[i]){
    //         return 1;
    //     }
    // }
    // return flag;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int letter_a[26];
    int letter_b[26];

    for(int i=0;i<26;i++){
        letter_a[i] = 0;
        letter_b[i] = 0;
    }

    for(int i=0;i<strlen(a);i++){
        letter_a[a[i]-'a'] = 1;
    }

    for(int i=0;i<strlen(b);i++){
        letter_b[b[i]-'a'] = 1;
    }

    int sum =0;

    for(int i=0;i<26;i++){
        sum += letter_a[i]-letter_b[i];
    }

    if(sum!=0){
        return sum>0;
    }

    else{
        return strcmp(a,b)>0;
        // int len_min;
        // if(strlen(a)<strlen(b)){
        //     len_min = strlen(a);
        // }
        // else{
        //     len_min = strlen(b);
        // }

        // for(int i=0;i<len_min;i++){
        //     if(a[i]<b[i]){
        //         return 0;
        //     }
        //     else if(a[i]>b[i]){
        //         return 1; 
        //    }
        //}
    }
    return 0;
}

int sort_by_length(const char* a, const char* b) {
    int strlen_a = strlen(a);
    int strlen_b = strlen(b);
    
    if(strlen_a!=strlen_b){
        return strlen_a>strlen_b;
    }
    else{
        return strcmp(a,b)>0;
        // for(int i=0;i<strlen_a;i++){
        //     if(a[i]<b[i]){
        //         return 0;
        //     }
        //     else if(a[i]>b[i]){
        //         return 1;
        //     }
        // }
    }
    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char* temp_ptr=NULL;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(cmp_func(arr[i],arr[j])){
                temp_ptr = arr[i];
                arr[i] = arr[j];
                arr[j] = temp_ptr;
            }
        }
    }

}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
