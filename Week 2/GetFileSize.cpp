#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& file)
{
	const size_t currPos = file.tellg();
	file.seekg(0, std::ios::end);
	const size_t fileSize = file.tellg();
	file.seekg(currPos);
	return fileSize;
}

int main()
{
}
