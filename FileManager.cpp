//
// Created by liududu on 17-9-6.
//

#include "FileManager.h"

FileManager::FileManager(const string & state) {
    //input.open(stdin);
    //output.open(stdout);
    this->state = state;
}

string FileManager::getFileName(const string& filePath){
    unsigned long index = filePath.find_last_of('/');
    return filePath.substr(index + 1);
}

string FileManager::getExtName(const string &fileName) {
    unsigned long index = fileName.find_last_of('.');
    return fileName.substr(index + 1);
}

bool FileManager::isHuf(const string &fileName) {
    return getExtName(fileName) == "huf";
}

bool FileManager::isHufc(const string &fileName) {
    return getExtName(fileName) == "hufc";
}
//TODO 这里有问题
bool FileManager::init(const string &filePath,const string &state){
    this->state = state.empty() ? this->state : state;
    //try {
        if (state == "read") {
            input.open(filePath,ios::binary);
        } else {
            output.open(filePath,ios::binary);
        }
        //}catch(){
        //    return false;
        //}
    return true;
}

string FileManager::getString() {
    stringstream buffer;
    buffer << input.rdbuf();
    return string(buffer.str());
}

bool FileManager::putString(string &code){
    output<<code;
    return true;
}
bool FileManager::writeMap(map<char,string>& code){
    for(map<char,string>::iterator it = code.begin(); it != code.end(); it ++){
        output<<it->first<<" "<<it->second<<endl;
    }
    return true;
}
map<char,string> FileManager::readMap(){
    map<char,string> code;
    char key;
    string value;
    while(!input.eof()){
        input>>key;
        input>>value;
        code[key] = value;
    }
    return code;
}

string FileManager::bit2string(const string & buf) {
    for(int i = 0; i <= buf.length(); i++){

    }
}

bool FileManager::close(){
    input.close();
    output.close();
}

