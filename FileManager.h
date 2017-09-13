//
// Created by liududu on 17-9-6.
//

#ifndef HUFFMAN_FILEMANAGER_H
#define HUFFMAN_FILEMANAGER_H

#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;
class FileManager {
private:
    string fileName;
    string fileType;
    float fileSize;
    string state;
    ifstream input;
    ofstream output;
    string bit2string(const string & buf);
    //char* string2bit(string&buf);
    //string getString();
public:
    FileManager(const string& state);
    bool init(const string & filePath,const string &state = "");
//    string readString(int num);
//    bool writeString(string& buf);
//    string readBit(int num);
//    bool writeBit(string& buf);
    static string getFileName(const string& filePath);
    static string getExtName(const string& fileName);
    static bool isHuf(const string& fileName);
    static bool isHufc(const string& fileName);
    bool writeMap(map<char,string>& code);
    map<char,string> readMap();
    string getString();
    bool putString(string& code);
    bool close();
};


#endif //HUFFMAN_FILEMANAGER_H
