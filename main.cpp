#include<iostream>

using namespace std;

struct strin {
	char* str = new char;
	int len=-1;
};
char charAt(strin inp, int numb)
{
	return (inp.str[numb - 1]);

};

strin append(strin inp, char add)
{
	strin outp;
	inp.len++;
	outp.len = inp.len;
	for( int i = 0; i < inp.len; i++){

		outp.str[i] = inp.str[i];
	}
	outp.str[outp.len - 1] = add;
	outp.str[outp.len] = '\0';

	return(outp);
	
};


strin removeChr(strin inp, int pos, int count) {
	strin outp;
	int g = 0;
	for (int i = 0; i < inp.len; i++) {
		if (i == pos-1) {
			i += count-1;
		}
		else
		{
			outp.str[g] = inp.str[i];
			g++;
		}
		
	}

	outp.len = inp.len - count;
	outp.str[outp.len] = '\0';
	return(outp);
};
void concr(strin inp, strin mod) {
	char * str = inp.str;
	int* len = &inp.len;
	for (int i = inp.len; i < inp.len + mod.len; i++) {
		str[i] = mod.str[i - inp.len];
	}
	str[inp.len + mod.len] = '\0';
	*len =inp.len+ mod.len;
}
strin* substring(strin inp, int pos, int count) {
	strin outp;
	int g = 0;
	outp.len = count;
	for (int i = pos - 1; i < pos + count - 1; i++) 
	{
		outp.str[g] = inp.str[i];
		g++;
	}
	outp.str[count] = '\0';
	return(&outp);
}
int main() {
	strin inp;
	strin* newstr;
	cin >> inp.str;
	int inpt;
	char in;
	do {
		inp.len++;
		in = inp.str[inp.len];

	} while (!(in == '\0' ));
	concr(inp, inp);
	newstr = substring(inp, 3, 4);
	cout << inp.str << "\n" <<newstr->str ;
}