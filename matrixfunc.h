#ifndef MATRIXFUNC_H
#define MATRIXFUNC_H

#include <stddef.h>

void menu(void);
void buf_clean(void);
void index_min_elem(int *matptr, size_t rows, size_t cols);
int sum_val_less_k(int *matptr, size_t rows, size_t cols, int k);
void index_last_positive_val(int *matptr, size_t rows, size_t cols);

#endif