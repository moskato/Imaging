//Definición de parámetros
#define    PI           3.141592652598793
#define    SQH          0.707106781186547
#define    SQRT_2       1.414213562373095
#define    SHOTS        8
#define    COLS         256
#define    ROWS         256
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


/*Función principal: 
Recibe un vector de medidas de una imagen hiperespectral
*/
int main()
{

    twist *result = new twist;
    size_t shots = 1;
    size_t coded = 0;
    size_t count = 0;
    
    //Carga de las medidas
    ifstream myfile;
    myfile.open ("medidas.txt");
    float output;
    int t1,t2,t3;
/*
    if (myfile.is_open()){
        while (count<(imagen->l*imagen->n*imagen->m)) {
            myfile >> output;
            t1 = count%imagen->m;
            t2 = ((int)(count/imagen->n)) % imagen->n;
            t3 = (int)(count/(imagen->n*imagen->m));
            imagen->data[t1][t2][t3] = output;
            count++;
        }
    }*/

    myfile.close();
      
    //Llamada al algoritmo de reconstrucción
    TwiST(y2,obj,tau,reconstruction,6,"TOLERANCEA",1e-12,"MAXITERA",MAXITERA,"VERBOSE",1,"FIN");

    //delete[] imagen;
    return 0;
    
}
