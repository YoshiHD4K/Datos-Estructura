#include <iostream>

using namespace std;

string capitalizar(string palabra){
    for (char &c : palabra)
    {
        c = tolower(c);
    }

    if (!palabra.empty()) {
        palabra[0] = toupper(palabra[0]);
    }
    return palabra;
}

main(){
    string nombre = "juan";
    string nombre2 = "Pedro";
    
    nombre = capitalizar(nombre);
    nombre2 = capitalizar(nombre2);

    if (nombre > nombre2) {
        cout << "El nombre " << nombre << " es mayor que " << nombre2 << endl;
    } else if (nombre < nombre2) {
        cout << "El nombre " << nombre << " es menor que " << nombre2 << endl;
    } else {
        cout << "Los nombres son iguales" << endl;
    }    
}