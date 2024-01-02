//The Code is Incomplete
#include <iostream>
using namespace std;

int main() {
//array for competition
  int coding[100],project[100],paper[100],master[100];
  //var to append above arrays 
  int a=0,b=0,c=0,d=0;
  
  int op;
  int num,roll,comp;
   cout<<"Enter the number of students"<<endl;
    cin>>num;
  for(int i =0;i<num;i++)
    {
      cout<<"Enter the Roll NO of stud"<<endl;
      cin>>roll;
      cout<<"NO of competiton participated"<<endl;
      cin>>comp;
      for(int i =0;i<comp;i++)
        {
          cout<<"Choose a Competition 1.Coding 2.Project 3.PaperPres 4.MasterMind"<<endl;
          cin>>op;
          switch(op)
            {
              case 1: coding[a] = roll;
                      a++;
                      break;
              case 2: project[b] = roll;
                      b++;
                      break;
              case 3: paper[c] = roll;
                    c++;
                      break;
              case 4: master[d] = roll;
                    d++;
              break;
            }
        }
    }

 

  
  //participated in coding and project
  for(int i = 0; i<a ;i++)
    {
      for(int j =0; j<b;j++)
        {
          if(coding[i] == project[j])
          {
            cout<<" "<<coding[i];
          }
        }
    }

    //student participated in coding
    cout<<"Students participated in coding"<<endl;
    for(int i =0;i<a;i++)
      {
        cout<<" "<<coding[i];
      }

  //students participated in project
  cout<<"Students participated in project"<<endl;
  for(int i =0;i<b;i++)
    {
      cout<<" "<<project[i];
    }

  //students paritcipated in coding but not in mastermind
  for(int i =0; i<num;i++)
    {
      for(int j =0; j<num;j++)
        {
          if(coding[i] == master[j])
          {
            continue;
          }
          else{
            cout<<coding[i]<<" ";
          }
        }
    }
    return 0;
}