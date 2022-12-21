#ifndef HASHING_OPENADDRESSING_H
#define HASHING_OPENADDRESSING_H

#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
using std::cout, std::endl, std::function, std::nullopt, std::optional, std::string, std::vector;

template<typename Keyable>
class QuadraticProbing {
private:
    enum state {EMPTY, FILLED, REMOVED};
    struct hashable {
        Keyable item;
        state status;
    };
    vector<hashable> table;
    unsigned long tableSize;
    function<string(Keyable)> getKey;
    unsigned long numItems;

    unsigned long hornerHash(string key) const {
        unsigned long hashVal = 0;
        for (char letter : key) {
            hashVal = hashVal * 37 + letter;
        }
        return hashVal % tableSize;
    }

    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

    void rehash() {
        // Store a copy of the hash table
        vector<hashable> oldTable = table;
        tableSize = nextPrime(tableSize * 2);
        // Empty the table
        table.clear();
        numItems = 0;

        table.resize(tableSize);

        // Reinsert all FILLED items
        for (int i = 0; i < oldTable.size(); ++i) {
            if (oldTable[i].status == FILLED) {
                insert(oldTable[i].item);
            }
        }

    }

public:
    // Constructor
    QuadraticProbing(unsigned long tableSize, function<string(Keyable)> getKey) {
        // This will fill the table with default Keyables and EMPTY statuses
        this->tableSize = nextPrime(tableSize);
        table.resize(this->tableSize);
        this->getKey = getKey;
        numItems = 0;
    }

    // Insert
    int insert(Keyable item) {
        int numReads = 0;
        // int for quadratic probing increment
        int i = 1;
        // Get the key from the item
        string key = getKey(item);
        if (!find(key, numReads)) {
            // Hash the key to get an index
            unsigned long index = hornerHash(key);
            // Probe until we find a non-filled index
            while (table[index].status == FILLED) {
                // Add i*i to the index for quadratic probing
                index = (index + i*i);
                index %= tableSize;
                i++;
            }
            table[index].item = item;
            numReads++;
            if (table[index].status == EMPTY) {
                ++numItems;
                table[index].status = FILLED;
                // Rehash when more than half the table is filled
                if (numItems > tableSize/2) {
                    rehash();
                }
            } else {
                table[index].status = FILLED;
            }
        }
        return numReads;
    }

    // Find
    optional<Keyable> find(string key, int &numReads) const {
        // int for quadratic probing increment
        int i = 1;
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        while (table[index].status != EMPTY) {
            // Check the index to see if the key matches
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                numReads++;
                // We found the item
                return table[index].item;
            }
            // Add i*i to the index for quadratic probing
            index = (index + i*i);
            index %= tableSize;
            i++;
            numReads++;
        }
        // We didn't find the item
        return nullopt;
    }

    // Remove
    bool remove(string key) {
        // int for quadratic probing increment
        int i = 1;
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        while (table[index].status != EMPTY) {
            // Check the index to see if the key matches
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                // We found the item
                // Remove it
                table[index].status = REMOVED;
                table[index].item = Keyable();
                return true;
            }
            // Add i*i to the index for quadratic probing
            index = (index + i*i);
            index %= tableSize;
            i++;
        }
        // We didn't find the item
        return false;
    }

    // Print the table
    void printTable() const {
        cout << "Beginning of table" << endl;
        for (unsigned long i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            if (table[i].status == FILLED) {
                cout << table[i].item;
            } else if (table[i].status == REMOVED) {
                cout << "X";
            }
            cout << endl;
        }
        cout << "End of table" << endl;
    }

    int getTableSize() {
        return tableSize;
    }
};



#endif