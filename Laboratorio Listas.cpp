/*Realice un programa en C++, para generar una lista simplemente enlazada para un registro
de Empleados ordenada de manera descendente por sueldo y que contiene la siguente
información CI, Nombre sueldo y fecha de ingreso, fecha de nacimiento, fecha ultimo
ascenso.*/

#include <iostream>
#include <locale.h>
#include <regex>
#include <ctime>
#include <sstream>

using namespace std;

struct Empleado
{
    int Cedula;
    string Nombre;
    int Sueldo;
    string FechaIngreso;
    string FechaNacimiento;
    string FechaUltimoAscenso;
};

struct Nodo
{
    Empleado data;
    Nodo *siguiente;
};

Nodo *primero = NULL;

void InsertarLista(Nodo *&primero, Empleado dato);
void ImprimirLista(Nodo *primero);
void LlenarEmpleado(Empleado &empleado);
void CrearEmpleados(Nodo *&primero);
void Menu();
void EliminarEmpleadoPorCedula(Nodo *&primero, int cedula);
void EliminarEmpleadoPorSueldo(Nodo *&primero, int sueldo);
bool SoloDigitos(const string &str);
bool esFechaValida(const string &fecha);
bool ValidarCedulaenLista(Nodo *primero, int cedula);
void BuscarEmpleadosPorSueldo(Nodo *primero, int sueldo);
void ImprimirEmpleado(const Empleado &empleado);
void buscarEmpleadosPorRangoFecha(Nodo *primero, const string &fechaInicio, const string &fechaFin);
void BuscarEmpleadoPorCedula(Nodo *primero, int cedula);

main()
{
    setlocale(LC_ALL, "Spanish");
    system("cls");
    Menu();

    getchar();
    return 0;
}

void CrearEmpleados(Nodo *&primero)
{
    char opcion;
    do
    {
        Empleado nuevoEmpleado;

        cout << "\nIngrese los datos del empleado a continuacion\n\n";
        LlenarEmpleado(nuevoEmpleado);

        InsertarLista(primero, nuevoEmpleado);

        cout << "¿Desea agregar otro empleado? (s/n): ";
        cin >> opcion;
        cin.ignore();

    } while (opcion == 's' || opcion == 'S');
}

void InsertarLista(Nodo *&primero, Empleado dato)
{
    Nodo *nuevo = new Nodo();
    nuevo->data = dato;

    Nodo *actual = primero;
    Nodo *anterior;

    while ((actual != NULL) and (actual->data.Sueldo > dato.Sueldo))
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (primero == actual)
    {
        primero = nuevo;
    }
    else
    {
        anterior->siguiente = nuevo;
    }
    nuevo->siguiente = actual;
}

void ImprimirLista(Nodo *primero)
{
    Nodo *anterior = primero;
    cout << endl;
    while (anterior != NULL)
    {
        cout << "Cedula: " << anterior->data.Cedula
             << ", Nombre: " << anterior->data.Nombre
             << ", Sueldo: " << anterior->data.Sueldo
             << ", Fecha de Ingreso: " << anterior->data.FechaIngreso
             << ", Fecha de Nacimiento: " << anterior->data.FechaNacimiento
             << ", Último Ascenso: " << anterior->data.FechaUltimoAscenso
             << endl;
        anterior = anterior->siguiente;
    }
    if (primero == NULL)
    {
        cout << "La lista de empleados esta vacía, llene antes de verla\n";
    }
}

