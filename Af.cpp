#include "functions.h"
/*!
 * Función Af:
 * La función Af realiza la  multiplicación de un vector x 
 * con una matriz R.
 * 
 * @param x puntero al vector a registrarle los elementos diferentes de cero.
 * @param R Puntero a la Matriz 
 * @param m el tamaño de las filas de R
 * @param n el tamaño de las columnas de R
 * @param nz_x puntero al vector resultante
 * 
 */

void Af(double *x, obj *A, int m, int n, double *result)
{
	int var;
	int cont = 0;
	for(int i = 0; i < A->m ; i++)
	{
		var = 0.0;
		for(int j = 0; j < A->n; j++)
		{
			var = var + A->matrixA[i][j]*x[j];
		}
		result[i] = var;
		cont++;
	}
}

