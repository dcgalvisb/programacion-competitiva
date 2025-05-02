#include <stdio.h>
int main()
{
    char categoria;
    const char nombreCategoria[5][10]={"DESAYUNOS","COMIDAS","MERIENDAS","CENAS","COPAS"};
    double valor,ventasPorCategoria[5]={0},mayor,menor,nComidas=0,nVentas=0,total=0;
    short int indiceMay,indiceMen,nMay,nMen,i;
    
    while(1)
    {
        if(scanf("%c %lf%*c",&categoria,&valor)==EOF)return 0;
        if(categoria != 'N')
        {
            if(categoria=='D')
                ventasPorCategoria[0]+=valor;
            else if(categoria=='A'){
                nComidas++;
                ventasPorCategoria[1]+=valor;
            }
            else if(categoria=='M')
                ventasPorCategoria[2]+=valor;
            else if(categoria=='I')
                ventasPorCategoria[3]+=valor;
            else if(categoria=='C')ventasPorCategoria[4]+=valor;
            total += valor;
            nVentas++;
        }
        
        else {
            nMay=nMen=1;
            indiceMay=indiceMen=0;
            mayor=menor=ventasPorCategoria[0];
            for(i=1;i<5;i++)
            {
                if(ventasPorCategoria[i]>mayor){
                    indiceMay=i;
                    nMay=1;
                    mayor=ventasPorCategoria[i];
                    
                }else if(ventasPorCategoria[i]==mayor)
                    nMay++;
                if(ventasPorCategoria[i]<menor)
                {
                    indiceMen=i;
                    nMen=1;
                    menor=ventasPorCategoria[i];
                    
                }
                else if(ventasPorCategoria[i]==menor)
                    nMen++;
            }
            
            printf("%s#",nMay>1?"EMPATE":nombreCategoria[indiceMay]);
            printf("%s#",nMen>1?"EMPATE":nombreCategoria[indiceMen]);
            printf((ventasPorCategoria[1] / nComidas> total/nVentas?"SI\n":"NO\n"));
            for(i=0;i<5;i++)
                ventasPorCategoria[i]=0;
            nComidas=nVentas=total=0;
            
        }

    }
    
}
