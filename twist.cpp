#include "functions.h"
/*!
 * El algoritmo "Two-step Iterative Shrinkage/Thresholding" (TwIST) es un algoritmo para resolver problemas lineales inversos.
 * Este algoritmo resuelve el siguiente problema de regularización:
 * arg min_x = 0.5*|| y - A x ||_2^2 + tau phi( x)
 * donde A es una matriz genérica y phi() es una función de regularización, tal que la solución del problema de eliminación de ruido es conocida:
 * Psi_tau(y) = arg min_x = 0.5*|| y - x ||_2^2 + tau \phi( x )
 * Toda la información relacionada a este algoritmo puede ser encontrada en:http://www.lx.it.pt/~bioucas/TwIST/TwIST.htm.
 *
 * @param y puntero al vector de medidas.
 * @param A objeto que contiene la matriz A y sus tamaños.
 * @param tau constante de regularización.
 * @param x representación de y en el dominio de la matriz A.
 *
*/
void twist(double *y,obj *A, double tau,double *x,int arguments, ...)
{
	
	//int tmy = 1024; //Static size for example :D
	//int tm = 4096;
	int tm = A->n;
	int tmy = A->m;

    int stopCriterion = 1;
    double criterion = 0;
    double tolA = 0.01;
    int maxiter = 10000;
    int maxiter_debias = 200;
    int miniter = 5;
    int miniter_debias = 5;
    int init = 0;
    int enforceMonotone = 1;
    bool compute_mse = false;
    int plot_ISNR = 0;
    bool verbose = true;
    double alpha = 0;
    double beta = 0;
    
    double prev_f = 0;
    double f = 0;
    
    int sparse = 1;
    double tolD = 0.001;
    
    //variable phi_l1 and psi_ok 
    double phi_l1 = 0;
    double psi_ok = 0;
    
    //Default eigenvalues
    double lam1 = 1e-4;
    double lamN = 1;
    
    //constants ans internal variables
    double for_ever = 1;
    
    //maj_max_sv: majorizer for the maximum singular value of operator A
    int max_svd = 1;


    char *str=0;
    int i;
    
    

    va_list args;
    va_start(args, arguments);
    
    /*-----------------------
            Optional parameters
    --------------------------*/
    while (true)
    {
        str = va_arg (args,char *);
		if (strcmp(str,"ALPHA")==0){
            alpha = va_arg (args, double);
            cout <<"Alpha: "<< alpha << '\n';
        }
        else if (strcmp(str,"BETA")==0){
            beta = va_arg (args, double);
            cout <<"Beta: "<< beta << '\n';
        }
        else if ( strcmp(str,"STOPCRITERION")==0){
            stopCriterion = va_arg (args, int);
            cout << "Stop criterion: "<<stopCriterion << '\n';
        }
        else if(strcmp(str,"TOLERANCEA")==0){
            tolA = va_arg (args, double);
            cout << "Tolerancia: "<<tolA << '\n';
        }
        else if(strcmp(str,"TOLERANCED")==0){
            tolD = va_arg (args, double);
            cout << "Toleranced: "<<tolD << '\n';
        }
        else if(strcmp(str,"MAXITERA")==0){
            maxiter = va_arg (args, int);
            cout << "Maxitera: "<<maxiter << '\n';
        }
        else if(strcmp(str,"MAXITERD")==0){
            maxiter_debias = va_arg (args, int);
            cout <<"Maxiter debias: "<< maxiter_debias << '\n';
        }
        else if(strcmp(str,"MINITERA")==0){
            miniter = va_arg (args, int);
            cout <<"Mintera: "<< miniter << '\n';
        }
        else if(strcmp(str, "MINITERD")==0){
            miniter_debias = va_arg (args, int);
            cout <<"Miniter debias: "<< miniter_debias << '\n';
        }
        else if(strcmp(str,"INITIALIZATION")==0){
            init=va_arg (args, int);
            cout<<"Init: "<<init<<endl;
        }
        else if(strcmp(str,"MONOTONE")==0){
            enforceMonotone = va_arg (args, int);
            cout <<"EnforceMonotone: "<< enforceMonotone << '\n';
        }
        else if(strcmp(str,"SPARSE")==0){
            sparse = va_arg (args, int);
            cout <<"Sparse: "<< sparse << '\n';
        }
        else{
            break;
        }
    }
    va_end (args);
    
    cout << "Stop criterion: "<<stopCriterion << '\n';
    //Others 
    
    static double *nz_x=new double[tm];
    static double *mask=new double[tm];
    static double *nz_x_prev=new double[tm]; //e
    
    static double *resid=new double[tmy];
    static double *grad=new double[tm];
    
    static double *temp0=new double[tm];
    static double *temp=new double[tm];
    static double *temp1=new double[tm];
    static double *temp2=new double[tm];
    static double *temp3=new double[tm];
    static double *temp4=new double[tmy];
    // initialize
	static double *xm2=new double[tm]; //e
    static double *xm1=new double[tm]; //e

	//static double *objective=new double[100];
	double objective;
    double num_changes_active;
    double c;
    
    //TwIST Parameters
    double rho0;
    rho0 = (1 - lam1/lamN)/(1 + lam1/lamN);
    if (alpha == 0)
    {
        alpha = 2/(1+sqrt(1-(rho0*rho0)));
    }
    if (beta == 0)
    {
        beta  = (alpha*2)/(lam1+lamN);
    }

    
    switch(init)
    {
    case 0: 
    {
        x = new double[tm];

        for(i=0;i<tm;i++){
            x[i]=0.0;
        }
        break;
    };
    default: cout<<"Unknown Initialization option"<<endl;break;
	}
    
    
    double max_tau;
    max_tau = 0.0;

	 //Define the indicator vector or matrix of nonzeros in x
	double num_nz_x;
	
	non_zero(x,tm,nz_x); //Extract the valuez nonzero in a vector
	num_nz_x = sum(nz_x,tm); //Sum the values in a vector
	 
	// Compute and store initial value of the objective function
	Af(x, A, tm, tmy, temp);
	vector_res(y, temp, tmy, resid);
	
	c = vector_prod(resid,resid,tmy);
	prev_f = 0.5*c + tau*phi_function(x,tm); //499
	
	//Start clock	
	//t0 = clock();
	//times(1) = cputime - t0;
	objective = prev_f;
	
	int cont_outer = 1;
	int iter = 1;
	
	// variables controling first and second order iterations
	int IST_iters = 0;
	int TwIST_iters = 0;


    
	xm2=x;
	xm1=x;	
	int k=0;
	
	/*--------------------------------------------------------------
		TwIST iterations
	-------------------------------------------------------------*/
	while (cont_outer)
	{
    // gradient
    AT(resid, A, tm, tmy, grad);
	/*if (k == 0)
	{
		for (i = 0; i < tm; i++)
		{
			cout<<"grad= "<<grad[i]<<", i ="<<i<<"\n"<<endl;
		}
			k=1;
	}*/
		while (for_ever)
		{
			prod_c_v(grad, (1/max_svd), tm, temp0);
			vector_sum(xm1, temp0, tm, temp0);
			psi_function(temp0, tau/max_svd, tm, x);

			if ((IST_iters >= 2) || ( TwIST_iters != 0))
			{
				if (sparse)
				{	
					non_zero(x, tm, mask);
					hadamard(xm1, mask, tm, xm1);
					hadamard(xm2, mask, tm, xm2);
				}
			
				// two-step iteration
				prod_c_v(xm1,(alpha-beta), tm, temp1);
				prod_c_v(xm2,(1-alpha), tm, temp2);
				prod_c_v(x, beta, tm, temp3);
				vector_sum(temp1,temp2, tm, xm2);
				vector_sum(xm2,temp3, tm, xm2);
            
				// compute residual
				Af(xm2, A, tm, tmy, temp4);
				vector_res(y, temp4, tmy, resid);
				
				
				c = vector_prod(resid,resid,tmy);
				f = 0.5*c + tau*phi_function(xm2,tm);
				
				if ((f > prev_f) && (enforceMonotone))
				{
					TwIST_iters = 0;  /*! do a IST iteration if monotonocity fails*/
				}
				else
				{
					TwIST_iters = TwIST_iters+1; // TwIST iterations
					IST_iters = 0;
					x = xm2;
					if ((TwIST_iters % 10000) == 0)
					{
						max_svd = 0.9*max_svd;
					}
					break;  // break loop while
				}	
			}	
			else
			{
				Af(x, A, tm, tmy, temp4);
				vector_res(y, temp4, tmy, resid);
				
				c = vector_prod(resid,resid,tmy);
				f = 0.5*c + tau*phi_function(x,tm);
				
				if (f > prev_f)
				{
					max_svd = 2*max_svd;
					IST_iters = 0;
					TwIST_iters = 0;
				}
				else
				{
					TwIST_iters = TwIST_iters + 1;
					break;
				}
			}/*
			for (i = 0; i < tm; i++)
			{			
				cout<<"x= "<<x[i]<<"\n"<<endl;
			} */
		}
		//while
		xm2 = xm1;
		xm1 = x;        
       
		//update the number of nonzero components and its variation
		nz_x_prev = nz_x;
		non_zero(x, tm, nz_x);
		num_nz_x = sum(nz_x, tm);
		diff(nz_x,nz_x_prev, tm, temp);
		num_changes_active = sum(temp,tm);
		// take no less than miniter and no more than maxiter iterations
		criterion = abs(f-prev_f)/prev_f;
		/*
		 * switch(stopCriterion)
		{
			case 0:
			{
				/* compute the stopping criterion based on the change
				of the number of non-zero components of the estimate*/
		/*		criterion =  num_changes_active;
			}
			case 1:
			{
				/* compute the stopping criterion based on the relative
				variation of the objective function.*/
		/*		criterion = abs(f-prev_f)/prev_f;
				//printf("Stop Criterion Error \n");

			}	
			default:
			{
				printf("Stop Criterion Error \n");
			}
		}
		*/
		cont_outer = ((iter <= maxiter) && (criterion > tolA));
		if (iter <= miniter)
		{
			cont_outer = 1;
		}
	
		iter = iter + 1;
		prev_f = f;
		objective = f;
		//times(iter) = cputime - t0; 
  
	
	}
	printf("\nFinished the main algorithm!\nResults:\n");
    printf("||A x - y ||_2^2 = %8.20f\n",vector_prod(resid,resid,tmy));
	//cout<<"||x||_1 = "<<mysum(x,1.0,tm,0)<<endl;
    printf("Objective function = %10.3f\n",f);
    //printf("Number of non-zero components = %2.0f\n",num_nz_x);
}
