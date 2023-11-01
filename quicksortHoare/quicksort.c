#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont = 0;
char *paths[] = {
    "/Com Duplicidade/Aleatorio/dtaleat%sdup0.txt",
    "/Com Duplicidade/Concavo-DecresceCresce/dtconcv%sdup0.txt",
    "/Com Duplicidade/Convexo-CresceDescresce/dtconvx%sdup0.txt",
    "/Com Duplicidade/Descrescente/dtdecre%sdup0.txt",
    "/Com Duplicidade/Crescente/dtcresc%sdup0.txt",
    "/Sem Duplicidade/Aleatorio/dtaleat%suni0.txt",
    "/Sem Duplicidade/Concavo-DecresceCresce/dtconcv%suni0.txt",
    "/Sem Duplicidade/Convexo-CresceDescresce/dtconvx%suni0.txt",
    "/Sem Duplicidade/Crescente/dtcresc%suni0.txt",
    "/Sem Duplicidade/Descrescente/dtdecre%suni0.txt",
    };

char *tipo_dado[] = {
    "Com duplicidade - Aleatorio",
    "Com duplicidade - Concavo-DecresceCresce",
    "Com duplicidade - Convexo-CresceDecresce",
    "Com duplicidade - Crescente",
    "Com duplicidade - Decrescente",

    "Sem duplicidade - Aleatorio",
    "Sem duplicidade - Concavo-DecresceCresce",
    "Sem duplicidade - Convexo-CresceDecresce",
    "Sem duplicidade - Crescente",
    "Sem duplicidade - Decrescente",
};

char *tamanho_dado[] = {
    "10", "50", "100", "500", "1k", "5k", "10k", "50k", "100k"
};

int tamanho_dado_int[] = {
    10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000
};


void swap(int *a, int *b);
void quicksort(int array[], int lenght);
void quicksort_recursion(int array[], int start, int end);
int partition(int array[], int start , int end);
void str_replace(char *string, const char *search, const char *replace) {
    char *pos = string;
    while ((pos = strstr(pos, search)) != NULL) {
        memmove(pos + strlen(replace), pos + strlen(search), strlen(pos + strlen(search)) + 1);
        memcpy(pos, replace, strlen(replace));
        pos += strlen(replace);
    }
}

char* build_path_name(int j_index, int k_index) {
    char path[500];
    sprintf(path, "C:\\Users\\vitor.pirolo\\aps-ordenacao\\Dados\\%s", tamanho_dado[j_index]);
    char tamanho_dado_char[10];
    sprintf(tamanho_dado_char, "%s", tamanho_dado[j_index]);
    strcat(path, paths[k_index]);
    str_replace(path, "%s", tamanho_dado_char);

    char *result = malloc(strlen(path) + 1);
    strcpy(result, path);
    return result;
}

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) {
        swap(&arr[low], &arr[mid]);
    }

    if (arr[low] > arr[high]) {
        swap(&arr[low], &arr[high]);
    }

    if (arr[mid] > arr[high]) {
        swap(&arr[mid], &arr[high]);
    }

    return arr[mid];
}

int main() {
    for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 10; k++) {
            
            FILE* arq;
            char *path = build_path_name(j, k);
            arq = fopen(path, "r");
            if (arq != NULL) {
                int x, i = 0;
                int V[tamanho_dado_int[j]];
                while (fscanf(arq, "%d", &x) != EOF) {
                    V[i] = x;
                    i++;
                }
                quicksort(V, tamanho_dado_int[j]);
                cont = 0;
                quicksort(V, tamanho_dado_int[j]);
                printf("%s %s - Iteracoes: %d\n", tamanho_dado[j], tipo_dado[k], cont);
            }
        }
    }

    return 0;
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
    int pivot_value = medianOfThree(array,start,end);
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