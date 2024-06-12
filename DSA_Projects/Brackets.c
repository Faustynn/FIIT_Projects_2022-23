/*
Your task is to analyze the entered sequences and count the number of errors in each sequence, and output this number of errors.
Sequences consist of pairs of parentheses of the type ( ), [ ], <>, or { }. It is an error if a pair does not have a starting or ending parenthesis or if a pair consists of different parentheses, such as ( ] or <}. Parentheses can nest into each other any number of times.
At the input there is first a number N (in the range from 1 to 200) expressing the number of sequences, while each sequence is located on a separate line. The length of one sequence can be from 1 to 100000 characters.
The output consists of error counts, and these numbers are written on separate lines.

Ukážkový vstup
5
{[]([]{}){[]{}}}
((([]()){}]}
[{([}]}
{[]
({})]

Ukážkový výstup
0
2
3
1
1
*/
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

int strlenBetta(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        // printf("!!%c!!",str[i]);
        i++;
    }
    return i;
}
int normalize(char *str,int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '[' && str[i] == ']' ||
            str[i] == '<' && str[i] == '>' || str[i] == '{' && str[i] == '}')
            i++;
        else{
            return 0;
        }
    }
    return 1;
}
int lookFunction(char *line, int length) {
    int errCount = 0;
    char* buffer=(char *)malloc(313 * sizeof(char));
    int top=0;

    for (int i = 0; i < length; i++) {
        if (line[i] == '(' || line[i] == '[' || line[i] == '<' || line[i] == '{') {
            buffer[top++] = line[i];
        } else if (line[i] == ')' || line[i] == ']' || line[i] == '>' || line[i] == '}') {
            if (top == 0) { // нет пары
                errCount++;
                line[i]=' ';
            } else {
                char prevChar = buffer[--top];
                if ((line[i] == ')' && prevChar != '(') || (line[i] == ']' && prevChar != '[') ||
                    (line[i] == '>' && prevChar != '<') || (line[i] == '}' && prevChar != '{')) {
                    errCount++; // закрывающая другая
                    line[i]=' ';
                    buffer[top] = ' ';
                }
            }
        } else if (line[i] == '}' || line[i] == ']' || line[i] == '>' || line[i] == ')') { // есил вложеные скобки
            if (top == 0) {
                errCount++; // вложеная без пары
                line[i]=' ';
            } else {
                char prevChar = buffer[--top];
                if ((line[i] == ')' && prevChar != '(') || (line[i] == ']' && prevChar != '[') ||
                    (line[i] == '>' && prevChar != '<') || (line[i] == '}' && prevChar != '{')) {
                    errCount++; // вложеная закрывающая другая
                    line[i]=' ';
                    buffer[top] = ' ';
                }
            }
            //   printf("\n!!OK!!\n");
        }
    }
    while (top > 0) {
        errCount++;
        top--;
    }
    free(buffer);
    return errCount;
}

int main() {
    unsigned short input = 0;
    scanf("%hu",&input);
    if(input<1 || input>200) {return 1;}

    int prenos = 0;
    char *line = (char *)malloc(100000 * sizeof(char));

    for (int i = 1; i <= input; i++) {
        scanf("%s", line);
        int length = strlenBetta(line);
        if(normalize(line,length)) {
            printf("Error Normaliz  e");
            return 1;
        }
        //   printf("%s", lines[i]);
        int errCount = lookFunction(line, length);
        if (prenos == 1) {
            printf("\n");
        } else {
            prenos = 1;
        }
        printf("%d", errCount);
        if(i==input) {
            return 0;
        }


    }
    free(line);
    return 0;
}