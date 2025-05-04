#include <stdio.h>
int main()
{
	int pkInicio,pkFinal,disPlana,pkDP,auxDisPlana,km;

	while(1)
	{
		scanf("%d",&pkInicio);
		if(pkInicio==-1)return 0;
		km = auxDisPlana=disPlana = 0;
		while(1)
		{
		    scanf("%d",&pkFinal);
		    if(pkFinal==-1)break;
		    if(pkInicio-pkFinal==0){
		        auxDisPlana++;
		        if(auxDisPlana>disPlana){
		            disPlana=auxDisPlana;
		            pkDP=km+1;
		            }
		    }
		    else auxDisPlana=0;
		    km++;
		    pkInicio=pkFinal;
	        }

	   if(disPlana==0)printf("HOY NO COMEN\n");
	   else printf("%d %d\n",(pkDP-disPlana),disPlana);
	}
}
