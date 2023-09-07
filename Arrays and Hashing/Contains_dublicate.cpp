#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {

	string input;

	unordered_set<char> chars;

	bool dublicate = false;

	std::cout << "Enter your input: ";
	std::cin >> input;

	for (auto& ch : input) {

		if (chars.count(ch) == 0) chars.insert(ch);
		else {
			dublicate = true; break;
		}
	}

	if (dublicate) {
		std::cout << "There is a letter that is dublicated in the input";
	}
	else std::cout << "Everything is clear";

	return 0;
}