void LlenarEmpleado(Empleado &empleado)
{
    string cedulastr;
    do
    {

        cout << "Ingrese la cédula (Solo Digitos): ";
        cin >> cedulastr;
        cin.ignore();
        if (!SoloDigitos(cedulastr))
        {
            cout << endl
                 << "La cedula contiene caracteres no validos. Intente nuevamente." << endl
                 << endl;
        }

        if (!ValidarCedulaenLista(primero, stoi(cedulastr)))
        {
            cout << "La cédula ingresada ya existe en la lista. Intente con otra cédula." << std::endl;
        }

    } while (!SoloDigitos(cedulastr) and !ValidarCedulaenLista(primero, stoi(cedulastr)));
    empleado.Cedula = stoi(cedulastr);

    cout << "Ingrese el nombre: ";
    getline(cin, empleado.Nombre);

    string sueldostr;
    do
    {
        cout << "Ingrese el sueldo: ";
        cin >> sueldostr;
        cin.ignore();
        if (!SoloDigitos(sueldostr))
        {
            cout << endl
                 << "El sueldo contiene caracteres no validos. Intente nuevamente." << endl
                 << endl;
        }
    } while (!SoloDigitos(sueldostr));
    empleado.Sueldo = stoi(sueldostr);

    string FechaNacimientoStr;
    do
    {
        cout << "Ingrese la fecha de Nacimiento (DD/MM/AAAA): ";
        cin >> FechaNacimientoStr;
        cin.ignore();
        if (!esFechaValida(FechaNacimientoStr))
        {
            cout << endl
                 << "La fecha ingresada no es valida. Intente nuevamente." << endl
                 << endl;
        }
    } while (!esFechaValida(FechaNacimientoStr));
    empleado.FechaNacimiento = FechaNacimientoStr;

    string fechingresostr;
    do
    {
        cout << "Ingrese la fecha de ingreso (DD/MM/AAAA): ";
        cin >> fechingresostr;
        cin.ignore();
        if (!esFechaValida(fechingresostr))
        {
            cout << endl
                 << "La fecha ingresada no es valida. Intente nuevamente." << endl
                 << endl;
        }
    } while (!esFechaValida(fechingresostr));
    empleado.FechaIngreso = fechingresostr;

    string FechaUltimoAscensoStr;
    do
    {
        cout << "Ingrese la fecha del último ascenso (DD/MM/AAAA): ";
        cin >> FechaUltimoAscensoStr;
        cin.ignore();
        if (!esFechaValida(FechaUltimoAscensoStr))
        {
            cout << endl
                 << "La fecha ingresada no es valida. Intente nuevamente." << endl
                 << endl;
        }
    } while (!esFechaValida(FechaUltimoAscensoStr));
    empleado.FechaUltimoAscenso = FechaUltimoAscensoStr;

    cout << endl
         << "Empleado creado correctamente." << endl;
}

void Menu()
{
    int opcion;

    do
    {
        cout << "\n==== Menú ====\n";
        cout << "1. Agregar empleado\n";
        cout << "2. Ver lista de empleados\n";
        cout << "3. Buscar empleado\n";
        cout << "4. Eliminar empleado\n";
        cout << "5. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            CrearEmpleados(primero);
            cout << "\nEmpleado agregado correctamente.\n";
            system("cls");
            break;
        }
        case 2:
        {
            ImprimirLista(primero);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            int opcion1;
            do
            {
                cout << "\n==== Buscar Empleado ====\n";
                cout << "1. Buscar por Cédula\n";
                cout << "2. Buscar por Sueldo\n";
                cout << "3. Buscar por Rango de Fecha\n";
                cout << "Ingrese su opción: ";
                cin >> opcion1;
                cin.ignore();

                if (opcion1 < 1 || opcion1 > 3)
                {
                    cout << "Opción inválida. Por favor, ingrese un número entre 1 y 3.\n";
                }
            } while (opcion1 < 1 || opcion1 > 3);

            switch (opcion1)
            {
            case 1:
                int cedula;
                cout << "\nIngrese la cédula del empleado a buscar: ";
                cin >> cedula;
                cin.ignore();
                BuscarEmpleadoPorCedula(primero, cedula);
                break;

            case 2:
                int sueldo;
                cout << "\nIngrese el sueldo del empleado a buscar: ";
                cin >> sueldo;
                cin.ignore();
                BuscarEmpleadosPorSueldo(primero, sueldo);
                break;

            case 3:
                string fechaInicio, fechaFin;
                do
                {
                    cout << "\nIngrese la fecha de inicio (DD/MM/AAAA): ";
                    cin >> fechaInicio;
                    cin.ignore();
                    if (!esFechaValida(fechaInicio))
                    {
                        cout << "Fecha inválida. Por favor, ingrese una fecha en formato válido.\n";
                    }
                } while (!esFechaValida(fechaInicio));

                do
                {
                    cout << "Ingrese la fecha de fin (DD/MM/AAAA): ";
                    cin >> fechaFin;
                    cin.ignore();
                    if (!esFechaValida(fechaFin))
                    {
                        cout << "Fecha inválida. Por favor, ingrese una fecha en formato válido.\n";
                    }
                } while (!esFechaValida(fechaFin));

                buscarEmpleadosPorRangoFecha(primero, fechaInicio, fechaFin);
                break;
            }
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            int opcion1;
            do
            {
                cout << "\n==== Eliminar Empleado ====\n";
                cout << "1. Eliminar por Cédula\n";
                cout << "2. Eliminar por Sueldo\n";
                cout << "Ingrese su opción: ";
                cin >> opcion1;
                cin.ignore();
                if (opcion1 != 1 && opcion1 != 2)
                {
                    cout << "Opción inválida. Por favor, ingrese 1 o 2.\n";
                }
            } while (opcion1 != 1 && opcion1 != 2);

            switch (opcion1)
            {
            case 1:
                int cedula;
                cout << "\nIngrese la cédula del empleado a buscar: ";
                cin >> cedula;
                cin.ignore();
                EliminarEmpleadoPorCedula(primero, cedula);
                cout << "\nEmpleado eliminado correctamente.\n";
                break;
                cout << "Ingrese la cédula del empleado a eliminar: ";
                break;
            case 2:
                cout << "\nIngrese el sueldo del empleado a buscar: ";
                int sueldo;
                cin >> sueldo;
                cin.ignore();
                EliminarEmpleadoPorSueldo(primero, sueldo);
                break;
            }
            system("pause");
            system("cls");
            break;
            }
        case 5:
        {
            cout << "\nSaliendo del programa...\n";
            break;
        }
        default:
            cout << "\nOpción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5); // Repite el menú hasta que el usuario elija salir
    cout << "\nGracias por usar el programa.\n";
    system("pause");
}

