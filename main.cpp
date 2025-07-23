#include <iostream>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <string>

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
	{"update", Command::UPDATE},
	{"delete", Command::DELETE},
	{"mark-in-progress", Command::MARK_IN_PROGRESS},
	{"mark-done", Command::MARK_DONE},
	{"list", Command::LIST},
	{"list done", Command::LIST_DONE},
	{"list todo", Command::LIST_TODO},
	{"list in-progress", Command::LIST_IN_PROGRESS}

};

struct Task {
	int id;
	std::string description;
	std::string status;
	std::string createdAt;
	std::string updatedAt;
};

const std::string filename = "tasks.json";

int add(std::string desc);
int max_Id(std::string file);

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
	{
		if (argc < 3) {
			std::cerr << "Erreur : description manquante pour 'add'\n";
			return 1;
		}
		std::string description = argv[2];
		int ret = add(description);
		break;
	}
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

int add(std::string desc)
{
	// Vérifie si le fichier existe
	if (!std::filesystem::exists(filename)) {
		std::ofstream outfile(filename);
		if (!outfile) {
			std::cerr << "Erreur : impossible de créer le fichier " << filename << "\n";
			return 1;
		}
		//outfile << "[]";
		outfile.close();
		std::cout << "Fichier créé : " << filename << "\n";
	}

	// Lecture du contenu
	std::ifstream infile(filename);
	if (!infile) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << "\n";
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();

	std::cout << "Contenu actuel de tasks.json :\n" << content << "\n";

	// Ecriture de la tache
	Task T ;
	T.id = max_Id(filename) + 1;
	T.description = desc;
	std::time_t current_time = std::time(nullptr);
	std::string now = std::ctime(&current_time);
	now.pop_back();
	T.createdAt = now;
	T.updatedAt = now;

	std::ofstream outfile(filename, std::ios::app); // en mode append pour ne pas effacer tout le contenu du fichier
	outfile << T.id << "|" << T.description << "|" << T.createdAt << "|" << T.updatedAt << "\n";
	outfile.close();

	return 0;
}

int max_Id(std::string file)
{
	std::ifstream infile(file);
	if (!infile) return 0;

	int maxId = 0;
	std::string line;
	while (std::getline(infile, line))
	{
		size_t sep = line.find('|');
		if (sep != std::string::npos) {
			std::string id_str = line.substr(0, sep);
			try
			{
				int id = std::stoi(id_str);
				if (id > maxId) maxId = id;
			}
			catch (const std::exception&)
			{
					
			}
		}
	}
	return maxId;
}