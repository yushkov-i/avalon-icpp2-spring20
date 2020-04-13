#pragma once

namespace ext
{
	using namespace std;
	int countSize(char * data) {
		int size = 0;
		while (data[size] != '\0') {
			++size;
		}
		return size + 1;
	}

	char characterAt(char * data, int position) {
		return data[position - 1];

	}

	char * append(char * data, char symbol) {
		int size = countSize(data);
		char * temp = new char[size + 1];
		for (int i = 0; i < size - 1; i++) {
			temp[i] = data[i];
		}
		temp[size - 1] = symbol;
		temp[size] = '\0';
		return temp;
	}

	char * concatenate(char * data1, char * data2) {
		int count_position = 0;
		int size1 = countSize(data1);
		int size2 = countSize(data2);
		char * temp = new char[size1 + size2 - 1];
		for (int i = 0; i < size1 - 1; i++) {
			temp[i] = data1[i];
		}
		for (int i = size1 - 1; i < size1 + size2; i++) {
			temp[i] = data2[count_position];
			count_position++;
		}
		return temp;
	}

	char * substring(char * data, int first, int length) {
		int size = length;
		char * temp = new char[size];
		for (int i = 0; i < length; i++) {
			temp[i] = data[first - 1];
			first++;
		}
		temp[size] = '\0';
		return temp;
	}

	char * replaceString(char * data_main, char * data_find, char * data_change) {
		int raznosti = countSize(data_change) - countSize(data_find);
		int i = 0, position = 0, quantity_find = 0;
		int count_for__position_find = 1;
		while (data_main[i] != '\0') {
			if (data_main[i] == data_find[0]) {
				for (count_for__position_find; count_for__position_find < countSize(data_find) - 1; count_for__position_find++) {
					if (data_main[i + count_for__position_find] != data_find[count_for__position_find]) {
						count_for__position_find = 1;
						break;
					}
					position++;
					if (position == countSize(data_find) - 2) {
						quantity_find++;
						position = 0;
						i = i + countSize(data_find) - 2;
					}
				}
				count_for__position_find = 1;
				position = 0;
			}
			i++;
		}
		i = 0;
		char * newData = new char[countSize(data_main) + raznosti * quantity_find];
		int count_position_newData = 0;
		while (data_main[i] != '\0') {
			if (data_main[i] == data_find[0]) {
				for (count_for__position_find; count_for__position_find < countSize(data_find) - 1; count_for__position_find++) {
					if (data_main[i + count_for__position_find] != data_find[count_for__position_find]) {
						count_for__position_find = 1;
						break;
					}
					position++;
					if (position == countSize(data_find) - 2) {
						for (int j = 0; j < countSize(data_change) - 1; j++) {
							newData[count_position_newData] = data_change[j];
							count_position_newData++;
						}
						i = i + countSize(data_find) - 2;
						position = 0;
					}
				}
				count_for__position_find = 1;
				position = 0;
			}
			else {
				newData[count_position_newData] = data_main[i];
				count_position_newData++;
			}
			i++;
		}
		newData[countSize(data_main) + raznosti * quantity_find - 1] = '\0';
		return newData;
	}


}
