#include <stdio.h>
int main()
{
    int nEvoltorios;
    int aRegalar;
    int tCComprados; 
    int tCConsumidos;
    int residuo;
    int cociente;
	
	while(1)
	{	
		scanf("%d %d %d",&nEvoltorios,&aRegalar,&tCComprados);
		if(nEvoltorios==0&&aRegalar==0&&tCComprados==0)return 0;
		if(tCComprados==0)printf("0 0\n");
		else if(aRegalar==0)printf("%d %d\n",tCComprados,tCComprados);
		else if (aRegalar>=nEvoltorios&&tCComprados>=nEvoltorios)printf("RUINA\n");
		else {
		    tCConsumidos=tCComprados;
		    while(tCComprados>=nEvoltorios)
		    {
		        cociente = tCComprados/nEvoltorios;
		        tCConsumidos += cociente*aRegalar;
		        residuo  = tCComprados%nEvoltorios;
		        tCComprados  = cociente + residuo;
		        
		        }
		  
		    printf("%d %d\n",tCConsumidos,tCComprados);
		    }
	}
	
}
