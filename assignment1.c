#include <stdio.h>
#include <string.h>
#include <math.h>

int getDigitValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}

int convertToDecimal(char* number, int base) {
    int decimal = 0;
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        int digitValue = getDigitValue(number[i]);
        if (digitValue == -1 || digitValue >= base) {
            printf("Invalid input in custom base representation.\n");
            return -1;
        }
        decimal += digitValue * pow(base, length - i - 1);
    }

    return decimal;
}

void convertToBase(int decimal, int base) {
    int result[100];
    int i = 0;

    while (decimal > 0) {
        result[i] = decimal % base;
        decimal = decimal / base;
        i++;
    }

    printf("The number in base %d is: ", base);

    for (int j = i - 1; j >= 0; j--) {
        if (result[j] < 10) {
            printf("%d", result[j]);
        } else {
            printf("%c", 'A' + result[j] - 10); 
        }
    }
    printf("\n");
}

int main() {
    int task;
    scanf("%d", &task);

    if (task == 1) {
        int d, x;
        scanf("%d %d", &d, &x);
        convertToBase(d, x);
    } else if (task == 2) {
        char input[100];
        int x;
        scanf("%s %d", input, &x);
        int result = convertToDecimal(input, x);
        if (result != -1) {
            printf("The decimal number is: %d\n", result);
        }
    } else {
        printf("Invalid task number.\n");
    }

    return 0;
}
