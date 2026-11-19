
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int age;
    char bloodGroup[5];
    int eligible;
} Donor;

typedef struct
{
    Donor *data;
    int size;
    int capacity;
} DonorList;

int add_donor(DonorList *list, Donor donor)
{
    if (list->size == list->capacity)
    {
        int newCapacity = (list->capacity == 0)
                          ? 2 : list->capacity * 2;

        Donor *temp = realloc(
            list->data,
            newCapacity * sizeof(Donor)
        );

        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return 0;
        }

        list->data = temp;
        list->capacity = newCapacity;
    }

    list->data[list->size] = donor;
    list->size++;

    return 1;
}

void displayReport(DonorList *list)
{
    int eligibleCount = 0;

    printf("\nDONOR ELIGIBILITY REPORT\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < list->size; i++)
    {
        printf("ID: %d\n", list->data[i].id);
        printf("Name: %s\n", list->data[i].name);
        printf("Age: %d\n", list->data[i].age);
        printf("Blood Group: %s\n", list->data[i].bloodGroup);

        if (list->data[i].eligible)
        {
            printf("Status: Eligible\n");
            eligibleCount++;
        }
        else
        {
            printf("Status: Not Eligible\n");
        }

        printf("----------------------------------------\n");
    }

    printf("Total donors: %d\n", list->size);
    printf("Eligible donors: %d\n", eligibleCount);
}

int main(void)
{
    DonorList list = {NULL, 0, 0};

    Donor donors[] = {
        {1, "Arun", 25, "O+", 1},
        {2, "Bala", 17, "A+", 0},
        {3, "Kumar", 30, "B+", 1},
        {4, "Ravi", 22, "AB+", 1},
        {5, "Raj", 16, "O-", 0}
    };

    int count = sizeof(donors) / sizeof(donors[0]);

    for (int i = 0; i < count; i++)
    {
        if (!add_donor(&list, donors[i]))
        {
            free(list.data);
            return 1;
        }
    }

    displayReport(&list);

    free(list.data);
    list.data = NULL;

    return 0;
}
