#include <iostream>
#include <string_view>
#include <set>
#include <cassert>
class Trie {
public:
    Trie() {
        
    }
    
    void insert(std::string word) {
        store.insert(word);        
    }
    
    bool search(std::string word) {
        return store.end() != store.find(word);
    }
    
    bool startsWith(std::string prefix) {
        auto it = store.lower_bound(prefix);
        

        if (store.end() == it )
            return false;
        
        std::string::size_type n = (*it).find(prefix);
        return n == 0;
    }
    std::set<std::string> store;
};

/**
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
*/
int main() {

    Trie *trie = new Trie();
    trie->insert("apple");
    assert(true == trie->search("apple"));
    assert(false == trie->search("app"));
    assert(true == trie->startsWith("app"));
    trie->insert("app");
    assert(true == trie->search("app"));
    std::cout << "Test done" << std::endl;
    return 0;
}