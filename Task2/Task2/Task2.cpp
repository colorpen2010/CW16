#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream vhid("input.txt");
    ofstream vyhid("output.txt");

    if (!vhid.is_open() || !vyhid.is_open())
    {
        cout << "Не вдалося відкрити файл." << endl;
        return 1;
    }

    string ryadok;
    while (getline(vhid, ryadok))
        vyhid << ryadok << endl;

    cout << "Готово. Рядки скопійовано у output.txt." << endl;
    return 0;
}
