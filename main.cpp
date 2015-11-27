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
#include <time.h>

using namespace std;

//Estructura para el resultado
typedef struct Result{ 
    double *result;
    float time;
    float *psnr;
}twist;

typedef struct Matrix{ 
    double *matrixA;
    size_t m;
    size_t n;
}matriz;





/*Función principal: 
Recibe un vector de medidas de una imagen hiperespectral
*/
int main()
{

    twist *result = new twist;
    size_t shots = 1;
    size_t coded = 0;
    size_t count = 0;
    int tmy = 1024;
    int tm = 4096;
    static float *y2= new float[tmy];
    matriz *R = new matriz;
    R ->m = ROWS;
    R ->n = COL;
    
    
    //Carga de las medidas
    ifstream myfile;
    myfile.open ("medidas_y_p1.txt");
    float output;
    int t1,t2,t3;

    if (myfile.is_open()){
        for (int i=0; i < tmy ; i++) {
			myfile >> output;
			y2[i] = output;
			//printf("This is the line = %10.3f\n", output);
        }
    }

    myfile.close();
      
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
