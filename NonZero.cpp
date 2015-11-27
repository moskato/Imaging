float NonZero(float x, int tm)
{
	float nz_x;
	for(int i=0;i<=tm;i++)
	{
		if(x[i]!=0)
			nz_x[i]=1;
		else
			nz_x[i]=0;
	}
	return nz_x;
}
