#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void chk(char pwd[])
 {
	for(int i=0;;i++)
	{
	 pwd[i]=getch();

	  if(pwd[i]!='\r') putch('*');

	 if(pwd[i]=='\b')
	{
	  cout<<"\b\b";
	  i=i-2;
	 }

	 if(pwd[i]=='\r') break;
	}
  pwd[i]=0;

}

struct date
{
 int dd,mm,yy;
} ;

date today;

int month_day(int month)
 {
	switch(month)
	 {
	  case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		 return 31;
	  case 4: case 6: case 9: case 11:
		 return 30;
	  case 2:
		 return 28;
	  }
 }

 date add_days( date d, int n)
  {
	 d.dd=d.dd+n;
	 for(int i=d.mm;  ; i++)
	  {
		if( d.dd>month_day(i))
		  {
			 d.dd=d.dd-month_day(i);
			 d.mm++;
		  }
		else if(d.dd<month_day(i))
				 break;

			if(d.mm==12)
		 {
			d.yy++;
			d.mm=1;
			i=0;
		 }
	  }
	 return d;
  }

int date_chk(date dob)
 {
	if(dob.yy<0)
	 {
	  cout<<"Invalid year...Re-Enter the Year"<<endl;
	  return 0;
	 }

	else if(dob.mm<=0||dob.mm>12)
	 {
	  cout<<"Invalid month number"<<endl;
	  return 0;
	 }
	else
	 {
	  if(dob.yy%4==0&&dob.mm==2)
		{
			 if(dob.dd>29||dob.dd<=0)
			{
				cout<<"Invalid day number"<<endl;
				return 0;
			}
		 }
	  else if(dob.yy%4!=0&&dob.mm==2)
		 {
			 if(dob.dd>28||dob.dd<=0)
			{
				cout<<"Invalid day number"<<endl;
				return 0;
			}
		 }
	  else if(dob.mm==1||dob.mm==3||dob.mm==5||dob.mm==7||dob.mm==8||dob.mm==10||dob.mm==12)
		 {
		  if(dob.dd>31||dob.dd<=0)
			{
				cout<<"Invalid day number"<<endl;
				return 0;

			}
		  }
	  else if(dob.mm==4||dob.mm==6||dob.mm==9||dob.mm==11)
		 {
		  if(dob.dd>30||dob.dd<=0)
			{
				cout<<"Invalid day number"<<endl;
				return 0;

			}
		  }
	  else
		return 1;
	 }
}

int date_compare(date d1 , date d2)
 {
  if(d1.yy>d2.yy)      return 1;
  else if(d2.yy>d1.yy) return 0;
  if(d1.mm>d2.mm)
  return 1;
  else if(d2.mm>d1.mm)
  return 0;
  if(d1.dd>d2.dd)
  return 1;
  else if(d2.dd>d1.dd)
  return 0;
  else return 0;

 }

class account
{    public:
	int acno;
	char name[50];
	double deposit;
	date mat;
	char type;
	char password[25];
	date dob;
	char nominee_name[50];
	char nominee_address[50];
	char address[50];
	char phno[50];
	double interest;
public:
	void create_account();	//function to get data from user
	void show_account();	//function to show data on screen
	void modify();   //function to get new data from user
	void dep(double);	//function to accept amount and add to balance amount
	void draw(double);	//function to accept amount and subtract from balance amount
	void report(int);	//function to show data in tabular format
	int retacno();	//function to return account number
	int retdeposit();	//function to return balance amount
	char rettype();	//function to return type of account
};

