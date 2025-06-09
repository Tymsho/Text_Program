#include <iostream>

//Para manejar caracteres
#include <string>

//Para utilizar la funcion _getch
#include <conio.h>

//Para utilizar la funcion de color
#include <windows.h>

//Para utilizar la funcion system
#include <cstdlib>

//Parte de la funcion color
#define color SetConsoleTextAttribute

//Incluimos el header de funciones
#include "funciones.h"

//Incluimos el header del struct
#include "struct.h"

using namespace std;



int main()
    //Matriz con la que trabaja la funcion de cifrado y descifrado
{   char matrizVigenere[26][26] = {
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
        {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
        {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
        {'d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
        {'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
        {'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
        {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
        {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
        {'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
        {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
        {'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
        {'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
        {'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
        {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
        {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
        {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
        {'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
        {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
        {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
        {'t', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
        {'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
        {'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
        {'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
        {'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
        {'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
        {'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}
        };

    //Vectores con los que trabajaremos en las distintas opciones (se guarda el abecedario en mayusculas y minusculas)
    char letrasMin [] = "abcdefghijklmnopqrstuvwxyz";
    char letrasMay [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Con esta variable "TEXTO" es con la que  trabajaremos en todo el programa
    string texto, clave, textoCifrado, textoDescifrado;

    // La variable de ejecucion del switch, iniciada en uno para entrar en el ciclo
    int opcion = 1;

    // Variable usada para buscar una letra en especifico
    char letra;

    // Funcion de consola para lo estetico
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

    //Declaramos el tipo de dato que va a ser texto
    TextoActual textocargado;

    color(hConsole, 15); //Funcion para cambiar el color de los textos
    cout << "--OPRIMA CUALQUIER LETRA PARA INICIAR--" << endl;

    //Esta es la funcion que pausara el sistema a lo largo del programa y esperara a que
    //el usuario presione una tecla para continuar
    _getch();
     system ("cls"); //Funcion que borra la consola

    cout << endl << "Ingrese un texto" << endl;
    cout << "----------------" << endl << endl;

    //Funcion utilizada para trabajar con el texto que proporcione el usuario
    getline(cin, texto);

    //Se le asigna el valor de texto a la propiedad "contenido" de textocargado
    textocargado.contenido = texto;

    //inicio del programa en el ciclo while
    while(opcion != 0){

       system("title MENU"); //Funcion que cambiara el titulo de la consola

       color(hConsole, 6); //Funcion con la que cambiamos el color del texto de menu

       //Couts con las opciones del programa
       cout << endl << "   _MENU DE INTERACCION_" << endl;

       color(hConsole, 15);// Aqui devolvemos el color del programa al original

       cout << "Opcion 1: Contador de caracteres" << endl;
       cout << "Opcion 2: Contador de letra unica" << endl;
       cout << "Opcion 3: Contador de palabras" << endl;
       cout << "Opcion 4: Contador de letras en general" << endl;
       cout << "Opcion 5: Invertir el texto" << endl;
       cout << "Opcion 6: Contador de oraciones" << endl;
       cout << "Opcion 7: Cambiar texto a mayuscula" << endl;
       cout << "Opcion 8: Cambiar texto a minuscula" << endl;
       cout << "Opcion 9: Cifrado Vigenere (solo minusculas)" << endl;
       cout << "Opcion 10: Mostrar texto actual" << endl;
       cout << "Opcion 11: Nuevo texto" << endl;
       cout << "Ingrese 0 para terminar el programa" << endl;
       cout << "-----------------------------------" << endl;
       cout << "Opcion: ";
       cin >> opcion;

       //Inicio del switch menu
       switch(opcion) {

        case 0: //Fin del programa

                system("title Gracias Vuelvas Prontos");
                color(hConsole, 10);
                cout << endl << "ADIOS" << endl;

        break;

        case 1: //Contador de caracteres

            textocargado.cantidadcaracteres = contcaracteres(textocargado.contenido);

            system("title CONTADOR DE CARACTERES");
            color(hConsole, 6);
            cout << endl << "================================================" << endl;
            cout << " La cantidad de caracteres del texto es " << textocargado.cantidadcaracteres << endl;
            cout <<        "================================================" << endl;

        break;

        case 2: //Contador de letras unica

            system("title CONTADOR DE LETRA UNICA");

            cout << endl << "-Ingrese la letra que desea contar: ";
            cin >> letra;

            textocargado.letraunica = contletra(textocargado.contenido, letra);

                color(hConsole, 6);
            if (textocargado.letraunica != 0){ //En funcion de lo que el contador contenga se dan distintas respuestas
                if (textocargado.letraunica == 1){
                cout << endl << "================================================" << endl;
                cout << "La letra se repite una vez" << endl;
                cout <<        "================================================" << endl;
                }else {
                cout << endl << "================================================" << endl;
                cout << "La letra se repite " << textocargado.letraunica << " veces" << endl;
                cout <<        "================================================" << endl;
                }
            }else {
                cout << endl << "================================================" << endl;
                cout << "No se encontro la letra solicitada" << endl;
                cout <<        "================================================" << endl;
            }

        break;

        case 3: //Contador de palabras


            system("title CONTADOR DE PALABRAS");

            textocargado.palabras = contletra(textocargado.contenido, ' ') + 1;

            color(hConsole, 6);
            cout << endl << "================================================" << endl;
            cout << "La cantidad de palabras es " << textocargado.palabras << endl;
            cout <<        "================================================" << endl;

        break;

        case 4: //Contador de letras general

            system("title CONTADOR DE LETRAS EN GENERAL");

            cout << endl << "================================================" << endl;

            Letraunica(textocargado.contenido, letrasMin, letrasMay);

            cout << endl << "================================================" << endl;

        break;

        case 5: //Revertir el texto

            system("title REVERTIR EL TEXTO");
            color(hConsole, 6);

            cout << endl << "================================================" << endl;

            invertirtexto(textocargado.contenido);

            cout << endl << "================================================" << endl;

        break;

        case 6: //Contador de oraciones


            system("title CONTADOR DE ORACIONES");

            textocargado.oraciones = contadororaciones(textocargado.contenido) + 1;

            color(hConsole, 6);
            cout << endl << "================================================" << endl;
            cout << "La cantidad de oraciones es " << textocargado.oraciones << endl;
            cout <<        "================================================" << endl;

        break;

        case 7: //Cambiar a Mayusculas

            system("title CAMBIAR A MAYUSCULAS");

            color(hConsole, 6);
            cout << endl << "================================================" << endl;
             cambiarMayuscula(textocargado.contenido, letrasMin, letrasMay);
            cout << endl << "================================================" << endl;

        break;

        case 8: //Cambiar a Minusculas

            system("title CAMBIAR A MINUSCULAS");
            color(hConsole, 6);
            cout << endl << "================================================" << endl;
            cambiarMinuscula(textocargado.contenido, letrasMin, letrasMay);
            cout << endl << "================================================" << endl;;

        break;

        case 9: //Cifrado Vigenere

            system("title  CIFRADO DE VIGENERE");
            color(hConsole, 6);
            cout << endl << "================================================" << endl;
            cout << endl  << "Ingrese la clave (solo letras minusculas): ";
            cin.ignore();
            getline(cin, clave);

            textoCifrado = cifrarTexto(textocargado.contenido, clave, matrizVigenere);

            color(hConsole, 15);
            cout << "Texto cifrado: " << textoCifrado << endl;
            color(hConsole, 6);
            cout << endl << "Ingrese la clave (solo letras minusculas): ";
            getline(cin, clave);
            color(hConsole, 15);

            textoDescifrado = descifrarTexto(textoCifrado, clave, matrizVigenere);

            cout << "Texto descifrado: " << textoDescifrado << endl;
            color(hConsole, 6);
            cout << endl << "================================================" << endl;

        break;

        case 10:    //Contenido actualmente en texto

            system("title TEXTO");
            color(hConsole, 6);
            cout << endl << endl << "    --TEXTO--" << endl << endl;
            color(hConsole, 15);
            cout << textocargado.contenido << endl;
            cout << "-----------------------------------" << endl;

        break;

        case 11:    //Ingresar nuevo texto
            system ("cls");
            color(hConsole, 15);
            cout << endl << "Ingrese un nuevo texto" << endl;
            cout << "----------------" << endl << endl;

            textocargado.ingresartextonuevo();

        break;

        default:  //limitaremos al usuario a que utilice las opciones del programa y no ingrese una opcion invalida

            system("title ERROR");
            color(hConsole, 12);
            cout << endl << "       --LA OPCION INGRESADA NO ES VALIDA-- " << endl;
            color(hConsole, 15);
            cout <<         "Por favor ingrese una opcion valida para el programa" << endl;
            color(hConsole, 12);
            cout <<         "           ----------------------------    " << endl;

        break;

       }

    //Se agrega una pausa al sistema luego de ejecutar alguna opcion del menu
    if (opcion >= 1 && opcion <= 11){
            color(hConsole, 15);
            cout << endl;
            system ("pause");
       }
    }
    return 0;
}
