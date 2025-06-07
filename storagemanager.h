#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <stdexcept>
#include <unordered_map>
#include <map>
#include <memory>
#include "storeditem.h"

class DuplicateItemException : public std::runtime_error {
public:
    DuplicateItemException(const std::string& msg) : std::runtime_error(msg) {}
};

class ItemNotFoundException : public std::runtime_error {
public:
    ItemNotFoundException(const std::string& msg) : std::runtime_error(msg) {}
};



class StorageManager {
private:
    std::unordered_map<std::string, std::shared_ptr<StoredItem>> itemById;
    std::map<std::string, std::shared_ptr<StoredItem>> itemByDescription;

public:
    void addItem(const std::shared_ptr<StoredItem>& item) ;

    std::shared_ptr<StoredItem> findById(const std::string& id) const ;

    void removeItem(const std::string& id) ;
    std::string listItemsByDescription() const;

void testDuplicateAddition();
void testItemNotFound();

};

#endif
