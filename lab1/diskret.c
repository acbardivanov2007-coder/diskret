#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "diskr.h"

void clear_input() { // очищаем буфер
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int input_set(const char* name, char* set) { // ввод множества
    char buffer[256];
    int size = 0;
    
    while (1) {
        printf("Введите элементы %s: ", name);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Ошибка, повторите\n");
            continue;
        }
        // Убираем \n
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
            len--;
        }
        if (len == 0) {
            printf("Пустота, повторите ввод\n");
            continue;
        }
        // Проверка на буквы
        int ok = 1;
        for (size_t i = 0; i < len; i++) {
            if (!isalpha(buffer[i])) {
                printf("Символ '%c' не является буквой\n", buffer[i]);
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        // Копируем
        for (size_t i = 0; i < len; i++) {
            set[i] = tolower(buffer[i]);
        }
        size = (int)len;
        break;
    }
    
    //сортировка (пузырек)
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (set[i] > set[j]) {
                char tmp = set[i];
                set[i] = set[j];
                set[j] = tmp;
            }
        }
    }
    // Удаляем повторы
    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || set[i] != set[new_size-1]) {
            set[new_size++] = set[i];
        }
    }
    printf("Множество %s: {", name);
    for (int i = 0; i < new_size; i++) {
        printf("%c", set[i]);
        if (i < new_size-1) printf(", ");
    }
    printf("}\n");
    
    return new_size;
}

void print_set(const char* name, char* set, int size) { // вывод
    printf("%s{", name);
    for (int i = 0; i < size; i++) {
        printf("%c", set[i]);
        if (i < size-1) printf(", ");
    }
    printf("}\n");
}
int union_sets(char* A, int sizeA, char* B, int sizeB, char* result) { // объединение 
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i] == B[j]) {
            result[k++] = A[i++];
            j++;
        } else if (A[i] < B[j]) {
            result[k++] = A[i++];
        } else {
            result[k++] = B[j++];
        }
    }
    while (i < sizeA) result[k++] = A[i++];
    while (j < sizeB) result[k++] = B[j++];
    return k;
}
int intersect_sets(char* A, int sizeA, char* B, int sizeB, char* result) { // пересечение
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i] == B[j]) {
            result[k++] = A[i++];
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    return k;
}
int difference_sets(char* A, int sizeA, char* B, int sizeB, char* result) { // разность
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i] == B[j]) {
            i++;
            j++;
        } else if (A[i] < B[j]) {
            result[k++] = A[i++];
        } else {
            j++;
        }
    }
    while (i < sizeA) result[k++] = A[i++];
    return k;
}

int is_subset(char* A, int sizeA, char* B, int sizeB) { // подмножество 
    int i = 0, j = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i] == B[j]) {
            i++;
            j++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            return 0;
        }
    }
    return i == sizeA;
}
