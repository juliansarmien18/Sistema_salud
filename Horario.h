
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
struct Horario{
	int n_horario;
	char hora[50];
};
void ver_HO(){
	FILE *f;
	f = fopen("horario.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		int a; 
		Horario ho;
		fread(&ho,sizeof(Horario),1,f);
		while(!feof(f)){
			cout<<"Horario n_"<<a<<endl;
			printf("N_horario: %i\n Hora: %s\n",ho.n_horario,ho.hora);
			cout<<endl;
			fread(&ho,sizeof(Horario),1,f);
			a++;
		}
		fclose(f);
	}
}

void consultar_HO(){
	FILE *f;
	f = fopen("Horario.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Id para consulta:");
		int id;
		scanf("%i",&id);
		fflush(stdin);
		Horario ho;
		bool encontrado = false;
		fread(&ho,sizeof(Horario),1,f);
		while(!feof(f)){
			if(id==ho.n_horario){
				printf("N_horario: %i\n Hora: %s\n",ho.n_horario,ho.hora);				
				encontrado = true;
				break;
			}
			fread(&ho,sizeof(Horario),1,f);
		}
		if (encontrado==false){
			printf("No existe el horario con ese id");
		}
		fclose(f);
	}
}


