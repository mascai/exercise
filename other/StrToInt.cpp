#include <string> 
#include <sstream>

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

template<typename T> 
T fromString(const std::string& s) 
{
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}

//Используется следующим образом

std::string str;
int iVal;
float fVal;

str = toString(iVal);
str = toString(fVal);

iVal = fromString<int>(str);
fVal = fromString<float>(str);
