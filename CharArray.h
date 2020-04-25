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

	char* concatenate(char* data1, char* data2) {
		int size = countSize(data1) + countSize(data2) - 1;    // abcd\0     def\0
		char* temp = new char[size];					   // 0123			

		for (int i = 0; i < size; ++i) {
			if (i < countSize(data1)-1) {
				temp[i] = data1[i];
			}
			else temp[i] = data2[i - countSize(data1) + 1];
		}
		// 		temp[size] = '\0';   строка не нужна тк в отличие от предыдущей функции присоединяем к строке строку и '\0' уже есть.

		return temp;

	}

	char* substring(char* data, int position, int len) {
		char* temp = new char[len];
		for (int i=0; i < len; i++) {
			temp[i] = data[position + i -1];
		}
		temp[len] = '\0';
		return temp;
	}
	char* replaceString(char* mainDate, char* foundDate, char* addDate) {
		
		return 0;
	}
}