/*!
 * Función phi_function:
 * Calcula la norma l0 de un vector
 * 
 * @param x puntero a vector de entrada.
 * @param tm tamaño vectores de entrada
 * @return norma l0
 * 
 */

double phi_function(double *x, int tm)
{
    int i;
    double z = 0;
    for(i=0; i < tm; i++)
    {
		if (x[i] != 0)
			z++;
    }
    return z;
}
