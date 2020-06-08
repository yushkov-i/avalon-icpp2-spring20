#pragma once
#include <iostream>

namespace ext
{
	int StrLen(char* str)//без \0
	{
		int size=0;
		for (; str[size] != '\0'; size++);
		return size;
	}
	
	char characterAt(char* str, int position)
	{
		return str[position - 1];
	}

	char* append(char* str, char symbolAdd)
	{
		int lsize = StrLen(str);

		char* newstr = new char[lsize + 2];
		for (int i = 0; i < lsize; i++)
		{
			newstr[i] = str[i];
		}
		newstr[lsize] = symbolAdd;
		newstr[lsize + 1] = '\0';

		return newstr;
	}

	char* concatenate(char* str1, char* str2)
	{
		int sizeStr1 = StrLen(str1);
		int sizeStr2 = StrLen(str2) + 1;
		char* newstr = new char[sizeStr1 + sizeStr2];
		
		int i = 0;
		for (; i < sizeStr1; i++)
			newstr[i] = str1[i];
		for (int j=0; j < sizeStr2; i++, j++)
			newstr[i] = str2[j];

		return newstr;
	}

	char* substring(char* str, int start, int len)
	{
		char* newstr = new char[len + 1];

		for (int i = 0; i < len; i++)
		{
			newstr[i] = str[start-1 + i];
		}
		newstr[len] = '\0';

		return newstr;
	}

	char * replaceString(char* origStr, char* searchStr, char* replaceStr)
	{
		int origSize = StrLen(origStr);
		int searchSize = StrLen(searchStr);
		int replaceSize = StrLen(replaceStr);

		char* newstr = new char[origSize / searchSize * replaceSize];

		int coincidence=0;
		int newpos = 0;

		for (int i = 0; i < origSize; i++)
		{	
			if (origStr[i] == searchStr[coincidence]) coincidence++;
			else
			{
				for (int j = 0; j <= coincidence; j++)
					newstr[newpos + j] = origStr[i- coincidence+j];
				newpos += coincidence+1;
				coincidence = 0;
			}
			if (coincidence == searchSize)
			{
				for (int j = 0; j < replaceSize; j++)
					newstr[newpos + j] = replaceStr[j];
				newpos += replaceSize;
				coincidence = 0;
			}
		}
		
		newstr[newpos]='\0';

		return substring(newstr, 1, newpos + 1);
	}

}