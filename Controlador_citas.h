using namespace std;
struct citas{
	int turno;
	int k_hospital;
	int k_ps;
	int k_paciente;
	char fh_cita[50];
};
bool validar_c(int kcita){
	FILE *f;
	f = fopen("Citas.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{	
		citas cit;
		bool encontrado = false;
		fread(&cit,sizeof(citas),1,f);
		while(!feof(f)){
			if(kcita==cit.turno){
				encontrado = true;
				return encontrado;
			}
			fread(&cit,sizeof(citas),1,f);
		}
		if (encontrado==false){
			return encontrado;
		}
		fclose(f);
	}
}
void agregar_c(){
	int kcita;
	FILE *f, *d, *t;
	f = fopen("Citas.txt","ab");
	d = fopen("Pacientes.txt","rb");
	t = fopen("trabajadores.txt","rb");
	if (f==NULL || d==NULL){
		printf("No se ha podido abrir el archivo");
	} else{	
		paciente pac;
		trabajador tra;
		citas cit;
		bool vive=true, encontrado = false;
		string aux, aux2, aux3;
		int edmes,edanio, horarioc;
		tm *ltm = new tm;
		char *pch, auxf[50];
		printf("Turno cita:");
		scanf("%i",&kcita);
		fflush(stdin);
		if(!validar_c(kcita)){
			cit.turno=kcita;
			printf("ID paciente: ");
			scanf("%i",&cit.k_paciente);
			fflush(stdin);
			fread(&pac,sizeof(paciente),1,d);
			while(!feof(d)){
				aux+=pac.estado;
				if(aux == "Muerto" && cit.k_paciente==pac.id_paciente ){
					vive = false;
					cout<<" el paciente no puede ser atendido porque esta muerto"<<endl;
				}
				if(vive == true && cit.k_paciente==pac.id_paciente){
					aux2 = pac.gravedad;
					cout<<aux2<<endl;
					printf("ID hospital:");
					scanf("%i",&cit.k_hospital);
					fflush(stdin);
					printf("Fecha y Hora de cita:");
					gets(cit.fh_cita);
					strncpy(auxf,cit.fh_cita,50);
					pch = strtok(auxf," /:");
					ltm->tm_mday = atoi(pch); 
				    ltm->tm_mon = atoi(strtok(NULL, " /:"));  
				    ltm->tm_year = atoi(strtok(NULL, " /:")); 
				    ltm->tm_hour = atoi(strtok(NULL, " /:")); 
				    ltm->tm_min = atoi(strtok(NULL, " /:")); 
				    ltm->tm_sec = atoi(strtok(NULL, " /:"));
    				if(ltm->tm_hour>=6 && ltm->tm_hour<14 ){
    					horarioc = 1;
					}
					if( ltm->tm_hour>=14 && ltm->tm_hour<22){
    					horarioc = 2;
					}
					if(ltm->tm_hour>=22 || ltm->tm_hour<6 ){
    					horarioc = 3;
					}
					fread(&tra,sizeof(trabajador),1,t);
					while(!feof(t)){
						aux3+=tra.seccion;
						if(horarioc == tra.horario && cit.k_hospital == tra.n_hospital && encontrado==false){
							if(aux2 == "Leve" && aux3 == "visitador"){
								cit.k_ps = tra.id_trabajor;
								encontrado = true;
							}
							if(aux2 == "Moderado" && aux3 == "piso"){
								cit.k_ps = tra.id_trabajor;
								encontrado = true;
							}
							if(aux2 == "Severo" && aux3 == "UCI"){
								cit.k_ps = tra.id_trabajor;
								encontrado = true;
							}
						}
						aux3.clear();
						fread(&tra,sizeof(trabajador),1,t);
					}
					if(encontrado=false) cout<<"No hay personal disponible"<<endl;
					fwrite(&cit,sizeof(citas),1,f);	
					cout<<"se agendo la cita con exito"<<endl;
				}
				aux.clear();
				fread(&pac,sizeof(paciente),1,d);
			}	
		}
		else{
			cout<<"Este turno no esta disponible"<<endl;
		}
		fclose(f);		
	}
}

void ver_c(){
	FILE *f;
	f = fopen("Citas.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		citas cit;
		int a=0; 
		lista <citas> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&cit,sizeof(citas),1,f);
		while(!feof(f)){
			x.insertar_pos(cit, a);
			fread(&cit,sizeof(citas),1,f);
		}
		x.imprimir_citas();
		fclose(f);
	}
}
void cons_listaPSP(){
	FILE *f;
	f = fopen("Citas.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		int idps, a=0;
		printf("ID personal de salud: ");
		cin>> idps;
		fflush(stdin);
		citas cit;
		bool encontrado = false;
		lista <citas> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&cit,sizeof(citas),1,f);
		while(!feof(f)){
			if(idps==cit.k_ps){
				x.insertar_pos(cit, a);
				encontrado= true;
				a++;	
			}	
			fread(&cit,sizeof(citas),1,f);
		}
		if (encontrado==false){
			cout<<"No existe personal de salud con ese id para citas"<<endl;;
		}else x.imprimir_citas();
		fclose(f);	
	}
}
void cons_listaPSS(){
	FILE *f;
	f = fopen("Citas.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		int idpac, a=0;
		printf("ID paciente: ");
		cin>> idpac;
		fflush(stdin);
		citas cit;
		lista <citas> x;
		bool encontrado = false;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&cit,sizeof(citas),1,f);
		while(!feof(f)){
			if(idpac==cit.k_paciente){
				x.insertar_pos(cit, a);
				encontrado= true;
				a++;		
			}	
			fread(&cit,sizeof(citas),1,f);
		}
		if (encontrado==false){
			cout<<"No existe paciente con es id para citas"<<endl;;
		}else x.imprimir_citas();
		fclose(f);	
	}
}
void consultar_c(){
	FILE *f;
	f = fopen("Citas.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Turno consulta:");
		int id, a=0;
		scanf("%i",&id);
		fflush(stdin);
		citas cit;
		lista <citas> x;
		bool encontrado = false;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&cit,sizeof(citas),1,f);
		while(!feof(f)){
			if(id==cit.turno){
				x.insertar_pos(cit, a);
				encontrado = true;
				a++;
			}
			fread(&cit,sizeof(citas),1,f);
		}
		if (encontrado==false){
			printf("No existe tal turno");
		}else x.imprimir_citas();
		fclose(f);
	}
}

