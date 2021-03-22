/*
Implementing Cache Class for strong key,value pairs where value can be different data-types and data-structures and maintaining LRU.

Class Cache {
	Constructor Cache() :
	    Used to set the size of the cache.
			Parameters:
			     n: Size of cache

	Function getter() :
	    Used to get the value against a key, if cache-hit, the value ios returned.
		Parameters:
	        key : Key for the cache
	Function setter() :
	    Used to set the value in cache against the key provided.
		Parameters:
		    key:  Key for the cache
			value:  Value for the cache

}
*/

#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Cache {
public:
	Cache(int n) {
		//settting the size for the cache
        size = n;
	}

	// For gettting values stored in cash using the key
	T getter(int key) {
		auto item = cacheData.find(key);
		use(item);
		return item->second.first;
	}

	// For settting values in the cache
	void setter(int key, T value) {
		auto item = cacheData.find(key);
		// settting the value if key exist
		if (item != cacheData.end()) {
			use(item);
			cacheData[key] = { value, LRU.begin() };
			return;
		}

        //Checking size if key does not exist
		if (cacheData.size() == size) {
			// Erasing the least recently used term
			cacheData.erase(LRU.back());
			LRU.pop_back();
		}
		LRU.push_front(key);
		// Inserting new key-value pair
		cacheData.insert({ key, {value, LRU.begin()} });
	}

	void use(typename unordered_map<int, pair<T, list<int>::iterator>>::iterator& it)
           {
		LRU.erase(it->second.second);
		LRU.push_front(it->first);
		it->second.second = LRU.begin();
	}

private:
	int size;
	// < key, < value, key iterator>>
	typename std::unordered_map<int, std::pair<T, list<int>::iterator>> cacheData;

    //  list of keys, Most recently used at the beginning, least recently used at the last
    list<int> LRU;
};

int main() {

//Using the class for storing character values.
char alphabet[26] {};
iota(begin(alphabet), end(alphabet), 'A');

Cache<char> cache1(5);
cache1.setter(1, alphabet[1]);
cache1.setter(2, alphabet[2]);
std::cout << cache1.getter(4) << std::endl;

//Using the class for storing vectors.
vector<vector<int>> vec{ { 1, 2, 3 },
                         { 4, 5, 6 },
                         { 7, 8, 9, 4 } };

Cache<vector<int>> cache2(5);
cache2.setter(1, vec[0]);
cache2.setter(2, vec[1]);
vector<int>a;
a=cache2.getter(1);
for(int i=0; i < a.size(); i++)
std::cout << a.at(i) << ' ';

return 0;
}
