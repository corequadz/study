#include <stdio.h>
#include <conio.h>
#define MAX_N 20

int main() {
    int n = 0;
    int matrix[MAX_N][MAX_N] = {0};
    char ch = 0;
    while (ch != 13) {
        ch = getch();
        if (ch >= '0' && ch <= '9') {
            printf("%c", ch);
            n *= 10;
            n += ch - '0';
        }
    }
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



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d", matrix[i][j]);
        printf("\n");
    }
}
