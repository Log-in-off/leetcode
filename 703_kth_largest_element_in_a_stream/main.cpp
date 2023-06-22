#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q_;
    int k_;
public:
    KthLargest(int k, std::vector<int>& nums) {
        k_ = k;
        for(auto v: nums)
            q_.push(v);
        
        while(q_.size() > k_)
            q_.pop();
    }
    
    int add(int val) {
        q_.push(val);
        if (q_.size() > k_)
            q_.pop();
        return q_.top();
    }
};

int main() 
{
    std::vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest = KthLargest(3, nums);
    assert(4 == kthLargest.add(3));   // return 4
    assert(5 == kthLargest.add(5));   // return 5
    assert(5 == kthLargest.add(10));  // return 5
    assert(8 == kthLargest.add(9));   // return 8
    assert(8 == kthLargest.add(4));   // return 8
    std::cout << "Test done" << std::endl;
    return 0;
}