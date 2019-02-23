/*
Generated file has next structure	
					
|___Product_Number__|_Book_Name_|___Author__|__Publishing_Year__|
|					|			|			|					|
|					|			|			|					|
...
All fieldes are numerical data types;
*/
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

void fillTable(int _amountOfRows);

int main()
{
	long number;

	printf_s("Enter amount of elements which should be generated\n");
	scanf_s("%ld", &number);
	printf_s("It might take a little time\n");

	clock_t startTime = clock();

	fillTable(number);

	printf_s("\nThe code was running for %.2fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);

	system("Pause");
	return 0;
}

void fillTable(int _amountOfRows)
{
	srand(time(NULL));

	fstream bookInfo;
	bookInfo.open("bookInfo.txt", ios::out | ios::trunc); // open file stream

	printf_s("|_ProductNumber_|___BookName____|____Author_____|__Publishing_Year__|\n");

	for (long i = 0; i < _amountOfRows; i++)
	{
		printf_s("|");

		for (int j = 0; j < 4; j++)
		{
			long generatedValue;

			switch (j)
			{
			case 0: // product number
				bookInfo << "ID:" << (i+1) << "__BookName:"; // write data to file
				printf_s("       %d\t|", (i+1));

				break;
			case 1: // book name
				generatedValue = rand() % _amountOfRows + 1; // 1 - _amountOfRows

				bookInfo << generatedValue << "__Author:"; // write data to file
				printf_s("      %d\t|", generatedValue);

				break;
			case 2: // author
				generatedValue = rand() % _amountOfRows + 1; // 1 - _amountOfRows

				bookInfo << generatedValue << "__Year:"; // write data to file
				printf_s("      %d\t|", generatedValue);

				break;
			case 3: // publishing year
				generatedValue = rand() % 120 + 1900; // 1000 - 2019

				bookInfo << generatedValue << ";"; // write data to file
				printf_s("\t%d\t    ", generatedValue);

				break;
			default:
				break;
			}
		}

		bookInfo << endl;
		printf_s("|\n");
	}

	bookInfo.close(); // close file stream
}
