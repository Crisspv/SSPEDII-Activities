#include<iostream>
#include<fstream>
#include "string.h"
#include "windows.h"
using namespace std;

class Alumno
{
	public:
		char user[35],pass[35],nom[35],ape[35],mail[35];
		void Capturar();
		void Mostrar();
		void Buscar();
		void Eliminar();
		void Modificar();
}x;

void Alumno::Capturar()
{
	cout<<"\nIngrese usuario: ";
	//cin.ignore();
	cin.getline(user,35);
	cout<<"\nContrase�a: ";
	cin.getline(pass,35);
	cout<<"\nNombre: ";
	cin.getline(nom,35);
	cout<<"\nApellido: ";
	cin.getline(ape,35);
	cout<<"\nMail: ";
	cin.getline(mail,35);

	ofstream Archivo("AlumnoDeli.txt",ios::app);
	Archivo<<user<<'|'<<pass<<'|'<<nom<<'|'<<ape<<'|'<<mail<<'|';
	Archivo.close();
}

void Alumno::Mostrar()
{
	int i;
	ifstream Lectura ("AlumnoDeli.txt");
	if(!Lectura.good())
	{
		cout<<"\nNo existe el archivo";
	}
	else
		{
			while(!Lectura.eof())
			{
				i=0;
				do{//Lectura del usuario
					Lectura.read((char *)&user[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(user[i-1]!='|');
				user[i-1]='\0';
				
				i=0;
				do{//Lectura de passport
					Lectura.read((char *)&pass[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(pass[i-1]!='|');
				pass[i-1]='\0';
				
				i=0;
				do{//Lectura de nombre
					Lectura.read((char *)&nom[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(nom[i-1]!='|');
				nom[i-1]='\0';
				
				i=0;
				do{//Lectura de apellido
					Lectura.read((char *)&ape[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(ape[i-1]!='|');
				ape[i-1]='\0';
				
				i=0;
				do{//Lectura del mail
					Lectura.read((char *)&mail[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(mail[i-1]!='|');
				mail[i-1]='\0';
				
				if(Lectura.eof())
					break;
				
				cout<<"\nUsuario: "<<user<<"\nPassword: "<<pass<<"\nNombre: "<<nom<<"\nApellido: "<<ape<<"\nMail: "<<mail;
			}
		}
	Lectura.close();
}

void Alumno::Buscar()
{
	char buscado[35];
	bool bandera;
	int i;
	cout<<"\nIngrese el usuario que desea buscar: ";
	cin.ignore();
	cin.getline(buscado, 35);
	
	ifstream Lectura ("AlumnoDeli.txt");
	if(!Lectura.good())
	{
		cout<<"\nEl archivo no existe. ";
	}
	else
		{
			bandera=false;
			while(!Lectura.eof())
			{
				i=0;
				do{//Lectura del usuario
					Lectura.read((char *)&user[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(user[i-1]!='|');
				user[i-1]='\0';
				
				i=0;
				do{//Lectura de passport
					Lectura.read((char *)&pass[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(pass[i-1]!='|');
				pass[i-1]='\0';
				
				i=0;
				do{//Lectura de nombre
					Lectura.read((char *)&nom[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(nom[i-1]!='|');
				nom[i-1]='\0';
				
				i=0;
				do{//Lectura de apellido
					Lectura.read((char *)&ape[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(ape[i-1]!='|');
				ape[i-1]='\0';
				
				i=0;
				do{//Lectura del mail
					Lectura.read((char *)&mail[i],1);
					if(Lectura.eof())
						break;
					i++;
				}while(mail[i-1]!='|');
				mail[i-1]='\0';
				
				if(Lectura.eof())
					break;
				
				int valor=strcmp(buscado,user);
				if(valor==0)
				{
					bandera=true;
					cout<<"\nUsuario: "<<user<<"\nPassword: "<<pass<<"\nNombre: "<<nom<<"\nApellido: "<<ape<<"\nMail: "<<mail;
				}
			}
			if(bandera==false)
				cout<<"\nNo se ha encontrado el registro. ";
		}
	
}


int main()
{
	x.Capturar();
	x.Mostrar();
	x.Buscar();
	return 0;
}
