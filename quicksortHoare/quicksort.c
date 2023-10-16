#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void quicksort(int array[], int lenght);
void quicksort_recursion(int array[], int start, int end);
int partition(int array[], int start , int end);
int cont = 0;

int main()
{
    FILE *arq;
    arq = fopen("C:\\Users\\vitor.pirolo\\aps-ordenacao\\N1500.txt", "r");
    if(arq != NULL)
    {
        int x, i =0;
        int v[1500];
        while(fscanf(arq,"%d",&x)!=EOF)
        {
            v[i] = x;
            i++;
        }
        quicksort(v, 1500);
        
        for(int i = 0; i< 1500; i++){
            printf("%d ", v[i]);
        }
    }

    printf("\nO numero de comparacoes realizadas foi: %d", cont);

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
            cont++;
        }while(array[i] < pivot_value);

        do{
            j--;
            cont++;
        }while(array[j] > pivot_value);
        if(i >= j){
            return j;
        }
        swap(&array[i], &array[j]);
    }
}