#include <iostream>
#include <vector>

#include "Menu.h"
#include "MenuOption.h"
#include "utils.h"
#include "files.h"
#include "validation.h"
#include "inputs.h"
#include "testMain.h"
#include "LongestSubstring.h"


void Menu::initializeMenu() {
	vector<MenuOption> items = {
		// Add mammal
		MenuOption(this->SINGLE_LINE, "Input single line texts",  []() {
			std::string str1 = getStringUserInput("Input first text:");
			std::string str2 = getStringUserInput("Input second text:");

			auto result = LongestSubstring::getLongestSubstring(str1, str2);

			result.print();
		}),

		MenuOption(this->MULTI_LINE, "Input multiline texts",  []() {
			std::vector<std::string> firstUserText = getMultilineString("Input first text (end with double ENTER): ");
			std::vector<std::string> secondUserTest = getMultilineString("Input second text (end with double ENTER): ");
			
			auto result = LongestSubstring::getLongestSubstring(convertToString(firstUserText), convertToString(secondUserTest));

			result.print();
		}),

		// Read from file
		MenuOption(this->READ_FROM_FILE, "Read texts from files",  []() {
			string firstFilePath = "";
			while (true) {
				firstFilePath = getValidFilePath();
				if (fileExists(firstFilePath)) {
					break;
				}
				cout << "File does not exist. Please enter a new path." << endl;
			}

			string secondFilePath = "";
			while (true) {
				secondFilePath = getValidFilePath();
				if (fileExists(secondFilePath)) {
					break;
				}
				cout << "File does not exist. Please enter a new path." << endl;
			}

			vector<string> firstFileText = getTextFromFile(firstFilePath);
			vector<string> secondFileText = getTextFromFile(secondFilePath);

			auto result = LongestSubstring::getLongestSubstring(convertToString(firstFileText), convertToString(secondFileText));
			result.print();
		}),

		MenuOption(this->RUN_TESTS, "Run tests",  []() {
			testMain();
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
