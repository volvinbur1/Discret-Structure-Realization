#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
	int n;
	std::cout << "Input n: ";
	std::cin >> n;
	std::ofstream out;
	out.open("D:\\ourfile.txt");
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		int number = rand() % 100 + 1;
		out << number << std::endl;
	}
	out.close();
}
