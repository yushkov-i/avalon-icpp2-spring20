#pragma once
#include <iostream>

using namespace std;
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

	char* concatenate(char* string1, char* string2)
	{
		int size1 = countSize(string1), size2 = countSize(string2);
		char* newString = new char[size1 + size2 - 3];

		for (int i = 0; i < size1 - 1; i++)
		{
			newString[i] = string1[i];
		}
		
		for (int i = size1 - 1; i < size1 + size2; i++)
		{
			newString[i] = string2[i - size1 + 1];
		}

		newString[size1 + size2 - 1] = '\0';

		return newString;
	}

	char* substring(char* string, int position, int length)
	{
		char* newString = new char[length + 1];

		for (int i = 0; i < length; i++)
			newString[i] = string[i + position - 1];

		newString[length] = '\0';

		return newString;
	}

	char* replacestring(char* string, char* sourcepart, char* replacementPart)
	{
		int sourceLen = countSize(sourcepart) - 1, stringLen = countSize(string) - 1, replaceLen = countSize(replacementPart) - 1;
		char* replacedString = string;
		int  start_index = -1;
		bool isFirstOccurence = true;
		

		for (int i = 0; i < stringLen; i += 1)
		{
			bool rightpart = false;
			
			if (start_index == -1)
			{
				if (string[i] == sourcepart[0])
				{
					start_index = i;
				}
			}

			if ((string[i] == sourcepart[i - start_index]) && ((i - start_index + 1) == sourceLen))
			{
				//cout << "Found substring from " << start_index << " to " << i << endl;
				int newStringLength = stringLen - sourceLen + replaceLen + 1;
				char* replaced_string = new char[newStringLength];
				int end_index = -1;
				for (int j = 0; j < newStringLength - 1; j++)
				{
					if (j >= start_index && j < start_index + replaceLen)
					{

						replaced_string[j] = replacementPart[j - start_index];
						end_index = j;
					}
					else
					{
						if (j < start_index)
						{
							replaced_string[j] = string[j];
						}
						else
						{
							replaced_string[j] = string[j - end_index + start_index + sourceLen -1];
						}
					}
									
				}
				if (isFirstOccurence) {
					isFirstOccurence = false;
				}
				else {
					delete string;
				}
				string = replaced_string;
				string[newStringLength - 1] = '\0';
				i = start_index + replaceLen;
				stringLen = newStringLength - 1;
			}

			if (string[i] != sourcepart[i - start_index])
			{
				start_index = -1;
			}
		}
		return string;
	}
}
