#ifndef __SIMPLE_PHONEBOOK_H
#define __SIMPLE_PHONEBOOK_H
#include <string>
using namespace std;
#include "SimplePerson.h"
class PhoneBook{
public:
 PhoneBook();
 ~PhoneBook();
 PhoneBook (const PhoneBook& phoneBookToCopy);
 void operator=(const PhoneBook& right);
 bool addPerson(const string name);
 bool removePerson(const string name);
 void displayPeople();
 bool PersonExist(string name);
int  findIndex(string name);

private:
 struct PersonNode {
 Person t;
 PersonNode* next;
 };
 PersonNode *head;
 int numberOfPeople;
 PersonNode* findPerson(string name);
 PersonNode* findPerson(int index);
};
#endif
