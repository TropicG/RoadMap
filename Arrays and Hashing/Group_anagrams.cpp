//leetCode problem - 49. Group Anagrams

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <utility>

#define MAX 124
#define MAX_LETTERS 26

using namespace std;

void takeInput(std::vector<string>& input, int& words) {

	std::cout << "How many words you want to be putted into the string: ";
	std::cin >> words;

	std::cout << "Enter the numbers: ";
	for (size_t i = 0; i < words; i++)
	{
		std::cin >> input[i];
	}
}

void groupAnagram(std::map<std::vector<int>, std::vector<string>>& map, std::vector<string>& input) {

	for (auto& word : input) {

		std::vector<int> cntLetters(MAX_LETTERS);

		for (size_t i = 0; i < word.size(); i++)
		{
			cntLetters[word[i] - 'a']++;
		}

		if (map.count(cntLetters) == 1) map[cntLetters].push_back(word);
		else {
			map.insert(pair<vector<int>, vector<string>>(cntLetters, {}));
			map[cntLetters].push_back(word);
		}
	}
}

void getOutput(std::map<std::vector<int>, std::vector<string>>& map) {

	for (auto& elem : map) {
		for (size_t i = 0; i < elem.second.size(); i++)
		{
			std::cout << elem.second[i] << " ";
		}
		std::cout << "\n";
	}
}

int main() {

	std::vector<string> input(MAX);
	int words = 0;

	takeInput(input, words);

	std::map<std::vector<int>, std::vector<string>> map;

	groupAnagram(map, input);

	getOutput(map);

	return 0;
}