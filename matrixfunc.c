#include "matrixfunc.h"
#include <stdio.h>
#include <limits.h>

void menu(void) {
    printf("a   Задать размер матрицы (строки, столбцы)\n");
    printf("b   Заполнить матрицу\n");
    printf("c   Представление матрицы (значения, адреса элементов)\n");
    printf("d   Поиск индексов (строка и столбец) минимального элемента матрицы\n");
    printf("e   Вычисление суммы элементов, значения которых выше заданного k\n");
    printf("f   Поиск индексов последнего положительного элемента матрицы при обходе построкам\n");
    printf("g   Выход\n");
    printf("Выберите пункт: ");
}

void buf_clean(void) {
    int metla;
    while((metla = getchar()) != '\n' && metla != EOF);
}

void index_min_elem(int *matptr, size_t rows, size_t cols) {
    int min_el = INT_MAX;
    int min_index_i = 0, min_index_j = 0;

    for(size_t i = 0; i < rows; i++)
        for(size_t j = 0; j < cols; j++)
            if (*(matptr + i * cols + j) < min_el) {
                min_index_i = i;
                min_index_j = j;
                min_el = *(matptr + i * cols + j);
            }
    
    printf("%d %d", min_index_i, min_index_j);
}

int sum_val_less_k(int *matptr, size_t rows, size_t cols, int k) {
    int sum = 0;

    for(size_t i = 0; i < rows; i++)
        for(size_t j = 0; j < cols; j++)
            if (*(matptr + i * cols + j) > k)
                sum += *(matptr + i * cols + j);
    
    return sum;
}

void index_last_positive_val(int *matptr, size_t rows, size_t cols) {
    int index_i = 0, index_j = 0;
    int flag_positive = 0;

    for(size_t i = 0; i < rows; i++)
        for(size_t j = 0; j < cols; j++)
            if (*(matptr + i * cols + j) > 0) {
                index_i = i;
                index_j = j;
                flag_positive = 1;
            }

    if (flag_positive)
        printf("%d %d", index_i, index_j);
    else
        printf("В матрице нет положительных чисел!");
}