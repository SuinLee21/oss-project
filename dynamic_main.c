#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    int number = 0;
    void *handle;
    void (*prime_factors)(int);
    char *error;
    
    handle = dlopen("./libprimefactors.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
	exit(1);
    }
    
    prime_factors = dlsym(handle, "prime_factors");
    if ((error = dlerror()) != NULL) {
 	fprintf(stderr, "%s\n", error);
 	exit(1);
    }

    while(1) {
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

    if (dlclose(handle) < 0) {
	fprintf(stderr, "%s\n", dlerror());
	exit(1);
    }

    return 0;
}
