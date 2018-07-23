#include <iostream>
#include <cstdlib>
#include <string>

class LinkedHashEntry {
private:
      std::string key;
      int value;
      LinkedHashEntry *next;
public:
      LinkedHashEntry(std::string key, int value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
      }
 
      std::string getKey() {
            return key;
      }
 
      int getValue() {
            return value;
      }
 
      void setValue(int value) {
            this->value = value;
      }
 
      LinkedHashEntry *getNext() {
            return next;
      }
 
      void setNext(LinkedHashEntry *next) {
            this->next = next;
      }
};

const int TABLE_SIZE = 65536;
int linear_prob_var = 0;

class HashMap {
private:
      LinkedHashEntry **table;
public:
      HashMap() {
            table = new LinkedHashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }
 
      int find(std::string key) {
	    int index = 0;
	    int length = key.size();
	    for (int i = 0; i < length; i++) {
		index += key[i];
	    }		
            int hash = (index % TABLE_SIZE);
            if (table[hash] == NULL)
                  return -1;
            else {
                  LinkedHashEntry *entry = table[hash];
                  if (entry == NULL)
                        return -1;
                  else
                        return entry->getValue();
            }
      }
 
      void insert(std::string key, int value) {
	    int index = 0;
            int length = key.size();
            for (int i = 0; i < length; i++) {
                index += key[i];
            }
            int hash = (index % TABLE_SIZE);
            if (table[hash] == NULL) {
                  table[hash] = new LinkedHashEntry(key, value);
	    }
            else {
		  while (table[hash] != NULL) {
			hash = ((index + linear_prob_var) % TABLE_SIZE); 
			//I have to handle an exception here what if it never breaks out of the loop 
		  }
		  table[hash] = new LinkedHashEntry(key,value);
            }
      }
	
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL) {
                        LinkedHashEntry *prevEntry = NULL;
                        LinkedHashEntry *entry = table[i];
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
		int v2 = 3;
                std::string key1 = "hello there";
                myhash->insert(key1,v2);
	} catch (std::exception& e) {
		std::cout << "bad things happened" << e.what() << std::endl;
		exit(1);
	}

	try {
		int value = myhash->find("hello there");
		std::cout << "The value is: " << value << std::endl;
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
