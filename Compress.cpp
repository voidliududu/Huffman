//
// Created by liududu on 17-9-6.
//

#include "Compress.h"


Compress::Compress(const map<char, string>& Hcode, string& fileBuffer) {
    init(Hcode,fileBuffer);
}

//初始化
void Compress::init(const map<char, string>& Hcode, string& fileBuffer) {
    this->Hcode  = Hcode;
    this->fileBuffer = fileBuffer;
    this->Htree = NULL;
}

//编码
bool Compress::encode() {
    for(string::iterator ch = fileBuffer.begin();ch != fileBuffer.end();ch++){
        encodeBuffer.append(Hcode[*ch]);
    }
    return true;
}


//这个函数写的很糟糕
void Compress::_decode(string& buffer,Node* node,string::iterator ch){
    if (node->charactor != '\0') {
        decodeBuffer.append(string(1,node->charactor));
        _decode(buffer, Htree,ch);
        return;
    }
    if(ch != buffer.end()) {
        if (*ch == '0') {
            _decode(buffer, node->left, ++ch);
        } else {
            _decode(buffer, node->right, ++ch);
        }
    }
}


//解码
bool Compress::decode() {
    Hufman h;
    Htree = h.resumeHtree(Hcode);
    _decode(fileBuffer,Htree,fileBuffer.begin());
}

//输出
string Compress::output(bool flag){
    if(flag){
        return encodeBuffer;
    }else{
        return decodeBuffer;
    }
}

Compress::~Compress() {
//    if(Htree != NULL)
//    delete Htree;
}