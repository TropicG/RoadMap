#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	string first, second;

	map<char, int> firstMap, secondMap;

	bool isAnagram = true;

	std::cout << "Enter the first string: ";
	std::cin >> first;

	std::cout << "Enter the second string: ";
	std::cin >> second;

	for (auto& ch : first) {
		if (firstMap.count(ch) == 0) firstMap.insert(pair<char, int>(ch, 1));
		else firstMap[ch]++;
	}

	for (auto& ch : second) {
		if (secondMap.count(ch) == 0) secondMap.insert(pair<char, int>(ch, 1));
		else secondMap[ch]++;
	}
	
	for (auto& elem : firstMap) {
		if (secondMap.count(elem.first) == firstMap.count(elem.first)) continue;
		else { isAnagram = false; break; }
	}

	if (isAnagram) std::cout << "The second string can be rearranged to look like the first one" << endl;
	else std::cout << "The second string cannot be rearranged to look like the first one" << endl;
}
