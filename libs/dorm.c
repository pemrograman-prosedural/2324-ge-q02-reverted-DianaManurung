#include "dorm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct dorm_t create_dorm(char *input)
{
    struct dorm_t dorm;
    strcpy(dorm.name, strtok(NULL, "#"));
    dorm.capacity = atoi(strtok(NULL, "#"));
    char *stop = strtok(NULL, "#");
    if (strcmp(stop, "male")== 0)
    {
        dorm.gender = GENDER_MALE;
    } else if (strcmp(stop, "female") == 0)
    {
        dorm.gender = GENDER_FEMALE;
    }
    return dorm;
}

void print_dorm(struct dorm_t dorm)
{
    printf("%s|%hu|", dorm.name, dorm.capacity);
    if (dorm.gender == GENDER_MALE)
    {
        printf("male\n");
    } else if (dorm.gender == GENDER_FEMALE)
    {
        printf("female\n");
    }
}