#include <iostream>
#include <fstream>

unsigned GetCharCountFromFile(std::ifstream ifs&, const char ch)
{
	const size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	if (!ifs.is_open())
	{
		std::cout << "File open error!";
		return -1;
	}

	unsigned int count = 0;

	while (true)
	{
		const char current = ifs.get();
		if (ifs.eof())
			break;

		if (current == ch)
			count++;
	}

	ifs.clear();
	ifs.seekg(currPos);
	return count;
}

unsigned getLineCount(const char* fileName)
{
	std::ifstream myFile(fileName);
	if(!myFile.is_open())
	{
		std::cout << "File open error!";
		return -1;
	}

	return GetCharCountFromFile(myFile, '\n');
}



int main()
{
}