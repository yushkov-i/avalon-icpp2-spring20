#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << "Введите кол-во ISBN: ";
    int N;
    cin >> N;
    cout << "Введите год ISBN(например: 2007) и ISBN" << endl;
    cout << "Год: ";
    int isbnYear;
    cin >> isbnYear;

    char isbn[13];

    char chpom[2];
    chpom[1] = '\0';
    int tec, i;

    for (int k = 1; k <= N; k++)
    {
        cout << "ISBN: ";
        cin >> isbn;

        tec = 0;
        if (isbnYear > 2007)
        {
            for (i = 0; i <= 11; i++)
            {
                chpom[0] = isbn[i];
                tec += atoi(chpom) * (2 + pow(-1, 1 + i % 2));
            }

            tec %= 10;
            if (tec) tec = 10 - tec;
        }
        else
        {
            for (i = 0; i <= 8; i++)
            {
                chpom[0] = isbn[i];
                tec += atoi(chpom) * (10 - i);
            }
            tec %= 11;
            if (tec) tec = 11 - tec;

            if (isbn[i] == 'X' && tec == 10)
            {
                cout << "valid" << endl;
                continue;
            }
        }

        chpom[0] = isbn[i];
        if (atoi(chpom) == tec) cout << "valid";
        else cout << "invalid";
        cout << endl;
    }
}
