#include <stdio.h>
#include <stdlib.h>

int count = 0; // Variável para contar as comparações

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
        count++; // Incrementa o contador de comparações
        maxHeapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    FILE *arq;

    arq = fopen("C:/Users/henri/Downloads/aps-ordenacao-main/aps-ordenacao-main/Dados/100k/Sem Duplicidade/Crescente/dtcresc100kuni0.txt", "r");
    if (arq != NULL) {
        int x, i = 0;
        int V[100000];
        while (fscanf(arq, "%d", &x) != EOF) {
            V[i] = x;
            i++;
        }
        heapSort(V, 100000);

        for (int i = 0; i < 100000; i++) {
            printf("%d\n", V[i]);
        }
        printf("Comparações: %d", count); // Imprime o número de comparações
    }
    return 0;
}