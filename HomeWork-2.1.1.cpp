#include <iostream>
#include <fstream>

int* fullArr(const int& count, std::ifstream& f)
{
	int* tmp = new int[count];
	for (int i = 0; i < count; ++i) {
		f >> tmp[i];
	}
	return tmp;
}

void shiftLeft(int* arr, const int& size) {
	int left = arr[size - 1];
	for (int i = size - 1; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
	arr[0] = left;
}

void shiftRight(int* arr, const int& size) {
	int right = arr[0];
	for (int i = 0; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = right;
}

void writeArr(const int* arr, const int& size, std::ofstream& f) {
	for (int i = 0; i < size; ++i) {
		f << arr[i] << " ";
	}
}

int main()
{
	std::ifstream f_in("in.txt");
	std::ofstream f_out("out.txt");
	int size_arr1;
	int size_arr2;
	int* arr1;
	int* arr2;

	setlocale(LC_ALL, "Russian");

	if (!f_in.is_open()) {
		std::cout << "Не удалось открыть фаил" << std::endl;
		return 1;
	}
	f_in >> size_arr1;
	arr1 = fullArr(size_arr1, f_in);
	f_in >> size_arr2;
	arr2 = fullArr(size_arr2, f_in);
	f_in.close();

	shiftLeft(arr2, size_arr2);
	shiftRight(arr1, size_arr1);

	f_out << size_arr2 << std::endl;
	writeArr(arr2, size_arr2, f_out);
	f_out << std::endl;
	f_out << size_arr1 << std::endl;
	writeArr(arr1, size_arr1, f_out);

	f_out.close();
	delete [] arr1;
	delete [] arr2;
}