void account::create_account()
{  char temp[25];
	int flag;
	cout<<"\nEnter The account No.";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
	cout<<"\nEnter Type of The account (F/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\nEnter The Address of The account holder : ";
	gets(address);

	m:
	cout<<"\n\nEnter The Date of birth of acccount holder : ";
	cout<<"\n\nEnter Day : ";
	cin>>dob.dd;
	cout<<"\n\nEnter Month : ";
	cin>>dob.mm;
	cout<<"\n\nEnter Year : ";
	cin>>dob.yy;
	flag=date_chk(dob);

	if(flag==0)
	 goto m;


	cout<<"\n\nEnter The Phone Number : ";
	gets(phno);
	cout<<"\n\nEnter The Name of The nominee : ";
	gets(nominee_name);
	cout<<"\n\nEnter The address of The nominee : ";
	gets(nominee_address);
 b:cout<<"\nEnter password for your account-not more than 20 characters "<<endl;
	chk(password);
	cout<<"\nRe-Enter the password"<<endl;
	chk(temp);
	if( strcmp(temp,password)==0)
	{

	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for Fixed Deposit ) : ";
	cin>>deposit;
	if(type=='F')
	{
	 int ch;

	 cout<<"Enter the duration of FD account"<<endl;
	 cout<<"1)45 days"<<endl;
	 cout<<"2)90 days"<<endl;
	 cout<<"3)1 year" <<endl;

	 cin>>ch;
	 switch(ch)
	 {
	  case 1:{  mat=add_days(today,45);

				  cout<<"Date of maturity:"<<" "<<mat.dd<<"/"<<mat.mm<<"/"<<mat.yy<<endl;
																											  interest = 1.07;
				  cout<<"Maturity Amount at end:"<<deposit*interest<<endl;
				  cout<<"please check back by then"<<endl;
				 break;
				}

		 case 2:{  mat=add_days(today,90);
				  cout<<"Date of maturity:"<<" "<<mat.dd<<"/"<<mat.mm<<"/"<<mat.yy<<endl;
				  interest = 1.081;
				  cout<<"Maturity Amount at end:"<<deposit*interest<<endl;
				  cout<<"please check back by then"<<endl;
				  break;
				 }
		 case 3:{  mat=add_days(today,365);
				  cout<<"Date of maturity:"<<" "<<mat.dd<<"/"<<mat.mm<<"/"<<mat.yy<<endl;
				  interest = 1.09;
				  cout<<"Maturity Amount at end:"<<deposit*interest<<endl;
				  cout<<"please check back by then"<<endl;
				  break;
				 }
		 default: {cout<<"Re-Enter the option"<<endl;}
	  }

	}

	cout<<"\n\n\nAccount Created..";
  }
  else
  {
	cout<<"\nPasswords do not match re enter again"<<endl;

	goto b;
  }
}

void account::show_account()
{                   int flag;
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
	cout<<"\n The Address of The account holder : ";
	puts(address);
	cout<<"\nDate of birth of acccount holder : ";
	cout<<dob.dd<<"-"<<dob.mm<<"-"<<dob.yy;

	cout<<"\nThe Phone Number : ";
	puts(phno);
	cout<<"\n Name of The nominee : ";
	puts(nominee_name);
	cout<<"\nAddress of The nominee : ";
	puts(nominee_address);
						if(type=='F')
						{
								  flag=date_compare(today,mat);
								  if(flag==1)
											{      char ch;
													 cout<<"You're Account Has Matured"<<endl;
													 cout<<"Maturity Amount : "<<deposit*interest<<endl;
													 cout<<"Do you want to Deposit in a Savings Bank Account"<<endl;
													 cin>>ch;
													 if(ch=='Y'||ch=='y')
														 {       int n;
																	cout<<"Enter the Saving Bank Account Number"<<endl;
																	cin>>n;
																	int found=0;
																	account ac;
																	fstream File;
																	File.open("acc.dat",ios::binary|ios::in|ios::out);

																	while(File.read((char *) &ac, sizeof(ac)) && found==0)
															  {
																  if(ac.retacno()==n)
																{
																	ac.deposit+=deposit*interest;
																  int pos=(-1)*sizeof(ac);
																 File.seekp(pos,ios::cur);
																 File.write((char *) &ac, sizeof(ac));
																cout<<"\n\n\t Record Updated";
																found=1;
																}
															 }
													File.close();


												ifstream inFile;
												ofstream outFile;
												inFile.open("acc.dat",ios::binary);

													outFile.open("Temp.dat",ios::binary);
													inFile.seekg(0,ios::beg);
											  while(inFile.read((char *) &ac, sizeof(ac)))
											{
													if(ac.retacno()!=acno)

												outFile.write((char *) &ac, sizeof(ac));

											}
										inFile.close();
										outFile.close();
										remove("acc.dat");
										rename("Temp.dat","acc.dat");
										cout<<"\n\n\tRecord Deleted ..";
													 if(found==0)
													 cout<<"\n\n Record Not Found ";
						}
											 else
											  {
												cout<<"The Account has Been Withdrawn by the customer"<<endl;
                                    cout<<"Amount Withdrawn is...."<<deposit*interest<<endl;
                                   	account ac;
												ifstream inFile;
												ofstream outFile;
												inFile.open("acc.dat",ios::binary);

													outFile.open("Temp.dat",ios::binary);
													inFile.seekg(0,ios::beg);
											  while(inFile.read((char *) &ac, sizeof(ac)))
											{
													if(ac.retacno()!=acno)

												outFile.write((char *) &ac, sizeof(ac));

											}
										inFile.close();
										outFile.close();
										remove("acc.dat");
										rename("Temp.dat","acc.dat");
										cout<<"\n\n\tRecord Deleted ..";



								 }







										}
						}

}


