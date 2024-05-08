#include <iostream>
#include "Nodo.h"
class HashMap
{
    private:
        int tableSize;
        double maxLoadFactor;
        vector<Nodo*> table;
        int hashFunction(int key)
        {
            return key % tableSize;
        }
        void rehash();
    public:
        HashMap(double maxLoadFactor = 0.75);
        void insert(int key, int value);
        int get(int key);
        void erase(int key);
        int getNumberOfElements();
};