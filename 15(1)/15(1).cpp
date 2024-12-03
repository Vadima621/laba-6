#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int element(int* p, int col ) {
	int k=0;
	for (int i = 0; i < col; ++i) {
		if (p[i] > 0) {
			k = i+1;
			break;
		}
	}
	return k;
}
void scanfarr(int* p, int col) {
	for (int i = 0; i < col; ++i) {
		p[i] = rand() % 10 -5 ;
		printf("%d ", p[i]);
	}
	printf("\n");
}
void scanfarr2(int* p, int* p1, int col, int el) {
	int n = 0;
	printf("массив после первого положительного\n");
	for (int i = el; i < col; ++i) {
		p1[n] = p[i];
		printf("%d ", p1[n]);
		n++;
	}
	printf("\n");
}


int main() {
	srand(time(NULL));
	int col, d, el, size;
	printf("введите количество эллементов ");
	while (1) {
		scanf_s("%3d", &col);
		if (getchar() != '\n') {
			printf("ошибка, попробуйте снова: ");
			while(getchar() != '\n')
			continue;
		}
		else if (col <=-1 || col>1000){
			printf("ошибка, введите натуральное число: ");
			while (getchar() != '\n');
			continue;
		}
		else if (col == 0) {
			printf("в массиве нет эллементов");
			exit(0);
		}
		else
			break;
	}
	int* p = (int*)malloc(sizeof(int) * col);

	scanfarr(p, col);
	el = element(p, col);

	size = col - el;
	printf("\n");

	printf("\n");

	int* p1 = (int*)malloc(sizeof(int) * size);

	scanfarr2(p, p1, col, el);

	d = size / 2;
	while (d >= 1) {
		for (int i = d; i < size; ++i) {
			int j = i;
			while (j >= d && p1[j] < p1[j - d]) {
				int tmp = p1[j];
				p1[j] = p1[j - d];
				p1[j - d] = tmp;
				j = j - d;
			}

		}
		d = d / 2;
	}

	printf("новый массив ");
	printf("\n");

	for (int i = 0; i < size; ++i) {
		printf("%d ", p1[i]);
	}


}