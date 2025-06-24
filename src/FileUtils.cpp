#include "../include/FileUtils.h"

RedBlackTree FileUtils::read_file(const std::string& file_path, const int len) {
    std::ifstream file(file_path);
    RedBlackTree tree;

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << file_path << std::endl;
        return tree;
    }

    std::string line;
    std::getline(file, line); // skip header line

    int count = 0;
    while (std::getline(file, line) && count < len) {
        std::stringstream ss(line);
        std::string name, street, city, postcode, country, phone;

        std::getline(ss, name, ';');
        std::getline(ss, street, ';');
        std::getline(ss, city, ';');
        std::getline(ss, postcode, ';');
        std::getline(ss, country, ';');
        std::getline(ss, phone, '\n');

        Entry e{name, street, city, postcode, country, phone};
        tree.put(name, e);
        count++;
    }

    file.close();
    return tree;
}
