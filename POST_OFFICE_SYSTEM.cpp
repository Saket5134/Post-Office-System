 /* All Header File */
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
#include<fstream>
#include<unistd.h>
#include<regex>

using namespace std;

/* Some Global Variable */
int x,n,z=0;

/* Class Declaration */
class Post_Office
{
    int user_no,weight,amount;
    float price;
    char name[20],country[20],state[20],cd[40],email[50],address[50],contact_no[15],pc[10],ch;
    char pswd[20],to_pc[20],to_cd[20],to_state[20],to_country[20],item[20],date[15];
    char to_address[20],po_name[20],to_name[20];
    fstream file;
public:
    void user_reg();
    void user_login();
    void admin_login();
    void user_menu();
    void admin_menu();
    void User_Update();
    void Delete_User();
    void Users_Display();
    void Search_User();
    void Speed_Post();
    void Domestic();
    void International();
    void Letter();
    void Letter_Domestic();
    void Letter_International();
    void Parcel();
    void Parcel_Domestic();
    void Parcel_International();
    void Money_Order();
    void Courier();
    int get_userno();
    char* get_user_name();
    char* get_user_password();
} p;

//Return User Name And Password
char* Post_Office::get_user_name()
{
    return name;
}

char* Post_Office::get_user_password()
{
    return pswd;
}

