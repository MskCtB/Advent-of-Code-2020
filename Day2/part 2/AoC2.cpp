#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
	std::string String = "";
	std::string Merge;
	int part = 0;
	int Argument[2];
	int Total = 0;
	char Condition;
	int Valid = 0;
	std::fstream Fstream("input.txt");
	std::vector<std::string> Vector;
	while (Fstream >> String)
		Vector.push_back(String);

	for (int i = 0; i < Vector.size() - 2; i += 3)
	{
		String = "";
		part = 0;
		for (int j = 0; j < Vector[i].length(); j++)
		{
			if (part == 0 && Vector[i][j] == '-')
			{
				std::istringstream Stream(String);
				Stream >> Argument[part];
				part++;
				String = "";
			}
			else if (part == 0 && Vector[i][j] != '-')
				String += Vector[i][j];
			else if (part == 1 && Vector[i][j] != '-')
			{
				String += Vector[i][j];
				if (j == Vector[i].length() - 1)
				{
					std::istringstream Stream(String);
					Stream >> Argument[part];
					part = 0;
				}
			}
		}

		for (int j = 0; j < Vector[i + 1].length(); j++)
			if (Vector[i + 1][j] != ':')
				Condition = Vector[i + 1][j];

		Argument[0] -= 1;
		Argument[1] -= 1;
		if (Vector[i + 2][Argument[0]] != Vector[i + 2][Argument[1]] && (Vector[i + 2][Argument[0]] == Condition || Vector[i + 2][Argument[1]] == Condition))
			Total++;
	}
	std::cout << Total << std::endl;
}