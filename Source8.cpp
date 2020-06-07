#include <fstream>
#include <iostream>
using namespace std;



int main()
{
    int ticket = 0, lucky = 0, unlucky = 0;
    ifstream T("tickets.txt");
    ofstream l("l.txt");
    ofstream unl("unl.txt");
    for (int i = 0; i < 1000; i++) {
        T >> ticket;
        if ((ticket / 100000 + ticket / 10000 % 10 + ticket / 1000 % 10) == (ticket / 100 % 10 + ticket / 10 % 10 + ticket % 10)) {
            l << ticket << endl;
            lucky++;
        }
        else {
            unl << ticket << endl;
            unlucky++;
        }
    }
    cout << "Lucky tikets =  " << lucky << " ; unlucky tikets  = " << unlucky << endl;


}