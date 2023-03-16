#include <iostream>
#include <fstream>

void replaceCharInFile(char ch1, char ch2, std::fstream& file)
{
	while (!file.eof())
	{
		const char currSymb = file.get();

		if (currSymb != ch1)
			continue;

		file.seekp(-1, std::ios::cur);
		file.put(ch2);
		file.flush();
	}
}

int main()
{
}
