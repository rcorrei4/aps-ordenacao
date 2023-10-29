#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
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


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int maior = i;
    int filho_esquerda = 2 * i + 1;
    int filho_direita = 2 * i + 2;

    if (filho_esquerda < n && arr[filho_esquerda] > arr[maior])
        maior = filho_esquerda;

    if (filho_direita < n && arr[filho_direita] > arr[maior])
        maior = filho_direita;

    if (maior != i) {
        swap(&arr[i], &arr[maior]);
        maxHeapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
        count++;

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
        count++;
    }
}

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
    sprintf(path, "C:/Users/ricar/Documents/UNIP/aps-ordenacao/Dados/%s", tamanho_dado[j_index]);
    char tamanho_dado_char[10];
    sprintf(tamanho_dado_char, "%s", tamanho_dado[j_index]);
    strcat(path, paths[k_index]);
    str_replace(path, "%s", tamanho_dado_char);

    char *result = malloc(strlen(path) + 1);
    strcpy(result, path);
    return result;
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
                count = 0; 
                heapSort(V, tamanho_dado_int[j]);
                printf("%s %s - Comparações: %d\n", tamanho_dado[j], tipo_dado[k], count);
            }
        }
    }

    return 0;
}

