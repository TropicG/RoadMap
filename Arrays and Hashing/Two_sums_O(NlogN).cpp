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

pair<int, int> twoSums(vector<int>& vec, const int& targetSum) {

	if (vec.size() == 1) {

		//if there is only 1 element and it is not equal to target sum we make a check with -1 later
		return pair<int, int>(targetSum == vec[0] ? 0 : -1, 1);
	}

	int leftIndex = 0, rightIndex = vec.size() - 1;
	
	//implements divided O(N)
	while (leftIndex <= rightIndex) {

		int sum = vec[leftIndex] + vec[rightIndex];

		//returns the numbers that form the targetSum
		if (sum == targetSum) return pair<int, int>(vec[leftIndex], vec[rightIndex]);

		else if (sum > targetSum) rightIndex--;

		else if (sum < targetSum) leftIndex++;
	}

	//returns a -1 first if there is no combination
	return pair<int, int>(-1, 0);
}

int main() {

	vector<int> vec;

	unordered_map<int, int> map;


	int size = 0;

	int targetSum = 0;

	getInput(map,vec, size, targetSum);

	std::sort(vec.begin(), vec.end());

	pair<int, int> answer = twoSums(vec, targetSum);

	if (answer.first == -1) std::cout << "There is no sum of numbers that matches targetSum";

	//since the original numbers are returned they are used as keys in the map so that the original indexes may be printed
	else std::cout << "The combination is " << map[answer.first] << " " << map[answer.second];
}