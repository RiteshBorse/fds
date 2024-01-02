#include<iostream>
#include<ctime>
#include <iomanip>
using namespace std;
static string name , birthdate,d;
class Node
{
public:
  string name;
  string birthdate;
  Node *next;
  Node(string name, string birthdate)
  {
    this->name = name;
    this->birthdate = birthdate;
  }
};

class linkedlist{
public:
  Node *head = NULL;
  Node *tail = NULL;
  void create(string name,string birthdate);
  void display();
  void remove(string name);
  void wish();
};

void linkedlist::create(string name,string birthdate)
{
  Node *temp = new Node(name,birthdate);
  if(head == NULL)
  {
    head = temp;
  }
  else{
    tail->next = temp;
  }
  tail = temp;
}
void linkedlist::display()
{
  int count = 1;
  Node *temp = head;
   while(temp != NULL) 
     {
       cout<<count<< " " << "Name : "<<temp->name<<" "<<"Birthdate : "<<temp->birthdate<<endl;
       temp = temp->next;
       count++;
     }
}
void linkedlist::remove(string name)
{
  Node *temp = head;
  if(temp == NULL)
  {
    cout<<"Linkedlist is empty"<<endl;
  }
  if(head->name == name)
  {
    Node *d = head;
    head = head->next;
    delete d;
    return;
  }
  while(temp->next->name != name && temp->next != NULL)
    {
      temp = temp->next;
    }
  if(temp->next != NULL)
  {
    Node *d = temp->next;
    temp->next = temp->next->next;
    delete d;
  }
}
void linkedlist::wish()
{
  int flag = 0;
  Node *temp = head;
  while(temp != NULL)
    {
      if(temp->birthdate.substr(0,4) == d.substr(0,4))
      {
        cout<<"Happy Birthday"<<temp->name;
        flag = 1;
      }
      temp= temp->next;
  
    }
  if(flag == 0)
  {
    cout<<"No Birthdays today"<<endl;
  }
}
void insert()
{
  cout<<"Enter name"<<endl;
  cin>>name;
  cout<<"Enter birthdate"<<endl;
  cin>>birthdate;
}
int main()
{
  time_t ct = time(0);
  tm* timeInfo= localtime(&ct);
  stringstream bdate;
  bdate << put_time(timeInfo, "%d/%m");
  string date = bdate.str();
  cout<<date;
  d = date;
  
    char ch;
  int op;
  linkedlist l;
  do{
  cout<<"Choose Operation\n1.Insert Name and Birthday\n2.Display All\n3.Delete\n4.Wish"<<endl;
  cin>>op;
  switch(op)
    {
      case 1 : insert();
               l.create(name, birthdate);
                break;
      case 2 : l.display();
                break;
      case 3 : cout<<"Enter the name to be deleted"<<endl;
                cin>>name;
              l.remove(name);
                break;
      case 4 : l.wish();
      default: break;
              
    }
    cout<<"Do you want to continue"<<endl;
    cin>>ch;
  }while(ch == 'y' || ch == 'Y');
  
  return 0;
}