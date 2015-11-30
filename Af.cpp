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

void Af(float *x, matrix_A *&matrixA, int m, int n, float *result)
{
	float var;
	int cont = 0;
	for(int i = 0; i < m ; i++)
	{
		var = 0;
		for(int j = 0; j < n; j++)
		{
			var = var + matrixA[i][j]*x[j];
		}
		result[cont] = var;
		cont++;
	}
}

