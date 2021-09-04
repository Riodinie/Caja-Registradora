#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <vector>
//contraseña
#define USER "ZAFRUTA"
#define PASS "ADM"
//Ascii
#define ENTER 13 // espacio
#define BACKSPACE 8 //borrar

using namespace std;
//Para los cuadros
void total();
void gotoxy(int x,int y);
void cuadro(int x1, int y1, int x2, int y2);

//Globales
string dia_semana_,dia_numero,mes_,anio,hora,minutos,segundos;
string nom,ape,dir,telf,auxnom,aux,auxape,auxdir,auxtelf,genero,auxgenero;
char des[30],auxdes[30];
string nom_A,auxnom_A;
float auxcost,auxpre,auxiva;
char a;
int auxcc,cc,cod,edad,auxcod,cant,i=11,j,auxedad;
float cost, pre, iva,m,st,sst,tt,auxsst;
bool encontrado=false;
char auxclient[10];

//
string Login();
void escribir();
void archivos();
void tienda();
void salir();
void menu();
void segundomenu();
void verdaderomenu();
void clientes();
void buscarcliente();
void inventario();
void facturacion();
void modificar();
void editar_I();
void archivos2();
void eliminar();
void eliminar_I();
void Lista_Facturas();
void Eliminar_F();

//Para cambiar el color de la pantalla y la letra
int main(){
system ("COLOR B0");
cuadro(0,0,118,27);
cuadro(11,3,100,25);
total();//llamado a la funcion
system ("pause");
return 0;

}

//contraseña
void total(){
bool ingresa = false;
string usuario,password;
int contador = 0;
  do{
  //forma los cuadros de la pantalla
  cuadro(0,0,118,27);
  cuadro(11,3,100,25);
  gotoxy(50,3);cout<<"CASH REGISTER"<<endl;
  gotoxy(35,6),cout<<"Usuario: ";
  getline(cin, usuario);
  char caracter;
  gotoxy(35,8),cout <<"Password: ";
  caracter = getch();
  password="";
    //codigo para ***
  while(caracter!=13){ //ascii codigo
    if(caracter!=8){
    password.push_back(caracter);
    cout<<"*";
    }else{
    if(password.length()> 0){
    cout<<"\b \b";
    password=password.substr(0, password.length() -1);
    }
  }
  caracter=getch();
 }
     
        
    if(usuario== USER && password== PASS){
    ingresa = true;
    }else{
    Beep(350,500);
    Beep(350,500);
    gotoxy(35,10),cout<<"EL usuario y/o password son incorrectos"<<endl;
    cin.get();
    contador++;
    system("cls");
    cuadro(0,0,118,27);
	cuadro(11,3,100,25);
    }
  }while(ingresa == false && contador < 3);
 
  if(ingresa == false){
  gotoxy(35,12),cout<<"USTED NO PUDO INGRESAR AL SISTEMA."<<endl;
  }else{
  gotoxy(35,12),cout<<"BIENVENIDO AL SISTEMA."<<endl; 
  Beep(1300, 1000);//pitido
  cout<<"\t\t";system("PAUSE");
  system("cls");
  cuadro(0,0,118,27);
  cuadro(1,1,117,3);
  segundomenu();
      
  }


}

