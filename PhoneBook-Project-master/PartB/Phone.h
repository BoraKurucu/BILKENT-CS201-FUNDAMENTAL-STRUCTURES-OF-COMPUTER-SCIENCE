#ifndef PHONE_H
#define PHONE_H

class Phone{
public:
Phone();
 Phone( const int areaCode, const int number );
 Phone (const Phone & phoneToCopy);
 void operator=(const Phone & right);
 int getAreaCode();
 int getNumber();
~Phone();
private:
 int areaCode;
 int number;
};
#endif
