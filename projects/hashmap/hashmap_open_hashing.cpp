#include <iostream>
#include <cstdlib>
#include <string>
#include <new>
#define A 54059 /* prime */
#define B 76963 /* prime */
#define C 86969 /* prime */
#define first 37 /* prime */

class HashEntry {
private:
      std::string key;
      int value;
      HashEntry* next;
public:
      HashEntry(std::string key, int value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
      }

      std::string
       getKey() {
            return key;
      }

      int
      getValue() {
            return value;
      }

      void
       setValue(int value) {
            this->value = value;
      }

      HashEntry*
      getNext() {
            return next;
      }

      void
      setNext(HashEntry *next) {
            this->next = next;
      }
};

//const unsigned long long TABLE_SIZE = (1ULL << 34);
const unsigned long long TABLE_SIZE = 1073741824;

class HashMap {
private:
      HashEntry** table;
public:

      HashMap() {
          try {
                table = new HashEntry*[TABLE_SIZE];
           } catch (const std::bad_alloc& e) {
                std::cout << "Out of memory: " << e.what() << std::endl;
                exit(1);
           }
            for (unsigned long long i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }

        unsigned long long hashFunction(std::string s)
        {
                unsigned long long h = first;
                int i = 0;
                int length = s.size();
                while (i < length) {
                        h = (h * A) ^ (s[i] * B);
                        i++;
                }
                return h % TABLE_SIZE;
        }

      int find(std::string key) {
	      unsigned long long hash = hashFunction(key);
            if (table[hash] == NULL)
                  return -1;
            else {
                  HashEntry *entry = table[hash];
                  while (entry != NULL && entry->getKey() != key)
                        entry = entry->getNext();
                  try {
                        if (entry != NULL) {
                                return entry->getValue();
                        }
                  }
                  catch (std::exception& e) {
                       std::cout << "bad things happened" << e.what() << std::endl;
                       exit(1);
                  }
            }
      }

      void insert(std::string key, int value) {
            unsigned long long hash = hashFunction(key);
            if (table[hash] == NULL) {
                  table[hash] = new HashEntry(key, value);
            }
            else {
                  HashEntry *entry = table[hash];
                  while (entry->getNext() != NULL) {
                        entry = entry->getNext(); //make it constant time
                  }
                  if (entry->getKey() == key) {//collision resolution. If two keys map to the same hash. if the key is the same set value, else move to next until you are able to create a new hash entry with the current key value pair
                        entry->setValue(value);
                  }
                  else {
                        entry->setNext(new HashEntry(key, value));
                  }
            }
      }

      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL) {
                        HashEntry *prevEntry = NULL;
                        HashEntry *entry = table[i];
                        while (entry != NULL) {
                             prevEntry = entry;
                             entry = entry->getNext();
                             delete prevEntry;
                        }
                  }
            delete[] table;
      }

};

void just_example() {
        HashMap* myhash = new HashMap();
        try {
                int length = 1073741824;
                int start_i = clock();
                for (int i = 0; i < length; i++) {
                        myhash->insert(std::to_string(i), i);
                }
                int end_i = clock();
                std::cout << " The time taken to insert 2^30 elements is: " << (end_i - start_i)/double(CLOCKS_PER_SEC)*1000 << std::endl;
        } catch (std::exception& e) {
                std::cout << "bad things happened" << e.what() << std::endl;
                exit(1);
        }

        try {
                int lengthFind = 1048576;
                int start_f = clock();
                for (int i = 0; i < lengthFind; i++) {
                        int output = myhash->find(std::to_string(i));
                }
                int end_f = clock();
		std::cout << " The time taken to find 2^20 elements is: " << (end_f - start_f)/double(CLOCKS_PER_SEC)*1000 << std::endl;
        } catch (std::exception& e) {
                std::cout << "Bad things happened!! " << e.what() << std::endl;
                exit(1);
        }
        delete myhash;
}

int
main() {
        just_example();
        return 0;
}