//menu
void segundomenu(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
int op=0,op_1=0,op_2=0,op_3=0;
 
 do{
 gotoxy(50,2);cout<<"     ZAFRUTA"<<endl;
 gotoxy(20,7),cout<<"1.CLIENTES.";
 gotoxy(20,9),cout<<"2.INVENTARIO.";
 gotoxy(20,11),cout<<"3.FACTURAS.";
 gotoxy(20,13),cout<<"4.SALIR.";
 gotoxy(20,15),cout<<"INGRESE LA OPCION: ";cin>>op;
 system("cls");
 cuadro(0,0,118,27);
 cuadro(1,1,117,3);
   
  switch(op){
  case 1:
    do{
 
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    gotoxy(50,2);cout<<"     ZAFRUTA     "<<endl;
    gotoxy(50,5),cout<<"_____CLIENTES_____";
    gotoxy(20,7),cout<<"1.BASE DE DATOS (CLIENTES).";
    gotoxy(20,9),cout<<"2.REGISTRAR CLIENTE.";
    gotoxy(20,11),cout<<"3.BUSCAR CLIENTE.";
    gotoxy(20,13),cout<<"4.EDITAR INFORMACION DE CLIENTE.";
    gotoxy(20,15),cout<<"5.ELIMINAR CLIENTE.";
    gotoxy(20,17),cout<<"6.VOLVER";
    gotoxy(20,19),cout<<"INGRESE LA OPCION: ";cin>>op_1;
   
    switch(op_1){
  case 1:
  archivos();//SE LLAMA LA FUNCION
  break;
  case 2:
   escribir();
  break;
  case 3:
  buscarcliente();
  break;
  case 4:
  modificar();
  break;
  case 5:
  eliminar();
  break;
  case 6:
  segundomenu();
  break;
  default:
  	Beep(350,500);
    Beep(350,500);
  gotoxy(5,5),cout<<"La opcion que ingreso no existe. "<<endl; 
   }

  }while(op!=6); 
  break;
  ///////////////////
  case 2:
  do{
 
   system("cls");
   cuadro(0,0,118,27);
   cuadro(1,1,117,3);
   gotoxy(50,2);cout<<"      ZAFRUTA"<<endl;
   gotoxy(30,5),cout<<"_____INVENTARIO_____";
   gotoxy(20,7),cout<<"1.AGREGAR A INVENTARIO.";
   gotoxy(20,9),cout<<"2.EDITAR ARTICULO.";
   gotoxy(20,11),cout<<"3.ELIMINAR ARTICULO.";
   gotoxy(20,13),cout<<"4.VER INVENTARIO.";
   gotoxy(20,15),cout<<"5.VOLVER";
   gotoxy(20,17),cout<<"INGRESE LA OPCION: ";cin>>op_2;
   
    switch(op_2){
  case 1:
  inventario();
  break;
  case 2:
  editar_I();
  break;
  case 3:
  eliminar_I();
  break;
  case 4:
  tienda();
  break;
  case 5:
  segundomenu();
  break;
  default:
  	Beep(350,500);
    Beep(350,500);
  gotoxy(5,5),cout<<"La opcion que ingreso no existe. "<<endl; 
   }

  }while(op!=5);

  break;
  ////////////////////////////////////
  case 3:
  do{
 
   system("cls");
   cuadro(0,0,118,27);
   cuadro(1,1,117,3);
   gotoxy(50,2);cout<<"     ZAFRUTA"<<endl;
   gotoxy(30,5),cout<<"_____FACTURA_____";
   gotoxy(20,7),cout<<"1.FACTURAR.";
   gotoxy(20,9),cout<<"2.VER FACTURAS.";
   gotoxy(20,11),cout<<"3.REGISTRO DE FACTURAS.";
   gotoxy(20,13),cout<<"4.ELIMINAR FACTURA.";
   gotoxy(20,15),cout<<"5.VOLVER";
   gotoxy(20,17),cout<<"INGRESE LA OPCION: ";cin>>op_2;
   
    switch(op_2){
  case 1:
  facturacion();
  break;
  case 2:
  archivos2();
  break;
  case 3:
  Lista_Facturas();
  break;
  case 4:
  Eliminar_F();
  break;
  case 5:
  segundomenu();
  break;
  default:
  	   Beep(350,500);
       Beep(350,500);
  gotoxy(5,5),cout<<"La opcion que ingreso no existe. "<<endl; 
   }

  }while(op!=5);

  break;
  /////////////////////////////////7
  case 4:
  system("cls");
  cuadro(0,0,118,27);
  cuadro(1,1,117,3);
  salir();
  break;
  default:
   Beep(350,500);
   Beep(350,500);
  gotoxy(5,5),cout<<"La opcion que ingreso no existe. "<<endl; 
   }
 
  }while(op!=4);
}

//Registrar clientes
void escribir(){
system("cls");//limpiar pantalla
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ifstream consulta;//
ofstream escritura;//
bool repetido=false;
escritura.open("clientes.txt",ios::out|ios::app);
consulta.open("clientes.txt",ios::in);
   if(escritura.is_open() && consulta.is_open()){   
   cout<<"\t\t\t\t";
   gotoxy(50,2);cout<<"REGISTRAR CLIENTE                  \n";
   cout<<"\t\t\t\t\n\n";
   cout<<"\t\tINGRESE LA CEDULA DE CIUDADANIA: ";
   cin>>auxcc;
   consulta>>cc;
   while(!consulta.eof()){
   consulta>>nom>>ape>>edad>>genero>>dir>>telf;
    if(cc==auxcc){            
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    cout<<"\t\t\t\t\n\n"; 
    cout<<"\t\t\t\t                  CLIENTE YA REGISTRADO                  \n"<<endl;
    system("PAUSE");
    repetido=true;
     }
   consulta>>cc;
   }
    if(repetido==false){
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    cout<<"\t\t\t\t\n\n";
    cout<<"\t\tNOMBRE: ";
    cin>>nom;
    cout<<"\t\tAPELLIDO: ";
    cin>>ape;
    cout<<"\t\tEDAD: ";
    cin>>edad;
    cout<<"\t\tGENERO: ";
    cin>>genero;
    cout<<"\t\tDIRECCION: ";
    cin>>dir;
    cout<<"\t\tTELEFONO: ";
    cin>>telf;
    escritura<<auxcc<<" "<<nom<<" "<<ape<<" "<<edad<<" "<<genero<<" "<<dir<<" "<<telf<<endl;
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    Beep(1300, 1000);
    cout<<"\t\tRegistro Agregado con exito."<<endl;
    system("PAUSE");
   }

   }else{
   system("cls");
   cout<<"\t\t\t"<<endl;
   Beep(350,500);
   Beep(350,500);
   cout<<"\t\t\t Error, el Archivo No se Pudo Abrir o No ha sido Creado   \n"<<endl;
   cout<<"\n\n\n\n\n\n"<<endl;
   system("PAUSE");
   }
escritura.close();
consulta.close();
}//Fin funcion CLIENTES

