#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class fcbranch
{
    string fcid,fcname,city,buffer;
    public:
    void unpack();
    void read();
    void r_f();
    void w_f();
    void display();
    void pack();
    int del(string);
    int search(string);
    void modify(string);
}b;

void fcbranch::read()
{
    cout<<"Enter [fcid fcname city]\n";
    cin>>fcid>>fcname>>city;
}

void fcbranch::pack()
{
    buffer.erase();
    buffer+=fcid+"|"+fcname+"|"+city+"$\n";
}
void fcbranch::r_f()
{
    fstream fp;
    fp.open("fc1.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        unpack();
        if(!fp.eof() &&buffer[0]!='*')
        display();
    }
    fp.close();
}

void fcbranch::unpack()
{
int i=0;
fcid.erase();
while(buffer[i]!='|')
fcid+=buffer[i++];
i++;
fcname.erase();
while(buffer[i]!='|')
fcname+=buffer[i++];
i++;
city.erase();
while(buffer[i]!='$')
city+=buffer[i++];
}

void fcbranch::display()
{
cout<<"fcid:"<<fcid<<"\n"<<"fcname:"<<fcname<<"\n"<<"city:"<<city<<"\n"<<endl;
}

int fcbranch::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("fc1.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
recno++;
unpack();
if(fcid==regno)
{
cout<<"\n record is"<<buffer;
cout<<"\n record is found at position"<<recno;
cout<<"\n";
pos=fp.tellg();
flag=1;
return pos;
}
}
fp.close();



if(!flag)
cout<<"record not found\n";
return pos;
}

int fcbranch::del(string regno)
{

fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("fc1.txt",ios::in|ios::out);
pos-=2;
t=fp.get();
while(t!='$'&& pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();

}
if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
if(!flag)
return 0;
else
return 1;
}

void fcbranch::modify(string regno)
{

if(del(regno))
{
cout<<"\nEnter details[fcid,fcname,city]\n";
cin>>fcid>>fcname>>city;
buffer.erase();
pack();
w_f();
}
}

void fcbranch::w_f()
{
fstream fp;
fp.open("fc1.txt",ios::out|ios::app);
fp<<buffer;
fp.close();
}
//2nd class
class member
{
string membno,membname,membphone,fcid,buffer;
public:
void unpack();
void read();
void r_f();
void w_f();
void display();
void pack();
int del(string);
int search(string);
void modify(string);
}c;
void member::read()
{
cout<<"Enter details[membernumber,memberName,memberphone,fcid]\n";
cin>>membno>>membname>>membphone>>fcid;
}

void member::pack()
{
buffer.erase();
buffer+=membno+"|"+membname+"|"+membphone+"|"+fcid+"$\n";
}
void member::r_f()
{
fstream fp;
fp.open("m2.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
unpack();
if(!fp.eof()&&buffer[0]!='*')
display();
}
fp.close();
}
void member::unpack()
{
int i=0;
membno.erase();
while(buffer[i]!='|')
membno+=buffer[i++];
i++;
membname.erase();
while(buffer[i]!='|')
membname+=buffer[i++];
i++;
membphone.erase();
while(buffer[i]!='|')
membphone+=buffer[i++];
i++;
fcid.erase();
while(buffer[i]!='$')
fcid+=buffer[i++];
i++;
}

void member::display()
{
cout<<"memberNumber:"<<membno<<"\n"<<"membername:"<<membname<<"\n"<<"memberphone:"<<membphone<<"\n"<<"fcid:"<<fcid<<"\n"<<endl;
}

int member::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("m2.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
//if(buffer[0]!='*')
recno++;
unpack();
if(membno==regno)
{
cout<<"\nrecord is"<<buffer;
cout<<"\nRecord found at position"<<recno;
cout<<"\n";
pos=fp.tellg();
flag=1;
return pos;
}

}
fp.close();
if(!flag)
cout<<"Record not found\n";
return pos;
}

int member::del(string regno)
{
fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("m2.txt",ios::in|ios::out);
pos-=2;
//cout<<"deletion posin delto"<<pos;
t=fp.get();
while(t!='$'&&pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();
}



if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
if(!flag)
return 0;
else
return 1;
}

