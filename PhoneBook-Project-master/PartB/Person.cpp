#include "Person.h"
using namespace std;
#include "Phone.h"
#include<iostream>
Person::Person(const string name)
{
    this->name = name;
    head = NULL;
}
bool Person::addPhone( const int areaCode, const int number )
{
  if(phoneExist(areaCode,number))
    return false;

PhoneNode * nNode = new PhoneNode;
nNode->p = Phone(areaCode,number);

if(head == NULL)
{

  head = nNode;
  head ->next  = NULL;
}
else
{


    PhoneNode * temp = head;

    while(temp->next != NULL)
        {
            temp = temp->next;
        }
    temp->next = nNode;
}
return true;
}
Person::~Person()
{
PhoneNode * cur = head;
while( cur!= NULL)
{
    PhoneNode * temp = cur;
    delete temp;
    cur = cur->next;

}
head = NULL;
}

bool Person::phoneExist( const int areaCode, const int number )
{


    if( head == NULL)
    {

        return false;
    }
     PhoneNode * cur = head;


    while(cur!= NULL)
    {

        if(cur->p.getAreaCode() == areaCode && cur ->p.getNumber() == number)
        {
            return true;
        }
        cur = cur ->next;
    }
    return false;
}
void Person::operator=(const Person& right)
{

name = right.name;
}
void Person::displayPhoneNumbers()
{
    int index = 0;
    PhoneNode * cur = head;
    if( cur == NULL)
        return;
   for(int i = 0; i < getPhoneNumber();i++)
    {
        index++;
        cout<<"Phone number "<< index << " : " << cur->p.getAreaCode()<< " ,"<< cur->p.getNumber()<<endl;
        cur = cur ->next;
    }
}
bool Person::removePhone( const int areaCode, const int number )
{
      PhoneNode * prev = NULL;
     PhoneNode * cur = head;
    if( cur == NULL)
        return false;


    while(cur!= NULL)
    {
        if(cur->p.getAreaCode() == areaCode && cur ->p.getNumber() == number)
        {
           if(cur == head)
           {
               cur = head;
               head = head ->next;
           }
           else
           {
               cur = prev->next;
               prev -> next = cur->next;
           }
           cur->next = NULL;
           delete cur;
           cur = NULL;
           return true;
        }
        prev = cur;
        cur = cur ->next;
    }


    cout<<" Can't remove a non existing phone"<<endl;
    return false;
}
string Person::getName()
{
    return name;
}
int Person::getPhoneNumber()
{
    int numb = 0;
     PhoneNode * cur = head;
    if( cur == NULL)
        return 0;

    while(cur!= NULL)
    {
        numb++;

        cur = cur ->next;
    }
    return numb;
}
void Person::displayArea(int area)
{
    int time = 0;
    PhoneNode * cur = head;

    if( cur == NULL)
        return;


    while(cur!= NULL)
    {
      if(cur->p.getAreaCode() == area)
      {
          if( time == 0)
          {
              cout<<name<<endl;
              time = 1;
          }
          cout<<"Phone "<<cur->p.getAreaCode()<< " " << cur->p.getNumber()<<endl;
      }
        cur = cur ->next;
    }
}
bool Person::AreaExist(int area)
{
    PhoneNode * cur = head;

    if( cur == NULL)
        return false;


    while(cur!= NULL)
    {
      if(cur->p.getAreaCode() == area)
      {
         return true;
      }
        cur = cur ->next;
    }
    return false;
}
void Person::deleteList()
{
    PhoneNode * cur = head;
while( cur!= NULL)
{
    PhoneNode * temp = cur;
    delete temp;
    cur = cur->next;

}
head = NULL;
}
