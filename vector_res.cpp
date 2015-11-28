/*!
 * Función vector_res:
 * Calcula la resta de dos vectores.
 * 
 * @param x puntero a vector de entrada.
 * @param y puntero a vector de entrada.
 * @param tm tamaño vectores de entrada
 * @param z puntero a vector resultado de la resta de x y y.
 * 
 */
void vector_res(float *x, float *y, int tm, float *z)
{
	for(int i=0;i<tm;i++)
		z[i]=x[i]-y[i];
}
