			     //SOURCE CODE
//***************************************************************************
//               PROJECT ON LAWFIRM MANGEMENT SYSTEM
//***************************************************************************

//***************************************************************************
//     HEADER FILES USED IN PROJECT
//***************************************************************************

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<graphics.h>

//***************************************************************************
//     STRUCTURES USED IN PROJECT
//***************************************************************************

struct employee
{
	char e_name[40];
	char e_designation[40];
	int e_age;
	char e_emailid[80];
	char e_phno[15];
};

struct client
{
	float ID;
	char cl_name[40];
	char cl_ars[80];
	int cl_age;
	char cl_emailid[80];
	char cl_phno[15];
};

struct casefile
{
	int d1,m1,y1;
	int d2,m2,y2;
	float ID;
	int c_no;
	char court_name[20];
	char c_name[40];
	char c_nextstage[10];
	char c_description[80];
};


//***************************************************************************
//     CLASS USED IN PROJECT
//***************************************************************************


class lawfirm
{
	employee emp;
	client cl;
	casefile csf;

  public:
	void employe();    //to enter employee's details
	void emp_edit();   //to edit employee's details
	void emp_delete(); //to delete employee's details
	void emp_search(); //to search a particular employee's record

	void clients();    //to enter client's details
	void cl_edit();    //to edit client's details
	void cl_delete();  //to delete client's details
	void cl_search();  //to search a client's personal & case details

	void casefil();    //to enter a case details
	void csf_edit();   //to edit a case details
	void csf_delete(); //to delete a case details
	void csf_search(); //to search for a particular case details

	void law_date();   //to search for date wise cases
	void law_month();  //to search for month wise cases
	void frontpage();  //to add graphics to the front page
	void design();     //to add graphics

	void case1();      //nested switch of main case 1
	void case2();      //nested switch of main case 2
	void case3();      //nested switch of main case 3

};     //class ends here


//***************************************************************************
//     FUNCTION TO ADD GRAPHICS TO FRONT PAGE
//***************************************************************************

void lawfirm::frontpage()
{
	setbkcolor(BROWN);
	for(int i=15;i<630;i+=9)
	{
		setcolor(YELLOW);
		setlinestyle(0,0,3);
		circle(i,5,4);
		circle(i,473,4);
	}

	for(i=15;i<470;i+=9)
	{
		setcolor(YELLOW);
		setlinestyle(0,0,3);
		circle(15,i,4);
		circle(628,i,4);
	}

	setcolor(LIGHTRED);
	settextstyle(1,0,5);
	outtextxy(180,100,"WELCOME TO");
	outtextxy(90,170,"LAWFIRM MANAGEMENT");
	outtextxy(230,220,"SYSTEM");

	{
		setcolor(RED);
		settextstyle(0,0,0);
		outtextxy(250,450,"PRESS ANY KEY");
	}

	getch();
	cleardevice();
}


//***************************************************************************
//     FUNCTION TO ADD GRAPHICS
//***************************************************************************

void lawfirm::design()
{
  cleardevice();
	setbkcolor(LIGHTBLUE);
	setcolor(GREEN);
	rectangle(5,10,620,475);
	rectangle(15,20,610,465);

	for(int i=5;i<615;i+=5)
		line(i,20,i+10,10);

	for(i=15;i<625;i+=5)
		line(i,465,i-10,475);

	for(i=10;i<470;i+=5)
		line(15,i,5,i+10);

	for(i=10;i<470;i+=5)
		line(620,i,610,i+10);
}


//***************************************************************************
//     FUNCTION TO ENTER EMPLOYEE'S DETAILS
//***************************************************************************

void lawfirm::employe()
{
  int size;
	design();
	gotoxy(18,4);cout<<"ENTER NO OF EMPLOYEES";
	gotoxy(18,6);cin>>size;
	ofstream outfile("employee.dat",ios::binary|ios::app);

		for(int i=0;i<size;i++)
		{
			design();
			gotoxy(14,4);cout<<"ENTER NAME";
			gotoxy(34,4);gets(emp.e_name);
			gotoxy(14,6);cout<<"ENTER DESIGNATION";
			gotoxy(34,6);gets(emp.e_designation);
			gotoxy(14,8);cout<<"ENTER AGE";
			gotoxy(34,8);cin>>emp.e_age;
			gotoxy(14,10);cout<<"ENTER EMAIL ID";
			gotoxy(34,10);gets(emp.e_emailid);
			gotoxy(14,12);cout<<"ENTER PHONE NO";
			gotoxy(34,12);cin>>emp.e_phno;
			outfile.write((char*)&emp,sizeof(employee));
			cleardevice();
		}
	outfile.close();
}


