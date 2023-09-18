#include <stdio.h>
#include <stdlib.h>


void merge_sort(int arr[], int length);

void merge_sort_recursion(int arr[], int l, int r);

void merge_sorted(int arr[], int l, int m, int r);

void merge_sort(int arr[], int length){

    merge_sort_recursion(arr, 0, length - 1);
}

void merge_sort_recursion(int arr[], int l, int r) {
    
    if(l < r) {
        int m = l + (r-1) / 2;

        merge_sort_recursion(arr, l, m); // porção esquerda do array
        merge_sort_recursion(arr, m + 1, r); // porão direita do array

        merge_sorted(arr, l, m, r);
    }
}

void merge_sorted(int arr[], int l, int m, int r) {

    int left_length = m - l + 1;
    int right_length = r - m;

    int *left = (int *)malloc(left_length * sizeof(int));
    int *right = (int *)malloc(right_length * sizeof(int));

    int i, j, k;

    for(int i = 0; i < left_length; i++) {
        left[i] = arr[l + 1];
    }

    for (int i = 0; i < right_length; i++) {
        right[i] = arr[m + 1 + i];
    }

    for (i = 0, j = 0, k = l; k <= r; k++){
        if((i < left_length) &&
        (j >= right_length) || left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }

    free(left);
    free(right);
}

int main(){

    int arr[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    merge_sort(arr, length);
 
    for (int i = 0; i < length; i++) 
        printf ("%d ", arr[i]);
    printf("\n");
    
    return 0;
}