//Ver el .txt de los cliente
void archivos(){
system("cls");
cuadro(1,1,117,3);
ifstream archivo;
string texto;
archivo.open("clientes.txt",ios::in);//ABRIR EL ARCHIVO PARA VER EN PANTALLA
gotoxy(50,2),cout<<"VISUALIZAR CLIENTES"<<endl;
  if(archivo.fail()){
  cout<<"\t\t\t\t\n\n";
  cout<<"\tNo Se pudo abrir el archivo. "<<endl;
  cout<<"\n";
  getch();
  segundomenu();
  system("cls");
  cuadro(0,0,118,27);
  cuadro(1,1,117,3);
 }
 archivo>>cc;	
  while(!archivo.eof()){ //MIENTRAS NO SEA EL FINAL DE ARCHIVO
  archivo>>nom>>ape>>edad>>genero>>dir>>telf;
  cout<<"\t\t\t\t"<<endl;
  cout<<"\t\tNOMBRE: "<<nom<<endl;
  cout<<"\t\tAPELLIDO: "<<ape<<endl;
  cout<<"\t\tEDAD: "<<edad<<endl;
  cout<<"\t\tCLIENTE RECIENTE."<<endl;
  cout<<"\t\t_____________"<<endl;
  archivo>>cc;
 }
archivo.close();
system("pause");
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
}

