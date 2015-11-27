
//Definición de parámetros
#define    PI           3.141592652598793
#define    SQH          0.707106781186547
#define    SQRT_2       1.414213562373095
#define    SHOTS        8
#define    COLS         4096
#define    ROWS         1024
#define    BANDS        24
#define    MAXITERA     300
#define    TAU          2e-5



#include <iostream>
#include <fstream>
#include <time.h>		/* time */
#include <stdlib.h>		/*srand, rand*/

using namespace std;

//float phi_function(float *x, int tmy);


//Estructura para el resultado
typedef struct Result{ 
    double *result;
    float time;
    float *psnr;
}twist;

typedef struct Matrix{ 
    float **matrixA;
    size_t m;
    size_t n;
}matriz_A;




/*Función principal: 
Recibe un vector de medidas de una imagen hiperespectral
*/
int main()
{
    twist *result = new twist;
    int tmy = 1024;
    int tm = 256;
    
    static float *y2= new float[tmy];
    
    matriz_A *R = new matriz_A;
    R ->m = ROWS;
    R ->n = COLS;     
    
    size_t i,j;
    /*
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
	}*/
    
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
    
    //Parámetros
    int tau = 20;
	float tolA = 0.01;
      
    //Llamada al algoritmo de reconstrucción
    //TwiST(y2,obj,tau,reconstruction,6,"TOLERANCEA",1e-12,"MAXITERA",MAXITERA,"VERBOSE",1,"FIN");

    /*FILE *pFile;

    pFile = fopen ("../cassi/reconstruccion.txt","w");
    for (i=0 ;i< tm*tmy ; i++){
        fprintf (pFile, "%f\n",reconstruction[i]);
    }
    fclose (pFile);*/

    //delete[] imagen;
    return 0;
    
}
