#pragma once

#include <iostream>
#include <vector>

#include "MenuOption.h"

using namespace std;

/**
 * \brief Responsible for managing a collection of menu options (menu).
 * Basic usage - initialize a menu with vector of MenuOption, then call actions
 */
class Menu
{
	vector<MenuOption> options;

public:
	enum optionsIds {
		SINGLE_LINE = 1,
		MULTI_LINE,
		READ_FROM_FILE,
		RUN_TESTS,
		EXIT,
	};

	void initializeMenu();
	void display();

	static void printWelcomeMessage();

	/**
	 * \brief Calling a menu action.
	 *
	 * \param index of option to call
	 */
	void choose(int index);
};


