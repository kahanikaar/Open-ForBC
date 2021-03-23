/*
Implementing Cache Class for strong key,value pairs where value can be different data-types and data-structures and maintaining LRU.
Appropriate examples are provided in the main() function to implement cache on characters, vectors and vector of vectors.
Uses a template class to declare the cache class which is capable of handling data of any data-type.

Class Cache {
	Constructor Cache() :
	    Used to set the size of the cache.
			Parameters:
			     n: Size of cache

	Function getter() :
	    Used to get the value against a key, if cache-hit, the value ios returned.
		Parameters:
	        dataArray : The data array from where values will be taken for caching
			key : Key for the cache
        Returns: Value for provided key, if cache hit, fetches directly from the cache, if cache miss, sets the value in the cache and then returns
		Return type: Template type

	Function setter() :
	    Used to set the value in cache against the key provided.
		Parameters:
		    key:  Key for the cache
			value:  Value for the cache
		Returns: Void- Just sets the value for the key provided and updates the LRU. If size of cache is full, then removes the least used value.

	Function use():
	    Used to modify the hash map where keys and iterator to the values referenced by the keys are stored.
		Calling this will make the recently used value to reside in the first place of the dequeue and
		repositioning subsequent values.
		Parameters:
		    it: Iterator to the dequeue where hash is stored

	Data Member size:
	    For storing the size of the cache
		Type: int

	Data Member cacheData:
	    For storing the key value pairs of the cache.
		Type: Unordered map for <key, <value, key iterator>>

	Data Member LRU:
	    For storing the keys for the cache from where the functions are called for checking cache hit or cache miss,
		Type: Dequeue of type int


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
	T getter(vector<T> dataArray, int key) {
		auto item = cacheData.find(key);

		if (item == cacheData.end()) {
			this->setter(key,dataArray[key]);
			item = cacheData.find(key);
		}
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
	}about:preferences#search

private:
	int size;
	// < key, < value, key iterator>>
	typename std::unordered_map<int, std::pair<T, list<int>::iterator>> cacheData;

    //  list of keys, Most recently used at the beginning, least recently used at the last
    list<int> LRU;
};

int main() {



//Using the Cache for storing character values.
vector<char> alphabet(27);
iota(alphabet.begin()+1, alphabet.end(), 'A');
Cache<char> cache1(5);
cache1.setter(1, alphabet[1]);
cache1.setter(2, alphabet[2]);
std::cout << cache1.getter(alphabet,4) << std::endl;




//Using the Cache for storing vectors.
vector<vector<int>> vec{ { 1, 2, 3 },
                         { 4, 5, 6 },
                         { 7, 8, 9, 4 } };

Cache<vector<int>> cache2(5);
cache2.setter(1, vec[0]);
cache2.setter(2, vec[1]);
vector<int>a;
a=cache2.getter(vec,1);
for(int i=0; i < a.size(); i++)
std::cout << a.at(i) << ' ';




//Using the Cache for storing vector of vectors.
vector< vector< vector<int> > > vect(3, vector< vector<int> >(3 , vector<int>(3)));
for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            for(int k=0;k<3;++k){
                vect[i][j][k] = i*3*3 + j*3 + k;
            }
        }
    }
Cache<vector<vector<int>>> cache3(5);
cache3.setter(1, vect[0]);
cache3.setter(2, vect[1]);
vector<vector<int>>b;

b=cache3.getter(vect,1);
for(int p=0; p < b.size(); p++)
{
	for(int q=0; q < b.at(0).size(); q++ )
    std::cout << b[p][q] << ' ';
    cout<<"\n";
}

return 0;

}
