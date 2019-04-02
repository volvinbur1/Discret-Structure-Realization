#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void counting_sort(vector<int> &_arr);

int main()
{
	vector<int> arr;// = { 9, 6, 8, 3, 5, 1 };
	
	size_t arr_size;//= sizeof(arr) / sizeof(arr[0]);

	std::fstream file;

	file.open("CountingSortarray_data.txt");

	while (!file.eof())
	{
		std::string data;
		getline(file, data);
		arr.push_back(stoi(data));
		//arr_size++;
	}
	
	file.close();

	arr_size = arr.size();

	clock_t start_time = clock();

	counting_sort(arr);

	double run_time = (clock() - start_time) / CLOCKS_PER_SEC;

	for (int i = 0; i < arr_size; i++)
		printf("%d\t", arr[i]);

	printf("\nAn array was sorted for %.2fs\n", run_time);
	system("Pause");
}

void counting_sort(vector<int> &_arr)
{
	int max = INT32_MIN, min = INT32_MAX;

	for (uint32_t i = 0; i < _arr.size(); i++)
	{
		if (_arr[i] > max)
			max = _arr[i];
		if (_arr[i] < min)
			min = _arr[i];
	}

	int size = _arr.size();
	int* counting_arr = new int[(max - min) + 1];
	int* output_arr = new int[size];

	for (uint32_t i = 0; i <= (max - min); i++)
		counting_arr[i] = 0;

	for (int32_t i = 0; i < size; i++)
		counting_arr[_arr[i] - min]++;

	for (uint32_t i = 1; i <= (max - min) ; i++)
		counting_arr[i] += counting_arr[i - 1];

	for (int32_t i = size - 1; i >= 0; i--)
	{
		output_arr[counting_arr[_arr[i] - min] - 1] = _arr[i];
		--counting_arr[_arr[i] - min];
	}

	for (uint32_t i = 0; i < size; i++)
		_arr[i] = output_arr[i];

	delete[] counting_arr;
	delete[] output_arr;
}
