/*Elabore un programa recursivo que invierta el orden de los elementos de un arreglo de N
posiciones de números enteros, es decir que el elemento que está en la posición 1 se
intercambie con el elemento de la posición N, el que está en la 2 se intercambie con el de
la N-1 y así sucesivamente.*/

#include <iostream>

using namespace std;

void InvertirArreglo(int arreglo[], int inicio, int fin)
{
    if (inicio >= fin)
    {
        return;
    }
    else
    {
        InvertirArreglo(arreglo, inicio + 1, fin - 1);
		swap(arreglo[inicio], arreglo[fin]);
        
    }
}

int tamano, i;
string tamanoStr;
char opc;

bool SoloDigitos(const string &str)
{
    int i = 0;
    while (i < str.length())
    {
        if (!isdigit(str[i]))
        {
            return false; // Si encuentra un carácter no válido, retorna false
        }
        i++;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Spanish");
    do
    {
        do
        {
            cout << "Ingrese el tamaño del arreglo (sin caracteres no validos): ";
            cin >> tamanoStr;
            if (!SoloDigitos(tamanoStr))
            {
                cout << endl
                     << "El tamaño del arreglo contiene caracteres no validos. Intente nuevamente." << endl
                     << endl;
            }
            cout << endl;
        } while (!SoloDigitos(tamanoStr));
        tamano = stof(tamanoStr);

        int arreglo[tamano];
        i = 0;

        while (i < tamano)
        {
            cout << "Ingrese dato del arreglo( " << i + 1 << " ): ";
            cin >> arreglo[i];
            i++;
        }

        cout << endl;
        i = 0;
        cout << "Arreglo antes de voltear: " << endl
             << endl;

        while (i < tamano)
        {
            cout << arreglo[i] << " / ";
            i++;
        }

        cout << endl
             << endl;

        InvertirArreglo(arreglo, 0, tamano - 1);

        i = 0;
        cout << "Arreglo despues de voltear: " << endl
             << endl;

        while (i < tamano)
        {
            cout << arreglo[i] << " / ";
            i++;
        }

        cout << endl
             << endl;

        cout << "Desea realizar otra operacion? (S/N): ";
        cin >> opc;
        system("cls");

    } while (opc == 's' || opc == 'S');

    return 0;
}
