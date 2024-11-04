//9 лаба
#define CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define ROW 9
#define COL 9
#define M_PI 3.14159265358979323846 // Определение числа Pi

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// Прототип функции
void print_pentagon(int radius, char symbol);

int main() {
    setlocale(LC_CTYPE, "RUS");

    // 1. Таблица умножения
    int row, col;
    printf("\nТаблица умножения\n");
    for (row = 1; row <= ROW; ++row) {
        for (col = 1; col <= row; col++)
            printf("%5d", col * row);
        printf("\n");
    }

    printf("\nПолная таблица умножения\n");
    for (row = 1; row <= ROW; ++row) {
        for (col = 1; col <= COL; ++col) {
            printf("%d * %d = %-3d ", col, row, col * row);
        }
        printf("\n");
    }

    // 2. Анализ числа
    while (1) {
        long long num; // Изменено на long long для больших чисел
        int digit, count3 = 0, lastDigit = -1, lastDigitCount = 1, evenCount = 0, greater5Count = 0, oddSum = 0, sum7 = 0;
        long long allProduct = 1; // Изменено на long long
        int secondDigit = -1; // Хранит вторую цифру
        int evenSum = 0, sameAdjacentDigits = 0;
        int numDigits = 0;

        printf("Введите число: ");
        scanf_s("%lld", &num); // Изменено на long long

        long long temp = num; // Для дальнейшей работы с цифрами
        int prevDigit = -1; // Для сравнения с предыдущей цифрой
        while (temp > 0) {
            digit = temp % 10;
            temp = temp / 10;
            numDigits++;

            if (digit == 3) {
                count3++;
            }

            if (digit == lastDigit) {
                lastDigitCount++;
            }
            else {
                lastDigit = digit;
                lastDigitCount = 1;
            }

            if (digit % 2 == 0) {
                evenCount++;
                evenSum += digit;
            }

            if (digit > 5) {
                greater5Count++;
            }

            if (digit % 2 != 0) {
                oddSum += digit;
            }

            if (digit >= 7) {
                sum7 += digit;
            }

            if (digit != 0) {
                allProduct *= digit;
            }

            // Сохранение второй цифры (если она существует)
            if (numDigits == 2) {
                secondDigit = digit;
            }

            // Проверка на соседние одинаковые цифры
            if (numDigits > 1 && digit == prevDigit) {
                sameAdjacentDigits = 1;
            }
            prevDigit = digit; // Обновление предыдущей цифры
        }

        // Вычисление суммы первой и второй половины
        int halfDigits = numDigits / 2;
        int firstHalfSum = 0, secondHalfSum = 0;
        temp = num; // Снова используем оригинальное число
        for (int i = 0; i < numDigits; i++) {
            digit = temp % 10;
            temp = temp / 10;

            if (i < halfDigits) {
                firstHalfSum += digit;
            }
            else {
                secondHalfSum += digit;
            }
        }

        printf("1) Количество цифр 3: %d\n", count3);
        printf("2) Количество повторений последней цифры: %d\n", lastDigitCount);
        printf("3) Количество четных цифр: %d\n", evenCount);
        printf("4) Количество цифр больше 5: %d\n", greater5Count);
        printf("5) Сумма нечетных цифр: %d\n", oddSum);
        printf("6) Сумма цифр больше или равно 7: %d\n", sum7);
        printf("7) Произведение всех цифр, исключая 0: %lld\n", allProduct);
        printf("8) Вторая цифра: %d\n", secondDigit);
        printf("9) Сумма четных цифр: %d\n", evenSum);
        printf("10) Рядом расположенные одинаковые цифры: %s\n", sameAdjacentDigits ? "Да" : "Нет");
        printf("11) Сумма первой и второй половины равны: %s\n", firstHalfSum == secondHalfSum ? "Да" : "Нет");
        printf("12) Произведение четных и нечетных цифр: %d\n", evenSum * oddSum);

        char a;
        printf("Продолжить? (Да - y, Нет - n): ");
        scanf_s(" %c", &a);

        if (a == 'n') {
            break;
        }
    }

    // 3. Рисование пентагона
    int radius;
    char symbol;
    printf("Введите радиус (количество символов): ");
    scanf_s("%d", &radius);
    printf("Введите символ: ");
    scanf_s(" %c", &symbol);
    print_pentagon(radius, symbol);

    return 0;
}

void print_pentagon(int radius, char symbol) {
    // Печать верхней части
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }

    // Печать нижней части
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < 2 * radius - 1; j++) {
            if (j == 0 || j == 2 * radius - 2) {
                printf("%c", symbol);
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}
