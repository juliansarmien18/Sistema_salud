using namespace std;
struct trabajador{
	int n_hospital;
	int id_trabajor;
	int horario;
	char seccion[50];
	char nombre[50];
	char apellido[50];
	char n_ti[50];
	char sexo;
	char telefono[50]; 
	char telefono_f[50];
	char mail[50];
	char f_nacimiento[50];
	char ciudadania[50];
	char pais[50];
	char direccion[50];
	char barrio[50];
};
bool validar_t(int id){
	FILE *f;
	f = fopen("trabajadores.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{	
		trabajador tra;
		bool encontrado = false;
		fread(&tra,sizeof(trabajador),1,f);
		while(!feof(f)){
			if(id==tra.id_trabajor){
				encontrado = true;
				return encontrado;
			}
			fread(&tra,sizeof(trabajador),1,f);
		}
		if (encontrado==false){
			return encontrado;
		}
		fclose(f);
	}
}
void agregar_t(){
	int id;
	FILE *f;
	f = fopen("trabajadores.txt","ab");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		trabajador tra;
		printf("Id trabajador:");
		scanf("%i",&id);
		fflush(stdin);
		if(!validar_t){
			tra.id_trabajor=id;
			printf("N_hospital:");
			scanf("%i",&tra.n_hospital);
			fflush(stdin);
			printf("Horario:");
			scanf("%i",&tra.horario);
			fflush(stdin);
			printf("Seccion:");
			gets(tra.nombre);
			printf("Nombre trabajador:");
			gets(tra.nombre);
			printf("Apellido trabajador:");
			gets(tra.apellido);
			printf("Tipo identificacion:");
			gets(tra.n_ti);
			printf("Sexo:");
			scanf("%c",&tra.sexo);
			fflush(stdin);
			printf("Telefono:");
			gets(tra.telefono);
			printf("Telefono fijo:");
			gets(tra.telefono_f);
			printf("Mail:");
			gets(tra.mail);
			printf("Fecha nacimiento:");
			gets(tra.f_nacimiento);
			printf("Ciudad:");
			gets(tra.ciudadania);
			printf("Pais:");
			gets(tra.pais);
			printf("Direccion:");
			gets(tra.direccion);
			printf("Barrio:");
			gets(tra.barrio);
			fwrite(&tra,sizeof(trabajador),1,f);			
		}
		else{
			cout<<"Esta id ya esta registrada"<<endl;
		}
		fclose(f);
		
	}
}

