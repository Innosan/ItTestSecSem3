#include "testMain.h"
#include "TestCase.h"
#include <vector>

void testMain() {
	std::vector<TestCase> testCases = {
		TestCase(
			"Test 1 - common case",
			"abc",
			"abc",
			LongestSubstring(1, 1, 3, "abc")
		),
		TestCase(
			"Test 2 - no substrings",
			"abc",
			"def",
			LongestSubstring(0, 0, 0, "")
		),
		TestCase(
			"Test 3 - one of the text longer",
			"abc",
			"raba dabu fredf abc",
			LongestSubstring(1, 17, 3, "abc")
		),
		TestCase(
			"Test 4 - empty texts",
			"",
			"",
			LongestSubstring(0, 0, 0, "")
		),
		TestCase(
			"Test 5 - two substrings with space",
			"abc rewerted fresetog",
			"trefas abc freseabstog reweris",
			LongestSubstring(4, 23, 6, " rewer")
		),
		TestCase(
			"Test 6 - human text!",
			"The quick brown fox jumps over the lazy dog.",
			"The lazy dog was jumped over by the quick brown fox.",
			LongestSubstring(1, 33, 19, "he quick brown fox")
		),
	};


	bool allTestsPassed = true;
	for (TestCase testCase : testCases) {
		auto result = testCase.runTest();

		if (!result.status) {
			allTestsPassed = false;
			std::cout << result.message << std::endl;;
		}
	}

	allTestsPassed ?
		std::cout << "All tests passed!" << std::endl :
		std::cout << "Some tests failed!" << std::endl;
};
