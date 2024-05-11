// 12S23014 - Mikhael Valentino Gultom
// 12S23040 - Diana Hevila Manurung

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libs/gender.h"
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int argc, char **argv) {
    char input[100];
    char aksi[100];
    char para[100];
    struct student_t students[100];
    struct dorm_t dormitories[100];
    int num_students = 0;
    int num_dorms = 0;
   
    while (1) {
        fgets(input, sizeof(input), stdin);
        scanf(input, "&s#%[^\n]", input, para);
        if (strcmp(input, "dorm-empty") == 0) {
        int find = find_dorm(para, num_dorms, dormitories);
            if (find != -1) {
            } else {
            printf("Error: Dormitory '%s' not found\n", para);
            }
        } else if (strcmp(input, "student-add") == 0) {
            students[num_students++] = create_student(para);
        } else if (strcmp(input, "dorm-add") == 0) {
            dormitories[num_dorms++] = create_dorm(para);
        } else if (strcmp(input, "assign-student") == 0) {
            char id[100];
            char dorm_name[100];
            sscanf(para, "%s#%s", id, dorm_name);
            move_student(dormitories, students, id, dorm_name, num_students, num_dorms, find_id, find_dorm);
        } else if (strcmp(input, "student-print-all-detail") == 0) {
            for (int i = 0; i < num_students; ++i) {
                print_student_detail(students[i]);
            }
        } else if (strcmp(input, "dorm-print-all-detail") == 0) {
            for (int i = 0; i < num_dorms; ++i) {
                print_dorm_detail(dormitories[i]);
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid input\n");
        }
    }

    return 0;
}