//Facturar
void facturacion(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
int num=0,paga=0;
int suma=0;
char codigo[50];
char  ayuda[60];
ofstream factura;
ofstream factura2;
ifstream codfact;
ofstream escritura;
ifstream consulta1;
ifstream consulta2; 
bool repetido=false;
//codigo que permite poner la fecha y la hora local
time_t now = time(0);
tm * time = localtime(&now);

vector<string> dia_semana;
dia_semana.push_back("Domingo");
dia_semana.push_back("Lunes");
dia_semana.push_back("Martes");
dia_semana.push_back("Miercoles");
dia_semana.push_back("Jueves");
dia_semana.push_back("Viernes");
dia_semana.push_back("Sabado");

vector<string> mes;
mes.push_back("Enero");
mes.push_back("Febrero");
mes.push_back("Marzo");
mes.push_back("Abril");
mes.push_back("Mayo");
mes.push_back("Junio");
mes.push_back("Julio");
mes.push_back("Agosto");
mes.push_back("Septiembre");
mes.push_back("Octubre");
mes.push_back("Noviembre");
mes.push_back("Diciembre");

int year = 1900 + time->tm_year;
//////////
//Para crear una factura se necesita tener datos del cliente,y por lo menos un producto agregado
escritura.open("ventas.txt",ios::out|ios::app);
consulta1.open("clientes.txt",ios::in);
consulta2.open("inventario.txt",ios::in);
   if(escritura.is_open() && consulta1.is_open() && consulta2.is_open()){    
   gotoxy(50,2);cout<<"FACTURAR\n";
   cout<<"\t\t\t\t\n\n";
   cout<<"\t\tINGRESE SU CEDULA DE CIUDADANIA: ";
   cin>>auxcc;
   consulta1>>cc;
    while(!consulta1.eof()){
    consulta1>>nom>>ape>>edad>>genero>>dir>>telf;
        if(cc==auxcc){            
        system("cls");
        cuadro(0,0,118,27);
        cuadro(1,1,117,3);
        gotoxy(50,2);
        cout<<"   ZAFRUTA";
        gotoxy(1,4);
        cout<<" CLIENTE: "<<nom<<" "<<ape<<endl;
        gotoxy(1,5);
        cout<<" DIRECCION: "<<dir;
        gotoxy(1,6);
        cout<<" TELEFONO: "<<telf;
        gotoxy(1,8);
        cout<<"-----------------------------------------------------------------------------------------------------------------";
        gotoxy(1,9);
        cout<<"| CODIGO    | DESCRIPCION |                            | CANT | PRECIO U | PRECIO T |\n";
        gotoxy(1,10);
        cout<<"-----------------------------------------------------------------------------------------------------------------\n";
          while(i>=11){
          if(i >= 12){
          consulta2.open("inventario.txt",ios::in);//busca en el archivo de los productos
          	}
          gotoxy(1,i);cin>>auxcod;
          while(!consulta2.eof()){
          consulta2>>cod;
          consulta2>>des>>cost>>pre>>iva;
            if(auxcod==cod){
            gotoxy(1,i);
            cout<<cod;
            gotoxy(16,i);
            cout<<des;
            gotoxy(60,i);
            cin>>cant;
            gotoxy(70,i);
            cout<<pre;
            m=cant*pre;
            st=m;
            gotoxy(80,i);
            cout<<st<<endl;
            sst=sst+st;
            iva=sst*12/100;
            tt=iva+sst;
            gotoxy(90,4);
            cout<<"SUB-TOTAL: "<<endl;
            gotoxy(101,4);
            cout<<sst<<endl;
            gotoxy(96,5);
            cout<<"IVA: "<<endl;
            gotoxy(101,5);
            cout<<iva<<endl;
            gotoxy(94,6);
            cout<<"TOTAL: "<<endl;
            gotoxy(101,6);
            cout<<tt<<endl;
            gotoxy(0,22);
            gotoxy(101,i);
            cin>>a;//salir o no
            i++;
             if(i==12){///guardando la factura en el punto .txt
             escritura<<"\t"<<endl;
             escritura<<"H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H\n"<<endl;
             escritura<<"\t CLIENTE: "<<nom<<" "<<ape<<endl;
             escritura<<"\t DIRECCION: "<<dir<<endl;
             escritura<<"\t TELEFONO: "<<telf<<endl;
             escritura<<"\t FECHA DE CREACION: "<<dia_semana[time->tm_wday]<<" "<<time->tm_mday<<" de "<<mes[time->tm_mon]<<" del "<<year<<endl;
             escritura<<"\t HORA DE CREACION: "<<time->tm_hour<<":"<<time->tm_min<<":"<<time->tm_sec<<endl;
                
             escritura<<" | CODIGO    | DESCRIPCION |                            | CANT | PRECIO U | PRECIO T |\n";
        
                
            }
             escritura<<"  "<<cod<<"        "<<des<<"                                   "<<cant<<"      "<<pre<<"     "<<m<<endl;
                if(a =='S'){
              	escritura<<"-----------------------------------------------------------------------------------------------------------------\n";
              	escritura<<"\tSUB-TOTAL: "<<sst<<endl;
                escritura<<"\tIVA: "<<iva<<endl;
                escritura<<"\tTOTAL: "<<tt<<endl;
                escritura<<"H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H-H\n"<<endl;
                escritura.close();
                consulta1.close();
                consulta2.close();
                factura.open("ayudante.txt",ios::out|ios::app);//para el nombre personlisado
                factura2.open("Registro_Lista.csv",ios::out|ios::app);//para el registro de facturas
                factura<<nom<<"_"<<ape<<time->tm_mday<<mes[time->tm_mon]<<year<<time->tm_hour<<time->tm_min<<".txt";
                factura2<<";"<<"NOMBRE DE LA FACTURA: "<<nom<<"_"<<ape<<time->tm_mday<<mes[time->tm_mon]<<year<<time->tm_hour<<time->tm_min<<";";
				factura2<<";"<<"FECHA: "<<dia_semana[time->tm_wday]<<" "<<time->tm_mday<<" de "<<mes[time->tm_mon]<<" del "<<year<<";";
                factura2<<";"<<"HORA: "<<time->tm_hour<<":"<<time->tm_min<<":"<<time->tm_sec<<";"<<"_______________________________________"<<endl;
                factura.close();
                factura2.close();
                codfact.open("ayudante.txt",ios::in);
                codfact>>ayuda;
                rename("ventas.txt",ayuda);//cambia el nombre que se  guardo en el ayudante.txt
                cout<<" "<<endl;
                cout<<"\tEl cliente paga:"<<endl;
                cout<<"\t";cin>>paga;
                cout<<"\tTotal del vuelto:"<<paga-tt<<endl;
                cout<<" "<<endl;
                Beep(1300, 1000);
                cout<<"\tLa fatura se guardo con exito."<<endl;
                cout<<"\tLa factura se registro como "<<ayuda;
	            codfact.close();
	            remove("ayudante.txt");//se elimina
              	getch();
              	segundomenu();
              	system("cls");
              	cuadro(0,0,118,27);
                cuadro(1,1,117,3);
                 }   
            
              }
               
            }
          consulta2.close();
        }//
           
		  }
               
            consulta1>>cc;
           }
        cout<<"\t\t"<<endl;
           Beep(350,500);
           Beep(350,500);
        cout<<"\tCliente no se encuentra registrado."<<endl;
        cout<<"\t\t"<<endl;
        cout<<"\tSi usted ingreso mal la cedula, por favor intentelo de nuevo."<<endl;
        system("PAUSE");
        system("cls");
        cuadro(0,0,118,27);
        cuadro(1,1,117,3);
        segundomenu();
   }else{
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\n";
    Beep(350,500);
    Beep(350,500);
    cout<<"\t\t\t\t  Error, el Archivo No se Pudo Abrir o No ha sido Creado   \n";
    cout<<"\t\t\t\t\n";
    cout<<"\n\n\n\n\n\n"<<endl;
    system("PAUSE");
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
   }
   
}
//Salir
void salir(){
cout<<"\t\t\t\t\n\n";
cout<<"\t\tPROGRAMA FINALIZADO, GRACIAS POR PREFERIRNOS."<<endl;
exit(1);
}
//Ver inventario
void tienda(){
system("cls");
cuadro(1,1,117,3);
int id;
char descripcion[50];
int costo, precio;
float iva;
fstream archivo;
archivo.open("inventario.txt",ios::in);
	if(archivo.fail()){
    cout<<"\t\t\t\t\n\n";
    Beep(350,500);
    Beep(350,500);
    cout<<"\tNo Se pudo abrir el archivo. "<<endl;
    cout<<"\n";
    getch();
    segundomenu();
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    }
cout<<"\t\t\t\t"<<endl;
gotoxy(50,2);cout<<"LISTA DE ARTICULOS\n";
archivo>>id;
	while ( !archivo.eof() ){//Revisa los archivos hasta el final
	archivo>>descripcion>>costo>>precio>>iva;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\tID: "<<id<<endl;
	cout<<"\t\tDESCRIPCION: "<<descripcion<<endl;
	cout<<"\t\tCOSTO: "<<costo<<endl;
	cout<<"\t\tPRECIO: "<<precio<<endl;
	cout<<"\t\tIVA: "<<iva<<endl;
	cout<<"\t\t____________"<<endl;
	archivo>>id;
	}
archivo.close();
system("pause");
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
}


