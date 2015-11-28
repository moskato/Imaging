/*!
 * Función vector_prod:
 * calcula el producto de dos vectores.
 * 
 * @param x puntero a vector de entrada.
 * @param y puntero a vector de entrada.
 * @param tm tamaño vectores de entrada
 * @return valor producto vectores de entrada.
 * 
 */
float vector_prod(float *x, float *y, int tm)
{
	float z=0;
	for(int i=0;i<tm;i++)
	{
		z+=(x[i])*(y[i]);
	}
	return z;
}