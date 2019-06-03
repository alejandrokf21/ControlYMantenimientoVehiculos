#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring.h>
#include <string.h>
#include <conio.h>

struct NodeMaintenance{
    int order;
    char status[25];
    char description[100];
    char plate[8];
    char make[15];
    int model;
    char line[15];
    char type[4];
    struct NodeMaintenance *sigMnt;
} *iniMaint=NULL, *ultMaint=NULL, *auxMaint;

struct NodeRepair{
    int orderRep;
    char statusRep[25];
    char descriptionRep[100];
    char plateRep[8];
    char makeRep[15];
    int modelRep;
    char lineRep[15];
    char typeRep[4];
    struct NodeRepair *sigRep;
} *iniRep=NULL, *ultRep=NULL, *auxRep;

//Lista para control de calidad
struct ControlCalidad{
    int orderControl;
    char statusControl[25];
    char descriptionControl[100];
    char plateControl[8];
    char makeControl[15];
    int modelControl;
    char lineControl[15];
    char typeControl[4];
    char mecanicoControl[10];
    struct ControlCalidad *sigControl;
}*iniControl=NULL, *ultControl=NULL, *auxControl;
//Cola para Ordenes de vuelta
struct ColaDeVuelta{
    int orderDeVuelta;
    char statusDeVuelta[25];
    char descriptionDeVuelta[100];
    char plateDeVuelta[8];
    char makeDeVuelta[15];
    int modelDeVuelta;
    char lineDeVuelta[15];
    char typeDeVuelta[4];
    char mecanicoDeVuelta[10];
    struct ColaDeVuelta *sigDeVuelta;
}*iniDeVuelta=NULL, *ultDeVuelta=NULL, *auxDeVuelta;

//Lista para Salida de Vehiculos
struct SalidaDeVehiculo{
   int orderSalida;
   char statusSAlida[25];
   char descriptionSalida[100];
   char plateSalida[8];
   char makeSalida[15];
   int modelSalida;
   char lineSalida[15];
   char typeSalida[4];
   char mecanicoSalida[10];
   struct SalidaDeVehiculo *sigSalida;
}*iniSalida=NULL, *ultSalida=NULL, *auxSalida;

struct NodeMecA{
    int orderMecA;
    char statusMecA[25];
    char descriptionMecA[100];
    char plateMecA[8];
    char makeMecA[15];
    int modelMecA;
    char lineMecA[15];
    char typeMecA[4];
    char userMecA[10];
    struct NodeMecA *sigMecA;
} *iniMecA=NULL, *ultMecA=NULL, *auxMecA;

struct NodeMecB{
    int orderMecB;
    char statusMecB[25];
    char descriptionMecB[100];
    char plateMecB[8];
    char makeMecB[15];
    int modelMecB;
    char lineMecB[15];
    char typeMecB[4];
    char userMecB[10];
    struct NodeMecB *sigMecB;
} *iniMecB=NULL, *ultMecB=NULL, *auxMecB;

struct NodeMecC{
    int orderMecC;
    char statusMecC[25];
    char descriptionMecC[100];
    char plateMecC[8];
    char makeMecC[15];
    int modelMecC;
    char lineMecC[15];
    char typeMecC[4];
    char userMecC[10];
    struct NodeMecC *sigMecC;
} *iniMecC=NULL, *ultMecC=NULL, *auxMecC;

struct NodeMecX{
    int orderMecX;
    char statusMecX[25];
    char descriptionMecX[100];
    char plateMecX[8];
    char makeMecX[15];
    int modelMecX;
    char lineMecX[15];
    char typeMecX[4];
    char userMecX[10];
    struct NodeMecX *sigMecX;
} *iniMecX=NULL, *ultMecX=NULL, *auxMecX;

struct NodeMecY{
    int orderMecY;
    char statusMecY[25];
    char descriptionMecY[100];
    char plateMecY[8];
    char makeMecY[15];
    int modelMecY;
    char lineMecY[15];
    char typeMecY[4];
    char userMecY[10];
    struct NodeMecY *sigMecY;
} *iniMecY=NULL, *ultMecY=NULL, *auxMecY;

struct NodeMecZ{
    int orderMecZ;
    char statusMecZ[25];
    char descriptionMecZ[100];
    char plateMecZ[8];
    char makeMecZ[15];
    int modelMecZ;
    char lineMecZ[15];
    char typeMecZ[4];
    char userMecZ[10];
    struct NodeMecZ *sigMecZ;
} *iniMecZ=NULL, *ultMecZ=NULL, *auxMecZ;

struct RegUsusario{
    char user[10];
    char name[20];
    char password[16];
    char type[5];
}userList, userAux;

//Declaracion de variables globales, funciones y metodos
char typeGlobal[5], nameGlobal[20]={' '}, userGlobal[10];
int countRep=1, countMnt=1, countNodeMecA=0, countNodeMecB=0, countNodeMecC=0, countNodeMecX=0, countNodeMecY=0, countNodeMecZ=0;
bool valA=true, valB=false, valC=false, valX=true, valY=false, valZ=false;

void iniciarSesion();
int verificarUsuario(char promptUser[20], char promptPassword[16]);
int opcionSalir();
void menuInicial();
void menuPrincpal(char type[5]);
void agregarArchivo();
void menuRepeccion();
void buscarOrden(int noOrder);
void agregarOrdRep(char description[100],char plate[8], char make[15], int model, char line[15]);
void agregarOrdMnt(char description[100],char plate[8], char make[15], int model, char line[15]);
void repartirOrdenMnt();
void repartirOrdenRep();
void deleteMntQueue();
void deleteRepQueue();
void agregarOrdA();
void agregarOrdB();
void agregarOrdC();
void agregarOrdX();
void agregarOrdY();
void agregarOrdZ();
void totalOrdenes();
void mostrarMnt();
void mostrarRep();
void mostrarMecA();
void mostrarMecB();
void mostrarMecC();
void mostrarMecX();
void mostrarMecY();
void mostrarMecZ();
void mostrarControl();
void deleteMecA();
void deleteMecB();
void deleteMecC();
void deleteMecX();
void deleteMecY();
void deleteMecZ();
void displayMecanico();
void agregarCalidad();
void agregarOrdCalidad(int orden, char description[100], char plate[8], char make[15], int model, char line[15], char type[4]);
void menuMecanico();
void MenuControlDeCalidad();
void buscarOrdenControl(int opBuscar);

/*-----------------------------------------------------------------------
                            INICIO DEL PROGRAMA
-----------------------------------------------------------------------*/

main(){
//agregarArchivo();
menuInicial();
}