void EliminarEmpleadoPorCedula(Nodo *&primero, int cedula)
{
    Nodo *actual = primero;
    Nodo *anterior = NULL;

    while (actual != NULL && actual->data.Cedula != cedula)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        cout << "Empleado no ha sido encontrado." << endl;
        return;
    }

    if (anterior == NULL)
    {
        primero = actual->siguiente; // Eliminar el primer nodo
    }
    else
    {
        anterior->siguiente = actual->siguiente; // Eliminar un nodo intermedio o final
    }

    delete actual; // Liberar memoria del nodo eliminado
}

void EliminarEmpleadoPorSueldo(Nodo *&primero, int sueldo)
{
    Nodo *actual = primero;
    Nodo *anterior = NULL;
    while (actual != NULL)
    {
        if (actual->data.Sueldo == sueldo)
        {
            if (anterior == NULL)
            {
                primero = actual->siguiente; // Eliminar el primer nodo
                delete actual; // Liberar memoria del nodo eliminado
                actual = primero; // Actualizar el nodo actual
            }
            else
            {
                anterior->siguiente = actual->siguiente; // Eliminar un nodo intermedio o final
                delete actual; // Liberar memoria del nodo eliminado
                actual = anterior->siguiente; // Actualizar el nodo actual
            }
            cout << "Empleado con sueldo " << sueldo << " eliminado." << endl;
        }else
        {
            // Si no se elimina el nodo, solo avanzamos al siguiente
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

bool SoloDigitos(const string &string)
{
    int i = 0;
    int length = string.length(); // Almacenar la longitud una vez
    while (i < length)
    {
        if (!isdigit(string[i]))
        {
            return false; // Si encuentra un carácter no válido, retorna false
        }
        i++;
    }
    return true;
}

bool esFechaValida(const string &fecha)
{
    // Expresión regular para validar el formato DD/MM/AAAA
    regex formato("^([0-9]{2})/([0-9]{2})/([0-9]{4})$");
    smatch coincidencias;

    if (!regex_match(fecha, coincidencias, formato))
    {
        return false; // Formato incorrecto
    }

    // Extraer día, mes y año
    int dia = stoi(coincidencias[1]);
    int mes = stoi(coincidencias[2]);
    int anio = stoi(coincidencias[3]);

    // Validar rango de mes y día
    if (mes < 1 || mes > 12 || dia < 1 || dia > 31)
    {
        return false;
    }

    // Días máximos por mes (sin contemplar años bisiestos)
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajustar febrero en años bisiestos
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        diasPorMes[1] = 29; // Febrero tiene 29 días en años bisiestos
    }

    // Comprobar que el día está dentro del límite permitido para el mes
    if (dia > diasPorMes[mes - 1])
    {
        return false;
    }

    return true; // La fecha es válida
}

void BuscarEmpleadoPorCedula(Nodo *primero, int cedula)
{
    Nodo *actual = primero;

    while (actual != NULL)
    {
        if (actual->data.Cedula == cedula)
        {
            cout << "\nEmpleado encontrado:" << endl;
            cout << "Cedula: " << actual->data.Cedula << endl;
            cout << "Nombre: " << actual->data.Nombre << endl;
            cout << "Sueldo: " << actual->data.Sueldo << endl;
            cout << "Fecha de Ingreso: " << actual->data.FechaIngreso << endl;
            cout << "Fecha de Nacimiento: " << actual->data.FechaNacimiento << endl;
            cout << "Fecha del Ultimo Ascenso: " << actual->data.FechaUltimoAscenso << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "\nEmpleado no encontrado." << endl;
}

void ImprimirEmpleado(const Empleado &empleado)
{
    cout << "\nInformación del empleado:\n";
    cout << "Cédula: " << empleado.Cedula << endl;
    cout << "Nombre: " << empleado.Nombre << endl;
    cout << "Sueldo: " << empleado.Sueldo << endl;
    cout << "Fecha de Ingreso: " << empleado.FechaIngreso << endl;
    cout << "Fecha de Nacimiento: " << empleado.FechaNacimiento << endl;
    cout << "Fecha del Último Ascenso: " << empleado.FechaUltimoAscenso << endl;
}

void BuscarEmpleadosPorSueldo(Nodo *primero, int sueldo)
{
    Nodo *actual = primero;
    bool encontrado = false;

    while (actual != NULL)
    {

        if (actual->data.Sueldo == sueldo)
        {
            cout << "\nEmpleado encontrado:" << endl;
            cout << "Cédula: " << actual->data.Cedula << endl;
            cout << "Nombre: " << actual->data.Nombre << endl;
            cout << "Sueldo: " << actual->data.Sueldo << endl;
            cout << "Fecha de Ingreso: " << actual->data.FechaIngreso << endl;
            cout << "Fecha de Nacimiento: " << actual->data.FechaNacimiento << endl;
            cout << "Fecha del Último Ascenso: " << actual->data.FechaUltimoAscenso << endl;
            encontrado = true;
        }
        actual = actual->siguiente;

        if (!encontrado)
        {
            cout << "\nNo se encontraron empleados con el sueldo especificado." << endl;
        }

        if (primero == NULL)
        {
            cout << "La lista de empleados esta vacía, llene antes de verla\n";
        }
        else
        {
            cout << "Empleado no encontrado." << endl;
        }
    }
}

void buscarEmpleadosPorRangoFecha(Nodo *primero, const string &fechaInicio, const string &fechaFin)
{
    int opcionFecha;

    // Preguntar qué fecha desea consultar
    do
    {
        cout << "\n==== Buscar Empleados por Rango de Fecha ====\n";
        cout << "Seleccione la fecha que desea utilizar:\n";
        cout << "1. Fecha de Ingreso\n";
        cout << "2. Fecha de Nacimiento\n";
        cout << "3. Fecha del Último Ascenso\n";
        cout << "Ingrese su opción: ";
        cin >> opcionFecha;
        cin.ignore();

        if (opcionFecha < 1 || opcionFecha > 3)
        {
            cout << "Opción inválida. Por favor, ingrese un número entre 1 y 3.\n";
        }
    } while (opcionFecha < 1 || opcionFecha > 3);

    // Recorrer la lista de empleados y filtrar según la opción seleccionada
    Nodo *actual = primero;
    bool encontrado = false;

    while (actual != NULL)
    {
        string fechaEmpleado;

        // Seleccionar la fecha correcta según la opción elegida
        switch (opcionFecha)
        {
        case 1:
            fechaEmpleado = actual->data.FechaIngreso;
            break;
        case 2:
            fechaEmpleado = actual->data.FechaNacimiento;
            break;
        case 3:
            fechaEmpleado = actual->data.FechaUltimoAscenso;
            break;
        }

        // Comparar si la fecha del empleado está dentro del rango
        if (fechaEmpleado >= fechaInicio && fechaEmpleado <= fechaFin)
        {
            cout << "\nEmpleado dentro del rango:" << endl;
            cout << "Cédula: " << actual->data.Cedula << endl;
            cout << "Nombre: " << actual->data.Nombre << endl;
            cout << "Sueldo: " << actual->data.Sueldo << endl;
            cout << "Fecha de Ingreso: " << actual->data.FechaIngreso << endl;
            cout << "Fecha de Nacimiento: " << actual->data.FechaNacimiento << endl;
            cout << "Fecha del Último Ascenso: " << actual->data.FechaUltimoAscenso << endl;
            encontrado = true;
        }

        actual = actual->siguiente;
    }

    // Mensaje si no se encontraron empleados dentro del rango
    if (!encontrado)
    {
        cout << "\nNo se encontraron empleados en el rango de fechas especificado." << endl;
    }
}

bool ValidarCedulaenLista(Nodo *primero, int cedula)
{
    Nodo *actual = primero;

    while (actual != NULL)
    {
        if (actual->data.Cedula == cedula)
        {
            return false; // La cédula ya existe
        }
        actual = actual->siguiente;
    }
    return true; // La cédula no existe
}