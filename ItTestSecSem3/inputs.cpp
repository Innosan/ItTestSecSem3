#include "inputs.h"

int getIntUserInput(std::string welcomeMessage, int min, int max) {
	int input = 0;

	std::cout << welcomeMessage << std::endl;

	do {
		std::cin >> input;

		if (std::cin.fail() || input <= min || input >= max) {
			std::cout << "Invalid input. Please enter a number from " << min + 1 << " to " << max - 1 << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (std::cin.fail() || input <= min || input >= max);

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
