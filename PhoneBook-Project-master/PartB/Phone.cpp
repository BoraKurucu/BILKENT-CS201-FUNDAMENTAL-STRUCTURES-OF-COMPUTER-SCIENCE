#include "Phone.h"
#include <iostream>
using namespace std;
Phone::Phone(const int areaCode,const int number)
{
    this->areaCode = areaCode;
    this->number =number;
}
Phone::Phone(const Phone & phoneToCopy)
{
    areaCode = phoneToCopy.areaCode;
    number = phoneToCopy.number;
}
Phone::~Phone()
{
    areaCode = 0;
    number = 0;
}
Phone::Phone()
{
    areaCode = 0;
    number = 0;
}
int Phone::getAreaCode()
{
    return areaCode;
}
int Phone::getNumber()
{
    return number;
}
void Phone::operator=(const Phone& right)
{

    areaCode = right.areaCode;
    number = right.number;
}
