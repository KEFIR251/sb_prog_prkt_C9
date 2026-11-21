#include <stdio.h>
#include "matrixfunc.h"
/*
    var0 4 15 23
    4 Поиск индексов (строка и столбец) минимального элемента матрицы
    15 Вычисление суммы элементов, значения которых выше заданного k
    23 Поиск индексов последнего положительного элемента матрицы при обходе по строкам
*/

int main(void) {
    char com;
    int rows, cols;
    int k, flag_a = 0;

    menu();
    while(flag_a == 0 && (com = getchar()) != EOF) {
        if (com == '\n') continue;
        buf_clean();

        switch(com) {
            case 'a':
                printf("Введите кол-во строк и столбцов: ");
                scanf("%d %d", &rows, &cols);
                buf_clean();
                flag_a = 1;
                break;
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                printf("Сначала задайте размер матрицы!\n");
                menu();
                break;
            case 'g':
                printf("Бай бай!=)\n");
                menu();
                return 0;
            default:
                printf("Некорректный код команды!\n");
                menu();
                break;
        }
    }

    int matrix[rows][cols];
    
    menu();
    while((com = getchar()) != EOF) {
        if (com == '\n') continue;
        buf_clean();

        switch(com) {
            case 'a':
                printf("Размер матрицы уже задан\n");
                break;

            case 'b':
                printf("Введите значения(заполнения по строкам): ");
                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        scanf("%d", *(matrix + i) + j);
                buf_clean();
                break;

            case 'c':
                printf("Представление матрицы(значения, адреса элементов): \n");
                for(int i = 0; i < rows; i++) {
                    printf("\n");
                    for(int j = 0; j < cols; j++)
                        printf("%d(%p) ", *(*(matrix + i) + j), *(matrix + i) + j);
                }
                printf("\n\n");
                break;

            case 'd':
                printf("Индексы (строка и столбец) минимального элемента матрицы: ");
                index_min_elem(*matrix, rows, cols);
                printf("\n");
                break;

            case 'e':
                printf("Введите значение k: ");
                scanf("%d", &k);
                printf("Сумма элементов матрицы значение котторых выше k: %d",
                sum_val_less_k(*matrix, rows, cols, k));
                buf_clean();
                printf("\n");
                break;
            case 'f':
                printf("Индексы (стока и столбец) последнего положительного элемента матрицы при обходе по строкам: ");
                index_last_positive_val(*matrix, rows, cols);
                printf("\n");
                break;

            case 'g':
                printf("Бай бай!=)\n");
                return 0;

            default:
                printf("Некорректный код команды!\n");
                break;
        }

        menu();
    }

    return 0;
}