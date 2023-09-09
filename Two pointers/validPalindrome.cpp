//leetcode 125. Valid Palindrome

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void getInput(string& input, vector<char>& letters) {

	std::cout << "Enter the string: ";
	std::cin >> input;

	for (int i = 0; i < input.size(); i++) {

		if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9')) {
			letters.push_back(input[i]);
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {

			//converting uppercase to lowercase
			letters.push_back(input[i] + 32);
		}
	}
}

bool isPalindrom(const string& input, const vector<char>& letters) {

	int leftIndex = 0, rightIndex = input.size() - 1;
	bool palindrome = true;

	while (leftIndex <= rightIndex) {

		if (letters[leftIndex] != letters[rightIndex]) {
			palindrome = false;
			break;
		}
	}

	return palindrome;
}

int main() {

	string input;

	vector<char> letters;

	getInput(input, letters);

	if (isPalindrom(input,letters)) std::cout << "This is a palindrome";
	else std::cout << "This is not a palindome";

	return 0;
}