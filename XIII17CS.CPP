#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>

struct DATE
{
 int dd,mm,yyyy;
};

class mparadise
{
 char username[30], password[20], name[30], emailid[30],
 nationality[20], gender[10],roomtype[20];
 long double phone;
 int age,rno,inidateno,findateno;
 DATE initiald,finald;

public:
 mparadise(){rno=0;strcpy(roomtype,"null");initiald.dd=0;initiald.mm=0;
	     initiald.yyyy=0;finald.dd=0;finald.mm=0;finald.yyyy=0;}
 void display();
 void inputlogin();
 void inputregistration();
 void inputcheckin();//forproviding room and days
 void edit();
 void delete1(){strcpy(roomtype,"NULL"); initiald.dd=0;initiald.mm=0;
	       initiald.yyyy=0;finald=initiald;rno=0;}
 char*rrtype(){return roomtype;}
 char*rusername(){return username;}
 char*rpassword(){return password;}
 int rrno(){return rno;}
 int rinidateno(){return inidateno;}
 int rfindateno(){return findateno;}
 DATE rinidate(){return initiald;}
 DATE rfindate(){return finald;}
 void inidatekano(int a){ inidateno=a;}
 void findatekano(int a){ findateno=a;}
 void giverno(int a){rno=a;}

};

void newscreen()
{
 clrscr();
 gotoxy(25,1);
 cout<<"WELCOME TO MAURYA PARADISE\n";
}

void displayhomescreen()
{
  for(int i=1; i<25;i++)
 {
  gotoxy(i,1);
  cout<<" WELCOME TO MAURYA PARADISE";
  delay(30);
 }
}

void sortfile();
void newrec(mparadise &);
void editrec(mparadise &);
void deleterec(mparadise &);
void admin();
char getuseradmin();
char getloginregister();
char menu();
void login(mparadise &);
int checkfile(mparadise &);
mparadise register1();
char menu();
void check(mparadise &);
void viewfile(mparadise );
int datekano(DATE);



void mparadise::display()
{
  cout<<endl;
  cout<<setw(10)<<name<<setw(10)<<rno<<setw(8)
  <<initiald.dd<<'.'<<initiald.mm<<'.'<<initiald.yyyy<<setw(8)
  <<finald.dd<<'.'<<finald.mm<<'.'<<finald.yyyy<<setw(21)
  <<roomtype<<endl;
}

void mparadise::inputlogin()
{
 newscreen();
 gotoxy(25,7);
 cout<<"USERNAME: ";
 gets(username);
 gotoxy(25,8);
 cout<<"PASSWORD: ";
 int i=0;
 char ch;
 do
 {
  ch=getch();
  password[i++]=ch;
  if(ch!=13)
  cout<<'*';
 }while(ch!=13);
 password[i-1]='\0';
}

void mparadise::inputregistration()
{
 gotoxy(3,4);cout<<"NEW REGISTRATION: "<<endl<<endl;
 cout<<"Enter Name: ";
 gets(name);cout<<endl;
 cout<<"Email id: ";
 gets(emailid);cout<<endl;
 cout<<"Enter nationality: ";
 gets(nationality);cout<<endl;
 cout<<"Enter age :";
 cin>>age;cout<<endl;
 cout<<"Enter phone number:";
 cin>>phone;cout<<endl;
 cout<<"Create username: ";
 gets(username);cout<<endl;
 cout<<"Create password: ";
 gets(password);cout<<endl;

}


