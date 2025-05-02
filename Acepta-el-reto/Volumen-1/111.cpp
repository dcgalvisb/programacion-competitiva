#include <stdio.h>
#include <string.h>
int main()
{
    char elemento[50];
    short int electrones[19] = {2,2,6,2,6,2,10,6,2,10,6,2,14,10,6,2,14,10,6};
    char subNiveles[19][3]={"1s","2s","2p","3s","3p","4s","3d","4p","5s","4d","5p","6s","4f","5d","6p","7s","5f","6d","7p"};
	int nAtomico,posicion,n;
	while(1)
	{
		scanf("%s",elemento);
		if(strcmp(elemento,"Exit")==0)return 0;
		scanf("%d",&nAtomico);
		n = 2;
		posicion = 0;
		while(n < nAtomico){
		    printf("%s%d ",subNiveles[posicion],electrones[posicion]);
		    n += electrones[++posicion];
		}
		if(n==nAtomico)
            printf("%s%d\n",subNiveles[posicion],electrones[posicion]);
        else
            printf("%s%d\n",subNiveles[posicion],nAtomico-(n-electrones[posicion]));
	}
}
