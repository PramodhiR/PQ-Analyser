//
// Created by my pc on 04/05/20
#include <math.h>
#include "waveform.h"

// Helper function
double get_voltage(WaveformSample s, char phase) {
    if (phase == 'A') return s.phase_A_voltage;
    if (phase == 'B') return s.phase_B_voltage;
    return s.phase_C_voltage;
}

double compute_rms(WaveformSample *samples, int n, char phase) {

    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double v = get_voltage(samples[i], phase);
        sum += v * v;   // square and add
    }

    double rms = sqrt(sum / n);

    return rms;
}

double compute_peak_to_peak(WaveformSample *samples, int n, char phase) {

    double max = get_voltage(samples[0], phase);
    double min = max;

    for (int i = 1; i < n; i++) {
        double v = get_voltage(samples[i], phase);

        if (v > max) max = v;
        if (v < min) min = v;
    }

    return max - min;
}
double compute_dc_offset(WaveformSample *samples, int n, char phase) {

    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += get_voltage(samples[i], phase);
    }

    return sum / n;
}

int count_clipped(WaveformSample *samples, int n, char phase) {

    int count = 0;

    for (int i = 0; i < n; i++) {
        double v = get_voltage(samples[i], phase);

        if (fabs(v) >= 324.9) {
            count++;
        }
    }

    return count;
}