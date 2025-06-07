#include "storeditem.h"



    StoredItem::StoredItem(std::string id, std::string desc, std::string loc)
        : id(id), description(desc), location(loc) {
    }

    std::string StoredItem::getId()  { return id; }
    std::string StoredItem::getDescription()  { return description; }
    std::string StoredItem::getLocation()  { return location; }
