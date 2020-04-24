#include <stdio.h>
#include <math.h>
#include <time.h>
#include "complex_float.h"
#include "r4_fft.h"

#define n_bench_loops 1000000

void init_samples(complex *samples, double sampleWindow){
    for(uint16_t i=0; i<SAMPLES_SIZE ; i++){
        double t = ((double)i)*sampleWindow/SAMPLES_SIZE;
        samples[i].real = cos(2*PI*t*1)+2*cos(2*PI*t*10)+3*cos(2*PI*t*20)+3*cos(2*PI*t*30)+2*cos(2*PI*t*40)+cos(2*PI*t*50);
        samples[i].imag = 0;
        // samples[i].real = (i%64 > 32) ? 1 : -1;
        // samples[i].imag = 0;
    }
}

void print_fft_mag(float *fft_mag, complex *samples, double sampleWindow){
    printf("{");
    printf("\"data\": [");
    for(uint16_t i=0 ; i<SAMPLES_SIZE/2 ; i++){
        printf("[%lf,%lf]", (double)i/sampleWindow, fft_mag[i]);
        if(i<SAMPLES_SIZE/2-1) printf(",");
    }
    printf("]");
    printf(",\"samples\": [");
    for(uint16_t i=0 ; i<SAMPLES_SIZE ; i++){
        printf("[%lf,%lf]", (double)i*sampleWindow/SAMPLES_SIZE, samples[i].real);
        if(i<SAMPLES_SIZE-1) printf(",");
    }
    printf("]");
    printf("}\n");
}

complex samples[SAMPLES_SIZE];
float fft_mag[SAMPLES_SIZE/2];

int main(){
    init_samples(samples, 10);
    // clock_t begin = clock();
    // for(uint32_t i=0 ; i<n_bench_loops ; i++){
    //     r4_fft(samples, output);
    // }
    // clock_t end = clock();
    // printf("%lf us/fft\n", (double)(end - begin) / CLOCKS_PER_SEC / n_bench_loops * 1000000);
    r4_fft_mag2(samples, fft_mag);
    print_fft_mag(fft_mag, samples, 10);
    return 0;
}