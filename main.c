#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void inputArray(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Введіть елемент %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

double calculateResult(double *arr1, int size1, double *arr2, int size2, char formula) {
    double result = 0.0;
    
    if (formula == 'A') {
        for (int i = 0; i < size1; i++) {
            result += arr1[i] * sin(arr1[i]);
        }
        for (int i = 0; i < size1; i++) {
            result += arr1[i] * arr1[i] * cos(arr1[i]);
        }
    } else if (formula == 'B') {
        for (int i = 0; i < size1; i++) {
            result += arr1[i] * cos(arr1[i]);
        }
        for (int i = 0; i < size2; i++) {
            result += arr2[i] * arr2[i] * sin(arr2[i]);
        }
    } else if (formula == 'C') {
        for (int i = 0; i < size1; i++) {
            result += arr1[i] * sin(arr1[i]);
        }
        for (int i = 0; i < size2; i++) {
            result += arr2[i] * arr2[i] * sin(arr2[i]);
        }
    } else if (formula == 'D') {
        for (int i = 0; i < size1; i++) {
            result += arr1[i] * cos(arr1[i]);
        }
        for (int i = 0; i < size2; i++) {
            result += arr2[i] * arr2[i] * cos(arr2[i]);
        }
    }
    return result;
}

int main() {
    system("chcp 65001");
    int nx, ny, nz, nq;
    printf("Введіть кількість елементів для масиву x: ");
    scanf("%d", &nx);
    double *x = (double *)malloc(nx * sizeof(double));
    inputArray(x, nx);
    
    printf("Введіть кількість елементів для масиву y: ");
    scanf("%d", &ny);
    double *y = (double *)malloc(ny * sizeof(double));
    inputArray(y, ny);
    
    printf("Введіть кількість елементів для масиву z: ");
    scanf("%d", &nz);
    double *z = (double *)malloc(nz * sizeof(double));
    inputArray(z, nz);
    
    printf("Введіть кількість елементів для масиву q: ");
    scanf("%d", &nq);
    double *q = (double *)malloc(nq * sizeof(double));
    inputArray(q, nq);
    
    char choice;
    printf("Яке значення хочете обчислити? (A, B, C, D): ");
    scanf(" %c", &choice);
    
    double result = 0.0;
    switch (choice) {
        case 'A':
            result = calculateResult(x, nx, x, nx, 'A');
            break;
        case 'B':
            result = calculateResult(y, ny, y, ny, 'B');
            break;
        case 'C':
            result = calculateResult(z, nz, y, ny, 'C');
            break;
        case 'D':
            result = calculateResult(q, nq, q, nq, 'D');
            break;
        default:
            printf("Невірно.\n");
            return 1;
    }
    
    printf("Результат: %.2lf\n", result);
    return 0;
}
