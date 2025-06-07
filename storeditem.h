#ifndef STOREDITEM_H
#define STOREDITEM_H
#include <string>
class StoredItem {
private:
    std::string id;
    std::string description;
    std::string location;

public:
    StoredItem(std::string id, std::string desc, std::string loc);

    std::string getId();
    std::string getDescription();
    std::string getLocation();
};

#endif
