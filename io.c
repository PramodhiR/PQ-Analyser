#include <stdio.h>
#include <stdlib.h>
#include "io.h"

WaveformSample* load_csv(const char *filename, int *n) {

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return NULL;
    }

    // Allocate memory for 1000 rows
    WaveformSample *samples = malloc(1000 * sizeof(WaveformSample));

    char line[256];
    fgets(line, sizeof(line), file); // skip header

    int i = 0;

    while (fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
        &samples[i].timestamp,
        &samples[i].phase_A_voltage,
        &samples[i].phase_B_voltage,
        &samples[i].phase_C_voltage,
        &samples[i].line_current,
        &samples[i].frequency,
        &samples[i].power_factor,
        &samples[i].thd_percent) == 8) {

        i++;
        }

    *n = i;

    fclose(file);
    return samples;
}