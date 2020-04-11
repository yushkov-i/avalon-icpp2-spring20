#pragma once

namespace ext
{
	int countSize(char * data)
	{
		int size = 0;
		while (data[size] != '\0')
		{
			++size;
		}

		return size + 1;
	}

	char characterAt(char * data, int position)
	{
		return data[position - 1];
	}

	char * append(char * data, char symbol)
	{
		int size = countSize(data);

		char * temp = new char[size + 1];
		//	temp = data; неправильно!!!

		for (int i = 0; i < size - 1; ++i)
		{
			temp[i] = data[i];
		}

		temp[size - 1] = symbol;
		temp[size] = '\0';

		return temp;
	}
}
