#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main(void) {
    int n, m;
    double matrix[MAX_ROWS][MAX_COLS]; // звичайна матриця
    double* row_ptrs[MAX_ROWS];        // вказівники на рядки
    double** matrix_ptr;               // вказівник на вказівник

    printf("Введіть кількість рядків і стовпців матриці: ");
    scanf("%d %d", &n, &m);

    // Введення матриці та ініціалізація row_ptrs
    for (int i = 0; i < n; i++) {
        row_ptrs[i] = matrix[i]; 
        printf("Введіть елементи %d-го рядка: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]); 
        }
    }

    // Ініціалізація вказівника на вказівник
    matrix_ptr = row_ptrs; // matrix_ptr[i][j]

    int min_row1 = 0, min_row2 = 1; // припущення початкового скалярного добутку
    double min_scalar = 0;

    // Обчислення скалярного добутку першої пари через звичайні індекси
    for (int j = 0; j < m; j++) {
        min_scalar += matrix[min_row1][j] * matrix[min_row2][j];
    }

    // Перебір усіх пар рядків для пошуку мінімального скалярного добутку
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double scalar = 0;

            // Використання row_ptrs (вказівник на рядок)
            double* ptr = row_ptrs[i];
            for (int k = 0; k < m; k++) {
                scalar += ptr[k] * row_ptrs[j][k]; // обчислюємо скалярний добуток рядків [i][j]
            }   

            if (scalar < min_scalar) {
                min_scalar = scalar;
                min_row1 = i;
                min_row2 = j;
            }
        }
    }

    printf("Найменший скалярний добуток між рядками %d і %d: %.2lf\n", min_row1 + 1, min_row2 + 1, min_scalar);

    return 0;
}
