#include <stdio.h>
#include <math.h>
#include "prime_factors.h"

void prime_factors(int number) {
    while (number % 2 == 0) {
        printf("2 ");
        number /= 2;
    }

    for (int i = 3; i <= sqrt(number); i += 2) {
        while (number % i == 0) {
            printf("%d ", i);
            number /= i;
        }
    }

    if (number > 2) {
        printf("%d", number);
    }
}
