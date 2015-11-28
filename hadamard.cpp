/*!
 * Función hadamard:
 * calcula el producto elemento a elemento entre dos vectores.
 * 
 * @param x puntero a vector de entrada.
 * @param y puntero a vector de entrada.
 * @param tm tamaño vectores de entrada.
 * @param z puntero a vector resultado del producto elemento a elemento de x y y.
 * 
 */
void hadamard(float *x, float *y, int tm, float *z)
{
	for(int i=0;i<tm;i++)
		z[i]=x[i]*y[i];
}