#include <stdio.h>
#include <string.h>
int main(){
    char numero1[1001];
    char numero2[1001];
    short int ln1,ln2,digito1,digito2,acarreo,suma,total,i,j;
    while(1)
    {
        scanf("%s %s",numero1,numero2);
        if(numero1[0]=='0'&&numero2[0]=='0')break;
        i=strlen(numero1)-1;
        j=strlen(numero2)-1;
        total=acarreo=0;
        while(1){
            
            digito1 = i>-1?(numero1[i--]-48):0;
            digito2 = j>-1?(numero2[j--]-48):0;
            suma=digito1+digito2+acarreo;
            
            if(suma>9){
                total++;
                acarreo=1;
            }
            else acarreo=0;
            if((acarreo==0&&(i==-1||j==-1))||(i==-1&&j==-1))break;
        }
        printf("%hd\n",total);
    }
    return 0;
}
