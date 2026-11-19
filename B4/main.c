e <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int id;
    char name[50];
    char bloodGroup[5];
    int daysSinceDonation;
} Donor;

typedef struct {
    Donor *data;
    size_t count;
    size_t capacity;
} DonorList;

int addDonor(DonorList *list, Donor donor) {
    if (list->count == list->capacity) {
        size_t newCapacity =
            (list->capacity == 0) ?
            INITIAL_CAPACITY : list->capacity * 2;

        Donor *temp = (Donor *)realloc(
    list->data,
    newCapacity * sizeof(Donor)
);
        
#includ

        if (temp == NULL)
            return 0;

        list->data = temp;
        list->capacity = newCapacity;
    }

    list->data[list->count++] = donor;
    return 1;
}

int loadDonors(DonorList *list, const char *filename) {
    FILE *fp = fopen(filename, "r");
    Donor donor;

    if (fp == NULL) {
        perror("Unable to open donor file");
        return 0;
    }

    while (fscanf(fp, "%d %49s %4s %d",
                  &donor.id,
                  donor.name,
                  donor.bloodGroup,
                  &donor.daysSinceDonation) == 4) {

        if (!addDonor(list, donor)) {
            printf("Memory allocation failed.\n");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

void generateReport(const DonorList *list) {
    size_t i;
    int found = 0;

    printf("\nDONOR ELIGIBILITY REPORT\n");
    printf("--------------------------------\n");

    for (i = 0; i < list->count; i++) {
        /* Example rule: 90 or more days since donation */
        if (list->data[i].daysSinceDonation >= 90) {
            printf("ID: %d | Name: %s | Blood Group: %s\n",
                   list->data[i].id,
                   list->data[i].name,
                   list->data[i].bloodGroup);
            found = 1;
        }
    }

    if (!found)
        printf("No eligible donors found.\n");
}

int main(void) {
    DonorList list = {NULL, 0, 0};
    FILE *fp;
    clock_t start, end;
    double elapsed;
    size_t memoryUsed;

    /* Create sample donor file */
    fp = fopen("donors.txt", "w");

    if (fp == NULL) {
        perror("File creation failed");
        return 1;
    }

    fprintf(fp, "101 Arun O+ 100\n");
    fprintf(fp, "102 Balu A+ 80\n");
    fprintf(fp, "103 Charan B+ 20\n");
    fprintf(fp, "104 David AB+ 120\n");
    fprintf(fp, "105 Ezhil O- 10\n");

    fclose(fp);

    start = clock();

    if (!loadDonors(&list, "donors.txt")) {
        free(list.data);
        return 1;
    }

    generateReport(&list);

    end = clock();

    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    memoryUsed = list.capacity * sizeof(Donor);

    printf("\nTotal donors loaded: %zu\n", list.count);
    printf("Allocated memory: %zu bytes\n", memoryUsed);
    printf("Execution time: %.6f seconds\n", elapsed);

    free(list.data);
    list.data = NULL;

    printf("Memory released successfully.\n");

    return 0;
}
