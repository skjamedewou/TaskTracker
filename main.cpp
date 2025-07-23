#include <iostream>
#include <unordered_map>

enum class Command {
	ADD,
	UPDATE,
	DELETE,
	MARK_IN_PROGRESS,
	MARK_DONE,
	LIST,
	LIST_DONE,
	LIST_TODO,
	LIST_IN_PROGRESS,
	UNKNOWN
};

std::unordered_map<std::string, Command> command_map = {
	{"add", Command::ADD},
	{"update", Command::ADD},
	{"delete", Command::ADD},
	{"mark-in-progress", Command::ADD},
	{"mark-done", Command::ADD},
	{"list", Command::ADD},
	{"list done", Command::ADD},
	{"list todo", Command::ADD},
	{"list in-progress", Command::ADD}

};

struct Task {
	int id;
	std::string description;
	std::string status;
	std::string createdAt;
	std::string updatedAt;
};

int main(int argc, char* argv[]) 
{
	std::string cmd_input = "";

	if (argc < 2)
	{
		std::cout << "Usage: task-cli <command> [arguments] \n";
		return 1;
	}
	if (argc >= 3 && std::string(argv[1]) == "list")
	{
		cmd_input = std::string(argv[1]) + " " + std::string(argv[2]);
	}
	else
	{
		cmd_input = argv[1];
	}

	Command cmd = Command::UNKNOWN;
	auto it = command_map.find(cmd_input);
	if (it != command_map.end()) {
		cmd = it->second;
	}

	switch (cmd)
	{
	case Command::ADD:
		break;
	case Command::UPDATE:
		break;
	case Command::DELETE:
		break;
	case Command::MARK_IN_PROGRESS:
		break;
	case Command::MARK_DONE:
		break;
	case Command::LIST:
		break;
	case Command::LIST_DONE:
		break;
	case Command::LIST_TODO:
		break;
	case Command::LIST_IN_PROGRESS:
		break;
	case Command::UNKNOWN:
		break;
	default:
		break;
	}
	return 0;
}

