#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Cache {
public:
	Cache(int n) {
		//Setting the size for the cache
        size = n;
	}

	T get(int key) {
		auto item = cacheData.find(key);
		use(item);
		return item->second.first;
	}

	void set(int key, T value) {
		auto item = cacheData.find(key);
		// Setting the value if key exist
		if (item != cacheData.end()) {
			use(item);
			cacheData[key] = { value, _lru.begin() };
			return;
		}

        //Checking size if key does not exist
		if (cacheData.size() == size) {
			// Erasing the least recently used term
			cacheData.erase(_lru.back());
			_lru.pop_back();
		}
		_lru.push_front(key);
		// Inserting new key-value pair
		cacheData.insert({ key, {value, _lru.begin()} });
	}

	void use(typename unordered_map<int, pair<T, list<int>::iterator>>::iterator& it)
           {
		_lru.erase(it->second.second);
		_lru.push_front(it->first);
		it->second.second = _lru.begin();
	}

private:
	int size;
	// < key, < value, key iterator>>
	typename std::unordered_map<int, std::pair<T, list<int>::iterator>> cacheData;

    //  list of keys, Most recently used at the beginning, least recently used at the last
    list<int> _lru;
};

int main() {

char alphabet[26] {};
iota(begin(alphabet), end(alphabet), 'A');

Cache<char> cache1(5);
cache1.set(1, alphabet[1]);
cache1.set(2, alphabet[2]);
std::cout << cache1.get(1) << std::endl;

vector<vector<int>> vec{ { 1, 2, 3 },
                         { 4, 5, 6 },
                         { 7, 8, 9, 4 } };

Cache<vector<int>> cache2(5);
cache2.set(1, vec[0]);
cache2.set(2, vec[1]);
vector<int>a;
a=cache2.get(1);
for(int i=0; i < a.size(); i++)
std::cout << a.at(i) << ' ';

return 0;
}
