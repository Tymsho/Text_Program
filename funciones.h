#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
using namespace std;

//El header donde se encuentran todas las funciones que utilizaremos en main

int contcaracteres(string texto);

int contletra(string texto, char letra);

void Letraunica (string texto, char letrasMin[26], char letrasMay[26]);

void invertirtexto (string texto);

int contadororaciones (string texto);

void cambiarMayuscula(string texto, char letrasMin[26], char letrasMay[26]);

void cambiarMinuscula(string texto, char letrasMin[26], char letrasMay[26]);

string cifrarTexto(string texto, string clave, char matriz[26][26]);

string descifrarTexto(string textoCifrado, string clave, char matriz[26][26]);

#endif // FUNCIONES_H_INCLUDED
