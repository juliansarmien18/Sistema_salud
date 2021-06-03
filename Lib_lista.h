#ifndef Liblsita_H
#define Lib_lista_H
#include <iostream>

using namespace std;
/*

Integrantes:

	- Julian Alejandro Sarmiento Linares 	- 20181020042
	- Juan Camilo Ramírez Rátiva 			- 20181020089
	- David Fernando Ravelo Garavito 		- 20191020061 

*/

template <class T>
struct nodo {T info;
             nodo<T> * sig;};
template <class T>
class lista{
			nodo <T> *cab;
			int tam;	
	public: lista(){
				cab=NULL; 
				tam=0;
			}
			void imprimir_pacientes();
			void imprimir_trabajadores();
			void imprimir_hospitales();
			void imprimir_citas();
			
			bool lista_vacia();
			int tamano_lista();	
			void insertar_pos(T info, int pos);
			void insertar_final(T inf);
			void insertar_inicio(T inf);
			
			bool eliminar(int pos);
			void obtenerDato_paciente (int pos);
			void obtenerDato_trabajador (int pos);
			void obtenerDato_hospital (int pos);
			void obtenerDato_cita (int pos);			
};
template <class T>
bool lista<T>::lista_vacia(){
	if(cab==NULL)
    	return true;
 	else
 		return false;
}

template <class T>
void lista <T>::insertar_pos(T inf, int pos){
	int x;
 	if (pos>tam)
		insertar_final(inf);
 	else 
	 if (pos == 0)
 			insertar_inicio(inf);
 		else{
		 	nodo <T> *nuevo, *Aux;
 	     	nuevo = new nodo <T>;
 	     	nuevo->info = inf;
 	     	Aux=cab;
 	    	 x=1;
 	    	while(x<pos-1 && Aux!= NULL){
		 		Aux=Aux->sig;
 	      		x++;
		  }
		nuevo->sig = Aux->sig;
		Aux->sig= nuevo;
		tam++; 
	 }	
}
template <class T>
int lista <T>::tamano_lista(){
	return tam;
}

template <class T>
void lista<T>::insertar_final(T infN){ 
	nodo <T> *n;
 	n = new nodo <T>;
  	n->info= infN;
  	n->sig = NULL;
  	if(tam == 0){
	  cab = n;}
  	else{
	  nodo <T> *aux;
      aux = cab;
    while(aux->sig != NULL){
	 	aux = aux->sig;}
     	aux->sig = n;
     	aux->info=n->info;
    }
  	tam++;
}

template <class T>
void lista<T>::insertar_inicio(T infN){ 
	nodo <T> *n;
  	n = new nodo <T>;
 	n->info= infN;
  	n->sig = cab;
  	cab = n;
 	tam++;
}

template <class T>
void lista<T>::obtenerDato_paciente(int id){
	nodo <T> *aux;
	aux = cab;
	int x = 1;
	while(x<id && aux != NULL){
		aux = aux->sig;
		x++;
	}
	if(aux!=NULL){
		cout<<"ID Hospital: "<<aux->info.n_hospital<<endl;
		cout<<"ID Paciente: "<<aux->info.id_paciente<<endl;
        cout<<"Nombre: "<<aux->info.nombre<<endl;
        cout<<"Apellido: "<<aux->info.apellido<<endl;
        cout<<"Sexo: "<<aux->info.sexo<<endl;
        cout<<"Fecha Nac.: "<<aux->info.f_nacimiento<<endl;
        cout<<"Enf. Prexist.: "<<aux->info.n_epexist<<endl;
        cout<<"Localidad: "<<aux->info.localidad<<endl;
        cout<<"Estado: "<<aux->info.estado<<endl;
        cout<<"Gravedad: "<<aux->info.gravedad<<endl;
        cout<<endl;
    } else {
        cout<<"El dato no existe..."<<endl;
    }
}

