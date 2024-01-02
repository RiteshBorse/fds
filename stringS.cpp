using namespace std;
class Stack{
  int capacity;
  char data[100];
  int top;
public:
  Stack()
  {
    capacity = 100;
    top = -1;
  }
  void push(char data)
{
  if(top == capacity-1)
  {
    cout<<"Stack Oveflow";
    return;
  }
  top++;
  this->data[top] = data;
  
}

  void pop()
{
 if(top == -1)
 {
   cout<<"Underflow";
   return;
 }
  top--;
}

char getTop()
{
  if(top == -1)
  {
    cout<<"Underflow";
    return 'x';
  }
  return data[top];
}
};