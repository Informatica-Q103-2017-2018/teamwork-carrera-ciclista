#include<stdio.h>
#include<string.h>



#define MAX_CORR 100

int main()
{
	int i,a;
	Corredores corredores[MAX_CORR];
	for( i = 0 ; i < MAX_CORR ; i++){
		corredores[i].nombre[0] = '\0';
		corredores[i].apellido[0] = '\0';
		corredores[i].dni[0] = '\0';
		corredores[i].fecha[0] = '\0';
		corredores[i].pais[0] = '\0';
		corredores[i].equipo[0] = '\0';
		corredores[i].dorsal = -1;
		corredores[i].tiempo.horas = 0;
		corredores[i].tiempo.minutos = 0;
		corredores[i].tiempo.segundos = 0;
	}
	menu(corredores);
	return 0;
}