void mparadise::inputcheckin()
{
 gotoxy(5,13);cout<<"Enter the room type you would like:";
 gotoxy(5,15);cout<<"1)Penthouse Suite";
 gotoxy(5,16);cout<<"2)Honeymoon Suite";
 gotoxy(5,17);cout<<"3)Business Suite";
 gotoxy(5,18);cout<<"4)Lounge";
 int y=15;char ch;
  gotoxy(5,15);
   do
   {
    ch=getch();
    if(ch==72 && y!=15)
    gotoxy(5,--y);
    else if(ch==80 && y!=18)
    gotoxy(5,++y);
   }while(ch!=13);

 switch(y)
 {
  case 15: strcpy(roomtype,"Penthouse Suite");break;
  case 16: strcpy(roomtype,"Honeymoon Suite");break;
  case 17: strcpy(roomtype,"Business Suite");break;
  case 18: strcpy(roomtype,"Lounge");break;
 }
 newscreen();
 gotoxy(2,4);cout<<"Enter checkin date(dd): ";cin>>initiald.dd;
 gotoxy(2,5);cout<<"Enter checkin month(mm): ";cin>>initiald.mm;
 gotoxy(2,6);cout<<"Enter checkin year(yyyy): ";cin>>initiald.yyyy;
 gotoxy(2,8);cout<<"Enter checkout date(dd): ";cin>>finald.dd;
 gotoxy(2,9);cout<<"Enter checkout month(mm): ";cin>>finald.mm;
 gotoxy(2,10);cout<<"Enter checkout year(yyyy): ";cin>>finald.yyyy;
}

void mparadise::edit()
{
 gotoxy(2,4);cout<<"Enter new initial date(dd): ";cin>>initiald.dd;
 gotoxy(2,5);cout<<"Enter new intial month(mm): ";cin>>initiald.mm;
 gotoxy(2,6);cout<<"Enter new initial year(yyyy): ";cin>>initiald.yyyy;
 gotoxy(2,8);cout<<"Enter new final date(dd): ";cin>>finald.dd;
 gotoxy(2,9);cout<<"Enter new final month(mm): ";cin>>finald.mm;
 gotoxy(2,10);cout<<"Enter new final year(yyyy): ";cin>>finald.yyyy;

 gotoxy(2,13);cout<<"Enter the new room type you would like:";
 gotoxy(2,15);cout<<"1)Penthouse Suite";
 gotoxy(2,16);cout<<"2)Honeymoon Suite";
 gotoxy(2,17);cout<<"3)Business Suite";
 gotoxy(2,18);cout<<"4)Lounge";

 int y=15;char ch;
  gotoxy(2,15);
   do
   {
    ch=getch();
    if(ch==72 && y!=15)
    gotoxy(2,--y);
    else if(ch==80 && y!=18)
    gotoxy(2,++y);
   }while(ch!=13);

 switch(y)
 {
  case 15: strcpy(roomtype,"Penthouse Suite");break;
  case 16: strcpy(roomtype,"Honeymoon Suite");break;
  case 17: strcpy(roomtype,"Business Suite");break;
  case 18: strcpy(roomtype,"Lounge");break;
 }
}

void main()
{
 clrscr();
 displayhomescreen();
 cout<<endl;
 int i=1;
 mparadise U;
 do
 {
  newscreen(); int j;
  char ch=getuseradmin();
  if(ch=='u')
  {
   char x=getloginregister();
   if(x=='l')
   {login(U);i=1;}
   else if(x=='r')
   {U=register1();i=1;}
   else if(x=='b')
   i=2;

   while(i==1)
   {
    char y=menu();
    if(y=='n')
    {
     newrec(U);i=1;
    }
    else if(y=='c')
    {editrec(U);i=1;}
    else if(y=='d')
    {deleterec(U);i=1;}
    else if(y=='v')
    {viewfile(U);
    i=1;}
    else if(y=='x')
    {i=2;}
    }
   }
   else
   if (ch=='a')
   {
    admin();
    i=2;
    getch();
   }
  else
  i=3;
 }while(i==2);
}


