#include "TestCase.h"
#include "TestResult.h"

bool isResultEquals(LongestSubstring result, LongestSubstring expected) {
	return result.getLength() == expected.getLength() &&
		result.getFirstStartPos() == expected.getFirstStartPos() &&
		result.getSecondStartPos() == expected.getSecondStartPos() &&
		result.getSubstring() == expected.getSubstring();
}

TestResult TestCase::runTest() {
	auto const result = LongestSubstring::getLongestSubstring(this->firstTestText, this->secondTestText);

	bool status = isResultEquals(result, this->expectedSubstringResult);
	
	if (!status) {
		std::cout << "Test failed." << std::endl;

		std::cout << "Result: " << std::endl;
		result.print();

		std::cout << "Expected: " << std::endl;
		this->expectedSubstringResult.print();
	}

	std::string message = status ? "Test passed." + this->title : "Test failed." + this->title;

	return TestResult(status, message);
}
