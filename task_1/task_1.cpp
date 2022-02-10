﻿/*
1. Создать массив из 10 случайных чисел в диапазоне от -20 до 20.
Преобразовать массив так, чтобы сначала шли все отрицательные
элементы, а затем положительные (0 считать положительным).
*/
/*
 Изначальный		-19, 18, 1, -12, -16, 11, -13, 12, -8, -12
 Отсортированный	-19, -12, -16, -13, -8, -12, 18, 1, 11, 12
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // Работает только с потоком вывода.
	srand(time(0));
	/*
		Функция srand() используется для установки начала последовательности,
	генерируемой функ­цией rand() (функция rand() возвращает псевдослучайные числа).
		Функция srand() позволяет запускать программу несколько раз	с различными
	последователь­ностями псевдослучайных чисел.
	*/

	int min{ -20 }; // Минимальное значение диапазона.
	int max{ 20 }; // Максимальное значение диапазона.
	const int arr_1_Size{ 10 }; // Размер массива.

	int arr_1[arr_1_Size]{ 0 }; // Создаем массив.

	for (int i = 0; i < arr_1_Size; i++) // Заполняем 1 массив и выводим.
	{
		arr_1[i] = rand() % (max - min + 1) + min;
		cout << arr_1[i] << "\t";
	}
	cout << endl;

	for (int i = 1; i < arr_1_Size; i++)
	{
		int key = arr_1[i]; // Ключевой элемент.
		int j = i - 1;
		while (j >= 0 && arr_1[j] >= 0 && key < 0)
		{
			arr_1[j + 1] = arr_1[j];
			j--;
		}
		arr_1[j + 1] = key;
	}

	for (int i = 0; i < arr_1_Size; i++) // Выводим 1 массив.
	{
		cout << arr_1[i] << "\t";
	}
	cout << endl;

	return 0;
}