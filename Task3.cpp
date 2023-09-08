#include<iostream>
#include<iomanip>
using namespace std;

void Display(int* arr, int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<" ";
        if(arr[i]==0)
        cout<<'-';
        else if(arr[i]==1)
        cout<<"O";
        else
        cout<<"X";

        cout<<" ";
        if((i+1)%3==0)
        cout<<endl;
        else
        cout<<" | ";
    }
}

int Board_Checker(int* arr,int size)
{
    if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[0])
        return arr[0];
    if(arr[0]==arr[3] && arr[3]==arr[6] && arr[6]==arr[0])
        return arr[0];
    if(arr[6]==arr[7] && arr[7]==arr[8] && arr[8]==arr[6])
        return arr[6];
    if(arr[2]==arr[5] && arr[5]==arr[8] && arr[8]==arr[2])
        return arr[2];
    if(arr[1]==arr[4] && arr[4]==arr[7] && arr[7]==arr[1])
        return arr[1];
    if(arr[3]==arr[4] && arr[4]==arr[5] && arr[5]==arr[3])
        return arr[3];
    if(arr[0]==arr[4] && arr[4]==arr[8] && arr[8]==arr[0])
        return arr[0];
    if(arr[2]==arr[4] && arr[4]==arr[6] && arr[6]==arr[2])
        return arr[2];
    else
        return 0;

}

void user1(int* arr,int loc,int* c)
{
    arr[loc-1]=1;
    *c=*c+1;
}
void user2(int* arr,int loc,int *c)
{
    arr[loc-1]=2;
    *c=*c+1;
}


int main()
{
     int loc=0;
  int* locval = new int[9];
  for(int i=0;i<9;i++)
  locval[i]=0;
    cout<<"-----______________----- TIC TAC TOE -----___________-----"<<endl;
    cout<<"Game Starting...... "<<endl;

int* count=new int;
*count=0;
  Display(locval,9);
  int checker=0;
  while(checker<=0)
  {
      cout<<"enter number (1-9) : ";
      cin>>loc;
      user1(locval,loc,count);
      Display(locval,9);
      checker=Board_Checker(locval,9);
      if(checker>0 || *count>=9)
          break;
      cout<<"enter number : ";
      cin>>loc;
      user2(locval,loc,count);
      Display(locval,9);
      checker=Board_Checker(locval,9);

      if(checker>0 || *count>=9)
          break;

  }

 if(checker==1)
  {
      cout<<"CONGRATULATION PLAYER 1 WINS"<<endl;
  }
 else if(checker==2)
 {
        cout<<"CONGRATULATION PLAYER 2 WINS"<<endl;
 }
 else
     cout<<"ALAS!! Match is Drawn"<<endl;


}
