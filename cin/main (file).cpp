#include <iostream>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

/*
#include <iostream>
#include <fstream>
#include <cstdlib>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

*/

COORD coord={0,0};
void gotoxy(int x , int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void add();
void reports();
//void trans();
void closeacc();
void edit();
int menu();

int pass=123;
int b=0;

struct movie
{
    int stat , tp , du , ses , sal;
    int id = std::stoi(std::to_string(sal) + std::to_string(ses));
    char name [21];
};

int main()
{
    int menuselection;
    system("cls");
    do
    {
        menuselection = menu();
        switch(menuselection)
        {
            case 1  : add ();                            break;
            case 2  : closeacc();                        break;
          //case 2  : trans();                           break;
            case 3  : edit();                            break;
            case 4  : reports();                         break;
            case 5  : cout<<endl<<endl<<endl;terminate();break;
            default : cout<<endl<<endl<<endl<<"Error! the entered number must be between 1 to 6.";
                      cout<<endl<<"Press any button to continue ..."; getch();  break;
        }
    }while(menuselection!=5);
    return 0;
}

int menu()
{
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::My cinema::::::::::::::::::::::::::File::::::"<<endl;
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
    int i=1  ;
    if(b==1)
        goto second;
    first: while( true )
    {
    cin>>temp;
    i++;
        if(temp==pass)
        {
            b=1;
            second : system("cls");
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::My cinema::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::::::Menu::::::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<"::::::        1. Add movie                   ::::::"<<endl;
            cout<<"::::::        2. Delete movie                ::::::"<<endl;
            cout<<"::::::        3. Edit movie ticket price     ::::::"<<endl;
            cout<<"::::::        4. Report info                 ::::::"<<endl;
            cout<<"::::::        5. terminate program           ::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<"::::::Please enter a number (from 1 to 5):   ::::::"<<endl;
            cout<<"::::::                                       ::::::"<<endl;
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            int s;
            gotoxy(43,14);
            cin>>s;
            cin.get();
            return s;
        }
        else
        {
            if(i==4)
            {   cout<<endl<<endl<<endl;
                terminate();
            }
            cout<<"::::::  wrong password! Try again : ";
            goto first;
        }
    }
}

void add ()
{
    system("cls");
    movie mov;
    fstream file;
    file.open("test.abc",ios::out | ios::in | ios::binary);
    if(!file)
    {
        file.open("test.abc",ios::out | ios::binary);
        if(!file)
            cout<<"error";
    }
    else
    {
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        cout<<"::::::My cinema::::::::::::::::::::::::::::::::::::"<<endl;
        cout<<":::::::::::::::::::::::Add:::::::::::::::::::::::::"<<endl;
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        cout<<"::::::                                       ::::::"<<endl;
        cout<<"::::::  Name               :                 ::::::"<<endl;
        cout<<"::::::  Ticket price (int) :                 ::::::"<<endl;
        cout<<"::::::  Duration (int)     :                 ::::::"<<endl;
        cout<<"::::::  Salon number (1-4) :                 ::::::"<<endl;
        cout<<"::::::  Session (1-3)      :                 ::::::"<<endl;
        cout<<"::::::                                       ::::::"<<endl;
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        gotoxy(29,5) ;
        cin>>mov.name;
        gotoxy(29,6) ;
        cin>>mov.tp  ;
        gotoxy(29,7) ;
        cin>>mov.du  ;
        sal:
        gotoxy(29,8) ;
        cin>>mov.sal ;
        if(mov.sal<1 || mov.sal>4)
        {
            gotoxy(0,13);
            cout<<"Error! Enter a number between 1 to 4.";
            goto sal;
        }
        ses:
        gotoxy(29,9) ;
        cin>>mov.ses ;
        if(mov.ses<1 || mov.ses>3)
        {
            gotoxy(0,13);
            cout<<"Error! Enter a number between 1 to 3.";
            goto ses;
        }
        mov.stat = 1 ;
        mov.id = std::stoi(std::to_string(mov.sal) + std::to_string(mov.ses));

        file.seekp(sizeof(struct movie)*mov.id,ios::beg);
        file.write((char*)&mov,sizeof(struct movie));
        cout<<endl<<endl<<endl<<"( "<<mov.name<<" ) with ( ID = "<<mov.id<<" ) added successfully !"<<endl<<"Press any button to continue  ...";
        getch();
        file.close();
    }
}

void edit()
{
    int id , newPrice , s = 0;
    char tran;
    movie mov;
    system("cls");
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::My cinema:::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::::::::::::::::::::::::Edit::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::                                                ::::::"<<endl;
    cout<<":::::: Enter account ID to change balance :           ::::::"<<endl;
    cout<<"::::::                                                ::::::"<<endl;
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    gotoxy(46,5);
    cin>>id;
    fstream file;
    file.open("test.abc", ios::in | ios::out | ios::binary);
    if(!file)
    {
        cout << "Error opening file..." << endl;
    }
    else
    {

        file.seekg(sizeof(struct movie) * id , ios::beg);
        file.read((char *)&mov , sizeof(struct movie));
        //system("cls");
        //cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        //cout<<"::::::My cinema::::::::::::::::::::::::::::::::::::"<<endl;
        //cout<<":::::::::::::::::::::::Edit::::::::::::::::::::::::"<<endl;
        //cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        cout<<endl<<endl;
        cout<<"::::::                                                ::::::"<<endl;
        cout<<":::::: Increase (I) or decrease (D) :                 ::::::"<<endl;
        cout<<"::::::                                                ::::::"<<endl;
        cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        gotoxy(40,9);
        cin>>tran;
        cout<<endl<<endl;
        cout<<"::::::                                                ::::::"<<endl;
        cout<<":::::: Enter a number as amount :                     ::::::"<<endl;
        cout<<"::::::                                                ::::::"<<endl;
        cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        gotoxy(38,13);
        cin>>newPrice;


       switch(tran)
       {
       case'I':
        mov.tp += newPrice;
        s=1;
        break;



       case'D':
        if (mov.tp<newPrice)
        {
            cout<<endl<<endl<<endl<<"Price is less than amount,can not change ticket price !";
        }
        else {
            mov.tp-=newPrice;
            s=1;
        }
        break;
        default: cout<<endl<<endl<<"error: please choose . . . . . . ";
       }
       if (s == 1)
       {
           file.seekg(sizeof(struct movie) *id , ios::beg);
        file.write((char *)&mov , sizeof(struct movie));
        cout<<endl<<endl<<endl<<"Ticket price successfully changed !";
       }
        cout<<endl<<"press any key to continue ...";
        getch();
       }

  /*else
    {
        int k,q;
        char v;
        cout<<"how do you want to edit the price?"<<endl;
        cout<<"1-single movie"<<endl;
        cout<<"2-all togheter"<<endl;
        cin>>k;
        if(k==1)
        {
            cout<<"1-change"<<endl;
            cout<<"2-increase or decrease by percent"<<endl;
            cin>>q;
            if(q==1)
            {
                file.seekg(sizeof(struct movie) *id , ios::beg);
                file.read((char*)&mov , sizeof(struct movie));
                cout << "Enter the movie ID to change ticket price :";
                cin >> id;
                cout << "Enter new ticket price : ";
                cin >> newPrice;
                mov.tp=newPrice;
                file.seekp(sizeof(struct movie) * id , ios::beg);
                file.write((char*)&mov , sizeof(struct movie));
                cout << "successfully done."<<endl;
                cout << "Press a key to continue ... "<< endl;
            }
            else if(q==2)
            {
                file.seekg(sizeof(struct movie) * id , ios::beg);
                file.read((char*)&mov , sizeof(struct movie));
                cout<<"press 'D' to decrease or 'I' to increase : ";
                cin>>v;
                if(v=='I')
                {
                    cout << "Enter the movie ID to increase ticket price :";
                    cin >> id;
                    cout << "Enter new ticket price : ";
                    cin >> newPrice;
                    mov.tp=((mov.tp/100)*newPrice)+mov.tp;
                    file.seekp(sizeof(struct movie) * id , ios::beg);
                    file.write((char*)&mov , sizeof(struct movie));
                    cout << "successfully done."<<endl;
                    cout << "Press a key to continue ... "<< endl;
                }
                else if(v=='D')
                {
                    cout << "Enter the movie ID to decrease ticket price :";
                    cin >> id;
                    cout << "Enter new ticket price : ";
                    cin >> newPrice;
                    mov.tp=((mov.tp/100)*newPrice)-mov.tp;
                    file.seekp(sizeof(struct movie) * id , ios::beg);
                    file.write((char*)&mov , sizeof(struct movie));
                    cout << "successfully done."<<endl;
                    cout << "Press a key to continue ... "<< endl;
                }
                else
                {
                    cout<<"enter 'D' or 'I'!";
                }
            }
            else
            {
                cout<<"enter '1' or '2'!";
            }

        }
        else if(k==2)
        {
            cout<<"how do you want to edit the price?"<<endl;
            cout<<"1-change"<<endl;
            cout<<"2-increase or decrease by percent"<<endl;
            cin>>q;
            if(q==1)
            {
                while(!file.eof())
                {
                    file.seekg(sizeof(struct movie) * id , ios::beg);
                    file.read((char*)&mov , sizeof(struct movie));
                    cout << "Enter new ticket price : ";
                    cin >> newPrice;
                    mov.tp=newPrice;
                    file.seekp(sizeof(struct movie) * id , ios::beg);
                    file.write((char*)&mov , sizeof(struct movie));
                    cout << "successfully done."<<endl;
                    cout << "Press a key to continue ... "<< endl;
                }
            }
            else if(q==2)
            {
                while(!file.eof())
                {
                file.seekg(sizeof(struct movie) * id , ios::beg);
                file.read((char*)&mov , sizeof(struct movie));
                cout<<"press 'D' to decrease or 'I' to increase : ";
                cin>>v;
                if(v=='I')
                {
                    cout << "Enter new ticket price : ";
                    cin >> newPrice;
                    mov.tp=((mov.tp/100)*newPrice)+mov.tp;
                    file.seekp(sizeof(struct movie) * id , ios::beg);
                    file.write((char*)&mov , sizeof(struct movie));
                    cout << "successfully done."<<endl;
                    cout << "Press a key to continue ... "<< endl;
                }
                else if(v=='D')
                {
                    cout << "Enter new ticket price : ";
                    cin >> newPrice;
                    mov.tp=((mov.tp/100)*newPrice)-mov.tp;
                    file.seekp(sizeof(struct movie) * id , ios::beg);
                    file.write((char*)&mov , sizeof(struct movie));
                    cout << "successfully done."<<endl;
                    cout << "Press a key to continue ... "<< endl;
                }
                else
                {
                    cout<<"enter 'D' or 'I'!";
                }
                }
            }
            else
            {
                cout<<"enter '1' or '2'!";
            }
        }
        else
        {
            cout<<" 1. enter '1' or '2'!";
        }
    }*/
    getch();
    file.close();
}

void reports()
{
    system("cls");
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::My cinema:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::Reports::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::                                                                              ::::::"<<endl;
    cout<<":::::: ID  .  Name                .  Ticket price  .  Length  .  Salon  .  Session  ::::::"<<endl;
    cout<<"::::::                                                                              ::::::"<<endl;
    fstream file;
    file.open("test.abc" , ios::in | ios::binary);
    if(!file)
        cout<<"error2"<<endl;
    else
    {
        movie mov;
        int row = 7;
        int h=0;
        while(file.read((char*)&mov ,sizeof(struct movie)))
        {
            if(mov.stat==1)
            {
                h=1;
                cout<<endl<<":::::: ";
                gotoxy(0,row);
                cout<<":::::: ";
                gotoxy(7,row);
                cout<<mov.id;
                gotoxy(14,row);
                cout<<mov.name;
                gotoxy(37,row);
                cout<<mov.tp;
                gotoxy(54,row);
                cout<<mov.du;
                gotoxy(65,row);
                cout<<mov.sal;
                gotoxy(75,row);
                cout<<mov.ses;
                gotoxy(82,row);
                cout<<"  ::::::";
                row++;
            }
          /*if(mov.stat==0 && h==0)
            {
                system("cls");
                cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
                cout<<"::::::Reports::::::::::::::::::::::::::::::::::::::"<<endl;
                cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
                cout<<"::::::                                       ::::::"<<endl;
                cout<<"::::::  There is't any movie reports yet!    ::::::"<<endl;
                cout<<"::::::                                       ::::::"<<endl;
                cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
                goto noRep;
            }*/
        }
        cout<<endl<<"::::::                                                                              ::::::"<<endl;
        cout      <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        //noRep:
        cout<<endl<<"Press any button to continue ...";
        file.close();
        getch();
    }
}

void closeacc()
{
    system("cls");
    int accID;
    movie mov;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::My cinema::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::Delete movie::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<"::::::  Enter movie ID :                     ::::::"<<endl;
    cout<<"::::::                                       ::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    gotoxy(25,5);
    cin>>accID;
    cout<<endl<<endl;
    fstream file;
    file.open("test.abc" , ios::out | ios::in | ios::binary);
    if(!file)
        cout<<"Error opening file !"<<endl;
    else
    {
        file.seekg(sizeof(struct movie)*accID , ios::beg);
        file.read((char*)&mov ,sizeof(struct movie));
        if(mov.stat==1)
            {
            mov.stat=0;
            file.seekp(sizeof(struct movie)*accID , ios::beg);
            file.write((char*)&mov ,sizeof(struct movie));
            cout<<endl<<"Movie ( "<<mov.name<<" ) deleted successfully !"<<endl<<"Press any button to continue ...";
            getch();
            }
        else
        {
            cout<<endl<<"Movie with ID ( "<<accID<<" ) does not exist !"<<endl<<"Press any button to continue ...";;
            getch();
        }
        file.close();
    }
}
