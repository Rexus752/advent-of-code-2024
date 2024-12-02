/**
 * @brief Sorts an array using the Merge Sort algorithm.
 *
 * This function sorts an array made of generic elements (void pointers)
 * using a comparison function defined by the user and the Merge Sort algorithm.
 *
 * @param base   Pointer to the first element of the array to be sorted.
 * @param nitems Number of elements in the array to be sorted.
 * @param size   Size (in bytes) of each element in the array.
 * @param compar Comparison function that defines the order of the elements.
 *               Given two pointers to elements in the array, it returns:
 *               - a positive number if the first element is greater than the second,
 *               - 0 if the two elements are equal,
 *               - a negative number if the first element is less than the second.
 */
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

/**
 * @brief Sorts an array using the Quick Sort algorithm.
 *
 * This function sorts an array made of generic elements (void pointers)
 * using a comparison function defined by the user and the Quick Sort algorithm.
 *
 * @param base   Pointer to the first element of the array to be sorted.
 * @param nitems Number of elements in the array to be sorted.
 * @param size   Size (in bytes) of each element in the array.
 * @param compar Comparison function that defines the order of the elements.
 *               Given two pointers to elements in the array, it returns:
 *               - a positive number if the first element is greater than the second,
 *               - 0 if the two elements are equal,
 *               - a negative number if the first element is less than the second.
 */
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
