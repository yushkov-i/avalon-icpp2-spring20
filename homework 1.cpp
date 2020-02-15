#include <iostream>

int main() {
    using namespace std;
    int a;
    int a1;
    int b;
    int c;

cout<<"Enter 12 numbers";
cin>>a;
a1=a;
b=(a/100000000000)*1+(a/10000000000-a/100000000000)*3+(a/1000000000-a/10000000000)*1+(a/100000000-a/1000000000)*3+(a/10000000-a/100000000)*1+(a/1000000-a/10000000)*3+(a/100000-a/1000000)*1+(a/10000-a/100000)*3+(a/1000-a/10000)*1+(a/100-a/1000)*3+(a/10-a/100)*1+(a/10)*3;
c=b/10;
c=10-c;
if(b+c%10==0)
{
true;
cout<<"True indeficator "<<a1;
else
{
false;
cout<<"True indeficator "<<a1;
}
}