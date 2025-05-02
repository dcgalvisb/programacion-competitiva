#include <stdio.h>
int main()
{
    short int n,k,**matriz,i,j;
    int suma;
    scanf("%hu %hu",&n,&k);

    while(n != 0 || k != 0)
    {

            matriz = new short int*[n];
            for(i = 0;i < n; i++)
                matriz[i] = new short int[n];

            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    matriz[i][j] = -1;

            i = 0;
            j = n/2;
            matriz[0][j] = k;
            k+=1;
            bool continuar = true;

            while(continuar)
            {
                if( (i - 1 ) < 0 && (j + 1) >= n){
                    continuar = false;
                    break;
                }
                else if( (i - 1) < 0){
                        i = n - 1;
                        j+=1;
                        matriz[i][j] = k;

                }
                else if( (j  + 1) >= n){
                        j = 0;
                        i -= 1;
                        matriz[i][j] = k;

                }
                else if( matriz[i - 1][j + 1] != -1){
                        i+=1;
                        matriz[i][j]=k;

                }
                else{
                        --i;
                        ++j;
                        matriz[i][j]=k;

                }
                k+=1;

            }

            j = suma = 0;
            for(i = n-1; i > -1; i--)
                suma += matriz[i][j++];

            printf("%d\n",suma);

            for(i = 0; i < n; i++)
                delete []matriz[i];
            delete []matriz;

            scanf("%hu %hu",&n,&k);
    }
    return 0;
}
