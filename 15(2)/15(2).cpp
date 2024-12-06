#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int res(int* row, int size) {
    int res = 1;
    int nomin = 0;
    for (int i = 0; i < size; i++) {
        if (row[i] < 0) {
            res *= row[i];
            nomin = 1;
        }
    }
    if (nomin == 1) 
        return res;
   
    else
        return 0;
}

void swap(int* row1, int* row2, int col) {
    for (int i = 0; i < col; i++) {
        int t = row1[i];
        row1[i] = row2[i];
        row2[i] = t;
    }
}


void merge(int** p, int left, int mid, int right, int col) {
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        int i1 = res(p[i], col);
        int j1 = res(p[j], col);

        if (i1 <= j1) {
            i++;
        }
        else {
            
            for (int k = j; k > i; k--) {
                swap(p[k], p[k - 1], col);
            }
            i++;
            mid++;
            j++;
        }
    }
}

void mergesort(int** p, int left, int right, int col) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergesort(p, left, mid, col);
    mergesort(p, mid + 1, right, col);

    merge(p, left, mid, right, col);
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("введите размеры массива : ");
    while (1) {
        if (scanf_s("%d%d", &n, &m) != 2 || getchar() != '\n') {
            printf("ошибка, попробуйте снова : ");
            while (getchar() != '\n');
        }
        else  if ( n <= 0 || m <= 0) {
            printf("введите натуральные числа : ");
            while (getchar() != '\n');
        }
         else  if (n > 1000000 || m > 1000000) {
            printf("ошибка, попробуйте снова : ");
            while (getchar() != '\n');
        }
        else
            break;
    }
  

    int** p = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        p[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = rand() % 10 - 7; 
        }
    }

    printf("ваш массив\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", p[i][j]);
        }
        printf("\n");
    }

    mergesort(p, 0, n - 1, m);

    puts("новый массив");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", p[i][j]);
        }
        printf("\n");
    }
    free(p);

}
