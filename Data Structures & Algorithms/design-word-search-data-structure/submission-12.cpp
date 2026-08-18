class TriNode{
    public:
        char data;
        TriNode* childern[26];
        bool isTerminate;
    TriNode(){
        this->data='\0';
        this->isTerminate=false;
        for(int i=0;i<26;i++){
            childern[i]=NULL;
        }
        
    }
};

class WordDictionary {
public:
    TriNode* root;
    WordDictionary() {
        root=new TriNode();

    }
    
    void addWord(string word) {
        TriNode* curr=this->root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->childern[index]){
                curr=curr->childern[index];
            }
            else{
                TriNode* newNode=new TriNode();
                newNode->data=word[i];
                curr->childern[index]=newNode;
                curr=curr->childern[index];
            }
        }
        curr->isTerminate=true;
        return;

        
    }
    bool backtrack(string& word, TriNode* curr, int index) {

        if(word.size()==index){
            return curr->isTerminate;
        }
        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(curr->childern[i]){
                    if(backtrack(word,curr->childern[i],index+1)){
                        return true;
                    }
                }
            }
            return false;
        }
        int ind=word[index]-'a';
        if(curr->childern[ind]==NULL){
            return false;
        }
        return backtrack(word,curr->childern[ind],index+1);
    }

    bool search(string word) {
        TriNode* curr=this->root; 
        return backtrack(word,curr,0);
    }
};
