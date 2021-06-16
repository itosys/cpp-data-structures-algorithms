#include <bits/stdc++.h>
using namespace std;

class HashTable {
    int BUCKET;
    list<int> *table;

   public:
    HashTable(int b) {
        this->BUCKET = b;
        table = new list<int>[BUCKET];
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == key) break;
        }

        if (i != table[index].end()) table[index].erase(i);
    }

    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (auto x : table[i]) cout << " --> " << x;
            cout << endl;
        }
    }
};

int main() {
    int A[] = {15, 11, 27, 8, 12};
    HashTable h(7);
    for (int a : A) h.insertItem(a);
    h.displayHash();
    cout << "delete item 12." << endl;
    h.deleteItem(12);
    h.displayHash();
}
