#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string enunciado;
	
	cout<<"Ingrese su nombre y carrera: ";
	getline(cin,enunciado);
	
	ofstream mi_archivo; //(output file stream). clase orientada para la escritura
	mi_archivo.open("datos.txt"); //(ios::app) añadir despues del nombre del archivo si queremos que se guarde en cada iteracion
	if(mi_archivo.good()) //sirve para verificar si nuestro escritor o lector se creo satisfasctoriamente
    mi_archivo<<enunciado; //escribe en el archivo la cadena que ingreso el usuario
    mi_archivo.close();
    
    ifstream mi_lector; //(input file stream). clase orientada para la lectura
    mi_lector.open("datos.txt");
    string cadena; //variable cadena para imprimir por palabra
    while(!mi_lector.eof())
	{
    	mi_lector>>cadena;
    	cout<<cadena<<" ";	
	}
	mi_lector.close();
    
    
    return 0;
}
