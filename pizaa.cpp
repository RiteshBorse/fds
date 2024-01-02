using namespace std;
class queue{
  int *arr;
  int size;
  int front,rear;
public:
  queue(int s)
{
  arr = new int[s];
  size = s;
  front = -1;
  rear = -1;
}
 void add(int data)
{
  if(rear == size-1)
  {
    cout<<"Pizza Counter is Full"<<endl;
    return;
  }
  else if(front == -1 && rear == -1)
  {
    cout<<"Pizza Ordered "<<data<<endl;
    front = rear = 0;
  }
  else
  {
    cout<<"Pizza Ordered " <<data<<endl;
    rear++;
  }
  arr[rear] = data;
}

void dequeue()
{
  if(rear == -1 && front == -1)
  {
    cout<<"No Pizza Ordered Yet"<<endl;
    return;
  }
  else if(front == rear)
  {
    front = rear = -1;
  }
  else{
    front++;
  }
}

int top()
{
  if(front == -1 && rear == -1)
  {
    cout<<"No Pizza Ordered"<<endl;
    return -999;
  }
  cout<<"Pizza Served : ";
  return arr[front];
}
};