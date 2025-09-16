#ifndef PARALLEL_FILE_ENCRYPTOR_ENVREADER_H
#define PARALLEL_FILE_ENCRYPTOR_ENVREADER_H

#include <sstream>
#include <string>

#include <fileHandling/IO.h>

class envReader{
public:
	static std::string get_env(){
		const std::string env_path = ".env";
		IO io(env_path);
		std::fstream f_stream = io.getFileStream();
		std::stringstream buffer;
		buffer << f_stream.rdbuf();
		std::string content = buffer.str();

		return content;
	}
};

#endif