#include <iostream>

using namespace std;

struct Nodo
{
    string nombre;
    string numerotlf;
    Nodo *sig;
    Nodo *ant;
};

Nodo *primero, *nuevo, *actual;

void menu();
void insertar(Nodo *&primero);
void mostrar(Nodo *primero);
void borrar(Nodo *&primero);
void buscar(Nodo *primero);

main()
{
    menu();
}

void menu()
{
    int opcion;
    do
    {
        cout << "-------------------------------------------------" << endl
             << endl;
        cout << "1. Insertar numero telefónico" << endl;
        cout << "2. Mostrar los Datos" << endl;
        cout << "3. Buscar datos" << endl;
        cout << "4. Eliminar por Nombre" << endl;
        cout << "5. SALIR" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        cout << "-------------------------------------------------" << endl
             << endl;

        switch (opcion)
        {
        case 1:
            insertar(primero);
            cout << "Número telefónico insertado correctamente." << endl;
            break;
        case 2:
            mostrar(primero);
            break;
        case 3:
            buscar(primero);
            break;
        case 4:
            borrar(primero);
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}
void insertar(Nodo *&primero)
{
    nuevo = new Nodo();
    cout << "Ingrese el nombre: ";
    cin >> nuevo->nombre;
    cout << "Ingrese el número telefónico: ";
    cin >> nuevo->numerotlf;

    nuevo->sig = primero;
    nuevo->ant = NULL; // El nuevo nodo no tiene nodo anterior

    if (primero != NULL)
    {
        primero->ant = nuevo; // Actualiza el nodo anterior del antiguo primero
    }

    primero = nuevo; // Actualiza el puntero al nuevo nodo
    system("pause");
    system("cls");
}
void mostrar(Nodo *primero)
{
    actual = primero;
    if (primero == NULL)
    {
        cout << "La lista está vacía." << endl;
        return;
    }    
    while (actual != NULL)
    {
        cout << "------------------------------------------------" << endl;
        cout << "Nombre: " << actual->nombre << endl;
        cout << "Número telefónico: " << actual->numerotlf << endl;
        cout << "------------------------------------------------" << endl;

        actual = actual->sig;
    }
    system("pause");
    system("cls");
}
void borrar(Nodo *&primero)
{
    string nombre;
    cout << "Ingrese el nombre a eliminar: ";
    cin >> nombre;

    actual = primero;

    if (primero == NULL)
    {
        cout << "La lista está vacía." << endl;
        return;
    }
    bool borrado = false;
    while (actual != NULL)
    {
        if (actual->nombre == nombre)
        {
            borrado = true;
            if (actual == primero) // Si es el primer nodo
            {
                primero = actual->sig;
                if (primero != NULL) // Verifica si la lista no queda vacía
                {
                    primero->ant = NULL;
                }
            }
            else // Si no es el primer nodo
            {
                if (actual->sig != NULL) // Si no es el último nodo
                {
                    actual->ant->sig = actual->sig;
                    actual->sig->ant = actual->ant;
                }
                else // Si es el último nodo
                {
                    actual->ant->sig = NULL;
                }
            }
            delete actual;
            cout << nombre << " eliminada de la lista" << endl;
        }
        actual = actual->sig;
    }
    if (!borrado)
    {
        cout << "Nombre no encontrado." << endl;
    }
    
    system("pause");
    system("cls");
}
void buscar(Nodo *primero)

{
    string numerotlf;
    cout << "Ingrese el número telefónico a buscar: ";
    cin >> numerotlf;

    actual = primero;
    bool encontrado = false;
    while (actual != NULL)
    {
        if (actual->numerotlf == numerotlf)
        {
            cout << "------------------------------------------------" << endl;
            cout << "Número telefónico encontrado: " << endl;
            cout << "Nombre: " << actual->nombre << endl;
            cout << "Número telefónico: " << actual->numerotlf << endl;
            cout << "------------------------------------------------" << endl;
            encontrado = true;
        }
        actual = actual->sig;
    }
    if (!encontrado)
    {
        cout << "Número telefónico no encontrado." << endl;
    }
    system("pause");
    system("cls");
}