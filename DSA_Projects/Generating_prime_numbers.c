/*
Your task is to generate all the prime numbers that are in the specified interval, i.e. which are greater than or equal to the first number entered and at the same time less than or equal to the second number entered.
The input is two numbers in the range from 0 to 1000000, which are separated by one space, and which represent the interval mentioned above.
The output is a list of generated prime numbers falling within this interval, with the numbers separated by a comma and a space.

Ukážkový vstup
7 29

Ukážkový výstup
7, 11, 13, 17, 19, 23, 29
*/


#include <stdio.h>
#include <stdlib.h>

int prime_chek();

int main() {
    unsigned int user_N1, user_N2;
    int pointer = 0;

    scanf("%u %u", &user_N1, &user_N2);

    if (user_N1<2) {user_N1 = 2;}
    for (unsigned int i = user_N1; i <= user_N2; i++) {
        if (prime_chek(i)) {
            if (pointer == 1) {
                printf(", ");
            } else {
                pointer = 1;
            }
            printf("%u", i);
        }
    }
    return 0;
}

int prime_chek (unsigned int N) {
    if (N <= 1) {return 0;}
    if (N <= 3) {return 1;}
    if (N % 2 == 0 || N % 3 == 0) {return 0;}
    for (unsigned int i = 5; i * i <= N; i += 6) {
        if (N % i == 0 || N % (i + 2) == 0) {return 0;}
    }
    return 1;
}