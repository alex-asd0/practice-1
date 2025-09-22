#include <iostream>
#include <fstream>
#include <cstring>


const size_t MAX_WORDS_LENGTH = 32;

bool ContainingLetters(char* s1, size_t s1_len, char* s2, size_t s2_len) {
	for (size_t i = 0; i < s1_len; ++i) {
		bool found = false;
		for (size_t j = 0; j < s2_len; ++j) {
			if (s1[i] == s2[j]) {
				found = true;
			}
		}
		if (!found) {
			return false;
		}
	}

  	return true;
}

void ReadArgvString(char** argv, char* word) {
	for (int j = 0; j < std::strlen(*argv); ++j) {
		word[j] = (*argv)[j];
	}
}

int main(int argc, char** argv) {
	if (argc < 5) {
		std::cerr << "Error: not enough arguments" << '\n';
		return 0;
	}

	char word[MAX_WORDS_LENGTH];
	char path[MAX_WORDS_LENGTH];
	for (int i = 0; i < argc; ++i) {
		if (std::strcmp(*argv, "--word") == 0) {
			ReadArgvString(argv + 1, word);
		}
		if (std::strcmp(*argv, "--file") == 0) {
			ReadArgvString(argv + 1, path);
		}
		argv++;
	}

	std::ifstream stream;
	stream.open(path);
	if (!stream.is_open()) {
		std::cerr << "Erorr: can't open file" << '\n';
		return 0;
	}

	for (char line[MAX_WORDS_LENGTH]; stream >> line;){
		if (ContainingLetters(word, std::strlen(word), line, std::strlen(line))) {
			std::cout << line << '\n';
		}
	}

	stream.close();
	return 0;
}
