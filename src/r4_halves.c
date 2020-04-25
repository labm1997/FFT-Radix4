#include "r4_fft.h"

/*
 * Computa as exponenciais complexas para operar com FFT de tamanho até Nmax
 * O tamanho do buffer halves deve ser de (Nmax-1)/3. Se Nmax=1024 são necessários 341 elementos (2728 bytes)
 */
void r4_init_halves(complex *h1, complex *h2, complex *h3, uint16_t Nmax){
    uint16_t i = 0;
    for(uint16_t N=4 ; N<=Nmax ; N *= 4){
        for(uint16_t k=0 ; k<N/4 ; k++){
            h1[i].real = cos((double)-2*PI*k/N);
            h1[i].imag = sin((double)-2*PI*k/N);
            cmul(h1[i], h1[i], h2[i]);
            cmul(h2[i], h1[i], h3[i]);
            i++;
        }
    }
}

/*
 * Printa os halves no formato de código C
 */
void print_halves(char *name, complex *h){
    printf("complex %s[] = {\n", name);
    for(uint16_t i=0 ; i<HALVES_SIZE(SAMPLES_SIZE) ; i++){
        printf("\t{.real = %lf, .imag = %lf}", h[i].real, h[i].imag);
        if(i != HALVES_SIZE(SAMPLES_SIZE)-1) printf(",");
        printf("\n", i);
    }
    printf("};\n");
}
