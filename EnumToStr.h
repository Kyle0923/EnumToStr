#ifndef ENUM_TO_STR_H
#define ENUM_TO_STR_H

#pragma comment This file requires C11 standard

#include <map>
#include <string>
#include <iostream>

#define CREATE_ENUM_MAP(enumT) template<>const std::map<int, std::string> SEnumName<enumT>::Map
#define PAIR(element) {element, #element}

template<typename EnumType>
struct SEnumName{
    static const std::map<int, std::string> Map;
};

template <typename EnumType>
const char* enumToStr(int value);


template <typename EnumType>
const char* enumToStr(int value)
{
    if(SEnumName<EnumType>::Map.find(value) != SEnumName<EnumType>::Map.end()){
        return (SEnumName<EnumType>::Map).at(value).c_str();
    } else {
        return "unspecified value";
    }
}

#endif /* ENUM_TO_STR_H */
