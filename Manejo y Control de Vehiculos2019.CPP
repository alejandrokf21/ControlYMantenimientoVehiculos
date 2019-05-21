#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring.h>
#include <string.h>
#include <conio.h>

struct RegUsusario{

	char user[10];
    char name[18];
    char password[16];
    char type[4];
}userList, userAux;

//Declaracion de variables globales, funciones y metodos
char typeGlobal[3], nameGlobal[15]={' '};

void iniciarSesion();
int verificarUsuario(char promptUser[20], char promptPassword[16]);
int opcionSalir();
void menuInicial();
void menuPrincpal(char type[4]);


main(){
   /*FILE *fp;
   int i=0;
    fp = fopen("users.dat","a+b");
    clrscr();
    do
    {
        cout<<"Ingrese el nuevo usuario: ";
        cin>>userList.user;
        cout<<"Ingrese el nombre: ";
        gets(userList.name);
        cout<<"Ingrese la contraseña: ";
        cin>>userList.password;
        cout<<"Ingrese Tipo de usuario: ";
        cin>>userList.type;
        fwrite(&userList, sizeof(userList), 1, fp);
         i++;
    } while (i<8);
    fclose(fp); */
	menuInicial();
}

void iniciarSesion(){
   char promptUser[20], promptPassword[16]={0}, op, c;
   int menu=400, ver, contador=0,i=0;

  FILE *fp;
   fp=fopen("users.dat", "r+b");
  //do{
    if(fp==NULL){
        cout<<"+------------------------------------------------------------------+"<<endl;
        cout<<" ERROR: El archivo 'users.dat' no se ha podido encontrar.\nAsegurese de incluir la extension del archivo y que este sea .dat.\n\n";
        cout<<"+------------------------------------------------------------------+"<<endl;
        cout<<" Desea continuar? S/N: ";
        cin>>op;

        if(op=='S' || op=='s'){
            menu=404;
          cout<<"Presione cualquier tecla para continuar...";
        }else if(op=='N' || op=='n'){
          menu=400;
          cout<<"Que tenga un buen dia!";
        }else{
          menu=404;
          cout<<" Opcion NO valida. Presione cualquier tecla para continuar...";
        }
        fclose(fp);
    }else{
        clrscr();
        menu=400;
        //----->Codigo a borrar
        fread(&userList, sizeof(userList), 1, fp);
        while(!feof(fp)){
            cout<<userList.user<<" | "<<userList.password<<endl;
            fread(&userList, sizeof(userList), 1, fp);
        }

        do{
        		i=0 ;
            cout<<"+-----------------------------------------+"<<endl;
            cout<<"|            INICIO DE SESION             |"<<endl;
            cout<<"+-----------------------------------------+"<<endl;
            cout<<" Usuario: ";
            cin>>promptUser;
            cout<<" Contrasena: ";
            memset( promptPassword, 0, 16 );
            while((c=_getch())!=13) {
                promptPassword[i] = c;
                putch('*');
                i++;
            }
            cout<<"+-----------------------------------------+"<<endl;
            ver = verificarUsuario(promptUser, promptPassword);
            if(ver!=1 && contador<3){
                clrscr();
                cout<<"Error: Usuario o contraseña invalidos. Le quedan "<<(3-contador)<<" intentos."<<endl;
                contador++;
            }else if(contador==3){
                cout<<"Lo sentimos, has agotado tus intentos. Adios!";
                contador++;
            }else{
                //entra al menu();
                clrscr();
                fclose(fp);
                menuPrincpal(typeGlobal);
                contador=4;
            }
        }while(contador<4);
    }
    fclose(fp);
}

