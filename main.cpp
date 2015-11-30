#include "functions.h"

/*Función principal: 
Recibe un vector de medidas de una imagen hiperespectral
*/
int main()
{
    int tmy = 1024;
    int tm = 4096;
    double *reconstruction=new double[tm];  
    double *y2=new double[tmy];
    static obj *R = new obj;
    double *y_hat=new double[tmy];

    R ->m = ROWS;
    R ->n = COLS;     
    
    size_t i,j;
    
    //Crear Matrix R
	R->matrixA = new double*[R->m];
	double LO = -4;
	double HI = 4;
	
	srand((unsigned)time(0));
    for (i = 0; i < R->m; i++) 
    {
		R->matrixA[i] = new double[R ->n];
		for (j = 0; j < R->n ; j++)
		{
			double out =  LO + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(HI-LO)));
			R->matrixA[i][j]= out;
			//printf("This is the line = %10.3f\n", out);
			

		}
	}
    
    //Carga de medidas observadas
    ifstream myfile;
    myfile.open ("medidas_y_p1.txt");
    double output;
    if (myfile.is_open())
    {
        for (i=0; i < tmy ; i++) 
        {
			myfile >> output;
			y2[i] = output;
			//printf("This is the line = %10.3f\n", output);
        }
        myfile.close(); 
    }
         
    
    /*double c = phi_function(y2,tmy);
    cout<<"y2= "<<c<<"\n"<<endl;
    for (i = 0; i < tmy; i++)
	{			
				cout<<"y2= "<<y2[i]<<"\n"<<endl;
	} */
    
    //Parámetros
    double tau = 20;
	double tolA = 0.01;
      
    //Llamada al algoritmo de reconstrucción
    twist(y2,R,tau,reconstruction,6,"TOLERANCEA",1e-12,"MAXITERA",MAXITERA,"FIN");
	
	/*Af(reconstruction, R, tm, tmy, y_hat); //Salida
	double var;
	/*
	for(int i = 0; i < R->m ; i++)
	{
		var = 0;
		for(int j = 0; j < R->n; j++)
		{
			var = var + R->matrixA[i][j]*reconstruction[j];
			cout<<"M="<<R->matrixA[i][j]*reconstruction[j]<<"\n"<<endl;
			//cout<<"var="<<var<<"\n"<<endl;
		}
		y_hat[i] = var;
		//cout<<var<<"\n"<<endl;
	}
	
	for(int i = 0; i < R->m ; i++)
	{
		for(int j = 0; j < R->n; j++)
		{
			cout<<R->matrixA[i][j]<<"\n"<<endl;
		}
	}*/
	
	/*
	for (int i=0; i < tmy ; i++) 
    {
			//fprintf (fFile, "%f\n",y_hat[i]);
			cout<<y_hat[i]<<"\n"<<endl;
     }*/
	
	/*//Guardar salida;
    FILE *fFile,
    fFile = fopen ("../TwIST/y_hat.txt","w");
    for (int i=0; i < tmy ; i++) 
        {
			fprintf (fFile, "%f\n",y_hat[i]);
			printf("y_hat - y = %10.3f\n", y_hat[i] - y2[i]);
        }

    fclose (fFile);*/
    
    
    ofstream mypfile;
    mypfile.open ("../TwIST/reconstruccion.txt");
    if (mypfile.is_open())
    {
        for (i=0; i < tm ; i++) 
        {
			mypfile<<reconstruction[i]<<endl;
        }
        mypfile.close(); 
    }
	/*
    FILE *pFile;
    pFile = fopen ("../TwIST/reconstruccion.txt","w");
    for (i=0 ;i< tm ; i++){
        fprintf (pFile, "%f\n",reconstruction[i]);
    }
    fclose (pFile);
*/
    //delete[] imagen;
    delete[] reconstruction;
    delete[] y2;
    delete[] y_hat;
    for (i = 0; i < R->m; i++) 
    {
		delete[] R->matrixA[i];
	}
    return 0;
    
}