void buscarcliente(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ifstream lectura;//Creamos la variable de tipo lectura
lectura.open("clientes.txt",ios::out|ios::in);//Abrimos el archivo
   //validando la apertura del archivo
encontrado=false;
   if(lectura.is_open()){
   gotoxy(50,2);cout<<"BUSCAR CLIENTES\n";
    cout<<"\t\t\t\t\n";
    cout<<"\t\tCEDULA DE CIUDADANIA: ";
    cin>>auxcc;
    lectura>>cc;
       while(!lectura.eof()){
        lectura>>nom>>ape>>edad>>genero>>dir>>telf;//leyendo los campos del registro, Comparar cada registro para ver si es encontrado
           if(auxcc==cc){
            system("cls");
            cuadro(0,0,118,27);
            cuadro(1,1,117,3);
            cout<<"\t\t\t\t\n";
            gotoxy(50,2);cout<<"BUSCAR CLIENTES                     \n";
            cout<<"\n\n\n";
            cout<<"\t\t\t\t____________________\n";
            cout<<"\t\t\t\tCEDULA DE CIUDADANIA: "<<cc<<endl;
            cout<<"\t\t\t\tNOMBRE: "<<nom<<endl;
            cout<<"\t\t\t\tAPELLIDO: "<<ape<<endl;
            cout<<"\t\t\t\tEDAD: "<<edad<<endl;
            cout<<"\t\t\t\tGENERO: "<<genero<<endl;
            cout<<"\t\t\t\tDIRECCION: "<<dir<<endl;
            cout<<"\t\t\t\tTELEFONO: "<<telf<<endl;
            cout<<"\t\t\t\t______________________\n";
            encontrado=true;
            cout<<"\n\n\n\n\n\n";
            system("PAUSE");
           }
            lectura>>cc;//lectura adelantada
       }
       if(encontrado==false){
        system("cls");
        cuadro(0,0,118,27);
        cuadro(1,1,117,3);
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        Beep(350,500);
        Beep(350,500);
        cout<<"\t\t\t\t              No Existe Tal Registros                 \n";
        cout<<"\n\n\n\n\n\n";
        getch();
        segundomenu();
        
       }
   }else{      
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    Beep(350,500);
    Beep(350,500);
    cout<<"\t\t\t\t    No se pudo Abrir el Archivo, aun no ha sido Creado     \n";
    cout<<"\n\n\n\n\n\n"<<endl;
    system("PAUSE");
   }
   //cerrando el archivo
    lectura.close();
}//fin de funcion BUSCAR

