#include <stdio.h>
#include <math.h>
int main()
{
    int m,n;
    float maxError [6]={1.0,0.1,0.01,0.001,0.0001,0.00001};
    float error,errorGauss,tn,totales[100000];
    bool estaMarcado[100000];
    totales[1]=0;
		    for(int i=2;i<=316;i++)
		        if(!estaMarcado[i]){
		            int aux=100000/i;
		            for(int j=i;j<=aux;j++)
		                estaMarcado[i*j]=1;
	                }
	       for(int i=2;i<100000;i++)
	            totales[i]=estaMarcado[i]?totales[i-1]:totales[i-1]+1.0;
	
	while(1)
	{
	    scanf("%d%d",&n,&m);
		if(n==0&&m==0)break;
		if(n==1)printf("Menor\n");
		else
		    errorGauss=fabs((double)totales[n]/n-(double)(1.0/log((double)n)));
		    if(errorGauss==maxError[m])printf("Igual\n");
		    else if(errorGauss>maxError[m])
		            printf("Mayor\n");
		         else
		            printf("Menor\n");
	}
	return 0;
}