void member::modify(string regno)
{

if(del(regno))
{
cout<<"\nEnter details[membernumber,membername,memberphone,fcid]\n";
cin>>membno>>membname>>membphone>>fcid;
buffer.erase();
pack();
w_f();
}
}
void member::w_f()
{

fstream fp;
fp.open("m2.txt",ios::out|ios::app);
fp<<buffer;
fp.close();
}
//trainer
class trainer
{
string trid,trname,trphone,fcid,trsalary,buffer;
public:
void unpack();
void read();
void r_f();
void w_f();
void display();
void pack();
int del(string);
int search(string);
void modify(string);
}e;
void trainer::read()
{
cout<<"Enter details[trid trname trphone  trfcid trsalary]\n";
cin>>trid>>trname>>trphone>>fcid>>trsalary;
}

void trainer::pack()
{
buffer.erase();
buffer+=trid+"|"+trname+"|"+trphone+"|"+fcid+"|"+trsalary+"$\n";
}
void trainer::r_f()
{
fstream fp;
fp.open("t3.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
unpack();
if(!fp.eof()&&buffer[0]!='*')
display();
}
fp.close();
}
void trainer::unpack()
{
int i=0;
trid.erase();
while(buffer[i]!='|')
trid+=buffer[i++];
i++;
trname.erase();
while(buffer[i]!='|')
trname+=buffer[i++];
i++;
trphone.erase();
while(buffer[i]!='|')
trphone+=buffer[i++];
i++;
fcid.erase();
while(buffer[i]!='|')
fcid+=buffer[i++];
i++;
trsalary.erase();
while(buffer[i]!='$')
trsalary+=buffer[i++];
i++;
}
void trainer::display()
{

cout<<"trainerid:"<<trid<<"\n"<<"trname:"<<trname<<"\n"<<"trphone:"<<trphone<<"\n"<<"fcid:"<<fcid<<"\n"<<"trSalary:"<<trsalary<<"\n"<<endl;
}

int trainer::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("t3.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
//if(buffer[0]!='*')
recno++;
unpack();
if(trid==regno)
{
cout<<"\nrecord is"<<buffer;
cout<<"\nRecord found at position"<<recno;
cout<<"\n";
pos=fp.tellg();
flag=1;
return pos;
}
}
fp.close();
if(!flag)
cout<<"Record not found\n";
return pos;
}

int trainer::del(string regno)
{
fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("t3.txt",ios::in|ios::out);
pos-=2;
//cout<<"deletion posin delto"<<pos;
t=fp.get();
while(t!='$'&&pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();
}
if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
if(!flag)
return 0;
else
return 1;
}
void trainer::modify(string regno)
{

if(del(regno))
{
cout<<"Enter details[trid trname trphone trfcid trsalary]\n";
cin>>trid>>trname>>trphone>>fcid>>trsalary;
buffer.erase();
pack();
w_f();
}
}
void trainer::w_f()
{

fstream fp;
fp.open("t3.txt",ios::out|ios::app);
fp<<buffer;
fp.close();

}
//type
class type
{
string membid,fcid,cate,level,morning_evening,buffer;
public:
void unpack();
void read();
void r_f();
void w_f();
void display();
void pack();
int del(string);
int search(string);
void modify(string);
}a;
void type::read()
{
cout<<"Enter details[memberid fcid category level morning_evening]\n";
cin>>membid>>fcid>>cate>>level>>morning_evening;
}
void type::pack()
{
buffer.erase();
buffer+=membid+"|"+fcid+"|"+cate+"|"+level+"|"+morning_evening+"$\n";
}
void type::r_f()
{
fstream fp;
fp.open("ty4.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
unpack();
if(!fp.eof()&&buffer[0]!='*')
display();
}
fp.close();
}
void type::unpack()
{
int i=0;
membid.erase();
while(buffer[i]!='|')
membid+=buffer[i++];
i++;
fcid.erase();
while(buffer[i]!='|')
fcid+=buffer[i++];
i++;
cate.erase();
while(buffer[i]!='|')
cate+=buffer[i++];
i++;
level.erase();
while(buffer[i]!='|')
level+=buffer[i++];
i++;
morning_evening.erase();
while(buffer[i]!='$')
morning_evening+=buffer[i++];
i++;
}

