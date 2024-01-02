#include<iostream>
#include<random>
#include<time.h>
using namespace std;
static int arr[100][100];
bool check(int m, int n)
{
  for(int i = 0; i<m ;i++)
    {
      for(int j = 0; j<n; j++)
        {
          if(arr[i][j] != 1)
          {
            return true;
          }
        }
    }
  return false;
}
int main()
{
  srand(time(0));
  int count = 0;
  int m,n;
  cout<<"Enter the rows and columns"<<endl;
  cin>>m>>n;
  //make every element 0
  for(int i = 0; i<m; i++)
    {
      for(int j = 0; j<n; j++)
        {
          arr[i][j] = 0;
        }
    }

  //center of array
  int center_x = m/2;
  int center_y = n/2;
  arr[center_x][center_y] = 1;
  while(check(m,n))
    {
      int x = center_x;
      int y = center_y;
      int min = 1 ,max = 8;
      int range = max - min + 1;
      int num = rand() % range + min;
      switch(num)
        {
          case 1 : x--,y--;
                  break;
          case 2 : y--;
                  break;
          case 3 : x++,y--;
                  break;
          case 4 : x--;
                  break;
          case 5 : x++;
                  break;
          case 6 : x--,y++;
                  break;
          case 7 : y++;
                  break;
          case 8 :x++,y++; 
                  break;  
        }
      if(x<0 || y<0 || y>(m-1) || x>(n-1))
      {
        continue;
      }
      arr[x][y] = 1;
      center_x = x;
      center_y = y;
      cout <<x<<" "<<y<<endl;
      count++;
    }
  cout<<"The total moves made are "<<count<<endl;
  
  return 0;
}