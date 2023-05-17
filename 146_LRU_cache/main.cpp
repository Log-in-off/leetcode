#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <unordered_map>

class LRUCache {
    std::list<std::pair<int, int>> cache_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
    int capacity_;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end())
            return -1;
        else
        {
            cache_.splice(cache_.end(),  cache_, it->second);
            return it->second->second;
        }
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
        if(it == map_.end())
        {
            if (cache_.size() == capacity_)
            {
                map_.erase(cache_.begin()->first);
                cache_.pop_front();
            }
            cache_.push_back({key,value});
            map_[key]=std::prev(cache_.end()); 
        }
        else
        {
            it->second->second=value;
            cache_.splice(cache_.end(),  cache_, it->second);
        }
        
    }
};

int main() 
{
    {
        LRUCache lRUCache = LRUCache(2);
        lRUCache.put(1, 1);
        lRUCache.put(2, 2);
        assert( 1  == lRUCache.get(1));
        lRUCache.put(3, 3);
        assert( -1 == lRUCache.get(2));
        lRUCache.put(4, 4);
        assert( -1 == lRUCache.get(1));
        assert( 3 == lRUCache.get(3));
        assert( 4 == lRUCache.get(4));
    }
    {
        LRUCache lRUCache = LRUCache(2);
        assert( -1 == lRUCache.get(2));
        lRUCache.put(2, 6);
        assert( -1 == lRUCache.get(1));
        lRUCache.put(1, 5);
        lRUCache.put(1, 2);
        assert(2 == lRUCache.get(1));;
        assert(6 == lRUCache.get(2));;

    }
    std::cout << "Test done" << std::endl;
    return 0;
}