#include <stdio.h>
#include <stdlib.h>
#include "io.h"

WaveformSample* load_csv(const char *filename, int *n) {

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return NULL;
    }

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

void write_results(const char *filename,
                   double rmsA, double rmsB, double rmsC,
                   double p2pA, double p2pB, double p2pC,
                   double dcA, double dcB, double dcC,
                   int clipA, int clipB, int clipC) {

    FILE *file = fopen(filename, "w");

    fprintf(file, "=== POWER QUALITY REPORT ===\n\n");

    fprintf(file, "RMS Voltage:\n");
    fprintf(file, "Phase A: %.2f (%s)\n", rmsA, (rmsA>=207&&rmsA<=253)?"OK":"OUT");
    fprintf(file, "Phase B: %.2f (%s)\n", rmsB, (rmsB>=207&&rmsB<=253)?"OK":"OUT");
    fprintf(file, "Phase C: %.2f (%s)\n\n", rmsC, (rmsC>=207&&rmsC<=253)?"OK":"OUT");

    fprintf(file, "Peak-to-Peak:\n");
    fprintf(file, "A: %.2f\nB: %.2f\nC: %.2f\n\n", p2pA, p2pB, p2pC);

    fprintf(file, "DC Offset:\n");
    fprintf(file, "A: %.5f\nB: %.5f\nC: %.5f\n\n", dcA, dcB, dcC);

    fprintf(file, "Clipping Count:\n");
    fprintf(file, "A: %d\nB: %d\nC: %d\n\n", clipA, clipB, clipC);

    fclose(file);
}