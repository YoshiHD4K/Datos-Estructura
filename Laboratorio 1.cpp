/*Escriba un algoritmo o funcion, que presente un menú en donde dependiendo de la escogencia genere
1. una cantidad finita de números enteros
2. una cantidad de colores
y sean mostrados por la pantalla, para ello deben utilizar la función random provista por C*/

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

using namespace std;

int opc, num_random, cantidad_colores, cantidad_numeros;

void cambiarcolor(int idcolor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, idcolor); 
}

int main()
{
    setlocale(LC_ALL, "Spanish");
    do
    {
        cout << "Menú de opciones" << endl;
        cout << "1. Generar números enteros" << endl;
        cout << "2. Generar colores" << endl;
        cout << "3. Salir" << endl
             << endl;
        cout << "Ingrese la opción deseada: " << endl
             << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "¿Cuántos números desea generar?" << endl;
            cin >> cantidad_numeros;

            for (int j = 1; j <= cantidad_numeros; j++)
            {
                num_random = (rand() % 100) + 1; // Genera un número entre 1 y 100
                cout << "Número (" << j << "): " << num_random << endl;
            }
            break;
        case 2:
            cout << "¿Cuántos colores desea generar?" << endl;
            cin >> cantidad_colores;
            for (int i = 1; i <= cantidad_colores; i++)
            {
                num_random = rand() % 6; // 6 colores
                cout << "Color (" << i << "): ";
                switch (num_random)
                {
                case 0:
                    cambiarcolor(4);
                    cout << "Rojo" << endl;
                    break;
                case 1:
                    cambiarcolor(2);
                    cout << "Verde" << endl;
                    break;
                case 2:
                    cambiarcolor(1);
                    cout << "Azúl" << endl;
                    break;
                case 3:
                    cambiarcolor(6);
                    cout << "Amarillo" << endl;
                    break;
                case 4:
                    cambiarcolor(12);
                    cout << "Naranja" << endl;
                    break;
                case 5:
                    cambiarcolor(5);
                    cout << "Violeta" << endl;
                    break;
                }
                cambiarcolor(7);
                cout << endl;
            }
            break;
        case 3:

            // code

            break;
        default:
            cout << "Opción inválida" << endl;
            break;
        }
        cout << endl
             << endl
             << endl;
    } while (opc != 3);
    return 0;
}
