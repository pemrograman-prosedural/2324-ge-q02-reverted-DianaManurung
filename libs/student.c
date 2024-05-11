#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct student_t create_student(char *input)
{
  struct student_t mhs;
  strcpy(mhs.id, strtok(NULL, "#"));
  strcpy(mhs.name, strtok(NULL, "#"));
  strcpy(mhs.year, strtok(NULL, "#"));
  char *stop = strtok(NULL, "#");
  if (strcmp(stop, "male") == 0)
  {
    mhs.gender = GENDER_MALE;
  }
  else if (strcmp(stop, "female") == 0)
  {
    mhs.gender = GENDER_FEMALE;
  }
  mhs.dorm = NULL;
  mhs.dorm = malloc(1 * sizeof(struct dorm_t));
  strcpy(mhs.dorm->name, "unassigned");
  return mhs;
}

void print_student(struct student_t mhs)
{
  printf("%s|%s|%s|", mhs.id, mhs.name, mhs.year);
  if (mhs.gender == GENDER_MALE)
  {
    printf("male\n");
  }
  else if (mhs.gender == GENDER_FEMALE)
  {
    printf("female\n");
  }
}
void print_student_detail(struct student_t mhs)
{
  printf("%s|%s|%s|", mhs.id, mhs.name, mhs.year);
  if (mhs.gender == GENDER_MALE)
  {
    printf("male|");
  }
  else if (mhs.gender == GENDER_FEMALE)
  {
    printf("female|");
  }
  printf("%s\n", mhs.dorm->name);
}
int find_id(char *nim, int stdn, struct student_t *mhs)
{
  int find_id = -1;
  for (int a = 0; a < stdn; a++)
{
    if (strcmp(nim, mhs[a].id) == 0)
    {
      find_id = a;
    }
  }
  return find_id;
}

void assign_student(struct dorm_t *dorm, struct student_t *mhs, char *nim, char *asrama, int stdn, int asrm, int find_id(char *nim, int stdn, struct student_t *mhs), int find_dorm(char *asrama, int asrm, struct dorm_t *dorm))
{
  int msiswa = find_id(nim, stdn, mhs);
  int mrama = find_dorm(asrama, asrm, dorm);
  if (msiswa >= 0 && mrama >= 0 && dorm[mrama].capacity != dorm[mrama].residents_num && mhs[msiswa].gender == dorm[mrama].gender)
  {
    strcpy(mhs[msiswa].dorm->name, asrama);
    drm[mrama].residents_num++;
  }
}

void move_student(struct dorm_t *dorm, struct student_t *mhs, char *nim, char *asrama, int stdn, int asrm, int find_id(char *nim, int stdn, struct student_t *mhs), int find_dorm(char *asrama, int dorm, struct dorm_t *dorm))
{
  int msiswa = find_id(nim, stdn, mhs);
  char sebelum[20];
  strcpy(sebelum, mhs[msiswa].dorm->name);
  int mramasebelum = find_dorm(sebelum, asrm, dorm);
  int mramasesudah = find_dorm(asrama, asrm, dorm);
  if (msiswa >= 0 && mramasebelum >= 0 && mramasesudah >= 0 && dorm[mramasesudah].capacity != dorm[mramasesudah].residents_num && mhs[msiswa].gender == dorm[mramasesudah].gender)
  {
    dorm[mramasebelum].residents_num--;
    strcpy(mhs[msiswa].dorm->name, asrama);
    dorm[mramasesudah].residents_num++;
  }
  else if (msiswa >= 0 && mramasesudah == -1 && mramasesudah >= 0 && dorm[mramasesudah].capacity != dorm[mramasesudah].residents_num && mhs[msiswa].gender == dorm[mramasesudah].gender)
  {
    strcpy(mhs[msiswa].dorm->name, asrama);
    dorm[mramasesudah].residents_num++;
  }
}

void dorm_empty(char *asrama, int stdn, int asrm, struct student_t *mhs, struct dorm_t *dorm, int find_dorm(char *asrama, int asrm, struct dorm_t *dorm))
{
  int mrama = find_dorm(asrama, asrm, dorm);
  for (int a = 0; a < stdn; a++)
  {
    if (strcmp(asrama, mhs[a].dorm->name) == 0)
    {
      strcpy(mhs[a].dorm->name, "unassigned");
      dorm[mrama].residents_num--;
    }
  }
}