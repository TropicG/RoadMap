#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {

	string first, second;

	unordered_set<char> set;

	bool isAnagram = true;

	std::cout << "Enter the first string: ";
	std::cin >> first;

	std::cout << "Enter the second string: ";
	std::cin >> second;

	for (auto& ch : first) {
		set.insert(ch);
	}

	//checks for every symbol of the second string is it found in the set from the first string
	for (auto& ch : second) {
		if (set.count(ch) == 0) { isAnagram = false; break;}
	}
	
	if (isAnagram) std::cout << "The second word can be rearranged to be equal to the first one";
	else std::cout << "The second word cannot be rearranged to be equal to the first one";

	return 0;
}