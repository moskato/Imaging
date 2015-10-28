void TwIST(double *y,const object *A, double tau,double *&x,int arguments, ...){

    /*int tmy = A->shots*A->apertures[0].m*(A->apertures[0].n+(A->l-1));
    int tm = A->apertures[0].n*A->apertures[0].m*A->l;
    double f=1.0,tol_debias=0.001,num_nz_x=2.0,alpha=1.0;
    bool cont_debias_cg=true,keep_going;
    static double *RWpvec=0;
    double beta_cg=0.0,alpha_cg=0.0,rTr_cg_plus=0.0,rTr_cg=0.0,final_tau=0.0;
    double final_tolA=0.0001;
    double tmp;*/
    
    int tm = A->apertures[0].n*A->apertures[0].m*A->l;
    //clock_t t0;
    int stopCriterion = 1;
    double tolA = 0.01;
    bool debias = false;
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
    
    int sparse = 1;
    double tolD = 0.001
    //variable phi_l1 and psi_ok type?
    double phi_l1 = 0;
    double psi_ok = 0;
    //Default eigenvalues
    double lam1 = 1e-4;
    double lamN = 1;
    //constants ans internal variables
    double for_ever = 1;
    //maj_max_sv: majorizer for the maximum singular value of operator A
    int max_svd = 1;

    //Set the defaults for outputs that may not be computed
    int debias_start = 0;
    double x_debias = [];
    double mses = [];

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
        if ( strcmp(str,"LAMBDA")==0){
            lam1 = va_arg (args, double);
            cout << "Lambda: "<<lam1 << '\n';            
        }
        else if (strcmp(str,"ALPHA")==0){
            alpha = va_arg (args, double);
            cout <<"Alpha: "<< alpha << '\n';
        }
        else if (strcmp(str,"BETA")==0){
            beta = va_arg (args, double);
            cout <<"Beta: "<< beta << '\n';
        }
        //-------
        //Add Psi and Phi Varargin (Check dependencies) ----------------------------------------------------Check
        //-------
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
        else if(strcmp(str,"DEBIAS")==0){
            debias = va_arg (args, bool);
            cout << "Debias: "<<debias << '\n';
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
            //Inizialization have an "If" ---> Check O_O ------------------------------------------------Check
        }
        else if(strcmp(str,"MONOTONE")==0){
            enforceMonotone = va_arg (args, int);
            cout <<"EnforceMonotone: "<< enforceMonotone << '\n';
        }
        else if(strcmp(str,"SPARSE")==0){
            sparse = va_arg (args, int);
            cout <<"Sparse: "<< sparse << '\n';
        }
        else if(strcmp(str,"TRUE_X")==0){
            compute_mse = true;
            va_arg (args, bool);
        }
        else if(strcmp(str,"AT")==0){
            AT = va_arg (args, int);
            cout <<"AT: "<< AT << '\n';
        }        
        else if(strcmp(str,"VERBOSE")==0){
            verbose = va_arg (args, int);
            cout <<"Verbose: "<< verbose << '\n';
        }
        else{
            break;
        }
    }
    va_end (args);
    
    //TwIST Parameters
    double rho0;
    rho0 = (1 - lam1/lamN)/(1 + lam1/lamN);
    if (alpha == 0)
    {
        alpha = 2/(1+sqrt(1-rho0^2));
    }
    if (beta == 0)
    {
        beta  = (alpha*2)/(lam1+lamN);
    }
}
