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
    if (!vhid.is_open())
    {
        cout << "Не вдалося відкрити input.txt." << endl;
        return 1;
    }

    vector<string> ryadky;
    string ryadok;
    while (getline(vhid, ryadok))
        ryadky.push_back(ryadok);
    vhid.close();

    // Знаходимо останній рядок, у якому немає пробілу.
    int pozytsiya = -1;
    for (int i = 0; i < static_cast<int>(ryadky.size()); i++)
    {
        if (ryadky[i].find(' ') == string::npos)
            pozytsiya = i;
    }

    // Індекс показує, після скількох рядків вставити риски.
    int kilkistRyadkiv = (pozytsiya == -1)
        ? static_cast<int>(ryadky.size())
        : pozytsiya + 1;

    ofstream vyhid("output.txt");
    if (!vyhid.is_open())
    {
        cout << "Не вдалося створити output.txt." << endl;
        return 1;
    }

    for (int i = 0; i < kilkistRyadkiv; i++)
        vyhid << ryadky[i] << endl;

    vyhid << "------------" << endl;

    for (int i = kilkistRyadkiv; i < static_cast<int>(ryadky.size()); i++)
        vyhid << ryadky[i] << endl;

    cout << "Готово. Результат записано у output.txt." << endl;
    return 0;
}
