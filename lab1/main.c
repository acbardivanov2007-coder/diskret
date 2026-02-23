#include <stdio.h>
#include <stdlib.h>
#include "diskret.h"

int main() {
    char A[MAX_SIZE], B[MAX_SIZE], res[MAX_SIZE*2];
    int sizeA = 0, sizeB = 0, sizeRes = 0;
    int choice;
    
    printf("Лаб 1: Множества\n");
    
    while (1) {
        // Ввод множеств
        printf("\nНовый ввод\n");
        sizeA = input_set("A", A);
        sizeB = input_set("B", B);
        
        while (1) {
            // Меню
            printf("\nОперации\n");
            printf("1 - A объединение B\n");
            printf("2 - A пересечение B\n");
            printf("3 - A разность B\n");
            printf("4 - B разность A\n");
            printf("5 - A подмножество B\n");
            printf("6 - B подмножество A\n");
            printf("7 - Новые множества\n");
            printf("0 - Выход\n");
            printf("Выбор: ");
            
            scanf("%d", &choice);
            clear_input();
            
            if (choice == 0) {
                printf("Выход\n");
                return 0;
            }
            
            if (choice == 7) break;
            
            // Показываем исходные
            printf("\nA = "); print_set("", A, sizeA);
            printf("B = "); print_set("", B, sizeB);
            
            // Операции
            switch(choice) {
                case 1:
                    sizeRes = union_sets(A, sizeA, B, sizeB, res);
                    printf("A ∪ B = "); print_set("", res, sizeRes);
                    break;
                case 2:
                    sizeRes = intersect_sets(A, sizeA, B, sizeB, res);
                    printf("A ∩ B = "); print_set("", res, sizeRes);
                    break;
                case 3:
                    sizeRes = difference_sets(A, sizeA, B, sizeB, res);
                    printf("A \\ B = "); print_set("", res, sizeRes);
                    break;
                case 4:
                    sizeRes = difference_sets(B, sizeB, A, sizeA, res);
                    printf("B \\ A = "); print_set("", res, sizeRes);
                    break;
                case 5:
                    if (is_subset(A, sizeA, B, sizeB))
                        printf("A ⊆ B - ДА\n");
                    else
                        printf("A ⊆ B - НЕТ\n");
                    break;
                case 6:
                    if (is_subset(B, sizeB, A, sizeA))
                        printf("B ⊆ A - ДА\n");
                    else
                        printf("B ⊆ A - НЕТ\n");
                    break;
                default:
                    printf("Неверный выбор\n");
            }
        }
    }
    
    return 0;
}
