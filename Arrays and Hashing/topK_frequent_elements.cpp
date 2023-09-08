//leetCode problem - top K frequent problems

#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

void getInput(vector<int>& nums, int& cnt, int& k) {

	std::cout << "Enter how many numbers you want to input: ";
	std::cin >> cnt;

	std::cout << "Enter your numbers: ";
	for (int i = 0; i < cnt; i++) {

		int input;
		std::cin >> input;
		nums.push_back(input);
	}

	std::cout << "Which top frequent numbers you want to see: ";
	std::cin >> k;
}

void fillMaps(const vector<int>& nums ,unordered_map<int, int>& numsToFrequency, multimap<int, int>& frequencyToNums) {

	for (auto& num : nums) {

		if (numsToFrequency.count(num) == 1) numsToFrequency[num]++;
		else numsToFrequency.insert(pair<int, int>(num, 1));
	}

	for (auto& elem : numsToFrequency) {
		frequencyToNums.insert(pair<int, int>(elem.second, elem.first));
	}
}

void getOutput(const multimap<int, int>& frequencyToNums, const int& k) {

	stack<int> answer;
	for (auto& elem : frequencyToNums) {
		answer.push(elem.second);
	}

	int stackSize = answer.size();
	for (int i = 0; i < stackSize; i++) {

		if (stackSize - k <= i) {
			std::cout << answer.top() << " ";
			answer.pop();
		}
	}
}

bool checkPreconditions(const int& cnt, const int& k) {

	if (cnt < k) return false;

	return true;
}

int main() {

	vector<int> nums;

	int cnt = 0;
	int k = 0;

	getInput(nums, cnt, k);

	if (!checkPreconditions(cnt, k)) return -1;
	
	//here the key is the number and the value is how often the key is met in the vector
	unordered_map<int, int> numsToFrequency;

	//here the key is how often the key is met in the vector and the value is the number
	multimap<int, int> frequencyToNums;
	
	fillMaps(nums, numsToFrequency, frequencyToNums);

	getOutput(frequencyToNums, k);

	return 0;
}