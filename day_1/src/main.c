#include <stdio.h>
#include <stdlib.h>
#include "array_sort.h"  // This header files were taken from my asd-lab-24-25 repository

#define MAX_STRING_SIZE 1024

int compare_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {

    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "error: file not found\n");
        exit(EXIT_FAILURE);
    }

    char *buffer = (char *)malloc(MAX_STRING_SIZE);
    if (!buffer) {
        fprintf(stderr, "error: memory allocation failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    int inputs = 0;
    while (fgets(buffer, MAX_STRING_SIZE, file)) {
        inputs++;
    }

    printf("Number of inputs for each array: %d\n", inputs);

    int *left_array = (int *)malloc(inputs * sizeof(int));
    int *right_array = (int *)malloc(inputs * sizeof(int));
    if (!left_array || !right_array) {
        fprintf(stderr, "error: memory allocation failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < inputs; i++) {
        fscanf(file, "%d", left_array + i);
        fscanf(file, "%d", right_array + i);
    }

    fclose(file);

    merge_sort(left_array, inputs, sizeof(int), compare_int);
    merge_sort(right_array, inputs, sizeof(int), compare_int);

    int result = 0;
    for (int i = 0; i < inputs; i++) {
        result += abs(left_array[i] - right_array[i]);
    }

    printf("Result of the first puzzle: %d\n", result);

    result = 0;
    for (int i = 0; i < inputs; i++) {
        for (int j = 0; j < inputs; j++) {
            if (left_array[i] == right_array[j]) {
                result += left_array[i];
            }
        }
    }

    printf("Result of the second puzzle: %d\n", result);
}
