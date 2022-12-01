

/* Puntero a funciones que carga en "clave" a la palabra clave y en "valo" a la posicion de memoria siguiente*/
char *obtenerclave(char *clave);



datos_t inicio() {
	
	FILE *config;
	char cadena[70], *clave, *valo;
	char variables[4][30]={"cables","tension_limite","tension","avisos"}, i;
	datos_t configuracion;
 	if(!(config=fopen("Config.conf","rb"))){
 		printf("\nNo se encontro el archivo buscado\n");
 	
	 }
	 fgets(cadena,70,config);
	 do{
	 	clave=cadena;
	 	if(*(clave) != '/' && strlen(clave)>0){
	 		valo=obtenerclave(clave);
	 		for(i=0;i<3;i++)
	 		{
	 			if(!strcmp(clave, variables[i])){
	 				switch(i)
	 				{
	 					case 0: configuracion.cables=atoi(valo);
	 							break;
	 					case 1: configuracion.tension_limite=atoi(valo);
	 							break;
	 					case 2: configuracion.tension=atoi(valo);
	 							break;
	 					case 3: strcpy(configuracion.avisos,valo);
	 							break;
	 							
					 }
				 }
			 }
	 		
		 }
		 fgets(cadena,70,config);
	 }while(!feof(config));
	 
	 fclose(config);
	 
	return configuracion;
}



char *obtenerclave(char *clave){
	char i=0;
	
	while(*(clave+i)!=' '){
		i++;
	}
	return clave+i+1;
}
