#include <iostream>

#include <vector>
#include <algorithm>

/**
 * Function to find the longest common substring in two strings.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 *
 * @return A pair where the first element is the longest common substring,
 *         the second element is another pair where the first element is the length of the longest common substring,
 *         and the second element is a pair of starting positions of the longest common substring in the first and second strings.
 */
std::pair<std::string, std::pair<size_t, std::pair<size_t, size_t>>> longestCommonSubstring(const std::string& str1, const std::string& str2) {
	// Get the sizes of the strings
	size_t m = str1.size();
	size_t n = str2.size();

	// Initialize the dynamic programming table
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

	// Variables to store the length and ending positions of the longest common substring
	size_t maxLength = 0;
	size_t endPos1 = 0;
	size_t endPos2 = 0;

	// Iterate over the characters of the strings
	for (size_t i = 1; i <= m; i++) {
		for (size_t j = 1; j <= n; j++) {
			// If the current characters match
			if (str1[i - 1] == str2[j - 1]) {
				// Update the dynamic programming table and the length and ending positions of the longest common substring
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > maxLength) {
					maxLength = dp[i][j];
					endPos1 = i - 1;
					endPos2 = j - 1;
				}
			}
		}
	}

	// Extract the longest common substring from the first string
	std::string longestSubstr = str1.substr(endPos1 - maxLength + 1, maxLength);

	// Return the longest common substring, its length, and its starting positions in the strings
	return { longestSubstr, {maxLength, {endPos1 - maxLength + 1, endPos2 - maxLength + 1}} };
}

int main()
{
	std::string str1 = "I suck my lolipop, but i'm not sick. Tommorrow i will be boss of the gym.";
	std::string str2 = "I suck, but i'm not sick. Today he'll will be my boss of the class.";

	auto result = longestCommonSubstring(str1, str2);

	std::cout << "Longest common substring: " << result.first << "\n";
	std::cout << "Length: " << result.second.first << "\n";
	std::cout << "Start position in str1: " << result.second.second.first << "\n";
	std::cout << "Start position in str2: " << result.second.second.second << "\n";

	return 0;
}