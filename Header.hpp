#pragma once

namespace ext

{
	int countSize(char* data) // размер, учитывая последний символ \0
	{
		int size = 0;
		while (data[size] != '\0')
		{
			++size;
		}

		return size + 1;
	}

	char characterAt(char* data, int position) {
		return data[position - 1];
	}

	char* append(char* data, char symbol) {
		int size = countSize(data);
		char* temp = new char[size + 1];
		for (int i = 0; i < size - 1; ++i) {
			temp[i] = data[i];
		}
		temp[size - 1] = symbol;
		temp[size] = '\0';
		return temp;
	}

	char* concatenate(char* data, char* add) {
		int s1, s2, o;
		s1 = countSize(data);
		s2 = countSize(add);
		char* k = new char[s1 + s2 - 3];
		for (int i = 0; i < s1 - 1; i++) {
			k[i] = data[i];
		}
		o = 0;
		for (int i = s1 - 1; i < s1 + s2 - 1; i++) {
			k[i] = add[o];
			o++;
		}
		k[s1 + s2 - 2] = '\0';
		return k;
	}

	char* substring(char* data, int first_pos, int size) {
		char* tmp = new char[size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = data[i + first_pos - 1];
		}
		tmp[size] = '\0';
		return tmp;
	}

	/* char* replaceString(char* data, char* a, char* b) {
		int size_b = countSize(b);
		int size_data = countSize(data);
		int tmp_size = size_data, x{}, times{}, y{};
		int size_a = countSize(a);
		char tt;
		bool k;
		for (int i = 0; i < size_data; i++) {
			if (data[i] == a[0]) {
				x = i;
				k = 1;
				for (int j = 1; j < size_a; j++) {
					x++;
					if (data[x] != a[j]) {
						k = 0;
						break;
					}
				}
				if (k == 1) {
					times++;
					tmp_size = tmp_size - size_a + size_b;
					i = x;
				}
			}
		}
		char* tmp = new char[tmp_size];
		tmp = data;
		y = 0;
		for (int i = 0; i < size_data; i++) {
			if (data[i] == a[0]) {
				x = i;
				k = 1;
				for (int j = 1; j < size_a; j++) {
					x++;
					if (data[x] != a[j]) {
						k = 0;
						break;
					}
				}
				if (k == 1) {
					for (int u = size_data + y * () - 1; u > i; u--) {
						tmp[u + size_b - 1]
						
					}
					for (int u = i; u < i + size_b; u++) {
						tmp[]
					}
					i = x;
					y++;
					times--;
				}
			}
		}
	} */
}