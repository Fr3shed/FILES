#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define IDENT 21
#define NOM 21
#define DESC 151
#define FECHA 11
#define NUM 10
#define ART 100

struct articulos{
    char identificador2[IDENT];
    int iden_num;
    char modelo[NOM];
    char marca[NOM];
    char fecha[FECHA];
    int stock_art;
    char tipo_art[NOM];
    float precio_art;
    float precio_transport;
    char ident_id_numerico[IDENT];
    int activo1;
};


struct componentes{
    char identificador1[IDENT];
    char nombre[NOM];
    char descripcion[DESC];
    int stock_comp;
    int activo;
    struct articulos articulo[ART];
};	

void dar_alta(FILE *componente1, char identificador1[IDENT],char nombre[NOM],char descripcion[DESC],char conversion[NOM]){
	fgets(identificador1,IDENT,componente1);
	fgets(nombre,NOM,componente1);
	fgets(descripcion,DESC,componente1);
	fgets(conversion,NOM,componente1);	
}

struct componentes crear_componente(char identificador1[IDENT],char nombre[NOM],char descripcion[DESC],char conversion[NOM],int stock_comp,int activo){
	struct componentes componente;
	strcpy(componente.identificador1,identificador1);
	strcpy(componente.nombre,nombre);
	strcpy(componente.descripcion,descripcion);
	componente.stock_comp = atoi(conversion);
	componente.activo = 1;
	return componente;
}



void dar_alta_articulo(FILE *componente1,char identificador2[IDENT],char fecha[FECHA],char modelo[NOM],char marca[NOM],char tipo_art[NOM],char precio_art1[NUM],char precio_transport1[NUM],char conversion[NOM]
, char ident_id_numerico[IDENT]){
	fgets(identificador2,IDENT,componente1);
	fgets(fecha,FECHA,componente1);
	fgets(modelo,NOM,componente1);
	fgets(marca,NOM,componente1);
	fgets(tipo_art,NOM,componente1);
	fgets(precio_art1,NUM,componente1);
	fgets(precio_transport1,NUM,componente1);
	fgets(conversion,NOM,componente1); 
	fgets(ident_id_numerico,IDENT,componente1);
} 

struct articulos crear_articulo(char identificador2[IDENT],char fecha[FECHA],char modelo[NOM],char marca[NOM],char tipo_art[NOM],float precio_art,float precio_transport,char precio_art1[NUM],
char precio_transport1[NUM], char conversion[NOM],int activo1, int stock_art,char ident_id_numerico[IDENT]){
	struct articulos articulo;
	strcpy(articulo.identificador2, identificador2);
	strcpy(articulo.fecha, fecha);
	strcpy(articulo.modelo, modelo);
	strcpy(articulo.marca, marca);
	strcpy(articulo.tipo_art, tipo_art);
	articulo.precio_art = atoi(precio_art1);
	articulo.precio_transport = atoi(precio_transport1);
	articulo.stock_art = atoi(conversion);
	articulo.activo1 = 1;
	strcpy(articulo.ident_id_numerico, ident_id_numerico);
	return articulo;
}

/*/void comparacion_articulos(FILE *componente1,struct componentes componente,char ident_id_numerico[IDENT],char fichero[NOM]){
	int j;
	if((componente1 = fopen(fichero,"r")) != NULL){
		fgets(ident_id_numerico,IDENT,componente1);
		for(j = 0; j < ART; j++){
			if((strcmp(componente.articulo[j].ident_id_numerico,ident_id_numerico) == 0) && (componente.articulo[j].activo1 == 1) && (componente.activo == 1)){
				printf("El articulo se ha eliminado correctamente\n");
				componente.articulo[j].activo1 = 0;
				printf("Activo: %d", componente.articulo[j].activo1);
			}
		}	
	}
	else{
		printf("El fichero no coincide\n");
	}
	fclose(componente1);	
}/*/

