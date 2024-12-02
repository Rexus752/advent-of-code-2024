#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_sort.h"

// Note: void pointers are casted to char * to allow pointer arithmetic

void split(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *), size_t left, size_t right);
void merge(void *base, size_t size, int (*compar)(const void *, const void *), size_t left, size_t middle, size_t right);

void quick_sort_ric(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
void swap(void *a, void *b, size_t size);

void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {

    if (!base) {
        fprintf(stderr, "merge_sort: base parameter cannot be NULL\n");
        exit(EXIT_FAILURE);
    }
    if (!compar) {
        fprintf(stderr, "merge_sort: compar parameter cannot be NULL\n");
        exit(EXIT_FAILURE);
    }

    if (nitems <= 1) return;

    split(base, nitems, size, compar, 0, nitems - 1);
}

void split(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *), size_t left, size_t right) {

    if (left < right) {
        size_t middle = left + (right - left) / 2;

        split(base, nitems, size, compar, left, middle);
        split(base, nitems, size, compar, middle + 1, right);

        merge(base, size, compar, left, middle, right);
    }
}

void merge(void *base, size_t size, int (*compar)(const void *, const void *), size_t left, size_t middle, size_t right) {

    size_t left_array_size = middle - left + 1;
    size_t right_array_size = right - middle;

    char *left_array = (char *)malloc(left_array_size * size);
    char *right_array = (char *)malloc(right_array_size * size);

    if (!left_array || !right_array) {
        fprintf(stderr, "merge: unable to allocate memory for temporary arrays\n");
        exit(EXIT_FAILURE);
    }

    memcpy(left_array, (char *)base + left * size, left_array_size * size);
    memcpy(right_array, (char *)base + (middle + 1) * size, right_array_size * size);

    size_t i = 0, j = 0; // Initial indexes of first and second subarrays
    size_t k = left; // Initial index of merged array
    while (i < left_array_size && j < right_array_size) {
        if (compar(left_array + i * size, right_array + j * size) <= 0) { // left_array[i] <= right_array[j]
            memcpy((char *)base + k * size, left_array + i * size, size);
            i++;
        } else {
            memcpy((char *)base + k * size, right_array + j * size, size);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_array (if any)
    while (i < left_array_size) {
        memcpy((char *)base + k * size, left_array + i * size, size);
        i++;
        k++;
    }

    // Copy the remaining elements of right_array (if any)
    while (j < right_array_size) {
        memcpy((char *)base + k * size, right_array + j * size, size);
        j++;
        k++;
    }

    free(left_array);
    free(right_array);
}

void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {

    if (!base) {
        fprintf(stderr, "quick_sort: base parameter cannot be NULL\n");
        exit(EXIT_FAILURE);
    }
    if (!compar) {
        fprintf(stderr, "quick_sort: compar parameter cannot be NULL\n");
        exit(EXIT_FAILURE);
    }

    quick_sort_ric(base, nitems, size, compar);
}

void quick_sort_ric(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {

    if (nitems <= 1) return; // Array is trivially sorted

    char *pivot = (char *)base + (nitems - 1) * size;
    size_t low = 0, high = nitems - 1, i = 0;

    while (i <= high) {

        int cmp = compar((char *)base + i * size, pivot);

        if (cmp < 0) { // base[i] < pivot

            swap((char *)base + low * size, (char *)base + i * size, size);
            low++;
            i++;

        } else if (cmp > 0) { // base[i] > pivot

            swap((char *)base + high * size, (char *)base + i * size, size);
            high--;

        } else i++;
    }

    quick_sort_ric(base, low, size, compar); // Sort the left partition
    quick_sort_ric((char *)base + (high + 1) * size, nitems - high - 1, size, compar); // Sort the right partition
}

void swap(void *a, void *b, size_t size) {

    if (a == b) return;

    void *temp = malloc(size);
    if (!temp) {
        fprintf(stderr, "swap: unable to allocate memory for temporary variable\n");
        exit(EXIT_FAILURE);
    }

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}
