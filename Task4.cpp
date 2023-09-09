#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct node {
    string val;
    int status;
    node* next;
};
class list {

    node* first;
public:
    list()
    {
        first = NULL;
    }
    void insert(string topic, int st)
    {

        node* temp = new node;
       
            temp->val = topic;
        temp->status = st;
        temp->next = NULL;

        node* p = first;
        if (first == NULL)
        {

            first = temp;
        }
        else
        {
            while (p->next != NULL)
                p = p->next;

            p->next = temp;
        }

    }
    void Display()
    {
        node* p = first;
        while (p != NULL)
        {
            cout <<"ToDo : "<< p->val << "\t Status : " << p->status << endl;
            p = p->next;
        }

    }
    int Search(string top)
    {
     
        int count = 0;
        node* p = first;
        bool check;
       
        while(p!=NULL)
        {
            count++;

            if (p->val == top)
                return count;
            p = p->next;
        }
        return 0;
    }
    void update(int index, int val)
    {
        node* p = first;
	    for(int i=0;i<index-1;i++)
	    {
            if(p!=NULL)
            p = p->next;
	    }
        if(p!=NULL)
        p->status = val;
    }
    void remove(int index)
    {
        node* q = NULL;
        node* p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            if (p != NULL)
                p = p->next;
            
        }
        q->next = p->next;
        delete p;

    }
};


int main()
{
    list todo;

    bool run = true;
    while (run) {
        string topic;
        int opt = 0;
        cout << "----------->>>>> To Do Manager <<<<<--------------" << endl;
        cout << "1.Add some Task" << endl;
        cout << "2.View Task" << endl;
        cout << "3.Change task to Mark as done" << endl;
        cout << "4.Remove a Task" << endl;
        cout << "PRESS the given number to perform" << endl;
        cout << "-------------->>>>>>>      <<<<<<---------------------" << endl;
        cin >> opt;
        cin.ignore();

        if (opt == 1) {
            cout << "please enter the task name you want to ADD" << endl;
            getline(cin,topic);
 
            todo.insert(topic, 0);
        }
        else if (opt == 2) {
            cout << endl;
            cout << "-----______________----- TO DO LIST -----_____________----- " << endl;
            cout << endl;
            todo.Display();
            cout << "-----_____________-----______________-----____________-----" << endl;
        }
        else if (opt == 3) {
            int num;
            cout << "Enter the Topic of the Task" << endl;
            getline(cin, topic);
            cout << "Press 1 for Completed and 0 for Pending" << endl;
            cin >> num;

            int getx = 0;
           getx = todo.Search(topic);

           todo.update(getx,num);
        }
        else if (opt == 4) {
            topic = new char[100];
            cout << "Enter the name of Task you want to delete" << endl;
            getline(cin, topic);
            int getx = 0;
            getx = todo.Search(topic);
            todo.remove(getx);
        }
        else
            cout << "Invalid Number" << endl;

     
        cout << "press 1 if you want to continue or press 0 to stop" << endl;
        cin >> run;
    }

}
