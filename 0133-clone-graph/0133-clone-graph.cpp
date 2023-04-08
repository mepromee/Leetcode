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
        if(node == nullptr) return node;
        if(valToNewNode.find(node->val) != valToNewNode.end()) return valToNewNode[node->val];
        Node* newNode = new Node(node->val);
        valToNewNode[node->val] = newNode;

        for(auto &nxt: node->neighbors) {
            auto newNxtNode = cloneGraph(nxt);
            newNode->neighbors.push_back(newNxtNode);
        }
        
        return newNode;
    }
private:
    unordered_map<int,Node*> valToNewNode;
};
/*
3:25
*/