template <class T>
void lista<T>::obtenerDato_trabajador(int id){
	nodo <T> *aux;
	aux = cab;
	int x = 1;
	while(x<id && aux != NULL){
		aux = aux->sig;
		x++;
	}
	if(aux!=NULL){
		cout<<"ID Hospital: "<<aux->info.n_hospital<<endl;
		cout<<"ID Medico: "<<aux->info.id_trabajor<<endl;
		cout<<"ID Horario: "<<aux->info.horario<<endl;
		cout<<"Seccion: "<<aux->info.seccion<<endl;
		cout<<"Nombre: "<<aux->info.nombre<<endl;
		cout<<"Apellido: "<<aux->info.apellido<<endl;
		cout<<"T.I.: "<<aux->info.n_ti<<endl;
		cout<<"Sexo: "<<aux->info.sexo<<endl;
		cout<<"Telefono: "<<aux->info.telefono<<endl;
		cout<<"Fijo: "<<aux->info.telefono_f<<endl;
		cout<<"Mail: "<<aux->info.mail<<endl;
		cout<<"Fecha Nac.: "<<aux->info.f_nacimiento<<endl;
		cout<<"Ciudad Nac.: "<<aux->info.ciudadania<<endl;
		cout<<"Pais Nac.: "<<aux->info.pais<<endl;
		cout<<"Dirección: "<<aux->info.direccion<<endl;
		cout<<"Barrio: "<<aux->info.barrio<<endl;
        cout<<endl;
    } else {
        cout<<"El dato no existe..."<<endl;
    }
}

template <class T>
void lista<T>::obtenerDato_hospital(int id){
	nodo <T> *aux;
	aux = cab;
	int x = 1;
	while(x<id && aux != NULL){
		aux = aux->sig;
		x++;
	}
	if(aux!=NULL){
		cout<<"ID Hospital: "<<aux->info.id_hospital<<endl;
		cout<<"Nombre: "<<aux->info.nombre<<endl;
		cout<<"Gerente: "<<aux->info.gerente<<endl;
		cout<<"Localidad: "<<aux->info.localidad<<endl;
		cout<<"Area Calle: "<<aux->info.calle<<endl;
		cout<<"Area Carrera: "<<aux->info.carrera<<endl;
		cout<<"Numero medicos: "<<aux->info.trabajadores<<endl;
		cout<<"Numero pacientes: "<<aux->info.pacientes<<endl;
        cout<<endl;
    } else {
        cout<<"El dato no existe..."<<endl;
    }
}

template <class T>
void lista<T>::obtenerDato_cita(int id){
	nodo <T> *aux;
	aux = cab;
	int x = 1;
	while(x<id && aux != NULL){
		aux = aux->sig;
		x++;
	}
	if(aux!=NULL){
		cout<<"Turno: "<<aux->info.turno<<endl;
		cout<<"ID Hospital: "<<aux->info.k_hospital<<endl;
		cout<<"ID Medico: "<<aux->info.k_ps<<endl;
		cout<<"ID Paciente: "<<aux->info.k_paciente<<endl;
		cout<<"Fecha cita "<<aux->info.fh_cita<<endl;
		cout<<endl;
    } else {
        cout<<"El dato no existe..."<<endl;
    }
}

template <class T>
bool lista<T>::eliminar(int pos){ 
	if(tam >= pos){ 
		nodo <T> *temp;
       	temp = cab;
       if(pos == 1){
	   		cab = temp->sig;
          	delete temp;
        }
       else{
	   		for(int i=1;i<pos-1;i++){
			   temp = temp->sig;
			   }          
         	nodo <T> *aux;
          	aux = temp->sig;
          	temp->sig = aux->sig;
          	delete aux;
         }
        tam--;
        return true;          
     }
 	else
     	return false;
}	

template <class T>
void lista<T>:: imprimir_pacientes (){
	if(lista_vacia()){
		cout<<" la lista no tiene informacion"<<endl;
	}
	else{
		cout<<"La informacion de la lista es : "<<endl;
		nodo<T> *aux;
		aux = cab;
		int pos = 0;
		while (aux!= NULL && pos < tam){
			cout<<"Paciente #: "<<pos+1<<": "<<endl;
			cout<<"ID Hospital: "<<aux->info.n_hospital<<endl;
			cout<<"ID Paciente: "<<aux->info.id_paciente<<endl;
            cout<<"Nombre: "<<aux->info.nombre<<endl;
            cout<<"Apellido: "<<aux->info.apellido<<endl;
            cout<<"Sexo: "<<aux->info.sexo<<endl;
            cout<<"Fecha Nac.: "<<aux->info.f_nacimiento<<endl;
            cout<<"Enf. Prexist.: "<<aux->info.n_epexist<<endl;
            cout<<"Localidad: "<<aux->info.localidad<<endl;
            cout<<"Estado: "<<aux->info.estado<<endl;
            cout<<"Gravedad: "<<aux->info.gravedad<<endl;
            cout<<endl;
            aux = aux->sig;
            pos++;
		} 
	}
}