void type::display()
{
cout<<"memberid:"<<membid<<"\n"<<"fcid:"<<fcid<<"\n"<<"category:"<<cate<<"\n"<<"level:"<<level<<"\n"<<"morning_evening:"<<morning_evening<<"\n"<<endl;
}
int type::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("ty4.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
if(buffer[0]!='*')
recno++;
unpack();
if(membid==regno)
{
cout<<"\nrecord is"<<buffer;
cout<<"\nRecord found at position"<<recno;
cout<<"\n";
pos=fp.tellg();
flag=1;
return pos;
}
}
fp.close();
if(!flag)
cout<<"Record not found\n";
return pos;
}

int type::del(string regno)
{
fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("ty4.txt",ios::in|ios::out);
pos-=2;
//cout<<"deletion posin delto"<<pos;
t=fp.get();
while(t!='$'&&pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();
}
if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
if(!flag)
return 0;
else
return 1;
}
void type::modify(string regno)
{
if(del(regno))
{
cout<<"\n Enter details[membid fcid category level morning_evening]\n";
cin>>membid>>fcid>>cate>>level>>morning_evening;
buffer.erase();
pack();
w_f();
}
}
void type::w_f()
{
fstream fp;
fp.open("ty4.txt",ios::out|ios::app);
fp<<buffer;
fp.close();
}
//payment
class payment
{
string membid,fcid,amount,paymenttype,buffer;
public:
void unpack();
void read();
void r_f();
void w_f();
void display();
void pack();
int del(string);
int search(string);
void modify(string);
}t;
void payment::read()
{
cout<<"Enter details[memberid fcid amount paymenttype]\n";
cin>>membid>>fcid>>amount>>paymenttype;
}

void payment::pack()
{
buffer.erase();
buffer+=membid+"|"+fcid+"|"+amount+"|"+paymenttype+"$\n";
}
void payment::r_f()
{
fstream fp;
fp.open("p5.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
unpack();
if(!fp.eof()&&buffer[0]!='*')
display();
}
fp.close();
}

void payment::unpack()
{
int i=0;
membid.erase();
while(buffer[i]!='|')
membid+=buffer[i++];
i++;
fcid.erase();
while(buffer[i]!='|')
fcid+=buffer[i++];
i++;
amount.erase();
while(buffer[i]!='|')
amount+=buffer[i++];
i++;
paymenttype.erase();
while(buffer[i]!='$')
paymenttype+=buffer[i++];
i++;
}

void payment::display()
{

cout<<"memberid:"<<membid<<"\n"<<"fcid:"<<fcid<<"\n"<<"Amount:"<<amount<<"\n"<<"paymenttype:"<<paymenttype<<"\n"<<endl;
}

int payment::search(string regno)
{
fstream fp;
int recno=0,flag=0,pos=0;
fp.open("p5.txt",ios::in);
while(!fp.eof())
{
buffer.erase();
getline(fp,buffer);
//if(buffer[0]!='*')
recno++;
unpack();
if(membid==regno)
{
cout<<"\nrecord is"<<buffer;
cout<<"\nRecord found at position"<<recno;
cout<<"\n";
pos=fp.tellg();
flag=1;
return pos;
}
}
fp.close();
if(!flag)
cout<<"Record not found\n";
return pos;
}

int payment::del(string regno)
{
fstream fp;
char mark='*',t;
int pos,flag=0;
pos=search(regno);
if(pos)
{
fp.open("p5.txt",ios::in|ios::out);
pos-=2;
//cout<<"deletion posin delto"<<pos;
t=fp.get();
while(t!='$'&&pos!=0)
{
pos--;
fp.seekp(pos,ios::beg);
t=fp.get();
}
if(pos!=0)
fp.seekp(pos+2,ios::beg);
else
fp.seekp(pos,ios::beg);
fp.put(mark);
flag=1;
}
fp.close();
if(!flag)
return 0;
else
return 1;
}

