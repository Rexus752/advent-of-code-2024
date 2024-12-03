#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 1024
#define MAX_LEVELS_FOR_REPORT 32

bool is_safe_report(int nums[], int size) {

    if (size < 2) return true;

    bool is_ascending = nums[1] > nums[0];

    for (int i = 0; i < size - 1; i++) {

        int diff = abs(nums[i] - nums[i+1]);

        if (
            diff < 1 ||
            diff > 3 ||
            (is_ascending && nums[i] > nums[i+1]) ||
            (!is_ascending && nums[i] < nums[i+1])
        ) {
            return false;
        }
    }

    return true;
}

bool is_safe_report_problem_dampener(int nums[], int size, bool is_removed) {

    if (size < 2) return true;

    bool is_ascending = nums[1] > nums[0];

    for (int i = 0; i < size - 1; i++) {

        int diff = abs(nums[i] - nums[i+1]);

        if (
            diff < 1 ||
            diff > 3 ||
            (is_ascending && nums[i] > nums[i+1]) ||
            (!is_ascending && nums[i] < nums[i+1])
        ) {
            if (is_removed) {
                return false;
            } else {
                bool flag = false;
                for (int j = 0; j < size && !flag; j++) {
                    int new_nums[MAX_LEVELS_FOR_REPORT];
                    int new_size = size - 1;
                    for (int k = 0; k < size; k++) {
                        if (k < j) {
                            new_nums[k] = nums[k];
                        } else {
                            new_nums[k] = nums[k+1];
                        }
                    }
                    flag = is_safe_report_problem_dampener(new_nums, new_size, true);
                }
                return flag;
            }
        }
    }

    return true;
}

int main() {

    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "error: file not found\n");
        exit(EXIT_FAILURE);
    }

    char *line = (char *)malloc(MAX_STRING_SIZE);
    if (!line) {
        fprintf(stderr, "error: memory allocation failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    int safe_reports = 0;
    int safe_reports_problem_dampener = 0;
    while (fgets(line, MAX_STRING_SIZE, file)) {

        // Parse the line
        int report[MAX_LEVELS_FOR_REPORT];
        int levels = 0;
        char *token = strtok(line, " ");
        while (token) {
            report[levels++] = atoi(token);
            token = strtok(NULL, " ");
        }

        if (is_safe_report(report, levels)) {
            safe_reports++;
        }
        if (is_safe_report_problem_dampener(report, levels, false)) {
            safe_reports_problem_dampener++;
        }
    }

    printf("Safe reports: %d\n", safe_reports);

    printf("Safe reports with Problem Dampener: %d\n", safe_reports_problem_dampener);

    fclose(file);
    free(line);

    return 0;
}