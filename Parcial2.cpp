#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Empleado
{
    string sexo;
    string Nombre;
    Fecha fecha_nacimiento;
    Empleado *siguiente;
};

char opcion;
Empleado *primero, *actual, *anterior;

void menu();
void insertar(Empleado *&primero);
bool validarFecha(Fecha fecha);
void imprimirLista(Empleado *primero);
bool compararFechas(Fecha fecha1, Fecha fecha2);
void BuscarHembrasporfecha(Empleado *primero);
void EliminarEmpleadoPorAnio(Empleado *&primero);

main()
{
	setlocale(LC_ALL, "Spanish");
    srand(time(0)); // Inicializa la semilla para generar números aleatorios
    menu();
}

void menu()
{
    do
    {
        cout << "------------------------------" << endl
             << endl;
        cout << "---- Menu de opciones----" << endl;
        cout << "1. Insertar personas " << endl;
        cout << "2. Buscar por Fecha" << endl;
        cout << "3. Eliminar por Fecha" << endl;
        cout << "4. Imprimir lista" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cout << endl;
        cout << "------------------------------" << endl;

        string nombre, sexo;

        switch (opcion)
        {
        case '1':
            insertar(primero);
            continue;
        case '2':
            BuscarHembrasporfecha(primero);
            continue;
        case '3':
            EliminarEmpleadoPorAnio(primero);
            continue;
        case '4':
            imprimirLista(primero);
            continue;
        case '5':
            cout << "Saliendo..."<< endl;
            continue;
        default:
            cout << "Opcion no valida" << endl;
            continue;
        }

    } while (opcion != '5');
}
void insertar(Empleado *&primero)
{
    int nroempleados;
    cout << "Ingrese el número de empleados a insertar: ";
    cin >> nroempleados;

    while (nroempleados > 0)
    {
        Empleado *nuevo = new Empleado;
        nuevo->siguiente = NULL; // Inicializa el siguiente nodo como NULL
        nuevo->sexo = rand() % 2 == 0 ? "Masculino" : "Femenino";
        nuevo->Nombre = nuevo->sexo == "Masculino" ? "Juan" : "Maria";

        do
        {
            nuevo->fecha_nacimiento.dia = rand() % 31 + 1;
            nuevo->fecha_nacimiento.mes = rand() % 12 + 1;
            nuevo->fecha_nacimiento.anio = rand() % 56 + 1970; // Años entre 1970 y 2025
        } while (!validarFecha(nuevo->fecha_nacimiento));

        // Si la lista está vacía o el nuevo nodo debe ir al iniciosy

        if (primero == NULL || compararFechas(primero->fecha_nacimiento, nuevo->fecha_nacimiento))
        {
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else
        {
            actual = primero;
            anterior = NULL;

            // Encuentra la posición correcta para insertar el nuevo nodo
            while (actual != NULL && compararFechas(actual->fecha_nacimiento, nuevo->fecha_nacimiento))
            {
                anterior = actual;
                actual = actual->siguiente;
            }

            // Inserta el nuevo nodo en la posición encontrada
            anterior->siguiente = nuevo;
            nuevo->siguiente = actual;
        }

        nroempleados--;
        cout << "Empleado insertado: " << nuevo->Nombre << endl;
    }
    Sleep(2000);
    system("cls");
}
void imprimirLista(Empleado *primero)
{
    actual = primero;
    while (actual != NULL)
    {
        cout << "Nombre: " << actual->Nombre << endl;
        cout << "Sexo: " << actual->sexo << endl;
        cout << "Fecha de nacimiento: " << actual->fecha_nacimiento.dia << "/" << actual->fecha_nacimiento.mes << "/" << actual->fecha_nacimiento.anio << endl;
        cout << endl;
        actual = actual->siguiente;
    }
    if (primero == NULL)
    {
        cout << "La lista de empleados está vacía." << endl;
    }
}
bool validarFecha(Fecha fecha)
{
    // Verificar que el año sea positivo
    if (fecha.anio < 1)
    {
        return false;
    }

    // Verificar que el mes esté en el rango válido
    if (fecha.mes < 1 || fecha.mes > 12)
    {
        return false;
    }

    // Determinar el número de días en el mes
    int diasEnMes;
    switch (fecha.mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        diasEnMes = 30;
        break;
    case 2:
        // Verificar si es un año bisiesto
        if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0))
        {
            diasEnMes = 29;
        }
        else
        {
            diasEnMes = 28;
        }
        break;
    default:
        diasEnMes = 31;
    }

    // Verificar que el día esté en el rango válido
    if (fecha.dia < 1 || fecha.dia > diasEnMes)
    {
        return false;
    }

    return true;
}
void BuscarHembrasporfecha(Empleado *primero)
{
    Fecha fechaInicio, fechaFin;

    // Solicitar el rango de fechas al usuario
    cout << "Ingrese la fecha de inicio (dd mm aaaa): " << endl;
    cout << "Ingrese el dia:";
    cin >> fechaInicio.dia;
    cout << "Ingrese el mes:";
    cin >> fechaInicio.mes;
    cout << "Ingrese el año:";
    cin >> fechaInicio.anio;
    cout << endl;

    cout << "Ingrese la fecha de fin (dd mm aaaa): " << endl;

    cout << "Ingrese el dia:";
    cin >> fechaFin.dia;
    cout << "Ingrese el mes:";
    cin >> fechaFin.mes;
    cout << "Ingrese el año:";
    cin >> fechaFin.anio;
    cout << endl;

    // Validar las fechas ingresadas
    if (!validarFecha(fechaInicio) || !validarFecha(fechaFin))
    {
        cout << "Una o ambas fechas ingresadas no son válidas." << endl;
        return;
    }

    // Verificar que la fecha de inicio sea anterior o igual a la fecha de fin
    if (compararFechas(fechaFin, fechaInicio))
    {
        cout << "La fecha de inicio debe ser anterior o igual a la fecha de fin." << endl;
        return;
    }

    // Recorrer la lista y buscar empleadas femeninas dentro del rango
    Empleado *actual = primero;
    bool encontrado = false;

    cout << "Empleadas femeninas en el rango de fechas:" << endl;

    while (actual != NULL)
    {
        if (actual->sexo == "Femenino" &&
            !compararFechas(actual->fecha_nacimiento, fechaInicio) && // actual >= fechaInicio
            !compararFechas(fechaFin, actual->fecha_nacimiento))
        { // actual <= fechaFin
            // Mostrar la información del empleado
            cout << "Nombre: " << actual->Nombre << endl;
            cout << "Fecha de nacimiento: " << actual->fecha_nacimiento.dia << "/"
                 << actual->fecha_nacimiento.mes << "/" << actual->fecha_nacimiento.anio << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }

    if (!encontrado)
    {
        cout << "No se encontraron empleadas femeninas en el rango de fechas especificado." << endl;
    }
}
bool compararFechas(Fecha fecha1, Fecha fecha2)
{
    if (fecha1.anio < fecha2.anio)
    {
        return true;
    }
    else if (fecha1.anio == fecha2.anio)
    {
        if (fecha1.mes < fecha2.mes)
        {
            return true;
        }
        else if (fecha1.mes == fecha2.mes)
        {
            if (fecha1.dia < fecha2.dia)
            {
                return true;
            }
        }
    }
    return false;
}
void EliminarEmpleadoPorAnio(Empleado *&primero)
{
    if (primero == NULL)
    {
        cout << "La lista de empleados está vacía." << endl;
        return;
    }

    Fecha fecha;
    cout << "Ingrese el año de nacimiento de los empleados a eliminar: ";
    cin >> fecha.anio;
    cout << endl;

    Empleado *actual = primero;
    Empleado *anterior = NULL;
    bool encontrado = false;

    while (actual != NULL)
    {
        if (actual->fecha_nacimiento.anio == fecha.anio)
        {
            cout << "Empleado eliminado: " << actual->Nombre << endl;
            encontrado = true;

            // Si el nodo a eliminar es el primero
            if (actual == primero)
            {
                primero = actual->siguiente;
                delete actual;
                actual = primero; // Avanzar al siguiente nodo
            }
            else
            {
                // Si el nodo a eliminar no es el primero
                anterior->siguiente = actual->siguiente;
                delete actual;
                actual = anterior->siguiente; // Avanzar al siguiente nodo
            }
        }
        else
        {
            // Avanzar en la lista
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontraron empleados con el año de nacimiento especificado." << endl;
    }
}