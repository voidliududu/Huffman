//#include <iostream>
//#include <string>
//#include <map>
//#include "Counter.h"
//#include "Hufman.h"
//#include "Compress.h"
//#include "FileManager.h"
#include "Cli.h"
//测试file模块
using namespace std;
//测试huffman。cpp
int main() {
//    std::cout << "Hello, World!" << std::endl;
//    Counter c;
//    string hello = "hello world";
//    map<char,int> count = c.countChar(hello);
//    for(map<char,int>::iterator it = count.begin();it != count.end();it++){
//        cout<<'\''<<it->first<<'\''<<"=>"<<it->second<<endl;
//    }
//    Hufman f(count);
//    f.createTree();
//    map<char,string>& e = f.createEncode();
//    for(map<char,string>::iterator t = e.begin();t != e.end();t++){
//        cout<<'\''<<t->first<<'\''<<"=>"<<t->second<<endl;
//    }
//    Compress com(e,hello);
//    com.encode();
//    string out = com.output(true);
//    cout<<out;
//    com.init(e,out);
//    com.decode();
//    cout<<com.output(false);
//    FileManager input("read");
//    input.init("../test.txt","read");
//    cout<<input.getString();

//    map<char,string> m;
//    m['c'] = "hello";
//    m['d'] = "world";
//    m['j'] = "!";
//    FileManager output("write");
//    output.init("hello.txt","");
//    output.writeMap(m);
//    output.close();
//    FileManager input("read");
//    input.init("hello.txt","read");
//    map<char,string> c = input.readMap();
//    for(auto it = c.begin();it != c.end();it++){
//        cout<<it->first<<"=>"<<it->second<<endl;
//    }
    Cli p;
    p.start();
    return 0;
//    char* m = "hello";
//     string a = string(m);
//    cout<<a;
}