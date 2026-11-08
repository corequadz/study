    #include <stdio.h>
    #include <conio.h>
    #include <windows.h>
    #include <math.h>
    #include <stdbool.h>
    #define MAX_N 20


    void print_mat(int matrix[MAX_N][MAX_N], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%7d", matrix[i][j]);
            printf("\n");
        }
    }


    int input(char s, char e) {
        char ch = 0;
        int n = 0;
        while (ch != 13) {
            ch = getch();
            if (ch >= s && ch <= e) {
                printf("%c", ch);
                n *= 10;
                n += ch - '0';
            }
        }
        return n;
    }


    void pow_m(int matrix[MAX_N][MAX_N], int n) {
        int t[MAX_N][MAX_N];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                t[i][j] = matrix[i][j] * matrix[i][j];
            }
        }
        print_mat(t, n);
    }


    double det(int matrix[MAX_N][MAX_N], int n) {
        double t[MAX_N][MAX_N];
        double res = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                t[i][j] = matrix[i][j];
            }
        }

        for (int c = 0; c < n; c++) {
            int p = c;
            for (int r = c + 1; r < n; r++)
                if (fabs(t[r][c]) > fabs(t[p][c]))
                    p = r;
            if (fabs(t[p][c]) < 1e-9)
                return 0;
            if (p != c) {
                for (int k = 0; k < n; k++) {
                    double tmp = t[c][k];
                    t[c][k] = t[p][k];
                    t[p][k] = tmp;
                }
                res = -res;
            }
            for (int r = c + 1; r < n; r++) {
                double f = t[r][c] / t[c][c];
                for (int k = c; k < n; k++)
                    t[r][k] -= f * t[c][k];
            }
            res *= t[c][c];
        }
        return res;
    }


    void gen_mat(int matrix[MAX_N][MAX_N], int n) {
        int m = n;
        int num = 1;
        printf("\n");

        while (m > 0) {
            for (int j = 0; j < m; j++) {
                matrix[m - 1][j] = num;
                num++;
            }

            for (int i = m - 2; i >= 0; i--) {
                matrix[i][m - 1] = num;
                num++;
            }
            m--;

            for (int i = 0; i < m; i++) {
                matrix[i][m - 1] = num;
                num++;
            }

            for (int j = m - 2; j >= 0; j--) {
                matrix[m - 1][j] = num;
                num++;
            }
            m--;
        }

    }


    int main() {
        SetConsoleOutputCP(1251);
        int matrix[MAX_N][MAX_N] = {0};
        while(true) {
            printf("Выберите режим (1 - генерация, 2 - ручной ввод, 0 - выход): ");
            int mode = input('0', '2');
            printf("\n");
            if (mode == 0) {
                break;
            }

            if (mode == 1) {
                printf("Режим генерации\n");
                int n = 0;
                while (true) {
                    printf("Введите размер матрицы (от 4 до 20): ");
                    n = input('0', '9');
                    if (n < 4 || n > 20) {
                        printf("Введено недопустимое значение (размер матрицы от 4 до 20)\n");
                    } else {
                        break;
                    }
                }
                gen_mat(matrix, n);
                printf("Матрица сгенерированна\n");
                while (true) {
                    printf("Режим генерации\n");
                    printf("Выберите действие (1 - вывести матрицу, 2 - возвести все элементы в квадрат, 3 - вычислить определитель, 0 - выход): ");
                    int act = input('0', '9');
                    printf("\n");
                    if (act == 0) {
                        break;
                    } else if (act == 1) {
                        printf("Матрица:\n");
                        print_mat(matrix, n);
                    } else if (act == 2) {
                        pow_m(matrix, n);
                        printf("Операция выполнена\n");
                    } else if (act == 3) {
                        printf("Определитель: %f", det(matrix, n));
                        printf("\n");
                    }
                }
            }
        }
    }
