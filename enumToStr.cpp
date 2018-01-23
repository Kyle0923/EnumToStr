#include <map>
#include <string>
#include <iostream>
#define CREATE_ENUM_MAP(enumT) template<> SEnumName<enumT>::SEnumName()
#define MAP_ADD(val) Map[val] = #val

enum MyEnum{
    app,baba,pp
};

template<typename EnumType>
struct SEnumName{
    SEnumName();
    static std::map<int, std::string> Map;  
};

template <typename EnumType>  
const char* enumToStr(EnumType value)
{
    std::string rtn = "Invalid Enum";
    int count = SEnumName<EnumType>::Map.size();
    if (value <= count){
        rtn = SEnumName<EnumType>::Map[value];
    }
    return rtn.c_str();  
}  

CREATE_ENUM_MAP(MyEnum)
{
    MAP_ADD(app);
    MAP_ADD(baba);
    MAP_ADD(pp);
}
SEnumName<MyEnum> MyEnumObj;

int main(){
    std::cout << enumToStr<MyEnum>(app);
}