//***************************************************************************
//     FUNCTION TO MODIFY EMPLOYEE'S RECORD
//***************************************************************************

void lawfirm::emp_edit()
{
   char name[40],res;
   long pos;
   int ch,flag=0;
	fstream file("employee.dat",ios::in|ios::out|ios::binary);

   {
	design();
	gotoxy(14,6);cout<<"ENTER NAME OF EMPLOYEE WHOSE RECORD HAS TO BE EDITED";
	gotoxy(14,8);gets(name);
   }
   while(!file.eof())
   {
		design();
		flag=1;
		pos=file.tellg();
		file.read((char*)&emp,sizeof(employee));
		if(file.eof())
		break;
		if(strcmpi(emp.e_name,name)==0)
	{
	 yy:
	design();
	setcolor(LIGHTRED);
	settextstyle(1,0,5);
	outtextxy(250,20,"MENU");
		gotoxy(18,8);cout<<"1. TO EDIT NAME:";
		gotoxy(45,8);cout<<emp.e_name;
		gotoxy(18,10);cout<<"2. TO EDIT DESIGNATION:";
		gotoxy(45,10);cout<<emp.e_designation;
		gotoxy(18,12);cout<<"3. TO EDIT AGE:";
		gotoxy(45,12);cout<<emp.e_age;
		gotoxy(18,14);cout<<"4. TO EDIT EMAIL ID:";
		gotoxy(45,14);cout<<emp.e_emailid;
		gotoxy(18,16);cout<<"5. TO EDIT PNONE NO:";
		gotoxy(45,16);cout<<emp.e_phno;
		gotoxy(18,18);cout<<"6. TO EXIT:";
		gotoxy(18,21);cout<<"ENTER YOUR CHOICE(1-6):";
		gotoxy(45,21);cin>>ch;

   switch(ch)
   {
   case 1:
		gotoxy(18,23);cout<<"ENTER NAME : ";
		gotoxy(45,23);gets(emp.e_name);
		break;

   case 2:      gotoxy(18,23);cout<<"ENTER DESIGNATION : ";
		gotoxy(45,23);gets(emp.e_designation);
		break;

   case 3:
		gotoxy(18,23);cout<<"ENTER AGE : ";
		gotoxy(45,23);cin>>emp.e_age;
		break;

   case 4:
		gotoxy(18,23);cout<<"ENTER EMAIL ID : ";
		gotoxy(45,23);gets(emp.e_emailid);
		break;

   case 5:
		gotoxy(18,23);cout<<"ENTER PHONE NO : ";
		gotoxy(45,23);cin>>emp.e_phno;
		break;

   case 6:
		return;
   }
	file.seekp(pos,ios::beg);
	file.write((char*)&emp,sizeof(employee));
	gotoxy(18,25);cout<<"DO YOU WANT TO MODIFY ANYTHING MORE? (Y/N) :";
	cin>>res;
	if(res=='y' || res=='Y')
	goto yy;
	break;
	}
   }

	if(flag==0)
	{
		design();
		gotoxy(18,8);cout<<"RECORD NOT FOUND";
	}
	file.close();
}


//***************************************************************************
//     FUNCTION TO DELETE EMPLOYEE'S RECORD
//***************************************************************************

void lawfirm::emp_delete()
{
	char name[40];
	ifstream infile("employee.dat",ios::binary);
	ofstream outfile("temp.dat",ios::binary);

	{
		design();
		gotoxy(18,8);cout<<"ENTER NAME OF EMPLOYEE TO DELETE THE RECORD";
		gotoxy(18,10);gets(name);
	}

	while(!infile.eof())
	{
		infile.read((char*)&emp,sizeof(employee));
		if(infile.eof())
		break;
		if(strcmpi(emp.e_name,name)!=0)
		outfile.write((char*)&emp,sizeof(employee));
	}
	infile.close();
	outfile.close();

	remove("employee.dat");
	rename("temp.dat","employee.dat");
}


//***************************************************************************
//     FUNCTION TO READ SPECIFIC EMPLOYEE'S RECORD
//***************************************************************************

