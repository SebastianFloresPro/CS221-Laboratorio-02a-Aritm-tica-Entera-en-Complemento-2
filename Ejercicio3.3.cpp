#include <iostream>
#include <vector>
#include <string>

using namespace std;

string SumaBinaria(string a, string b) ;
string Complemento2(string b);
string RestaBinaria(string a, string b) ;

int main()
{
    string A = "0000";   // acumulador
    string Q = "";       // mmultiplicador
    string M = "";       // multiplicando
    string Q_1 = "0";    // bit extra
    int n = 0;           // numero de bits 

    cout << "Ingresa el multiplicando (M) en binario: ";
    cin >> M;
    cout << "Ingresa el multiplicador (Q) en binario: ";
    cin >> Q;

    n = Q.length();
    A = string(n, '0');  // Rellena A con n ceros
    Q_1 = "0";


}

string SumaBinaria(string a, string b) 
{
    string r = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) 
    {
        int bitA = a[i] - '0';
        int bitB = b[i] - '0';
        int sum = bitA + bitB + carry;
        r = char((sum % 2) + '0') + r;
        carry = sum / 2;
    }
    return r;
}

string Complemento2(string bin) 
{
   
    for (int i = 0; i < bin.size(); i++) 
    {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }

    // Sumar 1 al resultado invertido
    string one(bin.size() - 1, '0');
    one += '1';
    return SumaBinaria(bin, one);
}

string RestaBinaria(string a, string b) 
{
    return RestaBinaria(a, Complemento2(b));
}