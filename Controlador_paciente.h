using namespace std;

struct paciente{
	int n_hospital;
	int id_paciente;
	char nombre[50];
	char apellido[50];
	char sexo;
	char f_nacimiento[50];
	char n_epexist[50];
	char localidad[50];
	char estado[50]; 
	char gravedad[50];
};
bool validar_p(int id){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{	
		paciente pac;
		bool encontrado = false;
		fread(&pac,sizeof(paciente),1,f);
		while(!feof(f)){
			if(id==pac.id_paciente){
				encontrado = true;
				return encontrado;
			}
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			return encontrado;
		}
		fclose(f);
	}
}

int edad(char a[]){
	time_t now = time(0);
	tm * time = localtime(&now);
	int anactual= 1900 + time->tm_year;
	int mesact=time->tm_mon+1;
	int edmes,edanio;
	tm *ltm = new tm;
	char *pch, auxf[50];
	strncpy(auxf,a,50);
	pch = strtok(auxf,"/");
	ltm->tm_mday=atoi(pch);
	ltm->tm_mon=atoi(strtok(NULL,"/"));
	ltm->tm_year=atoi(strtok(NULL,"/"));	
	if( mesact < ltm->tm_mon )
    {
        mesact = mesact + 12; 
        anactual = anactual - 1 ; 
        edmes = mesact - ltm->tm_mon; 
    }
    else 
        edmes = mesact - ltm->tm_mon; 
    edanio= anactual-ltm->tm_year;
}

int edad2(char a[]){
	time_t now = time(0);
	tm * time = localtime(&now);
	int anactual= 1900 + time->tm_year;
	int mesact=time->tm_mon+1;
	int edmes,edanio;
	tm *ltm = new tm;
	char *pch, auxf[50];
	strncpy(auxf,a,50);
	pch = strtok(auxf,"/");
	ltm->tm_mday=atoi(pch);
	ltm->tm_mon=atoi(strtok(NULL,"/"));
	ltm->tm_year=atoi(strtok(NULL,"/"));	
	if( mesact < ltm->tm_mon )
    {
        mesact = mesact + 12; 
        anactual = anactual - 1 ; 
        edmes = mesact - ltm->tm_mon; 
    }
    else 
        edmes = mesact - ltm->tm_mon; 
    	edanio= anactual-ltm->tm_year;
    cout<<edanio<<" Anios y "<<edmes<<" meses"<<endl;
}

void agregar_P(){
	FILE *f;
	int id;
	f = fopen("pacientes.txt","ab");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		paciente pac;
		printf("Id paciente:");
		scanf("%i",&id);
		fflush(stdin);
		if(!validar_p(id)){
			pac.id_paciente=id;
			printf("N_hospital:");
			scanf("%i",&pac.n_hospital);
			fflush(stdin);
			printf("Nombre paciente:");
			gets(pac.nombre);
			printf("Apellido paciente:");
			gets(pac.apellido);
			printf("Sexo:");
			scanf("%c",&pac.sexo);
			fflush(stdin);
			printf("Fecha nacimiento:");
			gets(pac.f_nacimiento);
			printf("Enfermedad:");
			gets(pac.n_epexist);
			printf("Localidad:");
			gets(pac.localidad);
			printf("Estado:");
			gets(pac.estado);
			printf("Gravedad:");
			gets(pac.gravedad);
			fwrite(&pac,sizeof(paciente),1,f);
			
		}
		else{
			cout<<"Esta id ya esta registrada"<<endl;
		}
		fclose(f);
	
		
	}
}

void ver_P(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		paciente pac;
		lista <paciente> x;
		int a = 0; 
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&pac,sizeof(paciente),1,f);
		while(!feof(f)){
			x.insertar_pos(pac, a);
			fread(&pac,sizeof(paciente),1,f);
			a++;
		}
		x.imprimir_pacientes();
		fclose(f);
	}
}

void cons_Lo(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Localidad:");
		string loc;
		string c;
		cin>> loc;
		fflush(stdin);
		paciente pac;
		lista <paciente> x;
		int a =0;
		bool encontrado = false;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			c+=pac.localidad;
			if(loc == c ){
				string enf;
				enf += pac.n_epexist;
				if(enf != "Ninguna"){
					x.insertar_pos(pac, a);
					a++;
					encontrado = true;
				}
				enf.clear();
			}	
			c.clear();
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			cout<<"No existen pacientes con enfermedades en esa localidad"<<endl;;
		}else x.imprimir_pacientes();
		fclose(f);	
	}	
}