void ver_t(){
	FILE *f;
	f = fopen("trabajadores.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		int a=0; 
		trabajador tra;
		lista <trabajador> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&tra,sizeof(trabajador),1,f);
		while(!feof(f)){
			x.insertar_pos(tra, a);
			fread(&tra,sizeof(trabajador),1,f);
			a++;
		}
		x.imprimir_trabajadores();
		fclose(f);
	}
}
void consultar_HoLo(){
	FILE *f,*d;
	f = fopen("trabajadores.txt","rb");
	d = fopen("Hospitales.txt","rb");
	if (f==NULL || d==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		int hor,auxh, a=0;
		string loc, c;
		cout<<"1. 6am-2pm"<<endl<<"2. 2pm-10pm"<<endl<<"3. 10pm-6am"<<endl;
		cout<<" Ingrese Horario: "<<endl;
		cin>>hor;
		fflush(stdin);
		cout<<"ingrese localidad"<<endl;
		cin>>loc;
		fflush(stdin);
		trabajador tra;
		hospitales hos;
		bool encontrado = false;
		lista <trabajador> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&hos,sizeof(hospitales),1,d);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(d)){
			c+= hos.localidad;
			if(loc==c){		
				auxh= hos.id_hospital;
			}
			c.clear();
			fread(&hos,sizeof(hospitales),1,d);
		}
		fread(&tra,sizeof(trabajador),1,f);
		while(!feof(f)){
			if(auxh==tra.n_hospital && hor==tra.horario){
				x.insertar_pos(tra, a);
				encontrado = true;
			}
			fread(&tra,sizeof(trabajador),1,f);
		}
		if (encontrado==false){
			printf("No existe personal en ese hospital en ese horario \n");
		}else x.imprimir_trabajadores();
		fclose(f);
	}
}
void consultar_HoPa(){
	FILE *f,*d;
	f = fopen("trabajadores.txt","rb");
	d = fopen("Pacientes.txt","rb");
	if (f==NULL || d==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		string c,m,auxs,auxe;
		int hor,auxh,pa,s, a=0;
		cout<<"1. 6am-2pm"<<endl<<"2. 2pm-10pm"<<endl<<"3. 10pm-6am"<<endl;
		cout<<" Ingrese Horario: "<<endl;
		cin>>hor;
		fflush(stdin);
		cout<<"ingrese ID del Paciente"<<endl;
		cin>>pa;
		fflush(stdin);
		trabajador tra;
		paciente pac;
		bool encontrado = false;
		lista <trabajador> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&pac,sizeof(paciente),1,d);
		while(!feof(d)){
			c += pac.gravedad;
			m += pac.estado;
			if(pa==pac.id_paciente && m != "Muerto"){		
				auxh = pac.n_hospital;
				auxe = c;
			}
			c.clear();
			m.clear();
			fread(&pac,sizeof(paciente),1,d);
		}
		fread(&tra,sizeof(trabajador),1,f);
		while(!feof(f)){
			auxs += tra.seccion;
			if(auxs == "visitador"){
				s=1;
			}
			if(auxs == "piso"){
				s=2;
			}
			if(auxs == "UCI"){
				s=3;
			}
			if(auxh==tra.n_hospital && hor==tra.horario){
				switch(s){
					case 1:{
						if(auxe=="Leve"){
							x.insertar_pos(tra, a);
							encontrado = true;	
						}
						break;
					}
					case 2:{
						if(auxe=="Moderado"){
							x.insertar_pos(tra, a);
							encontrado = true;
						}
						break;
					}
					case 3:{
						if(auxe=="Severo"){
							x.insertar_pos(tra, a);
							encontrado = true;	
						}
						break;
					}		
				}
			}
			auxs.clear();
			fread(&tra,sizeof(trabajador),1,f);
		}
		if (encontrado==false){
			printf("No existe personal que pueda encargarse del paciente o el paciente esta Muerto \n");
		}else x.imprimir_trabajadores();
		fclose(f);
	}
}

void consultar_t(){
	FILE *f;
	f = fopen("trabajadores.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Id para consulta: \n");
		int id, a=0;
		scanf("%i",&id);
		fflush(stdin);
		trabajador tra;
		bool encontrado = false;
		lista <trabajador> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&tra,sizeof(trabajador),1,f);
		while(!feof(f)){
			if(id==tra.id_trabajor){
				x.insertar_pos(tra, a);
				encontrado = true;
				a++;
			}
			fread(&tra,sizeof(trabajador),1,f);
		}
		if (encontrado==false){
			printf("No existe el trabajador con ese id");
		}else x.imprimir_trabajadores();
		fclose(f);
	}
}

void consultarTXH_t(){
	FILE *f;
	f = fopen("trabajadores.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Id del hospital para consultar todos los trabajadores de este:");
		int id,a=0;
		scanf("%i",&id);
		fflush(stdin);
		trabajador tra;
		bool encontrado = false;
		lista <trabajador> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&tra,sizeof(trabajador),1,f);
		while(!feof(f)){
			if(id==tra.n_hospital){
				x.insertar_pos(tra, a);
				encontrado = true;
				a++;
			}
			fread(&tra,sizeof(trabajador),1,f);
		}
		if(encontrado==false){
			cout<<"No existe hospital"<<endl;
		}else x.imprimir_trabajadores();
		fclose(f);
	}
}