//EDITAR INFO CLIENTE
void modificar(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ofstream aux;
ifstream lectura;
ifstream auxiliar;
lectura.open("clientes.txt",ios::out|ios::in);
aux.open("auxiliar.txt",ios::out|ios::app);//para evitar un daño en la lista
auxiliar.open("clientes.txt",ios::in);
   if(lectura.is_open()){
   	gotoxy(50,2);cout<<"EDITAR CLIENTES\n";
   	cout<<"\t\t\t\t\n";
   	cout<<"\t\tCEDULA DE LA PERSONA QUE DESEA EDITAR: ";
   	cin>>auxcc;
   	lectura>>cc;
   	while(!lectura.eof()){
   	   lectura>>nom>>ape>>edad>>genero>>dir>>telf;
   		if(auxcc==cc){
   		   cout<<"\t\t\t\t\n\n";
   		   cout<<"\n\t\tDIGITE NUEVO NOMBRE: ";
   		   cin>>auxnom;
   		   cout<<"\n\t\tDIGITE NUEVO APELLIDO: ";
   		   cin>>auxape;
   		   cout<<"\n\t\tDIGITE NUEVA EDAD: ";
   		   cin>>auxedad;
   		   cout<<"\n\t\tDIGITE NUEVO GENERO: ";
   		   cin>>auxgenero;
   		   cout<<"\n\t\tDIGITE NUEVA DIRECCION: ";
   		   cin>>auxdir;
   		   cout<<"\n\t\tDIGITE NUEVO TELEFONO: ";
   		   cin>>auxtelf;
   		   aux<<cc<<" "<<auxnom<<" "<<auxape<<" "<<auxedad<<" "<<auxgenero<<" "<<auxdir<<" "<<auxtelf<<endl;
   		}else{
   			 
   		   aux<<cc<<" "<<nom<<" "<<ape<<" "<<edad<<" "<<genero<<" "<<dir<<" "<<telf<<endl;
   		}
   	   lectura>>cc;
   	}
   	lectura.close();
   	aux.close();
   	auxiliar.close();
   }else{
   Beep(350,500);
   Beep(350,500);
   cout<<"t\tNo se encontro el archivo"<<endl;
    system("PAUSE");
    segundomenu();
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
   }
   remove("clientes.txt");
   rename("auxiliar.txt", "clientes.txt");
   getch();
   segundomenu();
   system("cls");
   cuadro(0,0,118,27);
   cuadro(1,1,117,3);
}  
//EDITAR ARTICULO
void editar_I(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ofstream aux2;
ifstream lectura3;
ifstream auxiliar2;
lectura3.open("inventario.txt",ios::out|ios::in);
aux2.open("auxiliar_I.txt",ios::out|ios::app);
auxiliar2.open("inventario.txt",ios::in);
   if(lectura3.is_open()){
   	gotoxy(50,2);cout<<"EDITAR ARTICULO\n";
   	cout<<"\t\t\t\t\n\n";
   	cout<<"\t\tCODICO DEL ARTICULO QUE DESEA EDITAR: ";
   	cin>>auxcod;
   	lectura3>>cod;
   	while(!lectura3.eof()){
   	    lectura3>>des>>cost>>pre>>iva;
   		if(auxcod==cod){
   		   cout<<"\t\t\t\t\n\n";
   		   cout<<"\n\t\tDIGITE NUEVA DESCRIPCION: ";
   		   cin>>auxdes;
   		   cout<<"\n\t\tDIGITE NUEVO COSTO: ";
   		   cin>>auxcost;
   		   cout<<"\n\t\tDIGITE NUEVO PRECIO: ";
   		   cin>>auxpre;
   		   cout<<"\n\t\tDIGITE NUEVO VALOR DEL IVA: ";
   		   cin>>auxiva;
   		   aux2<<cod<<" "<<auxdes<<" "<<auxcost<<" "<<auxpre<<" "<<auxiva<<endl;
   		}else{
   			
   		   aux2<<cod<<" "<<des<<" "<<cost<<" "<<pre<<" "<<iva<<endl;	
   		}
   		lectura3>>cod;
   	}
   	lectura3.close();
   	aux2.close();
   	auxiliar2.close();
   }else{
   Beep(350,500);
   Beep(350,500);
   cout<<"\t\tNo se encontro el archivo";
    system("PAUSE");
    segundomenu();
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
   }
   remove("inventario.txt");
   rename("auxiliar_I.txt", "inventario.txt");	
   segundomenu();
   system("cls");
   cuadro(0,0,118,27);
   cuadro(1,1,117,3);
}  
void inventario(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ofstream escritura;
ifstream consulta;
bool repetido=false;
escritura.open("inventario.txt",ios::out|ios::app);
consulta.open("inventario.txt",ios::in);
   if(escritura.is_open() && consulta.is_open()){    
    gotoxy(50,2);cout<<"INVENTARIO \n";
    cout<<"\t\t\t\t\n";
    cout<<"\t\tINGRESE EL CODIGO DEL PRODUCTO: ";
    cin>>auxcod;
    consulta>>cod; 
       while(!consulta.eof()){
           consulta>>des>>cost>>pre>>iva;
           if(cod==auxcod){            
            system("cls");
            cuadro(0,0,118,27);
            cuadro(1,1,117,3);
            cout<<"\n\n\n\n\n\n\n\n\n\n";
            cout<<"\t\t\t\t                   YA EXISTE EL PRODUCTO                  \n";
            cout<<"\n\n\n\n\n\n";
            system("PAUSE");
            repetido=true;
            break;
           }
           consulta>>cod;
       }
       if(repetido==false){
        system("cls");
        cuadro(0,0,118,27);
        cuadro(1,1,117,3);
        cout<<"\t\t\t\t\n\n";
        cout<<"\t\tDESCRIPCION: ";
        cin>>des;
        cout<<"\t\tCOSTO: ";
        cin>>cost;
        cout<<"\t\tPRECIO: ";
        cin>>pre;
        cout<<"\t\tIVA: ";
        cin>>iva;
        escritura<<auxcod<<" "<<des<<" "<<cost<<" "<<pre<<" "<<iva<<endl;
        system("cls");
        cuadro(0,0,118,27);
        cuadro(1,1,117,3);
        cout<<"\t\t\t\t";
        Beep(1300, 1000);
        cout<<"\t\tProducto Agragado Satisfactorimente."<<endl;
        system("PAUSE");
       }
   }else{
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
    cout<<"\n\n\n\n\n\n\n\n\n\n";
	Beep(350,500);
    Beep(350,500);       
    cout<<"\t\t\t\t   Error, el Archivo No se Pudo Abrir o No ha sido Creado   \n";
    cout<<"\n\n\n\n\n\n";
    system("PAUSE");
   }
   escritura.close();
   consulta.close();
}//Fin funcion CLIENTES
//Fin funcion FACTURACION

