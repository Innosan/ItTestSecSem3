#include "inputs.h"
#include <iostream>
#include <string>

int getIntUserInput(std::string welcomeMessage, int min, int max) {
	int input = 0;

	std::cout << welcomeMessage << std::endl;

	do {
		std::cin >> input;

		if (std::cin.fail() || input <= min || input >= max) {
			std::cout << "Invalid input. Please enter a number from " << min + 1 << " to " << max - 1 << std::endl;
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
		}
	} while (std::cin.fail() || input <= min || input >= max);

	std::cin.clear();
	std::cin.ignore(INT32_MAX, '\n');

	return input;
}

std::vector<std::string> getMultilineString(std::string welcomeMessage) {
    std::vector<std::string> lines;
    std::string line;

    std::cout << welcomeMessage << std::endl;

    while (std::getline(std::cin, line) && !line.empty()) {
        lines.push_back(line);
    }
	
    return lines;
}

std::string getStringUserInput(std::string welcomeMessage) {
	std::string input = "";
	std::cout << welcomeMessage << std::endl;

	std::getline(std::cin, input);

	return input;
}
