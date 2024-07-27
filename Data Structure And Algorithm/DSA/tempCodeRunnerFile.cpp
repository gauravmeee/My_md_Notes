#include <bits/stdc++.h>
using namespace std;

struct Node{
      int *link[26];
      bool flag=0;
};

class Trie{
   private: Node* root;
   public:
         Trie(){
            root = new Node;
         }

         void insert(string word){
            Node* node = root;
            for(int i=0; i<word.length(); i++){
               
            }
         }


};
