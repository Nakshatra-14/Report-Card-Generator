#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char name[50], line[50];
    int i, n, sub1, sub2, sub3, roll;
    FILE *fp;
    fp = fopen("student.txt", "a");
    if(fp == NULL)
    {
        puts("File not found");
        exit(1);
    }
    printf("How many student: ");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++)
    {
        printf("Roll: ");
        scanf("%d", &roll);
        fflush(stdin);
        printf("Name: ");
        gets(name);
        printf("Subject-1: ");
        scanf("%d", &sub1);
        printf("Subject-2: ");
        scanf("%d", &sub2);
        printf("Subject-3: ");
        scanf("%d", &sub3);
        fprintf(fp, "%s\n%d %d %d %d\n", name, roll, sub1, sub2, sub3);
    }
    fclose(fp);
return 0;
}    
