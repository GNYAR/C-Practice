#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COURSE_COUNT 3
#define INFO_COUNT 5
#define NAME_MAX 20
#define STUDENT_COUNT 6

typedef struct Course
{
  char name[NAME_MAX];
  float score;
} Course;

typedef struct Student
{
  char info[INFO_COUNT][NAME_MAX];
  Course courses[COURSE_COUNT];
  int courseCount;

  struct Student *next;
} Student;

void print(Student *, int);                                        // (*ptr, count)
void removeElement(Student **, Student *);                         // (**headPtr, *target)
Student *search(Student *, char[], int);                           // (*head, keyword, nameFlag) -> *ptr
void setChar(int, char[], char[], char[][2][NAME_MAX], int, char); // (exp, name, id, courses, index, char)

int main()
{
  // pointer for linked list
  Student *head, *current;

  // input student info
  printf("輸入班級成員資訊\n");
  for (int i = 0; i < STUDENT_COUNT; i++)
  {
    // pointer for inputs
    Student *new = malloc(sizeof(Student));

    // input data
    scanf("%s\t%s\t%s\t%s\t%s", new->info[0],
          new->info[1], new->info[2],
          new->info[3], new->info[4]);

    // initialize data
    new->courseCount = 0;
    new->next = NULL;

    // append to the linked list
    if (i == 0)
    {
      head = new;
    }
    else
    {
      current->next = new;
    }

    // move the pointer to next
    current = new;
  }

  // string for input
  char line[NAME_MAX * 8];
  // gets the trailing whitespace left
  gets(line);

  // input student course data
  printf("\n輸入每位同學修課成績\n");
  for (int i = 0; i < STUDENT_COUNT; i++)
  {
    // variable for inputs
    char name[NAME_MAX];
    char id[NAME_MAX];
    char temp[COURSE_COUNT][2][NAME_MAX];
    int indexForLine = 0, indexForColumn = 0, columnCounter = 0;

    // get the input line
    gets(line);
    // loop for each char in the line
    while (line[indexForLine] != '\0')
    {
      char currentChar = line[indexForLine];

      if (currentChar == ' ')
      {
        // column end
        if (indexForColumn != 0)
        {
          // set the null char to the variable (end of string)
          setChar(columnCounter++, name, id, temp, indexForColumn, '\0');
        }
        indexForColumn = 0;
      }
      else
      {
        // set current char to the variable
        setChar(columnCounter, name, id, temp, indexForColumn++, currentChar);
      }

      // next char
      indexForLine++;
    }

    // search with id
    current = search(head, id, 0);

    // hanlde not found
    if (current == NULL)
    {
      printf("查無此人\n");
      return 0;
    }

    // set the data into the element
    int courseCount = (columnCounter - 1) / 2;
    current->courseCount = courseCount;

    for (int j = 0; j < COURSE_COUNT; j++)
    {
      if (courseCount - 1 < j)
      {
        // set default value when courseCount < COURSE_COUNT
        strcpy(current->courses[j].name, "--");
        current->courses[j].score = 0;

        continue;
      }

      strcpy(current->courses[j].name, temp[j][0]);
      current->courses[j].score = atof(temp[j][1]);
    }
  }

  // print all
  // print(head, -1);

  int action;
  do
  {
    printf("\n輸入動作代碼(查詢: 1, 刪除: 2, 離開: -1): ");
    scanf("%d", &action);

    char keyword[NAME_MAX];

    switch (action)
    {
    // search
    case 1:
      printf("輸入學號或姓名查詢: ");
      scanf("%s", keyword);

      current = search(head, keyword, 1);

      // hanlde not found
      if (current == NULL)
      {
        printf("查無此人\n");
        break;
      }

      print(current, 1);
      break;
    // remove
    case 2:
      printf("輸入學號或姓名刪除: ");
      scanf("%s", keyword);

      current = search(head, keyword, 1);

      // hanlde not found
      if (current == NULL)
      {
        printf("查無此人\n");
        break;
      }

      removeElement(&head, current);
      print(head, -1);
      break;

    default:
      break;
    }
  } while (action != -1);

  return 0;
}

// print(Student *ptr, int count)
void print(Student *ptr, int count)
{
  printf("\n姓名\t學號\t性別\t科系\t聯絡電話\t科目1\t成績\t科目2\t成績\t科目3\t成績\t平均成績\n");

  int i = 1;
  do
  {
    // print student info
    for (int j = 0; j < INFO_COUNT; j++)
    {
      printf("%s\t", ptr->info[j]);
    }

    // print student course data and average
    float total = 0;
    for (int j = 0; j < COURSE_COUNT; j++)
    {
      Course course = ptr->courses[j];
      printf("%s\t%.2f\t", course.name, course.score);
      total += course.score;
    }
    printf("%.2f\n", total / ptr->courseCount);

    // next
    ptr = ptr->next;
  } while ((count == -1 || i++ < count) && ptr != NULL);
};

// removeElement(Student **headPtr, Student *target)
void removeElement(Student **headPtr, Student *target)
{
  if (*headPtr == target)
  {
    *headPtr = target->next;
    free(target);
    return;
  }

  // find previous
  Student *previous = *headPtr;
  while (previous->next != target)
  {
    previous = previous->next;
  }

  previous->next = target->next;
  free(target);
}

// search(Student *head, char keyword[], int nameFlag)
Student *search(Student *head, char keyword[], int nameFlag)
{
  while (head != NULL)
  {
    // compare with id or name(if flag set)
    if (strcmp(keyword, head->info[1]) == 0 || (nameFlag == 1 && strcmp(keyword, head->info[0]) == 0))
    {
      return head;
    }

    // next
    head = head->next;
  };

  return NULL;
}

// setChar(int exp, char name[], char id[], char temp[][2][NAME_MAX], int index, char x)
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
