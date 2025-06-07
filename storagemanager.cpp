#include "storagemanager.h"

#include <iostream>
#include <unordered_map>
#include <map>
#include <memory>



    void StorageManager::addItem(const std::shared_ptr<StoredItem>& item) {
        if (!itemById.count(item->getId()))
        {
            itemById[item->getId()] = item;
            itemByDescription[item->getDescription()] = item;
            std::cout << "Successfully added ID : " << item->getId() << std::endl;
        }
        else
        {
            throw DuplicateItemException("ID already exists : " + item->getId());
        }
        // TODO: Add item to both maps, throw if ID already exists
    }

    std::shared_ptr<StoredItem> StorageManager::findById(const std::string& id) const {
        if (itemById.count(id))
        {
            auto item = itemById.at(id);
            std::cout << "Successfully found item, ID : " + item->getId() << std::endl;
            std::cout << "Desc: " << item->getDescription()
                      << ", at " << item->getLocation() << std::endl;
            return item;
        }
        else
        {
            throw ItemNotFoundException("Cannot find, does not exist ID : " + id);
        }
        // TODO: Return item if found or throw ItemNotFoundException
        return nullptr;
    }

    void StorageManager::removeItem(const std::string& id) {
        if (itemById.count(id))
        {
            auto item = itemById.at(id);
            itemById.erase(item->getId());
            itemByDescription.erase(item->getDescription());
            std::cout << "Successfully removed ID : " + id;
        }
        else
        {
            throw ItemNotFoundException("Cannot delete, does not exist ID : " + id);
        }
        // TODO: Remove from both maps, throw if not found
    }

    std::string StorageManager::listItemsByDescription() const {
        std::string listOfItems = "";
        for (const auto& pair : itemByDescription)
        {
            auto item = pair.second;
            listOfItems += "Description: " + item->getDescription()
                    + ", ID: " + item->getId()
                    + ", Location: " + item->getLocation() + "\n";
        }
        return listOfItems;
        // TODO: Iterate over itemByDescription and print info
    }


