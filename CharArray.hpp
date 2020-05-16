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

		char* temp = new char[size];
		//	temp = data; неправильно!!!

		for (int i = 0; i < size - 1; ++i)
		{
			temp[i] = data[i];
		}

		temp[size - 1] = symbol;
		temp[size] = '\0';

		return temp;
	}

	char* concatenate(char* data, char* data1)
	{
		int size1 = countSize(data);
		int size2 = countSize(data1);
		int c = 0;
		char* temp = new char[size1 + size2 - 2];
		for (int i = 0; i < size1 - 1; ++i)
		{
			temp[i] = data[i];
			c++;
		}
		for (int i = 0; i < size2 - 1; ++i)
		{
			temp[c] = data1[i];
			c++;
		}
		temp[size1 + size2 - 2] = '\0';
		return temp;
	}

	char* substring(char* data, int position, int length)
	{
		int size = countSize(data);
		char* temp = new char[length];
		position -= 1;
		int c = 0;
		for (int i = position; i < size - 1; ++i)
		{
			temp[c] = data[i];
			c++;
		}
		temp[length] = '\0';
		return temp;
	}

	char* replaceString(char* data, char* targetString, char* replacementText)
	{
		int size = countSize(data);
		int size1 = countSize(targetString);
		int size2 = countSize(replacementText);
		char* temp = new char[100];
		int c = 0;
		int c1 = 0;
		for (int i = 0; i < size - 1; i++)
		{
			int a = i;
			for (int j = 0; j < size1 - 1; j++)
			{
				if (data[a] == targetString[j]) c1++;
				a++;
			}
			if (c1 == size1 - 1)
			{
				for (int k = 0; k < size2 - 1; k++) {
					temp[c] = replacementText[k];
					c++;
				}
				i++;
			}
			else
			{
				temp[c] = data[i];
				c++;
			}
			c1 = 0;
		}
		temp[c] = '\0';
		return temp;
	}
}