//PARA BUSCAR FACTURA xd
void archivos2(){
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ifstream archivo;
ofstream factura;
ifstream codfact;
string texto;
char nombre[60];
factura.open("ayudante_A.txt",ios::out|ios::app);
gotoxy(50,2);cout<<"BUSCAR FACTURA"<<endl;
cout<<"\t\t"<<endl;
cout<<"\tSI USTED NO RECUERDA EL NOMBRE VERIFIQUE EN LA LISTA DE FACTURAS REGISTRADAS."<<endl;
cout<<"\t "<<endl;
cout<<"\tDIGITE EL NOMBRE DEL ARCHIVO QUE BUSCA: ";
cin>>nombre;
factura<<nombre<<".txt";
factura.close();
codfact.open("ayudante_A.txt",ios::in);
codfact>>nombre;
archivo.open(nombre,ios::out);
codfact.close();
remove("ayudante_A.txt");
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
    if(archivo.fail()){
    cout<<"\n";
    Beep(350,500);
    Beep(350,500);
    cout<<"\tNo Se pudo abrir el archivo. "<<endl;
    cout<<"\n";
    cout<<"\tVerifique el nombre de la factura."<<endl;
    getch();
    segundomenu();
    }
gotoxy(50,2);cout<<"FACTURA ENCONTRADA\n";
   	  while(!archivo.eof()){ //MIENTRAS NO SEA EL FINAL DE ARCHIVO
	     getline(archivo,texto);
	     cout<<texto<<endl;
 }
fflush(stdin);//BACIAR EL BUFFER Y PERMITIR DIGITAR VALORES
archivo.close();
getch();
segundomenu();
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
}

