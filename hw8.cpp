#include <fstream>
#include <iostream>
using namespace std;



int main()
{
    int ticket = 0;
    int luckCount = 0;
    int unluckCount = 0;
    ifstream input;
    input.open("tickets.txt");
    ofstream luckOutput;
    luckOutput.open("lucky.txt");
    ofstream unluckOutput;
    unluckOutput.open("unlucky.txt");
    if (!input.is_open() || !luckOutput.is_open() || !unluckOutput.is_open()) {
        cout << "tickets.txt did not open!" << endl;
        return 1;
    }
    for (int i = 0; i < 1000; i++){
        input >> ticket;
        if (ticket / 100000 + ticket / 10000 % 10 + ticket / 1000 % 10
            == ticket / 100 % 10 + ticket / 10 % 10 + ticket % 10) {
            luckOutput << ticket << endl;
            luckCount++;
        }
        else{
            unluckOutput << ticket << endl;
            unluckCount++;
            }
    }
    cout << "there are " << luckCount << " lucky tickets and " << unluckCount << " unlucky tickets." << endl;


}

