#include <encryptDecrypt/Cryption.h>
#include <processes/Task.h>
#include <fileHandling/EnvReader.h>

int executeCrypt(const std::string &taskData){
	Task task= Task::fromString(taskData);

	const std::string envKey = EnvReader::get_env();
	const int key = std::stoi(envKey);

	if (task.action == e_encrypt){
		char ch;
		while (task.f_stream.get(ch)){
			ch  = (ch + key) % 256;
			task.f_stream.seekp(-1, std::ios::cur);
			task.f_stream.put(ch);
		}
		task.f_stream.close();
	}else{
		char ch;
		while (task.f_stream.get(ch)){
			ch  = (ch - key + 256) % 256;
			task.f_stream.seekp(-1, std::ios::cur);
			task.f_stream.put(ch);
		}
		task.f_stream.close();
	}
	return 0;
}