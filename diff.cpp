/*!
 * Función diff:
 * Estima la diferencia entre dos vectores
 * 
 * @param x puntero al vector A.
 * @param y puntero al vector B.
 * @param tm tamaño del vector x.
 * @param nz_x puntero al vector donde se registran los elementos diferentes de ccero de x.
 * 
 */

void diff(float *x, float *y, int tm, float *temp)
{
	for(int i=0;i<tm;i++)
	{
		if(x[i]!= y[i])
			temp[i]=1;
		else
			temp[i]=0;
	}
}
