//
// Created by liududu on 17-9-8.
//

#ifndef HUFFMAN_CLI_H
#define HUFFMAN_CLI_H

#include <iostream>
#include <string>
//#include <stdio.h>

#include "FileManager.h"
#include "Counter.h"
#include "Hufman.h"
#include "Compress.h"

using namespace std;

//命令行用户界面辅助类，负责用户交互相关功能的实现
class Cli {
private:
    int debug;
    void dumpMap(map<char,string> m);
    void dumpMap(map<char,int> m);
public:
    Cli();
    //打印问候信息
    void sayHello();
    void sayBye();
    //打印帮助信息
    void showHelp();
    //获取命令
    string getCommand();
    //解析命令
    bool judgeCommand(string command);
    //输出提示信息
    void showMsg(string msg,int flag);
    string question(string question);
    //输出错误信息
    /*
     * errType:
     * efile
     * ecommand
     * */
    void showErr(string msg,int errType);
    //询问并获取答案
    bool yoN(string question);
    bool compress();
    bool uncompress();
    bool start();

};


#endif //HUFFMAN_CLI_H
