float phi_function(float *x, int tmy)
{
		//Norma L0
    size_t i;
    float z;
    z = 0;
    for(i=0; i < tmy; i++)
    {
		if (x[i] != 0.0)
		{
			z = z + 1;
		}
    }
    return z;
}
