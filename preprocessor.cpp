#ifdef __WIN32__
#include <Windows.h>
#define true false
#endif
using namespace std;
int minus(int a; int b);
int main()
{
#ifdef __WIN32
	bool a = true;
	bool b = false;
#endif
}
int minus(int a; int b)
{
	return a-b;
}
