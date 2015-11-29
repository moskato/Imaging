#include "functions.h"

/*Función principal: 
Recibe un vector de medidas de una imagen hiperespectral
*/
int main()
{
    twist *result = new twist;
    int tmy = 1024;
    int tm = 256;
    static float *reconstruction  = new float[tm];  
    static float *y2= new float[tmy];
    
    matriz_A *R = new matriz_A;
    R ->m = ROWS;
    R ->n = COLS;     
    
    size_t i,j;
    
    //Crear Matrix R
	R->matrixA = new float*[R->m];
	srand((unsigned)time(0));
    for (i = 0; i < COLS; i++) 
    {
		R->matrixA[i] = new float[R ->n];
		for (j = 0; j < ROWS ; j++)
		{
			R->matrixA[i][j]= rand()%2;

		}
	}
    
    //Carga de medidas observadas
    ifstream myfile;
    myfile.open ("medidas_y_p1.txt");
    float output;
    if (myfile.is_open())
    {
        for (i=0; i < tmy ; i++) 
        {
			myfile >> output;
			y2[i] = output;
			//printf("This is the line = %10.3f\n", output);
        }
    }
    myfile.close();  
    //printf("Hello World");
    
    
    
    //Parámetros
    int tau = 20;
	float tolA = 0.01;
      
    //Llamada al algoritmo de reconstrucción
    TwiST(y2,R,tau,reconstruction,6,"TOLERANCEA",1e-12,"MAXITERA",MAXITERA,"VERBOSE",0,"FIN");

    /*FILE *pFile;

    pFile = fopen ("../cassi/reconstruccion.txt","w");
    for (i=0 ;i< tm*tmy ; i++){
        fprintf (pFile, "%f\n",reconstruction[i]);
    }
    fclose (pFile);*/

    //delete[] imagen;
    return 0;
    
}