void payment::modify(string regno)
{

if(del(regno))
{
cout<<"Enter details[membid fcid amount,paymenttype]\n";
cin>>membid>>fcid>>amount>>paymenttype;
buffer.erase();
pack();
w_f();
}
}
void payment::w_f()
{

fstream fp;
fp.open("p5.txt",ios::out|ios::app);
fp<<buffer;
fp.close();

}
main()
{
string regno;
int ch,ch1,ch2,ch3,ch4,ch5;

cout<<"######################################################################\n";
cout<<"\n";
cout<<"\t\t \t\n";
cout<<"\n";
while(1)
{
cout<<"###################################################################\n";

cout<<"1.FitnessClubBranch\n2.Member\n3.Trainer\n4.Type\n5.Payment\n6.exit"<<endl;
cout<<"\n";
cout<<"Enter your choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:
do
{
cout<<"\n!!!!!!!!!!!!!!!!!!!!!!fitnessclubbranch Information!!!!!!!!!!!!!!!!!!!!!!!\n"<<endl;
cout<<"1.read records\n2.display record\n3.search record\n4.Modify record\n5.back to home\n";
cout<<"\n";
cout<<"enter your choice\n";
cin>>ch1;
switch(ch1)
{
case 1:
b.read();
b.pack();
b.w_f();
break;

case 2:
b.r_f();
break;
case 3:
cout<<"enter fcid number to search\n";
cin>>regno;
b.search(regno);
break;
case 4:
cout<<"Enter fcid to modify\n";
cin>>regno;
b.modify(regno);
break;
default:
break;
}
}while(ch1<5);
break;

case 2:
do
{
cout<<"!!!!!!!!!!!!!!!!!!!!!!! member Information!!!!!!!!!!!!!!!!!!!!!"<<endl;
cout<<"1.read records\n2.display record\n3.search record\n4.Modify record\n5.back to home\n";
cout<<"\n";
cout<<"enter your choice\n";
cin>>ch2;
switch(ch2)
{
case 1:
c.read();
c.pack();
c.w_f();
break;

case 2:
c.r_f();
break;
case 3:
cout<<"enter memberno number to search\n";
cin>>regno;
c.search(regno);
break;
case 4:
cout<<"Enter memberno to modify\n";
cin>>regno;
c.modify(regno);
break;
default:
break;
}
}while(ch2<5);
break;
case 3:
do
{
cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!trainer Information!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
cout<<"1.read records\n2.Display record\n3.Search record\n4.Modify record\n5.back to home\n";
cout<<"\n";
cout<<"enter your choice\n";
cin>>ch3;
switch(ch3)
{
case 1:
e.read();
e.pack();
e.w_f();
break;

case 2:
e.r_f();
break;
case 3:
cout<<"enter trainerid to search\n";
cin>>regno;
e.search(regno);
break;
case 4:
cout<<"Enter trainerid to modify\n";
cin>>regno;
e.modify(regno);
break;
default:
break;
}
}while(ch3<5);
break;

case 4:
do
{
cout<<"!!!!!!!!!!!!!!!!!!!!!!!! type Information!!!!!!!!!!!!!!!!!!!!!"<<endl;
cout<<"1.Read records\n2.Display record\n3.Search record\n4.Modify record\n5.Back to home\n";
cout<<"\n";
cout<<"Enter your choice\n";
cin>>ch4;
switch(ch4)
{
case 1:
a.read();
a.pack();
a.w_f();
break;
case 2:
a.r_f();
break;
case 3:
cout<<"Enter membid number to search\n";
cin>>regno;
a.search(regno);
break;
case 4:
cout<<"Enter membid to modify\n";
cin>>regno;
a.modify(regno);
break;
default:
break;
}
}while(ch4<5);
break;
case 5:
do
{
cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!! Payment Information!!!!!!!!!!!!!!!!!!"<<endl;
cout<<"1.Read records\n2.Display record\n3.Search record\n4.Modify record\n5.Back to home\n";
cout<<"\n";
cout<<"Enter your choice\n";
cin>>ch5;
switch(ch5)
{
case 1:
t.read();
t.pack();
t.w_f();
break;

case 2:
t.r_f();
break;
case 3:
cout<<"Enter memberid number to search\n";
cin>>regno;
t.search(regno);
break;
case 4:
cout<<"Enter memberid to modify\n";
cin>>regno;
t.modify(regno);
break;
default:
break;
}
}while(ch5<5);
break;
default:
exit(0);
break;
}
}
}
