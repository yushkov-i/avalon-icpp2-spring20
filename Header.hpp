#pragma once

namespace ext
{
	int countSize(char* data)
	{
		int size = 0;
		while (data[size] != '\0')
		{
			++size;
		}

		return size + 1;
	}

	char characterAt(char* data, int position)
	{
		return data[position - 1];
	}

	char* append(char* data, char symbol)
	{
		int size = countSize(data);

		char* temp = new char[size + 1];
		//	temp = data; неправильно!!!

		for (int i = 0; i < size - 1; ++i)
		{
			temp[i] = data[i];
		}

		temp[size - 1] = symbol;
		temp[size] = '\0';

		return temp;
	}

	char* concatenate(char* fstr, char* sstr)
	{
		int size = countSize(fstr);
		int size2 = countSize(sstr);
		int newsize = size + size2 -1;

		char* temp = new char[newsize];

		for (int i = 0; i < size - 1; ++i)
		{
			temp[i] = fstr[i];
		}
		for (int i = 0; i < size2 ; ++i)
		{
			temp[i + size-1] = sstr[i];
		}
	
		return temp;
	}

	char* substring(char* str, int pos, int lenght)
	{
		char* temp = new char[lenght + 1];
		int i = 0;
		int leg = lenght;
		while (leg != 0)
		{
			temp[i] = str[pos-1 + i];
			i++;
			leg--;
		}
		temp[lenght] = '\0';
		return temp;
	}
}	
