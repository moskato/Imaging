/*!
 * Función A:
 * La función A realiza la  multiplicación de un vector x 
 * con una matriz R.
 * 
 * @param x puntero al vector a registrarle los elementos diferentes de cero.
 * @param R Puntero a la Matriz 
 * @param m el tamaño de las filas de R
 * @param n el tamaño de las columnas de R
 * @param nz_x puntero al vector resultante
 * 
 */

void A(float *x, float **R, int m, int n, float *result)
{
	float var;
	int cont = 0;
	for(int i = 0; i < m ; i++)
	{
		var = 0;
		for(int j = 0; j < n; j++)
		{
			var = var + R->matrizA[i][j]*x[j];
		}
		result[cont] = var;
		cont++;
	}
}

