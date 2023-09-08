#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
   double num1=0,num2=0;
   char operation;
   cout<<"------_________------ CACULATOR STATRTING ------________------"<<endl;
   cout<<"Enter any two numbers"<<endl;
   cin>>num1>>num2;
   cout<<"Enter the operation you want to perform"<<endl;
   cin>>operation;
   double result=0;
   switch(operation)
   {
       case '+':
       result=num1+num2;
       break;
       case '-':
       result=num1-num2;
       break;
       case '*':
       result=num1*num2;
       break;
       case '/':
       result=num1/num2;
       break;
       
   }
   cout<<"-------------------------------------"<<endl;
   cout<<"|"<<setw(25)<<"your result is : "<<result<<setw(10)<<"|"<<endl;;
   cout<<"-------------------------------------"<<endl;
   cout<<"----_________---- CALCULATOR CLOSING ----_________----"<<endl;
    return 0;
}
