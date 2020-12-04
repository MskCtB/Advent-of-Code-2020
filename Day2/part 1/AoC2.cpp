#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
	//char a;
	std::string String = "";
	std::string Merge;
	int part = 0;
	int Argument[2];
	int Counted = 0;
	int Total = 0;
	char Condition;
	int Valid = 0;
	std::fstream Fstream("input.txt");
	std::vector<std::string> Vector;
	while (Fstream >> String)
	{
		/*if (part >= 0 && part < 2)
		{
			Merge += String + " ";
			part++;
		}
		else if (part == 2)
		{
			Merge += String;
			part = 0;
			Vector.push_back(Merge);
			Merge = "";
		}*/
		Vector.push_back(String);
	}

	String = "";
	for (int i = 0; i < Vector.size() - 2; i += 3)
	{
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
		String = "";
		part = 0;

		for (int j = 0; j < Vector[i + 1].length(); j++)
			if (Vector[i + 1][j] != ':')
				Condition = Vector[i + 1][j];

		for (int j = 0; j < Vector[i + 2].length(); j++)
			if (Vector[i + 2][j] == Condition)
				Counted++;

		if (Counted >= Argument[0] && Counted <= Argument[1])
			Total++;
		Counted = 0;
	}
	std::cout << Total << std::endl;
}