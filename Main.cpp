#include <iostream>
using namespace std;
int main()
{int rep;
cout<<"repet times:";
cin>>rep;
for(rep; rep>0;rep--)
{	string inp = "";
	cout << "Enter the numb" << endl;

	cin >> inp;
	char pat;

	inp += "!";
	int cou = 0;
	do
	{
		cou += 1;
	} while (not(int(inp[cou]) == 33));
	cou--;
	int ver, sl;
	if (cou == 12)
	{
	
		ver = 0;
		bool flag = false;
		for (int i = 0; i < cou; i++)
		{
			sl = inp[i] - 48;
			if (flag)
			{
				ver += sl * 3;
				flag = false;
			}
			else
			{
				ver += sl * 1;
				flag = true;
			}
		}
	}
	else
	{
		ver = 0;
		for (int i = 10; i > 1; i--)
		{ver+=(inp[10-i]-48)*i;
			
			
		}
	}

	if (cou == 12)
	{
		cout << "Code type: ISBN-13" << endl
			 << "Validation: ";
		ver = ver % 10;
		if (10 - ver == inp[cou] - 48)
		{
			cout << "Vailid"<<endl;
		}
		else
		{
			cout << "Invailid"<<endl;
			
		}
	}
	else
	{
		cout << "Code type: ISBN-10" << endl
			 << "Validation: ";
			 ver=ver%11;
		if (11 - ver == inp[cou] - 48)
		{
			cout << "Vailid"<<endl;
		}
		else
		{
			cout << "invailid"<<endl;
		}
	}}
}