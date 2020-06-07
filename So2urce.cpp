
namespace ext
{
	int countSize(char* d)
	{
		int s = 0;
		while (d[s] != '\0')
		{
			++s;
		}

		return s + 1;
	}

	char characterAt(char* d, int p)
	{
		return d[p - 1];
	}

	char* append(char* d, char sy)
	{
		int s = countSize(d);

		char* t = new char[s + 1];

		for (int i = 0; i < s - 1; ++i)
		{
			t[i] = d[i];
		}

		t[s - 1] = sy;
		t[s] = '\0';

		return t;
	}

	char* concatenate(char* d1, char* d2) {
		int a = countSize(d1) + countSize(d2) - 1;   
		char* t = new char[a];			

		for (int i = 0; i < a; ++i) {
			if (i < countSize(d1) - 1) {
				t[i] = d1[i];
			}
			else t[i] = d2[i - countSize(d1) + 1];
		}

		return t;

	}

	char* substring(char* d, int p, int l) {
		char* o = new char[l];
		for (int i = 0; i < l; i++) {
			o[i] = d[p + i - 1];
		}
		o[l] = '\0';
		return o;
	}
	char* replaceString(char* mD, char* fD, char* aD) {

		return 0;
	}
}