void consultar_lorang(){
	FILE *f;
	bool aux= false;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Localidad:");
		string loc, c;
		int ran1, ran2, edcalc, a = 0;
		cin>> loc;
		printf("edad minima: ");
		cin>> ran1;
		fflush(stdin);
		printf("edad maxima: ");
		cin>>ran2;
		fflush(stdin);
		if(ran1 <= ran2) aux = true;
		paciente pac;
		bool encontrado = false;
		fread(&pac,sizeof(paciente),1,f);
		lista <paciente> x;
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		fread(&pac,sizeof(paciente),1,f);
		while(!feof(f)){
			c+=pac.localidad;
			edcalc=edad(pac.f_nacimiento);
			if(loc == c ){
				if(ran1 <= edcalc && ran2 >= edcalc && aux == true){
					x.insertar_pos(pac, a);
					encontrado = true;
					a++;
				}
			}	
			c.clear();
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			cout<<"No existen pacientes en ese rango de edad en esa localidad"<<endl;;
		}else x.imprimir_pacientes();
		fclose(f);	
	}	
}
void consultar_rang(){
	FILE *f;
	bool aux= false;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		int ran1, ran2, edcalc;
		printf("edad minima: ");
		cin>> ran1;
		printf("edad maxima: ");
		cin>>ran2;
		if(ran1 <= ran2) aux = true;
		fflush(stdin);
		paciente pac;
		bool encontrado = false;
		fread(&pac,sizeof(paciente),1,f);
		while(!feof(f)){
			edcalc=edad(pac.f_nacimiento);
			if(ran1 <= edcalc && ran2 >= edcalc && aux == true){
				printf("Nombre: %s\n Apellido: %s\n",pac.nombre,pac.apellido);
				edad2(pac.f_nacimiento);
				printf("Estado: %s\n Gravedad: %s\n N_hospital: %i\n Localidad: %s\n",pac.estado,pac.gravedad,pac.n_hospital,pac.localidad);
				encontrado = true;
				cout<<endl;
			}	
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			cout<<"No existen pacientes en ese rango de edad en esa localidad"<<endl;;
		}
		fclose(f);	
	}	
}

void consultar_P(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Id para consulta:");
		int id, a=0;
		scanf("%i",&id);
		fflush(stdin);
		paciente pac;
		lista <paciente> x;
		bool encontrado = false;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			if(id==pac.id_paciente){
				x.insertar_pos(pac, a);
				encontrado = true;
				a++;
			}
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			printf("No existe el paciente con ese id");
		}else x.imprimir_pacientes();
		fclose(f);
	}
}

void consultarPC_P(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Pacientes en casa:\n");
		int hos=0, a=0;
		paciente pac;
		bool encontrado = false;
		lista <paciente> x;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			if(hos==pac.n_hospital){
				x.insertar_pos(pac, a);
				a++;
			}
			fread(&pac,sizeof(paciente),1,f);
		}
		x.imprimir_pacientes();
		fclose(f);
	}
}

void consultarPXEXD_P(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Enfermedad:");
		string en;
		int a=0;
		cin>>en;
		fflush(stdin);
		printf("Localidad:");
		string ed;
		cin>>ed;
		fflush(stdin);	
		paciente pac;
		lista <paciente> x;
		bool encontrado = false;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
		for(int i = 0; i<=x.tamano_lista();i++){
			x.eliminar(i);
			}
		}
		while(!feof(f)){
			if(en==pac.n_epexist && ed==pac.localidad){
				x.insertar_pos(pac, a);
				encontrado == true;
				a++;
			}
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado=false){
			cout<<"Error en la consulta"<<endl;
		}else x.imprimir_pacientes();
		fclose(f);
	}
}

void consultarPXH_P(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
	printf("Id del hospital para consultar con los pacientes:");
		int id,a=0;
		scanf("%i",&id);
		fflush(stdin);
		paciente pac;
		bool encontrado = false;
		lista <paciente> x;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			if(id==pac.n_hospital){
				x.insertar_pos(pac, a);
				encontrado = true;
				a++;
			}
			fread(&pac,sizeof(paciente),1,f);
		}
		if(encontrado==false){
			cout<<"No se encuentra hospital"<<endl;
		}else x.imprimir_pacientes();
		fclose(f);
	}
}

void cons_pis(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		string loc, c, gr;
		printf("Localidad:");
		cin>> loc;
		cout<<" Pacientes en piso en la localidad de: "<<loc<<endl;
		paciente pac;
		int a=0;
		bool encontrado = false;
		lista <paciente> x;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			c += pac.localidad;
			gr += pac.gravedad;
			if(c==loc && gr=="Moderado"){
				x.insertar_pos(pac, a);
				encontrado = true;
				a++;
			}
			gr.clear();
			c.clear();	
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			cout<<"No existen pacientes en ese rango de edad en esa localidad"<<endl;;
		}else x.imprimir_pacientes();
		fclose(f);	
	}	
}

void cons_uci(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		string loc, c, gr;
		printf("Localidad:");
		cin>> loc;
		cout<<" Pacientes en UCI en la localidad de: "<<loc<<endl;
		paciente pac;
		bool encontrado = false;
		int a =0;
		lista <paciente> x;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			c += pac.localidad;
			gr += pac.gravedad;
			if(c==loc && gr=="Severo"){
				x.insertar_pos(pac, a);
				encontrado = true;
				a++;
			}
			gr.clear();
			c.clear();	
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			cout<<"No existen pacientes en ese rango de edad en esa localidad"<<endl;;
		}else x.imprimir_pacientes();
		fclose(f);	
	}
}

