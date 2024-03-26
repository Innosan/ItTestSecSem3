#pragma once
#include <iostream>

class LongestSubstring
{
	const size_t firstStartPos;
	const size_t secondStartPos;
	const size_t length;

	const std::string substring;

	public:
		LongestSubstring(
			const size_t firstStartPos,
			const size_t secondStartPos,
			const size_t length,
			const std::string substring
		) : 
			firstStartPos(firstStartPos),
			secondStartPos(secondStartPos),
			length(length),
			substring(substring) 
		{}

		void print() const {
			std::cout << "Longest common substring: " << substring << std::endl;
			std::cout << "Length: " << length << std::endl;
			std::cout << "First string start position: " << firstStartPos << std::endl;
			std::cout << "Second string start position: " << secondStartPos << std::endl;
		};

		/**
		 * Function to find the longest common substring in two strings.
		 * 
		 * @param str1 The first string.
		 * @param str2 The second string.
		 * \return LongestSubstring The longest common substring.
		 */
		static LongestSubstring getLongestSubstring(const std::string& str1, const std::string& str2);
};
