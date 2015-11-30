
#include "functions.h"
/*!
 * Función AT:
 * La función AT realiza la  multiplicación de un vector x 
 * con una matriz R.
 * 
 * @param x puntero al vector a registrarle los elementos diferentes de cero.
 * @param R Puntero a la Matriz 
 * @param m el tamaño de las filas de R
 * @param n el tamaño de las columnas de R
 * @param nz_x puntero al vector resultante
 * 
 */

void AT(double *y, obj *A, int m, int n, double *result)
{
	int var;
	int p;
	int cont = 0;
	for(int i = 0; i < A->n ; i++)
	{
		p = 0;
		var = 0;
		for(int j = 0; j < A->m; j++)
		{
			var = var + A->matrixA[j][i]*y[j];
			/*if (i == 1024)
			{
				cout<<"var= "<<var<<"\n A ="<<A->matrixA[j][i]<<", y[j]"<<y[j]<<"\n"<<endl;
			}*/
			p++;
		}
		
		result[i] = var;
		cont++;
	}
}
