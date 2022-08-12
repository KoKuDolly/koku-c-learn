/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // char* a[] = {"abc", "def", "ghi"};
    // // int len = sizeof(a)/sizeof(a[0]);
    
    // // char* b[len];
    // // for(int i = 0; i < len; i++) {
    // //     b[i] = a[i];
    // // }
    // // printf("%ld\n", sizeof(b));
    // // printf("%s\n", b[2]);
    // // printf("%ld\n", sizeof(a[0]));
    // // char* c = "abc";
    // // printf("%s\n", c);
    
    // // char** d = (char**)malloc(3);
    
    // char* d[3]; // 数组申明，但未初始化，必须指定大小
    
    // for(int i = 0; i < 3; i++) {
    //   d[i] = a[i];
    //     // strcpy(d[i], a[i]);
    // }
    
    // // char* e = "abc";
    // // char* f = malloc(sizeof(char*));
    // // strcpy(f, e);
    // // // f = "abc";
    // d[2] = "ccc";
    // printf("%s\n", d[2]);
    
    char* s1;
    char* s2;
    
    s1 = "abc";
    // strcpy(s2, s1);
    s2 = s1;
    s2 = "333";
    
    char* a[] = {"abc", "def", "ghi"};

    return 0;
}
