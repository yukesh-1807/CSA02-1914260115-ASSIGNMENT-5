#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int validBloodGroup(const char *group)
{
    const char *groups[] = {
        "A+", "A-", "B+", "B-",
        "AB+", "AB-", "O+", "O-"
    };

    for (int i = 0; i < 8; i++)
    {
        if (strcmp(group, groups[i]) == 0)
            return 1;
    }

    return 0;
}

void testScanf(void)
{
    char name[50];

    printf("Enter donor name (one word): ");

    if (scanf("%49s", name) == 1)
        printf("Name entered: %s\n", name);
    else
        printf("Invalid input.\n");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void testFgets(void)
{
    char name[100];

    printf("Enter full donor name: ");

    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Input error.\n");
        return;
    }

    if (strchr(name, '\n') == NULL)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Name is too long.\n");
        return;
    }

    name[strcspn(name, "\n")] = '\0';
    printf("Full name entered: %s\n", name);
}

void testFile(const char *filename)
{
    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        perror("File opening failed");
        return;
    }

    printf("File opened successfully.\n");
    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n");
        printf("./B2 name-scanf\n");
        printf("./B2 name-fgets\n");
        printf("./B2 filecheck filename\n");
        return 1;
    }

    if (strcmp(argv[1], "name-scanf") == 0)
        testScanf();
    else if (strcmp(argv[1], "name-fgets") == 0)
        testFgets();
    else if (strcmp(argv[1], "filecheck") == 0 && argc == 3)
        testFile(argv[2]);
    else
        printf("Invalid command or arguments.\n");

    return 0;
}
