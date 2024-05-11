// 12S23014 - Mikhael Valentino Gultom
// 12S23040 - Diana Hevila Manurung

#include <stdlib.h>
#include <string.h>
#include "./libs/gender.h"
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int argc, char **argv) {
    char input[100];
    int n = 0;
    int size = 0;
    struct dorm_t *dorm = NULL;
    
    int p = 0;
    int size2 = 0;
    struct student_t *mhs = NULL;

    fflush(stdin);
    input[0] = '\0';
    int l = 0;
    while (1) {
        char c = getchar();
        if (c =='\r');
        {
            continue;
        }
        if (c == '\n')
        {
            break;
        }
        input[1] = c;
        input[++1] = '\0';
    }
    if (strcmp(input, "---") == 0)
    {
        int i;
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;
        int temp4 = 0;
        for (i = 0; i < count_scheduler; i++)
    {
        if (strcmp(scheduler[i],"student-print-all")== 0)
        {
            printstudents = print_student;
            printstudents(student, dormshow[temp1]);
            temp1++
        }
        if (strcmp(scheduler[i],"student-print-detail")== 0)
        {
            printstudents = print_student_details;
            printstudents(student, showalldorm[temp2])
            temp2++
        }
        if (strcmp(scheduler[i],"student-print-all")== 0)
        {
            printstudents = print_student;
            printstudents(student, dormshow[temp3]);
            temp3++
        }
        if (strcmp(scheduler[i],"student-print-detail")== 0)
        {
            printstudents = print_student_details;
            printstudents(student, showalldorm[temp4])
            temp4++
        }
            token = strtok(NULL, "#");
            strcpy(mhs.id, token);
            token = strtok(NULL, "#");
            strcpy(mhs.name, token);
            token = strtok(NULL, "#");
            strcpy(mhs.year, token)
        
            if (strcmp("male", token) == 0)
            {
                student[temp_size_student] = create_student(temp_id, temp_name, temp_year, GENDER_MALE);
                temp_size_student++;
                }
                else
                {
                student[temp_size_student] = create_student(temp_id, temp_name, temp_year, GENDER_FEMALE);
                temp_size_student++;
            }

        }
    }
    return 0;
    }