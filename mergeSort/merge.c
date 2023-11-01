#include <stdio.h>
#include <stdlib.h>

int count = 0;

void merge_sort(int arr[], int length);
void merge_sort_recursion(int arr[], int l, int r);
void merge_sorted(int arr[], int l, int m, int r);

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
        count++;
    }

    while (i < left_length) {
        arr[k++] = temp_left[i++];
        count++;
    }

    while (j < right_length) {
        arr[k++] = temp_right[j++];
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
    sprintf(path, "C:\\Users\\mathe\\aps-ordenacao\\Dados\\%s", tamanho_dado[j_index]);
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
                merge_sort(V, tamanho_dado_int[j]);
                count = 0;
                merge_sort(V, tamanho_dado_int[j]);
                printf("%s %s - Iterações: %d\n", tamanho_dado[j], tipo_dado[k], count);
            }
        }
    }

    return 0;
}