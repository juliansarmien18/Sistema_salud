#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
struct hospitales{
	int id_hospital;
	char nombre[50];
	char gerente[50];
	char localidad[50];
	int calle;
	int carrera;
	int trabajadores;
	int pacientes; 
	
};
bool validar_h(int id){
	FILE *f;
	f = fopen("hospitales.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{	
		hospitales hos;
		bool encontrado = false;
		fread(&hos,sizeof(hospitales),1,f);
		while(!feof(f)){
			if(id==hos.id_hospital){
				encontrado = true;
				return encontrado;
			}
			fread(&hos,sizeof(hospitales),1,f);
		}
		if (encontrado==false){
			return encontrado;
		}
		fclose(f);
	}
}

void agregar_H(){
	int id;
	FILE *f;
	f = fopen("hospitales.txt","ab");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{	
		hospitales hos;
		printf("Id Hospital:");
		scanf("%i",&id);
		fflush(stdin);
		if(!validar_h(id)){
			hos.id_hospital=id;
			printf("Nombre hospital:");
			gets(hos.nombre);
			printf("Gerente:");
			gets(hos.gerente);
			printf("Localidad:");
			gets(hos.localidad);
			printf("Calle:");
			scanf("%i",&hos.calle);
			fflush(stdin);
			printf("Carrera:");
			scanf("%i",&hos.carrera);
			fflush(stdin);
			printf("Nº trabajadores:");
			scanf("%i",&hos.trabajadores);
			fflush(stdin);
			printf("Nº paciente:");
			scanf("%i",&hos.pacientes);
			fflush(stdin);
			fwrite(&hos,sizeof(hospitales),1,f);
			
		}
		else{
			cout<<"Esta id ya esta registrada"<<endl;
		}
		fclose(f);
	}
}

void ver_H(){
	FILE *f;
	f = fopen("hospitales.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{	
		hospitales hos;
		int a=0; 
		lista <hospitales> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&hos,sizeof(hos),1,f);
		while(!feof(f)){
			x.insertar_pos(hos, a);
			fread(&hos,sizeof(hospitales),1,f);
			a++;
		}
		x.imprimir_hospitales();
		fclose(f);
	}
}

void consultar_H(){
	FILE *f;
	f = fopen("hospitales.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Id para consulta:");
		int id,a=0;;
		scanf("%i",&id);
		fflush(stdin);
		hospitales hos;
		lista <hospitales> x;
		bool encontrado = false;
		fread(&hos,sizeof(hospitales),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			if(id==hos.id_hospital){
				x.insertar_pos(hos, a);
				encontrado = true;
				a++;
			}
			fread(&hos,sizeof(hospitales),1,f);
		}
		if (encontrado==false){
			printf("No existe el hospital con ese id");
			
		}else x.imprimir_hospitales();
		fclose(f);
	}
}
void consultar_Area(){
	int cll1, cll2, crr1, crr2;
	bool aux= false;
	FILE *f;
	f = fopen("hospitales.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Calle menor:");
		cin>>cll1;
		fflush(stdin);
		printf("Calle mayor:");
		cin>>cll2;
		fflush(stdin);
		printf("Carrera menor:");
		cin>>crr1;
		fflush(stdin);
		printf("Carrera mayor:");
		cin>>crr2;
		fflush(stdin);
		if(cll1 <= cll2 && crr1<=crr2) aux = true;
		hospitales hos;
		bool encontrado = false;
		int a=0;
		lista <hospitales> x;
		fread(&hos,sizeof(hospitales),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			if(cll1<=hos.calle && cll2>=hos.calle && crr1<=hos.carrera && crr2>=hos.carrera){
				x.insertar_pos(hos, a);
				encontrado = true;
				a++;
			}
			fread(&hos,sizeof(hospitales),1,f);
		}
		if (encontrado==false){
			printf("No existe el hospital en dicha zona");
		}else x.imprimir_hospitales();
		fclose(f);
	}
}

void consLo(){
	FILE *f;
	f = fopen("hospitales.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Localidad:");
		string loc,c;
		cin>>loc;
		fflush(stdin);
		hospitales hos;
		int a=0;
		lista <hospitales> x;
		bool encontrado = false;
		fread(&hos,sizeof(hospitales),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			c+= hos.localidad;
			if(loc == c){
				x.insertar_pos(hos, a);
				encontrado = true;
				a++;
			}
			c.clear();
			fread(&hos,sizeof(hospitales),1,f);
		}
		if (encontrado==false){
			printf("No existe el hospital con ese id \n");
		}else x.imprimir_hospitales();
		fclose(f);
	}
}