void lawfirm::emp_search()
{
   char name[40];
	ifstream infile("employee.dat",ios::binary);
	if(!infile)
	{
		design();
		cout<<"FILE NOT FOUND";
		exit(0);
	}

	{
		design();
		gotoxy(18,8);cout<<"ENTER NAME OF EMPLOYEE TO DISPLAY THE RECORD";
		gotoxy(18,10);gets(name);
		cleardevice();
	}

	while(!infile.eof())
	{
		infile.read((char*)&emp,sizeof(employee));
		if(infile.eof())
		break;
	  if(strcmpi(emp.e_name,name)==0)
	{
		design();
		gotoxy(14,4);cout<<"NAME:";
		gotoxy(34,4);cout<<emp.e_name;
		gotoxy(14,6);cout<<"DESIGNATION:";
		gotoxy(34,6);cout<<emp.e_designation;
		gotoxy(14,8);cout<<"AGE:";
		gotoxy(34,8);cout<<emp.e_age;
		gotoxy(14,10);cout<<"EMAIL ID:";
		gotoxy(34,10);cout<<emp.e_emailid;
		gotoxy(14,12);cout<<"PHONE NO:";
		gotoxy(34,12);cout<<emp.e_phno;
		break;
	}
	}
   infile.close();
}




//***************************************************************************
//     FUNCTION TO ENTER CLIENT'S DETAILS
//***************************************************************************

void lawfirm::clients()
{
   int size;
	design();
	gotoxy(18,4);cout<<"ENTER NO OF CLIENTS";
	gotoxy(18,6);cin>>size;
	ofstream outfile("client.dat",ios::binary|ios::app);

		for(int i=0;i<size;i++)
	{
		cleardevice();
		design();
		gotoxy(14,4);cout<<"ENTER CLIENT'S ID";
		gotoxy(38,4);cin>>cl.ID;
		gotoxy(14,6);cout<<"ENTER NAME";
		gotoxy(38,6);gets(cl.cl_name);
		gotoxy(14,8);cout<<"ENTER ADDRESS";
		gotoxy(38,8);gets(cl.cl_ars);
		gotoxy(14,10);cout<<"ENTER AGE";
		gotoxy(38,10);cin>>cl.cl_age;
		gotoxy(14,12);cout<<"ENTER EMAIL ID";
		gotoxy(38,12);gets(cl.cl_emailid);
		gotoxy(14,14);cout<<"ENTER PHONE NO";
		gotoxy(38,14);cin>>cl.cl_phno;
		outfile.write((char*)&cl,sizeof(client));
	}
   outfile.close();

       gotoxy(14,17);cout<<"NOW ENTER DETAILS OF CASEFILE OF CLIENT(S)"<<endl;
}


//***************************************************************************
//     FUNCTION TO EDIT CLIENT'S RECORD
//***************************************************************************

void lawfirm::cl_edit()
{
    char name[40],res;
    long pos;
    int ch,flag=0;
	fstream file("client.dat",ios::in|ios::out|ios::binary);
	{
		design();
		gotoxy(14,6);cout<<"ENTER NAME OF CLIENT WHOSE RECORD HAS TO BE EDITED";
		gotoxy(14,8);gets(name);
	}
	while(!file.eof())
	{
			design();
			flag=1;
			pos=file.tellg();
			file.read((char*)&cl,sizeof(client));
			if(file.eof())
			break;
			if(strcmpi(cl.cl_name,name)==0)
	   {
	   yy:
	   cleardevice();
	   design();
	   setcolor(LIGHTRED);
	   settextstyle(1,0,5);
	   outtextxy(250,20,"MENU");
			gotoxy(18,8);cout<<"1. TO EDIT NAME:";
			gotoxy(45,8);cout<<cl.cl_name;
			gotoxy(18,10);cout<<"2. TO EDIT ADDRESS:";
			gotoxy(45,10);cout<<cl.cl_ars;
			gotoxy(18,12);cout<<"3. TO EDIT AGE:";
			gotoxy(45,12);cout<<cl.cl_age;
			gotoxy(18,14);cout<<"4. TO EDIT EMAIL ID:";
			gotoxy(45,14);cout<<cl.cl_emailid;
			gotoxy(18,16);cout<<"5. TO EDIT PNONE NO:";
			gotoxy(45,16);cout<<cl.cl_phno;
			gotoxy(18,18);cout<<"6. TO EXIT:";
			gotoxy(18,21);cout<<"ENTER YOUR CHOICE(1-6):";
			gotoxy(45,21);cin>>ch;
    switch(ch)
    {
    case 1:
		gotoxy(18,23);cout<<"ENTER NAME";
		gotoxy(45,23);gets(cl.cl_name);
		break;

    case 2:
		gotoxy(18,23);cout<<"ENTER ADDRESS";
		gotoxy(45,23);gets(cl.cl_ars);
		break;

    case 3:
		gotoxy(18,23);cout<<"ENTER AGE";
		gotoxy(45,23);cin>>cl.cl_age;
		break;

    case 4:
		gotoxy(18,23);cout<<"ENTER EMAIL ID";
		gotoxy(45,23);gets(cl.cl_emailid);
		break;

    case 5:
		gotoxy(18,23);cout<<"ENTER PHONE NO";
		gotoxy(45,23);cin>>cl.cl_phno;
		break;

    case 6:
		return;
    }

	 file.seekp(pos,ios::beg);
	 file.write((char*)&cl,sizeof(client));
	 gotoxy(18,25);cout<<"DO YOU WANT TO MODIFY ANYTHING MORE? (Y/N) : ";
	 cin>>res;
	 if(res=='y'||res=='Y')
	 goto yy;
	 break;
	 }
    }
	if(flag==0)
	{
		design();
		gotoxy(18,8);cout<<"RECORD NOT FOUND";
	}
	file.close();
}


