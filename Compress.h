//
// Created by liududu on 17-9-6.
//

#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include <string>
#include <map>
#include "Hufman.h"

using namespace std;

//TODO 文件模块加入file2map函数
//负责用编码map和源文件的buffer得到编码buffer
class Compress {
private:
    string fileBuffer;
    string encodeBuffer;
    string decodeBuffer;
    map<char,string> Hcode;
    Node* Htree;
    void _decode(string& buffer,Node* node,string::iterator ch);
public:
    Compress(const map<char,string>& Hcode,string& fileBuffer);
    void init(const map<char,string>& Hcode,string& fileBuffer);
    bool encode();
    bool decode();
    string output(bool flag);
    ~Compress();
};


#endif //HUFFMAN_COMPRESS_H
