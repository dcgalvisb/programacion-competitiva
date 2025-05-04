#include <stdio.h>
#include <string.h>

const char *tiemposVerbales  [3][3][6]={
        {
            {"o", "as", "a", "amos", "ais", "an"},
            {"e", "aste", "o", "amos", "asteis", "aron"},
            {"are", "aras", "ara", "aremos", "areis", "aran"},
        },
        {
            {"o", "es", "e", "emos", "eis", "en"},
            {"i", "iste", "io", "imos", "isteis", "ieron"},
            {"ere", "eras", "era", "eremos", "ereis", "eran"},
        },
        {
            {"o", "es", "e", "imos", "is", "en"},
            {"i", "iste", "io", "imos", "isteis", "ieron"},
            {"ire", "iras", "ira", "iremos", "ireis", "iran"}
        }
    };

const char *personas[6]={"yo","tu","el","nosotros","vosotros","ellos"};

int main()
{
    char tVerbal;
	char verbo[21];
	char lexema[21];
	char letra;
	int longitud;
	short int i,j,k;
	while(1)
	{
		scanf("%s %c",verbo,&tVerbal);
		if(tVerbal=='T')break;
		longitud = strlen(verbo)-2;
    	strncpy(lexema, verbo,longitud);
    	lexema[longitud] ='\0';
		
		if(verbo[longitud]=='a')i=0;
		else if(verbo[longitud]=='e')i=1;
		else i=2;
		if(tVerbal=='A')j=0;
		else if(tVerbal=='P')j=1;
		else if(tVerbal=='F')j=2;
		for(k=0;k<6;k++)
		    printf("%s %s%s\n",personas[k],lexema,tiemposVerbales[i][j][k]);
	}
	return 0;
}
