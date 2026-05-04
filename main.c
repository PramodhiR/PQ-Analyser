#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {

    int n;

    WaveformSample *samples = load_csv("power_quality_log.csv", &n);

    if (!samples) return 1;

    printf("Loaded %d samples\n", n);

    double rmsA = compute_rms(samples, n, 'A');
    double rmsB = compute_rms(samples, n, 'B');
    double rmsC = compute_rms(samples, n, 'C');

    printf("RMS A: %.2f\n", rmsA);
    printf("RMS B: %.2f\n", rmsB);
    printf("RMS C: %.2f\n", rmsC);
    free(samples);
    return 0;
}