void modificar_t(){
	int a;
	FILE *f;
	f = fopen("trabajadores.txt","r+b");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("ID paciente a modificar: ");
		int id;
		scanf("%i",&id);
		fflush(stdin);
		trabajador tra;
		bool encontrado = false;
		fread(&tra,sizeof(trabajador),1,f);
		while(!feof(f)){
			if(id==tra.id_trabajor){
				printf("N_hospital: %i\n ID: %i\n Horario: %i\n Seccion: %s\n Nombre: %s\n Apellido: %s\n t_identificacion %s\n Sexo: %c\n Telefono: %s\n Telefono_fijo: %s\n Mail: %s\n F_nacimiento: %s\n Ciudad: %s\n Pais %s\n Direccion %s\n Barrio %s\n",tra.n_hospital,tra.id_trabajor,tra.horario,tra.seccion,tra.nombre,tra.apellido,tra.n_ti,tra.sexo,tra.telefono,tra.telefono_f,tra.mail,tra.f_nacimiento,tra.ciudadania,tra.pais,tra.direccion,tra.barrio);			
				cout<<"Ingrese 1 para modificar el hospital"<<endl; 
				cout<<"Ingrese 2 para modificar el horario"<<endl; 
				cout<<"Ingrese 3 para modificar la seccion"<<endl; 
				cout<<"Ingrese 4 para modificar el nombre"<<endl; 
				cout<<"Ingrese 5 para modificar el apellido"<<endl; 
				cout<<"Ingrese 6 para modificar el tipo de identificacion"<<endl;
				cout<<"Ingrese 7 para modificar el sexo"<<endl;  
				cout<<"Ingrese 8 para modificar el telefono"<<endl;
				cout<<"Ingrese 9 para modificar el telefono fijo"<<endl;
				cout<<"Ingrese 10 para modificar el mail"<<endl;
				cout<<"Ingrese 11 para modificar el fecha nacimiento"<<endl;
				cout<<"Ingrese 12 para modificar el ciudad de nacimiento"<<endl;
				cout<<"Ingrese 13 para modificar el pais nacimiento"<<endl;
				cout<<"Ingrese 14 para modificar la direccion"<<endl;
				cout<<"Ingrese 15 para modificar el barrio"<<endl;
				cin>>a;
				fflush(stdin);
				switch (a){
					case 1:	{
							printf("Ingrese nuevo Hospital:");
							scanf("%i",&tra.n_hospital);
							fflush(stdin);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("N_hospital modificado con exito");
							encontrado = true;
							break;
						} 
							 
					case 2: {
							printf("Ingrese nuevo Horario:");
							scanf("%i",&tra.horario);
							fflush(stdin);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("Horario modificado con exito");
							encontrado = true;
							break;
					}
					case 3: {
							printf("Ingrese nueva seccion:");
							gets(tra.seccion);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("Seccion modificado con exito");
							encontrado = true;
							break;
						
					} 
					case 4: {
							printf("Ingrese nuevo nombre:");
							gets(tra.nombre);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("Nombre modificado con exito");
							encontrado = true;
							break;
					}
					case 5: {
							printf("Ingrese nuevo apellido:");
							gets(tra.apellido);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("Apellido modificado con exito");
							encontrado = true;
							break;
					}	
				    case 6: {
							printf("Ingrese nuevo t_identificacion:");
							gets(tra.n_ti);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("t_identificacion modificado con exito");
							encontrado = true;
							break;
					}	
					case 7: {
							printf("Ingrese nuevo sexo:");
							scanf("%c",&tra.sexo);
							fflush(stdin);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("sexo modificado con exito");
							encontrado = true;
							break;
					} 
					case 8: {
							printf("Ingrese nuevo telefono:");
							gets(tra.telefono);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("telefono modificado con exito");
							encontrado = true;
							break;
					}
					case 9: {
							printf("Ingrese nuevo telefono_F:");
							gets(tra.telefono_f);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("Telefono_f modificado con exito");
							encontrado = true;
							break;
					}
					case 10: {
							printf("Ingrese nuevo mail:");
							gets(tra.mail);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("mail modificado con exito");
							encontrado = true;
							break;
					}
					case 11: {
							printf("Ingrese nueva F_nacimiento:");
							gets(tra.f_nacimiento);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("F_nacimiento modificado con exito");
							encontrado = true;
							break;
					}
					case 12: {
							printf("Ingrese nueva ciudad:");
							gets(tra.ciudadania);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("ciudad modificado con exito");
							encontrado = true;
							break;
					}
					case 13: {
							printf("Ingrese nuevo pais:");
							gets(tra.pais);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("pais modificado con exito");
							encontrado = true;
							break;
					}
					case 14: {
							printf("Ingrese nueva direccion:");
							gets(tra.direccion);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("direccion modificado con exito");
							encontrado = true;
							break;
					}
					case 15: {
							printf("Ingrese nuevo barrio:");
							gets(tra.barrio);
							int pos = ftell(f)-sizeof(trabajador);
							fseek(f,pos,SEEK_SET);
							fwrite(&tra,sizeof(trabajador),1,f);
							printf("Barrio modificado con exito");
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
			fread(&tra,sizeof(trabajador),1,f);
		}
		if (encontrado==false){
			printf("No se ha encontrado un paciente con ese ID");
		}
		fclose(f);
	}
}