/*-----------------------------------------------------------------------
                            FUNCIONES GENERALES
-----------------------------------------------------------------------*/

void iniciarSesion(){
    char promptUser[20], promptPassword[16], op, c;
    int menu=400, ver, contador=0,i=0;

    FILE *fp;
    fp=fopen("users.dat", "r+b");

    memset( userGlobal, 0,16);
    memset( nameGlobal, 0,20);
    memset( typeGlobal, 0,4);

    if(fp==NULL){
        cout<<"+------------------------------------------------------------------+"<<endl;
        cout<<" ERROR: El archivo 'users.dat' no se ha podido encontrar.\nAsegurese de incluir la extension del archivo y que este sea .dat.\n\n";
        cout<<"+------------------------------------------------------------------+"<<endl;
        fclose(fp);
    }else{
        system("CLS");

        //----->Codigo a borrar
        fread(&userList, sizeof(userList), 1, fp);
        while(!feof(fp)){
            cout<<userList.user<<" | "<<userList.password<<endl;
            fread(&userList, sizeof(userList), 1, fp);
        }

        do{
            cin.ignore();
            cout<<"+-----------------------------------------+"<<endl;
            cout<<"|            INICIO DE SESION             |"<<endl;
            cout<<"+-----------------------------------------+"<<endl;
            cout<<" Usuario: ";
            cin>>promptUser;
            cout<<" Contrasena: ";
            memset( promptPassword, 0,sizeof(promptPassword));
            for(i=0; i<16; i++){
                if((c=getch())!=13){
                    promptPassword[i]=c;
                    cout<<'*';
                }else
                    break;
            }
            cout<<"+-----------------------------------------+"<<endl;
            ver = verificarUsuario(promptUser, promptPassword);
            if(ver!=1 && contador<3){
                system("CLS");
                cout<<"Error: Usuario o contraseña invalidos. Le quedan "<<(3-contador)<<" intentos."<<endl;
                contador++;
            }else if(contador==3){
                cout<<"Lo sentimos, has agotado tus intentos. Adios!";
                contador++;
            }else{
                //entra al menu();
                system("CLS");
                fclose(fp);
                menuPrincpal(typeGlobal);
                contador=4;
            }
        }while(contador<4);
    }
    fclose(fp);
}

///////////////------------Valida el usuario y contraseña ingresado
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
            strcpy(userGlobal,userList.user);
            fclose(fp);
            return 1;
            
        }else if(feof(fp)){
            fclose(fp);
            return 404;
        }
        fread(&userList, sizeof(userList), 1, fp);
    }
    fclose(fp);
}

/*-----------------------------------------------------------------------
                            FUNCIONES GENERALES
-----------------------------------------------------------------------*/
void menuInicial(){
    int op, menu=404;

    do{
        system("CLS");
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
                system("CLS");
                iniciarSesion();
                break;
            /*     SALIR   */ 
            case 2:
                menu = opcionSalir();
                break;
                
        }
    }while(menu==404);

}

