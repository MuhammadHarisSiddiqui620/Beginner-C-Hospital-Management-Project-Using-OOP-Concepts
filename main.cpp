#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include<stdio.h>

using namespace std;

class verifed;
class Hospital
{
protected:
    string name,disease,address;
    char sex;
     int month,day,year,age,scale,card_no,cvv,pincode,balance;
    string contact;
public:
    Hospital(): name(" "),age(0),sex(' '),disease(" "),day(0),month(0),year(0),contact(" "),card_no(0),pincode(0),cvv(0),balance(0) {}
    Hospital(int a): balance(a) {}                                        ///Constructors
    ~Hospital()  {}
    Hospital(string n,int a,char s,string d1,int d,int m,int y,string c,int a1,int b1,int c1): name(n),age(a),sex(s),disease(d1),day(d),month(m),year(y),contact(c),card_no(a1),pincode(b1),cvv(c1) {}
                                                                        ///Destructor
      void getinfo1()
{
    cout<<"Enter Patient Name: ";
    cin>>name;
    cout<<"Enter Address: ";
    cin>>address;
}
      void putinfo()
{
        cout<<"\n|"<<name <<"\t\t|"<<age<<"\t\t|"<<sex<<"\t\t|"<<disease<<"\t\t|"<<day<<"/"<<month<<"/"<<year<<"\t|"<<contact<<"\t  |";
}
    void putinfo1()
{
    cout<<"\n|"<<name<<"\t|"<<address<<"  \t      |";
}
 void modify()
{
        int y;
        cout<<"What You Want To Modify\n";
        cout<<" 0)Name\n 1)Age\n 2)Disease\n 3)Date\n 4)Sex\n 5)Contact Number\n";
        cout<<"\n Enter choice = ";
        cin>>y;
        switch(y)
        {
        case 0:
            cin>>name;
            break;
        case 1:
            cin>>age;
            break;
        case 2:
            cin>>disease;
            break;
        case 3:
            cin>>day>>month>>year;
            break;
        case 4:
            cin>>sex;
            break;
        case 5:
            cin>>contact;
            break;
        }
}
     virtual void getinfo(){}                           ///Polymorphism

     template <class atype>                              ///Function Template
      atype Payment(atype a1)
{
         cout<<"Enter Credit/Debit Card Number: ";
         cin>>a1.card_no;
         cout<<"Enter Pin Code: ";
         cin>>a1.pincode;
         cout<<"Enter CVV: ";
         cin>>a1.cvv;
         cout<<"Enter Account Balance: ";
         cin>>a1.balance;
         return a1;
}

Hospital operator --()                            ///Unary Operator Overloading
{
  int B=10000;
  if (balance<10000 )
  {
      cout<<"\n\n\t\t\t************* Sorry Not Enough Money *************\t\n\n\n ";
       balance=0;
  }
  else
  {
      balance=balance-B;
      cout<<"\n\n\t\t\t*************"<<balance<<" Has Been Drawn Out Of Your Account *************\n\n";
  }
return Hospital(balance);
}
friend class verifed;
};

class Emerg                                         ///Composition
{
    Hospital h1;
public:
    void getinfo1()
    {
    h1.getinfo1();
    }
    void putinfo1()
    {
     h1.putinfo1();
    }
    friend class verifed;

};

class Data:public Hospital                          /// Public Inheritance
{
public:
    void getinfo()
    {
        cout<<"Enter Patient Name: ";
        cin>>name;
        cout<<"Enter Age: ";
        cin>>age;
        cout<<"Enter Sex: ";
        cin>>sex;
        cout<<"Enter Disease: ";
        cin>>disease;
        cout<<"Enter Date in D/M/Y Format: ";
        cin>>day>>month>>year;
        cout<<"Enter Contact No.: ";
        cin>>contact;

    }
};

