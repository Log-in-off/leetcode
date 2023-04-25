#include <iostream>
#include <cassert>
#include <vector>
#include <set>

/*
https://leetcode.com/problems/smallest-number-in-infinite-set/description/
*/

class SmallestInfiniteSet {
    std::set<int> add;
    uint value;
public:
    SmallestInfiniteSet() {
        value = 1;
    }
    
    int popSmallest() {
        if (add.empty())
            return value++;
        
        int answer = *add.begin();
        add.erase(answer);
        return answer;
    }
    
    void addBack(int num) {
        if (num < value)
            add.insert(num);
    }
};

int main() 
{
    SmallestInfiniteSet smallestInfiniteSet;
    smallestInfiniteSet.addBack(2);
    assert( 1 == smallestInfiniteSet.popSmallest());
    assert( 2 == smallestInfiniteSet.popSmallest());
    assert( 3 == smallestInfiniteSet.popSmallest());
    smallestInfiniteSet.addBack(1);
    assert( 1 == smallestInfiniteSet.popSmallest());
    assert( 4 == smallestInfiniteSet.popSmallest());
    assert( 5 == smallestInfiniteSet.popSmallest());
    std::cout << "Test done" << std::endl;
    return 0;
}