void consultarPCXL_P(){
	FILE *f;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		string p;
		printf("Pacientes en casa en localidad:\n");
		cin>>p;
		int hos=0,a=0;
		paciente pac;
		bool encontrado = false;
		lista <paciente> x;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			if(hos==pac.n_hospital && p==pac.localidad){
				x.insertar_pos(pac, a);
				encontrado = true;
				a++;
			}
			fread(&pac,sizeof(paciente),1,f);
		}
		if(encontrado==false){
			cout<<"Error en la consulta"<<endl;
		}else x.imprimir_pacientes();
		fclose(f);
	}
}

void cons_Lopa(){
	FILE *f;
	bool aux= false;
	f = fopen("pacientes.txt","rb");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("Localidad:");
		string loc, c, gr;
		cin>> loc;
		fflush(stdin);
		paciente pac;
		int a=0;
		bool encontrado = false;
			lista <paciente> x;
		fread(&pac,sizeof(paciente),1,f);
		if(x.lista_vacia()==false){
			for(int i = 0; i<=x.tamano_lista();i++){
				x.eliminar(i);
			}
		}
		while(!feof(f)){
			c+=pac.localidad;
			gr +=pac.gravedad;
			if(loc == c &&gr!= "Leve"){
				x.insertar_pos(pac, a);
				encontrado = true;
				a++;
			}	
			gr.clear();
			c.clear();
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			cout<<"No existen pacientes en ese rango de edad en esa localidad"<<endl;;
		}else x.imprimir_pacientes();
		fclose(f);	
	}	
}

void modificar_P(){
	int a;
	FILE *f;
	f = fopen("pacientes.txt","r+b");
	if (f==NULL){
		printf("No se ha podido abrir el archivo");
	} else{
		printf("ID paciente a modificar: ");
		int id;
		scanf("%i",&id);
		fflush(stdin);
		paciente pac;
		bool encontrado = false;
		fread(&pac,sizeof(paciente),1,f);
		while(!feof(f)){
			if(id==pac.id_paciente){
				printf("N_hospital: %i\n ID: %i\n Nombre: %s\n Apellido: %s\n Sexo: %c\n F_nacimiento: %s\n N_epexistente: %s\n Localidad: %s\n Estado: %s\n Gravedad: %s\n",pac.n_hospital,pac.id_paciente,pac.nombre,pac.apellido,pac.sexo,pac.f_nacimiento,pac.n_epexist,pac.localidad,pac.estado,pac.gravedad);
				cout<<"Ingrese 1 para modificar el hospital"<<endl; 
				cout<<"Ingrese 2 para modificar el nombre"<<endl; 
				cout<<"Ingrese 3 para modificar el apellido"<<endl; 
				cout<<"Ingrese 4 para modificar el sexo"<<endl; 
				cout<<"Ingrese 5 para modificar el F_nacimiento"<<endl; 
				cout<<"Ingrese 6 para modificar la localidad"<<endl;
				cout<<"Ingrese 7 para modificar el estado"<<endl;  
				cout<<"Ingrese 8 para modificar el gravedad"<<endl; 
				cin>>a;
				fflush(stdin);
				switch (a){
					case 1:	{
							printf("Ingrese nuevo Hospital:");
							scanf("%i",&pac.n_hospital);
							fflush(stdin);
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("N_hospital modificado con exito");
							encontrado = true;
							break;
						} 
							 
					case 2: {
							printf("Ingrese nuevo nombre:");
							gets(pac.nombre);
							
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("Nombre modificado con exito");
							encontrado = true;
							break;
					}
					case 3: {
							printf("Ingrese nuevo apellido:");
							gets(pac.apellido);
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("Apellido modificado con exito");
							encontrado = true;
							break;
						
					} 
					case 4: {
							printf("Ingrese nuevo sexo:");
							scanf("%c",&pac.n_hospital);
							fflush(stdin);
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("Apellido modificado con exito");
							encontrado = true;
							break;
					}
					case 5: {
							printf("Ingrese nueva F_nacimiento:");
							gets(pac.f_nacimiento);
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("Apellido modificado con exito");
							encontrado = true;
							break;
					}	
				    case 6: {
							printf("Ingrese nuevo localidad:");
							gets(pac.localidad);
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("Apellido modificado con exito");
							encontrado = true;
							break;
					}	
					case 7: {
							printf("Ingrese nuevo estado:");
							gets(pac.estado);
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("Apellido modificado con exito");
							encontrado = true;
							break;
					} 
					case 8: {
							printf("Ingrese nuevo gravedad:");
							gets(pac.gravedad);
							int pos = ftell(f)-sizeof(paciente);
							fseek(f,pos,SEEK_SET);
							fwrite(&pac,sizeof(paciente),1,f);
							printf("Apellido modificado con exito");
							encontrado = true;
							break;
					}
					default: {printf("No aplica");
							break;  
							} 
				}
				cout<<endl;
				break;
			}
			fread(&pac,sizeof(paciente),1,f);
		}
		if (encontrado==false){
			printf("No se ha encontrado un paciente con ese ID");
		}
		fclose(f);
	}
}