//***************************************************************************
//     FUNCTION TO DELETE CLIENT'S RECORD
//***************************************************************************

void lawfirm::cl_delete()
{
     char name[40];
	ifstream infile("client.dat",ios::binary);
	ofstream outfile("temp.dat",ios::binary);
     {
	design();
	gotoxy(18,8);cout<<"ENTER NAME OF CLIENT TO DELETE THE RECORD";
	gotoxy(18,10);gets(name);
     }

	while(!infile.eof())
     {
	infile.read((char*)&cl,sizeof(client));
	if(infile.eof())
	break;
	if(strcmpi(cl.cl_name,name)!=0)
	outfile.write((char*)&cl,sizeof(client));
     }
	infile.close();
	outfile.close();

     remove("client.dat");
     rename("temp.dat","client.dat");
}


//***************************************************************************
//     FUNCTION TO READ SPECIFIC CLIENT'S RECORD INCLUDING CASEFILE
//***************************************************************************
void lawfirm::cl_search()
{
    float temp;
	ifstream infile,infile1;
	infile.open("client.dat",ios::binary);
	infile1.open("casefile.dat",ios::binary);
	if(!infile)
    {
	design();
	cout<<"FILE NOT FOUND";
	exit(0);
    }
    {
	design();
	gotoxy(18,8);cout<<"ENTER CLIENT'S ID TO DISPLAY THE RECORD";
	gotoxy(18,10);cin>>temp;
	cleardevice();
	design();
    }
	while(!infile.eof())
    {
	infile.read((char*)&cl,sizeof(client));
	if(infile.eof())
	break;
	if(cl.ID==temp)
	{
		gotoxy(14,4);cout<<"CLIENT'S ID:";
		gotoxy(38,4);cout<<cl.ID;
		gotoxy(14,6);cout<<"NAME:";
		gotoxy(38,6);cout<<cl.cl_name;
		gotoxy(14,8);cout<<"ADDRESS:";
		gotoxy(38,8);cout<<cl.cl_ars;
		gotoxy(14,10);cout<<"AGE:";
		gotoxy(38,10);cout<<cl.cl_age;
		gotoxy(14,12);cout<<"EMAIL ID:";
		gotoxy(38,12);cout<<cl.cl_emailid;
		gotoxy(14,14);cout<<"PHONE NO:";
		gotoxy(38,14);cout<<cl.cl_phno;
		break;
	}
    }
	infile.close();

	while(!infile1.eof())
    {
	infile.read((char*)&csf,sizeof(casefile));
	if(infile1.eof())
	break;
	if(csf.ID==temp)
	{
		gotoxy(14,16);cout<<"PREVIOUS HEARING DATE:";
		gotoxy(38,16);cout<<csf.d1<<"/"<<csf.m1<<"/"<<csf.y1;
		gotoxy(14,18);cout<<"NEXT HEARING DATE:";
		gotoxy(38,18);cout<<csf.d2<<"/"<<csf.m2<<"/"<<csf.y2;
		gotoxy(14,20);cout<<"CLIETN'S NAME(VS):";
		gotoxy(38,20);cout<<csf.c_name;
		gotoxy(14,22);cout<<"CASE NO:";
		gotoxy(38,22);cout<<csf.c_no;
		gotoxy(14,24);cout<<"CASE DESCRIPTION:";
		gotoxy(38,24);cout<<csf.c_description;
		break;
	}
    }
	infile1.close();
}



//***************************************************************************
//     FUNCTION TO WRITE CASE DETAILS
//***************************************************************************

