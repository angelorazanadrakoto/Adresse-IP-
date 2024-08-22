#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct donnee donnee;
struct donnee 
{
	int partie1;
	int partie2;
	int partie3;
	int partie4;
};
void entete();	
void division( char *data , char  **N1 , char  **N2, char  **N3 , char  **N4);
void sauvegarde( char **N1 , char **N2, char **N3 ,char  **N4, donnee *inscri);
void resultat(donnee *inscri);
void classIP(donnee *inscri , int validity);
void validiteIP(donnee *inscri , int *validity);
void fin();

int main()
{
		char *data ;
		donnee inscri;
		char *N1= NULL ,*N3= NULL ,*N2= NULL, *N4= NULL ; 
		int  validity = 1;
		entete();
		data = getenv("QUERY_STRING");
		division( data , &N1 , &N2, &N3 , &N4);
		sauvegarde( &N1 , &N2, &N3 , &N4 ,&inscri);
		resultat(&inscri);
		validiteIP(&inscri , &validity);
		classIP(&inscri ,  validity);
		fin();
		 
	return 0;
}
void entete()
{
	printf("Content-type: Text/html\n\n");
	printf("<html>\n\t<head>\n\t\t<title>donnee</title>\n\t<style>\n\t\tP{color:blue;}\n\tH4{color : red ;}\n\t\t</style></head>\n<body>\n");
}
void division( char *data , char **N1 , char **N2, char **N3 , char  **N4)
{
	if (data != NULL)
	{ 
		*N1 = strtok(data , "&");
		*N2 = strtok(NULL , "&");
		*N3 = strtok(NULL , "&");
		*N4 = strtok(NULL , "&");
	}
}
void sauvegarde( char **N1 , char **N2, char **N3 ,char  **N4, donnee *inscri)
{
	if (*N1 != NULL || *N2 != NULL || *N3 != NULL || *N4 != NULL)
	{
		sscanf(*N1 , "I=%d" , &inscri->partie1);
		sscanf(*N2 , "II=%d" , &inscri->partie2);
		sscanf(*N3 , "III=%d" , &inscri->partie3);
		sscanf(*N4 , "IV=%d" , &inscri->partie4);
	}	
}
void resultat(donnee *inscri)
{           
	printf("<h4>IP:%d.%d.%d.%d</h4>", inscri->partie1 ,inscri->partie2 ,inscri->partie3 ,inscri->partie4 );            
}
void classIP(donnee *inscri , int validity)
{
	if (validity == 1 )
	{
		if (inscri->partie1 >= 0  && inscri->partie1 < 128)
		{
			printf("<p  >=> IP de classe A</p>");
		}
		if (inscri->partie1 >= 128  && inscri->partie1 < 192)
		{
			printf("<p > => Adresse IP de classe B</p>");
		}
		if (inscri->partie1 >=192   && inscri->partie1 < 224)
		{
			printf("<p > => Adresse IP de classe C</p>");
		}
		if (inscri->partie1 >=224  && inscri->partie1 < 240)
		{
			printf("<p > => Adresse IP de classe D</p>");
		}
		if (inscri->partie1 >= 240  && inscri->partie1 <= 255)
		{
			printf("<p > =>Adresse IP de classe E</p>");
		}
	}
}
void validiteIP(donnee *inscri , int *validity)
{
	if (inscri->partie1 > 255 || inscri->partie2 > 255 ||inscri->partie3 > 255 ||inscri->partie4 > 255 )
	{
		printf("<p>Adresse IP non valide</p>");
		*validity = 0;
	}
}
void fin()
{
	printf("\n\t</body>\n</html>");
}	
