#pragma once

#include <iostream>
#include <vector>

#include "LongestSubstring.h"
#include "TestResult.h"

class TestCase
{
public:
	std::string title;

	std::string firstTestText;
	std::string secondTestText;

	LongestSubstring expectedSubstringResult;

	TestResult runTest();

	TestCase(
		std::string title,
		std::string firstTestText,
		std::string secondTestText,
		LongestSubstring expectedSubstringResult
	) : title(title),
		firstTestText(firstTestText),
		secondTestText(secondTestText),
		expectedSubstringResult(expectedSubstringResult)
	{}
};

