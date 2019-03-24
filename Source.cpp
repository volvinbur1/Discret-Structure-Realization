#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

void shell_sort(int arr[], uint32_t n)
{
	for (int d = n / 2; d >= 1; d /= 2)
		for (int i = d; i < n; i++)
		{
			int temp = arr[i];

			int itr = i;
			while (itr >= d && temp < arr[itr - d])
			{
				arr[itr] = arr[itr - d];
				itr -= d;
			}
			arr[itr] = temp;
		}
}

int main()
{
	int arr[100];// = { 9, 6, 2, 7, 1, 3 };
	
	uint32_t n = 0;// = sizeof(arr) / sizeof(arr[0]);

	std::fstream file;

	file.open("SSarray_data.txt");

	while (!file.eof())
	{
		std::string data;
		getline(file, data);
		arr[n] = stoi(data);
		n++;
	}

	file.close();

	clock_t start_time = clock();

	shell_sort(arr, n);

	double run_time = (clock() - start_time) / CLOCKS_PER_SEC;

	for (int i = 0; i < n; i++)
		printf("%d\t", arr[i]);

	printf("\nAn array was sorted for %.2fs\n", run_time);

	system("Pause");
}