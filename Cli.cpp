//
// Created by liududu on 17-9-8.
//

#include "Cli.h"

Cli::Cli(){
    debug = 1;
}
void Cli::sayHello() {
    cout<<"欢迎使用huffman编码与解码演示系统"<<endl;
    cout<<"该系统可将文件或终端输入的字符用huffman算法编码或解码"<<endl;
    showHelp();
}

void Cli::sayBye(){
    cout<<"Bye";
}
void Cli::showHelp() {
    cout<<"help infomation"<<endl;
    cout<<"输入compress进入编码交互环境"<<endl;
    cout<<"输入uncompress进入解码交互环境"<<endl;
    cout<<"输入help显示这份帮助"<<endl;
    cout<<"输入exit退出该系统"<<endl;
}

void Cli::dumpMap(map<char,int> m){
    //unsigned long length = m.size();
    int count=0;
    for(map<char,int>::iterator it = m.begin(); it != m.end(); it++){
        cout<<"\'"<<it->first<<"\'"<<"=>"<<it->second<<'\t';
        count++;
        if(count%3 == 0){
            cout<<endl;
        }
    }
    cout<<endl;
}

void Cli::dumpMap(map<char,string> m){
    unsigned long length = m.size();
    int count = 0;
    for(map<char,string>::iterator it = m.begin(); it != m.end(); it++){
        cout<<"\'"<<it->first<<"\'"<<"=>"<<it->second<<'\t';
        count++;
        if(count%3 == 0){
            cout<<endl;
        }
    }
    cout<<endl;
}

string Cli::getCommand(){
    cout<<"Huffman>>";
    string command;
    cin>>command;
    return command;
}

bool Cli::judgeCommand(string command) {
    if(command == "help"){
        showHelp();
        return true;
    }
    if(command == "exit"){
        exit(0);
    }
    if(command == "compress"){
        compress();
        return true;
    }
    if(command == "uncompress"){
        uncompress();
        return true;
    }
    showMsg("未识别的命令",1);
    if(yoN("是否显示帮助？"))
        showHelp();
}

bool Cli::start(){
    sayHello();
    while(true){
        judgeCommand(getCommand());
    }
}

void Cli::showMsg(string msg,int flag){
    if(debug == 1 || flag == 1)
    cout<<msg<<endl;
}

string Cli::question(string question) {
    cout<<question<<endl;
    //cin.ignore();
    //char m[100];
    //cin.getline(m,sizeof(m));
    //string res = string(m);
    string res;
    cin>>res;
    return res;
}

bool Cli::yoN(string question){
    cout<<question<<"(y/N)";
    string answer;
    cin>>answer;
    if(answer == "y" || answer == "Y"){
        return true;
    }
    if(answer == "n" || answer == "N"){
        return false;
    }
    cout<<"呃。。。看来你真的是个小白，"<<endl;
    cout<<"y/Y表示肯定，n/N表示否定"<<endl;
    return yoN(question);
}


bool Cli::compress() {
    string word;
    bool answer = yoN(string("要从文件中读入编码数据吗？"));
    if(answer){
        string filename = question("请输入待编码文件名");
        FileManager input("read");
        input.init(filename,"read");
        word = input.getString();
        showMsg("文件读入成功",1);
    }else{
        showMsg("将从终端读入字符",1);
        word = question("请输入待编码的字符，按回车结束");
        showMsg("字符读入成功",1);
    }
    Counter counter;
    map<char,int> charNum;
    showMsg("正在统计字频",1);
    charNum = counter.countChar(word);
    showMsg("字频统计成功",1);
    if(yoN("要输出字符统计结果吗？"))
        dumpMap(charNum);
    Hufman hufman(charNum);
    showMsg("正在创建huffman树",1);
    hufman.createTree();
    showMsg("正在生成huffman编码",1);
    map<char,string>& code = hufman.createEncode();
    if(yoN("是否显示huffman编码表"))
        dumpMap(code);
    Compress compress(code,word);
    showMsg("正在编码",1);
    compress.encode();
    string encodeCode = compress.output(true);
    showMsg("编码成功",1);
    if(yoN("是否显示在终端上？"))
        cout<<encodeCode<<endl;
    if(yoN("是否输出到文件？")){
        string filePath = question("请输入文件名(不用输入扩展名)");
        string dfilePath = filePath + ".huf";
        string hfilePath = filePath + ".hufc";
        FileManager output("write");
        output.init(dfilePath,"write");
        showMsg("正在写入编码文件",1);
        output.putString(encodeCode);
        output.close();
        showMsg("写入编码成功",1);
        output.init(hfilePath,"write");
        showMsg("正在写入编码信息",1);
        output.writeMap(code);
        output.close();
        showMsg("写入编码信息成功",1);
        showMsg("文件清单:",1);
        showMsg(dfilePath,1);
        showMsg(hfilePath,1);
    }
}

bool Cli::uncompress() {
    string word;
    map<char,string> code;
    string codeFileName = question("请输入编码文件名（后缀为.huf）");
    FileManager input("read");
    input.init(codeFileName,"read");
    word = input.getString();
    showMsg("文件读入成功",1);
    input.close();
    string hufFileName = question("请输入huffman编码文件名(后缀为.hufc)");
    cout<<hufFileName;
    FileManager input2("read");
    input2.init(hufFileName,"read");
    code = input2.readMap();
    input2.close();
    showMsg("文件读入成功",1);
    Compress compress(code,word);
    showMsg("正在解码",1);
    compress.decode();
    string decodeWord = compress.output(false);
    showMsg("解码成功",1);
    if(yoN("要显示在终端上吗？"))
        cout<<decodeWord<<endl;
    if(yoN("要写入文件吗？")){
        string filePath = question("请输入文件名(不用输入扩展名)");
        FileManager output("write");
        output.init(filePath,"write");
        showMsg("正在写入文件",1);
        output.putString(decodeWord);
        output.close();
        showMsg("写入文件成功",1);
    }
}

