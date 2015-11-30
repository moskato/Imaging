#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Definición de parámetros
#define    PI           3.141592652598793
#define    SQH          0.707106781186547
#define    SQRT_2       1.414213562373095
#define    SHOTS        8
#define    COLS         4096
#define    ROWS         1024
#define    BANDS        24
#define    MAXITERA     300
#define    TAU          2e-5


#include <iostream>
#include <fstream>
#include <time.h>		/* time */
#include <stdlib.h>		/*srand, rand*/
#include <math.h>  

typedef struct Matrix{ 
    float **matrixA;
    size_t m;
    size_t n;
}obj;

using namespace std;

void Af(float *x, float **R, int m, int n, float *result);
void AT(float *y, float **R, int m, int n, float *result);
void diff(float *x, float *y, int tm, float *temp);
void hadamard(float *x, float *y, int tm, float *z);
void non_zero(float *x, int tm, float *nz_x);
float phi_function(float *x, int tm);
void prod_c_v(float *x, float sc, int tm, float *z);
void psi_function(float *x, float lambda, int tm, float *z);
float sum(float *x, int tm);
void twist(float *y,matrixA *A, double tau,float *&x,int arguments, ...);
float vector_prod(float *x, float *y, int tm);
void vector_res(float *x, float *y, int tm, float *z);
void vector_sum(float *x, float *y, int tm, float *z);



#endif
