#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;

int main()
{
    int table[10][12];
        for(int i=0; i<10; i++)
    {
        for(int j=0; j<12; j++)
        {
           table[i][j] =-1;
        }
    }
    for(int i=0; i<10; i++)
    {
        int k=GetRandomValue(0, 5);
        int l=GetRandomValue(k+2, 11);
        for(int j=k; j<=l; j++)
        {
            table[i][j]=GetRandomValue(1000, 100000);
            
        }
       
    }
        for(int i=0; i<10; i++)
    {
        for(int j=0; j<12; j++)
        {
           cout << table[i][j] << ' ';
        }
        cout << endl;
    }
        for(int i=0; i<10; i++)
    {
         for(int j=0; j<12; j++)
         {
        for(int k=0; k<12; k++)
        {
            if(table[i][k] > table [i][k+1]) {int temp=table[i][k]; table[i][k]=table[i][k+1]; table[i][k+1]=temp;}
        }
    }
    }
    int M=0;
    int Ma=-1;
for(int i=0; i<10; i++)
{
    for(int j=0; i<12; i++)
{
    if(table[i][j]!=-1) 
    {
        int m=0;
        if((10-j) %2 ==1 ) {m=table[i][(12-j)/2];}
        else {m=table[i][((12-j)/2+(12-j)/2+1)/2];}
        if(m>M) {M=m;Ma=i;}
    }
}
}
cout << "Лучший агент: " << Ma << endl;
cout << "Медиана: " << M<< endl;
}
