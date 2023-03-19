#include <iostream>

class Node {
    public:
    Node(){
        end_ =false;
        for(int i = 0; i < 26; i++)
            ch_[i] = nullptr;
    };
    Node* ch_[26];
    bool end_;
};

class WordDictionary {
    Node* root_;
public:
    WordDictionary():root_(new Node()) {}
    
    void addWord(std::string word) {
        int index = 0;
        Node* node = root_;
        for(auto c : word)
        {
            index = c - 'a';
            if (!node->ch_[index])
                node->ch_[index] = new Node ();
            node = node->ch_[index];
        }
        node->end_ = true;
    }
    
    bool search(std::string word) {
        return search(word, root_, 0);

    }
    bool search(std::string word, Node* node, int ind)
    {
        if (!node)
            return false;

        if (ind == word.size())
            return node->end_;
        
        
        if (word[ind] != '.')
            return search(word, node->ch_[word[ind]-'a'], ind + 1);

        for(int k = 0; k < 26; k++)
        {
            if ( search(word, node->ch_[k], ind+1))
                return true;    
        }
      
        return false;
    }

};

#include <cassert>
int main() {
    {
        WordDictionary* wordDictionary = new WordDictionary();
        wordDictionary->addWord("bad");
        wordDictionary->addWord("dad");
        wordDictionary->addWord("mad");
        assert( false == wordDictionary->search("pad"));
        assert( true == wordDictionary->search("bad"));
        assert( true == wordDictionary->search(".ad"));
        assert( true == wordDictionary->search("b.."));
        delete wordDictionary;
    }

    {
        WordDictionary* wordDictionary = new WordDictionary();
        wordDictionary->addWord("a");

        assert( true == wordDictionary->search("."));
        delete wordDictionary;
    }

    std::cout << "Test done" << std::endl;
    return 0;
}