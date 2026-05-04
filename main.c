#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"

int main() {
    FILE *file = fopen("power_quality_log.csv", "r");

    if (!file) {
        printf("File not found\n");
        return 1;
    }

    printf("File opened successfully\n");

    fclose(file);
    return 0;
}