/*

1.	Imaginemos que el restaurant tiene en total N platos
Suponiendo que hay platos, de color 1 (rojo), otro de color 2 Azul
y color 3 (amarillo) y que alguien lava platos  y los coloca uno sobre
otro  y que los mesoneros  toman  de los platos  que se lavan para
servir. Escriba un programa en C++ que simule el proceso anterior de
lavar y servir, utilizando para ello una Pila, y muestre en un
momento determinado cuantos platos hay disponible y de que color son
esos platos

*/

#include <iostream>
#include <stack>
#include <windows.h>
#include <locale.h>
#include <conio.h> // Para _kbhit y _getch
using namespace std;

stack<int> pila; // Pila para almacenar los platos

int cantidadtotal, cantidadrojo, cantidadazul, cantidadamarillo;
char tecla;

void cambiarcolor(int idcolor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, idcolor);
}

void apilar(int color, int &cantidadtotal, int &cantidadrojo, int &cantidadazul, int &cantidadamarillo)
{
    // Apilar un plato de color dado
    pila.push(color);
    switch (color)
    {
    case 1:
        cambiarcolor(4); // Rojo
        cout << "Se ha apilado un plato rojo." << endl;
        cantidadrojo++;
        cantidadtotal++;
        break;
    case 2:
        cambiarcolor(1); // Azul
        cout << "Se ha apilado un plato azul." << endl;
        cantidadazul++;
        cantidadtotal++;
        break;
    case 3:
        cambiarcolor(6); // Amarillo
        cout << "Se ha apilado un plato amarillo." << endl;
        cantidadamarillo++;
        cantidadtotal++;
        break;
    }
}

void desapilar(int &cantidadtotal, int &cantidadrojo, int &cantidadazul, int &cantidadamarillo)
{
    if (!pila.empty())
    {
        int color = pila.top();
        pila.pop();
        switch (color)
        {
        case 1:
            cambiarcolor(4); // Rojo
            cout << "Se ha desapilado un plato rojo." << endl;
            cantidadrojo--;
            cantidadtotal--;
            break;
        case 2:
            cambiarcolor(1); // Azul
            cout << "Se ha desapilado un plato azul." << endl;
            cantidadazul--;
            cantidadtotal--;
            break;
        case 3:
            cambiarcolor(6); // Amarillo
            cout << "Se ha desapilado un plato amarillo." << endl;
            cantidadamarillo--;
            cantidadtotal--;
            break;
        }
    }
    else
    {
        apilar(rand() % 3 + 1, cantidadtotal, cantidadrojo, cantidadazul, cantidadamarillo);
    }
}

int main()
{
    setlocale(LC_ALL, "Spanish");
    int opcion;

inicio: // Etiqueta para el goto
    do
    {
        if (_kbhit())
        {
            tecla = _getch();
        }
        if (rand() % 2 == 0)
        {
            apilar(rand() % 3 + 1, cantidadtotal, cantidadrojo, cantidadazul, cantidadamarillo);
        }
        else
        {
            desapilar(cantidadtotal, cantidadrojo, cantidadazul, cantidadamarillo);
        }
        Sleep(1500);
    } while (tecla != ' ');

    Sleep(2000);
    system("cls");
    cambiarcolor(7);
    cout << "Se presionó la barra espaciadora. Ciclo pausado." << endl;
    cout << "Cantidad total de platos: " << cantidadtotal << endl;
    cout << "Cantidad de platos rojos: " << cantidadrojo << endl;
    cout << "Cantidad de platos azules: " << cantidadazul << endl;
    cout << "Cantidad de platos amarillos: " << cantidadamarillo << endl << endl;
    cout << "Presione 'c' para continuar." << endl;
    cout << "Presione 'q' para salir." << endl;
    cout << "Presione 'r' para reiniciar." << endl << endl;

    while (true)
    {
        if (_kbhit())
        {
            tecla = _getch();
            if (tecla == 'c')
            {
                cout << "Continuando..." << endl;
                Sleep(1000);
                system("cls");
                goto inicio;
                break; // Salir del bucle para continuar
            }
            else if (tecla == 'q')
            {
                cout << "Saliendo..." << endl;
                return 0; // Salir del programa
            }
            else if (tecla == 'r')
            {
                cout << "Reiniciando..." << endl;
                cantidadtotal = 0;
                cantidadrojo = 0;
                cantidadazul = 0;
                cantidadamarillo = 0;
                while (!pila.empty())
                {
                    pila.pop(); // Limpiar la pila
                }
                Sleep(1000);
                system("cls");
                goto inicio; // Reiniciar el programa
            }
        }
    }
}