void lawfirm::casefil()
{
   int size;
	design();
	gotoxy(18,4);cout<<"ENTER NO OF CASES";
	gotoxy(18,6);cin>>size;

	ofstream outfile("casefile.dat",ios::binary|ios::app);

	for(int i=0;i<size;i++)
   {
	cleardevice();
	design();
	gotoxy(14,4);cout<<"ENTER CLIENT'S ID";
	gotoxy(44,4);cin>>csf.ID;
	gotoxy(14,6);cout<<"ENTER PREVIOUS HEARING DATE";
	gotoxy(44,6);cout<<"- /- /-";
	gotoxy(44,6);cin>>csf.d1;
	gotoxy(46,6);cout<<"/";cin>>csf.m1;
	gotoxy(49,6);cout<<"/";cin>>csf.y1;
	gotoxy(14,8);cout<<"ENTER CASE NUMBER";
	gotoxy(44,8);cin>>csf.c_no;
	gotoxy(14,10);cout<<"ENTER COURT NAME";
	gotoxy(44,10);gets(csf.court_name);
	gotoxy(14,12);cout<<"ENTER CLIENT'S NAME(VS)";
	gotoxy(44,12);gets(csf.c_name);
	gotoxy(14,14);cout<<"ENTER NEXT STAGE";
	gotoxy(44,14);gets(csf.c_nextstage);
	gotoxy(14,16);cout<<"ENTER NEXT HEARING DATE";
	gotoxy(44,16);cout<<"- /- /-";
	gotoxy(44,16);cin>>csf.d2;
	gotoxy(46,16);cout<<"/";cin>>csf.m2;
	gotoxy(49,16);cout<<"/";cin>>csf.y2;
	gotoxy(14,18);cout<<"ENTER CASE DESCRIPTION";
	gotoxy(44,18);gets(csf.c_description);
	outfile.write((char*)&csf,sizeof(casefile));
   }
	outfile.close();
}


//***************************************************************************
//     FUNCTION TO UPDATE CASE RECORD
//***************************************************************************

void lawfirm::csf_edit()
{
    char res,ch;
    int temp;
    long pos;
    int flag=0;
	fstream file("casefile.dat",ios::in|ios::out|ios::binary);
    {
	design();
	gotoxy(14,6);cout<<"ENTER CASE NO WHOSE RECORD HAS TO BE UPDATED";
	gotoxy(14,8);cin>>temp;
    }
    while(!file.eof())
    {
		design();
		flag=1;
		pos=file.tellg();
		file.read((char*)&csf,sizeof(casefile));
		if(file.eof())
		break;
		if(csf.c_no==temp)
       {
	 yy:
	 design();
	 settextstyle(1,0,5);

		gotoxy(14,4);cout<<"CLIENT'S ID:";
		gotoxy(48,4);cout<<csf.ID;
		gotoxy(14,6);cout<<"PREVIOUS HEARING DATE:";
		gotoxy(48,6);cout<<csf.d1<<"/"<<csf.m1<<"/"<<csf.y1;
		gotoxy(14,8);cout<<"NEXT HEARING DATE:";
		gotoxy(48,8);cout<<csf.d2<<"/"<<csf.m2<<"/"<<csf.y2;
		gotoxy(14,10);cout<<"CASE NUMBER:";
		gotoxy(48,10);cout<<csf.c_no;
		gotoxy(14,12);cout<<"COURT NAME:";
		gotoxy(48,12);cout<<csf.court_name;
		gotoxy(14,14);cout<<"NAME OF PARTY:";
		gotoxy(48,14);cout<<csf.c_name;
		gotoxy(14,16);cout<<"NEXT STAGE:";
		gotoxy(48,16);cout<<csf.c_nextstage;
		gotoxy(14,18);cout<<"CASE DESCRIPTION:";
		gotoxy(48,18);cout<<csf.c_description;
		gotoxy(18,20);cout<<"DO YOU WANT TO UPDATE THIS RECORD? (Y/N): ";
			      cin>>ch;
			if(ch=='y'||ch=='Y')
       {
		csf.d1=csf.d2;
		csf.m1=csf.m2;
		csf.y1=csf.y2;
		gotoxy(18,22);cout<<"ENTER NEXT HEARING DATE";
		gotoxy(48,22);cout<<"- /- /-";
		gotoxy(48,22);cin>>csf.d2;
		gotoxy(50,22);cout<<"/";cin>>csf.m2;
		gotoxy(53,22);cout<<"/";cin>>csf.y2;


		gotoxy(18,24);cout<<"ENTER NEXT STAGE";
		gotoxy(48,24);gets(csf.c_nextstage);

		file.seekp(pos,ios::beg);
		file.write((char*)&csf,sizeof(casefile));

       }
		else
		return;
    }
		}
	if(flag==0)
    {
	design();
	gotoxy(18,8);cout<<"RECORD NOT FOUND";
    }
	file.close();
}


