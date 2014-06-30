#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include "cpp_common.h"
using namespace CppCommonFunction;

int StringFunction::split(const string& str, char spliter,vector<string>& result){
    result.clear();
    istringstream ss( str );
    string feild;
    while (!ss.eof()){
        string x;              // here's a nice, empty string
        getline( ss, feild, spliter );  // try to read the next field into it
        result.push_back(feild);
        //   cout << x << endl;    // print it out, even if we already hit EOF
    }
    return result.size();
}

string StringFunction::join(const vector<string>& strs,char sep){
    if(strs.size()==0){
        return string("");
    }
    if(strs.size()==1){
        return strs[0];
    }
    string sep_str(1,sep);
    string result;
    for(int i=0;i<strs.size()-1;i++){
        result+=strs[i]+sep_str;
    }
    return result+=strs.back();
}

string TimeFunction::now(){
    time_t t=time(0);
    return string(asctime(localtime(&t)));
}
bool IndexAdapter::InitFromFile(const std::string& file_name,unsigned int index_of_key,char spliter){
    std::ifstream fin(file_name.c_str());
    if(!fin.is_open()){
        std::cerr<<"open file "<<file_name<<" failed."<<std::endl;
        return false;
    }
    keys_.clear();
    std::string line;
    std::vector<std::string> line_vec;
    while(std::getline(fin,line)){
        int n=StringFunction::split(line,spliter,line_vec);
        if(index_of_key>=n){
            std::cerr<<"WARNING:broken line,index of key out of line items"<<std::endl;
        }else{
            dict_.insert(std::map<std::string,unsigned int>::value_type(line_vec[index_of_key],keys_.size()));
            keys_.push_back(line_vec[index_of_key]);
        }
    }
    fin.close();
    return true;
}
bool IndexAdapter::GetIndex(const std::string& key,unsigned int& index)const{
    std::map<std::string,unsigned int>::const_iterator iter=dict_.find(key);
    if(iter==dict_.end())   return false;
    index=iter->second;
    return true;
}
bool IndexAdapter::GetValue(unsigned int index,std::string& value)const{
    if(index>=keys_.size())    return false;
    value=keys_[index];
    return true;
}
unsigned int IndexAdapter::GetSize()const{
    return keys_.size();
}

