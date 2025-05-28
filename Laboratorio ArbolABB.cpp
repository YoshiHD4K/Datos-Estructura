#include <iostream>
#include <cstdlib>

using namespace std;

struct arbol{
    int dato;
    arbol* izq;
    arbol* der;
    arbol(int val) : dato(val), izq(NULL), der(NULL) {}
}; 
arbol *raiz = NULL, *rec = NULL, *nuevo = NULL;

arbol insertar(arbol *&raiz, int valor);
void imprimirArbol(arbol *raiz, int espacios = 0);
bool buscar(arbol *raiz, int valor);
void preorden(arbol *raiz);
void inorden(arbol *raiz);
void postorden(arbol *raiz);
void Menu();
arbol *eliminardato(arbol *&raiz, int valor);


main(){
    
    srand(time(0)); // Inicializa la semilla para números aleatorios
    system("cls");
    Menu();
    
}
void Menu (){
    int opcion;

    do{
        cout << "\n==== Menu ====\n";
        cout << "1. Insertar datos:\n";
        cout << "2. Eliminar datos:\n";
        cout << "3. Imprimir Arbol:\n";
        cout << "4. Imprimir recorrido:\n";
        cout << "5. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
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
            cout << "---------------------------------------------------------" << endl
                 << endl;

            int dato;
            while (NumVeces > 0)
            {
                do
                {

                    dato = rand() % 100 + 1; // Genera un número aleatorio entre 1 y 100

                } while (buscar(raiz, dato)); // Asegurarse de que el dato no se repita

                insertar(raiz, dato);
                cout << "Se inserto el dato: " << dato << endl;
                NumVeces--;
            }
            cout << endl;
            cout<<"Se ha insertado los datos correctamente"<< endl;
            system("pause");
            system("cls");
            break;
            
        case 2:
            int valor;
            cout << "Ingrese el valor a eliminar: ";
            cin >> valor;
            if (buscar(raiz, valor))
            {
                eliminardato(raiz, valor);
                cout << "El dato " << valor << " ha sido eliminado." << endl;
            }
            else
            {
                cout << "El dato " << valor << " no se encuentra en el arbol." << endl;
            }
            system("pause");
            system("cls");
            break;

        case 3:
            cout << "---------------------------------------------------------" << endl;
            cout << "Imprimiendo el arbol:" << endl;
            if (raiz == NULL)
            {
                cout << "El arbol esta vacio." << endl;
            }
            else
            {
                imprimirArbol(raiz);
            }
            system("pause");
            system("cls");
            break;
        
        case 4:
            cout << "---------------------------------------------------------" << endl;
            cout << "Recorridos del arbol:" << endl;
            cout << "1. Preorden" << endl;
            preorden(raiz);
            cout << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "2. Inorden" << endl;
            inorden(raiz);
            cout << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "3. Postorden" << endl;
            postorden(raiz);
            cout << endl;
            cout << "---------------------------------------------------------" << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            cout << "Gracias por usar el programa." << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
            cout << "---------------------------------------------------------" << endl;
            break;
        }

        

    }while(opcion != 5);
}
arbol *encontrarminimo(arbol *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    while (raiz->izq != NULL)
    {
        raiz = raiz->izq;
    }
    return raiz;
}
arbol *encontrarmaximo(arbol *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    while (raiz->der != NULL)
    {
        raiz = raiz->der;
    }
    return raiz;
}
arbol *eliminardato(arbol *&raiz, int valor)
{
    if (raiz == NULL)
    {
        cout << "El arbol esta vacio o el valor no existe." << endl;
        return raiz;
    }
    if (valor < raiz->dato)
    {
        raiz->izq = eliminardato(raiz->izq, valor);
    }
    else if (valor > raiz->dato)
    {
        raiz->der = eliminardato(raiz->der, valor);
    } else {
        //caso 1 y 2: nodo con un hijo o sin hijos
        if (raiz->izq == NULL)
        {
            rec = raiz->der;
            delete raiz;
            return rec;
        }
        else if (raiz->der == NULL)
        {
            rec = raiz->izq;
            delete raiz;
            return rec;
        }
        // caso 3: nodo con dos hijos
        // Encontrar el nodo con el valor mínimo en el subárbol derecho
        cout << "El nodo con el valor " << raiz->dato << " tiene dos hijos" << endl;
        cout << "Desea eliminar el nodo y buscar en el arbol derecho o izquierdo?" << endl;
        cout << "1. Buscar en el arbol derecho" << endl;
        cout << "2. Buscar en el arbol izquierdo" << endl;
        int opcion;
        cin >> opcion;
        if (opcion != 1 && opcion != 2) {
            cout << "Opcion invalida. Se eliminara el nodo y se buscara en el arbol derecho." << endl;
            opcion = 1; // Por defecto, buscar en el arbol derecho
        }
        if (opcion == 1)
        {
            // Buscar el nodo con el valor mínimo en el subárbol derecho
            cout << "Buscando en el arbol derecho..." << endl;
            rec = encontrarminimo(raiz->der);
            raiz->dato = rec->dato;
            raiz->der = eliminardato(raiz->der, rec->dato);
        }
        else
        {
            // Buscar el nodo con el valor máximo en el subárbol izquierdo
            cout << "Buscando en el arbol izquierdo..." << endl;
            rec = encontrarmaximo(raiz->izq);
            raiz->dato = rec->dato;
            raiz->izq = eliminardato(raiz->izq, rec->dato);
        }        
    }
    return raiz;
}
    
        
bool buscar(arbol *raiz, int valor){
    if (raiz == NULL)
    {
        return false;
    }
    if (raiz->dato == valor)
    {
        return true;
    }
    if (valor < raiz->dato)
    {
        return buscar(raiz->izq, valor);
    }
    else
    {
        return buscar(raiz->der, valor);
    }
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
    cout << string(espacios, ' ') << raiz->dato << endl<<endl;

    imprimirArbol(raiz->izq, espacios + 4);
}
arbol insertar(arbol *&raiz, int valor)
{
    if (raiz == NULL)
    {
        raiz = new arbol(valor);
    }else{
        if(valor < raiz->dato){
            insertar(raiz->izq, valor);
    }else{
        if(valor > raiz->dato){
            insertar(raiz->der, valor);
        }
    }
    }
    return *raiz; 
}
void preorden(arbol *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    cout << raiz->dato << " - ";
    preorden(raiz->izq);
    preorden(raiz->der);
}
void inorden(arbol *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    inorden(raiz->izq);
    cout << raiz->dato << " - ";
    inorden(raiz->der);
}
void postorden(arbol *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    postorden(raiz->izq);
    postorden(raiz->der);
    cout << raiz->dato << " - ";
}