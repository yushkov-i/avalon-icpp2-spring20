#include <iostream>
using namespace std;
int main()
{
    char ISBN[14];
    int weight=0;
    cout << ("Введите ISBN: ");
    for(int i=0; i<13; i++)
    {
        cin >> ISBN[i+1];
        ISBN[i+1]-=48;
        if(i!=12)
        {
        if(i%2 == 0) {weight += ISBN[i+1];}
        else {weight += ISBN[i+1]*3;}
        }
    }
    weight = weight % 10;
    for(int i =0;weight++;i++){if (weight % 10 ==0) {weight=i+1; break;};}
    if(ISBN[13]==weight) {cout << "ISBN действителен ";}
    else  {cout << "ISBN недействителен ";}
}

