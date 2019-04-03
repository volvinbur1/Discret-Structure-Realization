#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#define BUCKET_AMOUNT 10

using namespace std;

void bucket_sort(vector<int> &_arr, int _devider, size_t _size);
void insertation_sort(queue<int> &q);

int main()
{
	vector<int> arr;// = { 9, 6, 8, 3, 5, 1 };
;
	size_t arr_size;//= sizeof(arr) / sizeof(arr[0]);

	std::fstream file;

	file.open("BucketSortarray_data.txt");

	while (!file.eof())
	{
		std::string data;
		getline(file, data);
		arr.push_back(stoi(data));
		//arr_size++;
	}

	arr_size = arr.size();

	file.close();

	int max = INT32_MIN;

	for (size_t i = 0; i < arr_size; i++)
		if (arr[i] > max)
			max = arr[i];

	clock_t start_time = clock();

	bucket_sort(arr, (int)ceil((max+1) / BUCKET_AMOUNT), arr_size);

	double run_time = (clock() - start_time) / CLOCKS_PER_SEC;

	for (int i = 0; i < arr_size; i++)
		printf("%d\t", arr[i]);

	printf("\nAn array was sorted for %.2fs\n", run_time);
	system("Pause");
}

void bucket_sort(vector<int> &_arr, int _devider, size_t _size)
{
	queue<int> buckets[BUCKET_AMOUNT];

	for (size_t i = 0; i < _size; i++)
		buckets[_arr[i] / _devider].push(_arr[i]);

	int indexator = 0;

	for (queue<int> bucket : buckets)
	{
		insertation_sort(bucket);
		while (!bucket.empty())
		{
			_arr[indexator] = bucket.front();
			indexator++;
			bucket.pop();
		}
	}
}

void insertation_sort(queue<int> &q)
{
	const int n = (int)q.size();
	
	if (n > 1)
	{
		int* temp_arr = new int(n);
		int indexator = 0;

		while (!q.empty())
		{
			temp_arr[indexator] = q.front();
			indexator++;
			q.pop();
		}

		for (int i = 1; i < n; i++)
		{
			int key = temp_arr[i];
			int j = i - 1;

			while (j >= 0 && temp_arr[j] > key)
			{
				temp_arr[j + 1] = temp_arr[j];
				j--;
			}

			temp_arr[j + 1] = key;
		}

		for (int i = 0; i < n; i++)
			q.push(temp_arr[i]);

		delete temp_arr;
	}
}
