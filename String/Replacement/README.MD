# Exercise #1
Let’s write a program that can do word replacement in an article (e.g., replacing "he" with "she" in an article). The program will first ask the user to enter two strings. The first input indicates the string in the article that will be replaced and the second input represents the string that will be used to replace the first string. Furthermore, the user can choose whether to enter the parameter -i after the input of the two strings. Please see the table below for the meaning and usage of -i. Therefore, the input format would be like `he she` (replacing all he in the article with she) or `he she -i` (replacing all "he" or "He" in the article with "she"). For example, the word "hello" in the article will become "shello".

| Parameter | Condition |
| :-------- | :-------- |
| -i        | Change the compared condition from case sensitive to case insensitive. The default state is case-sensitive, which means that 'a' is different from 'A'. |

If the user enters the incorrect input format or the invalid parameter, the program should show the correct input format as a reminder to users `The input format: string1 string2 [parameter]` and terminate. After the user entered the correct input format, the program will then ask the user to enter an article. Once the user finished entering the article and press enter (i.e., the new-line character), the program should replace every word (i.e., the first string and first appearence) in the article with the word represented by the second string and print those words that are replaced.

The definition of a word is a string consisting of numbers, letters, and the dash character. The length of the input string will not exceed **100** characters, and the length of the article will not exceed **4095** characters.

For the efficiency of execution, you can use `fprintf(stderr, "message you want to send")`. You may also want to check these functions on the Internet when writing this exercise: `fgets()`, `isalnum()`, `strstr()`.

## Example:
> Enter pattern, replacement, and at most one parameter: `he it`  
> Enter the article: `He is our new TA called Bo-Zheng, Chen. It is ok not entering the  parameters.`  
> Bo-Zitng  
> Citn  
> tit

> Enter pattern, replacement, and at most one parameter: `he it -i`  
> Enter the article: `He is our new TA called Bo-Zheng, Chen. Cause the parameter "-i", He has been replaced with it.`  
> it  
> Bo-Zitng  
> Citn  
> tit  
> it

> Enter pattern, replacement, and at most one parameter: `he it -r`  
> Enter the article: `Example for Invalid case.`  
> The input format: string1 string2 [parameter]

# Exercise #2
Let's continue to extend the program that can do word replacement in an article(ie. Exercise #1). Please add **at least** three parameterized macros in the program and these parameterized macros need handle critical parts related to the output. The trivial parameterized macros like `#define PRINT(n) printf("%s", n)` will not be included in the three parameterized macros. Moreover, you need to use the conditional compilation as a debugging tool. When the program is in the debug mode, you must show the information like table of output below.

## Example:
> Enter pattern, replacement, and at most one parameter: `he it`  
> Enter the article: `The debug test.`  
> this is case: 0  
> the word is: The  
> Tit  
> the word is: debug  
> the word is: test

> Enter pattern, replacement, and at most one parameter: `he it -i`  
> Enter the article: `The debug test.`  
> this is case: 1  
> the word is: The  
> Tit  
> the word is: debug  
> the word is: test

> Enter pattern, replacement, and at most one parameter: `he it -r`  
> The input format: string1 string2 [parameter]
