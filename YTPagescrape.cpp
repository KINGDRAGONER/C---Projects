#include <iostream>
#include <fstream>

int main() {
    std::string video_id;
    std::cout << "Enter the YouTube video ID: ";
    std::cin >> video_id;

    std::string cmd = "curl -s https://www.youtube.com/watch\\?v\\=" + video_id + " | sed -e 's/<[^>]*>//g' | grep -o '[^ \t].*'";
    std::string result;
    char buffer[128];

    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cout << "Error: Failed to open pipe." << std::endl;
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    pclose(pipe);

    std::ofstream file("comments.txt");
    if (!file.is_open()) {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    file << result;
    file.close();

    std::cout << "Comments saved to comments.txt" << std::endl;

    return 0;
}
