#include <fstream>

#include <fileHandling/IO.h>

IO::IO(const std::string& filePath){
	file_stream.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
	if (!file_stream.is_open())
	{
		throw std::runtime_error("Error opening file");
	}
}

IO::~IO(){
	if (file_stream.is_open()){
		file_stream.close();
	}
}




std::fstream IO::getFileStream(){
	return std::move(file_stream);
}

