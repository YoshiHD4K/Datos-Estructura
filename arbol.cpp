#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct arbol
{
    int dato;
    arbol *izq;
    arbol *der;
    arbol(int val) : dato(val), izq(NULL), der(NULL) {}
};

arbol *raiz = NULL, *rec = NULL, *nuevo = NULL;

void imprimirArbol(arbol *raiz, int espacios = 0);
int calcularAltura(arbol *raiz);
bool insertarEnNivel(arbol *&raiz, int valor, int nivelObjetivo, int nivelActual);
void insertarPorNiveles(arbol *&raiz, int valor);
void imprimirHojasSimple(arbol *raiz);

main()
{
    char opcion;
    do
    {
        system("cls");
        int NumVeces;
        cout << "---------------------------------------------------------" << endl;
        do
        {
        

            cout << "Cuantas veces desea insertar un dato: ";
            cin >> NumVeces;
            if (NumVeces <= 0)
            {
                cout << "El numero de veces a insertar debe ser mayor a 0" << endl;
            }

        } while (NumVeces <= 0);
        cout << "---------------------------------------------------------" << endl  <<  endl;

        while (NumVeces > 0)
        {
            int dato = rand() % 100 + 1; // Genera un número aleatorio entre 1 y 100
            insertarPorNiveles(raiz, dato);
            cout << "Se inserto el dato: " << dato << endl;
            NumVeces--;
        }
        cout << endl;
        system("pause");
        cout << "---------------------------------------------------------" << endl
             << endl
             << endl;

        imprimirArbol(raiz, 0);
        cout << endl
             << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Altura del arbol: " << calcularAltura(raiz) << endl;
        cout << "Hojas del arbol: ";
        imprimirHojasSimple(raiz);
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        cout << "Desea ingresar mas datos? (s/n): ";
        cin >> opcion;
        if (opcion == 'n' or opcion == 'N')
        {
            cout << endl
                 << endl
                 << "Saliendo...";
            Sleep(1000);
        }

    } while (opcion == 'S' or opcion == 's');
}
int calcularAltura(arbol *rec)
{
    if (raiz == NULL)
        return -1;
    return 1 + max(calcularAltura(raiz->izq), calcularAltura(raiz->der));
}
void imprimirArbol(arbol *raiz, int espacios)
{
    if (raiz == NULL)
    {
        return;
    }
    // Aumentamos los espacios para la indentación
    imprimirArbol(raiz->der, espacios + 4);

    // Mostramos el valor con espacios para dar forma
    cout << string(espacios, ' ') << raiz->dato << endl;

    imprimirArbol(raiz->izq, espacios + 4);
}
bool insertarEnNivel(arbol *&raiz, int valor, int nivelObjetivo, int nivelActual)
{
    if (raiz == NULL)
    {
        if (nivelActual == nivelObjetivo)
        {
            raiz = new arbol(valor);
            return true;
        }
        return false;
    }

    if (nivelActual == nivelObjetivo)
        return false; // Ya hay nodo en este nivel

    // Intentar insertar primero a la izquierda
    bool insertado = insertarEnNivel(raiz->izq, valor, nivelObjetivo, nivelActual + 1);
    if (insertado)
        return true;

    // Si no se pudo insertar a la izquierda, intentar a la derecha
    return insertarEnNivel(raiz->der, valor, nivelObjetivo, nivelActual + 1);
}
void insertarPorNiveles(arbol *&raiz, int valor)
{
    if (raiz == NULL)
    {
        raiz = new arbol(valor);
        return;
    }

    int h = calcularAltura(raiz);
    int nivel = 0;
    while (nivel <= h)
    {
        if (insertarEnNivel(raiz, valor, nivel, 0))
        {
            return;
        }
        ++nivel;
    }

    // Si no se pudo insertar en ningún nivel existente, crear nuevo nivel
    insertarEnNivel(raiz, valor, h + 1, 0);
}
void imprimirHojasSimple(arbol *raiz)
{
    if (raiz == NULL)
        return;

    if (raiz->izq == NULL && raiz->der == NULL)
    {
        cout << raiz->dato << " ";
    }

    imprimirHojasSimple(raiz->izq);
    imprimirHojasSimple(raiz->der);
}