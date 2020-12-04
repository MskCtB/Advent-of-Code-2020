#include <iostream>
#include <vector>
#include <fstream>

#if 1
int main()
{
	int next = 1;
	int next2 = 2;
	int input;
	std::vector<int> Vector = {};
	std::fstream LoadFile("input.txt");

	while (LoadFile >> input)
	{
		Vector.push_back(input);
	}

	int size = Vector.size() - 2;
	for (int i = 0; i < size; i)
	{
		if (i != next && i != next2)
		{
			if (Vector[i] + Vector[next] + Vector[next2] == 2020)
			{
				std::cout << Vector[i] * Vector[next] * Vector[next2] << std::endl;
				break;
			}
		}
		++i;
		if (i == size - 1) {
			if (next == size - 1)
			{
				next = next2;
				++next2;
			}
			i = next2 - 1;
			++next;
		}
	}
}
#endif

#if 0
int main()
{
	int next = 1;
	int input;
	std::vector<int> Vector = {};
	std::fstream LoadFile("input.txt");

	while (LoadFile >> input)
	{
		Vector.push_back(input);
	}

	int size = Vector.size() - 1;
	for (int i = 0; i < size; i++)
	{
		if (i != next)
		{
			if (Vector[i] + Vector[next] == 2020)
			{
				std::cout << Vector[i] * Vector[next] << std::endl;
				break;
			}
		}
		if (i == size - 1) {
			i = next;
			next++;
		}
	}
}
#endif