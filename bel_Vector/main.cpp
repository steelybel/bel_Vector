#include "tVector.h"
#include <iostream>
int main()
{
	bool addStuff = true;
	int input = 0;
	tVector<int> original;
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);

	tVector<int> copy = original;
	copy.pop_back(); // removes from the copy array, but not the original
	copy.pop_back();
	copy.pop_back();

	//std::cout << original.size() << std::endl; // 3
	//std::cout << copy.size() << std::endl;     // 0
	while (addStuff)
	{
		std::cin >> input;
		if (input > 10) addStuff = false;
	}
	return 0;
}