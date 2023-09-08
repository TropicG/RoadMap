//leetcode 128. longest consecutive sequence

#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

void getInput(vector<int>& input, int& cnt, unordered_set<int>& numbers) {

	std::cout << "Enter how numbers you want to input: ";
	std::cin >> cnt;

	std::cout << "Enter the numbers you want to input: ";
	for (int i = 0; i < cnt; i++) {
		int temp;
		std::cin >> temp;

		input.push_back(temp);
	}

	for (auto& num : input) {
		numbers.insert(num);
	}
}

int longestConsecutiveSequence(unordered_set<int> numbers, vector<int> input) {

	int longest = 1, crnt = 1, index = 0;

	int currentNum = input[index];


	//iteratos a different kind of way

	//gets the index number in the array and checks can it start a sequence with it
	//then checks everything in the set
	while (true) {

		bool inNumbers = (numbers.count(currentNum) == 1);

		if (inNumbers) {
			crnt++;
			currentNum++;
		}
		else {
			index++;

			if (index == input.size()) break;

			currentNum = input[index];
			longest = longest < crnt ? crnt : longest;
			crnt = 0;
		}
	}
}

int main() {

	vector<int> input;

	int cnt;

	unordered_set<int> numbers;

	getInput(input, cnt, numbers);

	int longest = longestConsecutiveSequence(numbers, input);

	std::cout << "Return the longest: " << longest;

	return 0;
}