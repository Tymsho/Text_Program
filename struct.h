#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <string>
using namespace std;

//Struct que utilizaremos para comvertir a texto en un tipo de dato texto actual
struct TextoActual {
    //Propiedades con las que trabajaremos en las funciones
    string contenido;
    int cantidadcaracteres;
    int letraunica;
    int palabras;
    int oraciones;

//Funcion que reemplazara el contenido del texto anterior por uno nuevo a gusto del ususario
string ingresartextonuevo(){

    string texto;
    cin.ignore(); //Funcion que nos permite vaciar el contenido de texto
    getline(cin, texto);
    contenido = texto;
 }
};

#endif // STRUCT_H_INCLUDED
