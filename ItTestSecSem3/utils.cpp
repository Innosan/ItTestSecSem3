#include "utils.h"

std::string convertToString(std::vector<std::string> vec) {
	std::stringstream ss;

	for (int i = 0; i < vec.size(); i++) {
		ss << vec[i];

		if (i != vec.size() - 1) {
			ss << " ";
		}
	}

	return ss.str();
}