/* User Registration */
void Post_Office::user_reg()
{
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t=============================";
    cout<<"\n\t\t\t\t\t\t\t\t|| || USER REGISTRATION || ||";
    cout<<"\n\t\t\t\t\t\t\t\t=============================";
    cout<<endl;

    user_no = z + 1;

    int flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your Name :- ";
        fflush(stdin);
        gets(name);
        int l=strlen(name);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; name[i]!=NULL; i++)
            {
                if(isalpha(name[i]))
                    alpha++;
                else if(name[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tAlphabets Only.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your Address :- ";
        gets(address);
        if(strlen(address)>1)
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your Country :- ";
        gets(country);
        int l=strlen(country);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; country[i]!=NULL; i++)
            {
                if(isalpha(country[i]))
                    alpha++;
                else if(country[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tAlphabets Only.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your State :- ";
        gets(state);
        int l=strlen(state);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; state[i]!=NULL; i++)
            {
                if(isalpha(state[i]))
                    alpha++;
                else if(state[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tAlphabets Only.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your City / District :- ";
        gets(cd);
        int l=strlen(cd);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; cd[i]!=NULL; i++)
            {
                if(isalpha(cd[i]))
                    alpha++;
                else if(cd[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tAlphabets Only.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your Pincode :- ";
        gets(pc);
        const regex pattern("^[1-9]{1}[0-9]{2}\\s{0,1}[0-9]{3}$");
        if(regex_match(pc, pattern))
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tEnter Valid Pincode......\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your E-Mail :- ";
        gets(email);
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        if(regex_match(email, pattern))
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tEnter Valid Email\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your Mobile Number (+91) :- ";
        gets(contact_no);
        const regex pattern("(0|91)?[6-9][0-9]{9}");
        if(regex_match(contact_no, pattern))
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tEnter Valid Mobile Number......\n";
    }
    while(flag!=1);

    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your Password :- ";
        for(int i=0; i<=10; i++)
        {
            pswd[i] = getch();
            cout<< "*";
            if(pswd[i]==13)
            {
                pswd[i] = '\0';
                break;
            }
        }
        if(strlen(pswd)>=5 && strlen(pswd)<= 10)
            flag = 1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    cout<<"\n\n\t\t\t\t\t\t\t\t############## USER REGISTERED SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t==========================================================\n";
}

/* User Login*/
void Post_Office::user_login()
{
    system("cls");
    char a='y';
    int pos,choice;
    x=0,n;
    char u_nm[20];
    char u_pass[20];

    cout<<"\n\n\t\t\t\t\t\t\t\t======================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || USER LOGIN || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t======================";
    cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Your Name :- ";
    fflush(stdin);
    gets(u_nm);
    cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Password :- ";
    for(int i=0; i<=10; i++)
    {
        u_pass[i] = getch();
        cout<< "*";
        if(u_pass[i]==13)
        {
            u_pass[i] = '\0';
            break;
        }
    }

    ifstream file("pos.txt");
    while(file.read((char*)&p,sizeof(p)))
    {
        if(strcmp(get_user_name(),u_nm)==0 && strcmp(get_user_password(),u_pass)==0)
        {
            x=1;
            break;
        }
    }
    if(x==1)
    {
        while(a=='y')
        {
            system("cls");
            p.user_menu();
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
            cin>>choice;

            if(choice==1)
            {
                system("cls");
                p.Speed_Post();
            }
            else if(choice == 2)
            {
                system("cls");
                p.Letter();
            }
            else if(choice == 3)
            {
                system("cls");
                p.Parcel();
            }
            else if(choice == 4)
            {
                system("cls");
                p.Money_Order();
            }
            if(choice == 5)
                exit(0);
            cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go Main Menu (y/n) :- ";
            cin>>a;

        }
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t############# USER LOGIN FAILED #############";
        cout<<"\n\n\t\t\t\t\t\t\t\t=============================================";
    }
    file.close();
}

//For Domestic Purpose
void Post_Office::Domestic()
{
    cout<<"\n\n\t\t\t\t\t\t\t\t====================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || DOMESTIC || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t====================";

    int flag=0;

    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's Pincode :- ";
        fflush(stdin);
        gets(to_pc);
        const regex pattern("^[1-9]{1}[0-9]{2}\\s{0,1}[0-9]{3}$");
        if(regex_match(to_pc, pattern))
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's City / District :- ";
        fflush(stdin);
        gets(to_cd);
        int l=strlen(to_cd);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_cd[i]!=NULL; i++)
            {
                if(isalpha(to_cd[i]))
                    alpha++;
                else if(to_cd[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your State :- ";
        fflush(stdin);
        gets(state);
        int l=strlen(state);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; state[i]!=NULL; i++)
            {
                if(isalpha(state[i]))
                    alpha++;
                else if(state[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Type Of Document You Want To Send  :- ";
        fflush(stdin);
        gets(item);
        int l=strlen(item);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; item[i]!=NULL; i++)
            {
                if(isalpha(item[i]))
                    alpha++;
                else if(item[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        flag=1;
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter The Weight Of Document(in gms) :- ";
        while(!(cin>>weight))
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Correct Weight :- ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    while(flag!=1);
    //Price Calculation For Speed Post
    if(weight>0 && weight<=50)
    {
        price=(35*18)/100;
        price+=35;
    }
    else if(weight>51 && weight<=200)
    {
        price=(40*18)/100;
        price+=40;
    }
    else if(weight>201 && weight<=500)
    {
        price=(60*18)/100;
        price+=60;
    }
    else if(weight>501 && weight<=1000)
    {
        price=(90*18)/100;
        price+=90;
    }
    else if(weight>1001 && weight<=1500)
    {
        price=(120*18)/100;
        price+=120;
    }
    else if(weight>1501 && weight<=2000)
    {
        price=(150*18)/100;
        price+=150;
    }
    else if(price>=2000 && price<=100000)
    {
        price=(price/100)*5;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;

    }
    else
    {
        price=(price/100)*5;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;
    }

    cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price (Postage Amt.+GST) :- "<<price<<" INR"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t############## SPEED POST SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t=====================================================\n";

}

//For International Purpose
void Post_Office::International()
{
    cout<<"\n\n\t\t\t\t\t\t\t\t=========================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || INTERNATIONAL || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t=========================";

    int flag=0;

    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's Country :- ";
        fflush(stdin);
        gets(to_country);
        int l=strlen(to_country);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_country[i]!=NULL; i++)
            {
                if(isalpha(to_country[i]))
                    alpha++;
                else if(to_country[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Type Of Document You Want To Send  :- ";
        gets(item);
        int l=strlen(item);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; item[i]!=NULL; i++)
            {
                if(isalpha(item[i]))
                    alpha++;
                else if(item[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;

        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        flag=1;
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter The Weight Of Document(in gms) :- ";
        while(!(cin>>weight))
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Correct Weight :- ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    while(flag!=1);
    //Price Calculation
    if(strcmp(to_country,"USA")==0 || strcmp(to_country,"usa")==0 || strcmp(to_country,"Usa")==0)
    {
        if(weight>0 && weight<250)
            price=1550+(1550/100)*18;
        else
            price=1700+(1700/100)*18;
    }
    else if(price>=2000 && price<=100000)
    {
        price=(price/100)*5;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;
    }
    else if(price>100000)
    {
        price=(price/100)*10;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;
    }
    else
        cout<<"\n\n\t\t\t\t\t\t\t\tThis Country Is Not In Post Office List"<<endl;

    cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price (Postage Amt.+GST) :- "<<price<<" INR"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t############## SPEED POST SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t=====================================================\n";

}

/* Letter Domestic */
void Post_Office::Letter_Domestic()
{
    cout<<"\n\n\t\t\t\t\t\t\t\t====================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || DOMESTIC || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t====================";

    int flag=0;

    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's Pincode :- ";
        fflush(stdin);
        gets(to_pc);
        const regex pattern("^[1-9]{1}[0-9]{2}\\s{0,1}[0-9]{3}$");
        if(regex_match(to_pc, pattern))
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's City / District :- ";
        fflush(stdin);
        gets(to_cd);
        int l=strlen(to_cd);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_cd[i]!=NULL; i++)
            {
                if(isalpha(to_cd[i]))
                    alpha++;
                else if(to_cd[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your State :- ";
        fflush(stdin);
        gets(state);
        int l=strlen(state);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; state[i]!=NULL; i++)
            {
                if(isalpha(state[i]))
                    alpha++;
                else if(state[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        flag=1;
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter The Weight Of Letter(in gms max.2000) :- ";
        while(!(cin>>weight))
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Correct Weight :- ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    while(flag!=1);
    //Price Calculation For Letter
    if(weight>0 && weight<=2000)
    {
        price=(weight+20)*5/20;
        price+=17;
    }
    else
        cout<<"\n\n\t\t\t\t\t\t\t\tWeight Should Be Less Than 2000";

    cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price (Postage Amt.) :- "<<price<<" INR"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t############## LETTER POSTED SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t========================================================\n";


}

//Letter International
void Post_Office::Letter_International()
{
    cout<<"\n\n\t\t\t\t\t\t\t\t=========================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || INTERNATIONAL || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t=========================";

    int flag=0;

    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's Country :- ";
        fflush(stdin);
        gets(to_country);
        int l=strlen(to_country);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_country[i]!=NULL; i++)
            {
                if(isalpha(to_country[i]))
                    alpha++;
                else if(to_country[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        flag=1;
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter The Weight Of Letter(in gms max.2000) :- ";
        while(!(cin>>weight))
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Correct Weight :- ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    while(flag!=1);
    //Price Calculation
    if(strcmp(to_country,"USA")==0 || strcmp(to_country,"usa")==0 || strcmp(to_country,"Usa")==0)
    {
        if(weight>0 && weight<=20)
            price=32;
        else if(weight>20 && weight<=2000)
            price=54+(weight/20);
    }
    else if(price>=2000 && price<=100000)
    {
        price=(price/100)*5;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;
    }
    else if(price>100000)
    {
        price=(price/100)*10;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;
    }
    else
        cout<<"\n\n\t\t\t\t\t\t\t\tThis Country Is Not In Post Office List"<<endl;

    cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price (Postage Amt.+GST) :- "<<price<<" INR"<<endl;

    cout<<"\n\n\t\t\t\t\t\t\t\t############## LETTER POSTED SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t========================================================\n";

}


/* Parcel Domestic */
void Post_Office::Parcel_Domestic()
{
    cout<<"\n\n\t\t\t\t\t\t\t\t====================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || DOMESTIC || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t====================";

    int flag=0;

    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's Pincode :- ";
        fflush(stdin);
        gets(to_pc);
        const regex pattern("^[1-9]{1}[0-9]{2}\\s{0,1}[0-9]{3}$");
        if(regex_match(to_pc, pattern))
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's City / District :- ";
        fflush(stdin);
        gets(to_cd);
        int l=strlen(to_cd);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_cd[i]!=NULL; i++)
            {
                if(isalpha(to_cd[i]))
                    alpha++;
                else if(to_cd[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your State :- ";
        fflush(stdin);
        gets(state);
        int l=strlen(state);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; state[i]!=NULL; i++)
            {
                if(isalpha(state[i]))
                    alpha++;
                else if(state[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        flag=1;
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter The Weight Of Parcel(in gms max.20000) :- ";
        while(!(cin>>weight))
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Correct Weight :- ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    while(flag!=1);
    //Price Calculation For Letter
    if(weight>0 && weight<=500)
    {
        price=19;
    }
    else if(weight>500 && weight<=20000)
    {
        price = weight/500;
        price = price*16+3;
    }
    cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price (Postage Amt.) :- "<<price<<" INR"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t############## PARCEL POSTED SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t========================================================\n";

}

/* Parcel International */
void Post_Office::Parcel_International()
{
    cout<<"\n\n\t\t\t\t\t\t\t\t=========================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || INTERNATIONAL || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t=========================";

    int flag=0;

    do
    {
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Receiver's Country :- ";
        fflush(stdin);
        gets(to_country);
        int l=strlen(to_country);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_country[i]!=NULL; i++)
            {
                if(isalpha(to_country[i]))
                    alpha++;
                else if(to_country[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        flag=1;
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter The Weight Of Parcel(in gms max.20000) :- ";
        while(!(cin>>weight))
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Correct Weight :- ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    while(flag!=1);
    //Price Calculation
    if(strcmp(to_country,"USA")==0 || strcmp(to_country,"usa")==0 || strcmp(to_country,"Usa")==0)
    {
        if(weight>0 && weight<=250)
            price=790;
        else if(weight>250 && weight<=20000)
            price = 940+(weight/250);
    }
    else if(price>=2000 && price<=100000)
    {
        price=(price/100)*5;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;
    }
    else if(price>100000)
    {
        price=(price/100)*10;
        cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price After Discount :- "<<price<<" INR"<<endl;
    }
    else
        cout<<"\n\n\t\t\t\t\t\t\t\tThis Country Is Not In Post Office List"<<endl;

    cout<<"\n\n\t\t\t\t\t\t\t\tTotal Price (Postage Amt.+GST) :- "<<price<<" INR"<<endl;

    cout<<"\n\n\t\t\t\t\t\t\t\t############## PARCEL POSTED SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t========================================================\n";

}

//Speed Post
void Post_Office::Speed_Post()
{
    int pos,choice;
    char s = 'y';
    x=0,n;
    system("cls");
    cout<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ---------------------------- ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ##########          SPEED POST          ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ---------------------------- ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 1. FOR DOMESTIC !!!!!!!!!!!!!!!!!!       ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 2. FOR INTERNATIONAL !!!!!!!!!!!!!       ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t||=====================================================||";

    while(s=='y')
    {

        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
        cin>>choice;

        if(choice==1)
        {
            system("cls");
            p.Domestic();

        }
        else if(choice == 2)
        {
            system("cls");
            p.International();
        }

        cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go To User Menu (y/n) :- ";
        cin>>s;

        char a = 'y';

        if(s=='y')
        {
            while(a=='y')
            {
                p.user_menu();
                cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
                cin>>choice;

                if(choice==1)
                {
                    system("cls");
                    p.Speed_Post();
                }
                else if(choice == 2)
                {
                    system("cls");
                    p.Letter();
                }
                else if(choice == 3)
                {
                    system("cls");
                    p.Parcel();
                }
                else if(choice == 4)
                {
                    system("cls");
                    p.Money_Order();
                }
                if(choice == 5)
                    exit(0);
                cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go Main Menu (y/n) :- ";
                cin>>a;
                if(a=='y')
                {
                    s = 'n';
                    break;
                }
            }
        }
    }
}

/* Letter */
void Post_Office::Letter()
{
    int pos,choice;
    char q = 'y';
    x=0,n;
    system("cls");
    cout<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ---------------------------- ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ##########            LETTER            ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ---------------------------- ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 1. FOR DOMESTIC !!!!!!!!!!!!!!!!!!       ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 2. FOR INTERNATIONAL !!!!!!!!!!!!!       ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t||=====================================================||";

    while(q=='y')
    {

        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
        cin>>choice;

        if(choice==1)
        {
            system("cls");
            p.Letter_Domestic();

        }
        else if(choice == 2)
        {
            system("cls");
            p.Letter_International();
        }

        cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go To User Menu (y/n) :- ";
        cin>>q;

        char b = 'y';

        if(q=='y')
        {
            while(b=='y')
            {
                p.user_menu();
                cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
                cin>>choice;

                if(choice==1)
                {
                    system("cls");
                    p.Speed_Post();
                }
                else if(choice == 2)
                {
                    system("cls");
                    p.Letter();
                }
                else if(choice == 3)
                {
                    system("cls");
                    p.Parcel();
                }
                else if(choice == 4)
                {
                    system("cls");
                    p.Money_Order();
                }
                if(choice == 5)
                    exit(0);
                cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go Main Menu (y/n) :- ";
                cin>>b;
                if(b=='y')
                {
                    q = 'n';
                    break;
                }
            }
        }
    }
}

/* Parcel */
void Post_Office::Parcel()
{
    int pos,choice;
    char d = 'y';
    x=0,n;
    system("cls");
    cout<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ---------------------------- ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ##########            PARCEL            ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ---------------------------- ##########  ||";
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 1. FOR DOMESTIC !!!!!!!!!!!!!!!!!!       ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 2. FOR INTERNATIONAL !!!!!!!!!!!!!       ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t||=====================================================||";

    while(d=='y')
    {

        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
        cin>>choice;

        if(choice==1)
        {
            system("cls");
            p.Parcel_Domestic();

        }
        else if(choice == 2)
        {
            system("cls");
            p.Parcel_International();
        }

        cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go To User Menu (y/n) :- ";
        cin>>d;

        char e = 'y';

        if(d=='y')
        {
            while(e=='y')
            {
                p.user_menu();
                cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
                cin>>choice;

                if(choice==1)
                {
                    system("cls");
                    p.Speed_Post();
                }
                else if(choice == 2)
                {
                    system("cls");
                    p.Letter();
                }
                else if(choice == 3)
                {
                    system("cls");
                    p.Parcel();
                }
                else if(choice == 4)
                {
                    system("cls");
                    p.Money_Order();
                }
                if(choice == 5)
                    exit(0);
                cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go Main Menu (y/n) :- ";
                cin>>e;
                if(e=='y')
                {
                    d = 'n';
                    break;
                }
            }
        }
    }
}

/* Money Order */
void Post_Office::Money_Order()
{
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t=============================";
    cout<<"\n\t\t\t\t\t\t\t\t|| ||    MONEY ORDER    || ||";
    cout<<"\n\t\t\t\t\t\t\t\t=============================";
    cout<<endl;

    int flag=0;

    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Today's Date ( dd-mm-yyyy ) :- ";
        fflush(stdin);
        gets(date);
        if(strlen(date)==10)
        {
            if(isdigit(date[0]) && isdigit(date[1]) && date[2]=='-' && isdigit(date[3]) && isdigit(date[4]) && date[5]=='-' &&
                    isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9]) )
            {
                int p,q,r,s,d,m,y;
                p=date[0]-48;
                q=date[1]-48;
                d=p*10+q;
                p=date[3]-48;
                q=date[4]-48;
                m=p*10+q;
                p=date[6]-48;
                q=date[7]-48;
                r=date[8]-48;
                s=date[9]-48;
                p=p*1000;
                q=q*100;
                r=r*10;
                y=p+q+r+s;
                if(y>=2023)
                {
                    if(m==4 || m==6 || m==9 || m==11)
                    {
                        if(d>=1 && d<=30)
                            flag=1;
                    }
                    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
                    {
                        if(d>=1 && d<=31)
                            flag=1;
                    }
                    else if(m==2)
                    {
                        if(y%4==0)
                        {
                            if(d>=1 && d<=29)
                                flag=1;
                        }
                        else
                        {
                            if(d>=1 && d<=28)
                                flag=1;
                        }
                    }
                }
            }
            if(flag!=1)
                cout<<"\n\n\t\t\t\t\t\t\t\tPlease check you entered something wrong.....\n";
        }
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Post Office Name :- ";
        fflush(stdin);
        gets(po_name);
        if(strlen(po_name)>1)
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";

    }
    while(flag!=1);
    flag=0;
    do
    {
        flag=1;
        cout<<"\n\t\t\t\t\t\t\t\tEnter Amount You Want To Pay :- ";
        fflush(stdin);
        while(!(cin>>amount))
        {
            cout<<"\n\t\t\t\t\t\t\t\tEnter Correct Amount :- ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Payee Name :- ";
        fflush(stdin);
        gets(to_name);
        int l=strlen(to_name);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_name[i]!=NULL; i++)
            {
                if(isalpha(to_name[i]))
                    alpha++;
                else if(to_name[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Payee Address :- ";
        gets(to_address);
        if(strlen(to_address)>1)
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Payee State :- ";
        gets(to_state);
        int l=strlen(to_state);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_state[i]!=NULL; i++)
            {
                if(isalpha(to_state[i]))
                    alpha++;
                else if(to_state[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your City / District :- ";
        gets(to_cd);
        int l=strlen(to_cd);
        if(l>1)
        {
            int alpha=0,space=0;
            for(int i=0; to_cd[i]!=NULL; i++)
            {
                if(isalpha(to_cd[i]))
                    alpha++;
                else if(to_cd[i]==' ')
                    space++;
            }
            if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                flag=1;
        }
        if(flag!=1)
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);
    flag=0;
    do
    {
        cout<<"\n\t\t\t\t\t\t\t\tEnter Your Pincode :- ";
        gets(to_pc);
        const regex pattern("^[1-9]{1}[0-9]{2}\\s{0,1}[0-9]{3}$");
        if(regex_match(to_pc, pattern))
            flag=1;
        else
            cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
    }
    while(flag!=1);

    cout<<"\n\n\t\t\t\t\t\t\t\t############## MONEY ORDER SUCCESSFULLY ##############";
    cout<<"\n\n\t\t\t\t\t\t\t\t======================================================\n";

}

/* Updating User Record */
void Post_Office::User_Update()
{
    int pos,choice;
    x=0,n;
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t=======================";
    cout<<"\n\t\t\t\t\t\t\t\t|| || UPDATE USER || ||";
    cout<<"\n\t\t\t\t\t\t\t\t=======================";
    cout<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\tEnter The User No. :- ";
    cin>>n;
    fstream file("pos.txt");
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)&p,sizeof(p));
        if(p.get_userno()==n)
        {
            x=1;
            break;
        }
    }
    if(x==1)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t############# USER RECORD FOUND #############";
        cout<<"\n\n\t\t\t\t\t\t\t\t=============================================";
        cout<<"\n\n\t\t\t\t\t\t\t\tPress Any Key To Continue...........";
        getch();
        system("cls");
        cout<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
        cout<<"\n\t\t\t\t\t\t\t\t|| ########## ----------------------------- ########## ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| ##########          UPDATE USER          ########## ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| ########## ----------------------------- ########## ||";
        cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 1. FOR UPDATING NAME !!!!!!!!!!!!!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 2. FOR UPDATING ADDRESS !!!!!!!!!!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 3. FOR UDATING COUNTRY !!!!!!!!!!!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 4. FOR UPDATING STATE !!!!!!!!!!!!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 5. FOR UPDATING CITY / DISTRICT !!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 6. FOR UPDATING PINCODE !!!!!!!!!!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 7. FOR UPDATING E-MAIL !!!!!!!!!!!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 8. FOR UPDATING MOBILE !!!!!!!!!!!!!!    ||";
        cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
        cout<<"\n\t\t\t\t\t\t\t\t||=====================================================||";
        int flag=0;
        do
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
            cin>>choice;
            if(choice==1)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New Name :- ";
                    fflush(stdin);
                    gets(name);
                    int l=strlen(name);
                    if(l>1)
                    {
                        int alpha=0,space=0;
                        for(int i=0; name[i]!=NULL; i++)
                        {
                            if(isalpha(name[i]))
                                alpha++;
                            else if(name[i]==' ')
                                space++;
                        }
                        if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                            flag=1;
                    }
                    if(flag!=1)
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);
            }
            else if(choice==2)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New Address :- ";
                    fflush(stdin);
                    gets(address);
                    if(strlen(address)>1)
                        flag=1;
                    else
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);

            }
            else if(choice==3)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New Country :- ";
                    fflush(stdin);
                    gets(country);
                    int l=strlen(country);
                    if(l>1)
                    {
                        int alpha=0,space=0;
                        for(int i=0; country[i]!=NULL; i++)
                        {
                            if(isalpha(country[i]))
                                alpha++;
                            else if(country[i]==' ')
                                space++;
                        }
                        if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                            flag=1;
                    }
                    if(flag!=1)
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);

            }
            else if(choice==4)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New State :- ";
                    fflush(stdin);
                    gets(state);
                    int l=strlen(state);
                    if(l>1)
                    {
                        int alpha=0,space=0;
                        for(int i=0; state[i]!=NULL; i++)
                        {
                            if(isalpha(state[i]))
                                alpha++;
                            else if(state[i]==' ')
                                space++;
                        }
                        if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                            flag=1;
                    }
                    if(flag!=1)
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);

            }
            else if(choice==5)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New City / District :- ";
                    fflush(stdin);
                    gets(cd);
                    int l=strlen(cd);
                    if(l>1)
                    {
                        int alpha=0,space=0;
                        for(int i=0; cd[i]!=NULL; i++)
                        {
                            if(isalpha(cd[i]))
                                alpha++;
                            else if(cd[i]==' ')
                                space++;
                        }
                        if( (alpha==l-1 || alpha==l) && (space==1 || space==0) )
                            flag=1;
                    }
                    if(flag!=1)
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);

            }
            else if(choice==6)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New Pincode :- ";
                    fflush(stdin);
                    gets(pc);
                    const regex pattern("^[1-9]{1}[0-9]{2}\\s{0,1}[0-9]{3}$");
                    if(regex_match(pc, pattern))
                        flag=1;
                    else
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);

            }
            else if(choice==7)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New E-Mail :- ";
                    fflush(stdin);
                    gets(email);
                    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
                    if(regex_match(email, pattern))
                        flag=1;
                    else
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);

            }
            else if(choice==8)
            {
                do
                {
                    cout<<"\n\t\t\t\t\t\t\t\tEnter User's New Mobile Number (+91) :- ";
                    fflush(stdin);
                    gets(contact_no);
                    const regex pattern("(0|91)?[6-9][0-9]{9}");
                    if(regex_match(contact_no, pattern))
                        flag=1;
                    else
                        cout<<"\n\t\t\t\t\t\t\t\tPlease Check You Entered Something Wrong.....\n";
                }
                while(flag!=1);

            }

            if(flag!=1)
                cout<<"\nPlease Check You Entered Wrong Choice.....";
        }
        while(flag!=1);

        file.seekg(pos);
        file.write((char*)&p,sizeof(p));
        cout<<"\n\n\t\t\t\t\t\t\t\t############# USER RECORD UPDATED SUCCESSFULY #############";
        cout<<"\n\n\t\t\t\t\t\t\t\t===========================================================";

    }
    else
    {
        cout<<"\n\n\n\t\t\t\t\t\t\t\t############# NO RECORD FOUND #############";
        cout<<"\n\n\n\t\t\t\t\t\t\t\t===========================================\n";
    }
}

/* Delete User */
void Post_Office::Delete_User()
{
    x=0,n;
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t=======================";
    cout<<"\n\t\t\t\t\t\t\t\t|| || DELETE USER || ||";
    cout<<"\n\t\t\t\t\t\t\t\t=======================";
    cout<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\tEnter The User No. :- ";
    cin>>n;
    ifstream file("pos.txt");
    ofstream temp("temp.txt");
    while(file.read((char*)&p,sizeof(p)))
    {
        if(p.get_userno()==n)
            x=1;
        else
            temp.write((char*)&p,sizeof(p));
    }
    file.close();
    temp.close();
    remove("pos.txt");
    rename("temp.txt","pos.txt");
    if(x==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t############# NO RECORD FOUND #############";
        cout<<"\n\n\t\t\t\t\t\t\t\t===========================================\n";
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t############# USER DELETED #############";
        cout<<"\n\n\t\t\t\t\t\t\t\t========================================\n";
        cout<<"\n\n\t\t\t\t\t\t\t\tPress Any Key To View Deleted User's Record.............";
        getch();
        p.Users_Display();
    }
}

void Post_Office::Search_User()
{
    x=0,n;
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t=======================";
    cout<<"\n\t\t\t\t\t\t\t\t|| || SEARCH USER || ||";
    cout<<"\n\t\t\t\t\t\t\t\t=======================";
    cout<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\tEnter The User No. :- ";
    cin>>n;
    ifstream file("pos.txt");
    while(file.read((char*)&p,sizeof(p)))
    {
        if(p.get_userno()==n)
        {
            x=1;
            p.Users_Display();
            break;
        }
    }
    file.close();
    if(x==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t############# NO RECORD IS FOUND #############";
        cout<<"\n\n\t\t\t\t\t\t\t\t==============================================\n";

    }
}

/* Admin Login */
void Post_Office::admin_login()
{
    system("cls");
    int choice,ch;
    char c='y';
    x=0;
    string a_nm, a_pass;
    cout<<"\n\n\t\t\t\t\t\t\t\t========================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || ADMIN LOGIN  || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t========================";
    cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Your Name :- ";
    fflush(stdin);
    getline(cin, a_nm);
    cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Password :- ";
    ch = getch();
    while(ch!=13)
    {
        a_pass.push_back(ch);
        cout<<"*";
        ch = getch();
    }
    if(a_nm == "Saket Anand" && a_pass == "5134")
    {
        x=1;
    }

    if(x==1)
    {
        while(c=='y')
        {
            system("cls");
            p.admin_menu();
            cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
            cin>>choice;

            if(choice==1)
            {
                x=0;
                system("cls");
                ifstream file("pos.txt");
                while(file.read((char*)&p,sizeof(p)))
                {
                    x=1;
                    p.Users_Display();
                    sleep(5);
                }
                file.close();
                if(x==0)
                {
                    system("cls");
                    cout<<"\n\n\t\t\t\t\t\t\t\tNo Record Is Present Till Now.............\n";
                    cout<<"\n\t\t\t\t\t\t\t\t============================================\n";
                }
            }
            else if(choice == 2)
            {
                system("cls");
                p.User_Update();
            }
            else if(choice == 3)
            {
                system("cls");
                p.Delete_User();
            }
            else if(choice == 4)
            {
                system("cls");
                p.Search_User();
            }
            else if(choice == 5)
                exit(0);
            cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go To Admin Menu (y/n) :- ";
            cin>>c;
        }
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t############# ADMIN LOGIN FAILED #############";
        cout<<"\n\n\t\t\t\t\t\t\t\t==============================================";
    }
    file.close();
}

/* Displaying Users Record */
void Post_Office::Users_Display()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\t\t================================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| ||     USERS RECORD     || ||";
    cout<<"\n\n\t\t\t\t\t\t\t\t================================";
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || USER NO :- "<< user_no ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || USER NAME :- "<< name ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || ADDRESS :- "<< address ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || COUNTRY :- "<< country ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || STATE :- "<< state ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || CITY / DISTRICIT :- "<< cd ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || PINCODE :- "<< pc ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || E-MAIL :- "<< email ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || MOBILE NO. :- "<< contact_no ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| || PASSWORD :- "<< pswd ;
    cout<<"\n\n\t\t\t\t\t\t\t\t|| ||======================|| ||";
}

/* User Menu */
void Post_Office::user_menu()
{
    system("cls");
    cout<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ------------------------------ ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ##########          WELCOME USER          ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ------------------------------ ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                      ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 1. SPEED POST !!!!!!!!!!!!!!!!!!!!!!!!!!  ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                      ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 2. LETTER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                      ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 3. PARCEL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                      ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 4. MONEY ORDER !!!!!!!!!!!!!!!!!!!!!!!!!  ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                      ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 5. EXIT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                      ||";
    cout<<"\n\t\t\t\t\t\t\t\t||======================================================||";
}

/* Admin Menu */
void Post_Office::admin_menu()
{
    cout<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ----------------------------- ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ##########         WELCOME ADMIN         ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ----------------------------- ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 1. USER DETAILS !!!!!!!!!!!!!!!!!!!!!    ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 2. UPDATE USER !!!!!!!!!!!!!!!!!!!!!!    ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 3. DELETE USER !!!!!!!!!!!!!!!!!!!!!!    ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 4. SEARCH USER !!!!!!!!!!!!!!!!!!!!!!    ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 5. EXIT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!    ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t||=====================================================||";
}

/* Main Menu Function */
void main_menu()
{
    cout<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ----------------------------- ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## WELCOME TO POST OFFICE SYSTEM ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| ########## ----------------------------- ########## ||";
    cout<<"\n\t\t\t\t\t\t\t\t=========================================================";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 1. NEW USER REGISTRATION !!!!!!!!!!      ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 2. USER LOGIN !!!!!!!!!!!!!!!!!!!!!      ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 3. ADMIN LOGIN !!!!!!!!!!!!!!!!!!!!      ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t|| !!!!!!!!!! 4. EXIT !!!!!!!!!!!!!!!!!!!!!!!!!!!      ||";
    cout<<"\n\t\t\t\t\t\t\t\t||                                                     ||";
    cout<<"\n\t\t\t\t\t\t\t\t||=====================================================||";
}

/* To Return User Number */
int Post_Office::get_userno()
{
    return user_no;
}

/* Main Function of Program */
int main()
{
    int choice;
    char ch='y';
    while(ch=='y')
    {
        system("cls");
        system("color f0");
        main_menu();
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter Your Choice :- ";
        cin>>choice;

        if(choice==1)
        {
            fstream file;
            file.open("pos.txt",ios::in);
            while(file.read((char*)&p,sizeof(p)))
            {
                z=p.get_userno();
            }
            file.close();

            file.open("pos.txt",ios::app);
            p.user_reg();
            file.write((char*)&p,sizeof(p));
            file.close();

        }
        else if(choice==2)
        {
            system("cls");
            p.user_login();
        }
        else if(choice==3)
        {
            system("cls");
            p.admin_login();
        }
        else if(choice==4)
            exit(0);
        cout<<"\n\n\t\t\t\t\t\t\t\tWant To Go Main Menu (y/n) :- ";
        cin>>ch;

    }
    return 0;
}
