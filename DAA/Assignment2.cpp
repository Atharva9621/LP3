#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <queue>
using namespace std;

class HuffmanTree{
    public:
        class HuffmanNode{
            public:
                int weight;
                HuffmanNode* left;
                HuffmanNode* right;
                bool isLeaf;
                int data;

                HuffmanNode();

                HuffmanNode(int weight){
                    this->isLeaf = false;
                    this->weight = weight;
                    this->data = 0;
                }

                HuffmanNode(int data, int weight){
                    this->data = data;
                    this->weight = weight;
                    this->isLeaf = true;
                }

                bool operator < (const HuffmanNode& other){
                    return this->weight < other.weight;
                }

                friend std::ostream& operator<<(std::ostream& os, const HuffmanNode& node){
                    os << "Node( weight: " << node.weight << ", data: " << node.data<<" )";
                    return os;
                };
        };

        class HuffmanNodeComparator{
            public:
                bool operator()(const HuffmanNode* a, const HuffmanNode* b){
                    return a->weight > b->weight; //inverted
                }
        };

        map<char, string>codes;
        HuffmanNode* root;

        void fit(string s){
            priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNodeComparator> nodes = _initNodes(s);
            this->root = this->_buildTree(nodes);
            codes.clear();
            //Generate new codes
            this->_traverseTreeRecursive(root, codes);
        } 

        string operator[] (char c){
            return this->codes[c];
        }

    protected:
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNodeComparator> _initNodes(string s){
            map<char, int>m;
            for (auto &&i : s) m[i]++;
            priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNodeComparator>nodes;
            // vector<HuffmanNode*>nodes;
            for (auto &&i : m)nodes.push(new HuffmanNode(i.first, i.second));
            return nodes;
        }

        HuffmanNode* _buildTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNodeComparator> nodes){
            while(nodes.size()>1){
                HuffmanNode* a = nodes.top(); nodes.pop();
                HuffmanNode* b = nodes.top(); nodes.pop();
                nodes.push(_mergeNodes(a, b));
            }
            return nodes.top();
        }

        void _traverseTreeRecursive(HuffmanNode* root, map<char, string>&res, string code = ""){
            if(root->isLeaf){
                res[root->data] = code;
                return;
            }
            if(root->left)_traverseTreeRecursive(root->left, res, code+'0');
            if(root->right)_traverseTreeRecursive(root->right, res, code+'1');
        }

        HuffmanNode* _mergeNodes(HuffmanNode* a, HuffmanNode* b){
            HuffmanNode* mergedRoot = new HuffmanNode(a->weight+b->weight);
            mergedRoot->left = a;
            mergedRoot->right = b;
            return mergedRoot;
        }
};

int main(){
    string s = "hello worldlllllwwww";
    HuffmanTree ht = HuffmanTree();
    ht.fit(s);
    cout<<"h: "<<ht['h']<<endl;
    cout<<"l: "<<ht['l']<<endl;
    cout<<"w: "<<ht['w']<<endl;
}