//
// Created by liududu on 17-9-6.
//

#ifndef HUFFMAN_HUFMAN_H
#define HUFFMAN_HUFMAN_H

#include <string>
#include <map>
#include <queue>

using namespace std;
//实现由字频统计表生成huffman树

class Node;

class Hufman {
private:
    //储存字频统计map
    map<char,int> charCount;
    //储存生成的huffman树
    Node* hufTree;
    Node* rhufTree;
    //储存生成的huffman编码
    map<char,string> encode;
    //生成huffman编码
    void createHCode(Node* tree,string code);
    void createLeaf(const string& code,const char& ch,Node* node,int flag);
public:
    //初始化huffman类
    Hufman(map<char,int>& count);
    Hufman();
    //创建huffman树
    Node* createTree();
    //提供生成huffman编码的接口
    map<char,string>& createEncode();
    //由huffman编码生成huffman树
    Node* resumeHtree(map<char,string>& rHcode);
    ~Hufman();
};

//node类作为树的节点
class Node{
public:
    char charactor;
    int num;
    Node* left;
    Node* right;
    Node(char key = '\0',int num = 0){
        this->charactor = key;
        this->num = num;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node(){
        delete left;
        delete right;
    };
};

//nodeCmp结构用于确定优先级
struct nodeCmp{
    bool operator()(Node* a,Node* b){
        return a->num > b->num;
    }
};


#endif //HUFFMAN_HUFMAN_H
