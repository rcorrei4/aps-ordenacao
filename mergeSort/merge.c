#include <stdio.h>
#include <stdlib.h>


void merge_sort(int arr[], int length);

void merge_sort_recursion(int arr[], int l, int r);

void merge_sorted(int arr[], int l, int m, int r);

void merge_sort(int arr[], int length) {

    merge_sort_recursion(arr, 0, length - 1);
}

void merge_sort_recursion(int arr[], int l, int r) {
    
    if(l < r) {
        int m = l + (r-1) / 2;

        merge_sort_recursion(arr, l, m); // porção esquerda do array
        merge_sort_recursion(arr, m + 1, r); // porção direita do array

        merge_sorted(arr, l, m, r);
    }
}

void merge_sorted(int arr[], int l, int m, int r) {

    int left_length = m - l + 1;
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for(int i = 0; i < left_length; i++) {
        temp_left[i] = arr[l + 1];
    }

    for (int i = 0; i < right_length; i++) {
        temp_right[i] = arr[m + 1 + i];
    }

    for (i = 0, j = 0, k = l; k <= r; k++){
        if((i < left_length) &&
        (j >= right_length) || temp_left[i] <= temp_right[j])
        {
            arr[k] = temp_left[i];
            i++;
        } else {
            arr[k] = temp_right[j];
            j++;
        }
    }

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