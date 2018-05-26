#include<stdio.h>
#include<string.h>



#define MAX_CORR 100

void ingresar();
void buscar();
void tiempos();
void eliminar();
void fin();
void menu();
void clasificaciones();
void intercambiar();
void imprimir_tiempos();
void ordenar();

typedef struct 
{
	int horas;
	int minutos;
	int segundos;
}tiempo;

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

void ingresar(Corredores *corredores, int last_dorsal){
	printf("Valor del contador: %d\n", last_dorsal);
	
	printf("Ingrese Nombre\n");
	scanf("%s", corredores[last_dorsal-1].nombre);
	printf("Ingrese Apellido(SOLO EL PRIMER APELLIDO)\n");
	scanf("%s", corredores[last_dorsal-1].apellido);
	printf("Ingrese su DNI\n");
	scanf("%s", corredores[last_dorsal-1].dni);
	printf("Fecha de nacimiento\n");
	scanf("%s", corredores[last_dorsal-1].fecha);
	printf("Pais\n");
	scanf("%s", corredores[last_dorsal-1].pais);
	//El dorsal no lo elige el corredor se le asigna segun llega
	corredores[last_dorsal-1].dorsal = last_dorsal;
	printf("Tu dorsal es el: %d\n", corredores[last_dorsal-1].dorsal);
	printf("Jugador registrado correctamente con dorsal %d .\n\n", corredores[0].dorsal);

	

}
 
void buscar(Corredores *corredores){
	int dorsal;
	int i;

	 printf("Ingrese el numero de dorsal\n");
	 scanf("%d", &dorsal);
	 for(i=0;i<=MAX_CORR;i++)
	 {
		 if(corredores[i].dorsal== dorsal)
		 {
			printf("Nombre: %s \n", corredores[i].nombre);
			printf("Apellido: %s \n", corredores[i].apellido);	
			printf("Pais: %s \n", corredores[i].pais);
			printf("Dorsal: %d \n", corredores[i].dorsal);
			printf("Horas: %d \n", corredores[i].tiempo.horas);
			printf("Minutos: %d \n", corredores[i].tiempo.minutos);
			printf("Segundos: %d \n\n", corredores[i].tiempo.segundos);

			return;
			
		}
		//fin de condicional for
	
	}
	printf("El corredor no ha sido encontrado o ha sido eliminado\n\n");
	//fin de ciclo for
 }//fin de case 1
 

void tiempos(Corredores *corredores){
	int dorsal;
	int i;

	printf("Introduce el dorsal: ");
	scanf("%d", &dorsal);
	
	
	for(i=0;i<=MAX_CORR;i++)
	 {
		 if(corredores[i].dorsal == dorsal)
		 {
	
	
		printf("Ingrese los tiempos(horas, minutos, segundos) \n");
		printf("Introduce horas\n ");
		scanf("%d", &corredores[i].tiempo.horas);
		do{
			printf("Introduce minutos\n ");
			scanf("%d", &corredores[i].tiempo.minutos);
			if(corredores[i].tiempo.minutos > 60)
				printf("Los minutos deben ser menores de 60\n");
		}while(corredores[i].tiempo.minutos > 60);
		
		do{
			printf("Introduce segundos\n ");
			scanf("%d", &corredores[i].tiempo.segundos);
			if(corredores[i].tiempo.segundos > 60)
				printf("Los segundos deben ser menores de 60\n");
		}while(corredores[i].tiempo.segundos > 60);
		
		return;
	}
	}
}//fin de modificar
 
void eliminar(Corredores *corredores){
	char dni[10];
	dni[0] = '\0';
	int u;
	printf("Ingrese el dni que desea Eliminar\n");
	printf("ADVERTENCIA:Los Datos no seran Recuperados\n");
	printf("Ingrese el dni\n");
	scanf("%s", dni);
		
	for(u=0 ; u < MAX_CORR ; u++){
			
		if (strcmp(corredores[u].dni, dni)==0){
			
			printf("%s \n",corredores[u].nombre);
			printf("%s \n",corredores[u].apellido);
			
			printf("%s \n",corredores[u].pais);
			printf("%s \n",corredores[u].fecha);
			printf("%d \n",corredores[u].dorsal);
		
			corredores[u].nombre[0] = '\0';
			corredores[u].apellido[0] = '\0';
		
			corredores[u].pais[0] = '\0';
			corredores[u].dorsal= -1;
			corredores[u].fecha[0] = '\0';
			printf("Se elimino el corredor\n\n");
		
		}//fin de condicional if
	}//fin de ciclo for
	
}//Fin de eliminar
 
void fin(){
	printf("Gracias por usar nuestro programa.");
return;

}

void intercambiar(Corredores *uno, Corredores *dos){
	Corredores aux;

	aux = *uno;
	*uno = *dos;
	*dos = aux;

	return;
}



void ordenar (Corredores *corredores, int last_dorsal)
{
   
  int i, j;
  int marca =1;
  
  for (i = last_dorsal-2 ; marca==1 && i>= 0+1 ; i--)
  {
  	marca= 0;
    for (j = 0; j<= i-1 ; j++)
    {
      //Lo suyo
      
      if (corredores[j].tiempo.horas > corredores[j+1].tiempo.horas)
   		{
   			intercambiar(&corredores[j], &corredores[j+1]);
   			 marca =1;
    	}
    	else if (corredores[j].tiempo.horas == corredores[j+1].tiempo.horas){
			if(corredores[j].tiempo.minutos > corredores[j+1].tiempo.minutos){
    			intercambiar(&corredores[j], &corredores[j+1]);
    			marca =1;      
			}
			else if(corredores[j].tiempo.minutos == corredores[j+1].tiempo.minutos){
				if(corredores[j].tiempo.segundos > corredores[j+1].tiempo.segundos){
	    			intercambiar(&corredores[j], &corredores[j+1]);
	    			marca =1;		  
				}
				
			}
    }
	
    }
  }
  
   
}


void clasificaciones(Corredores *corredores, int last_dorsal){

int i, j,contador;
    ordenar(corredores, last_dorsal);
    for(i = 0 ; i < last_dorsal -2 ; i++ ){
    	printf("\n\t-%dº -> dorsal: %d", i+1, corredores[i].dorsal);
    }

    printf("\n\tEl dorsal del mejor tiempo es: %d", corredores[0].dorsal);
    printf("\n\tEl dorsal del peor tiempo es: %d \n\n", corredores[last_dorsal-2].dorsal);

    printf("\tSi se ha eliminado algun jugador la clasificacion puede verse alterada.\n");
    
    return;

}





void imprimir_tiempos(Corredores *corredores, int last_dorsal){

 FILE *f;
 int i;
 
 f=fopen("tiempo.txt","w");
 
 if( f==NULL )
	printf("Error al abrir el fichero\n");
 else
 {
	  for(i=0; i<last_dorsal -1; i++){
	  fprintf(f,"Dorsal: %d\n", corredores[i].dorsal);
	  if(corredores[i].dorsal==-1)
	  fprintf(f,"(El jugador ha sido eliminado)\n");
	  fprintf(f,"%dh  ", corredores[i].tiempo.horas);
	  fprintf(f,"%dmin  ", corredores[i].tiempo.minutos);
	  fprintf(f,"%ds\n", corredores[i].tiempo.segundos);
	  }
 }

 fclose(f);
}
