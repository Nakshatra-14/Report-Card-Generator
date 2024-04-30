#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char calcGrade(float mark)
{
    // 85-100   S
    // 75*84    A
    // 65-74    B
    // 55-64    C
    // 50-54    D
    // 0-49     F

    if (100 > mark && mark > 85)
        return 'S';
    else if (84 > mark && mark > 75)
        return 'A';
    else if (74 > mark && mark > 65)
        return 'B';
    else if (64 > mark && mark > 55)
        return 'C';
    else if (54 > mark && mark > 50)
        return 'D';
    else
        return 'F';
}

int main(void)
{
    char name[50], line[50];
    int sub1, sub2, sub3, roll, total;
    FILE *sfp, *tfp;
    sfp = fopen("student.txt", "r");
    if (sfp == NULL)
    {
        puts("File not found");
        exit(1);
    }
    tfp = fopen("report.html", "w");
    fputs("<!DOCTYPE html>\n", tfp);
    fputs("<html>\n", tfp);
    fputs("    </head>\n", tfp);
    fputs("        <title>Student Report Card</title>\n", tfp);
    fputs("    </head>\n", tfp);
    fputs("    <body>\n", tfp);
    fputs("        <table border=\"1\">\n", tfp);
    fputs("            <tr>\n", tfp);
    fputs("                <th>Roll</td>\n", tfp);
    fputs("                <th>Name</td>\n", tfp);
    fputs("                <th>Marks 1</td>\n", tfp);
    fputs("                <th>Marks 2</td>\n", tfp);
    fputs("                <th>Marks 3</td>\n", tfp);
    fputs("                <th>Total</td>\n", tfp);
    fputs("                <th>Grade</td>\n", tfp);
    fputs("            </tr>\n", tfp);

    // ABCDn0
    // 012345
    //  printf("%d\n", feof(fp));

    while (fgets(name, 50, sfp) != NULL)
    {
        name[strlen(name) - 1] = '\0';
        fgets(line, 50, sfp);
        sscanf(line, "%d %d %d %d", &roll, &sub1, &sub2, &sub3);
        total = sub1 + sub2 + sub3;
        // printf("=%s=\n", name);
        // printf("Name = %s, Rollno. = %d, subject-1 = %d, Subject-2 = %d, Subject-3 = %d\n", name, roll, sub1, sub2, sub3);
        fputs("            <tr>\n", tfp);
        fprintf(tfp, "                <td>%s</td>\n", name);
        fprintf(tfp, "                <td>%d</td>\n", roll);
        fprintf(tfp, "                <td>%d</td>\n", sub1);
        fprintf(tfp, "                <td>%d</td>\n", sub2);
        fprintf(tfp, "                <td>%d</td>\n", sub3);
        fprintf(tfp, "                <td>%d</td>\n", total);
        fprintf(tfp, "                <td>%c</td>\n", calcGrade(total/3.0));
    }
    
    fputs("        </table>\n", tfp);
    fputs("    </body>\n", tfp);
    fputs("</html>\n", tfp);
    puts("Succesfully Completed");
    fclose(sfp);
    fclose(tfp);
    return 0;
}
