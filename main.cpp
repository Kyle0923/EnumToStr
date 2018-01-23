/* This file is a sample code of 
 * using libEnumToStr.a to print
 * a string representation of an
 * enumeration value.
 */

#include <iostream>
#include "EnumToStr.h"

// Enum definition
enum MyEnum{
    eOne = 1,
    eThree = 3,
    eElev = 11,
};

//use macro CREATE_ENUM_MAP to create a map to store the enum names
//#define CREATE_ENUM_MAP(enumT) template<>const std::map<int, std::string> SEnumName<enumT>::Map
// This is essentially a std::map<int, std::string> initialization list
CREATE_ENUM_MAP(MyEnum)
{
	//use macro PAIR to create and insert a pair into map
	//#define PAIR(element) {element, #element}
	PAIR(eOne),
	PAIR(eThree),
	PAIR(eElev),
};

int main(){
	std::cout << enumToStr<MyEnum>(1) << std::endl;
	std::cout << enumToStr<MyEnum>(3) << std::endl;
	std::cout << enumToStr<MyEnum>(11) << std::endl;
	std::cout << enumToStr<MyEnum>(10) << std::endl;
}
