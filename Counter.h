//
// Created by liududu on 17-9-6.
//

#ifndef HUFFMAN_COUNTER_H
#define HUFFMAN_COUNTER_H

#include <string>
#include <map>

using namespace std;

//字频统计模块
class Counter {
private:
    map<char,int> lastCount;
public:
    Counter(map<char,int> initCount);
    Counter();
    map<char,int> countChar(string s);
};


#endif //HUFFMAN_COUNTER_H