//***************************************************************************
//     FUNCTION TO ELIMINATE A CASE RECORD
//***************************************************************************

void lawfirm::csf_delete()
{
    int temp;
	ifstream infile("casefile.dat",ios::binary);
	ofstream outfile("temp.dat",ios::binary);
    {
	design();
	gotoxy(18,8);cout<<"ENTER CASE NUMBER TO DELETE THE RECORD";
	gotoxy(18,10);cin>>temp;
    }
	while(!infile.eof())
    {
	infile.read((char*)&csf,sizeof(casefile));
	if(infile.eof())
	break;
	if(csf.c_no!=temp)
	outfile.write((char*)&emp,sizeof(employee));
    }
	infile.close();
	outfile.close();

	remove("casefile.dat");
	rename("temp.dat","casefile.dat");
}


//***************************************************************************
//     FUNCTION TO READ SPECIFIC CASE RECORD
//***************************************************************************

void lawfirm::csf_search()
{
	int temp;
	ifstream infile("casefile.dat",ios::binary);
		if(!infile)
	{
		design();
		cout<<"FILE NOT FOUND";
		exit(0);
	}

	{
		design();
		gotoxy(18,8);cout<<"ENTER CASE NUMBER TO DISPLAY THE RECORD";
		gotoxy(18,10);cin>>temp;
		cleardevice();
	}

	while(!infile.eof())
	{
		infile.read((char*)&csf,sizeof(casefile));
		if(infile.eof())
		break;
		if(csf.c_no==temp)
	   {
		design();
		gotoxy(14,4);cout<<"PREVIOUS HEARING DATE:";
		gotoxy(38,4);cout<<csf.d1<<"/"<<csf.m1<<"/"<<csf.y1;
		gotoxy(14,6);cout<<"CASE NUMBER:";
		gotoxy(38,6);cout<<csf.c_no;
		gotoxy(14,8);cout<<"COURT NAME:";
		gotoxy(38,8);cout<<csf.court_name;
		gotoxy(14,10);cout<<"CLIENT'S NAME(VS):";
		gotoxy(38,10);cout<<csf.c_name;
		gotoxy(14,12);cout<<"NEXT STAGE:";
		gotoxy(38,12);cout<<csf.c_nextstage;
		gotoxy(14,14);cout<<"NEXT HEARING DATE:";
		gotoxy(38,14);cout<<csf.d2<<"/"<<csf.m2<<"/"<<csf.y2;
		gotoxy(14,16);cout<<"CASE DESCRIPTION:";
		gotoxy(38,16);cout<<csf.c_description;
	break;
	   }
	}
	infile.close();
}



//***************************************************************************
//     FUNCTION TO DISPLAY DATE WISE LIST OF CASES
//***************************************************************************

void lawfirm::law_date()
{
  int date,month,year;
  float temp;
  int x=6;
		gotoxy(18,6);cout<<"ENTER THE HEARING DATE";
		gotoxy(44,6);cout<<"- /- /-";
		gotoxy(44,6);cin>>date;
		gotoxy(46,6);cout<<"/";cin>>month;
		gotoxy(49,6);cout<<"/";cin>>year;
		cleardevice();
		design();

		ifstream infile,infile1;
		infile.open("casefile.dat",ios::binary);
		infile1.open("client.dat",ios::binary);
		if(!infile)
	{
		design();
		cout<<"FILE NOT FOUND";
		exit(0);
	}
		gotoxy(6,3);cout<<"PREVIOUS";
		gotoxy(7,4);cout<<"DATE";
		gotoxy(17,3);cout<<"CASE";
		gotoxy(18,4);cout<<"NO";
		gotoxy(24,3);cout<<"NAME OF";
		gotoxy(24,4);cout<<"COURT";
		gotoxy(35,3);cout<<"NAME OF";
		gotoxy(35,4);cout<<"PARTY (VS)";
		gotoxy(48,3);cout<<"NAME OF";
		gotoxy(48,4);cout<<"CLIENT";
		gotoxy(58,3);cout<<"NEXT";
		gotoxy(58,4);cout<<"STAGE";
		gotoxy(66,3);cout<<"CLIENT'S";
		gotoxy(66,4);cout<<"ID";

		while(!infile.eof())
	{
		infile.read((char*)&csf,sizeof(casefile));
		if(infile.eof())
		break;
		if(date==csf.d2 && month==csf.m2 && year==csf.y2)
	{
		gotoxy(6,x);cout<<csf.d1<<"/"<<csf.m1<<"/"<<csf.y1;
		gotoxy(17,x);cout<<csf.c_no;
		gotoxy(24,x);cout<<csf.court_name;
		gotoxy(35,x);cout<<csf.c_name;
		gotoxy(58,x);cout<<csf.c_nextstage;
		gotoxy(70,x);cout<<csf.ID;
		temp=csf.ID;
		infile1.seekg(0);
		while(!infile1.eof())
	{
		infile1.read((char*)&cl,sizeof(client));
		if(infile1.eof())
		break;
		if(temp==cl.ID)
	{
		gotoxy(48,x);cout<<cl.cl_name;
		break;
	}
	}
		x++;
	}
 }
	infile.close();
	infile1.close();
}



