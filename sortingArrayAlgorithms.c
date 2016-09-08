/*
 * sortingArrayAlgorithms.c
 *
 *  Created on: May 24, 2016
 *      Author: n
 */

#include<stdio.h>

/*
 * sort array : Max Sort - without recursion :
 */
static void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void MaxSortNoRecursion(int array[], int n){
	int current_iteration = n-1;
	while(current_iteration > 0){
		int* max = &array[0];
		for(int i = 1 ; i <= current_iteration; i++){
			if(array[i] > *max){
				max = &array[i];
			}
		}
		swap(max, &array[current_iteration]);
		current_iteration--;
	}
}
/*
 * sort array : Max Sort - recursion :
 */
static int* findMaxelem(int array[], int n){
	int* max = &array[0];
	for(int i = 0 ; i < n; i++){
		if(*max < array[i]){
			max = &array[i];
		}
	}
	return max;
}
void MaxSortRecursion(int array[], int n){
	if(n == 1) {
		return;
	}
	int* max = findMaxelem(array,n);
	swap(max,&array[n-1]);
	MaxSortRecursion(array,n-1);
}

/*
 * sort array : bubble Sort - recursion :
 */
void bubbleSort(int array[], int n){
	int current_iteration = n-1;
	while(current_iteration > 0){
		for(int i = 0 ; i < current_iteration ; i++){
			if(array[i] > array[i+1]){
				swap(&array[i], &array[i+1]);
			}
		}
		current_iteration--;
	}
}

int main1(){
	int array[10] = {5, 7, 4, 33, 21, 77, 22, 33, 31, 14};
	MaxSortNoRecursion(array, 10);
	for(int i = 0 ; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n\n");
	int array1[10] = {5, 7, 4, 33, 21, 77, 22, 33, 31, 14};
	MaxSortRecursion(array1, 10);
	for(int i = 0 ; i < 10; i++){
		printf("%d ", array1[i]);
	}
	printf("\n\n");
	int array2[10] = {5, 7, 4, 33, 21, 77, 22, 33, 31, 14};
	bubbleSort(array2, 10);
	for(int i = 0 ; i < 10; i++){
		printf("%d ", array2[i]);
	}
	return 1;
}

