#include <iostream>
#include <vector>
#include <string>

using namespace std;

string SumaBinaria(string a, string b);
string Complemento2(string bin);
string RestaBinaria(string a, string b);
void ShiftAR(string &A, string &Q, string &Q_1);
void ImprimirEstado(int paso, string A, string Q, string Q_1);

int main()
{
    string A, Q, M, Q_1;
    int n;

    cout << "Ingresa el multiplicando (M) en binario: ";
    cin >> M;
    cout << "Ingresa el multiplicador (Q) en binario: ";
    cin >> Q;

    n = Q.length();
    A = string(n, '0');
    Q_1 = "0";

    cout << "\nEstado inicial:\n";
    ImprimirEstado(0, A, Q, Q_1);

    for (int i = 1; i <= n; i++)
    {
        string Q0 = string(1, Q[Q.length() - 1]);

        if (Q0 == "1" && Q_1 == "0")
        {
            A = RestaBinaria(A, M);
            cout << "Paso " << i << ": A = A - M\n";
        }
        else if (Q0 == "0" && Q_1 == "1")
        {
            A = SumaBinaria(A, M);
            cout << "Paso " << i << ": A = A + M\n";
        }
        else
        {
            cout << "Paso " << i << ": No se hace suma/resta\n";
        }

        ShiftAR(A, Q, Q_1);
        cout << "Despues del shift:\n";
        ImprimirEstado(i, A, Q, Q_1);
    }

    string resultado = A + Q;
    cout << "\nResultado final en binario (complemento 2): " << resultado << endl;
    return 0;
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

    string one(bin.size() - 1, '0');
    one += '1';
    return SumaBinaria(bin, one);
}

string RestaBinaria(string a, string b)
{
    string comp2 = Complemento2(b);
    return SumaBinaria(a, comp2);
}

void ShiftAR(string &A, string &Q, string &Q_1)
{
    string lastA = string(1, A[0]);
    Q_1 = string(1, Q[Q.size() - 1]);
    Q = A[A.size() - 1] + Q.substr(0, Q.size() - 1);
    A = lastA + A.substr(0, A.size() - 1);
}

void ImprimirEstado(int paso, string A, string Q, string Q_1)
{
    cout << "Paso " << paso << ": A = " << A << " | Q = " << Q << " | Q-1 = " << Q_1 << endl;
}
