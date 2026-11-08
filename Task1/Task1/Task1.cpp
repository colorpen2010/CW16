#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int dovzhynaSlova(const string& slovo)
{
    int kilkist = 0;
    for (unsigned char symvol : slovo)
    {
        if ((symvol & 0xC0) != 0x80)
            kilkist++;
    }
    return kilkist;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream vhid("input.txt");
    ofstream vyhid("output.txt");

    if (!vhid.is_open() || !vyhid.is_open())
    {
        cout << "Не получилось открыть файл." << endl;
        return 1;
    }

    string slovo;
    bool persheSlovo = true;
    while (vhid >> slovo)
    {
        if (dovzhynaSlova(slovo) >= 7)
        {
            if (!persheSlovo)
                vyhid << ' ';
            vyhid << slovo;
            persheSlovo = false;
        }
    }

    cout << "Результат записан в output.txt." << endl;
    return 0;
}