void menuPrincpal(char type[5]){
    int op, menu=404;
    char des;

    system("CLS");
    do{
        system("CLS");
        if(strcmp(type,"mecr")==0){
            system("CLS");
            menuMecanico();
        }else if(strcmp(type,"mecm")==0){
            system("CLS");
            menuMecanico();
        }else if(strcmp(type,"qya")==0){
            system("CLS");
            MenuControlDeCalidad();
        }else if(strcmp(type,"rec")==0){ //Menu Recepcion
            system("CLS");
            menuRepeccion();
        }else{
            system("CLS");
            cout<<"----------------------------------------"<<endl;
            cout<<" ERROR: No se ha reconocido su puesto,\npor favor contacte al administrador "<<endl;
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

void agregarArchivo(){
    FILE *fp;
   int i=0;
    fp = fopen("users.dat","a+b");
    system("CLS");
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
    fclose(fp);
}

/*-----------------------------------------------------------------------
                            FUNCIONES RECEPCION
-----------------------------------------------------------------------*/
void menuRepeccion(){
    int op, menu=404,model, i=0, noOrder;
    char description[100]={' '}, plate[8]={' '}, make[15]={' '}, line[15]={' '};

    do{
        system("CLS");
        cout<<"-------------------------------------"<<endl;
        cout<<"     Menu Recepcion"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<" 1. Ingresar a Reparacion"<<endl;
        cout<<" 2. Ingresar a Mantenimiento"<<endl;
        cout<<" 3. Buscar Orden"<<endl;
        cout<<" 4. Listado de Ordenes para Entregar"<<endl;
        cout<<" 5. Total de Ordenes"<<endl;//cambiar a ver reporte 
        cout<<" 6. Cerrar Sesion"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<" Ingrese la opcion: ";
        cin>>op;

        switch(op){
            case 1:
                system("CLS");
                cout<<"-------------------------------------"<<endl;
                cout<<"     Recepcion para Reparacion"<<endl;
                cout<<"-------------------------------------"<<endl;
                cout<<" Ingrese la Marca del vehiculo: ";
                gets(make);
                cout<<" Ingrese la Linea del vehiculo: ";
                gets(line);
                cout<<" Ingrese El ano del vehiculo: ";
                cin>>model;
                cout<<" Ingrese la Placa del vehiculo: ";
                gets(plate);
                cout<<" Ingrese Descripcion de la reparacion: ";
                gets(description);

                agregarOrdRep(description, plate, make, model, line);
                repartirOrdenRep();
                break;
            case 2:
                system("CLS");
                cout<<"-------------------------------------"<<endl;
                cout<<"     Recepcion para Mantenimiento"<<endl;
                cout<<"-------------------------------------"<<endl;
                cout<<" Ingrese la Marca del vehiculo: ";
                gets(make);
                cout<<" Ingrese la Linea del vehiculo: ";
                gets(line);
                cout<<" Ingrese El ano del vehiculo: ";
                cin>>model;
                cout<<" Ingrese la Placa del vehiculo: ";
                gets(plate);
                cout<<" Ingrese Descripcion del mantenimiento: ";
                gets(description);

                agregarOrdMnt(description, plate, make, model, line);
                repartirOrdenMnt();
                break;
            case 3:
                /* BUSCAR OREN */
                system("CLS");
                cout<<"-------------------------------------"<<endl;
                cout<<"     Busqueda de Orden"<<endl;
                cout<<"-------------------------------------"<<endl;
                cout<<" Ingrese el numero de orden: ";
                cin>>noOrder;

                buscarOrden(noOrder);
                system("pause");
                break;
            case 4:
                /* LISTADO DE VHICULOS A ENTREGAR */
                break;
            case 5:
                /* Total de Ordenes */
                totalOrdenes();
                break;
            case 6:
                /* CERRAR SESION*/
                repartirOrdenRep();
                menu = opcionSalir();
                break;
            default:
                system("CLS");
                cout<<" ERROR: La opcion ingresada no es valida, por favor intente de nuevo."<<endl;
                system("pause");
                break;
        }
    }while(menu==404);
}


void agregarOrdRep(char description[100],char plate[8], char make[15], int model, char line[15]){
    /*char noOrder[10]={' '};
    char buffer[3]={' '};
    strcat(noOrder,"REP-");
    itoa(countRep,buffer,10);
    strcat(noOrder,buffer);
    countRep++;*/
    

    auxRep = new NodeRepair;
    auxRep->orderRep= countRep;
    strcpy(auxRep->statusRep, "En Linea de Espera");
    strcpy(auxRep->descriptionRep, description);
    strcpy(auxRep->plateRep, plate);
    strcpy(auxRep->makeRep, make);
    auxRep->modelRep= model;
    strcpy(auxRep->lineRep,line);
    strcpy(auxRep->typeRep,"REP");

    if(iniRep == NULL){
        iniRep = ultRep = auxRep;
        auxRep->sigRep = NULL;
    }else{
        auxRep->sigRep=NULL;
        ultRep->sigRep=auxRep;
        ultRep=auxRep;
    }
    
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<" Orden ingresada Exitosamente, su numero de orden es: "<<countRep<<endl;
    system("pause");
    countRep++;
}
void agregarOrdMnt(char description[100],char plate[8], char make[15], int model, char line[15]){
    /*char noOrder[10]={' '};
    char buffer[3]={' '};
    strcat(noOrder,"MNT-");
    itoa(countMnt,buffer,10);
    strcat(noOrder,buffer);
    countMnt++;*/
    
    auxMaint = new NodeMaintenance;
    auxMaint->order = countRep;
    strcpy(auxMaint->status, "En Linea de Espera");
    strcpy(auxMaint->description, description);
    strcpy(auxMaint->plate, plate);
    strcpy(auxMaint->make, make);
    auxMaint->model= model;
    strcpy(auxMaint->line,line);
    strcpy(auxMaint->type,"MNT");

    if(iniMaint == NULL){
        iniMaint = ultMaint = auxMaint;
        auxMaint->sigMnt = NULL;
    }else{
        auxMaint->sigMnt=NULL;
        ultMaint->sigMnt=auxMaint;
        ultMaint=auxMaint;
    }
    
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<" Orden ingresada Exitosamente, su numero de orden es: "<<countRep<<endl;
    system("pause");
    countRep++;
}

void buscarOrden(int noOrder){
    
}

void repartirOrden(){
    /* 1. Validar si existe alguna en cola de descalidad*/
    /* 2. Agragrar a cola de mec correspondiente*/
    //repartirOrdencONTROL();
    repartirOrdenRep();
    repartirOrdenMnt();
}

void repartirOrdenRep(){
    while(iniRep!=NULL){
        if(countNodeMecA==5 && countNodeMecB==5 && countNodeMecC==5){
            break;
        }else{
            if((countNodeMecA<countNodeMecB) && (countNodeMecA<countNodeMecC)){
                valB=valC=false;
                valA=true;
            }else if((countNodeMecB<countNodeMecA) && (countNodeMecB<countNodeMecC)){
                valA=valC=false;
                valB=true;
            }else if((countNodeMecC<countNodeMecA) && (countNodeMecB<countNodeMecC)){
                valB=valA=false;
                valC=true;
            }

            if(valA==true && countNodeMecA <5){
                agregarOrdA();
                deleteRepQueue();
                valA=valC=false;
                valB=true;
                countNodeMecA++;
            }else if(valB==true && countNodeMecB <5){
                agregarOrdB();
                deleteRepQueue();
                valB=valA=false;
                valC=true;
                countNodeMecB++;
            }else if(valC==true && countNodeMecC <5){
                agregarOrdC();
                deleteRepQueue();
                valB=valC=false;
                valA=true;
                countNodeMecC++;
            }
        }
    }
}

void repartirOrdenMnt(){
    while(iniMaint!=NULL){
        if(countNodeMecX==5 && countNodeMecY==5 && countNodeMecZ==5){
            break;
        }else{
            if(countNodeMecX<countNodeMecY && countNodeMecX<countNodeMecZ){
                valY=valZ=false;
                valX=true; 
            }else if(countNodeMecY<countNodeMecX && countNodeMecY<countNodeMecZ){
                valX=valZ=false;
                valY=true;
            }else if(countNodeMecZ<countNodeMecX && countNodeMecY<countNodeMecZ){
                valY=valX=false;
                valZ=true;
            }

            
            if(valX==true && countNodeMecX <5){
                agregarOrdX();
                deleteMntQueue();
                valX=valZ=false;
                valY=true;
                countNodeMecX++;
            }else if(valY==true && countNodeMecY <5){
                agregarOrdY();
                deleteMntQueue();
                valY=valX=false;
                valZ=true;
                countNodeMecY++;
            }else if(valZ==true && countNodeMecZ <5){
                agregarOrdZ();
                deleteMntQueue();
                valY=valZ=false;
                valX=true;
                countNodeMecZ++;
            }
        }
    }
}


void mostrarMnt(){
    auxMaint=iniMaint;
    if (iniMaint==NULL){
        return;
    }else{ 
        while(auxMaint!=NULL){
            cout<<auxMaint->order<<"\t\t"<<auxMaint->type<<"\t"<<auxMaint->make<<"\t"<<auxMaint->line<<"\t"<<auxMaint->model<<"\t"<<auxMaint->plate<<"\t"<<auxMaint->status<<endl;
            auxMaint=auxMaint->sigMnt;
        }
    }
}

void mostrarRep(){
    auxRep=iniRep;
    if (iniRep==NULL){
        return;
    }else{ 
        while(auxRep!=NULL){
            cout<<auxRep->orderRep<<"\t\t"<<auxRep->typeRep<<"\t"<<auxRep->makeRep<<"\t"<<auxRep->lineRep<<"\t"<<auxRep->modelRep<<"\t"<<auxRep->plateRep<<"\t"<<auxRep->statusRep<<endl;
            auxRep=auxRep->sigRep;
        }
    }
}

void mostrarMecA(){
    auxMecA=iniMecA;
    if (iniMecA==NULL){
        return;
    }else{ 
        while(auxMecA!=NULL){
            cout<<auxMecA->orderMecA<<"\t\t"<<auxMecA->typeMecA<<"\t"<<auxMecA->makeMecA<<"\t"<<auxMecA->lineMecA<<"\t"<<auxMecA->modelMecA<<"\t"<<auxMecA->plateMecA<<"\t"<<auxMecA->statusMecA<<"\t"<<auxMecA->userMecA<<endl;
            auxMecA=auxMecA->sigMecA;
        }
    }
}
void mostrarMecB(){
    auxMecB=iniMecB;
    if (iniMecB==NULL){
        return;
    }else{ 
        while(auxMecB!=NULL){
            cout<<auxMecB->orderMecB<<"\t\t"<<auxMecB->typeMecB<<"\t"<<auxMecB->makeMecB<<"\t"<<auxMecB->lineMecB<<"\t"<<auxMecB->modelMecB<<"\t"<<auxMecB->plateMecB<<"\t"<<auxMecB->statusMecB<<"\t"<<auxMecB->userMecB<<endl;
            auxMecB=auxMecB->sigMecB;
        }
    }
}
void mostrarMecC(){
    auxMecC=iniMecC;
    if (iniMecC==NULL){
        return;
    }else{ 
        while(auxMecC!=NULL){
            cout<<auxMecC->orderMecC<<"\t\t"<<auxMecC->typeMecC<<"\t"<<auxMecC->makeMecC<<"\t"<<auxMecC->lineMecC<<"\t"<<auxMecC->modelMecC<<"\t"<<auxMecC->plateMecC<<"\t"<<auxMecC->statusMecC<<"\t"<<auxMecC->userMecC<<endl;
            auxMecC=auxMecC->sigMecC;
        }
    }
}
void mostrarMecX(){
    auxMecX=iniMecX;
    if (iniMecX==NULL){
        return;
    }else{ 
        while(auxMecX!=NULL){
            cout<<auxMecX->orderMecX<<"\t\t"<<auxMecX->typeMecX<<"\t"<<auxMecX->makeMecX<<"\t"<<auxMecX->lineMecX<<"\t"<<auxMecX->modelMecX<<"\t"<<auxMecX->plateMecX<<"\t"<<auxMecX->statusMecX<<"\t"<<auxMecX->userMecX<<endl;
            auxMecX=auxMecX->sigMecX;
        }
    }
}
void mostrarMecY(){
    auxMecY=iniMecY;
    if (iniMecY==NULL){
        return;
    }else{ 
        while(auxMecY!=NULL){
            cout<<auxMecY->orderMecY<<"\t\t"<<auxMecY->typeMecY<<"\t"<<auxMecY->makeMecY<<"\t"<<auxMecY->lineMecY<<"\t"<<auxMecY->modelMecY<<"\t"<<auxMecY->plateMecY<<"\t"<<auxMecY->statusMecY<<"\t"<<auxMecY->userMecY<<endl;
            auxMecY=auxMecY->sigMecY;
        }
    }
}
void mostrarMecZ(){
    auxMecZ=iniMecZ;
    if (iniMecZ==NULL){
        return;
    }else{ 
        while(auxMecZ!=NULL){
            cout<<auxMecZ->orderMecZ<<"\t\t"<<auxMecZ->typeMecZ<<"\t"<<auxMecZ->makeMecZ<<"\t"<<auxMecZ->lineMecZ<<"\t"<<auxMecZ->modelMecZ<<"\t"<<auxMecZ->plateMecZ<<"\t"<<auxMecZ->statusMecZ<<"\t"<<auxMecZ->userMecZ<<endl;
            auxMecZ=auxMecZ->sigMecZ;
        }
    }
}
void mostrarControl(){
    auxControl=iniControl;
    if (iniControl==NULL){
        return;
    }else{ 
        while(auxControl!=NULL){
            cout<<auxControl->orderControl<<"\t\t"<<auxControl->typeControl<<"\t"<<auxControl->makeControl<<"\t"<<auxControl->lineControl<<"\t"<<auxControl->modelControl<<"\t"<<auxControl->plateControl<<"\t"<<auxControl->statusControl<<endl;
            auxControl=auxControl->sigControl;
        }
    }
}

void deleteRepQueue() {
   auxRep = iniRep;
   if (iniRep == NULL) {
      return;
   }
   else
   if (auxRep->sigRep != NULL) {
      auxRep = auxRep->sigRep;
      free(iniRep);
      iniRep = auxRep;
   } else {
      free(iniRep);
      iniRep = NULL;
      ultRep = NULL;
   }
}

void deleteMntQueue() {
   auxMaint = iniMaint;
   if (iniMaint == NULL) {
      return;
   }
   else
   if (auxMaint->sigMnt != NULL) {
      auxMaint = auxMaint->sigMnt;
      free(iniMaint);
      iniMaint = auxMaint;
   } else {
      free(iniMaint);
      iniMaint = NULL;
      ultMaint = NULL;
   }
}

void agregarOrdA(){
    auxMecA = new NodeMecA;
    auxMecA->orderMecA = ultRep->orderRep;
    strcpy(auxMecA->statusMecA, "En Reparacion");
    strcpy(auxMecA->descriptionMecA, ultRep->descriptionRep);
    strcpy(auxMecA->plateMecA, ultRep->plateRep);
    strcpy(auxMecA->makeMecA, ultRep->makeRep);
    auxMecA->modelMecA= ultRep->modelRep;
    strcpy(auxMecA->lineMecA,ultRep->lineRep);
    strcpy(auxMecA->typeMecA,"REP");
    strcpy(auxMecA->userMecA,"meca");

    if(iniMecA == NULL){
        iniMecA = ultMecA = auxMecA;
        auxMecA->sigMecA = NULL;
    }else{
        auxMecA->sigMecA=NULL;
        ultMecA->sigMecA=auxMecA;
        ultMecA=auxMecA;
    }
}

void agregarOrdB(){
    auxMecB = new NodeMecB;
    auxMecB->orderMecB = ultRep->orderRep;
    strcpy(auxMecB->statusMecB, "En Reparacion");
    strcpy(auxMecB->descriptionMecB, ultRep->descriptionRep);
    strcpy(auxMecB->plateMecB, ultRep->plateRep);
    strcpy(auxMecB->makeMecB, ultRep->makeRep);
    auxMecB->modelMecB= ultRep->modelRep;
    strcpy(auxMecB->lineMecB,ultRep->lineRep);
    strcpy(auxMecB->typeMecB,"REP");
    strcpy(auxMecB->userMecB,"mecb");

    if(iniMecB == NULL){
        iniMecB = ultMecB = auxMecB;
        auxMecB->sigMecB = NULL;
    }else{
        auxMecB->sigMecB=NULL;
        ultMecB->sigMecB=auxMecB;
        ultMecB=auxMecB;
    }
}

void agregarOrdC(){
    auxMecC = new NodeMecC;
    auxMecC->orderMecC = ultRep->orderRep;
    strcpy(auxMecC->statusMecC, "En Reparacion");
    strcpy(auxMecC->descriptionMecC, ultRep->descriptionRep);
    strcpy(auxMecC->plateMecC, ultRep->plateRep);
    strcpy(auxMecC->makeMecC, ultRep->makeRep);
    auxMecC->modelMecC= ultRep->modelRep;
    strcpy(auxMecC->lineMecC,ultRep->lineRep);
    strcpy(auxMecC->typeMecC,"REP");
    strcpy(auxMecC->userMecC,"mecc");

    if(iniMecC == NULL){
        iniMecC = ultMecC = auxMecC;
        auxMecC->sigMecC = NULL;
    }else{
        auxMecC->sigMecC=NULL;
        ultMecC->sigMecC=auxMecC;
        ultMecC=auxMecC;
    }
}
void agregarOrdX(){
    auxMecX = new NodeMecX;
    auxMecX->orderMecX = ultMaint->order;
    strcpy(auxMecX->statusMecX, "En Mantenimiento");
    strcpy(auxMecX->descriptionMecX, ultMaint->description);
    strcpy(auxMecX->plateMecX, ultMaint->plate);
    strcpy(auxMecX->makeMecX, ultMaint->make);
    auxMecX->modelMecX= ultMaint->model;
    strcpy(auxMecX->lineMecX,ultMaint->line);
    strcpy(auxMecX->typeMecX,"MNT");
    strcpy(auxMecX->userMecX,"mecx");

    if(iniMecX == NULL){
        iniMecX = ultMecX = auxMecX;
        auxMecX->sigMecX = NULL;
    }else{
        auxMecX->sigMecX=NULL;
        ultMecX->sigMecX=auxMecX;
        ultMecX=auxMecX;
    }
}
void agregarOrdY(){
    auxMecY = new NodeMecY;
    auxMecY->orderMecY = ultMaint->order;
    strcpy(auxMecY->statusMecY, "En Mantenimiento");
    strcpy(auxMecY->descriptionMecY, ultMaint->description);
    strcpy(auxMecY->plateMecY, ultMaint->plate);
    strcpy(auxMecY->makeMecY, ultMaint->make);
    auxMecY->modelMecY= ultMaint->model;
    strcpy(auxMecY->lineMecY,ultMaint->line);
    strcpy(auxMecY->typeMecY,"MNT");
    strcpy(auxMecY->userMecY,"mecy");

    if(iniMecY == NULL){
        iniMecY = ultMecY = auxMecY;
        auxMecY->sigMecY = NULL;
    }else{
        auxMecY->sigMecY=NULL;
        ultMecY->sigMecY=auxMecY;
        ultMecY=auxMecY;
    }
}

void agregarOrdZ(){
    auxMecZ = new NodeMecZ;
    auxMecZ->orderMecZ = ultMaint->order;
    strcpy(auxMecZ->statusMecZ, "En Mantenimiento");
    strcpy(auxMecZ->descriptionMecZ, ultMaint->description);
    strcpy(auxMecZ->plateMecZ, ultMaint->plate);
    strcpy(auxMecZ->makeMecZ, ultMaint->make);
    auxMecZ->modelMecZ= ultMaint->model;
    strcpy(auxMecZ->lineMecZ,ultMaint->line);
    strcpy(auxMecZ->typeMecZ,"MNT");
    strcpy(auxMecZ->userMecZ,"mecz");

    if(iniMecZ == NULL){
        iniMecZ = ultMecZ = auxMecZ;
        auxMecZ->sigMecZ = NULL;
    }else{
        auxMecZ->sigMecZ=NULL;
        ultMecZ->sigMecZ=auxMecZ;
        ultMecZ=auxMecZ;
    }
}

void totalOrdenes(){
    system("CLS");
    cout<<"  No. Orden\t"<<"Tipo\t"<<"Fabricante\t"<<"Linea\t"<<"Modelo\t"<<"No. Placa\t"<<"Estado\t"<<"Usuario"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    mostrarRep();
    mostrarMnt();
    mostrarMecA();
    mostrarMecB();
    mostrarMecC();
    mostrarMecX();
    mostrarMecY();
    mostrarMecZ();
    mostrarControl();
    cout<<"----------------------------------------- Ultima Linea-------------------------------------------------"<<endl;
    system("pause");
}

/*-----------------------------------------------------------------------
                            FUNCIONES MECANICOS
-----------------------------------------------------------------------*/

void menuMecanico(){
    int op, menu=404,model, i=0;
    char op1;

    do{
        system("CLS");
        cout<<"--------- Menu Principal --------"<<endl;
        cout<<" Bienvenido: "<< nameGlobal<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<" 1. Ver Ordenes"<<endl;
        cout<<" 2. Terminar Orden"<<endl;
        cout<<" 3. Ver Reporte"<<endl;
        cout<<" 4. Cerrar Sesion"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<" Ingrese la opcion: ";
        cin>>op;

        switch(op){
            case 1:
                /* MOSTRAR ORDENES A TRABAJAR*/
                displayMecanico();
                break;
            case 2:
                /* SACAR ORDEN A CONTROL DE CALIDAD */

                if(strcmp(userGlobal,"meca")==0){
                    if(iniMecA!=NULL){
                        cout<<"\n\nEsta seguro que ya termino la orden No.'"<<iniMecA->orderMecA<<"'?  S/N:";
                        cin>>op1;
                        if((op1=='S') || (op1=='s')){
                           agregarCalidad(); 
                        }
                    }else{
                        cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<" ERROR: No tiene ninguna orden que enviar a control de calidad, cola vacia."<<endl;
                        cout<<"-------------------------------------------------------------------------------"<<endl;
                        system("pause");
                    }
                }else if(strcmp(userGlobal,"mecb")==0){
                    if(iniMecB!=NULL){
                        cout<<"\n\nEsta seguro que ya termino la orden No.'"<<iniMecB->orderMecB<<"'?  S/N:";
                        cin>>op1;
                        if((op1=='S') || (op1=='s')){
                           agregarCalidad(); 
                        }
                    }else{
                        cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<" ERROR: No tiene ninguna orden que enviar a control de calidad, cola vacia."<<endl;
                        cout<<"-------------------------------------------------------------------------------"<<endl;
                        system("pause");
                    }
                }else if(strcmp(userGlobal,"mecc")==0){
                    if(iniMecC!=NULL){
                        cout<<"\n\nEsta seguro que ya termino la orden No.'"<<iniMecC->orderMecC<<"'?  S/N:";
                        cin>>op1;
                        if((op1=='S') || (op1=='s')){
                           agregarCalidad(); 
                        }
                    }else{
                        cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<" ERROR: No tiene ninguna orden que enviar a control de calidad, cola vacia."<<endl;
                        cout<<"-------------------------------------------------------------------------------"<<endl;
                        system("pause");
                    }
                }else if(strcmp(userGlobal,"mecx")==0){
                    if(iniMecX!=NULL){
                        cout<<"\n\nEsta seguro que ya termino la orden No.'"<<iniMecX->orderMecX<<"'?  S/N:";
                        cin>>op1;
                        if((op1=='S') || (op1=='s')){
                           agregarCalidad(); 
                        }
                    }else{
                        cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<" ERROR: No tiene ninguna orden que enviar a control de calidad, cola vacia."<<endl;
                        cout<<"-------------------------------------------------------------------------------"<<endl;
                        system("pause");
                    }
                }else if(strcmp(userGlobal,"mecy")==0){
                    if(iniMecY!=NULL){
                        cout<<"\n\nEsta seguro que ya termino la orden No.'"<<iniMecY->orderMecY<<"'?  S/N:";
                        cin>>op1;
                        if((op1=='S') || (op1=='s')){
                           agregarCalidad(); 
                        }
                    }else{
                        cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<" ERROR: No tiene ninguna orden que enviar a control de calidad, cola vacia."<<endl;
                        cout<<"-------------------------------------------------------------------------------"<<endl;
                        system("pause");
                    }
                }else if(strcmp(userGlobal,"mecz")==0){
                    if(iniMecZ!=NULL){
                        cout<<"\n\nEsta seguro que ya termino la orden No.'"<<iniMecZ->orderMecZ<<"'?  S/N:";
                        cin>>op1;
                        if((op1=='S') || (op1=='s')){
                           agregarCalidad(); 
                        }
                    }else{
                        cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<" ERROR: No tiene ninguna orden que enviar a control de calidad, cola vacia."<<endl;
                        cout<<"-------------------------------------------------------------------------------"<<endl;
                        system("pause");
                    }
                }

                                   
                break;

            case 3:
                /* VER REPORTE DE PUNTOS, CANT ODRS EN REPARACION, CANT ORDRS EN QA, CANT ORDRS LISTAS PARA RECO, TOT VEHICULOS REVISADOS */
                
            case 4:                
                repartirOrdenRep();
                menu = opcionSalir();
                break;
            default:
                system("CLS");
                cout<<" ERROR: La opcion ingresada no es valida, por favor intente de nuevo."<<endl;
                system("pause");
                break;
        }
    }while(menu==404);
}

void agregarCalidad(){
    if(strcmp(userGlobal,"meca")==0){
        system("CLS");
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<" Numero de Orden '"<<iniMecA->orderMecA<<"' ingresada Exitosamente a Control de calidad. "<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        system("pause");
        agregarOrdCalidad(iniMecA->orderMecA, iniMecA->descriptionMecA, iniMecA->plateMecA, iniMecA->makeMecA, iniMecA->modelMecA, iniMecA->lineMecA, iniMecA->typeMecA);
        deleteMecA();
    }else if(strcmp(userGlobal,"mecb")==0){
        system("CLS");
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<" Numero de Orden '"<<iniMecB->orderMecB<<"' ingresada Exitosamente a Control de calidad. "<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        system("pause");
        agregarOrdCalidad(iniMecB->orderMecB, iniMecB->descriptionMecB, iniMecB->plateMecB, iniMecB->makeMecB, iniMecB->modelMecB, iniMecB->lineMecB, iniMecB->typeMecB);
        deleteMecB();
    }else if(strcmp(userGlobal,"mecc")==0){
        system("CLS");
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<" Numero de Orden '"<<iniMecC->orderMecC<<"' ingresada Exitosamente a Control de calidad. "<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        system("pause");
        agregarOrdCalidad(iniMecC->orderMecC, iniMecC->descriptionMecC, iniMecC->plateMecC, iniMecC->makeMecC, iniMecC->modelMecC, iniMecC->lineMecC, iniMecC->typeMecC);
        deleteMecC();
    }else if(strcmp(userGlobal,"mecx")==0){
        system("CLS");
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<" Numero de Orden '"<<iniMecX->orderMecX<<"' ingresada Exitosamente a Control de calidad. "<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        system("pause");
        agregarOrdCalidad(iniMecX->orderMecX, iniMecX->descriptionMecX, iniMecX->plateMecX, iniMecX->makeMecX, iniMecX->modelMecX, iniMecX->lineMecX, iniMecX->typeMecX);
        deleteMecX();
    }else if(strcmp(userGlobal,"mecy")==0){
        system("CLS");
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<" Numero de Orden '"<<iniMecY->orderMecY<<"' ingresada Exitosamente a Control de calidad. "<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        system("pause");
        agregarOrdCalidad(iniMecY->orderMecY, iniMecY->descriptionMecY, iniMecY->plateMecY, iniMecY->makeMecY, iniMecY->modelMecY, iniMecY->lineMecY, iniMecY->typeMecY);
        deleteMecY();
    }else if(strcmp(userGlobal,"mecz")==0){
        system("CLS");
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<" Numero de Orden '"<<iniMecZ->orderMecZ<<"' ingresada Exitosamente a Control de calidad. "<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        system("pause");
        agregarOrdCalidad(iniMecZ->orderMecZ, iniMecZ->descriptionMecZ, iniMecZ->plateMecZ, iniMecZ->makeMecZ, iniMecZ->modelMecZ, iniMecZ->lineMecZ, iniMecZ->typeMecZ);
        deleteMecZ();
    }
}

void agregarOrdCalidad(int orden, char description[100], char plate[8], char make[15], int model, char line[15], char type[4]){
    auxControl = new ControlCalidad;
    auxControl->orderControl = orden;
    strcpy(auxControl->statusControl, "En Control de Calidad");
    strcpy(auxControl->descriptionControl, description);
    strcpy(auxControl->plateControl, plate);
    strcpy(auxControl->makeControl, make);
    auxControl->modelControl= model;
    strcpy(auxControl->lineControl, line);
    strcpy(auxControl->typeControl,type);
    strcpy(auxControl->mecanicoControl, userGlobal);

    if(iniControl == NULL){
        iniControl = ultControl = auxControl;
        auxControl->sigControl = NULL;
    }else{
        auxControl->sigControl=NULL;
        ultControl->sigControl=auxControl;
        ultControl=auxControl;
    }
}

void deleteMecA() {
   auxMecA = iniMecA;
   if (iniMecA == NULL) {
      return;
   }
   else
   if (auxMecA->sigMecA != NULL) {
      auxMecA = auxMecA->sigMecA;
      free(iniMecA);
      iniMecA = auxMecA;
      countNodeMecA--;
   } else {
      free(iniMecA);
      iniMecA = NULL;
      ultMecA = NULL;
      countNodeMecA--;
   }
}
void deleteMecB() {
   auxMecB = iniMecB;
   if (iniMecB == NULL) {
      return;
   }
   else
   if (auxMecB->sigMecB != NULL) {
      auxMecB = auxMecB->sigMecB;
      free(iniMecB);
      iniMecB = auxMecB;
      countNodeMecB--;
   } else {
      free(iniMecB);
      iniMecB = NULL;
      ultMecB = NULL;
      countNodeMecB--;
   }
}
void deleteMecC() {
   auxMecC = iniMecC;
   if (iniMecC == NULL) {
      return;
   }
   else
   if (auxMecC->sigMecC != NULL) {
      auxMecC = auxMecC->sigMecC;
      free(iniMecC);
      iniMecC = auxMecC;
      countNodeMecC--;
   } else {
      free(iniMecC);
      iniMecC = NULL;
      ultMecC = NULL;
      countNodeMecC--;
   }
}
void deleteMecX() {
   auxMecX = iniMecX;
   if (iniMecX == NULL) {
      return;
   }
   else
   if (auxMecX->sigMecX != NULL) {
      auxMecX = auxMecX->sigMecX;
      free(iniMecX);
      iniMecX = auxMecX;
      countNodeMecX--;
   } else {
      free(iniMecX);
      iniMecX = NULL;
      ultMecX = NULL;
      countNodeMecX--;
   }
}
void deleteMecY() {
   auxMecY = iniMecY;
   if (iniMecY == NULL) {
      return;
   }
   else
   if (auxMecY->sigMecY != NULL) {
      auxMecY = auxMecY->sigMecY;
      free(iniMecY);
      iniMecY = auxMecY;
      countNodeMecY--;
   } else {
      free(iniMecY);
      iniMecY = NULL;
      ultMecY = NULL;
      countNodeMecY--;
   }
}
void deleteMecZ() {
   auxMecZ = iniMecZ;
   if (iniMecZ == NULL) {
      return;
   }
   else
   if (auxMecZ->sigMecZ != NULL) {
      auxMecZ = auxMecZ->sigMecZ;
      free(iniMecZ);
      iniMecZ = auxMecZ;
      countNodeMecZ--;
   } else {
      free(iniMecZ);
      iniMecZ = NULL;
      ultMecZ = NULL;
      countNodeMecZ--;
   }
}

void displayMecanico(){
    if(strcmp(userGlobal,"meca")==0){
        auxMecA=iniMecA;
        if (iniMecA==NULL){
            cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<" No tiene ninguna orden que trabajar, cola vacia."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            system("pause");
        }else{ 
            system("CLS");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<" \tOrdenes: "<<nameGlobal<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            while(auxMecA!=NULL){
                cout<<" Numero de Orden: "<<auxMecA->orderMecA<<endl;
                cout<<" Tipo: "<<auxMecA->typeMecA<<endl;
                cout<<" Marca: "<<auxMecA->makeMecA<<endl;
                cout<<" Linea: "<<auxMecA->lineMecA<<endl;
                cout<<" Modelo: "<<auxMecA->modelMecA<<endl;
                cout<<" Placa: "<<auxMecA->plateMecA<<endl;
                cout<<" Estado: "<<auxMecA->statusMecA<<endl;
                cout<<" Descripcion: "<<auxMecA->descriptionMecA<<endl;
                auxMecA=auxMecA->sigMecA;
                cout<<"--------------------------------------------------------"<<endl;
            }
            system("pause");
        }
    }else if(strcmp(userGlobal,"mecb")==0){
        auxMecB=iniMecB;
        if (iniMecB==NULL){
            cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<" No tiene ninguna orden que trabajar, cola vacia."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            system("pause");
        }else{ 
            system("CLS");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<" \tOrdenes: "<<nameGlobal<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            while(auxMecB!=NULL){
                cout<<" Numero de Orden: "<<auxMecB->orderMecB<<endl;
                cout<<" Tipo: "<<auxMecB->typeMecB<<endl;
                cout<<" Marca: "<<auxMecB->makeMecB<<endl;
                cout<<" Linea: "<<auxMecB->lineMecB<<endl;
                cout<<" Modelo: "<<auxMecB->modelMecB<<endl;
                cout<<" Placa: "<<auxMecB->plateMecB<<endl;
                cout<<" Estado: "<<auxMecB->statusMecB<<endl;
                cout<<" Descripcion: "<<auxMecB->descriptionMecB<<endl;
                auxMecB=auxMecB->sigMecB;
                cout<<"--------------------------------------------------------"<<endl;
            }
            system("pause");
        }
    }else if(strcmp(userGlobal,"mecc")==0){
        auxMecC=iniMecC;
        if (iniMecC==NULL){
            cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<" No tiene ninguna orden que trabajar, cola vacia."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            system("pause");
        }else{ 
            system("CLS");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<" \tOrdenes: "<<nameGlobal<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            while(auxMecC!=NULL){
                cout<<" Numero de Orden: "<<auxMecC->orderMecC<<endl;
                cout<<" Tipo: "<<auxMecC->typeMecC<<endl;
                cout<<" Marca: "<<auxMecC->makeMecC<<endl;
                cout<<" Linea: "<<auxMecC->lineMecC<<endl;
                cout<<" Modelo: "<<auxMecC->modelMecC<<endl;
                cout<<" Placa: "<<auxMecC->plateMecC<<endl;
                cout<<" Estado: "<<auxMecC->statusMecC<<endl;
                cout<<" Descripcion: "<<auxMecC->descriptionMecC<<endl;
                auxMecC=auxMecC->sigMecC;
                cout<<"--------------------------------------------------------"<<endl;
            }
            system("pause");
        }        
    }else if(strcmp(userGlobal,"mecx")==0){
        auxMecX=iniMecX;
        if (iniMecX==NULL){
            cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<" No tiene ninguna orden que trabajar, cola vacia."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            system("pause");
        }else{ 
            system("CLS");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<" \tOrdenes: "<<nameGlobal<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            while(auxMecX!=NULL){
                cout<<" Numero de Orden: "<<auxMecX->orderMecX<<endl;
                cout<<" Tipo: "<<auxMecX->typeMecX<<endl;
                cout<<" Marca: "<<auxMecX->makeMecX<<endl;
                cout<<" Linea: "<<auxMecX->lineMecX<<endl;
                cout<<" Modelo: "<<auxMecX->modelMecX<<endl;
                cout<<" Placa: "<<auxMecX->plateMecX<<endl;
                cout<<" Estado: "<<auxMecX->statusMecX<<endl;
                cout<<" Descripcion: "<<auxMecX->descriptionMecX<<endl;
                auxMecX=auxMecX->sigMecX;
                cout<<"--------------------------------------------------------"<<endl;
            }
            system("pause");
        }
    }else if(strcmp(userGlobal,"mecy")==0){
        auxMecY=iniMecY;
        if (iniMecY==NULL){
            cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<" No tiene ninguna orden que trabajar, cola vacia."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            system("pause");
        }else{ 
            system("CLS");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<" \tOrdenes: "<<nameGlobal<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            while(auxMecY!=NULL){
                cout<<" Numero de Orden: "<<auxMecY->orderMecY<<endl;
                cout<<" Tipo: "<<auxMecY->typeMecY<<endl;
                cout<<" Marca: "<<auxMecY->makeMecY<<endl;
                cout<<" Linea: "<<auxMecY->lineMecY<<endl;
                cout<<" Modelo: "<<auxMecY->modelMecY<<endl;
                cout<<" Placa: "<<auxMecY->plateMecY<<endl;
                cout<<" Estado: "<<auxMecY->statusMecY<<endl;
                cout<<" Descripcion: "<<auxMecY->descriptionMecY<<endl;
                auxMecY=auxMecY->sigMecY;
                cout<<"--------------------------------------------------------"<<endl;
            }
            system("pause");
        }
    }else if(strcmp(userGlobal,"mecz")==0){
        auxMecZ=iniMecZ;
        if (iniMecZ==NULL){
            cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<" No tiene ninguna orden que trabajar, cola vacia."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            system("pause");
        }else{ 
            system("CLS");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<" \tOrdenes: "<<nameGlobal<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            while(auxMecZ!=NULL){
                cout<<" Numero de Orden: "<<auxMecZ->orderMecZ<<endl;
                cout<<" Tipo: "<<auxMecZ->typeMecZ<<endl;
                cout<<" Marca: "<<auxMecZ->makeMecZ<<endl;
                cout<<" Linea: "<<auxMecZ->lineMecZ<<endl;
                cout<<" Modelo: "<<auxMecZ->modelMecZ<<endl;
                cout<<" Placa: "<<auxMecZ->plateMecZ<<endl;
                cout<<" Estado: "<<auxMecZ->statusMecZ<<endl;
                cout<<" Descripcion: "<<auxMecZ->descriptionMecZ<<endl;
                auxMecZ=auxMecZ->sigMecZ;
                cout<<"--------------------------------------------------------"<<endl;
            }
            system("pause");
        }
    }
}


/*-----------------------------------------------------------------------
                            FUNCIONES CONTROL DE CALIDAD
-----------------------------------------------------------------------*/

//Procedimiento para menu de control de calidad 
void MenuControlDeCalidad(){
   int opControl, menu=404, i=0, opBuscar;
   char op;
    do{
        system("CLS");
        cout<<"            Control de Calidad            \n";
        cout<<"|----------------------------------------|\n";
        cout<<"|  1.          Buscar Orden              |\n";
        cout<<"|  2.          Validar Orden             |\n";
        cout<<"|  3.    Salir de Control de Calidad     |\n";
        cout<<"|----------------------------------------|\n";
        cout<<"Ingrese codigo del menu: ";
        cin>>opControl;

        switch(opControl){

            case 1:
                /* BUSCAR OREN */
                system("CLS");
                cout<<"-------------------------------------"<<endl;
                cout<<"     Busqueda de Orden"<<endl;
                cout<<"-------------------------------------"<<endl;
                cout<<" Ingrese el numero de orden: ";
                cin>>opBuscar;

                buscarOrdenControl(opBuscar);
                break;

             case 2:
                
                break;

             case 3:
                menu=opcionSalir();
                break;

             default:
                cout<<"\nERROR: Opcion ingresada no es valida, intente de nuevo... \n";
                system("pause");            
                break;
        }
   }while(menu==404);
} 

void buscarOrdenControl(int opBuscar){
    char op1;
    bool found=false;
    
    auxControl=iniControl;

    if (auxControl!=NULL){
        while(auxControl!=NULL){
            if(opBuscar == auxControl->orderControl){
                cout<<endl<<endl<<"--------------------------------------------------------"<<endl;
                cout<<" Numero de Orden: "<<auxControl->orderControl<<endl;
                cout<<" Tipo: "<<auxControl->typeControl<<endl;
                cout<<" Marca: "<<auxControl->makeControl<<endl;
                cout<<" Linea: "<<auxControl->lineControl<<endl;
                cout<<" Modelo: "<<auxControl->modelControl<<endl;
                cout<<" Placa: "<<auxControl->plateControl<<endl;
                cout<<" Mecanico: "<<auxControl->mecanicoControl<<endl;
                cout<<" Estado: "<<auxControl->statusControl<<endl;
                cout<<" Descripcion: "<<auxControl->descriptionControl<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cout<<" Desea dar Salida a esta orden? S/N: ";
                cin>>op1;

                if((op1=='S') || (op1=='s')){
                    cout<<endl<<"--------------------------------------------------------"<<endl;
                    cout<<" Esta orden cumple con los estandares de calidad? S/N: ";
                    cin>>op1;

                    if((op1=='S') || (op1=='s')){
                        //mandar a lista salida
                        //eliminar de lista control
                    }else if((op1=='N') || (op1=='n')){
                        //madar a cola de incalidad
                        //eliminar de lista control
                    }else{
                        cout<<" ERROR: Opcion ingresada es invalida"<<endl;
                        system("pause");
                    }
                }
                found=true;
                return;
            }
            auxControl=auxControl->sigControl;
        }
        if(auxControl==NULL && found==false){
            cout<<endl<<endl<<"--------------------------------------------------------------------------------------------"<<endl;
            cout<<" No se encontro la orden No.'"<<opBuscar<<"'. La orden no se encuentra en control de calidad."<<endl;
            cout<<"--------------------------------------------------------------------------------------------"<<endl;
            system("pause");
        }else{
            cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<" ERROR: No existe ninguna orden en control de Calidad, lista vacia."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            system("pause");
        }
    }
}
