#include <stdio.h>
bool estaEquilibrado(int pi,int di,int pd,int dd,int *s)
{
    bool izq=1,der=1;
    if(pi==0){
        int api,adi,apd,add;
        scanf("%d %d %d %d",&api,&adi,&apd,&add);
        izq = estaEquilibrado(api,adi,apd,add,&pi);
        
    }
    if(pd==0){
        int api,adi,apd,add;
        scanf("%d %d %d %d",&api,&adi,&apd,&add);
        der = estaEquilibrado(api,adi,apd,add,&pd);
        
    }
    *s=pi+pd;
    return  pi*di==pd*dd && izq && der;
    
    }
int main()
{
	int pi,di,pd,dd,suma;
	
	while(1)
	{	
	    scanf("%d %d %d %d",&pi,&di,&pd,&dd);
	    if(pi==0&&di==0&&pd==0&&dd==0)break;
	    suma=0;
	    printf(estaEquilibrado(pi,di,pd,dd,&suma)==1?"SI\n":"NO\n");
	}
	return 0;
}
