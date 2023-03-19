#include <iostream>

class Node {
    public:
    Node(){
        for(int i = 0; i < 26; i++)
            ch_[i] = nullptr;
    };
    Node* ch_[26];
    bool end_ = false;
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
        return search(word, 0, root_);

    }

    bool search(std::string &word, int index, Node* node)
    {
        if (index == word.size())
            return node->end_;        
        
        if (word[index] != '.')
        {
            Node *tmp = node->ch_[word[index]-'a'];
            return tmp && search(word, index + 1, tmp);
        }

        for(int k = 0; k < 26; k++)
        {
            if ( node->ch_[k] && search(word, index+1, node->ch_[k]))
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