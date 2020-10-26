#include "HeaderK2L1V35.h"

#include <iostream>

int main()
{
	int arr_i = 0, arr_j = 0, num = 0;
	int Narr_i = 0, Narr_j = 0, Nnum = 0;

	int n = 0, m = 0;

	int k = 1;

	int Nk = 1;

	int cur_size = 0;

	int Ncur_size = 0;

	int opt = 1;

	Element* arr = nullptr;
	Element* Narr = nullptr;

	std::cout << "Enter n:\n> ";

	GetNum(n);
	
	std::cout << "Enter m:\n> ";

	GetNum(m);

	int N = 0;
	while (opt)
	{
		std::cout << "Exit(0), Add new element(1), Print(2)\n> ";

		GetNum(opt);

		if (opt == 1)
		{
			if (!GetNumI(n, arr_i))
			{
				if (GetNumJ(m, arr_j, arr, cur_size, arr_i))
					std::cout << "Try again!\n";

				else
				{
					Narr_i = arr_i;
					Narr_j = arr_j;
					N = AddElem(cur_size, k, &arr, arr_i, arr_j, 1, N);
					AddElem(Ncur_size, Nk, &Narr, Narr_i, Narr_j, 0, N);
				}
			}
		}

		else if (opt == 2)
			Printing(arr, cur_size);
	}
	std::cout << "\n**************\n>The original Matrix:\n";
	Printing(arr, cur_size);
	std::cout << "\n**************\n>Ready-made Matrix:\n";
	PrintingREADY(Narr, cur_size);

	return 0;
}























/*delete[] arr;
int arrREADY_i = arr_i;
int arrREADY_j = arr_j;
int numREADY   = num;

int nREADY = n;
int mREADY = m;

int k = 1;

int cur_size = 0;

int opt = 1;

Element* arr = nullptr;

































int* b = new int[n];

for (int i{}; i < n; i++)
	b[i] = 0;

int prev{};

for (int i{}; i < n; i++)
{
	int sum{};

	for (int j = prev; j < cur_size && arr[j].i == arr[prev].i; j++)
	{
		if (SumOfANumeral(arr[prev].num) == SumOfANumeral(arr[j].num))
		{
			sum += arr[j].num;
		}

		prev = j;
	}

	prev++;

	b[i] = sum;
}

delete[] arr;

arr = nullptr;

std::cout << "b[n] = (";

for (int i = 0; i < n; i++)
{
	if (i == n - 1)
		std::cout << b[i] << ")";

	else
		std::cout << b[i] << ",";
}

delete[] b;

b = nullptr;

return 0;
}*/
