/*!
 * Función vector_sum:
 * calcula la suma de dos vectores.
 * 
 * @param x puntero a vector de entrada.
 * @param y puntero a vector de entrada.
 * @param tm tamaño vectores de entrada
 * @param z puntero a vector resultado de la suma de x y y.
 * 
 */
void vector_sum(float *x, float *y, int tm, float *z)
{
	for(int i=0;i<tm;i++)
		z[i]=x[i]+y[i];
}