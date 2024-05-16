#include <iostream>
#include <vector>
#include "HashMap.h"
#include "Nodo.h"
#include "Producto.h"

using namespace std;

void HashMap::rehash() {
    int newTableSize = tableSize * 2;
    vector<Nodo*> newTable(newTableSize, nullptr);

    for (int i = 0; i < tableSize; i++) {
        Nodo* curr = table[i];
        while (curr != nullptr) {
            int index = hashFunction(curr->key) % newTableSize;
            Nodo* newNode = new Nodo(curr->key, curr->value);

            // Insertar newNode mientras se conservan las claves más grandes
            Nodo* prev = nullptr;
            Nodo* next = newTable[index];
            while (next != nullptr && next->key > curr->key) { // Buscar clave más grande
                prev = next;
                next = next->next;
            }

            if (prev == nullptr) { // Bucket vacío o clave más pequeña
                newTable[index] = newNode;
            } else {
                prev->next = newNode;
            }
            newNode->next = next; // Mantener el orden original de la lista enlazada

            curr = curr->next;
        }
    }

    table.swap(newTable);
    tableSize = newTableSize;
}
HashMap::HashMap(double maxLoadFactor) 
{
    this->tableSize = 1000;
    this->maxLoadFactor = maxLoadFactor;
    table.resize(tableSize, nullptr);
}

void HashMap::insert(int key, Producto* value) 
{
    int index = hashFunction(key);
    Nodo* newNode = new Nodo(key, value);

    if (table[index] == nullptr) 
    {
        table[index] = newNode;
    } 
    else 
    {
        Nodo* prev = nullptr;
        Nodo* curr = table[index];
        while (curr != nullptr) 
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
    }

    double loadFactor = (double) getNumberOfElements() / tableSize;

    if (loadFactor > maxLoadFactor) 
    {
        rehash();
    }
}

Producto* HashMap::get(int key) 
{
    int index = hashFunction(key);
    Nodo* curr = table[index];

    while (curr != nullptr) 
    {
        if (curr->key == key) 
        {
            return curr->value;
        }
        curr = curr->next;
    }

    return nullptr;
}

void HashMap::erase(int key) 
{
    int index = hashFunction(key);
    Nodo* prev = nullptr;
    Nodo* curr = table[index];

    while (curr != nullptr) 
    {
        if (curr->key == key) 
        {
            if (prev == nullptr) 
            {
                table[index] = curr->next;
            } 
            else 
            {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int HashMap::getNumberOfElements() 
{
    int count = 0;
    for (int i = 0; i < tableSize; i++) 
    {
        Nodo* curr = table[i];
        while (curr != nullptr) 
        {
            count++;
            curr = curr->next;
        }
    }
    return count;
}