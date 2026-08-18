class TriNode{
    public:
        char data;
        TriNode* childern[26];
        bool isterminal;
        TriNode(){
            this->data='\0';
            this->isterminal=false;
            for(int i=0;i<26;i++){
                childern[i]=NULL;
            }

        }
};

class PrefixTree {
public:
    TriNode* root;
    PrefixTree() {
        root=new TriNode();

    }
    
    void insert(string word) {
        TriNode* curr=this->root;
        for(int i=0;i<word.size();i++){
            
            int index=word[i]-'a';
            if(curr->childern[index]){
                curr=curr->childern[index];
                
            }
            else{
                TriNode* temp=new TriNode();
                temp->data=word[i];
                curr->childern[index]=temp;
                curr=curr->childern[index];
            }
        }
        curr->isterminal=true;
        return;
    }
    
    bool search(string word) {
        TriNode* curr=this->root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->childern[index]){
                curr=curr->childern[index];
            }
            else{
                return false;
            }
        }
        if(curr->isterminal==true){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TriNode* curr=this->root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(curr->childern[index]){
                curr=curr->childern[index];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
