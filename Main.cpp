#include<iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include "Lib_lista.h"
#include "Controlador_paciente.h"
#include "Controlador_hospitales.h"
#include "Controlador_trabajadores.h"
#include "Controlador_citas.h"


/*
Integrantes:
	
	- Julian Alejandro Sarmiento Linares 	- 20181020042
	- Juan Camilo Ramírez Rátiva 			- 20181020089
	- David Fernando Ravelo Garavito 		- 20191020061 

*/
using namespace std;
int main(){	

	int a,b,aux=0,aux0=0;
	cout<<"                                   Bienvenido al sistema de consulta de hospitales"<<endl;
	while(aux == 0){
		cout<<"ingrese 0 para salir"<<endl;
		cout<<"Ingrese 1 para el menu de pacientes"<<endl;
		cout<<"Ingrese 2 para el menu de hospitales"<<endl;
		cout<<"Ingrese 3 para el menu de trabajadores"<<endl;
		cout<<"Ingrese 4 para el menu de citas"<<endl;
		cout<<"Ingrese la opcion deseada"<<endl;
		cin>>a;
		system("cls");
		switch(a){
			case 0:{
				aux = 1;
				break;
			}
			case 1: {
				aux0=0;
				while(aux0 == 0){
					cout<<"Ingrese 0 para regresar"<<endl;
					cout<<"Ingrese 1 para segun localidad y rango de edad, encontrar pacientes"<<endl;
					cout<<"Ingrese 2 para ver toda la lista de pacientes"<<endl;
					cout<<"Ingrese 3 para modificar la informacion de un paciente"<<endl;
					cout<<"Ingrese 4 para agregar un paciente"<<endl;
					cout<<"Ingrese 5 para consultar la informacion de un paciente"<<endl; 
					cout<<"Ingrese 6 para segun localidad, personas enfermedades preexistentes"<<endl;
					cout<<"Ingrese 7 para segun rango de edad, informacion del paciente"<<endl;
					cout<<"Ingrese 8 para buscar pacientes en casa"<<endl;
					cout<<"Ingrese 9 para consultar paciente por hospital"<<endl;
					cout<<"Ingrese 10 para buscar pacientes por enfermedad y localidad"<<endl;
					cout<<"Ingrese 11 para ver la lista de pacientes en UCI segun localidad"<<endl;
					cout<<"Ingrese 12 para ver la lista de pacientes en piso segun localidad"<<endl;
					cout<<"Ingrese 13 para ver la lista de pacientes en casa segun localidad"<<endl;
					cout<<"Ingrese 14 para ver la lista de pacientes segun localidad"<<endl;
					cout<<"Ingrese la opcion deseada"<<endl;
					cin>>b;
					system("cls");
					switch(b){
						case 0: aux0 = 1;
							break;
						case 1: consultar_lorang();
							break;
						case 2: ver_P();
							break;
						case 3: modificar_P();
							break;
						case 4: agregar_P();
							break;
						case 5: consultar_P();
							break;	
						case 6: cons_Lo();	
							break;
						case 7: consultar_rang();
							break;		
						case 8: consultarPC_P();
							break;
						case 9: consultarPXH_P();
							break;
						case 10: consultarPXEXD_P();
							break;
						case 11: cons_uci();
							break;
						case 12: cons_pis();
							break;
						case 13: consultarPCXL_P();
							break;
						case 14: cons_Lopa();
							break;
					}		
				}
				break;
			}
			case 2: {
				aux0=0;
				while(aux0 == 0){
					cout<<"ingrese 0 para regresar"<<endl;
					cout<<"Ingrese 1 para ver toda la lista de Hospitales"<<endl;
					cout<<"Ingrese 2 para modificar la informacion de un Hospital"<<endl;
					cout<<"Ingrese 3 para agregar un Hospitales"<<endl;
					cout<<"Ingrese 4 para consultar la informacion de un Hospital"<<endl; 
					cout<<"Ingrese 5 para consultar Hospitales en zona determinada"<<endl;
					cout<<"Ingrese 6 segun localidad mostrar Hospitales"<<endl;
					cout<<"Ingrese la opcion deseada"<<endl;
					cin>>b;
					system("cls");
					switch(b){
						case 0: aux0 = 1;
							break;
						case 1: ver_H();
							break;
						case 2: modificar_H();
							break;
						case 3: agregar_H();
							break;
						case 4: consultar_H();
							break;	
						case 5: consultar_Area();
							break;
						case 6: consLo();
							break;
					}
				}
				break;	
			}
			case 3: {
				aux0=0;
				while(aux0 == 0){
					cout<<"Ingrese 0 para regresar"<<endl;
					cout<<"Ingrese 1 para ver toda la lista de Trabajadores"<<endl;
					cout<<"Ingrese 2 para modificar la informacion de un Trabajador"<<endl;
					cout<<"Ingrese 3 para agregar un Trabajadores"<<endl;
					cout<<"Ingrese 4 para consultar la informacion de un Trabajador"<<endl;
					cout<<"Ingrese 5 para segun horario y localidad, personal disponible"<<endl;
					cout<<"Ingrese 6 para segun horario y paciente, lista de personal que puede hacerse cargo"<<endl;
					cout<<"Ingrese 7 para consultar trabajador por hospital"<<endl;
					cout<<"Ingrese la opcion deseada"<<endl;
					cin>>b;
					system("cls");
					switch(b){
						case 0: aux0 = 1;
							break;
						case 1: ver_t();
							break;
						case 2: modificar_t();
							break;
						case 3: agregar_t();
							break;
						case 4: consultar_t();
							break;
						case 5: consultar_HoLo();
							break;	
						case 6: consultar_HoPa();
							break;
						case 7: consultarTXH_t();
							break;
							
					}	
				}
				break;	
			}
			case 4:{
				aux0=0;
				while(aux0 == 0){
					cout<<"Ingrese 0 para regresar"<<endl;
					cout<<"Ingrese 1 para ver la lista de citas"<<endl;
					cout<<"Ingrese 2 para consultar 1 cita"<<endl;
					cout<<"Ingrese 3 para segun ID de trabajador, ver citas"<<endl;
					cout<<"Ingrese 4 para segun ID de paciente, ver personal y citas"<<endl;
					cout<<"Ingrese 5 para agregar una cita"<<endl;
					cout<<"Ingrese la opcion deseada"<<endl;
					cin>>b;
					system("cls");
					switch(b){
						case 0: aux0 = 1;
							break;
						case 1: ver_c();
							break;
						case 2: consultar_c();
							break;
						case 3: cons_listaPSP();
							break;
						case 4: cons_listaPSS();
							break;		
						case 5: agregar_c();			
					}		
				}
				break;
			}
		}
	}	
}
