#pragma once

namespace ext
{
	char characterAt(char * str, int pos)
	{
		return str[pos - 1];
	}

	namespace impl
	{
		// "Hello\0" => 5 
		int countLength(char * str)
		{
			int count = 0;
			while (str[count] != '\0')
			{
				++count;
			}

			return count + 1;
		}
	}	

	void append(char * &str, char symbol)
	{
		int oldLength = impl::countLength(str);
		char * newStr = new char[oldLength + 1];

		for (int i = 0; i < oldLength - 1; ++i)
		{
			newStr[i] = str[i];
		}
		newStr[oldLength - 1] = '!';
		newStr[oldLength] = '\0';

		delete[] str;
		str = newStr;
	}

	void concatenate(char * &firstStr, char * secondStr)
	{

	}

	char * substring(char * str, int pos, int length)
	{

	}

	void replaceString(char * &str, char * from, char * to)
	{

	}
}