void modificar_H(){
	int a;
	FILE *f;
	f = fopen("hospitales.txt","r+b");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("ID hospital a modificar: ");
		int id,b=0;
		scanf("%i",&id);
		fflush(stdin);
		hospitales hos;
		bool encontrado = false;
		fread(&hos,sizeof(hospitales),1,f);
		while(!feof(f)){
			if(id==hos.id_hospital){
				printf(" ID: %i\n Nombre: %s\n Gerente: %s\n Localidad: %s\n Calle: %i\n Carrera %i\n Trabajadores: %i\n Pacientes %i\n",hos.id_hospital,hos.nombre,hos.gerente,hos.localidad,hos.calle,hos.carrera,hos.trabajadores,hos.pacientes);				cout<<"Ingrese 1 para modificar el hospital"<<endl; 
				cout<<"Ingrese 1 para modificar el nombre"<<endl; 
				cout<<"Ingrese 2 para modificar el gerente"<<endl; 
				cout<<"Ingrese 3 para modificar el localidad"<<endl; 
				cout<<"Ingrese 4 para modificar la calle"<<endl; 
				cout<<"Ingrese 5 para modificar la carerra"<<endl;
				cout<<"Ingrese 6 para modificar el n_trabajadores"<<endl;  
				cout<<"Ingrese 7 para modificar el n_pacientes"<<endl; 
				cin>>a;
				fflush(stdin);
				switch (a){
					case 1:	{
							printf("Ingrese nuevo nombre:");
							gets(hos.nombre);
							int pos = ftell(f)-sizeof(hospitales);
							fseek(f,pos,SEEK_SET);
							fwrite(&hos,sizeof(hospitales),1,f);
							printf("Nombre modificado con exito");
							encontrado = true;
							break;
						} 
							 
					case 2: {
							printf("Ingrese nuevo gerente:");
							gets(hos.gerente);
							
							int pos = ftell(f)-sizeof(hospitales);
							fseek(f,pos,SEEK_SET);
							fwrite(&hos,sizeof(hospitales),1,f);
							printf("Gerente modificado con exito");
							encontrado = true;
							break;
					}
					case 3: {
							printf("Ingrese nueva localidad:");
							gets(hos.localidad);
							int pos = ftell(f)-sizeof(hospitales);
							fseek(f,pos,SEEK_SET);
							fwrite(&hos,sizeof(hospitales),1,f);
							printf("Localidad modificado con exito");
							encontrado = true;
							break;
						
					} 
					case 4: {
							printf("Ingrese nueva calle:");
							scanf("%i",&hos.calle);
							fflush(stdin);
							int pos = ftell(f)-sizeof(hospitales);
							fseek(f,pos,SEEK_SET);
							fwrite(&hos,sizeof(hospitales),1,f);
							printf("Calle modificada con exito");
							encontrado = true;
							break;
					}
					case 5: {
							printf("Ingrese nueva carrera:");
							scanf("%i",&hos.carrera);
							fflush(stdin);
							int pos = ftell(f)-sizeof(hospitales);
							fseek(f,pos,SEEK_SET);
							fwrite(&hos,sizeof(hospitales),1,f);
							printf("Carrera modificada con exito");
							encontrado = true;
							break;
					}	
				    case 6: {
							printf("Ingrese nuevo n_trabajadores:");
							scanf("%i",&hos.trabajadores);
							fflush(stdin);
							int pos = ftell(f)-sizeof(hospitales);
							fseek(f,pos,SEEK_SET);
							fwrite(&hos,sizeof(hospitales),1,f);
							printf("N_trabajadores modificado con exito");
							encontrado = true;
							break;
					}	
					case 7: {
							printf("Ingrese nuevo n_pacientes:");
							scanf("%i",&hos.pacientes);
							fflush(stdin);
							int pos = ftell(f)-sizeof(hospitales);
							fseek(f,pos,SEEK_SET);
							fwrite(&hos,sizeof(hospitales),1,f);
							printf("N_pacientes modificado con exito");
							encontrado = true;
							break;
					} 
					default: {
							printf("No aplica");
							break;
					}   
				}
				cout<<endl;
				break;
			}
			fread(&hos,sizeof(hospitales),1,f);
			b++;
			cout<<"Nya"<<b<<"nya"<<endl;
		}
		if (encontrado==false){
			printf("No se ha encontrado un paciente con ese ID");
		}
		fclose(f);
	}
}
