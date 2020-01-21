#include "PhoneBook.h"
#include <string>
using namespace std;
#include <iostream>
PhoneBook::PhoneBook()
{
    head = NULL;
    numberOfPeople = 0;
}
PhoneBook::~PhoneBook()
{
   Node * cur = head;
while( cur!= NULL)
{
    Node * temp = cur;
    delete temp;
    cur = cur->next;

}
head = NULL;
}
bool PhoneBook::addPerson(string name)
{
if(nameExist(name))
    return false;

Node * nNode = new Node;
nNode->t = Person(name);

Node * temp = head;
if(head == NULL)
{
  head = nNode;
}
else
{
while(temp->next != NULL)
{
    temp = temp->next;
}
temp->next = nNode;
}

return true;
}
bool PhoneBook::addPhone( string personName, int areaCode, int number )
{
if(!(nameExist(personName)))
{
    cout<<"No user with that name"<<endl;
    return false;
}

    Node * cur = findPerson(personName);
if(cur->t.phoneExist(areaCode,number))
{
    cout<<"User already has that phone"<<endl;
    return false;
}


    (cur->t).addPhone(areaCode,number);
    return true;
}
void PhoneBook::displayPeople()
{
        Node * cur = head;

    if( cur == NULL)
        return;

    while(cur!= NULL)
    {
        cout<<"Person "<< cur->t.getName() << " number of phones "<< cur->t.getName() << " has "<< cur->t.getPhoneNumber()<<endl;
        cur = cur ->next;
    }

}
void PhoneBook::displayPerson(string name)
{
    Node * cur = findPerson(name);
    if( cur == NULL)
    {
        cout<<"---EMPTY---"<<endl;
        return;
    }


    cout<< name<<endl;
    cur->t.displayPhoneNumbers();
}
void PhoneBook::displayAreaCode(int areaCode)
{
     Node * cur = head;

    if( cur == NULL)
        return;


    bool go = 0;

        while(cur!= NULL)
    {
       if( cur ->t.AreaExist(areaCode))
       {
         go = 1;
       }
       cur = cur->next;
    }
    if(go == 0)
        cout<<"---EMPTY---"<<endl;
    if( go == 1)
        cout<<"Area code "<< areaCode<<endl;

   Node * cur2 = head;

    while(cur2!= NULL)
    {
       cur2->t.displayArea(areaCode);
        cur2 = cur2 ->next;
    }

}
void PhoneBook::operator=(const PhoneBook& right)
{
    delete head;
    if(right.head == NULL)
        head = NULL;
    else
    {
        head = new Node;
        Node * cur = head;
        Node * cur2 = right.head;
        cur->t = right.head->t;
        while(cur2 != NULL)
        {
            cur->next = new Node;
            cur->next->t = cur2->next->t;
            cur = cur -> next;
            cur2 = cur2->next;
        }

    }
}
PhoneBook::Node * PhoneBook::findPerson( string name )
{
    Node * cur = head;
    if( cur == NULL)
        return NULL;

    while(cur!= NULL)
    {

        if((cur->t).getName() == name)
        {

            return cur;
        }
        cur = cur ->next;
    }
    return NULL;
}

bool PhoneBook::nameExist(string name)
{
 Node * cur = head;
    if( cur == NULL)
        return false;

    while(cur!= NULL)
    {

        if((cur->t).getName() == name)
        {

            return true;
        }
        cur = cur ->next;
    }
    return false;
}
bool PhoneBook::removePhone( string personName, int areaCode, int number )
{
    Node * cur = findPerson(personName);
    if(cur!= NULL)
    {
     cur->t.removePhone(areaCode,number);
     return true;
    }
    return false;
}

bool PhoneBook::removePerson(string name)
{
    if(!(nameExist(name)))
    {
        return false;
    }
    Node * cur2 = findPerson(name);
    if( cur2 == head)
    {
        Node * temp = head;
       temp->t.deleteList();
        head = head -> next;
        delete temp;

    }
    else{
        Node * prev = NULL;
        Node * cur = head;

         while(cur!= NULL)
            {

                if((cur->t).getName() == name)
                {

                    break;
                }
                prev = cur;
                cur = cur ->next;
            }
            prev->next = cur->next;
            cur->t.deleteList();
            delete cur;



    }
    return true;

}
