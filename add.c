#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "internal.h"

// Funktion, die wir testen wollen
int calculate_sum(int *result)
{
    int retVal = EXIT_FAILURE;

    for (size_t i = 0; i < 2; i++)
    {
        result[i] = add_numbers(10 + i, (10 + i) * 3);
        retVal = EXIT_SUCCESS;
    }

    return retVal;
}