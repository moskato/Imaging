/*!
 * Función sum:
 * Calcula la suma de los elementos de
 * un vector.
 * 
 * @param x puntero a vector de entrada.
 * @param tm tamaño vectores de entrada
 * @return elemento de salida de la suma del vector de entrada
 * 
 */
double sum(double *x, int tm)
{
	double sum_z = 0;
	for(int i=0;i<tm;i++)
		sum_z = sum_z + x[i];
	return sum_z;
}
