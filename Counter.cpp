//
// Created by liududu on 17-9-6.
//

#include "Counter.h"

//构造函数，传人初始统计参数
Counter::Counter(map<char, int> initCount) {
    this->lastCount = initCount;
}

Counter::Counter() {
    this->lastCount = map<char,int>();
}
//由字符串s统计字符频率
map<char,int> Counter::countChar(string s) {
    string::iterator c;
    for(c = s.begin(); c != s.end(); c++){
        if(lastCount.find(*c) != lastCount.end())
            lastCount[*c] ++;
        else
            lastCount[*c] = 1;
    }
    return lastCount;
}