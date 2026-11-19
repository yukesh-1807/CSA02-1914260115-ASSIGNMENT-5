
#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];
    char bloodGroup[10];
    int units;

    printf("B2 - Input Validation and Error Handling\n");

    // Test 1: Read full donor name
    printf("\nEnter donor name: ");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Input error.\n");
        return 1;
    }

    name[strcspn(name, "\n")] = '\0';
    printf("Donor Name: %s\n", name);

    // Test 2: Validate blood group
    printf("\nEnter blood group: ");
    if (scanf("%9s", bloodGroup) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (strcmp(bloodGroup, "A+") == 0 ||
        strcmp(bloodGroup, "A-") == 0 ||
        strcmp(bloodGroup, "B+") == 0 ||
        strcmp(bloodGroup, "B-") == 0 ||
        strcmp(bloodGroup, "AB+") == 0 ||
        strcmp(bloodGroup, "AB-") == 0 ||
        strcmp(bloodGroup, "O+") == 0 ||
        strcmp(bloodGroup, "O-") == 0)
    {
        printf("Valid blood group.\n");
    }
    else
    {
        printf("Invalid blood group.\n");
    }

    // Test 3: Validate units
    printf("\nEnter units: ");

    if (scanf("%d", &units) != 1 || units <= 0)
    {
        printf("Invalid units.\n");
    }
    else
    {
        printf("Valid units: %d\n", units);
    }

    return 0;
}
