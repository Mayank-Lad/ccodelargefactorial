#include <stdio.h>
#include <time.h>

#define MAX_DIGITS 100000

void multiply(int result[], int num, int *size) {
    int carry = 0;
    for (int i = 0; i < *size; i++) {
        int prod = result[i] * num + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        result[*size] = carry % 10;
        carry /= 10;
        (*size)++;
    }
}

void factorial(int n) {
    int result[MAX_DIGITS] = {0};
    result[0] = 1; 
    int size = 1;
    
    for (int i = 2; i <= n; i++) {
        multiply(result, i, &size);
    }
    
    printf("Factorial of %d is: ", n);
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    
    time_t start_time, end_time;
    double elapsed_time;
    
    start_time = time(NULL);
    factorial(number);
    end_time = time(NULL);
    
    elapsed_time = difftime(end_time, start_time);
    printf("Time taken: %f seconds\n", elapsed_time);
    
    return 0;
}
