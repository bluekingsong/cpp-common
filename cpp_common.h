#ifndef CPP_COMMON_COMMON_H_
#define CPP_COMMON_COMMON_H_
#include <vector>
#include <string>
#include <map>
using namespace std;
namespace CppCommonFunction{

class StringFunction{
  public:
    static int split(const string& str, char spliter,vector<string>& result);
    static string join(const vector<string>& strs,char sep);
};
class TimeFunction{
  public:
    static string now();
};
class IndexAdapter{
  public:
      IndexAdapter(){
      }
      bool InitFromFile(const std::string& file_name,unsigned int index_of_key=0,char spliter='\t');
      bool GetIndex(const std::string& key,unsigned int& index)const;
      bool GetValue(unsigned int index, std::string& value)const;
      unsigned int GetSize()const;
  private:
      std::vector<std::string> keys_;
      std::map<std::string,unsigned int> dict_;
};

}; //CppCommonFunction
#endif // CPP_COMMON_COMMON_H_
