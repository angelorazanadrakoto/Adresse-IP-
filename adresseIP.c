#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct a_propos a_propos;
struct a_propos 
{
	int partie1;
	int partie2;
	int partie3;
	int partie4;
};
void entete();	
void division( char *donne , char  **N1 , char  **N2, char  **N3 , char  **N4);
void enregistrement( char **N1 , char **N2, char **N3 ,char  **N4, a_propos *inscri);
void resultat(a_propos *inscri);
void IPclass(a_propos *inscri , int validity);
void validationIP(a_propos *inscri , int *validity);
void fin();

int main()
{
	char *donne ;
	a_propos inscri;
	char *N1= NULL ,*N3= NULL ,*N2= NULL, *N4= NULL ; 
	int  validity = 1;
	entete();
	donne = getenv("QUERY_STRING");
	division( donne , &N1 , &N2, &N3 , &N4);
	enregistrement( &N1 , &N2, &N3 , &N4 ,&inscri);
	resultat(&inscri);
	validationIP(&inscri , &validity);
	IPclass(&inscri ,  validity);
	fin();	 
	return 0;
}
void entete()
{
	printf("Content-type: Text/html\n\n");
	printf("<html>\n\t<head>\n\t\t<title>AdresseIP</title>\n\t<style>\n\t\tbody{background-color:rgb(85, 85, 204);}A{color: yellowgreen;}h1{font-size:50px;color:red;}P{color:yellow;}\n\tH4{color : chartreuse ;}button{background-color: darkblue;border: 5px double red;padding: 50px;border-radius: 10px 10px 10px 10px;font-size: 25px;height: 400px;width: 400px;}\n");
	printf("\t\t</style></head>\n<body><center><button>\n");
}
void division( char *donne , char **N1 , char **N2, char **N3 , char  **N4)
{	
	if (donne != NULL)
	{ 
		*N1 = strtok(donne , "&");
		*N2 = strtok(NULL , "&");
		*N3 = strtok(NULL , "&");
		*N4 = strtok(NULL , "&");
	}
}
void enregistrement( char **N1 , char **N2, char **N3 ,char  **N4, a_propos *inscri)
{
	if (*N1 != NULL || *N2 != NULL || *N3 != NULL || *N4 != NULL)
	{
		sscanf(*N1 , "part=%d" , &inscri->partie1);
		sscanf(*N2 , "part1=%d" , &inscri->partie2);
		sscanf(*N3 , "part2=%d" , &inscri->partie3);
		sscanf(*N4 , "part3=%d" , &inscri->partie4);
	}
	
}
void resultat(a_propos *inscri){
           
			printf("<h1>L'ADRESSE IP</h1>");
			printf("<h4>IP:%d.%d.%d.%d", inscri->partie1 ,inscri->partie2 ,inscri->partie3 ,inscri->partie4 );
            
	}
void IPclass(a_propos *inscri , int validity)
{
	if (validity == 1 )
	{
		if (inscri->partie1 >= 0  && inscri->partie1 < 128){
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
void validationIP(a_propos *inscri , int *validity)
{
	if (inscri->partie1 > 255 || inscri->partie2 > 255 ||inscri->partie3 > 255 ||inscri->partie4 > 255 )
	{
		printf("<p>Adresse IP non valide</p>");
		*validity = 0;
	}
}
void fin()
{
	printf("</button></center>\n");
	printf("<br><A href=""reseau.html"">CLIQUER ICI POUR RETAPPER</A>");
	printf("\n\t</body>\n</html>");
}	