//Valida el usuario y contraseña ingresado
int verificarUsuario(char promptUser[20], char promptPassword[16]){
    int compUser, compPass;
    bool found =true;

    FILE *fp=fopen("users.dat","r+b");
    fread(&userList, sizeof(userList), 1, fp);
    while(!feof(fp)){
        compUser=strcmp(promptUser,userList.user);
        compPass=strcmp(promptPassword, userList.password);

        if(compUser==0 && compPass==0){
            strcpy(nameGlobal,userList.name);
            strcpy(typeGlobal,userList.type);
            fclose(fp);
            return 1;
            //found=false;
        }else if(feof(fp)){
            fclose(fp);
            return 404;
        }
        fread(&userList, sizeof(userList), 1, fp);
    }
    fclose(fp);
}

void menuInicial(){
    int op, menu=404;

    do{
        clrscr();
        cout<<"---------------------------------"<<endl;
        cout<<"         MENU INICIAL  "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<" 1. Iniciar Session"<<endl;
        cout<<" 2. Salir"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<" Ingrese su opcion: ";
        cin>>op;

        switch(op){
            /*     Iniciar session   */
            case 1:
                iniciarSesion();
                break;
            /*     SALIR   */ 
            case 2:
                menu = opcionSalir();
                break;
                
        }
    }while(menu==404);

}

void menuPrincpal(char type[4]){
    int op, menu=404;
    char des;

    do{
        clrscr();
        if(strcmp(type,"mecr")==0){
            cout<<"--------- Menu Principal --------"<<endl;
            cout<<" Bienvenido a Reparaciones: "<< nameGlobal<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" 1. "<<endl;
            cout<<" 2. Lista Enlazada"<<endl;
            cout<<" 3. Lista Doblemente Enlazada"<<endl;
            cout<<" 4. Pilas"<<endl;
            cout<<" 5. Salir"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" Ingrese su opcion: "; 
            cin>> op;    
        }else if(strcmp(type,"mecm")==0){
            cout<<"--------- Menu Principal --------"<<endl;
            cout<<" Bienvenido a Mantenimiento: "<< nameGlobal<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" 1. "<<endl;
            cout<<" 2. Lista Enlazada"<<endl;
            cout<<" 3. Lista Doblemente Enlazada"<<endl;
            cout<<" 4. Pilas"<<endl;
            cout<<" 5. Salir"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" Ingrese su opcion: "; 
            cin>> op;

        }else if(strcmp(type,"qya")==0){
            cout<<"--------- Menu Principal --------"<<endl;
            cout<<" Bienvenido a "<<nameGlobal<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" 1. "<<endl;
            cout<<" 2. Lista Enlazada"<<endl;
            cout<<" 3. Lista Doblemente Enlazada"<<endl;
            cout<<" 4. Pilas"<<endl;
            cout<<" 5. Salir"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" Ingrese su opcion: "; 
            cin>> op;
        }else if(strcmp(type,"rec")==0){
            cout<<"--------- Menu Principal --------"<<endl;
            cout<<" Bienvenido a "<<nameGlobal<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" 1. "<<endl;
            cout<<" 2. Lista Enlazada"<<endl;
            cout<<" 3. Lista Doblemente Enlazada"<<endl;
            cout<<" 4. Pilas"<<endl;
            cout<<" 5. Salir"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<" Ingrese su opcion: "; 
            cin>> op;
        }else{
            cout<<"----------------------------------------"<<endl;
            cout<<" ERROR: No se ha reconocido su puesto,\npor favor contacte al administrador "; 
            cout<<"----------------------------------------"<<endl;
        }
        system("pause");
        
    }while(menu==400);
}

int opcionSalir(){
    int menu;
    char des;
    cout<<"Esta seguro que desea salir? S/N: ";
    cin>>des;
    /*  menu 400: sale del programa.
        menu 404: regresa al menu principal.
        menu 504: opcion no reconocida, pregunta nuevamente si desea salir.
    */

    if(des=='s' || des=='S'){
    menu=400;
    }else if(des=='n' || des=='N'){
    menu=404;
    }else{
    cout<<"Opcion ingresada no es valida!"<<endl;
    menu=504;
    }
    return menu;
}
