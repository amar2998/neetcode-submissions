/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node==NULL){
            return NULL;
        }
        queue<Node*> q;
        unordered_map<int,Node*> mapNode;
        Node* newNode=new Node(node->val);
        mapNode[node->val]=newNode;
        q.push(node);
        
        while(!q.empty()){
            Node* top=q.front();
            Node* currNode=mapNode[top->val];
            q.pop();
            for(int i=0;i< top->neighbors.size();i++){
                if(mapNode.find(top->neighbors[i]->val)== mapNode.end()){
                    Node * tempNode=new Node(top->neighbors[i]->val);
                    currNode->neighbors.push_back(tempNode);
                    mapNode[tempNode->val]=tempNode;
                    q.push(top->neighbors[i]);
                }
                else{
                    Node* tempNode=mapNode[top->neighbors[i]->val];
                    currNode->neighbors.push_back(tempNode);

                }
            }
        }
        return newNode;

        
    }
};
