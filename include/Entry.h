#ifndef ENTRY_H
#define ENTRY_H

#include <string>

struct Entry {
    std::string name;
    std::string street;
    std::string city;
    std::string postcode;
    std::string country;
    std::string phone;

    bool operator<(const Entry& other) const {
        return name < other.name;
    }

    bool operator==(const Entry& other) const {
        return name == other.name &&
               street == other.street &&
               city == other.city &&
               postcode == other.postcode &&
               country == other.country &&
               phone == other.phone;
    }
};

#endif // ENTRY_H