main(){
	//struct articulos articulo[ART];
	struct componentes componente[NUM];
	char identificador[IDENT], modelo[NOM],marca[NOM],fecha[FECHA],tipo_art[NOM],identificador1[IDENT],nombre[NOM],descripcion[DESC],conversion[NOM],seguir = 'y',comparacion[IDENT],fichero[NOM];
	char precio_art1[NUM],precio_transport1[NUM],identificador2[IDENT],ident_id_numerico[IDENT];
	float precio_art,precio_transport;
	int stock_art,stock_comp,iden_num,opcion,contador = 0,activo = 0,stock_comp1,activo1 = 0, j, k = 0, i, creado;
	FILE *componente1;
	do{
		printf("OPCION 1: DAR DE ALTA COMPONENTES\n");
		printf("OPCION 2: DAR DE BAJA COMPONENTES\n");
		printf("OPCION 3: DAR DE BAJA ARTICULOS\n");
		printf("OPCION 4: DAR DE ALTA ARTICULOS\n");
		printf("OPCION 5: GUARDAR ESTADO DE PROGRAMA\n");
		printf("OPCION 6: CARGAR ESTADO DE FICHERO\n");
		printf("OPCION 7: LISTAR LOS DATOS\n");
		printf("Escribe una opcion: ");
		scanf("%d",&opcion);
		fflush(stdin);
		switch(opcion){
			case 1:
				printf("contador: %d\n",contador);
				do{
				printf("Escribe el nombre del fichero: ");
				fflush(stdin);
				gets(fichero);
				seguir = 'y';
					if((seguir == 'y') && ((componente1 = fopen(fichero,"r")) != NULL)) {
						dar_alta(componente1,identificador1,nombre,descripcion,conversion);
						fclose(componente1);
						componente[contador] = crear_componente(identificador1, nombre, descripcion,conversion,stock_comp, activo);
						contador++;
						printf("Quieres seguir introduciendo componentes(y/n)");	
						scanf("%c",&seguir);
						fflush(stdin);
						}
					else{
						printf("Ese fichero no existe o ya se encuentra activo en esa posicion.\n");
						seguir = 'n';
					}			
				}
				while(seguir == 'y');
				break;
			case 2:
				printf("Escribe el fichero: ");
				fflush(stdin);
				gets(fichero);
				printf("Escribe el identificador: ");
				fflush(stdin);
				gets(comparacion);
				printf(" COMP: %s\n",comparacion);
				for(i = 0; i < NUM; i++){
					if((componente1 = fopen(fichero,"r")) != NULL){
						fgets(comparacion,IDENT,componente1);
						if((strcmp(comparacion,componente[i].identificador1) == 0) && (componente[i].activo == 1)){
							printf("Quieres eliminar los articulos asociados a %s (y/n)?\n",comparacion);
							scanf("%c",&seguir);
							if(seguir == 'y'){
								componente[i].activo = 0;
								printf("Activo: %d\n", componente[i].activo);
							}
						}
						else{
							printf("El fichero no esta activo o el identificador no coincide.");
						}
					}
				}
				fclose(componente1);
				break;
			case 3:
					printf("Escribeme el fichero: ");
					fflush(stdin);
					gets(fichero);
					printf("Escribeme el identificador (con el id numerico del articulo): ");
					fflush(stdin);
					gets(ident_id_numerico);
					for(i = 0; i < NUM; i++){
						if((componente1 = fopen(fichero,"r")) != NULL){
							fgets(ident_id_numerico,IDENT,componente1);
							for(j = 0; j < ART; j++){
								if((strcmp(componente[i].articulo[j].ident_id_numerico,ident_id_numerico) == 0) && (componente[i].articulo[j].activo1 == 1) && (componente[i].activo == 1)){
									printf("El articulo se ha eliminado correctamente\n");
									componente[i].articulo[j].activo1 = 0;
									printf("Activo: %d", componente[i].articulo[j].activo1);
								}
							}	
						}
						else{
							printf("El fichero no existe.\n");
						}
					}
					fclose(componente1);
					break;
			case 4:	
					printf("Escribeme el fichero: ");
					fflush(stdin);
					gets(fichero);
					if((componente1 = fopen(fichero,"r")) != NULL){
						dar_alta_articulo(componente1,identificador2,fecha,modelo,marca,tipo_art,precio_art1,precio_transport1,conversion,ident_id_numerico);
						for(i = 0; i < NUM; i++){
							if((strcmp(identificador2,componente[i].identificador1) == 0) && (componente[i].activo == 1)){
								creado = 0;
								for(j = 0; j < ART; j++){
									if((componente[i].articulo[j].activo1 != 1) && (creado == 0)){
										fclose(componente1);
										componente[i].articulo[j] = crear_articulo(identificador2,fecha,modelo,marca,tipo_art,precio_art,precio_transport,precio_art1,precio_transport1,conversion,activo1,stock_art,ident_id_numerico);
									
										if(componente[i].articulo[j].activo1 == 1){
											creado = 1;
											printf("El articulo ha sido dado de alta con exito!!\n");
											printf("El identificador asignado al articulo es %s%s",componente[i].articulo[j].ident_id_numerico,componente[i].articulo[j].fecha);
										}
									}
								}
							}
						}
					}		
					else{
						printf("No coinciden los ficheros.\n");
						seguir = 'n';
					}
				break;  
			case 5:
				componente1 = fopen ("binario.bin","wb");
				fwrite(componente,sizeof(struct componentes),NUM,componente1);
				fclose(componente1);
				componente1 = fopen("binario2.bin","wb");
				fwrite(componente,sizeof(contador),1,componente1);
				fclose(componente1);
				break;
			case 6: 
				componente1 = fopen("binario.bin","rb");	
				fread(componente,sizeof(struct componentes),NUM,componente1);
				fclose(componente1);
				componente1 = fopen("binario2.bin","rb");
				fread(componente,sizeof(contador),1,componente1);
				fclose(componente1);
				break;
				
			case 7:
					printf("/****** STOCK TIENDA DE COMPONENTES INFORMATICOS ******/\n");
					for(i = 0; i < NUM; i++){
						if(componente[i].activo == 1){
							printf("---------------------------------------------------\n");
							printf("Componente %s",componente[i].identificador1);
							printf("---------------------------------------------------\n");
							printf("Nombre: %s",componente[i].nombre);
							for(j = 0; j < ART; j++){
								if(componente[i].articulo[j].activo1 == 1){
									printf("Marca: %s\n",componente[i].articulo[j].marca);	
									printf("Stock General: %d\n",componente[i].stock_comp);
									printf("\n\n\n\t- Articulo: \t %s%s\n",componente[i].articulo[j].ident_id_numerico,componente[i].articulo[j].fecha);
									printf("\t- Modelo: \t %s\n", componente[i].articulo[j].modelo);
									printf("\t- Marca: \t %s \n", componente[i].articulo[j].marca);
									printf("\t- Stock: \t %d\n", componente[i].articulo[j].stock_art);
									printf("\t- Precio: \t %.02f\n", componente[i].articulo[j].precio_art);
									printf("\t- Transporte: \t %.02f\n",componente[i].articulo[j].precio_transport);
									printf("\t- Tipo: \t %s",componente[i].articulo[j].tipo_art);
								}
							}
						}
				
					}
					printf("\n\n");

				break;
			}
		}
	while(opcion != 8);
return 0;
}
