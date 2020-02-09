#include <iostream>

using namespace std;

int main()
{
    setlocale(0,"rus");
   long long number=0,chanching=0;
   int sum=0;
    cout << "enter your ISBN-13 " << endl;
   cin>>number;
   chanching=number/10;
    for(int i=12;i>0;i--)
    {
      int a=chanching%10;
      chanching=chanching/10;

      if (i%2==0)
      {
           sum=sum+(a*3);
      }
      else
      {
          sum+=a;
      }
    }
if((10-(sum%10)==number%10))
    cout<<"valid ISBN-13\n";
    else
    cout<<"invalid ISBN-13\n";
    //дополнительно
  /* cout << "enter your ISBN-10 " << endl;
   cin>>number;
   chanching=number/10;
    for(int i=10,j=2;i>1;i--,j++)
    {
      int a=chanching%10;
      chanching=chanching/10;
      sum+=a*j;
    }
if((11-(sum%11)==number%10))
    cout<<"valid ISBN-10\n";
    else
    cout<<"invalid ISBN-10\n";*/

    return 0;
}
