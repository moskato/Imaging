/*!
 * Función prod_c_v:
 * calcula el producto de un escalar con un vector.
 * 
 * @param x puntero a vector de entrada.
 * @param sc escalar.
 * @param tm tamaño vectores de entrada.
 * @param z puntero a vector resultado del producto de x y sc.
 * 
 */
void prod_c_v(double *x, double sc, int tm, double *z)
{
	for(int i=0;i<tm;i++)
		z[i]=sc*x[i];
}
