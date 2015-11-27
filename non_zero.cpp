/*!
 * Función non_zero:
 * calcula un vector booleano que registra los elementos diferentes de cero
 * del vector de entrada x.
 * 
 */
float non_zero(float *x, int tm)
{
	float nz_x[tm];
	int i;
	for(i=0;i<tm;i++)
	{
		if(x[i]!=0)
			nz_x[i]=1;
		else
			nz_x[i]=0;
	}
	return nz_x;
}
