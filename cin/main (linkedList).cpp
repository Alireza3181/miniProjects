#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>

COORD coord= {0,0};
void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
using namespace std;

int pass=123; // پسورد
int b=0;      // متغیر کمکی برای کنترل نمایش صفحه ورود

int Menu(int choise);

class Movie
{
     friend class LinkList;
     int tp , du , ses , sal;
     int id = std::stoi(std::to_string(sal) + std::to_string(ses)); // سازنده آیدی برای فیلم بوسیله عدد سالن و سانس نماش فیلم
     char name [21];
     Movie *next;
};

class LinkList
{
 public:
    LinkList();
    ~LinkList();
    void addNode();
    void deleteNode(int no);
    void display();
 private:
    Movie *first;
    Movie *last;
 };

LinkList::LinkList()    // تابع سازنده
{
     first = last = NULL;
 }

LinkList::~LinkList()    // تابع مخرب
{
    Movie *curPtr = first;
    Movie *temp;
    while(curPtr)
    {
        temp = curPtr;
        delete temp;
        curPtr = curPtr->next;
    }
}

void LinkList::addNode()    // افزودن گره
{
    system("cls");
    Movie *newPtr = new Movie();
    if(!newPtr)
    {
    cout<<"failed allocation !";
    }
    newPtr->next = NULL;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::My cinema::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::Menu::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<"::::::  Name               :                 ::::::"<<endl;
    cout<<"::::::  Ticket price       :                 ::::::"<<endl;
    cout<<"::::::  Length (minutes)   :                 ::::::"<<endl;
    cout<<"::::::  Salon number (1-4) :                 ::::::"<<endl;
    cout<<"::::::  Session (1-3)      :                 ::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    gotoxy(29,5) ;
    cin>>newPtr->name;
    gotoxy(29,6) ;
    cin>>newPtr->tp  ;
    gotoxy(29,7) ;
    cin>>newPtr->du  ;
    sal:
    gotoxy(29,8) ;
    cin>>newPtr->sal ;
    if(newPtr->sal<1 || newPtr->sal>4)  // فرض گرفته شده که سینمای ما 4 سالن نمایش دارد
    {
        gotoxy(0,13);
        cout<<"Error! Enter a number between 1 to 4.";
        goto sal;
    }
    ses:
    gotoxy(29,9) ;
    cin>>newPtr->ses ;
    if(newPtr->ses<1 || newPtr->ses>3)  // فرض گرفته شده که سینمای ما در 3 نوبت فیلم نمایش میدهد
    {
        gotoxy(0,13);
        cout<<"Error! Enter a number between 1 to 3.";
        goto ses;
    }
    newPtr->id = std::stoi(std::to_string(newPtr->sal) + std::to_string(newPtr->ses));
    cout<<endl<<endl<<endl<<"( "<<newPtr->name<<" ) with ( ID = "<<newPtr->id<<" ) added successfully !"<<endl<<"Press any button to continue  ...";
    if(first == NULL) // اگر گره اول باشد
    {
        first = last = newPtr;
    }
    else // اگر گره اول نباشد
    {
        last->next = newPtr;
        last = newPtr;
    }
    getch();
}

void LinkList::deleteNode(int no)   // حذف گره
{
    Movie *curPtr = first , *nextPtr = first;
    while(nextPtr)
    {
        if(no == nextPtr->id)
        {
            if(nextPtr == first)
            {
                first = first->next;
                delete nextPtr;
                break;
            }
            else{
                if(nextPtr == last)
                {
                    last = curPtr;
                }
                curPtr->next = nextPtr->next;
                delete nextPtr;
                break;
            }
        }
        else {
            curPtr = nextPtr;
            nextPtr = nextPtr->next;
        }
    }

}

void LinkList::display()    // نمایش اطلاعات
{
   system("cls");
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::My cinema:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::Reports::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::                                                                              ::::::"<<endl;
    cout<<":::::: ID  .  Name                .  Ticket price  .  Length  .  Salon  .  Session  ::::::"<<endl;
    cout<<"::::::                                                                              ::::::"<<endl;
    int row = 7;
    Movie *curPtr = first;
    while(curPtr)
    {
        cout<<endl<<":::::: ";
        gotoxy(0,row);
        cout<<":::::: ";
        gotoxy(7,row);
        cout<<curPtr->id;
        gotoxy(14,row);
        cout<<curPtr->name;
        gotoxy(37,row);
        cout<<curPtr->tp;
        gotoxy(54,row);
        cout<<curPtr->du;
        gotoxy(65,row);
        cout<<curPtr->sal;
        gotoxy(75,row);
        cout<<curPtr->ses;
        gotoxy(82,row);
        cout<<"  ::::::";
        row++;
        // برو ب گره بعدی
        curPtr = curPtr->next;
    }
    cout<<endl<<"::::::                                                                              ::::::"<<endl;
    cout      <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<endl<<"Press any button to continue ...";
    getch();
}

int menu(int choice)    // منو
{
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::My cinema:::::::::::::::::::Linked list::::::"<<endl;
    cout<<"::::::::::::::::::::::Login::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<"::::::  Please enter the password :          ::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    gotoxy(36,5);
    int temp ;
    int i=1  ;  // تعداد دفعات ورود پسورد توسط کاربر
    if(b==1)    // اگر حداقل یک بار پسورد درست وارد شود دیگر صفحه ورود با فراخوانده شدن تابع منو نمایش داده نمیشود
        goto second;
    first: while( true )
    {
        cin>>temp;  // ورود پسورد توسط کاربر
        i++;        // با هر بار ورود پسورد توسط کاربر .اضافه میشود
        if(temp==pass)
        {
            b=1;
            second : system("cls");
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::My cinema::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::::::Menu::::::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<"::::::           1. Add movie                ::::::"<<endl;
            cout<<"::::::           2. Delete movie             ::::::"<<endl;
            cout<<"::::::           3. Report info              ::::::"<<endl;
            cout<<"::::::           4. terminate program        ::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<"::::::Please enter a number (from 1 to 4):   ::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            int s;
            gotoxy(43,13);
            cin>>s;
            cin.get();
            return s;
        }
        else
        {
            if(i==4)  // اگر پسورد 3 بار اشتباه وارد شود تابع ترمینیت فراخوانی میشود
            {   cout<<endl<<endl<<endl;
                terminate();
            }
            cout<<"::::::  wrong password! Try again : ";
            goto first;
        }
     }
  }

int main()
{
    system("color 0D");
    int id , choice;
    LinkList testlist;
    do
    {
        system("cls");
        choice = menu(choice);
        if (choice == 1)
        {
            testlist.addNode();
        }
        else if(choice == 2)
        {
            system("cls");
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::My cinema::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::Delete movie::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<"::::::  Enter movie ID :                     ::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            gotoxy(25,5);
            cin>>id;
            testlist.deleteNode(id);
            cout<<endl<<endl<<endl<<"Movie ( "<<id<<" ) deleted successfully !"<<endl<<"Press any button to continue ...";
            getch();
        }
        else if(choice == 3)
        {
            testlist.display();
        }
        else if(choice == 4)
        {
            cout<<endl<<endl<<endl;terminate();
        }
    }while (choice != 4);
    return 0;
}
