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

	char* concatenate(char* data, char* data2) {
		int size = countSize(data);
		int size2 = countSize(data2);
		char* temp = new char[size + size2];
		for (int i = 0; i < size - 1; ++i)
		{
			temp[i] = data[i];
		}
		for (int i = size - 1; i < size + size2 - 1; ++i)
		{
			temp[i] = data2[i - size + 1];
		}
		return temp;
	}

	char* substring(char* data, int position, int length) {
		char* temp = new char[length - 1];
		for (int i = position, j = 0; i < position + length, j < length; ++j, ++i)
		{
			temp[j] = data[i - 1];
		}
		temp[length] = '\0';
		return temp;
	}
	char* replaceString(char* data, char* target, char* replaceable) {
		int size = countSize(data);
		int sizeTarget = countSize(target);
		int sizeReplaceable = countSize(replaceable);
		char* temp = new char[size + (sizeReplaceable-1)*(size/(sizeTarget-1))];
		int i = 0;
		int n = 0;
		bool notTarget=false;
		while (data[i] != '\0') {


			notTarget = true;
			if (data[i] == target[0]) {
				
				for (int j = i, k=0; j < i + sizeTarget-1,k<sizeTarget-1; ++j,++k) {
					if (data[j] == target[k]) {
						notTarget = false;
					}
				}
				if (notTarget == false) {
					for (int j = n, k = 0; j < n + sizeReplaceable-1, k < sizeReplaceable-1 ; ++j, ++k) {
						temp[j] = replaceable[k];
					}
					n += sizeReplaceable-1;
				}
				if (notTarget == false) {
					i += sizeTarget ;
				}
			}
			if (notTarget==true){
				temp[n] = data[i];
			}
			i++;
			n++;
		}
		temp[n] = '\0';
		return temp;

	}
}