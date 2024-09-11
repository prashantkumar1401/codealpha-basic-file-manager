#include <iostream>
#include <filesystem> // For filesystem operations
#include <fstream>    // For file operations
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

//  Displaying the Current Directory
void displayCurrentDirectory() {
    std::string currentPath = std::filesystem::current_path().string();
    std::cout << "Current Directory: " << currentPath << std::endl;
}

void listDirectoryContents() {
    for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path())) {
        std::cout << (entry.is_directory() ? "[DIR]  " : "[FILE] ") << entry.path().filename().string() << std::endl;
    }
}

//   Navigating Directories
void changeDirectory(const std::string& path) {
    std::filesystem::current_path(path);
}

//    Viewing File Contents
void viewFileContents(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

//   Creating a Directory
void createDirectory(const std::string& dirName) {
    if (std::filesystem::create_directory(dirName)) {
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cerr << "Failed to create directory: " << dirName << std::endl;
    }
}

//   Copying or Moving Files
void copyFile(const std::string& source, const std::string& destination) {
    try {
        std::filesystem::copy(source, destination);
        std::cout << "File copied to: " << destination << std::endl;
    } catch (std::filesystem::filesystem_error& e) {
        std::cerr << "Error copying file: " << e.what() << std::endl;
    }
}

void moveFile(const std::string& source, const std::string& destination) {
    try {
        std::filesystem::rename(source, destination);
        std::cout << "File moved to: " << destination << std::endl;
    } catch (std::filesystem::filesystem_error& e) {
        std::cerr << "Error moving file: " << e.what() << std::endl;
    }
}

//    Implement the Command-Line Interface
void showHelp() {
    std::cout << "Commands:" << std::endl;
    std::cout << "  ls         - List directory contents" << std::endl;
    std::cout << "  cd <dir>   - Change directory" << std::endl;
    std::cout << "  cat <file> - View file contents" << std::endl;
    std::cout << "  mkdir <dir> - Create a new directory" << std::endl;
    std::cout << "  cp <src> <dst> - Copy file" << std::endl;
    std::cout << "  mv <src> <dst> - Move file" << std::endl;
    std::cout << "  help       - Show this help" << std::endl;
    std::cout << "  exit       - Exit the program" << std::endl;
}

int main() {
    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        std::istringstream iss(command);
        std::vector<std::string> tokens;
        for (std::string token; iss >> token; ) {
            tokens.push_back(token);
        }

        if (tokens.empty()) continue;

        if (tokens[0] == "ls") {
            listDirectoryContents();
        } else if (tokens[0] == "cd" && tokens.size() ==
