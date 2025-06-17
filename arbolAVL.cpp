#include <iostream>
#include <locale.h>
#include <cstdlib>

using namespace std;

struct arbol {
    int dato;
    arbol* izq;
    arbol* der;
    arbol(int val) : dato(val), izq(NULL), der(NULL) {}
};

arbol* raiz = NULL, *rec = NULL, *nuevo = NULL;
arbol insertar(arbol*& raiz, int valor);
void imprimirArbol(arbol* raiz, int espacios = 0);

int main() {
    setlocale(LC_ALL, "Spanish");
    int NumVeces;

    do {
        cout << "Cuantas veces desea insertar un dato: ";
        cin >> NumVeces;
        if (NumVeces <= 0) {
            cout << "El numero de veces a insertar debe ser mayor a 0" << endl;
        }
    } while (NumVeces <= 0);

    cout << " De qué manera desea insertar los datos? " << endl;
    cout << "1. Manualmente" << endl;
    cout << "2. Aleatoriamente" << endl;
    cout << "Ingrese su opcion: ";
    int opcion;
    cin >> opcion;

    switch (opcion) {
        case 1:
            do {
                int dato;
                cout << "Ingrese el dato " << (NumVeces) << ": ";
                cin >> dato;
                insertar(raiz, dato);
                cout << "Se insertó el dato: " << dato << endl;
                NumVeces--;
            } while (NumVeces > 0);

            cout << endl << endl;

            cout << " Arbol resultante: " << endl;
            imprimirArbol(raiz, 0);
            system("pause");
            break;

        case 2:
            // Implementar inserción aleatoria si es necesario
            break;

        default:
            cout << "Opción no válida." << endl;
            break;
    }

    return 0;
}

arbol insertar(arbol*& raiz, int valor) {
    if (raiz == NULL) {
        raiz = new arbol(valor);
    } else if (valor < raiz->dato) {
        insertar(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        insertar(raiz->der, valor);
    }
    return *raiz;
}