void account::modify()
{   int flag;
	cout<<"\nThe account No."<<acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
	cout<<"\n\nEnter The Address of The account holder : ";
	gets(address);
		k:
	cout<<"\n\nEnter The Date of birth of acccount holder : ";
	cout<<"\n\nEnter Day : ";
	cin>>dob.dd;
	cout<<"\n\nEnter Month : ";
	cin>>dob.mm;
	cout<<"\n\nEnter Year : ";
	cin>>dob.yy;
	flag=date_chk(dob);

	if(flag==0)
	 goto k;
	cout<<"\n\nEnter The Phone Number : ";
	gets(phno);
	cout<<"\n\nEnter The Name of The nominee : ";
	gets(nominee_name);
	cout<<"\n\nEnter The address of The nominee : ";
	gets(nominee_address);
}


void account::dep(double x)
{
	deposit+=x;
}

void account::draw(double x)
{
	deposit-=x;
}

void account::report(int format)
{  gotoxy(0,format);
	cout<<acno;
	gotoxy(15,format);
	cout<<name;
	gotoxy(30,format);
	cout<<type;
	gotoxy(40,format);
	cout<<deposit;
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}

void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function



void main()
{
	char ch;
	int num;
	clrscr();
	intro();
	int option;
	char admin[50];

	a:
	clrscr();
	cout<<"\n\n\t Main Menu"<<endl;
	cout<<"\n\n\t 1.Administrator"<<endl;
	cout<<"\n\n\t 2.Customer"<<endl;
	cout<<"\n\n\t 3.Exit Application"<<endl;
	cin>>option;
	if(option==1)
	{
	  cout<<"Enter the password for admin"<<endl;
	  b:
	  chk(admin);
	  if(strcmpi(admin,"admin")==0)
		{



	do
	{  H:
		clrscr();
		cout<<"\n\n\n\t  MAIN MENU";
		cout<<"\n\n\t 01. NEW ACCOUNT";
		cout<<"\n\n\t 02. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t 03. CLOSE AN ACCOUNT";
		cout<<"\n\n\t 04. MODIFY AN ACCOUNT";
		cout<<"\n\n\t 05. EXIT";
		cout<<"\n\n\tSelect Your Option (1-5) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			display_all();
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '5':
			goto a;
			break;
		 default : {cout<<"Invalid Option..Reneter the  option"; getchar(); goto H;}
		}
		getch();
	}while(ch!='5');
  }
  else
	{
	 cout<<"\n\nRe-Enter the password"<<endl;
	 goto b;
	 }

  }

	else if(option==2)
	{
	 do
	{
		clrscr();
		u:
		cout<<"\n\n\n\tMAIN MENU";

		cout<<"\n\n\t01. DEPOSIT AMOUNT(Only Savings Account)";
		cout<<"\n\n\t02. WITHDRAW AMOUNT(Only Savings Account)";
		cout<<"\n\n\t03. BALANCE ENQUIRY";
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tSelect Your Option (1-4) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{

		case '1':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		 case '4':
			goto a;
			break;
		 default :cout<<"Invalid Option.....Please select correct one"; getchar(); goto u;
		}
		getch();
	}while(ch!='5');
  }

  else if(option==3)
 {cout<<"\n\n Thank you. Have a nice day;"<<endl;

  }
  else goto a;


}



