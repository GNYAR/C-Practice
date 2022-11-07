#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COURSE_COUNT 3
#define INFO_COUNT 5
#define NAME_MAX 20
#define STUDENT_COUNT 6

struct Course
{
  char name[NAME_MAX];
  float score;
};

void setChar(int, char[], char[], char[][2][NAME_MAX], int, char);
void print(char[][INFO_COUNT][NAME_MAX], struct Course[][COURSE_COUNT], int[], int);
int search(char[][INFO_COUNT][NAME_MAX], char[], int);

int main()
{
  char students[STUDENT_COUNT][INFO_COUNT][NAME_MAX];
  struct Course courses[STUDENT_COUNT][COURSE_COUNT];
  int studentCourseCount[STUDENT_COUNT];

  printf("輸入班級成員資訊\n");
  for (int i = 0; i < STUDENT_COUNT; i++)
  {
    scanf("%s\t%s\t%s\t%s\t%s",
          students[i][0], students[i][1], students[i][2],
          students[i][3], students[i][4]);
    studentCourseCount[i] = 0;
  }

  char line[NAME_MAX * 8];
  gets(line);

  printf("輸入每位同學修課成績\n");
  for (int i = 0; i < STUDENT_COUNT; i++)
  {
    char name[NAME_MAX];
    char id[NAME_MAX];
    char temp[COURSE_COUNT][2][NAME_MAX];
    int p = 0, q = 0, r = 0;

    gets(line);
    while (line[p] != '\0')
    {
      char c = line[p];

      if (c == ' ')
      {
        if (q != 0)
        {
          setChar(r, name, id, temp, q, '\0');
          r++;
        }
        q = 0;
        p++;
        continue;
      }
      setChar(r, name, id, temp, q++, c);
      p++;
    }

    int count = (r - 1) / 2;
    int index = search(students, id, 0);

    if (index == -1)
    {
      printf("查無此人\n");
      return 0;
    }

    for (int j = 0; j < COURSE_COUNT; j++)
    {
      if (count - 1 < j)
      {
        strcpy(courses[index][j].name, "--");
        courses[index][j].score = 0;
        continue;
      }

      strcpy(courses[index][j].name, temp[j][0]);
      courses[index][j].score = atof(temp[j][1]);
    }

    studentCourseCount[index] = count;
  }

  // print(students, courses, studentCourseCount, -1);

  int action;
  int ignore[STUDENT_COUNT];
  do
  {
    printf("輸入動作代碼(查詢: 1, 刪除: 2, 離開: -1): ");
    scanf("%d", &action);

    char keyword[NAME_MAX];
    int index;

    switch (action)
    {
    case 1:
      printf("輸入學號或姓名查詢: ");
      scanf("%s", keyword);

      index = search(students, keyword, 1);

      if (index == -1)
      {
        printf("查無此人\n");
        break;
      }

      print(students, courses, studentCourseCount, index);
      break;

    case 2:
      printf("輸入學號或姓名刪除: ");
      scanf("%s", keyword);

      index = search(students, keyword, 1);

      print(students, courses, studentCourseCount, -1);
      break;

    default:
      break;
    }
  } while (action != -1);

  return 0;
}

void setChar(int exp, char name[], char id[], char temp[][2][NAME_MAX], int index, char x)
{
  switch (exp)
  {
  case 0: // name
    name[index] = x;
    break;

  case 1: // id
    id[index] = x;
    break;

  default: // temp
    temp[(exp - 2) / 2][exp % 2][index] = x;
    break;
  }
}

void print(char students[][INFO_COUNT][NAME_MAX], struct Course courses[][COURSE_COUNT], int studentCourseCount[], int index)
{
  printf("姓名\t學號\t性別\t科系\t聯絡電話\t科目1\t成績\t科目2\t成績\t科目3\t成績\t平均成績\n");
  for (int i = 0; i < STUDENT_COUNT; i++)
  {
    if (index != -1 && i != index)
    {
      continue;
    }

    for (int j = 0; j < INFO_COUNT; j++)
    {
      printf("%s\t", students[i][j]);
    }

    float total = 0;
    for (int j = 0; j < COURSE_COUNT; j++)
    {
      struct Course course = courses[i][j];
      printf("%s\t%.2f\t", course.name, course.score);
      total += course.score;
    }
    printf("%.2f\n", total / studentCourseCount[i]);
  }
};

int search(char students[][INFO_COUNT][NAME_MAX], char keyword[], int flag)
{
  for (int i = 0; i < STUDENT_COUNT; i++)
  {
    if (strcmp(keyword, students[i][1]) == 0 || (flag == 1 && strcmp(keyword, students[i][0]) == 0))
    {
      return i;
    }
  }

  return -1;
}
