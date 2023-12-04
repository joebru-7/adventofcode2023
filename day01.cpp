#include "everything.h"
void part1()
{
	char lastNum = '0';
	char lastChar = '\0';
	auto file = std::fstream("input.txt");
	bool foundFirst = false;
	int sum = 0;

	while (file.get(lastChar), !file.eof())
	{
		if (std::isdigit(lastChar))
		{
			lastNum = lastChar;
			if (!foundFirst)
			{
				foundFirst = true;
				sum += 10 * (lastChar - '0');
			}
		}
		else if (lastChar == '\n')
		{
			sum += (lastNum - '0');
			foundFirst = false;
		}
	}
	std::cout <<"\n1:"<< sum;
}

void part2()
{
	using namespace std::literals;
	std::string line = "";
	auto file = std::fstream("input.txt");
	int sum = 0;

	std::map<std::string_view, int> nums
	{
		{"one"sv,1},
		{"1"sv ,1},
		{"two"sv,2},
		{ "2"sv ,2},
		{ "three"sv ,3},
		{ "3"sv ,3},
		{ "four"sv ,4},
		{ "4"sv ,4},
		{ "five"sv ,5},
		{ "5"sv ,5},
		{ "six"sv ,6},
		{ "6"sv ,6},
		{ "seven"sv ,7},
		{ "7"sv ,7},
		{ "eight"sv ,8},
		{ "8"sv ,8},
		{ "nine"sv ,9},
		{ "9"sv ,9}
	};
	
	while (getline(file, line), !file.eof())
	{
		int lastNum = 0;
		int firstnum = 0;
		int firstindex = 100000;
		int lastIndex = -1;

		for (auto [val, res] : nums)
		{
			if (int index = line.find(val); index != std::string::npos && index < firstindex)
			{
				firstindex = index;
				firstnum = res;
			}

			if (int index = line.rfind(val); index != std::string::npos && index > lastIndex)
			{
				lastIndex = index;
				lastNum = res;
			}
		}

		sum += firstnum * 10;
		sum += lastNum;

	}
	std::cout << "\n2:" << sum;
}

int main()
{
	part1();
	part2();
}