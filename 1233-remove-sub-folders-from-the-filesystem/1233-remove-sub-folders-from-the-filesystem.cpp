
class TrieNode {
  public:
    bool isLeaf;
    TrieNode* children[27];
    
    TrieNode() {
        isLeaf = false;
        for(int i=0;i<27;i++) {
            children[i]=NULL;
        }
    }
};

class Trie {
  private:
    TrieNode* root;
  public:
    Trie() {
        root = new TrieNode();
    }
    
    bool insert(string word) {
        int len = word.size();
        int index = 0;
        TrieNode* cur = root;        
        
        for(int i=0;i<len;i++) {
            if(word[i]=='/') index = 26;
            else index = word[i]-'a';

            if(cur->children[index]==NULL) {
                cur->children[index] = new TrieNode();
            } 
            cur = cur->children[index];
            if(word[i+1]=='/' && cur->isLeaf==true) return false;
        }
        cur->isLeaf = true;
        return true;
    }
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(), folder.end());
        Trie* obj = new Trie();

        vector<string> ans;

        for(auto it : folder) {
            if(obj->insert(it)) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};
