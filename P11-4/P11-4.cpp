//	P11-4.cpp	-	Dylan King	-	November 5, 2026
//
//	Description:	

#include <iostream>
#include <string>
using namespace std;

bool isNumeric(string s);
bool isCorrectLength(string s);
bool isCardValid(int digits[], int size);	//	Completed

string input;
int credit_card_num;
int digits[16];

bool running = true;

int main() {

	while (running) {
		cout << "Enter 16-digit credit card # or Q to quit: ";
		cin >> input;

		//cin >> credit_card_num;
		if (cin.fail()) {
			return 0;
		}

		for (int i = 0; i < 16; i++) {
			digits[i] = credit_card_num % 10;
			credit_card_num /= 10;
		}

		bool card_validity = isCardValid(digits, 8);
		if (card_validity) {
			cout << "Card is valid." << endl;
		}
		else {
			cout << "Card is not valid." << endl;
		}
	}
}

bool isCardValid(int digits[], int size) {
	int sum_of_every_other_digit_from_right = 0;
	int sum_of_every_other_doubled_digit_from_left = 0;
	for (int i = 16; i >= 0; i -= 2) {
		sum_of_every_other_digit_from_right += digits[i];
		}
	for (int i = 1; i < 16; i += 2) {
		sum_of_every_other_doubled_digit_from_left += ((digits[i] * 2) % 10 + (digits[i] * 2) / 10);
	}
	if ((sum_of_every_other_digit_from_right + sum_of_every_other_doubled_digit_from_left) % 10 == 0) {
		return true;
	}
	else { return false; }
}

bool isNumeric(string s) {
	for (int i = 0; i < 16; i++) {
		if (s[i] > '9' || s[i] < 0) {
			return false;
		}
	}
	return true;
}
bool isCorrectLength(string s) {
	if (s.length() != 16) {
		return false;
	}
	else {
		return true;
	}
}