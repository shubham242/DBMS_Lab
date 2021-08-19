#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream file;
    srand(time(0));
    file.open("data.csv");
    for (int i = 0; i < 100; i++)
    {
        char a = rand() % 8 + 65;
        file << rand() % 4 + 1 << " " << rand() % 6 + 1 << " " << a << " " << rand() % 20 + 1 << "\n";
    }
}