//***************************************************************************
//     FUNCTION TO DISPLAY MONTH WISE LIST OF CASES
//***************************************************************************

void lawfirm::law_month()
{
   int month,year;
   float temp;
   int x=6;
		gotoxy(18,6);cout<<"ENTER THE MONTH AND YEAR";
		gotoxy(44,6);cout<<"- /-";
		gotoxy(44,6);cin>>month;
		gotoxy(46,6);cout<<"/";cin>>year;
		cleardevice();
		design();

		ifstream infile,infile1;
		infile.open("casefile.dat",ios::binary);
		infile1.open("client.dat",ios::binary);
		if(!infile)
	{
		design();
		cout<<"FILE NOT FOUND";
		exit(0);
	}
		gotoxy(6,3);cout<<"PREVIOUS";
		gotoxy(7,4);cout<<"DATE";
		gotoxy(17,3);cout<<"CASE";
		gotoxy(18,4);cout<<"NO";
		gotoxy(24,3);cout<<"NAME OF";
		gotoxy(24,4);cout<<"COURT";
		gotoxy(35,3);cout<<"NAME OF";
		gotoxy(35,4);cout<<"PARTY (VS)";
		gotoxy(48,3);cout<<"NAME OF";
		gotoxy(48,4);cout<<"CLIENT";
		gotoxy(58,3);cout<<"NEXT";
		gotoxy(58,4);cout<<"STAGE";
		gotoxy(66,3);cout<<"CLIENT'S";
		gotoxy(66,4);cout<<"ID";

		while(!infile.eof())
	{
		infile.read((char*)&csf,sizeof(casefile));
		if(infile.eof())
		break;
		if(month==csf.m2 && year==csf.y2)
	{
		gotoxy(6,x);cout<<csf.d1<<"/"<<csf.m1<<"/"<<csf.y1;
		gotoxy(17,x);cout<<csf.c_no;
		gotoxy(24,x);cout<<csf.court_name;
		gotoxy(35,x);cout<<csf.c_name;
		gotoxy(58,x);cout<<csf.c_nextstage;
		gotoxy(66,x);cout<<csf.ID;
		temp=csf.ID;
		infile1.seekg(0);
		while(!infile1.eof())
	{
		infile1.read((char*)&cl,sizeof(client));
		if(infile1.eof())
		break;
		if(temp==cl.ID)
	{
		gotoxy(48,x);cout<<cl.cl_name;
		break;
	}
	}
		x++;
	}
 }
	infile.close();
	infile1.close();
}



//***************************************************************************
//     FUNCTION WITH NESTED SWITCH OF MAIN CASE 1
//***************************************************************************

void lawfirm::case1()
{
  int ch;
		cleardevice();
		design();
		setcolor(LIGHTRED);
		settextstyle(1,0,5);
		outtextxy(250,20,"MENU");
		gotoxy(18,8);cout<<"1. ENTER EMPLOYEE'S DETAILS";
		gotoxy(18,10);cout<<"2. EDIT EMPLOYEES'S DETAILS";
		gotoxy(18,12);cout<<"3. DELETE EMPLOYEE'S DETAILS";
		gotoxy(18,14);cout<<"4. SEARCH EMPLOYEE'S DETAILS";
		gotoxy(18,16);cout<<"5. TO EXIT";
		gotoxy(18,19);cout<<"ENTER YOUR CHOICE(1-5):";
		gotoxy(45,19);cin>>ch;
  switch(ch)
  {
	case 1:
	{
		design();
		employe();    //to enter employee's details
		break;
	}
	case 2:
	{
		design();
		emp_edit();   //to edit employee's details
		break;
	}
	case 3:
	{
		design();
		emp_delete(); //to delete employee's details
		break;
	}
	case 4:
	{
		design();
		emp_search(); //to search a particular employee's record
		break;
	}
	case 5:
		return;
	}
  }



