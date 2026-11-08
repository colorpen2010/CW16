#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

    vector<string> ryadky;
    string ryadok;
    while (getline(vhid, ryadok))
        ryadky.push_back(ryadok);

    for (int i = static_cast<int>(ryadky.size()) - 1; i >= 0; i--)
        vyhid << ryadky[i] << endl;

    cout << "Готово. Рядки записано у зворотному порядку." << endl;
    return 0;
}
