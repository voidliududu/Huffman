//
// Created by liududu on 17-9-6.
//

#include "Hufman.h"
//TODO resumeTree，createLeaf的内存泄漏

//初始化huffman
Hufman::Hufman() {
    this->charCount = map<char,int>();
    this->hufTree = NULL;
    this->rhufTree = NULL;
    this->encode = map<char,string>();
}

//用字频统计表初始化
Hufman::Hufman(map<char, int>& count) {
    this->charCount = count;
    this->hufTree = NULL;
    this->rhufTree = NULL;
    this->encode = map<char, string>();
}

//创建hufman树
Node* Hufman::createTree() {
    //通过map创建元素为node*的优先队列
    priority_queue<Node*,vector<Node*>,nodeCmp> p;
    for(map<char,int>::iterator it = charCount.begin(); it != charCount.end();it++){
        p.push(new Node(it->first,it->second));
    }
    Node *n1,*n2,*n3;
    while(p.size() != 1){
        n1 = p.top();
        p.pop();
        n2 = p.top();
        p.pop();
        n3 = new Node('\0',n1->num + n2->num);
        n3->left = n1;
        n3->right = n2;
        p.push(n3);
    }
//    this->hufTree = new Node('\0',0);
//    this->hufTree->left = p.top();
    this->hufTree = p.top();
    return this->hufTree;
}

//生成huffman编码
void Hufman::createHCode(Node* tree,string code){
    if(tree->charactor != '\0'){
        encode[tree->charactor] = code;
        return;
    }
    createHCode(tree->left,code + "0");
    createHCode(tree->right,code + "1");
};

map<char,string>& Hufman::createEncode(){
    createHCode(this->hufTree,"");
    return encode;
}

//由huffman编码恢复huffman树
void Hufman::createLeaf(const string &code,const char& ch, Node *node, int flag) {
    if(flag < code.length()){
        if(code[flag] == '0'){
            if(node->left == NULL){
                node->left = new Node();
            }
            createLeaf(code,ch,node->left,++flag);
        }else{
            if(node->right == NULL){
                node->right = new Node();
            }
            createLeaf(code,ch,node->right,++flag);
        }
    } else{
        node->charactor = ch;
    }
}

Node* Hufman::resumeHtree(map<char, string> &rHcode) {
    rhufTree  = new Node();
    for(map<char,string>::iterator it = rHcode.begin();it != rHcode.end();it++){
        createLeaf(it->second,it->first,rhufTree,0);
    }
    return rhufTree;
}

//析构
Hufman::~Hufman(){
    delete hufTree;
    delete rhufTree;
}
