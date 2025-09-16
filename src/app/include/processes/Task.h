#ifndef TASK_H
#define TASK_H

#include <iosfwd>
#include <utility>
#include <sstream>

#include <fileHandling/IO.h>

enum Action{
	e_encrypt = 0,
	e_decrypt
};

struct Task{
	std::string filePath;
	std::fstream f_stream;
	Action action;

	Task(std::fstream &&f_stream, Action action, std::string filePath)
		: filePath(std::move(filePath)), f_stream(std::move(f_stream)), action(action){}

	std::string toString() const{
		std::ostringstream oss;
		oss << filePath << "," << (action == e_encrypt ? "ENCRYPT" : "DECRYPT");
		return oss.str();
	}

	static Task fromString(const std::string &taskData){
		std::istringstream iss(taskData);
		std::string filePath;
		std::string actionText;

		if (std::getline(iss, filePath, ',') && std::getline(iss, actionText)){
			Action action = (actionText == "ENCRYPT" ? e_encrypt : e_decrypt);
			IO io(filePath);

			if (std::fstream f_stream = std::move(io.getFileStream()); f_stream.is_open())
			{
				return {std::move(f_stream), action, filePath};
			}
			throw std::runtime_error("Failed to open file: " + filePath);
		}
		throw std::runtime_error("Failed to parse task data: " + taskData);
	}
};

#endif