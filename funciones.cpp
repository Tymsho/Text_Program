#include <iostream>

#include <string>
using namespace std;

//Funcion que recorrera texto contando todos los caracteres
int contcaracteres(string texto){ //texto es la cadena de caracteres que el usuario ingresa
        int contCaracteres = 0;
        for(int i = 0; i < texto.length(); i++){ //La funcion ".length" es la que utilizamos para recorrer los caracteres de texto
        contCaracteres++; // Variable utilizada para contador los caracteres y se "reutilizara" en las demas funciones
        }

        return contCaracteres;
}

//Funcion que recorrera texto y reconocera las veces que aparece la letra solicitada distingiendo entre mayusculas y minusculas
//Esta funcion tambien es utilizada para contar las palabras
int contletra(string texto, char letra){
        int contCaracteres = 0;
        for(int i = 0; i < texto.length(); i++){
                if (texto[i] == letra){
                    contCaracteres++;
                }
            }
        return contCaracteres;
}

//Funcion que cuenta la cantidad especifica de letras en texto contando de igual forma mayusculas y minusculas
void Letraunica (string texto, char letrasMin[26], char letrasMay[26]){

int contLetraUnica[26] = {0};

    for (int i = 0; i < texto.length(); i++){
        for (int x = 0; x < 26; x++){
            if (texto[i] == letrasMin[x] || texto[i] == letrasMay[x] ){
                contLetraUnica[x]++;
            }
        }
    }

    //Se muestran las cantidad de caracteres que hay
    for (int x = 0; x < 26; x++){

        if (contLetraUnica[x] > 0) cout << endl << "La letra " << letrasMay[x] << " aparecio: " << contLetraUnica[x] << endl;

        }
}

//Funcion que recorre texto de una manera inversa para poder devolver texto en el orden contrario
void invertirtexto (string texto){

    for(int i = texto.length(); i >= 0; i--){
            cout << texto[i];

    }

}

//Funcion que recorre el texto en busca de signos en especifico para determinar el numero de oraciones del texto
int contadororaciones (string texto){
    int contOraciones = 0;
    for (int i = 0; i < texto.length(); i++){

     if ((texto[i] == '.' && texto[i + 1] == ' ') || (texto[i] == '!' && texto[i + 1] == ' ' ) || (texto[i] == '?' && texto[i + 1] == ' ')){
                    contOraciones++;
                }

    }

    return contOraciones;
}

//Funcion en la que modificaremos los caracteres del texto de forma que todos sean letras mayusculas
void cambiarMayuscula(string texto, char letrasMin[26], char letrasMay[26]){

        for (int i = 0; i < texto.length(); i++){
        for (int x = 0; x < 26; x++){
            if(texto[i] == letrasMin[x]){
                texto[i] = letrasMay[x];
            }
        }
    }

    cout << texto;
}

//Funcion en la que modificaremos los caracteres del texto de forma que todos sean letras minusculas
void cambiarMinuscula(string texto, char letrasMin[26], char letrasMay[26]){

        for (int i = 0; i < texto.length(); i++){
        for (int x = 0; x < 26; x++){
            if(texto[i] == letrasMay[x]){
                texto[i] = letrasMin[x];
            }
        }
    }

    cout << texto;
}

//Funcion de cifrado vigenere
string cifrarTexto(string texto, string clave, char matriz[26][26]) {
    //Comprueba que la clave no este vacia para no crashear el programa
    if (clave.length() == 0) {
        cerr << "La clave no puede estar vacía" << endl;
        return "";
    }

    //Declaracion de variables para guardar el texto cifrado y para recorrer la clave
    string textoCifrado;
    int claveIndex = 0;

    //Recorre el texto ingresado y verifica si hay espacios, si hay los coloca en el texto cifrado
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] == ' ') {
            textoCifrado.push_back(' ');
        } else {
            //Convierte la letra encontrada en un valor numerico y es asignado el indice de fila de la matriz
            int fila = texto[i] - 'a';
            //El mismo proceso para asignar la fila, pero usando el modulo de la cantidad de caracteres para obtener un numero menor a esta
            int columna = clave[claveIndex % clave.length()] - 'a';
            // Busca la letra en la matriz y la coloca en el texto cifrado
            textoCifrado.push_back(matriz[fila][columna]);
            claveIndex++;
        }
    }
    return textoCifrado;
}

//Funcion de descifrado vigenere
string descifrarTexto(string textoCifrado, string clave, char matriz[26][26]) {
    //Comprueba que la clave no este vacia para no crashear el programa
    if (clave.length() == 0) {
        cerr << "La clave no puede estar vacía" << endl;
        return "";
    }

    //Declaracion de variables para guardar el texto cifrado y para recorrer la clave
    string textoOriginal;
    int claveIndex = 0;

    //Recorre el texto cifrado y verifica si hay espacios, si hay los coloca en el texto original
    for (int i = 0; i < textoCifrado.length(); i++) {
        if (textoCifrado[i] == ' ') {
            textoOriginal.push_back(' ');
        } else {
            //Usando el index y el modulo del tamaño de la clave, se le asigna un valor numerico a cada letra de esta
            int fila = clave[claveIndex % clave.length()] - 'a';
            //Recorre la fila usando el indice J buscando el caracter que coincida con el caracter del texto cifrado
            for (int j = 0; j < 26; j++) {
                if (matriz[fila][j] == textoCifrado[i]) {
                    textoOriginal.push_back('a' + j); //Convierte al numero de indice J en un caracter y lo coloca en el texto original
                    break;
                }
            }
            claveIndex++;
        }
    }
    return textoOriginal;
}