template <class T>
void lista<T>:: imprimir_trabajadores (){
	if(lista_vacia()){
		cout<<" la lista no tiene informacion"<<endl;
	}
	else{
		cout<<"La informacion de la lista es : "<<endl;
		nodo<T> *aux;
		aux = cab;
		int pos = 0;
		while (aux!= NULL && pos < tam){
			cout<<"Medico #: "<<pos+1<<": "<<endl;
			cout<<"ID Hospital: "<<aux->info.n_hospital<<endl;
			cout<<"ID Medico: "<<aux->info.id_trabajor<<endl;
			cout<<"ID Horario: "<<aux->info.horario<<endl;
			cout<<"Seccion: "<<aux->info.seccion<<endl;
			cout<<"Nombre: "<<aux->info.nombre<<endl;
			cout<<"Apellido: "<<aux->info.apellido<<endl;
			cout<<"T.I.: "<<aux->info.n_ti<<endl;
			cout<<"Sexo: "<<aux->info.sexo<<endl;
			cout<<"Telefono: "<<aux->info.telefono<<endl;
			cout<<"Fijo: "<<aux->info.telefono_f<<endl;
			cout<<"Mail: "<<aux->info.mail<<endl;
			cout<<"Fecha Nac.: "<<aux->info.f_nacimiento<<endl;
			cout<<"Ciudad Nac.: "<<aux->info.ciudadania<<endl;
			cout<<"Pais Nac.: "<<aux->info.pais<<endl;
			cout<<"Dirección: "<<aux->info.direccion<<endl;
			cout<<"Barrio: "<<aux->info.barrio<<endl;
            cout<<endl;
            aux = aux->sig;
            pos++;
		} 
	}
}

template <class T>
void lista<T>:: imprimir_hospitales (){
	if(lista_vacia()){
		cout<<" la lista no tiene informacion"<<endl;
	}
	else{
		cout<<"La informacion de la lista es : "<<endl;
		nodo<T> *aux;
		aux = cab;
		int pos = 0;
		while (aux!= NULL && pos < tam){
			cout<<"Medico #: "<<pos+1<<": "<<endl;
			cout<<"ID Hospital: "<<aux->info.id_hospital<<endl;
			cout<<"Nombre: "<<aux->info.nombre<<endl;
			cout<<"Gerente: "<<aux->info.gerente<<endl;
			cout<<"Localidad: "<<aux->info.localidad<<endl;
			cout<<"Area Calle: "<<aux->info.calle<<endl;
			cout<<"Area Carrera: "<<aux->info.carrera<<endl;
			cout<<"Numero medicos: "<<aux->info.trabajadores<<endl;
			cout<<"Numero pacientes: "<<aux->info.pacientes<<endl;
            cout<<endl;
            aux = aux->sig;
            pos++;
		} 
	}
}

template <class T>
void lista<T>:: imprimir_citas (){
	if(lista_vacia()){
		cout<<" la lista no tiene informacion"<<endl;
	}
	else{
		cout<<"La informacion de la lista es : "<<endl;
		nodo<T> *aux;
		aux = cab;
		int pos = 0;
		while (aux!= NULL && pos < tam){
			cout<<"Turno: "<<aux->info.turno<<endl;
			cout<<"ID Hospital: "<<aux->info.k_hospital<<endl;
			cout<<"ID Medico: "<<aux->info.k_ps<<endl;
			cout<<"ID Paciente: "<<aux->info.k_paciente<<endl;
			cout<<"Fecha cita "<<aux->info.fh_cita<<endl;
			cout<<endl;
            aux = aux->sig;
            pos++;
		} 
	}
}

#endif
