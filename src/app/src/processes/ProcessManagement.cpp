#include <iostream>
#include <queue>
#include <string>

#include <processes/ProcessManagement.h>
#include <encryptDecrypt/Cryption.h>

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task){
	taskQueue.push(std::move(task));
	return true;
}

bool ProcessManagement::executeTasks(){
	while(!taskQueue.empty()){
		const std::unique_ptr<Task> executeTask = std::move(taskQueue.front());
		taskQueue.pop();
		std::string executeTaskName = executeTask->toString();

		std::cout << executeTaskName << std::endl;

		executeCrypt(executeTaskName);
	}
	return true;
}

ProcessManagement::ProcessManagement(){
	taskQueue = std::queue<std::unique_ptr<Task>>();
}
