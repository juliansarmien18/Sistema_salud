#ifndef LORDEN_H
#define LORDEN_H

using namespace std;
/*

Integrantes:

	- Julian Alejandro Sarmiento Linares 	- 20181020042
	- Juan Camilo Ramírez Rátiva 			- 20181020089
	- David Fernando Ravelo Garavito 		- 20191020061 

*/

template <class T>
struct nodo {
	T info;
    nodo<T> *sig;
	int id;	
};

template <class T>
class lista{
	nodo <T> *cab;
	int tam;
	
	public: lista(){
		cab=NULL; 
		tam=0;
	}
	
	int tamano_lista();		
	T obtenerdatoPos(int pos);
	
	
	//L-ORDENADAS
	bool eliminar(int pos);
	void insertar();
	bool lista_vacia();
	void imprimir();
	void insertarNodo(int id, T x);
	void obtenerdatoNodo(int id);
	bool eliminarNodo(int id);
			
};

template <class T>
int lista<T>::tamano_lista(){
	return tam;
}

template <class T>
T lista<T>::obtenerdatoPos(int pos){
	nodo <T> *aux;
	aux = cab;
	int x = 1;
	while(x<pos && aux != NULL){
		aux = aux->sig;
		x++;
		
	}
	return aux->info;
}

// LISTAS ORDENADAS

template <class T>
bool lista<T>::lista_vacia(){
	if(cab==NULL || tam==0)
    	return true;
 	else
 		return false;
}

template <class T>
bool lista<T>::eliminar(int id){ 
	nodo <T> *aux, *temp;
    aux = cab;
    temp = cab;
    while (aux->id != id){
        temp = aux;
        aux = temp->sig;
    }
    if (aux->id == id){
        temp -> sig = aux->sig;
        return true;
    } else {
        return false;
    }
}


template <class T>
void lista<T>:: imprimir (){
	if(lista_vacia()){
		cout<<" la lista no tiene informacion"<<endl;
	}
	else{
		cout<<"La informacion de la lista es : "<<endl;
		nodo<T> *aux;
		aux = cab;
		int pos = 0;
		while (aux!= NULL && pos < tam){
			cout<<"Estudiante #"<<pos+1<<": "<<endl;
			cout<<"Codigo: "<<aux->id<<endl;
			cout<<"Nombre: "<<aux->info.nombre<<endl;
            cout<<"Direccion: "<<aux->info.direccion<<endl;
            cout<<"Edad: "<<aux->info.edad<<endl;
            aux = aux->sig;
            pos++;
		} 
	}
}

template <class T>
void lista<T>::insertarNodo(int id, T x){
	nodo<T> *data, *aux, *aux1;
	
	data = new nodo<T>;
		
	data->id = id;
	data->info = x;
	
	if(cab==NULL){
		data->sig = NULL;
		cab = data;
	}else{
		if(data->id < cab->id){
			data->sig = cab;
            cab = data;
		}else{
			aux = cab;
			aux1 = cab;
			while((aux1->sig!=NULL) && (aux1->id <= data->id)){
				aux = aux1;
				aux1 = aux->sig;
			}
			if(aux1->id <= data->id){
				aux1->sig = data;
			}else{
				data->sig = aux1;
				aux->sig = data;
			}
		}
	}
	tam++;
}


template <class T>
void lista<T>::obtenerdatoNodo(int id){
	nodo <T> *aux;
	aux = cab;
	int x = 0;
	while(aux->id!=id && aux != NULL){
		aux = aux->sig;
		x++;
	}
	if(aux!=NULL){
        cout<<"Estudiante #"<<x+1<<": "<<endl;
        cout<<"Clave: "<<aux->id<<endl;
        cout<<"Nombre: "<<aux->info.nombre<<endl;
        cout<<"Direccion: "<<aux->info.direccion<<endl;
        cout<<"Edad: "<<aux->info.edad<<endl;
    } else {
        cout<<"El dato no existe..."<<endl;
    }
}

template <class T>
bool lista<T>::eliminarNodo(int id){ 
	nodo <T> *aux;
	aux = cab;
	int x = 1;
	
	while(x<tam && aux != NULL){
		aux = aux->sig;
		if(aux->id == id){
			delete aux;
			tam--;
			return true;
		}
		x++;
	} 
	
	return false;
}

#endif
