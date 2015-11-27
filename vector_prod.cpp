/*!
 * Función vector_prod:
 * calcula el producto de dos vectores.
 * 
 */
float vector_prod(float *x, float *y, int tm)
{
	float *z;
	for(size_t i=0;i<tm;i++)
		z=+x[i]*y[i];
	return z;
}