void admin()
{
 clrscr();
 sortfile();
 gotoxy(15,8);
 cout<<"Enter password : ";
 char pword[10];
 int i=0;char ch;


 do
 {
  ch=getch();
  pword[i++]=ch;
  if(ch!=13)
  cout<<'*';
 }while(ch!=13);
 pword[i-1]='\0';
 if(strcmp("mpr",pword)==0)
 {
  clrscr();
  gotoxy(2,2);cout<<"Which bookings would you like to see:";
  gotoxy(2,4);cout<<"1)Penthouse Suite";
  gotoxy(2,5);cout<<"2)Honeymoon Suite";
  gotoxy(2,6);cout<<"3)Business Suite";
  gotoxy(2,7);cout<<"4)Lounge";
  char rtype[20];
  int y=4;
  gotoxy(2,4);
   do
   {
    ch=getch();
    if(ch==72 && y!=4)
    gotoxy(2,--y);
    else if(ch==80 && y!=7)
    gotoxy(2,++y);
   }while(ch!=13);

  switch(y)
  {
   case 4: strcpy(rtype,"Penthouse Suite");break;
   case 5: strcpy(rtype,"Honeymoon Suite");break;
   case 6: strcpy(rtype,"Business Suite");break;
   case 7: strcpy(rtype,"Lounge");break;
  };
   clrscr();
   fstream fil;
   mparadise S;
   fil.open("para.dat",ios::binary|ios::in);
   gotoxy(1,2);
   cout<<setw(10)<<"Name"<<setw(10)<<"Room no."
   <<setw(16)<<"Initial date"<<setw(15)<<"Final date"<<setw(21)
   <<"Suite type"<<endl<<endl;
   while(fil.read((char*)&S,sizeof(S)))
   {
    if(strcmpi(S.rrtype(),rtype)==0)
    S.display();
   }
  fil.close();
  }
  else
  {gotoxy(15,9);cout<<"\nSORRY! Invalid password ";}
  getch();
  newscreen();
}

char getuseradmin()
{
 newscreen();
 char ch;
 gotoxy(5,4);cout<<"Choose an option:";
 gotoxy(5,6);cout<<"1)USER";
 gotoxy(5,7);cout<<"2)ADMIN";
 gotoxy(5,8);cout<<"3)Exit";
 int y=6;
 gotoxy(5,6);
   do
   {
    ch=getch();
    if(ch==72 && y!=6)
    gotoxy(5,--y);
    else if(ch==80 && y!=8)
    gotoxy(5,++y);
   }while(ch!=13);

 switch(y)
 {
  case 6: ch='u';break;
  case 7: ch='a';break;
  case 8: ch='e';break;
 }
 return ch;
}

char getloginregister()
{
 newscreen();
 char ch;
 gotoxy(5,7);cout<<"Choose an option(1/2/3)";
 gotoxy(5,8);cout<<"(NOTE: If you dont have a LOGIN ID, click REGISTER)";
 gotoxy(5,10);cout<<"1)LOGIN";
 gotoxy(5,11);cout<<"2)REGISTER";
 gotoxy(5,12);cout<<"3)Go back";

 int y=10;
  gotoxy(5,10);
   do
   {
    ch=getch();
    if(ch==72 && y!=10)
    gotoxy(5,--y);
    else if(ch==80 && y!=12)
    gotoxy(5,++y);
   }while(ch!=13);

 switch(y)
 {
  case 10: ch='l';break;
  case 11: ch='r';break;
  case 12: ch='b';break;
 }
 return ch;
}

void login(mparadise &temp)
{
 fstream fil;
 fil.open("para.dat",ios::binary|ios::in|ios::out);
 int p,u;
 do
 {
  newscreen();
  mparadise m;
  int j=0;u=0;p=0;
  m.inputlogin();
  fil.seekg(0);
  while(j==0 && fil.read((char*)&temp, sizeof(temp)))
  {
   if(strcmp(m.rusername(),temp.rusername())==0)
   {
    u=0,j=1;
    if(strcmp(m.rpassword(),temp.rpassword())==0)
    p=0;
    else
    p=1;
   }
  else
  u=1;
  }
  if(p==1)
  {gotoxy(25,9);cout<<"Sorry! Invalid password";getch();}
  else if(u==1)
   {gotoxy(25,9);cout<<"Sorry! Invalid username";getch();}
 }while(p==1 || u==1);
 fil.close();
}

int checkfile(mparadise &U)
{
 fstream fil;
 int i=1;
 mparadise temp;
 fil.open("para.dat",ios::binary|ios::in);
 while(i && fil.read((char*)&temp,sizeof(temp)))
 {
  if(strcmp(U.rusername(),temp.rusername())==0)
  i=0;//else i=1;
 }
 fil.close();
 return i;
}

mparadise register1()
{
 newscreen();
 cout<<"\n\n\n";
 mparadise U;
 fstream fil; int j=0;
 fil.open("para.dat",ios::binary|ios::app);

 do
 {
  U.inputregistration();
  int i=checkfile(U);
  if(i==0)
   {cout<<"Sorry! Username already exits.Register again.";
   getch();newscreen();}
   else
   {
   j=1;
   cout<<"CONGRATULATIONS!!! You are successfully registered!!";
   getch();
   }
  }while(j==0);

 fil.write((char*)&U,sizeof(U));
 fil.close();
 return U;
}

