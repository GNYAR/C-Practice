#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
  char input[300] = "";
  char article[4095] = "";
  // User input
  printf("Enter pattern, replacement, and at most one parameter:\n");
  gets(input);
  printf("Enter the article:\n");
  gets(article);
  // String split
  char inputs[3][100] = {"", "", ""};
  char transformedInput[100] = "";
  int i = 0;
  int p = 0;
  int q = 0;
  do
  {
    char c = input[i];
    if (c == ' ' || c == '\0')
    {
      if (p == 0)
        transformedInput[q] = '\0';
      inputs[p++][q] = '\0';
      q = 0;
    }
    else
    {
      if (p == 0)
        transformedInput[q] = toupper(c);
      inputs[p][q++] = c;
    }
  } while (input[i++] != '\0' && p <= 3);
  // Check param
  bool isCaseInsensitive = strcmp(inputs[2], "-i") == 0;
  if (
      input[i] == '\0' &&
      inputs[0][0] != '\0' &&
      inputs[1][0] != '\0' &&
      (inputs[2][0] == '\0' || isCaseInsensitive))
  {
    // For each char
    char word[100] = "";
    char transformedWord[100] = "";
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
      // For each word
      word[q] = '\0';
      transformedWord[q] = '\0';
      if (isCaseInsensitive)
      {
        char *ptr = strstr(transformedWord, transformedInput);
        while (ptr != NULL)
        {
          int index = ptr - transformedWord;
          strncpy(&word[index], inputs[1], strlen(inputs[1]));
          strncpy(ptr, inputs[1], strlen(inputs[1]));
          ptr = strstr(transformedWord, transformedInput);
          printf("%s\n", word);
        }
      }
      else
      {
        char *ptr = strstr(word, inputs[0]);
        while (ptr != NULL)
        {
          strncpy(ptr, inputs[1], strlen(inputs[1]));
          ptr = strstr(word, inputs[0]);
          printf("%s\n", word);
        }
      };
      q = 0;
    } while (article[i++] != '\0');
    return 0;
  }
  // Wrong input
  printf("The input format: string1 string2 [parameter]");
  return 0;
}
