#include <bits/stdc++.h>
using namespace std;

class Hash {
private:
    int size = 0;
    int total = 100;
    string* value = new string[total];

public:
    Hash() {
        for (int i = 0; i < 60; ++i) value[i] = '\0';
    }
    void setHash(int key, string val) {
        if (key/10000 == 17) key = key + 40;
        key = key%100;
        value[key] = val;
        ++size;
    }
    string getValue(int key) {
        if (key/10000 == 17) key = key + 40;
        key = key%100;
        return value[key];
    }
    void deleteKey(int key) {
        if (key/10000 == 17) key = key + 40;
        key = key%100;
        value[key] = '\0';
        --size;
    }
    int getLength() {
        return size;
    }

};

int main() {
    Hash* hash = new Hash();
    hash->setHash(170111, "Nayef Al Mahbub");
    hash->setHash(180111, "Anonymous");
    hash->setHash(180122, "Nayem Mehedi");
    hash->setHash(180135, "Md. Ananda Mia");
    hash->setHash(170135, "Anonymous");
    
    cout << hash->getLength() << endl;
    cout << hash->getValue(170111) << endl;
    cout << hash->getValue(180111) << endl;
    hash->deleteKey(180135);
    cout << hash->getLength() << endl;

}