char menu()
{
 newscreen();
 char ch;
 gotoxy(25,14);cout<<"choose an option:";
 gotoxy(25,16);cout<<"1)Book a new room";
 gotoxy(25,17);cout<<"2)change previous booking";
 gotoxy(25,18);cout<<"3)cancel your booking";
 gotoxy(25,19);cout<<"4)view your booking";
 gotoxy(25,20);cout<<"5)logout\n";
 int y=16;
  gotoxy(25,16);
   do
   {
    ch=getch();
    if(ch==72 && y!=16)
    gotoxy(25,--y);
    else if(ch==80 && y!=20)
    gotoxy(25,++y);
   }while(ch!=13);


 switch(y)
 {
  case 16: ch='n';break;
  case 17: ch='c';break;
  case 18: ch='d';break;
  case 19: ch='v';break;
  case 20: ch='x';break;
 }
 return ch;
}

void newrec( mparadise &U)
{
 newscreen();
 mparadise temp;
 fstream fil;
 fil.open("para.dat",ios::binary|ios::in|ios::out);
 U.inputcheckin();
 DATE d1=U.rinidate();
 DATE d2=U.rfindate();
 int p=datekano(d1);
 int q=datekano(d2);
 U.inidatekano(p);
 U.findatekano(q);
 check(U);
 int R=U.rrno();
 if(R!=0)
 {
  cout<<endl<<"CONGRATULATIONS!!! YOUR ROOM NUMBER IS "<<U.rrno();
  while(fil.read((char*)&temp,sizeof(temp)))
  {
   if(strcmp(U.rusername(),temp.rusername())==0)
   {
    fil.seekg(fil.tellg()-sizeof(temp));
    fil.write((char*)&U,sizeof(U));
   }
  }
  getch();
 }
 else
  {cout<<"\n\nSORRY! That room isn't available";
   U.delete1();
  getch();}
  fil.close();
}



void editrec(mparadise &U)
{
 newscreen();
 fstream fil;
 mparadise temp, Temp;
 fil.open("para.dat",ios::binary|ios::in|ios::out);
 while(fil.read((char*)&temp,sizeof(temp)))
 {
  if(strcmp(U.rusername(),temp.rusername())==0)
  {
   mparadise old1=U;
   U.edit();
    DATE d1=U.rinidate();
    DATE d2=U.rfindate();
    int p=datekano(d1);
    int q=datekano(d2);
    U.inidatekano(p);
    U.findatekano(q);
    check(U);
   if(U.rrno()!=0)
    {
     cout<<endl<<"\n\n\nCONGRATULATIONS!!!!YOUR BOOKINGS HAVE BEEN CHANGED!";
     cout<<"\nYOUR NEW ROOM NUMBER IS "<<U.rrno();
     fil.seekg(fil.tellp()-sizeof(U));
     fil.write((char*)&U,sizeof(U));
     getch();
    }
   else
   {
     fil.seekg(fil.tellp()-sizeof(U));
     fil.write((char*)&old1,sizeof(U));
     cout<<"\n\n\n\n\n\n\nSORRY!! That date is not available.";
     cout<<" Your booking has not been edited.";
     getch();
   }
  }
 }
}

void deleterec(mparadise &U)
{
 newscreen();
 fstream fil;
 fil.open("para.dat",ios::binary|ios::in|ios::out);
 mparadise temp;
 gotoxy(20,8);cout<<"Are you sure you want to cancel your bookings??";
 gotoxy(20,10);cout<<"1)Yes";
 gotoxy(20,11);cout<<"2)No";

 int y=10;char ch;
  gotoxy(20,10);
   do
   {
    ch=getch();
    if(ch==72 && y!=10)
    gotoxy(20,--y);
    else if(ch==80 && y!=11)
    gotoxy(20,++y);
   }while(ch!=13);
  switch(y)
  {
   case 10:{ U.delete1();
	     gotoxy(20,13);cout<<"Your bookings have been CANCELLED.";
	     getch();}
  }
 while(fil.read((char*)&temp,sizeof(temp)))
 {
 if(strcmp(U.rusername(),temp.rusername())==0)
  {
   fil.seekg(fil.tellp()-sizeof(U));
   fil.write((char*)&U,sizeof(U));
  }
 }
 fil.close();//function now continues in main.
}

