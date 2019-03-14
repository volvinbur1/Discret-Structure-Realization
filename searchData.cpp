#include <fstream>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int book_data_array[50000][4], index = 0;
	ifstream data;

	data.open("E:\\Program\\Discrete structures\\BookData\\BookData\\bookInfo.txt");

	while (!data.eof()) // read lines from the file until it ends
	{
		// example of get line
		// ID:1__BookName:370__Author:514__Year:1906;

		string line;
		size_t pos;
		getline(data, line); // geting the line from the file
	
		line = line.substr(3); // get a substring "1__BookName:370__Author:514__Year:1906;" (deleting 3 first elements)
		line.pop_back(); // deleting last character
		pos = line.find("__"); // finding index of first appearance "__" in new string

		book_data_array[index][0] = stoi(line.substr(0, pos)); // writing "1" to first cell(book id)

		pos = line.find(":") + 1; // find index for first appearance in new string ":" and make the index for next element (+ 1)
		line = line.substr(pos); // get a substring "370__Author:514__Year:1906"
		pos = line.find("__"); // finding index of first appearance "__" in new string

		book_data_array[index][1] = stoi(line.substr(0, pos)); // writing writing "370" to second cell(book name)

		pos = line.find(":") + 1; // find index for first appearance in new string ":" and make the index for next element (+ 1)
		line = line.substr(pos); // get a substring "514__Year:1906"
		pos = line.find("__"); // finding index of first appearance "__" in new string

		book_data_array[index][2] = stoi(line.substr(0, pos)); // writing writing "514" to third cell(book author)

		pos = line.find(":") + 1; // find index for first appearance in new string ":" and make the index for next element (+ 1)
		line = line.substr(pos); // get a substring "514__Year:1906"
		pos = line.find("__"); // finding index of first appearance "__" in new string

		book_data_array[index][3] = stoi(line.substr(0, pos)); // writing writing "1906" to fourth cell(book year)

		index++;
	}

	data.close();
	int search_colom, search_line;

	printf("Enter by what you want to search:");
	scanf_s("%d", &search_colom);

	printf("\nEnter search information:");
	scanf_s("%d", &search_line);

	bool is_something_found = false;

	printf("\n|_ProductNumber_|___BookName____|____Author_____|__Publishing_Year__|\n");

	clock_t startTime = clock();

	for (int i = 0; i <= index; i++)
		if (book_data_array[i][search_colom - 1] == search_line) // checking search equation
		{
			printf("       %d\t|      %d\t|      %d\t|\t%d\t    |\n", book_data_array[i][0], book_data_array[i][1], book_data_array[i][2], book_data_array[i][3]);
			is_something_found = true;
		}

	if (!is_something_found)
	{
		printf("\nAccording to input info no data found.\n");
	}

	printf_s("\nThe code was running for %.2fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);

	system("Pause");
}
