#pragma once

#include <stdio.h>

typedef enum Status
{
    OK,
    INVALID_ARGUMENTS
}Status;

Status solveQuadraticEquation(const float* a, const float* b, const float* c, int* numberOfSolutions)
{
    if (!a || !b || !c || !numberOfSolutions)
    {
        return INVALID_ARGUMENTS;
    }

    const float delta = (*b) * (*b) - 4 * (*a) * (*c);

    if (delta > 0)
    {
        *numberOfSolutions = 2;
    }
    else if (delta < 0)
    {
        *numberOfSolutions = 0;
    }
    else
    {
        *numberOfSolutions = 1;
    }

    return OK;
}

int main()
{
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;

    while (scanf("%f %f %f", &a, &b, &c) == 3)
    {
        int numberOfSolutions = 0;
        const Status status = solveQuadraticEquation(&a, &b, &c, &numberOfSolutions);
        printf("%d\n", numberOfSolutions);
    }
}