int datekano(DATE d1)
{
 //1 jan 2016=1;
 int a;
 int b=d1.yyyy;
 int c=(b-2016)/4;//c will give leap year.
 int d=c*366+(b-2016-c)*365;
 if(b%4==0)
 {
 switch(d1.mm)
 {
  case 1:a=d+d1.dd;break;
  case 2:a=d+31+d1.dd;break;
  case 3:a=d+60+d1.dd;break;
  case 4:a=d+91+d1.dd;break;
  case 5:a=d+121+d1.dd;break;
  case 6:a=d+152+d1.dd;break;
  case 7:a=d+182+d1.dd;break;
  case 8:a=d+213+d1.dd;break;
  case 9:a=d+244+d1.dd;break;
  case 10:a=d+274+d1.dd;break;
  case 11:a=d+305+d1.dd;break;
  case 12:a=d+335+d1.dd;break;
  }
 }
 else
 {  switch(d1.mm)
 {
  case 1:a=d+d1.dd;break;
  case 2:a=d+31+d1.dd;break;
  case 3:a=d+59+d1.dd;break;
  case 4:a=d+90+d1.dd;break;
  case 5:a=d+120+d1.dd;break;
  case 6:a=d+151+d1.dd;break;
  case 7:a=d+181+d1.dd;break;
  case 8:a=d+212+d1.dd;break;
  case 9:a=d+243+d1.dd;break;
  case 10:a=d+273+d1.dd;break;
  case 11:a=d+304+d1.dd;break;
  case 12:a=d+334+d1.dd;break;
  }
 }

return a;
}

void sortfile()
{
mparadise F,S;
fstream fil;
fil.open("para.dat",ios::binary|ios::in|ios::out);

fil.seekg(0,ios::end);
int n= fil.tellp()/sizeof(F);

for (int i=0; i<n-1; i++)
 for(int j=0; j<n-i-1; j++)
  {
   fil.seekg(j*sizeof(F));
   fil.read((char*)&F, sizeof(F));
   fil.read((char*)&S, sizeof(S));
   if(F.rrno() > S.rrno())
    {
     fil.seekg(j*sizeof(F));
     fil.write((char*)&S, sizeof(S));
     fil.write((char*)&F, sizeof(F));
    }
  }
fil.close();
}

void check(mparadise &U)
{
 mparadise temp;
 sortfile();
 fstream fil;
 fil.open("para.dat", ios::binary|ios::in|ios::out);
  int a=U.rinidateno();
  int b=U.rfindateno();
  int rr,start,l=0;
   if(strcmp(U.rrtype(),"Penthouse Suite")==0)
  start=201;
  else
  if(strcmp(U.rrtype(),"Honeymoon Suite")==0)
  start=301;
  else
  if(strcmp(U.rrtype(),"Business Suite")==0)
  start=401;
  else
  if(strcmp(U.rrtype(),"Lounge")==0)
  start=501;
 while(fil.read((char*)&temp,sizeof(temp)))
 {
  int k=0;
  if(start+l==temp.rrno())
  {
   for(int i=a;i<=b && k==0;i++)
   {
    for( int j=temp.rinidateno();j<temp.rfindateno();j++)
    {
     if(i==j)
     k++;
    }
   }
  if(k!=0)
  l++;
 }
}

 if(l>=5)
 rr=0;
 else
 rr=start+l;

  U.giverno(rr);
 fil.close();
}

void viewfile(mparadise U)
{
 fstream fil;
 fil.open("para.dat",ios::binary|ios::in);
 mparadise temp;
 newscreen();
 cout<<endl;
 cout<<setw(10)<<"name"<<setw(10)<<"room no."<<setw(16)<<"initial date"
     <<setw(15)<<"final date"<<setw(21)<<"room type"<<endl<<endl;
 while(fil.read((char*)&temp,sizeof(temp)))
 {
  if(strcmp(U.rusername(),temp.rusername())==0)
  temp.display();
 }
  fil.close();
  getch();
}




