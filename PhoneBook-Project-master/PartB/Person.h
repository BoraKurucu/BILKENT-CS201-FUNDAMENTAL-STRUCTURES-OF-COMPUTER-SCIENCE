#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "Phone.h"
using namespace std;
class Person{
public:
 Person( const string name = "" );
 ~Person();
 Person( const Person& personToCopy );
 void operator=( const Person &right );
 string getName();
 bool addPhone( const int areaCode, const int number );
 bool removePhone( const int areaCode, const int number );
 void displayPhoneNumbers();
 int getPhoneNumber();
 void displayArea(int area);
 bool phoneExist( const int areaCode, const int number );
 bool AreaExist( int area);
 void deleteList();
private:
 struct PhoneNode {
 Phone p;
 PhoneNode* next;
 };
 PhoneNode *head;
 PhoneNode *last;
 string name;
 PhoneNode* findPhone( const int areaCode, const int number );
};
#endif
