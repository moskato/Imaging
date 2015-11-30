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
#include <stdarg.h>
#include <string.h>

typedef struct Matrix{ 
    double **matrixA;
    size_t m;
    size_t n;
}obj;

using namespace std;

void Af(double *x, obj *A, int m, int n, double *result);
void AT(double *y, obj *A, int m, int n, double *result);
void diff(double *x, double *y, int tm, double *temp);
void hadamard(double *x, double *y, int tm, double *z);
void non_zero(double *x, int tm, double *nz_x);
double phi_function(double *x, int tm);
void prod_c_v(double *x, double sc, int tm, double *z);
void psi_function(double *x, double lambda, int tm, double *z);
double sum(double *x, int tm);
void twist(double *y,obj *A, double tau,double *x,int arguments, ...);
double vector_prod(double *x, double *y, int tm);
void vector_res(double *x, double *y, int tm, double *z);
void vector_sum(double *x, double *y, int tm, double *z);



#endif
