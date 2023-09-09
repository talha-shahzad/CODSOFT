#include<iostream>
#include<vector>
using namespace std;

class Book{
    string book_name;
    string author;
    string ISBN;

public:
    Book* next;
    bool avail_status;
    int res_days;
    Book():book_name(""),author(""),ISBN(""),next(NULL),avail_status(0),res_days(0)
    {}
    Book(string bn,string auth, string isbn,bool as):book_name(bn),author(auth),ISBN(isbn),avail_status(as),res_days(0)
    {}
    void setBook_name(string bn)
    {
        book_name=bn;
    }
    void setAuthor(string auth)
    {
        author=auth;
    }
    void setBook(string isbn)
    {
        ISBN=isbn;
    }
    string getBookName()
    {
        return book_name;
    }
    string getAuthor()
    {
        return author;
    }
    string getISBN()
    {
        return ISBN;
    }

};
class Library{
    Book* first;
public:
    Library()
    {
        first=NULL;
    }
  void InsertBook(Book* book)
  {
        book->next=NULL;
        if(first==NULL)
            first=book;
        else
        {
            Book* p=first;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=book;

        }

  }
  void Display()
  {
        Book* p=first;
        string av;

        while(p!=NULL) {
            if(p->avail_status==1)
                av="Book Avaialable";
            else
                av="Book Not Available";
            cout << "Book Name : " << p->getBookName() << "\t Author : " << p->getAuthor() << "\t ISBN : "
                 << p->getISBN()<<"\t Status : "<<av<< endl;
            p = p->next;
        }
  }
int SearchByName(string name)
{
        int count=0;
        Book* p=first;
        while(p!=NULL)
        {
            count++;
            if(name==p->getBookName()) {
                cout << "Book Found at Shelf : " << count << endl;
                return count;
            }
            p=p->next;
        }
        return 0;
}
    int SearchByAuthor(string name)
    {
        int count=0;
        Book* p=first;
        while(p!=NULL)
        {
            count++;
            if(name==p->getBookName()) {
                cout << "Book Found at Shelf : " << count << endl;
                return count;
            }
            p=p->next;

        }
        return 0;
    }
    int SearchByISBN(string name)
    {
        int count=0;
        Book* p=first;
        while(p!=NULL)
        {
            count++;
            if(name==p->getISBN()) {
                cout << "Book Found "<< endl;
                return count;
            }
            p=p->next;
        }
        return 0;
    }

    int UpdateAvail(int loc,int val)
    {
        Book* p=first;
        for(int i=0;i<loc-1;i++)
        {
            if(p!=NULL)
            p=p->next;
        }
        p->avail_status=val;
        int res;
        if(val==0) {
            cout << "how many days you want to take book" << endl;
            cin >> res;
            p->res_days = res;
        }else
        {
            cout<<"How many days you have that Book"<<endl;
            cin>>res;
            int ret=res-p->res_days;
            p->res_days=0;
            return ret;
        }
        return 0;
    }



};

int Search(Library& lib)
{
    int sop=0;string send;int ret=0;
    cout<<" Search Book By  "<<endl;
    cout<<"1. NAME "<<endl;
    cout<<"2. Author "<<endl;
    cout<<"3. ISBN "<<endl;
    cout<<"   Press the number "<<endl;
    cin>>sop;
    cin.ignore();
    cout<<"Please enter :"<<endl;
    getline(cin,send);
    if(sop==1)
       ret= lib.SearchByName(send);
    else if(sop==2)
        ret=lib.SearchByAuthor(send);
    else if(sop==3)
        ret=lib.SearchByISBN(send);
    else
        cout<<"Invalid Command"<<endl;

    return ret;
}

int main()
{
    Library lib;
    bool run=1;
    int opt=0;
    while(run) {

        cout << "-----------------______________ WELCOME _______________--------------" << endl;
        cout << "->>>>>>>>>------>>>>>>>>> LIBRARY MANAGEMENT SYSTEM <<<<<<<------<<<<<<<<<-" << endl;
        cout<<"1. Add a Book "<<endl;
        cout<<"2. Search Book "<<endl;
        cout<<"3. Checkout Book "<<endl;
        cout<<"4. CheckIn / Return Book "<<endl;
        cout<<"5. Display Books "<<endl;
        cout<<"      PRESS THE NUMBERS GIVEN TO PERFORM ANY TASK  "<<endl;
        cin>>opt;
        cin.ignore();
        if(opt==1){
            string bn,au,isbn;
            cout<<"Enter Book Name "<<endl;
            getline(cin,bn);

            cout<<"Enter Author Name "<<endl;
            getline(cin,au);

            cout<<"Enter ISBN "<<endl;
            getline(cin,isbn);
            Book* book=new Book(bn,au,isbn,1);
            lib.InsertBook(book);
        }
        else if(opt==2){
           int send= Search(lib);
            int getx;
            cout<<"Do you want to check in Press 1 for yes and vice versa"<<endl;
            cin>>getx;
            if(getx)
                lib.UpdateAvail(send,0);

        }
        else if(opt==3)
        {
            cout<<" CHECKING OUT PROCESS ......."<<endl;
            int send= Search(lib);
            lib.UpdateAvail(send,0);
        }
        else if(opt==4)
        {
            int fine=0;
        cout<<"Returning Book "<<endl;
        int send= Search(lib);
        int ds=lib.UpdateAvail(send,1);
        if(ds>0)
            for(int i=0;i<ds;i++)
                fine+=10;
        cout<<"you have Fine of "<<fine<<" Rupees due to late return"<<endl;
        }
        else if(opt==5)
        {
            cout<<" DISPLAYING ALL THE BOOKS ........."<<endl;
            lib.Display();
        }

        else{
            cout<<" INVALID COMMAND "<<endl;
        }


        cout<<"--->>> Press 1 if you want to continue else Press 0 <<<---"<<endl;
        cin>>run;
    }
    return 0;
}

