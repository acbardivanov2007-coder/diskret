#ifndef DISKRET_H
#define DISKRET_H

#define MAX_SIZE 50

// Ввод и обработка множества
int input_set(const char* name, char* set);

// Операции над множествами (алгоритм слияния)
int union_sets(char* A, int sizeA, char* B, int sizeB, char* result);
int intersect_sets(char* A, int sizeA, char* B, int sizeB, char* result);
int difference_sets(char* A, int sizeA, char* B, int sizeB, char* result);
int is_subset(char* A, int sizeA, char* B, int sizeB);

// Вспомогательные функции
void print_set(const char* name, char* set, int size);
void clear_input();

#endif

