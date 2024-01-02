//Spare Matrix Operations

#include <iostream>
#include <iomanip>
using namespace std;
static int mat1[100][100], mat2[100][100], result[100][100];
//Case 1 
void getdata()
{
  //Taking input for matrix 1
  cout<<"Spare Matrix 1"<<endl;
  cout<<"Enter the number of rows,col,values"<<endl;
  cin>>mat1[0][0]>>mat1[0][1]>>mat1[0][2];
  cout<<"Enter the Spare Matrix"<<endl;
  cout<<"Row"<<setw(5)<<"Col"<<setw(5)<<"Val"<<endl;
  for(int i=1;i<=mat1[0][2];i++)
    {
       cin>>mat1[i][0]>>mat1[i][1]>>mat1[i][2];
    }
  //Taking input for matrix 2
  cout<<"Spare Matrix 2"<<endl;
  cout<<"Enter the number of rows,col,values"<<endl;
  cin>>mat2[0][0]>>mat2[0][1]>>mat2[0][2];
  cout<<"Enter the Spare Matrix"<<endl;
  cout<<"Row"<<setw(5)<<"Col"<<setw(5)<<"Val"<<endl;
  for(int i=1;i<=mat2[0][2];i++)
    {
       cin>>mat2[i][0]>>mat2[i][1]>>mat2[i][2];
    }
 
}
//Case 2
void display()
{  
  //Display matrix 1
  cout<<"Spare Matrix 1"<<endl;
  cout<<"Row"<<setw(5)<<"Col"<<setw(5)<<"Val"<<endl;
  for(int i = 0;i<=mat1[0][2];i++)
    {
      cout<<mat1[i][0]<<setw(5)<<mat1[i][1]<<setw(5)<<mat1[i][2]<<endl;
    }
  //Display matrix 2
  cout<<"Spare Matrix 2"<<endl;
  cout<<"Row"<<setw(5)<<"Col"<<setw(5)<<"Val"<<endl;
  for(int i = 0;i<=mat2[0][2];i++)
    {
      cout<<mat2[i][0]<<setw(5)<<mat2[i][1]<<setw(5)<<mat2[i][2]<<endl;
    }
}
//Case 3
void addition()
{
  int i,j,k,m,n;
  i=1,j=1,k=1;
  result[0][0] = mat1[0][0];
  result[0][1] = mat1[0][1];
  m = mat1[0][2];
  n = mat2[0][2];

  while(i<=m && j<=n)
    {
      if(mat1[i][0] == mat2[j][0])
      {
        if(mat1[i][1] == mat2[j][1])
        {
          result[k][0] = mat1[i][0];
          result[k][1] = mat1[i][1];
          result[k][2] = mat1[i][2] + mat2[j][2];
          i++;
          j++;
          k++;
        }
        else if(mat1[i][1] > mat2[j][1]){
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
            k++;
          }
          else if(mat1[i][1] < mat2[j][1]) {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
            k++;
          }
        }
      else if(mat1[i][0]>mat2[j][0])
      {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++;
        k++;
      }
      else if(mat1[i][0]<mat2[j][0])
      {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
        
      }
      }
  while(i<=m)
    {
      result[k][0] = mat1[i][0];
       result[k][1] = mat1[i][1];
       result[k][2] = mat1[i][2];
      i++;
      k++;
    }
  while(j<=n)
    {
      result[k][0] = mat2[j][0];
      result[k][1] = mat2[j][1];
      result[k][2] = mat2[j][2];
      j++;
      k++;
    }
  result[0][2] = k-1;

  //Display the addition
  cout<<"Row"<<setw(5)<<"Col"<<setw(5)<<"Val"<<endl;
  for(int i = 0;i<=result[0][2];i++)
    {
      cout<<result[i][0]<<setw(5)<<result[i][1]<<setw(5)<<result[i][2]<<endl;
    } 
}
int main() {
  char ch;
  int op;
  
 do{
   cout<<"Enter the operation"<<endl;
   cout<<"1.Input of Matrix\n2.Display Matrix\n3.Addition"<<endl;
   cin>>op;
   switch(op)
     {
       case 1: getdata();
              break;
       case 2: display();
              break;
       case 3: addition();
              break; 
     }
   cout<<"Do you want to continue"<<endl;
   cin>>ch;
 }while(ch == 'y' || ch == 'Y');
  return 0;
}