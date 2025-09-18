#include <algorithm>
#include <filesystem>
#include <iostream>

#include "processes/ProcessManagement.h"

namespace fs = std::filesystem;

int main(){
	std::string dir;

	std::cout << "\033[1;35m" << "Directory Path Input" << "\033[0m" << std::endl;
	std::cout << "\033[1;33m" << "➤ Enter directory path: " << "\033[0m";
	std::cin >> dir;

	if (!fs::exists(dir) || ! fs::is_directory(dir)){
		std::cout <<"\033[1;31m" << "NON EXISTING DIR" << "\033[0m" << std::endl;
	}

	std::cout << "\033[1mSelect action:\033[0m\n"
			  << "  \033[32menc\033[0m - encrypt file\n"
			  << "  \033[31mdec\033[0m - decrypt file\n"
			  << "  Default: \033[33menc\033[0m\n"
			  << "> ";

	std::string action;
	std::cin >> action;
	std::ranges::transform(action, action.begin(), ::tolower);
	try{
		ProcessManagement processManager;
		for (const auto &entry : fs::recursive_directory_iterator(dir)){
			if (entry.is_regular_file()){
				std::string filePath = entry.path().string();
				IO io(filePath);
				std::fstream f_stream = std::move(io.getFileStream());
				if (f_stream.is_open()){
					Action taskAction = (action == "ENCRYPT" ? e_encrypt : e_decrypt);
					auto task = std::make_unique<Task>(std::move(f_stream), taskAction,filePath);
					processManager.submitToQueue(std::move(task));
				}else{
					std::cout<<"\033[1;31m"<<"UNABLE TO OPEN THE FILE" << "\033[0m"<< filePath << std::endl;
				}
			}
		}
		processManager.executeTasks();
	}catch(std::exception& e){
		std::cout<< "\033[1;31m"<< "FILESYSTEM ERR" << "\033[0m" << e.what() << std::endl;
	}

}