#include <iostream>

#include "encryptDecrypt/Cryption.h"

int main(const int argc, char *argv[]){
	if (argc < 2){
		std::cout << "Usage: ./crypt <taskName>\n";
		return 1;
	}
	executeCrypt(argv[1]);
	return 0;
}
