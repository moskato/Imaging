#include "functions.h"
/*!
 * Función psi_function:
 * Se hace un umbral para cada valor del vector de entrada dependiendo del 
 * parámetro lambda
 * 
 * @param x puntero al vector a registrarle los elementos diferentes de cero.
 * @param lambda parámetro umbral
 * @param tm tamaño del vector
 * 
 */

void psi_function(double *x, double lambda, int tm, double *z)
{
	int i,j;
	for (i = 0; i < tm; i++)
	{
		
		if(abs(x[i]) >= sqrt(2*lambda))
		{
			z[i] = x[i];			
		}
		else
		{
			z[i] = 0;
		}
	}
}
