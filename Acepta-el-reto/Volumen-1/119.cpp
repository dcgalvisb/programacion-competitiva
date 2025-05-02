#include <stdio.h>
#include <math.h>
int main()
{
	int totalEscudos,nSoldados;
	short int nFormacion;
	while(1)
	{	
		scanf("%d",&nSoldados);
		if(nSoldados==0)return 0;
		totalEscudos=nFormacion=0;
		while(nSoldados!=0)
		{
		    nFormacion=sqrt(nSoldados);
		    totalEscudos+=12+(nFormacion-2)*(nFormacion+6); 
		    nSoldados-=(nFormacion*nFormacion);
		    }
		printf("%d\n",totalEscudos);
	}
	
}
