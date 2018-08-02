#include <iostream>
#include <cstdlib>
#include <string>
#include <new>
#include <cstring>
#include <algorithm>

#define A 54059 /* prime */
#define B 76963 /* prime */
#define C 86969 /* prime */
#define first 37 /* prime */


struct record_t {
	char key[1024];
	int value1;
	int value2;
};

class HashEntry {
	public:
	      char keyHash[1024];
	      record_t* r = new record_t;
	      HashEntry* next;
	      HashEntry* prev;
	      HashEntry(char k[1024], record_t* record) {
			std::strcpy(this->keyHash, k);
			this->r = record;
			this->next = NULL;
			this->prev = NULL;
	      }

	      char* 
	      getKey()
	      {
	      	        return this->keyHash;
	      }

	      record_t*
	      getValue() 
	      {
		        return r;
	      }

	      void 
	      setValue(record_t* value) 
	      {
		 	this->r = value;
	      }

	      HashEntry* 
	      getNext() {
			return next;
	      }

	      void 
	      setNext(HashEntry* next) 
	      {
			this->next = next;
	      }
	      
};

const int TABLE_SIZE = 100;

class HashMap {
private:
      HashEntry** table;
public:

      HashMap() {
	    try {
            	table = new HashEntry*[TABLE_SIZE];
            }
            catch (const std::bad_alloc& e) {
		std::cout << "Out of memory: " << e.what() << std::endl;
		exit(1);
	    }
            for (unsigned long long i = 0; i < TABLE_SIZE; i++) {
                  table[i] = NULL;
  	    }
      }

      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL) {
                        HashEntry *prevEntry = NULL;
                        HashEntry *entry = table[i];
                        while (entry != NULL) {
                             prevEntry = entry;
                             entry = entry->next;
                             delete prevEntry;
                        }
                  }
            delete[] table;
      }

	unsigned long long 
	hashFunction (std::string s)
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

	void 
	insert (char key[1024], void* r, long unsigned size) 
	{
		record_t* record = new record_t;
		memcpy(record, r, size);
		unsigned long long hash = hashFunction(key);
		if (table[hash] == NULL) {
			table[hash] = new HashEntry(key,record);
		}
		else {
			HashEntry* entry = table[hash];
			while (entry->getNext() != NULL) {
				entry = entry->getNext();
			}	
			if (entry->getKey() == key) {
				entry->setValue(record);
			}
			else {
				entry->setNext(new HashEntry(key,record));
			}
		}
		delete record;
	}

	record_t* 
	find (char key[1024]) 
	{
	    unsigned long long hash = hashFunction(key);
            if (table[hash] == NULL) {
                  return NULL;
	    }

            else {
                  HashEntry *entry = table[hash];
                  while (entry != NULL && entry->getKey() != key) {
                        entry = entry->getNext();
		  }
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

	void 
	remove (char key[1024]) 
	{
		unsigned long long hash = hashFunction(key);
		if (table[hash] != NULL) {
			HashEntry* prevEntry = NULL;
			HashEntry* entry = table[hash];
			while (entry->getNext() != NULL && entry->getKey() != key) {
				prevEntry = entry;
				entry = entry->getNext();		
			}
			if (entry->getKey() == key) {
				if (prevEntry == NULL) {
					HashEntry* nextEntry = entry->getNext();
					delete entry;
					table[hash] = nextEntry;
				}
				else {
					HashEntry* nextEntry = entry->getNext();
					delete entry;
					prevEntry->setNext(nextEntry);
				}
			}
		}
		
	}
};

void
test(HashMap* h) 
{
	record_t y;
	std::strcpy(y.key, "Hello there");
	y.value1 = 1;
	y.value2 = 2;
	try
	{
		h->insert(y.key, &y, sizeof(record_t));
	}
	catch (std::exception &e) 
	{
		std::cout << "Bad things Happened" << e.what() << std::endl;
	}

	try 
	{	
		h->find(y.key);
	}
	catch (std::exception &e)  
	{
		std::cout << "Bad things Happened" << e.what() << std::endl;
	}
	try 
	{
		h->remove(y.key);
	}
	catch(std::exception &e)
	{
		std::cout << "Bad things happened" << e.what() << std::endl;
	}
}

int 
main()
{
	HashMap* h = new HashMap();
	test(h);
	return 0;
}
