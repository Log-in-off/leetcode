#include <iostream>
#include <list>
class BrowserHistory {
public:
    BrowserHistory(std::string homepage) {
        history_.push_back(homepage);
        current_ = history_.begin();
    }
    
    void visit(std::string url) {
        
        while(next(current_, 1) != history_.end())
            history_.pop_back();

        history_.push_back(url);
        current_ = prev(history_.end(), 1);
    }
    
    std::string back(int steps) {
        while(current_ != history_.begin() && steps >= 1)
        {
            current_--;
            steps--;
        }
        return *current_;
    }
    
    std::string forward(int steps) {
        for(int i = 0; i < steps; i++)
        {
            if (current_ != prev(history_.end(), 1))
                current_++;
            else
                break;    
        }
        return *current_;
    }
    std::list<std::string> history_;
    std::list<std::string>::iterator current_;
};


#include <cassert>
int main() {
    using namespace std::literals;
    BrowserHistory *browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");
    assert("facebook.com"s == browserHistory->back(1));
    assert("google.com"s == browserHistory->back(1));
    assert("facebook.com"s == browserHistory->forward(1));
    browserHistory->visit("linkedin.com");
    assert("linkedin.com"s == browserHistory->forward(2));
    assert("google.com"s == browserHistory->back(2));
    assert("leetcode.com"s == browserHistory->back(7)); 
    std::cout << "Test done" << std::endl;
    return 0;
}