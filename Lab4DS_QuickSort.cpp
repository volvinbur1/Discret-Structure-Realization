#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

void quick_sort(int arr[], int lower, int higher);
int partation(int arr[], int lower, int higher);
void swap(int *a, int *b);

int main()
{
	int arr[100];// = { 9, 6, 2, 7, 1, 3 };

	int n = 0; //sizeof(arr) / sizeof(arr[0]);

	std::fstream file;

	file.open("QSarray_data.txt");

	while (!file.eof())
	{
		std::string data;
		getline(file, data);
		arr[n] = stoi(data);
		n++;
	}

	file.close();

	clock_t start_time = clock();

	quick_sort(arr, 0, n - 1);

	double run_time = (clock() - start_time) / CLOCKS_PER_SEC;

	for (int i = 0; i < n; i++)
		printf("%d\t", arr[i]);

	printf("\nAn array was sorted for %.2fs\n", run_time);

	system("Pause");
}

void quick_sort(int arr[], int lower, int higher)
{
	if (lower < higher)
	{
		int part_index = partation(arr, lower, higher);

		quick_sort(arr, lower, part_index - 1);
		quick_sort(arr, part_index + 1, higher);
	}
}

int partation(int arr[], int lower, int higher)
{
	int bigger_index = lower;

	for (int j = lower; j <= higher - 1; j++)
	{
		if (arr[j] <= arr[higher])
			swap(&arr[bigger_index++], &arr[j]);
	}

	swap(&arr[bigger_index], &arr[higher]);

	return bigger_index;
}

void swap(int *a, int *b)
{
	int temprorary = *a;
	*a = *b;
	*b = temprorary;
}
