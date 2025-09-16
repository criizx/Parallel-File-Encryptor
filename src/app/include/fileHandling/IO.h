#ifndef PARALLEL_FILE_ENCRYPTOR_IO_H
#define PARALLEL_FILE_ENCRYPTOR_IO_H

#include <fstream>
#include <string>

class IO{
	std::fstream file_stream;

	public:
		explicit IO(const std::string &filePath);
		~IO();
		[[nodiscard]] std::fstream getFileStream();



};


#endif