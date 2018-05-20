#include<stdio.h>
#include<string.h>

#define MAX_CORR 100
void menu();

typedef struct{
	char nombre[50];
	char apellido[50];
	char dni[10];
	char fecha [20];
	char pais[30];
	char equipo[30];
	int dorsal;
	tiempo tiempo;
 
}Corredores;

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

void menu(Corredores *corredores){
	int opcion;
	int last_dorsal = 1;
	

do{


printf("BIENVENIDO AL PROGRAMA \n");
printf("PORFAVOR ELIJA UNA OPCION\n");
printf("1. REGISTRAR A UN CORREDOR\n");
printf("2. BUSCAR CORREDOR POR DORSAL\n"); //MOstrar resultados del atleta 
printf("3. REGISTRAR TIEMPOS\n"); //REgistrar tiempos
printf("4. ELIMINAR CORREDOR POR DNI\n"); //Mostrar toda la clasificacion
printf("5. CLASIFICACION\n");
printf("6. IMPRIMIR TIEMPOS\n");
printf("7. SALIR DEL PROGRAMA\n"); 
scanf ("%d", &opcion);

if(opcion>0&&opcion<8){
	switch(opcion){
		case 1:{
			ingresar(corredores, last_dorsal);
			last_dorsal++;
			break;
			}//case 1 switch1
	    case 2:{
			buscar(corredores); 
			break;
			}//case 2 switch1
		case 3:{
			tiempos(corredores); //Se va a llamar tiempos 
			break;
			}//case 3 switch1
		case 4:{
			eliminar(corredores);
					break;
			}//case 4 switch1
		case 5:{
			clasificaciones(corredores, last_dorsal);
			break;
			}
		case 6:{
			imprimir_tiempos(corredores, last_dorsal);
			break;
			}
		case 7:{
			fin();
			}//case7 switch1
	}//fin de switch
  }
  else
  printf("Opcion incorrecta.\n");
 }while(opcion!=7);

}//fin de la funcion menu
