#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

int main() {
	int count[3] = { 30000, 60000, 100000 };
	srand(time(NULL));
	int n = 0;
	double t1, t2, delta;
	
	for (int i = 0; i < 3; i++) {
		n = count[i];
		double* arr = myMalloc(n);

		for (int j = 0; j < n; j++)
			arr[j] = 121.0 + rand() % 1000;

		printf("count = %d \n \n", count[i]);

		t1 = clock();
		bubblesort(arr, n);
		t2 = clock();
		delta = (t2 - t1) / (CLOCKS_PER_SEC);
		printf("bubblesort: \n");
		for (int i = 1000; i < 26001; i += 5000)
			printf("%.2lf \n", arr[i]);
		printf("time = %lf \n", delta);


		printf("\n \n");

		t1 = clock();
		selectsort(arr, n);
		t2 = clock();
		delta = (t2 - t1) / (CLOCKS_PER_SEC);
		printf("selectsort: \n");
		for (int i = 1000; i < 26001; i += 5000)
			printf("%.2lf \n", arr[i]);
		printf("time = %lf \n", delta);


		printf("\n \n");

		t1 = clock();
		quicksort(arr, n);
		t2 = clock();
		delta = (t2 - t1) / (CLOCKS_PER_SEC);
		printf("quicksort: \n");
		for (int i = 1000; i < 26001; i += 5000)
			printf("%.2lf \n", arr[i]);
		printf("time = %lf \n", delta);

		printf("\n \n");


		free(arr);
	}
	return 0;
}

