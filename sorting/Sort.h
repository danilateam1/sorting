#pragma once
double* myMalloc(int n) {
	return(double*)malloc(n * sizeof(double));
}

void swap(double* a, double* b) {
	double tmp = *a;
	*a = *b;
	*b = tmp;
}


void bubblesort(double* arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}	
	}
}
void selectsort(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		int min = arr[i];
		int number = i;
		for (int j = i; j < n; j++) {
			if (min > arr[j]) {
				min = arr[j];
				number = j;
			}
		}
		swap(&arr[i], &arr[number]);
	}
 }

void quicksort(double* arr, int n) {
	int i = 0;
	int j = n - 1;
	int opora = arr[n/2];

	do {
		while (arr[i] < opora) {
			i++;
		}
		while (arr[j] > opora) {
			j--;
		}
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0) {
		quicksort(&arr[0], j + 1);
	}
	if (i < n) {
		quicksort(&arr[i], n - i);
	}
}