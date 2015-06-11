#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache{
private:
	unordered_map<int, pair<int,list<int>::iterator> > m;
	list<int> l;
	int cap;
public:
	LRUCache(int capacity):cap(capacity) {

	}

	int get(int key) {
		unordered_map<int, pair<int, list<int>::iterator> >::iterator itr = m.find(key);
		if (itr == m.end())
			return -1;
		//l.remove(key);
		l.erase((*itr).second.second);
		l.push_front(key);
		return (*itr).second.first;
	}

	void set(int key, int value) {
		unordered_map<int, pair<int, list<int>::iterator> >::iterator itr = m.find(key);
		if (itr != m.end()){//update
			(*itr).second.first = value;
			l.erase((*itr).second.second);
			l.push_front(key);
		}
		else{
			if (m.size() == cap){
				int rmkey = l.back();
				l.pop_back();
				m.erase(rmkey);
			}
			l.push_front(key);
			m.insert(make_pair(key,pair<int,list<int>::iterator>(value,l.begin())));
			
		}
	}
	void printLRUCache(){
		for (list<int>::iterator it = l.begin(); it != l.end(); it++){
			cout << *it << " => " << m[*it].first << endl;
		}
	}
	void static test(){
		LRUCache cache(3);
		cache.set(0, 0);
		cache.set(1, 1);
		cache.set(2, 2);
		cache.printLRUCache();
		cout << cache.get(1) << endl;
		cout << cache.get(4) << endl;
		cache.printLRUCache();
		cache.set(0, 1);
		cache.printLRUCache();
		cache.set(4, 5);
		cache.printLRUCache();
	}
};