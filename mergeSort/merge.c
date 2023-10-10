#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int arr[], int length);

void merge_sort_recursion(int arr[], int l, int r);

void merge_sorted(int arr[], int l, int m, int r);

void merge_sort(int arr[], int length) {

    merge_sort_recursion(arr, 0, length - 1);
}

void merge_sort_recursion(int arr[], int l, int r) {
    
    if(l < r) {
        int m = l + (r - l) / 2;

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

    for (i = 0; i < left_length; i++) {
        temp_left[i] = arr[l + i];
    }

    for (j = 0; j < right_length; j++) {
        temp_right[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < left_length && j < right_length) {
        if (temp_left[i] <= temp_right[j]) {
            arr[k++] = temp_left[i++];
        } else {
            arr[k++] = temp_right[j++];
        }
    }

    while (i < left_length) {
        arr[k++] = temp_left[i++];
    }

    while (j < right_length) {
        arr[k++] = temp_right[j++];
    }
}

int main(){

    clock_t tic = clock();

    FILE *arq;

    arq = fopen("C:/Users/mathe/aps-ordenacao/N1500.txt", "r");
    if(arq != NULL)
    {
        int x, i = 1;
        int V[1500];
        while(fscanf(arq, "%d", &x)!=EOF)
        {
            V[i] = x;
            i++;
        }
        merge_sort(V, 1500);
 
        for (int i = 0; i < 1500; i++) {
            printf ("%d ", V[i]);
        }

    }


    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}