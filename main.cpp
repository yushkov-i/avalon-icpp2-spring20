#include <iostream>

using namespace std;

int main()
{
    setlocale(0,"rus");
   int number=0,sum=0,chanching=0;
   cout << "¬ведите ваш ISBN-10 " << endl;
   cin>>number;
   chanching=number/10;
    for(int i=10,j=2;i>1;i--,j++)
    {
      int a=chanching%10;
      chanching=chanching/10;
      sum+=a*j;
    }
if((11-(sum%11)==number%10))
    cout<<"действительный ISBN-10\n";
    else
    cout<<"недействительный ISBN-10\n";
    return 0;
}
