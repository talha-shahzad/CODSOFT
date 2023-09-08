#include<iostream>
using namespace std;
int main()
{
    int number=0,range=0,guess=0;
    srand(time(0));
    cout<<"----______----  WELCOME TO NUMBER GUESSER ----______----"<<endl;
    cout<<"Please select the range starting from 0"<<endl;
    cin>>range;
    number=rand()%range;
    cout<<"please guess the number"<<endl;
    cin>>guess;
    while(guess!=number)
    {
        if(guess>number)
        cout<<"Too High "<<endl;
        else if(guess<number)
        cout<<"Too Low"<<endl;
        else
        break;
        cout<<"please Guess the number"<<endl;
        cin>>guess;
    }
    cout<<"CONGRATULATIONS!! YOU GUESSED THE NUMBER"<<endl;
    return 0;
}
