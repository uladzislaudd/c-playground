#include "5.h"

#include <unistd.h>

#include <stdio.h>

int fn5()
{
    int p = 0;
    
    p = getpid();
    fprintf(stdout, "My pid - %d!\n", p);

    fprintf(stdout, "Hello, World!\n");

    return 0;
}