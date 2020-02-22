#ifdef __WIN32__
#include <Windows.h>
#define true false
#endif
using namespace std;
int main()
{
#ifdef __WIN32
	bool a = true;
	bool b = false;
#endif
}
