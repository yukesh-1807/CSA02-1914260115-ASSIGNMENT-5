
#include <stdio.h>

/* Counters for recursive function calls */
long long linearCalls = 0;
long long fastCalls = 0;

/* Add all digits of a number */
int sumDigits(int n)
{
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

/* Recursive digital root */
int digitalRoot(int n)
{
    if (n < 10)
        return n;

    return digitalRoot(sumDigits(n));
}

/* Linear recursive power */
long long powerLinear(int base, int exp)
{
    linearCalls++;

    if (exp == 0)
        return 1;

    return base * powerLinear(base, exp - 1);
}

/* Fast recursive power */
long long powerFast(int base, int exp)
{
    long long half;

    fastCalls++;

    if (exp == 0)
        return 1;

    /* Calculate the half power only once */
    half = powerFast(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;

    return base * half * half;
}

/* Iterative square-and-multiply power */
long long powerIterative(int base, int exp)
{
    long long result = 1;
    long long current = base;

    while (exp > 0) {
        if (exp % 2 == 1)
            result *= current;

        current *= current;
        exp /= 2;
    }

    return result;
}

/* Calculate theoretical linear call count */
long long linearCallCount(int exp)
{
    return (long long)exp + 1;
}

/* Calculate fast recursive call count */
long long fastCallCount(int exp)
{
    long long count = 1;

    while (exp > 0) {
        exp /= 2;
        count++;
    }

    return count;
}

int main(void)
{
    int values[] = {10, 100, 1000, 10000};
    int i;
    int base = 2;
    int exp = 30;

    printf("DIGITAL ROOT TESTS\n");
    printf("Digital root of 0 = %d\n", digitalRoot(0));
    printf("Digital root of 1 = %d\n", digitalRoot(1));
    printf("Digital root of 9875 = %d\n", digitalRoot(9875));

    printf("\nPOWER TESTS\n");

  long long answer;

linearCalls = 0;
answer = powerLinear(base, exp);
printf("Linear: %lld in %lld calls\n", answer, linearCalls);

fastCalls = 0;
answer = powerFast(base, exp);
printf("Fast: %lld in %lld calls\n", answer, fastCalls);

    printf("\nCALL COUNT COMPARISON\n");
    printf("Exponent\tLinear\tFast\n");

    for (i = 0; i < 4; i++) {
        printf("%d\t\t%lld\t%lld\n",
               values[i],
               linearCallCount(values[i]),
               fastCallCount(values[i]));
    }

    return 0;
}
