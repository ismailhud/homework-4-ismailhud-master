#include "../include/Entry.h"
#include "../include/FileUtils.h"
#include "../include/RedBlackTree.h"

#define NUM_ENTRIES 1000000

int main() {
    std::string filepath;
    std::cout << "Enter path to CSV file: ";
    std::getline(std::cin, filepath);

    RedBlackTree tree = FileUtils::read_file(filepath, NUM_ENTRIES);

    int* edge_counts = tree.count_red_and_black_edges();
    std::cout << "Total black edges: " << edge_counts[0] << std::endl;
    std::cout << "Total red edges: " << edge_counts[1] << std::endl;
    delete[] edge_counts;

    std::string input;
    while (true) {
        std::cout << "\nEnter a name to search (Surname, Name) or -1 to exit: ";
        std::getline(std::cin, input);

        if (input == "-1") break;

        std::vector<Entry> results = tree.get(input);
        if (results.empty()) {
            std::cout << "No entries found for: " << input << std::endl;
        } else {
            std::cout << results.size() << " entr" << (results.size() == 1 ? "y" : "ies") << " found:\n";
            for (const Entry& e : results) {
                std::cout << "Name: " << e.name << "\n"
                          << "Street: " << e.street << "\n"
                          << "City: " << e.city << "\n"
                          << "Postcode: " << e.postcode << "\n"
                          << "Country: " << e.country << "\n"
                          << "Phone: " << e.phone << "\n"
                          << "------------------------\n";
            }
        }
    }

    std::cout << "Exiting program." << std::endl;
    return 0;
}
