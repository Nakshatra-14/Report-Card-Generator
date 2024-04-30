#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char name[50], line[50];
    int sub1, sub2, sub3, roll;
    FILE *fp;
    fp = fopen("student.txt", "r");
    if(fp == NULL)
    {
        puts("File not found");
        exit(1);
    }
    //ABCDn0
    //012345
    // printf("%d\n", feof(fp));
    while(fgets(name, 50, fp) != NULL)
    {    
        name[strlen(name) - 1] = '\0';
        fgets(line, 50, fp);
        sscanf(line, "%d %d %d %d", &roll, &sub1, &sub2, &sub3);
        // printf("=%s=\n", name);
        printf("Name = %s, Rollno. = %d, subject-1 = %d, Subject-2 = %d, Subject-3 = %d\n", name, roll, sub1, sub2, sub3);
    }
    fclose(fp);
    return 0;
}
