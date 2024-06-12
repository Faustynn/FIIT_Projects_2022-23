/* Task 1 for DSA
 * Your task is to create a program that calculates the greatest common divisor for two natural numbers in the interval from 0 to 18446744073709551615.
On the input, there is a natural number N (in the interval from 1 to 100000) on the first line, which expresses how many lines follow on the input.
Each subsequent line contains two natural numbers, separated by one space, which represent the numbers for which the greatest common divisor needs to be calculated.
Write the results of these calculations to the output, each result on a separate line.
Be careful about the input and output format.

Ukážkový vstup
5
30 70
1024 1000
33 88
48 256
500 128

Ukážkový výstup
10
8
11
16
4
*/

#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned int user_riadok;
    scanf("%d", &user_riadok);
    for (int i=1; i <= user_riadok; i++) {
        unsigned long long user_N1,user_N2;
        scanf("%llu %llu", &user_N1,&user_N2);
        while (user_N2 != 0) {
            unsigned long long tmp = user_N2;
            user_N2 = user_N1 % user_N2;
            user_N1 = tmp;
        }
        unsigned long long delitel = user_N1;
        printf("%llu", delitel);
        if (i < user_riadok) {
            printf("\n");
        }
    }
    return 0;
}