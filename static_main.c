#include <stdio.h>
#include "prime_factors.h"

int main() {
    int number = 0;

    while (1) {
        printf("정수를 입력하세요. (0 입력 시 종료): ");
        scanf("%d", &number);

        if (number == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        printf("소인수 분해 결과: ");
        prime_factors(number);
        printf("\n");
    }

    return 0;
}