//ELIMINAR UNA FACTURA 
void Eliminar_F(){
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ifstream archivo;
ofstream factura;
ifstream codfact;
string texto;
char eleccion;
char nombre[60];
factura.open("ayudante_P.txt",ios::out|ios::app);
gotoxy(50,2);cout<<"ELIMINAR FACTURA"<<endl;
cout<<"\t\t"<<endl;
cout<<"\tSI USTED NO RECUERDA EL NOMBRE VERIFIQUE EN LA LISTA DE FACTURAS REGISTRADAS."<<endl;
cout<<"\t "<<endl;
cout<<"\tDIGITE EL NOMBRE DE LA FCATURA QUE DESEA ELIMINAR: ";
cin>>nombre;
factura<<nombre<<".txt";
factura.close();
codfact.open("ayudante_P.txt",ios::in);
codfact>>nombre;
archivo.open(nombre,ios::out);
codfact.close();
remove("ayudante_P.txt");
    if(archivo.fail()){
    cout<<"\n";
    Beep(350,500);
    Beep(350,500);
    cout<<"\tNo Se pudo encontrar el archivo. "<<endl;
    cout<<"\n";
    cout<<"\tVerifique el nombre de la factura."<<endl;
    getch();
    segundomenu();
    }
cout<<"\n\tDESEA ELIMINAR LA FACTURA "<<nombre<<" (S/N): ";
cin>>eleccion;
    if(eleccion=='S'|| eleccion=='s'){
    archivo.close();
    remove(nombre);
    Beep(1300, 1000);
    cout<<"\n\tFactura fue eliminada"<<endl;
    }
     if(eleccion=='N'|| eleccion=='n'){
     archivo.close();
     Beep(350,500);
     Beep(350,500);
	 cout<<"\n\tFactura no fue eliminada"<<endl;	
	 }
getch();
segundomenu();
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
}
//ELIMINAR UN CLIENTE
void eliminar(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ofstream aux;
ifstream lectura;
ifstream auxiliar;
lectura.open("clientes.txt",ios::out|ios::in);
aux.open("auxiliar.txt",ios::out|ios::app);
auxiliar.open("clientes.txt",ios::in);
   if(lectura.is_open()){
   	cout<<"\t\t\t\t\n\n";
   	cout<<"\t\tCEDULA DE LA PERSONA QUE DESEA ELIMINAR: ";
   	cin>>auxcc;
   	lectura>>cc;
   	while(!lectura.eof()){
   		lectura>>nom>>ape>>edad>>genero>>dir>>telf;
   		if(auxcc==cc){
   		   cout<<"\t\t\t\t\n\n";
   		   Beep(1300, 1000);
   		   cout<<"\tPersona a sido eliminada satisfactoriamente.";
   		   getch();
   	       }else{	
   		   aux<<cc<<" "<<nom<<" "<<ape<<" "<<edad<<" "<<genero<<" "<<dir<<" "<<telf<<endl;	 
   		  }
   	   lectura>>cc;
   	  }
   	lectura.close();
   	aux.close();
   	auxiliar.close();
   }else{
   	Beep(350,500);
    Beep(350,500);
    cout<<"t\tNo se encontro el archivo"<<endl;
    system("PAUSE");
    segundomenu();
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
   }
remove("clientes.txt");
rename("auxiliar.txt", "clientes.txt");	
segundomenu();
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
} 
//ELIMINAR INVENTARIO
void eliminar_I(){
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
ofstream aux2;
ifstream lectura3;
ifstream auxiliar2;
lectura3.open("inventario.txt",ios::out|ios::in);
aux2.open("auxiliar_I.txt",ios::out|ios::app);
auxiliar2.open("inventario.txt",ios::in);
   if(lectura3.is_open()){
   	gotoxy(50,2);cout<<"ELEMINAR ARTICULO\n";
   	cout<<"\t\t\t\t\n";
   	cout<<"\t\tCODICO DEL ARTICULO QUE DESEA ELIMINAR: ";
   	cin>>auxcod;
   	lectura3>>cod;
   	while(!lectura3.eof()){
   	    lectura3>>des>>cost>>pre>>iva;
   		if(auxcod==cod){
   			cout<<"\t\t\t\t\n\n";
   		   Beep(1300, 1000);
   		   gotoxy(5,6);cout<<"Articulo a sido eliminado satisfactoriamente.";
   		   getch();
   		}else{
   		   aux2<<cod<<" "<<des<<" "<<cost<<" "<<pre<<" "<<iva<<endl;	
   		}
   		lectura3>>cod;
   	}
   	lectura3.close();
   	aux2.close();
   	auxiliar2.close();
   }else{
   	Beep(350,500);
    Beep(350,500);
    cout<<"\t\tNo se encontro el archivo";
    system("PAUSE");
    segundomenu();
    system("cls");
    cuadro(0,0,118,27);
    cuadro(1,1,117,3);
   }
remove("inventario.txt");
rename("auxiliar_I.txt", "inventario.txt");	
segundomenu();
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
}  

// LEER REGISTRO DE FACTURAS
void Lista_Facturas(){
system("cls");
cuadro(1,1,117,3);
ifstream myfile;
gotoxy(50,2);cout<<"REGISTRO DE FACTURAS\n\n";
myfile.open("Registro_Lista.csv");
 while(myfile.good()){
	string line;
	getline(myfile,line,';');
	cout<<"\t"<<line<<endl;
}
myfile.close();
getch();
system("cls");
cuadro(0,0,118,27);
cuadro(1,1,117,3);
}

//PARA HACER LOS CUADROS EN LA PANTALLA
//Usa caracteres que no estan en el abecedario en ingles
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}
void cuadro(int x1, int y1, int x2, int y2){
    int i;
    for (i=x1;i<x2;i++){	
		gotoxy(i,y1);printf("Ä") ; //linea horizontal superior 
		gotoxy(i,y2);printf("Ä") ; //linea horizontal inferior
    }
    for (i=y1;i<y2;i++){	
		gotoxy(x1,i);printf("³") ; //linea vertical izquierda
		gotoxy(x2,i);printf("³") ; //linea vertical derecha
    }
    gotoxy(x1,y1); printf("Ú"); //Esquinas del cuadro
    gotoxy(x1,y2); printf("À");
    gotoxy(x2,y1); printf("¿");
    gotoxy(x2,y2); printf("Ù");
}
