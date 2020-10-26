#include "HeaderK2L1V35.h"

#include <iostream>

void GetNum(int& a)
{
	while (1)
	{
		if (std::cin >> a)
			break;

		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Try again!\n";
	}
}

int GetNumI(int n, int& coord)
{
	while (1)
	{
		std::cout << "Enter i\n> ";

		if (std::cin >> coord && coord < n)
			break;

		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Try again!\n";
	}

	return 0;
}

int AddElem(int& size, int& k, Element** arr, int arr_i, int arr_j, int Flag, int N)
{
	int num = 0;
	if (Flag == 1)
	{
		std::cout << "Enter num\n> ";

		GetNum(num);

		while (!num) {
			if (num == 0)
			{
				std::cout << "Try again!\nNum can't be zero\n\n";
				GetNum(num);
			}

		}
	}
	else
		num = N;

	if (size == k || (*arr) == nullptr)
	{
		k *= 2;

		Element* arr_new = new Element[k];

		if ((*arr) != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				arr_new[i].i = (*arr)[i].i;

				arr_new[i].j = (*arr)[i].j;

				arr_new[i].num = (*arr)[i].num;

				arr_new[i].Check = (*arr)[i].Check;
			}
		}

		delete[](*arr);

		(*arr) = nullptr;

		if (size < k)
		{
			arr_new[size].i = arr_i;

			arr_new[size].j = arr_j;

			arr_new[size].num = num;

			if (CheckProblem(num))
				arr_new[size].Check = 1;
			else
				arr_new[size].Check = 0;

			(*arr) = arr_new;
		}
	}

	else
	{
		(*arr)[size].i = arr_i;

		(*arr)[size].j = arr_j;

		(*arr)[size].num = num;

		if (CheckProblem(num))
			(*arr)[size].Check = 1;
		else
			(*arr)[size].Check = 0;
	}

	size++;

	return num;
}

int GetNumJ(int m, int& coord, Element* arr, int k, int arr_i)
{
	while (1)
	{
		std::cout << "Enter j\n> ";

		if (std::cin >> coord && coord < m)
			break;

		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Try again!\n";
	}

	if (SearchJ(arr, coord, k, arr_i))
		return 1;

	return 0;
}

int SearchJ(Element* arr, int j, int k, int arr_i)
{
	for (int i{}; i < k ; i++)
	{
		if (arr_i == arr[i].i && arr[i].j == j)
		{
			std::cout << "Element already exists! ";

			return 1;
		}
	}

	return 0;
}

int CheckProblem(int num)
{
	int res = num;
	int flag = 0;
	int a = 0;

	if (num == 0)
		return 0;

	while (res)
	{
		a = res % 10;

		if (a < 5)
			flag = 1;

		res /= 10;
	}

	if (!flag)
		return 1;

	return 0;
}

void Sorting(Element* arr, int size)
{
	int add_i{}, add_j{}, add_num{};

	Element add{};

	//for (int i = 0; i < k; i++)

	for (int i{}; i < size; i++)
	{
		for (int j{}; j < size; j++)
		{
			if (arr[i].i < arr[j].i)
			{
				add = arr[j];
				arr[j] = arr[i];
				arr[i] = add;
			}
		}
	}

	for (int i{}; i < size; i++)
	{
		for (int j{}; j < size; j++)
		{
			if (arr[i].i == arr[j].i && arr[i].j < arr[j].j)
			{
				add = arr[j];
				arr[j] = arr[i];
				arr[i] = add;
			}
		}
	}
}

void Printing(Element* arr, int k)
{
	Sorting(arr, k);

	for (int i = 0; i < k; i++)
	{
		std::cout << i + 1 << " element:\n ";
		std::cout << "(" << arr[i].i << ", " << arr[i].j << ") - " << arr[i].num;

		std::cout << "\n";
	}
}

void PrintingREADY(Element* arr, int k)
{
	int Flag = 0;
	Sorting(arr, k);
	
	for (int i = 0; i < k; i++)
	{
		if (arr[i].Check)
		{
			Flag++;
			std::cout << i + 1 << " element:\n ";
			std::cout << "(" << arr[i].i << ", " << arr[i].j << ") - " << arr[i].num;

			std::cout << "\n";
		}
	}
	if (!Flag)
		std::cout << "\n!!!No matching elements!!!\n ";
}
