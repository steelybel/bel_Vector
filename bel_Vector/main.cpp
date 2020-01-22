#include "tVector.h"
#include "tStack.h"
#include "tQueue.h"
#include <iostream>
int main()
{
	bool addStuff = true;
	int input = 0;
	tVector<int> original;
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);

	tStack<int> magazine;
	tQueue<int> queue;

	std::cout << original.size() << std::endl; // 3
	while (addStuff)
	{
		std::cout << "Load in a number >";
		std::cin >> input;
		std::cout << std::endl;
		magazine.push(input);
		if (magazine.size() > 12)
		{
			addStuff = false;
		}
	}
	for (int b = 0; b < 12; b++)
	{
		std::cout << "Fired a " << magazine.top() << " from the number gun";
		magazine.pop();
		std::cout << std::endl;
	}
	addStuff = true;
	while (addStuff)
	{
		std::cout << "Put in a number >";
		std::cin >> input;
		std::cout << std::endl;
		queue.push(input);
		if (queue.size() > 10)
		{
			addStuff = false;
		}
	}
	for (int b = 0; b < 10; b++)
	{
		std::cout << queue.front() << " checked out";
		queue.pop();
		std::cout << std::endl;
	}
	std::cin >> input;
	return 0;
}