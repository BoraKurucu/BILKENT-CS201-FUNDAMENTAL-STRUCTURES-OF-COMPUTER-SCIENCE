#include "SimplePhoneBook.h"
using namespace std;
#include<iostream>
PhoneBook::PhoneBook()
{

head = NULL;
//head -> next = NULL;
numberOfPeople = 0;
}

PhoneBook::~PhoneBook()
{

PersonNode * cur = head;
while(cur != NULL)
{
    PersonNode * next = cur->next;
    delete cur;
    cur = next;
}
head = NULL;
numberOfPeople = 0;
}

PhoneBook::PhoneBook(const PhoneBook& phoneBookToCopy)
{

    if(phoneBookToCopy.head == NULL)
        head = NULL;
    else
    {
    // copy first node
    numberOfPeople = phoneBookToCopy.numberOfPeople;
      head = new PersonNode;
      head->t = phoneBookToCopy.head->t;
      // copy rest of list
      PersonNode *newPtr = head;

      for (PersonNode *origPtr = phoneBookToCopy.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new PersonNode;
         newPtr = newPtr->next;
         newPtr->t = origPtr->t;
      }
      newPtr->next = NULL;
   }
}

void PhoneBook::operator=(const PhoneBook& right)
{

    if(this != &right)
    {
       if(right.head == NULL)
        head = NULL;
    else
    {
       delete head;
      head = new PersonNode;
      head->t = right.head->t;
      // copy rest of list
      PersonNode *newPtr = head;
       numberOfPeople = right.numberOfPeople;
      for (PersonNode *origPtr = right.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new PersonNode;
         newPtr = newPtr->next;
         newPtr->t = origPtr->t;
      }
      newPtr->next = NULL;
   }
    }
}
bool PhoneBook::PersonExist(string name)
{

    PersonNode * cur = head;
    while(cur != NULL)
{


    if(  (cur-> t).getName() == name)
    {

        return true;
        break;
    }

    cur = cur->next;

};
return false;
}
bool PhoneBook::addPerson(const string name)
{

    if( PersonExist(name))
    {

        return false;
    }
       PersonNode * nNode = new PersonNode;
        nNode->t = Person(name);

    if(head == NULL)
    {

        head = nNode;
        head -> next = NULL;
        return true;
    }

    PersonNode* temp = head;

    while(temp->next!= NULL)
    {
        temp = temp -> next;
    }
    temp->next = nNode;
    nNode -> next = NULL;

    numberOfPeople++;

    return true;
}
int PhoneBook::findIndex(string name)
{
    int index = 1;

    bool found = false;
    PersonNode * cur = head;
    while(cur != NULL)
   {

    if( cur != NULL &&  (cur-> t).getName() == name)
    {
      found = true;
       break;
    }
    index++;
    cur = cur->next;
    }
if(found)
   return index;
   else
    return 0;

}
bool PhoneBook::removePerson(const string name)
{
      PersonNode *cur;
  if(!(PersonExist(name)))
  {

    return false;
  }


int index = findIndex(name);

   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      PersonNode *prev = findPerson(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   numberOfPeople--;
   return true;

}
void PhoneBook::displayPeople()
{

    if(head == NULL)
    {

            cout<<"---EMPTY---"<<endl;

    }
    else
    {

        PersonNode * curr = head;
        while(curr != NULL) {
        cout<<curr->t.getName()<<endl;
        curr = curr->next;
    }
}
}
PhoneBook::PersonNode * PhoneBook::findPerson(int index)
{


   if ( (index < 1) || (index > numberOfPeople) )
      return NULL;

   else{ // count from the beginning of the list
      PersonNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;

}
}
PhoneBook::PersonNode * PhoneBook::findPerson(string name)
{
    int index = findIndex(name);

    if( index != 0)
    return findPerson(index);

    return NULL;
}


