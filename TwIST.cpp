void TwIST(double *y,const object *A, double tau,double *&x,int arguments, ...){

    int tmy = A->shots*A->apertures[0].m*(A->apertures[0].n+(A->l-1));
    int tm = A->apertures[0].n*A->apertures[0].m*A->l;
    double f=1.0,tol_debias=0.001,num_nz_x=2.0,alpha=1.0;
    bool cont_debias_cg=true,keep_going;
    static double *RWpvec=0;
    double beta_cg=0.0,alpha_cg=0.0,rTr_cg_plus=0.0,rTr_cg=0.0,final_tau=0.0;
    double final_tolA=0.0001;
    double tmp;
    //clock_t t0;
    int iter=0;
    int final_stopCriterion=4;
    const unsigned Initial_X_supplied=80;
    
    
    int stopCriterion = 1;
    double tolA = 0.01;
    bool debias = 0;
    int maxiter = 10000;
    int maxiter_debias = 200;
    int miniter = 5;
    int miniter_debias = 5;
    int init = 0;

    
    int enforceMonotone = 1;
    double alphamin = 1e-30;
    double alphamax = 1e30;
    bool compute_mse = false;
    bool verbose = true;
    bool continuation = false;
    int cont_steps = -1;
    int firstTauFactorGiven = 0;
    double firstTauFactor = 0.0,criterionObjective=0.0,realmin=0.0,lambda0=0.0;
    double lambda=0.001,dGd=0.0,criterionActiveSet=0.0,delta_x_criterion=0.0;
    double prev_f=0.0,dd=0.0,num_changes_active=0.0,criterionLCP=0.0;
    char *str=0;
    int i;
    

    va_list args;
    va_start(args, arguments);

    while (true)
    {

        str = va_arg (args,char *);
        if ( strcmp(str,"STOPCRITERION")==0){
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
        }
        else if(strcmp(str,"MONOTONE")==0){
            enforceMonotone = va_arg (args, int);
            cout <<"EnforceMonotone: "<< enforceMonotone << '\n';
        }
        else if(strcmp(str,"CONTINUATION")==0){
            continuation = va_arg (args, bool);
            cout <<"Continuacion: "<< continuation << '\n';
        }
        else if(strcmp(str,"CONTINUATIONSTEPS")==0){
            cont_steps = va_arg (args, int);
            cout <<"ContSteps: "<< cont_steps << '\n';
        }
        else if(strcmp(str,"FIRSTTAUFACTOR")==0){
            firstTauFactor = va_arg (args, int);
            firstTauFactorGiven = 1;
            cout <<"FirstTauFactor: "<< firstTauFactor << '\n';
        }
        else if(strcmp(str,"TRUE_X")==0){
            compute_mse = true;
            va_arg (args, bool);
        }
        else if(strcmp(str,"ALPHAMIN")==0){
            alphamin = va_arg (args, double);
            cout <<"Alpha min: "<< alphamin << '\n';
        }
        else if(strcmp(str,"ALPHAMAX")==0){
            alphamax = va_arg (args, double);
            cout <<"Alpha max: "<< alphamax << '\n';
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

