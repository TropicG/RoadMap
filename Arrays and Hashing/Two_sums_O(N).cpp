#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void getInput(unordered_map<int,int>& map ,vector<int>& vec, int& size, int& targetSum) {

	std::cout << "Enter the size of the vector: ";
	std::cin >> size;

	std::cout << "Enter the numbers in the vector: ";
	for (int i = 0; i < size; i++) {
		int input = 0;
		std::cin >> input;

		vec.push_back(input);

		//adds the number and they are keys for their original position in the index
		map.insert(pair<int, int>(input, i));
	}

	std::cout << "Enter the target sum: ";
	std::cin >> targetSum;
}

int main() {

	vector<int> vec;

	unordered_map<int, int> map;


	int size = 0;

	int targetSum = 0;

	bool foundPartner = true;

	pair<int, int> answer;

	getInput(map,vec, size, targetSum);

	


	
	for (auto& key : map) {

		int partner = targetSum - key.first;

		if (map.count(partner) == 1) {

			foundPartner = true;

			answer.first = key.first;
			answer.second = partner;

			break;
		}
	}

	if (foundPartner) std::cout << "There is an combination that sums to targetSum: " << map[answer.first] << " " << map[answer.second];
	else std::cout << "There is not a combination that sums to targetSum:";
}