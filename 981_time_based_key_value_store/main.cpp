#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

class TimeMap {
public:
    TimeMap() {        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        store_[key].push_back({value, timestamp});
    }
    
    std::string get(std::string key, int timestamp) {
    	auto it = store_.find(key);
    	if (it == store_.end())
    		return "";
    	
    	return high_bound(it->second, timestamp);
    	}
private:
	std::string high_bound(std::vector<std::pair<std::string, int>>& vec, int timestamp)
	{
		int l = 0, r = vec.size()-1;
	    	while(l <=r)
	    	{
	    		int mid = (l+r)/2;
	    		if (vec[mid].second == timestamp)
	    		{
	    			return vec[mid].first;
	    		}
	    		else if (vec[mid].second > timestamp)
	    		{
	    			r = mid-1;
	    		}
	    		else
	    		{
	    			l = mid+1;
	    		}
	    	}
	    	if (r >=0)
	    	{
	    		return vec[r].first;
	    	}
	    	return "";
	}
	std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> store_;
};


int main() 
{
    TimeMap timeMap = TimeMap();
    using namespace std::string_literals;
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    assert( "bar"s == timeMap.get("foo", 1));         // return "bar"
    assert( "bar"s == timeMap.get("foo", 3));         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    assert( "bar2"s == timeMap.get("foo", 4));         // return "bar2"
    assert( "bar2"s == timeMap.get("foo", 5));         // return "bar2"
    std::cout << "Test done" << std::endl;
    return 0;
}