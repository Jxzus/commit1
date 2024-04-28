#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
using namespace std;
class menu2{
    public:
        void mostrar2(){
        system("cls");
            cout<<"M E N U  P A R A  E D I T A R"<<endl;
            cout<<"--------------------------"<<endl;
            cout<<endl;
            cout<<"---Que desea editar del estudiante?---"<<endl;
            cout<<"1. Nombre del estudiante"<<endl;
            cout<<"2. Carrera del estudiante"<<endl;
            cout<<"3. nota numero 1"<<endl;
            cout<<"4. nota numero 2"<<endl;
            cout<<"5. nota numero 3"<<endl;
            cout<<"6. Regresar al menu principal"<<endl;
            cout<<endl;
            cout<<"Ingrese la opcion: "<<endl;
        }

void editarNombre(ifstream &archivo, ofstream &auxiliar) {
    system("cls");
    string nombre;
    string codigo;
    string carrera;
    string nombreAux;
    string codigoAux;
    archivo.open("H:\\Proyecto\\estudiante.txt");
    auxiliar.open("H:\\Proyecto\\Auxiliar.txt");
    if (archivo.is_open() && auxiliar.is_open()) {
        cout << "Digite el codigo del estudiante: ";
        cin >> codigoAux;
        bool modificado = false;
        while (archivo >> codigo >> nombre >> carrera) {
            if (codigo == codigoAux) {
                cout << "Digite el nuevo nombre: ";
                cin.ignore();
                getline(cin, nombreAux);
                auxiliar << codigo << " " << nombreAux << " " << carrera << endl;
                modificado = true;
            } else {
                auxiliar << codigo << " " << nombre << " " << carrera << endl;
            }
        }
        archivo.close();
        auxiliar.close();
        if (modificado) {
            remove("H:\\Proyecto\\estudiante.txt");
            rename("H:\\Proyecto\\Auxiliar.txt", "H:\\Proyecto\\estudiante.txt");
            cout << "Cambios guardados exitosamente." << endl;
        } else {
            cout << "No se encontró ningún estudiante con el código proporcionado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}


void editarCarrera(ifstream &archivo, ofstream &auxiliar) {
    system("cls");
    string nombre;
    string codigo;
    string carrera;
    string carreraAux;
    string codigoAux;
    string nombreAux;
    archivo.open("H:\\Proyecto\\estudiante.txt");
    auxiliar.open("H:\\Proyecto\\Auxiliar.txt");
    if (archivo.is_open() && auxiliar.is_open()) {
        cout << "Digite el codigo del estudiante: ";
        cin >> codigoAux;
        bool modificado = false;
        while (archivo >> codigo >> nombre >> carrera) {
            if (codigo == codigoAux) {
                cout << "Digite la nueva carrera: ";
                cin.ignore();
                getline(cin, carreraAux);
                auxiliar << codigo << " " << nombre << " " << carreraAux << endl;
                modificado = true;
            } else {
                auxiliar << codigo << " " << nombre << " " << carrera << endl;
            }
        }
        archivo.close();
        auxiliar.close();
        if (modificado) {
            remove("H:\\Proyecto\\estudiante.txt");
            rename("H:\\Proyecto\\Auxiliar.txt", "H:\\Proyecto\\estudiante.txt");
            cout << "Cambios guardados exitosamente." << endl;
        } else {
            cout << "No se encontró ningún estudiante con el código proporcionado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

        void QueHace2(int op2){
            system("cls");
            switch(op2){
                case 1:
                    cout<<"Ha seleccionado editar nombre"<<endl;
                    {
                    ifstream archivo;
                    ofstream auxiliar;
                    editarNombre(archivo, auxiliar);
                    }
                    break;
                case 2:
                    cout<<"Ha seleccionado editar carrera"<<endl;
                    {
                    ifstream archivo;
                    ofstream auxiliar;
                    editarCarrera(archivo, auxiliar);
                    }
                    break;
                case 3:
                    cout<<"Ha seleccionado borrar estudiantes"<<endl;
                    break;
                case 4:
                    cout<<"Ha seleccionado modificar etudiantes"<<endl;
                    break;
                case 5:
                    cout<<"saliendo..."<<endl;
                    break;
                default:
                    cout<<"Opcion incorrecta"<<endl;
                    break;
            }

        }
};
class menu{
    public:
        void ciclo1(){
        menu Menu;
        int op1;
            do {
            Menu.mostrar();
            cin >> op1;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Error, debes colocar un numero del 1 al 5"<<endl;
            Sleep(2000);
            }
            Menu.QueHace(op1);
            } while(op1 != 5);
        }

        void ciclo2(){
        menu2 Menu2;
        int op2;
            do {
            Menu2.mostrar2();
            cin >> op2;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Error, debes colocar un numero del 1 al 5"<<endl;
            Sleep(2000);
            }
            Menu2.QueHace2(op2);
            } while(op2 != 6);
        }

        void mostrar(){
        system("cls");
            cout<<"M E N U  P R I N C I P A L"<<endl;
            cout<<"--------------------------"<<endl;
            cout<<endl;
            cout<<"1. Crear estudiante"<<endl;
            cout<<"2. Mostrar estudiantes"<<endl;
            cout<<"3. Borrar estudiantes"<<endl;
            cout<<"4. modificar estudiante"<<endl;
            cout<<"5. Salir"<<endl;
            cout<<endl;
            cout<<"Ingrese la opcion: "<<endl;
        }
    
        void verarch(ifstream &archivo)  {
            system("cls");
                string nombre;
                string codigo;
                string carrera;
                float nota1;
                float nota2;
                float nota3;
                float definitiva;
                archivo.open("H:\\Proyecto\\estudiante.txt", ios::in);
                    cout<<"|    Codigo    |"<<"      Nombre      |"<<"      Carrera       |"<<"   nota 1   |"<<"   nota2   |"<<"   nota3   |"<<"   definitiva   |"<<endl;
                    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;     
                while(archivo >> codigo) {
                    getline(archivo >> ws, nombre);//el ws es un manipulador de flujo que emite los espacios en blanco
                    getline(archivo >> ws, carrera);
                    archivo>>nota1;
                    archivo>>nota2;                
                    archivo>>nota3;
                    archivo>>definitiva;
                    cout<<"|   "<<codigo<<"  |  "<<nombre<<"  |    "<<carrera<<"    |      "<<nota1<<"      |      "<<nota2<<"      |      "<<nota3<<"      |      "<<definitiva<<"      |    "<<endl;
                    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;          
            }   
        archivo.close();
        system("pause");
        }
        
    void editarNombre(ifstream &archivo, ofstream &auxiliar) {
    system("cls");
    string nombre;
    string codigo;
    string carrera;
    string codigoAux;
    string nombreAux;
    archivo.open("H:\\Proyecto\\estudiante.txt");
    auxiliar.open("H:\\Proyecto\\Auxiliar.txt");
    if (archivo.is_open() && auxiliar.is_open()) {
        cout << "Digite el codigo del estudiante: ";
        cin >> codigoAux;
        bool modificado = false;
        while (archivo >> codigo >> nombre >> carrera) {
            if (codigo == codigoAux) {
                cout << "Digite el nuevo nombre: ";
                cin.ignore();
                getline(cin, nombreAux);
                auxiliar << codigo << " " << nombreAux << " " << carrera << endl;
                modificado = true;
            } else {
                auxiliar << codigo << " " << nombre << " " << carrera << endl;
            }
        }
        archivo.close();
        auxiliar.close();
        if (modificado) {
            remove("H:\\Proyecto\\estudiante.txt");
            rename("H:\\Proyecto\\Auxiliar.txt", "H:\\Proyecto\\estudiante.txt");
            cout << "Cambios guardados exitosamente." << endl;
        } else {
            cout << "No se encontró ningún estudiante con el código proporcionado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}





        void QueHace(int op1){
            system("cls");
            switch(op1){
                case 1:
                    cout<<"Ha seleccionado crear estudiantes"<<endl;
                    {
                    ofstream estudiante;
                    crearEstudiante(estudiante);
                    }
                    break;
                case 2:
                    cout<<"Ha seleccionado mostrar estudiantes"<<endl;
                    {
                    ifstream archivo;
                    verarch(archivo);
                    }
                    break;
                case 3:
                    cout<<"Ha seleccionado borrar estudiantes"<<endl;
                    break;
                case 4:
                    cout<<"Ha seleccionado modificar etudiantes"<<endl;
                    ciclo2();
                    break;
                case 5:
                    cout<<"saliendo..."<<endl;
                    break;
                default:
                    cout<<"Opcion incorrecta"<<endl;
                    break;
            }

        }
        void crearEstudiante(ofstream &estudiante){
        system("cls");
            string codigo;
            string nombre;
            string carrera;
            float nota1;
            float nota2;
            float nota3;
            float definitiva;
            estudiante.open("H:\\Proyecto\\estudiante.txt", ios::out | ios::app);
            cout<<"Agregue el codigo del estudiante: ";
            cin>>codigo;
            cout<<"Agregue el nombre del estudiante: ";
            cin.ignore();
            getline(cin, nombre);
            cout<<"Agregue la carrera del estudiante: ";
            getline(cin, carrera);
            cout<<"Agregue la primera nota del estudiante: ";
            cin>>nota1;
            cout<<"Agregue la segunda nota del estudiante: ";
            cin>>nota2;
            cout<<"Agregue la tercera nota del estudiante: ";
            cin>>nota3;
            definitiva = (nota1 + nota2 + nota3)/3;
            estudiante<<codigo<<" "<<nombre<<endl;
            estudiante<<carrera<<endl;
            estudiante<<nota1<<" "<<nota2<<" "<<nota3<<" "<<definitiva<<endl;
            estudiante.close();
            cout<<"Estudiante creado exitosamente. Redirigiendo al menu principal"<<endl;
        Sleep(4000);
        }


    };

int main()
{
    menu MenuPrincipal;
    MenuPrincipal.ciclo1();
    return 0;
}
