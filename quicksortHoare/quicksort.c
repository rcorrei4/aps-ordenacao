#include <stdio.h>

void swap(int *a, int *b);
void quicksort(int array[], int lenght);
void quicksort_recursion(int array[], int start, int end);
int partition(int array[], int start , int end);

int main()
{
    int list[] = {5, 6, 9, 8, 4, 4, 2, 7, 1};
    int lenght = 9;

    quicksort(list, lenght);

    for(int i = 0; i< lenght; i++){
        printf("%d ", list[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

void quicksort(int array[], int lenght)
{
    quicksort_recursion(array, 0, lenght -1);
}

void quicksort_recursion(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot_index = partition(array, start, end);
        quicksort_recursion(array, start, pivot_index);
        quicksort_recursion(array, pivot_index +1, end);
    }
}

int partition(int array[], int start, int end)
{
    int pivot_value = array[start];
    int i = start -1;
    int j = end +1;

        while(1){

        do{
            i++;
        }while(array[i] < pivot_value);

        do{
            j--;
        }while(array[j] > pivot_value);
        if(i >= j){
            return j;
        }
        swap(&array[i], &array[j]);
    }
}