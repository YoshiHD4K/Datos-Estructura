/*Elabore un programa recursivo que calcule la Potencia de 2 números enteros cualesquiera
con base (a) y exponente (b)*/

#include<iostream>
#include<windows.h>
#include<locale.h>

using namespace std;

float base, exponente;
char opc;
string baseStr, exponenteStr;

float Potencia(float a, float n){
    if(n==0){
        return (1);
    }
    else if(n>0){
        return a * Potencia(a, n - 1);
    }else{
        return 1 / Potencia(a, -n);
    }
}

bool SoloDigitos(const string &str)
{
    int i = 0;
    while (i < str.length())
    {
        if (!isdigit(str[i]))
        {
            // Permitir el signo '-' solo al inicio
            if (i == 0 && str[i] == '-')
            {
                i++;
                continue;
            }
            return false; // Si encuentra un carácter no válido, retorna false
        }
        i++;
    }
    return true;
}

main()
{
	setlocale(LC_ALL, "Spanish");
    do
    {

        do
        {
            cout << "Ingrese la base (sin caracteres no validos): ";
            cin >> baseStr;
            if (!SoloDigitos(baseStr))
            {
                cout << endl << "La base contiene caracteres no validos. Intente nuevamente." << endl<<endl;
            }
        } while (!SoloDigitos(baseStr));
        base = stof(baseStr);
        cout << endl;
        do
        {
            cout << "Ingrese el exponente (sin caracteres no validos): ";
            cin >> exponenteStr;
            if (!SoloDigitos(exponenteStr))
            {
                cout << endl << "El exponente contiene caracteres no validos. Intente nuevamente." << endl << endl;
            }
        } while (!SoloDigitos(exponenteStr));
        exponente = stof(exponenteStr);
        cout << endl;

        cout << "Su resultado es: " << Potencia(base, exponente) << endl << endl;

        cout << "Desea realizar otra operacion? (S/N): ";
        cin >> opc;
        Sleep(1000);
        system("cls");

    } while (opc == 's' or opc == 'S');

}