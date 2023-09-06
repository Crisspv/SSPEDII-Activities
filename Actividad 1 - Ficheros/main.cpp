#include <iostream>
#include <fstream>

using namespace std;

int main(){
    mi_archivo = fstream("datos.txt",ios::out);
    mi_archivo<<"Hola mundo";
}