void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("acc.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(ac));
	outFile.close();
}


void display_sp(int n)
{
	account ac;
	int check=0;
	ifstream inFile;
	char pwd[80];
	inFile.open("acc.dat",ios::binary);

	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &ac, sizeof(ac)))
	{
		if(ac.retacno()==n)
		{  cout<<"Enter the Password"<<endl;
			chk(pwd);check++;
			if(strcmpi(pwd,ac.password)==0)

			 ac.show_account();
			else cout<<"\n\n\tWrong Password"<<endl;
		}
	}
	inFile.close();
	if(check==0)
		cout<<"\n\nAccount number does not exist";
}


void modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
	File.open("acc.dat",ios::binary|ios::in|ios::out);

	while(File.read((char *) &ac, sizeof(ac)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(ac));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}



void delete_account(int n)
{
	account ac;
	int flag = -1;
	ifstream inFile;
	ofstream outFile;
	inFile.open("acc.dat",ios::binary);

	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(ac)))
	{
		if(ac.retacno()!=n)
		{

			outFile.write((char *) &ac, sizeof(ac));
		}
		else flag++;
	}
	inFile.close();
	outFile.close();
	remove("acc.dat");
	rename("Temp.dat","acc.dat");
	if(flag!=-1)cout<<"\n\n\tRecord Deleted ..";
	else cout<<"\n\n\tRecord Not Found...Invalid Account Number"<<endl;
}


void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("acc.dat",ios::binary);
	int format=10;
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"____________________________________________________\n";
	cout<<"A/c no.       NAME           Type    Balance\n";
	cout<<"____________________________________________________\n";
	while(inFile.read((char *) &ac, sizeof(ac)))
	{

		ac.report(format);
		format++;
	}
	inFile.close();

}


void deposit_withdraw(int n, int option)
{
	double amt;
	int found=0;
	account ac;
	fstream File;
	char pwd[80];
	File.open("acc.dat", ios::binary|ios::in|ios::out);

	while(File.read((char *) &ac, sizeof(ac)) && found==0)
	{
		if(ac.retacno()==n)
		{  cout<<"Enter the Password"<<endl;
			chk(pwd);
			found++;
			if(strcmpi(pwd,ac.password)==0)
			{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited : ";
				cin>>amt;
				ac.dep(amt);

			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<500)
					cout<<"Insufficiencent balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(ac));
			cout<<"Current Balance after Deposit/Withdrawal :  "<<ac.deposit<<endl;
			cout<<"\n\n\t Record Updated";

		 }


		else cout<<"\n\n\tWrong Password"<<endl;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}




void intro()
{
	cout<<"\n\n\n\t\t  BANK";
	cout<<"\n\n\t\tMANAGEMENT";
	cout<<"\n\n\t \t SYSTEM";
	cout<<"\n\n\n\n\tMADE BY : Aprameya And Roshan";
	cout<<"\n\n\tSCHOOL : National Public School";
	f:
	getchar();
	clrscr();
	cout<<"Enter Today's Date"<<endl;
	cout<<" Enter the day"<<endl;
	cin>> today.dd;
	cout<<"Enter the Month"<<endl;
	cin>>today.mm;
	cout<<"Enter the Year"<<endl;
	cin>>today.yy;
  int flag =  date_chk(today);
  if(flag==0)
  {
	cout<<"Invalid Date"<<endl;
	goto f;
  }
	getch();

}
