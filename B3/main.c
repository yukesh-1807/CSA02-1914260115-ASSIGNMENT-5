
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100000

typedef struct
{
    int id;
    char name[30];
    int units;
} Stock;

void createTextFile(int n)
{
    FILE *fp = fopen("stock.txt", "w");

    if (fp == NULL)
    {
        perror("stock.txt");
        return;
    }

    for (int i = 1; i <= n; i++)
        fprintf(fp, "%d Donor%d %d\n", i, i, 10 + i % 50);

    fclose(fp);
}

void createBinaryFile(int n)
{
    FILE *fp = fopen("stock.dat", "wb");

    if (fp == NULL)
    {
        perror("stock.dat");
        return;
    }

    Stock s;

    for (int i = 1; i <= n; i++)
    {
        s.id = i;
        snprintf(s.name, sizeof(s.name), "Donor%d", i);
        s.units = 10 + i % 50;
        fwrite(&s, sizeof(Stock), 1, fp);
    }

    fclose(fp);
}

int update_units(FILE *fp, int index, int units)
{
    Stock s;

    if (fp == NULL || index < 0 || units < 0)
        return 0;

    if (fseek(fp, (long)index * sizeof(Stock), SEEK_SET) != 0)
        return 0;

    if (fread(&s, sizeof(Stock), 1, fp) != 1)
        return 0;

    s.units = units;

    if (fseek(fp, -(long)sizeof(Stock), SEEK_CUR) != 0)
        return 0;

    if (fwrite(&s, sizeof(Stock), 1, fp) != 1)
        return 0;

    fflush(fp);
    return 1;
}

void showUpdates(void)
{
    Stock s;
    FILE *fp = fopen("update.dat", "wb+");

    if (fp == NULL)
    {
        perror("update.dat");
        return;
    }

    for (int i = 1; i <= 5; i++)
    {
        s.id = i;
        strcpy(s.name, "Donor");
        s.units = i * 10;
        fwrite(&s, sizeof(Stock), 1, fp);
    }

    printf("\nUpdate demonstration:\n");

    printf("update record 3: ");
    printf("%s\n", update_units(fp, 2, 12) ? "done" : "failed");

    printf("update record 9: ");
    printf("%s\n", update_units(fp, 8, 50) ? "done" : "failed");

    rewind(fp);

    printf("Updated stock: ");

    for (int i = 0; i < 5; i++)
    {
        fread(&s, sizeof(Stock), 1, fp);
        printf("%d:%d ", s.id, s.units);
    }

    printf("\n");
    fclose(fp);
}

int main(void)
{
    int sizes[] = {10, 1000, 10000, 100000};
    int count = 4;

    printf("B3 - Text File vs Binary File\n");

    printf("\nFILE SIZE AND TIME COMPARISON\n");
    printf("Records\tText Size\tBinary Size\tText Time\tBinary Time\n");

    for (int k = 0; k < count; k++)
    {
        int n = sizes[k];
        clock_t start, end;
        double textTime, binaryTime;
        long textSize, binarySize;

        start = clock();
        createTextFile(n);
        end = clock();
        textTime = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        createBinaryFile(n);
        end = clock();
        binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

        FILE *fp = fopen("stock.txt", "rb");
        fseek(fp, 0, SEEK_END);
        textSize = ftell(fp);
        fclose(fp);

        fp = fopen("stock.dat", "rb");
        fseek(fp, 0, SEEK_END);
        binarySize = ftell(fp);
        fclose(fp);

        printf("%d\t%ld\t\t%ld\t\t%.6f\t%.6f\n",
               n, textSize, binarySize, textTime, binaryTime);
    }

    showUpdates();

    return 0;
}