class verifed                                      ///Friend Class
{
public:
    void verifys(Hospital a1)
    {
       if (a1.balance<1)
        {
            cout<<"Not Verified    |";
        }
        else
        {
            cout<<"Verified        |";
        }

    }
};

int main()
{
    Hospital *p1;
    Hospital s1,s2;
    Data m1;
    Emerg e1;
    verifed v1;
    int Y;
   char choice;
    cout << "\n\t\t\t************** WELCOME TO GOTHAM GENERAL HOSPITAL **************\n\n" << endl;
   fstream file("Patient.dat", ios::binary |ios::app | ios::in | ios::out );
   file.seekp(0,ios::end);
   if(!file)
   {
       cout<<"\n\t\t\t\t\t Cannot Create the file";
      return 0;
   }
   do
    {
   cout<<"\n\t\t\t\t\t1) Emergency\n";
   cout<<"\n\t\t\t\t\t2) Enter For Appointment\n";
   cout<<"\n\t\t\t\t\t3) Modify Your Appointment\n";
   cout<<"\n\t\t\t\t\t4) Advance Payment\n";
   cout<<"\n\t\t\t\t\t5) Delete Your Details\n";
   cout<<"\n\t\t\t\t\t6) Exit\n";
   cout<<"\n\t\t\t\t\t Enter Your Choice = ";
   cin>>Y;
   try  {                                                        ///Exception Handling
     if(Y<7 && Y>0)
     {
   switch(Y)
   {
   case 1:
   e1.getinfo1();
   break;

   case 2:
        p1=&m1;                                           ///Default Assignment Operator
        p1->getinfo();
    break;

   case 3:
    p1->modify();
    break;

     case 4:
    s1=s1.Payment(s2);
    --s1;
    p1=&s1;
    break;

    case 5:
       remove("Patient.dat");
         cout<<"\n\n\t\t\t\t************* Data is Deleted *************\n\n\n\n\n";
        return 0;

     case 6:
         cout<<"\n\n\t\t\t\t************* Menu is Closed *************\n\n\n\n\n";
    return 0;
       }
   }
   else
   {
        throw (Y);
   }

   }
    catch (int x)
 {
     cout<<"\n\n\t\t\t*************  Exception Caught Choice was = "<<x<<"  ************* \n\n";

 }

if (Y==1)
{
    file.write( (char*)&(e1),sizeof(e1) );
}
if (Y==2 || Y==3 || Y==4)
{
    file.write( (char*)&(*p1),sizeof(*p1) );
}
 cout<<"\nEnter another one (y/n)? ";
   cin >>choice;
 }
 while( choice=='y' );
 cout<<"\n";

 file.seekg(0);
if (Y==1)
{
  file.read((char *)&(e1),sizeof(e1));
  cout<<" ------------------------------------- ";
  cout<<"\n|Name "<<"\t\t|"<<"Address"<<"              |";
while(!file.eof())
  {
 cout<<"\n|---------------|---------------------| ";
   e1.putinfo1();
  file.read((char *)&(e1),sizeof(e1));
  }
  cout<<"\n ------------------------------------- ";
}
else
{
file.read(reinterpret_cast<char*>(&(*p1)),sizeof(*p1));
 cout<<"\n ------------------------------------------------------------------------------------------------------------------ ";
 cout<<"\n|Patient "<<"\t|"<<"Age"<<"\t\t|"<<"Sex"<<"\t\t|"<<"Disease"<<" \t|"<<"Date"<<"\t\t|"<<"Contact Number"<<"\t  |"<<"Payment         |";
while(!file.eof())
{
 cout<<"\n|---------------|---------------|---------------|---------------|---------------|-----------------|----------------|";
  p1->putinfo();
  file.read((char *)&(*p1),sizeof(*p1));
    v1.verifys(*p1);
}
 cout<<"\n ------------------------------------------------------------------------------------------------------------------ ";
}
 file.close();
cout<<"\n\n";
return 0;
}

