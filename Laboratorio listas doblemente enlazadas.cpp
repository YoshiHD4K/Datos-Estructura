#include <iostream>
#include <cctype>

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
    if (!nuevo->nombre.empty())
    {
        nuevo->nombre[0] = toupper(nuevo->nombre[0]);
    }
    cout << "Ingrese el número telefónico: ";
    cin >> nuevo->numerotlf;

    if (primero == NULL or nuevo->nombre < primero->nombre)
    {
        nuevo->sig = primero;
        if (primero != NULL)
        {
            primero->ant = nuevo;
        }
        primero = nuevo;      
    } else {
        actual = primero;
        while (actual->sig != NULL && nuevo->nombre > actual->sig->nombre)
        {
            actual = actual->sig;
        }
        nuevo->sig = actual->sig;
        if (actual->sig != NULL)
        {
            actual->sig->ant = nuevo;
        }
        actual->sig = nuevo;
        nuevo->ant = actual;
    }
    cout << "Número telefónico agregado correctamente." << endl;
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
    int eliminados = 0;
    while (actual != NULL)
    {
        if (actual->nombre == nombre)
        {
            eliminados++;
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
    
    if (eliminados != 0){
        cout << "Se eliminaron " << eliminados << " personas con el nombre " << nombre << endl;
    }
    else{
        cout << "No se encontraron personas con el nombre " << nombre << endl;
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
    int encontrados = 0;
    while (actual != NULL)
    {
        if (actual->numerotlf == numerotlf)
        {
            cout << "------------------------------------------------" << endl;
            cout << "Número telefónico encontrado: " << endl;
            cout << "Nombre: " << actual->nombre << endl;
            cout << "Número telefónico: " << actual->numerotlf << endl;
            cout << "------------------------------------------------" << endl;
            encontrados++;
        }
        actual = actual->sig;
    }
    if (encontrados != 0)
    {
        cout << "Se encontraron " << encontrados << " números telefónicos con el número " << numerotlf << endl;
    }
    else
    {
        cout << "Número telefónico no encontrado." << endl;
    }
    system("pause");
    system("cls");
}