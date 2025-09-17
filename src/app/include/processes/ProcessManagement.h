#ifndef PARALLEL_FILE_ENCRYPTOR_PROCESSMANAGMENT_H
#define PARALLEL_FILE_ENCRYPTOR_PROCESSMANAGMENT_H

#include <queue>
#include <memory>

#include <processes/Task.h>

class ProcessManagement{
	std::queue<std::unique_ptr<Task>> taskQueue;

public:
	ProcessManagement();

	bool submitToQueue(std::unique_ptr<Task> task);
	bool executeTasks();
};


#endif