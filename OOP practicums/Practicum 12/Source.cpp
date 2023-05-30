#include <iostream>

#include "MyVector.hpp"

int main()
{
	MyVector<int> vector;
	vector.pushBack(1);
	vector.pushBack(2);
	vector.pushBack(3);
	vector.pushBack(4);
	vector.insert(7, 2);
	vector.erase(1);
	vector.popBack();
	vector.clear();
	std::cout << vector[0] << std::endl;
	std::cout << vector[1] << std::endl;
	std::cout << vector[2] << std::endl;
	std::cout << vector[3] << std::endl;
}