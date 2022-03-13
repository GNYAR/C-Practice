#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define WORD_SIZE 100
#define ARTICLE_SIZE 4095
#define DEBUG true

int main()
{
  char input[WORD_SIZE * 3] = "";
  char article[ARTICLE_SIZE] = "";
  // User input
  printf("Enter pattern, replacement, and at most one parameter:\n");
  gets(input);
  printf("Enter the article:\n");
  gets(article);

  // Split input parameters
  char inputs[3][WORD_SIZE] = {"", "", ""};
  char transformedInput[WORD_SIZE] = "";
  int i = 0, p = 0, q = 0;
  do
  {
    char c = input[i];
    if (c == ' ' || c == '\0')
    {
      if (p == 0)
        transformedInput[q] = '\0';
      inputs[p++][q] = '\0';
      q = 0;
      continue;
    }
    if (p == 0)
      transformedInput[q] = toupper(c);
    inputs[p][q++] = c;
  } while (input[i++] != '\0' && p < 3);

  // Check input parameters
  bool isCaseInsensitive = strcmp(inputs[2], "-i") == 0;
  if (inputs[0][0] == '\0' ||
      inputs[1][0] == '\0' ||
      (inputs[2][0] != '\0' && !isCaseInsensitive) ||
      input[i] != '\0')
  {
    printf("The input format: string1 string2 [parameter]");
    return 0;
  }
  if (DEBUG)
    printf("this is case: %d\n", isCaseInsensitive);

  // Split input article
  char word[WORD_SIZE] = "";
  char transformedWord[WORD_SIZE] = "";
  i = 0;
  q = 0;
  do
  {
    char c = article[i];
    if (isalnum(c) || c == '-')
    {
      word[q] = c;
      transformedWord[q++] = toupper(c);
      continue;
    }
    word[q] = '\0';
    transformedWord[q] = '\0';
    if (DEBUG && strcmp(word, "") != 0)
      printf("the word is: %s\n", word);

    // Search in word
    char *ptr = isCaseInsensitive ?
      strstr(transformedWord, transformedInput) :
      strstr(word, inputs[0]);
    while (ptr != NULL)
    {
      // Replace
      if (isCaseInsensitive)
        strncpy(&word[ptr - transformedWord], inputs[1], strlen(inputs[1]));
      strncpy(ptr, inputs[1], strlen(inputs[1]));
      // Next
      ptr = isCaseInsensitive ?
        strstr(transformedWord, transformedInput) :
        strstr(word, inputs[0]);
      printf("%s\n", word);
    }
    q = 0;
  } while (article[++i] != '\0');
  return 0;
}
