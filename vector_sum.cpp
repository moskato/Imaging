/*!
 * Función vector_sum:
 * calcula la suma de dos vectores.
 * 
 */
float vector_sum(float *x, float *y, int tm)
{
	float *z;
	for(size_t i=0;i<tm;i++)
		z[i]=x[i]+y[i];
	return z;
}