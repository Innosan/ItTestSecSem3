#include <iostream>
#include <vector>

#include "Menu.h"
#include "MenuOption.h"
#include "utils.h"
#include "files.h"
#include "validation.h"
#include "inputs.h"
#include "LongestSubstring.h"


void Menu::initializeMenu() {
	vector<MenuOption> items = {
		// Add mammal
		MenuOption(this->SINGLE_LINE, "Get texts from single line",  []() {
			std::string str1 = "I suck my lolipop, but i'm not sick. Tommorrow i will be boss of the gym.";
			std::string str2 = "I suck, but i'm not sick. Today he'll will be my boss of the class.";

			auto result = LongestSubstring::getLongestSubstring(str1, str2);
			result.print();
		}),

		MenuOption(this->MULTI_LINE, "Get texts from single line",  []() {
			std::string firstUserText = convertToString(getMultilineString("Input first text: "));
			std::string secondUserText = convertToString(getMultilineString("Input second text: "));

			auto result = LongestSubstring::getLongestSubstring(firstUserText, secondUserText);
			result.print();
		}),

		// Read from file
		MenuOption(this->READ_FROM_FILE, "Read texts from files",  []() {
			string firstFilePath = getValidFilePath();
			string secondFilePath = getValidFilePath();

			vector<string> firstFileText = getTextFromFile(firstFilePath);
			vector<string> secondFileText = getTextFromFile(secondFilePath);

			auto result = LongestSubstring::getLongestSubstring(convertToString(firstFileText), convertToString(secondFileText));
			result.print();
		}),

		// Exit
		MenuOption(this->EXIT, "Exit",  []() { exit(EXIT_SUCCESS); })
	};

	this->options = items;
};

void Menu::display() {
	std::cout << "\n";

	for (MenuOption item : this->options) {
		item.print();
	}
}

void Menu::choose(int index) {
	this->options[index - 1].callAction();
}

void Menu::printWelcomeMessage() {
	cout << "Fomin Mikhail Vital\'evich, group 4307, number 25" << endl;
	cout << "Test 3, task 7." << endl;

	cout << "For two given texts, find the longest common substring." << endl << endl;
	cout << "The program should output the position at which the text begins in each file, " << endl;
	cout << "the length of the line and the text of the line itself." << endl;
	cout << "Provide necessary checks of source data." << endl;
};
