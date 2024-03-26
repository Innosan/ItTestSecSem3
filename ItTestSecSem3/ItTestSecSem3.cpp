#include <iostream>

#include "LongestSubstring.h"
#include "Menu.h"

#include "inputs.h"
#include "utils.h"

int main()
{
	Menu::printWelcomeMessage();

	std::unique_ptr<Menu> menu = std::make_unique<Menu>();
	menu->initializeMenu();

	int pickedItem = 0;

	do {
		menu->display();

		pickedItem = getIntUserInput("Choose an option: ", Menu::optionsIds::SINGLE_LINE - 1, Menu::optionsIds::EXIT + 1);

		menu->choose(pickedItem);
	} while (pickedItem != Menu::optionsIds::EXIT);

	return 0;
}