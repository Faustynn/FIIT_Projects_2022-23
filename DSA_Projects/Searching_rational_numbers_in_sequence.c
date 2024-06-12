/*
Your task is to create a program that first reads an increasing sequence of rational numbers and remembers this sequence. You can only use data types for whole numbers and characters (e.g. int, long or char) to solve the assignment, not float. These rational numbers have a precision of 0 to 10 digits after the decimal point.
Subsequently, this program will receive an arbitrary rational number at the input (in the same format as the numbers forming the sequence mentioned above), while the essence of this program is to find the given number within the specified sequence for each entered number and to return the position (i.e. ordinal number) of the found number. The sequence of numbers is numbered from number 1. If the entered number is not in the sequence, the program returns number 0.
The input is first a natural number N (in the range from 1 to 50000) expressing the size of the sequence. There are N rows, each row containing one number from the sequence.
This sequence is followed by a natural number M (in the range from 1 to 100000) expressing the number of searched numbers. There are M lines, each line containing one number to be found in the given sequence.
The output is numbers representing the order of the entered search numbers in sequence, with each number in a separate line.

Ukážkový vstup
10
-849243,9810
-555,434
-555,230
-40,10993
0,231
3,141592
239
10934,234
234301,0
294348134
6
-555,23
808
239
0,231
234301,0
-555,434

Ukážkový výstup
3
0
7
5
9
2
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

struct CISLO_STRUKTURA {
    long cisloCele;
    long cisloDrobne;
    int zeros;
    bool negative;
};
typedef struct CISLO_STRUKTURA CISLO;

long strlenBetta(char* str) {
    long i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

CISLO* addZero(char* str) {
    long dotIndex = -1;
    for (long i = strlenBetta(str) - 1; i >= 0; i--) {
        if (str[i] != ',' && str[i] != '.') {
            continue;
        }
        dotIndex = i;
        break;
    }

    CISLO* number = (CISLO*)calloc(1, sizeof(CISLO));

    bool isNegative =
            number->negative = str[0] == '-';

    if (dotIndex != -1) {
        char afterDot[11] = { '\0' };
        for (long i = (isNegative == true ? 1 : 0); i < dotIndex; i++) {
            number->cisloCele = number->cisloCele * 10 + (str[i] - '0');
        }

        for (long i = dotIndex + 1, flag = 0; i < strlenBetta(str); i++) {

            if (!(str[i] >= '0' && str[i] <= '9')) {
                break;
            }

            if (str[i] != '0') {
                flag = 1;
            }
            if (flag == 0) {
                number->zeros++;
            }
            else {
                afterDot[i - dotIndex - 1 - number->zeros] = str[i];
            }
        }
        number->zeros = strlenBetta(afterDot) == 0 ? 0 : number->zeros;
        for (long i = strlenBetta(afterDot) - 1; i != -1; i--) {
            if (afterDot[i] != '0') {
                break;
            }
            afterDot[i] = '\0';
        }
        for (long i = 0; i < strlenBetta(afterDot); i++) {
            number->cisloDrobne = number->cisloDrobne * 10 + (afterDot[i] - '0');
        }
    }
    else {
        for (long i = (isNegative == true ? 1 : 0); i < strlenBetta(str) - 1; i++) {
            number->cisloCele = number->cisloCele * 10 + (str[i] - '0');
        }

    }

    if (number->cisloCele == 0) {
        number->negative = false;
    }

    return number;
}

long binarySearch(CISLO* sequence, long n, CISLO* number) {
    long left = 0;
    long right = n - 1;
    long middle = 0;

    while (left <= right) {
        middle = (left + right) / 2;

        if (number->negative == sequence[middle].negative
            && number->cisloCele == sequence[middle].cisloCele
            && number->cisloDrobne == sequence[middle].cisloDrobne
            && number->zeros == sequence[middle].zeros) {
            return middle + 1;
        }

        if (number->negative == false) {
            if (sequence[middle].negative == true) {
                left = middle + 1;
                continue;
            }
            if (number->cisloCele < sequence[middle].cisloCele) {
                right = middle - 1;
                continue;
            }
            else if (number->cisloCele > sequence[middle].cisloCele) {
                left = middle + 1;
                continue;
            }
            else {
                if (number->zeros < sequence[middle].zeros) {
                    if (number->cisloDrobne == 0) {
                        right = middle - 1;
                        continue;
                    }
                    else {
                        left = middle + 1;
                        continue;
                    }
                    printf("EXCEPTION\n");
                    continue;
                }
                else if (number->zeros > sequence[middle].zeros) {

                    if (sequence[middle].cisloDrobne == 0) {
                        left = middle + 1;
                        continue;
                    }
                    else {
                        right = middle - 1;
                        continue;
                    }
                    printf("EXCEPTION\n");
                    continue;
                }
                else {
                    if (number->cisloDrobne < sequence[middle].cisloDrobne) {
                        right = middle - 1;
                        continue;
                    }
                    else if (number->cisloDrobne > sequence[middle].cisloDrobne) {
                        left = middle + 1;
                        continue;
                    }
                    else {
                        return middle + 1;
                    }
                }
            }
        }
        else if (number->negative == true) {
            if (sequence[middle].negative == false) {
                right = middle - 1;
                continue;
            }
            if (number->cisloCele < sequence[middle].cisloCele) {
                left = middle + 1;
                continue;
            }
            else if (number->cisloCele > sequence[middle].cisloCele) {
                right = middle - 1;
                continue;
            }
            else {
                if (number->zeros < sequence[middle].zeros) {
                    if (number->cisloDrobne == 0) {
                        left = middle + 1;
                        continue;
                    }
                    else {
                        right = middle - 1;
                        continue;
                    }
                }
                else if (number->zeros > sequence[middle].zeros) {
                    if (sequence[middle].cisloDrobne == 0) {
                        right = middle - 1;
                        continue;
                    }
                    else {
                        left = middle + 1;
                        continue;
                    }
                }
                else {
                    if (number->cisloDrobne < sequence[middle].cisloDrobne) {
                        left = middle + 1;
                        continue;
                    }
                    else if (number->cisloDrobne > sequence[middle].cisloDrobne) {
                        right = middle - 1;
                        continue;
                    }
                    else {
                        return middle + 1;
                    }
                }
            }
        }

    }
    return 0;
}

int main() {
    long n = 0;
    scanf("%lld", &n);

    CISLO* vstup = (CISLO*)calloc(n, sizeof(CISLO));
    char line[100];
    fgets(line, sizeof line, stdin);

    for (long i = 0; i < n; i++) {
        fgets(line, sizeof line, stdin);
        vstup[i] = *addZero(line);
    }



    long m = 0;
    scanf("%lld", &m);
    fgets(line, sizeof line, stdin);

    for (long i = 0; i < m; i++) {
        fgets(line, sizeof line, stdin);

        if (line[strlenBetta(line) - 1] != '\n') {
            line[strlenBetta(line)] = '\n';
            line[strlenBetta(line) + 1] = '\0';
        }

        CISLO* number = addZero(line);
        printf("%lld%s", binarySearch(vstup, n, number), i != m -1 ? "\n" : "");
        free(number);
    }

    free(vstup);
}