//***************************************************************************
//     FUNCTION WITH NESTED SWITCH OF MAIN CASE 2
//***************************************************************************

void lawfirm::case2()
{
		design();
		int ch;
		setcolor(LIGHTRED);
		settextstyle(1,0,5);
		outtextxy(250,20,"MENU");
		gotoxy(18,8);cout<<"1. ENTER CLIENT'S DETAILS";
		gotoxy(18,10);cout<<"2. EDIT CLIENT'S DETAILS";
		gotoxy(18,12);cout<<"3. DELETE CLIENT'S DETAILS";
		gotoxy(18,14);cout<<"4. SEARCH CLIENT'S DETAILS";
		gotoxy(18,16);cout<<"5. TO EXIT";
		gotoxy(18,19);cout<<"ENTER YOUR CHOICE(1-5):";
		gotoxy(45,19);cin>>ch;
	switch(ch)
	{
		case 1:
		{
			design();
			clients();     //to enter client's details
			break;
		}
		case 2:
		{
			design();
			cl_edit();    //to edit client's details
			break;
		}
		case 3:
		{
			design();
			cl_delete();  //to delete client's details
			break;
		}
		case 4:
		{
			design();
			cl_search();  //to search a particular client's details
			break;
		}
		case 5:
			return;
	}

}



//***************************************************************************
//     FUNCTION WITH NESTED SWITCH OF MAIN CASE 3
//***************************************************************************

void lawfirm::case3()
{
		design();
		int ch;
		setcolor(LIGHTRED);
		settextstyle(1,0,5);
		outtextxy(250,20,"MENU");
		gotoxy(18,8);cout<<"1. ENTER CASE DETAILS";
		gotoxy(18,10);cout<<"2. UPDATE CASE DETAILS";
		gotoxy(18,12);cout<<"3. DELETE CASE DETAILS";
		gotoxy(18,14);cout<<"4. SEARCH CASE DETAILS";
		gotoxy(18,16);cout<<"5. TO EXIT";
		gotoxy(18,19);cout<<"ENTER YOUR CHOICE(1-5):";
		gotoxy(45,19);cin>>ch;
	switch(ch)
	{
		case 1:
		{
			design();
			casefil();   //to enter a case details
			break;
		}
		case 2:
		{
			design();
			csf_edit();   //to edit a case details
			break;
		}
		case 3:
		{
			design();
			csf_delete(); //to delete a case details
			break;
		}
		case 4:
		{
			design();
			csf_search(); //to search for a particular case details
			break;
		}
		case 5:
			return;
	}
}



//***************************************************************************
//     THE MAIN FUNCTION OF PROGRAM
//***************************************************************************

void main()
{
	lawfirm law;
	int choice;
	char pw[10],temp[10];
		gotoxy(20,4);cout<<"Enter password\n";
		gotoxy(20,6);gets(pw);
		if(strcmp(pw,"abc")!=0)
	{
		cout<<"WRONG PASSWORD";
		getch();
	}
		else
	{
		int gdriver=DETECT,mode;
		initgraph(&gdriver,&mode,"C:\\TC\\bgi");
		cleardevice();
		law.frontpage();
		xx:
		law.design();
			setcolor(LIGHTRED);
			settextstyle(1,0,5);
			outtextxy(250,20,"MENU");
			gotoxy(18,8);cout<<"1. EMPLOYEES";
			gotoxy(18,10);cout<<"2. CLIENTS";
			gotoxy(18,12);cout<<"3. CASES";
			gotoxy(18,14);cout<<"4. SEARCH CASES DATE WISE";
			gotoxy(18,16);cout<<"5. SEARCH CASES MONTH WISE";
			gotoxy(18,18);cout<<"6. TO EXIT";
			gotoxy(18,20);cout<<"ENTER YOUR CHOICE(1-6):";
			gotoxy(45,20);cin>>choice;
		switch(choice)
	{
			case 1:
		{
			law.case1();
			break;
		}

			case 2:
		{
			law.case2();
			break;
		}
			case 3:
		{
			law.case3();
			break;
		}
			case 4:
		{
			law.design();
			law.law_date();   //to search for date wise cases
			break;
		}
			case 5:
		{	law.design();
			law.law_month();  //to search for month wise cases
			break;
		}
			case 6:
			exit(0);
	}
		getch();
		goto xx;
	}
}


//***************************************************************************
//     END OF PROJECT
//***************************************************************************
