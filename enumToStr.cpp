#include <map>
#include <string>
#define CREATE_ENUM_MAP(enumT) template<>const std::map<int, std::string> SEnumName<enumT>::Map

enum MyEnum{
    app,baba,pp
};

template<typename EnumType>
struct SEnumName{  
    static const std::map<int, std::string> Map;  
};

template <typename EnumType>  
char* enumToStr(EnumType value)
{
    std::string rtn = "Invalid Enum";
    int count = SEnumName<EnumType>::Map.size();
    if (value <= count){
        rtn = SEnumName<EnumType>::Map[value];
    }
    return rtn.c_str();  
}  

// template<>const std::map<int, std::string> SEnumName<MyEnum>::Map
CREATE_ENUM_MAP(MyEnum) = 
{
    {app, "Status1"},
    {baba, "Status2"},
    {pp, "Status3"},
};
