/*En una institución bancaria, se ha depositado un monto de capital m, por el cual se recibe un interés X anual, El problema consiste
en determinar el capital que se ontendra al cabo de n años. Escriba un programa recursivo que realice el
cálculo sabiendo que la fórmula es m(1+x%)^n   */

#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

float capital, interes, capital_total, anos;
string capitalStr, interesStr, anosStr;

float capital_calculo(float capital, float interes, float anos)
{
    if (anos == 0)
    {
        return capital;
    }
    else
    {
        return capital_calculo(capital, interes, anos - 1) * (1 + interes);
    }
}

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
    char opcion;

    do
    {
        do
        {
            cout << "Ingrese el capital depositado: ";
            cin >> capitalStr;
            if (!SoloDigitos(capitalStr))
            {
                cout << endl
                     << "El capital contiene caracteres no válidos. Intente nuevamente." << endl
                     << endl;
            }
            cout << endl;
        } while (!SoloDigitos(capitalStr));
        capital = stof(capitalStr);

        do
        {
            cout << "Ingrese la cantidad de años para determinar capital total: ";
            cin >> anosStr;
            if (!SoloDigitos(anosStr))
            {
                cout << endl
                     << "El año contiene caracteres no válidos. Intente nuevamente." << endl
                     << endl;
            }
            cout << endl;
        } while (!SoloDigitos(anosStr));
        anos = stof(anosStr);

        do
        {
            cout << "Ingrese el porcentaje de intereses que desea: ";
            cin >> interesStr;
            if (!SoloDigitos(interesStr))
            {
                cout << endl
                     << "El interes contiene caracteres no válidos. Intente nuevamente." << endl
                     << endl;
            }
            cout << endl;
        } while (!SoloDigitos(interesStr));
        interes = stof(interesStr);

        capital_total = capital_calculo(capital, interes / 100, anos);
        cout << endl
             << "La capital total teniendo en cuenta " << anos << " años es: " << capital_total;

        cout << endl
             << endl
             << "¿Desea ingresar una nueva expresión? (s/n): ";
        cin >> opcion;
        system("cls");
    } while (opcion == 's' || opcion == 'S');
}
