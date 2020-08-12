#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
//	The time_t datatype is a data type in the C library defined for storing system time values
using namespace std;

class hotel
{
	public:
		void addrecord();  //FUNCTIONS DECLARED IN CLASS HOTEL IN PUBLIC SECTION
		void listrecords();
		void editrecord();  
		void deleterecord();
		void searchrecord();
		void login();
};

void hotel::login()			//LOGIN ACCESS TO LIMITED PERSONNEL ONLY.
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="admin";		// ORIGINAL USERNAME STRING WHICH IS VALID TO LOGIN TO SYSTEM
    char pass[10]="orchid1";		// ORIGINAL PASSWORD STRING;
    do
	{
	system("cls");
	
    cout<<"\n  **************************  LOGIN FORM  **************************  ";	//LOGIN PAGE
    cout<<" \n                       ENTER USERNAME:-";
	cin>>uname; 
	cout<<" \n                       ENTER PASSWORD:-";
	
	
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13)		// 13 is the ascii value of enter key(carriage return)
		 break;
	    else
		 cout<<"*";
	    i++;
	}
	pword[i]='\0';		// adding null char to the end of pword string
	
	i=0;
	
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)		// checking the username and the password
	{															
	cout<<"  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL";
	
	break;
	}
	else
	{
		cout<<"\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
		a++;
		
		getch();
		
	}
}while(a<=2);			
	if (a>2)		// if incorrect password entered for three times then it would display an error message
	{
		cout<<"\nSorry you have entered the wrong username and password for three times!!!";
		cout<<endl<<"Press any key";
		getch();
		exit(0);
		
		}
		system("cls");	//		clearing screen
}

struct CustomerDetails   //	Structure declaration for all the fields of a guest
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];	
	char email[20];
	char arrivaldate[10];
	
}s;

int main()
{   
	  // MAIN FUNCTION	
	hotel obj;
	int i=0;
	
	time_t ct;		// returns the current calendar time of the system as time in variable ct
	time(&ct);
	char customername;
	char choice;

	system("cls");   // FOR CLEARING SCREEN
	
						// Index page:
		for(i=0;i<7;i++)
			cout<<endl;
		
		
		cout<<"\t\t\t      *************************************************"<<endl;	
			
		cout<<"\t\t\t      *                                               *"<<endl;
		cout<<"\t\t\t      *                                               *"<<endl;
		cout<<"\t\t\t      *                                               *"<<endl;	
		cout<<"\t\t\t      *   -----------------------------------------   *"<<endl;
		cout<<"\t\t\t      *             WELCOME TO THE ORCHID             *"<<endl;
		cout<<"\t\t\t      *   -----------------------------------------   *"<<endl;
		cout<<"\t\t\t      *                                               *"<<endl;
		cout<<"\t\t\t      *                                               *"<<endl;
		cout<<"\t\t\t      *                                               *"<<endl;
		cout<<"\t\t\t      *************************************************"<<endl;
		cout<<endl;
		cout<<"\t\t\t             Created By Kartik, Bhavya and Manan      "<<endl<<endl;
		for(i=0;i<160;i++)
		cout<<"-";
		cout<<endl;
	    cout<<"\n       Current date and time : "<<ctime(&ct);
	    for(i=0;i<160;i++)
		cout<<"-";
	cout<<" \n Press any key to continue:";
	
	getch();		
    system("cls");
    obj.login();		//  Call to login function to verify the user
    system("cls");
	while (1)      // INFINITE LOOP OF MAIN MENU UNTIL THE USER SELECTS THE EXIT OPTION
	{
		system("cls");
		
		 for(i=0;i<80;i++)
		cout<<"-";
		cout<<"\n";
		cout<<"   ******************************  MAIN MENU  ***************************** \n";
		for(i=0;i<80;i++)
		cout<<"-";
		cout<<"\n";
		
		cout<<"\t\t *Please enter your choice for menu*:";
		cout<<"\n\n";
		cout<<" \n Enter 1 -> Book a room";
		cout<<"\n------------------------";
		cout<<" \n Enter 2 -> View Guests' Record";
		cout<<"\n----------------------------------";
		cout<<" \n Enter 3 -> Delete a Guest Record";
		cout<<"\n-----------------------------------";
		cout<<" \n Enter 4 -> Search Guests' Record";
		cout<<"\n-----------------------------------";
		cout<<" \n Enter 5 -> Edit Record";
		cout<<"\n-----------------------";
		cout<<" \n Enter 6 -> Exit";
		cout<<"\n------------------";
		cout<<"\n";
		for(i=0;i<80;i++)
		cout<<"-";
	    cout<<"\nCurrent date and time : "<<ctime(&ct);
	    for(i=0;i<80;i++)
		cout<<"-";
		
		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT FOR CALLING FUNCTIONS ACCORDING TO CHOICE
		{	
			case '1':
				obj.addrecord();break;		
			case '2':
				obj.listrecords();break;
			case '3':
				obj.deleterecord();break;
			case '4':
				obj.searchrecord();break;
			case '5':
				obj.editrecord();break;
			case '6':
				system("cls");
				cout<<"\n\n\t *****THANK YOU*****";
				cout<<"\n\t FOR TRUSTING OUR SERVICE";
				cout<<"\n\t PLEASE FEEL FREE TO CONTACT US FOR ANY FURTHER ASSISTANCE"<<endl;
				exit(0);
				break;
			default:
				system("cls");
				cout<<"Incorrect Input; Please do make a choice from above options";
				cout<<"\n Press any key to continue";
				getch();
		}
	}
}

void hotel::addrecord()
{
	FILE *f;
	char test;
	f=fopen("data.txt","a+");		// opening the file in reading and appending mode
	if(f==0)		// if file does not get created in any case
	{   f=fopen("data.txt","w+");
		system("cls");
		cout<<"Please hold on while we set our database in your computer!!";
		cout<<"\n Process completed press any key to continue!! ";
		getch();
	}
	while(1)
	{
		system("cls");
		cout<<"\n Enter Guest Details:";
		cout<<"\n**************************";
		cout<<"\n Enter Room number:\n";
		cin>>s.roomnumber;
		fflush(stdin);
		cout<<"Enter Name:\n";
		cin>>s.name;
		cout<<"Enter Address:\n";
		cin>>s.address;
		cout<<"Enter Phone Number:\n";
		cin>>s.phonenumber;
		cout<<"Enter Nationality:\n";
		cin>>s.nationality;
		cout<<"Enter Email:\n";
		cin>>s.email;
		cout<<"Enter Arrival date(dd/mm/yyyy):\n";
		cin>>s.arrivaldate;
		fwrite(&s,sizeof(s),1,f);
		
		fflush(stdin);
		cout<<"\n\n1 Room is successfully booked!!";
		cout<<"\n Press esc key to exit,  any other key to add another customer detail:";
		test=getche();
		if(test==27)		// 27 is the ascii value for esc key
			break;
			
	}
	fclose(f);
}

void hotel::listrecords()
{
	FILE *f;
	int i;
	if((f=fopen("data.txt","r"))==NULL)
		exit(0);
	system("cls");
	
	while(fread(&s,sizeof(s),1,f)==1)
	{
		
		cout<<"ROOMNUMBER:\t "<<s.roomnumber<<endl;
		cout<<"NAME:\t\t "<<s.name<<endl;
		cout<<"ADDRESS:\t"<<s.address<<endl;
		cout<<"PHONE NO:\t"<<s.phonenumber<<endl;
		cout<<"EMAIL:\t\t"<<s.email<<endl;
		cout<<"NATIONALITY:\t"<<s.nationality<<endl;
		cout<<"ARRIVAL DATE:\t"<<s.arrivaldate<<endl<<endl<<endl;
		
	}
	cout<<"\n";
	for(i=0;i<118;i++)
		cout<<"-";
		cout<<endl;
		cout<<"Please press any key: ";

	fclose(f);
	getch();
}

void hotel::deleterecord()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("data.txt","r"))==NULL)
	exit(0);
	system("cls");
	cout<<"Enter the Room Number of the Guest to be deleted from the database: \n";
	fflush(stdin);
	cin>>roomnumber;
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
		{
			fwrite(&s,sizeof(s),1,t);
			
		}
	}
	if(i==1)
	{       
		cout<<"\n\n Records of Guest in this  Room number is not found!!";
		
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("data.txt");
	rename("temp.txt","data.txt");
	cout<<"\n\nThe Guest is successfully removed....";
	fclose(f);
	fclose(t);
	cout<<endl;
	cout<<"Press any key to go to main menu: ";
	getche();
}

void hotel::searchrecord()
{
	system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("data.txt","r+");		// opening the file in reading and writing mode
	if(f==0)
		exit(0);
	fflush(stdin);
	cout<<"Enter Room number of the Guest to search its details: \n";
	cin>>roomnumber;
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			cout<<"\n\tRecord Found\n ";
			cout<<"\nRoom Number:\t  "<<s.roomnumber;
			cout<<"\nName:\t \t"<<s.name;
			cout<<"\nAddress:\t"<<s.address;
			cout<<"\nPhone number:\t"<<s.phonenumber;
			cout<<"\nNationality:\t"<<s.nationality;
			cout<<"\nEmail:\t\t"<<s.email;
			cout<<"\nArrival date:\t"<<s.arrivaldate;
			flag=0;
			break;
		}
	}
	if(flag==1){	
		cout<<"\n\tRequested Guest could not be found!";
	}
	cout<<endl;
	cout<<"Press any key to get to the main menu: ";
	getche();
	fclose(f);
}

void hotel::editrecord()
{
	FILE *f,*t;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("data.txt","r+"))==NULL)
		exit(0);
	if((t=fopen("temp1.txt","w"))==NULL)		// CREATING A TEMPORARY FILE IN WRITE MODE
		exit(0);
		
	system("cls");
	cout<<"Enter Room number of the Guest to edit:\n\n";
	cin>>roomnumber;
	fflush(stdin);
	
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
		}
		else
		{
			fwrite(&s,sizeof(s),1,t);	
		}
		
	}
		
	
	if(k==1){
		cout<<"\n\nTHE RECORD OF GUEST THAT WAS REQUESTED DOESN'T EXIST!!!!"<<endl;
		cout<<"Press any Key: ";
		fclose(f);
		getch();
	}else{
		cout<<"Enter the new details: "<<endl;
		cout<<"\nEnter Room Number: ";
		cin>>s.roomnumber;
		cout<<"\nEnter Name: ";
		fflush(stdin);
		cin>>s.name;
		cout<<"\nEnter Address: ";
		cin>>s.address;
		cout<<"\nEnter Phone number: ";
		cin>>s.phonenumber;
		cout<<"\nEnter Nationality: ";
		cin>>s.nationality;
		cout<<"\nEnter Email: ";
		cin>>s.email;
		cout<<"\nEnter Arrival date: ";
		cin>>s.arrivaldate;
		fseek(f,size,SEEK_CUR);
		fwrite(&s,sizeof(s),1,t);
		
	fclose(f);
	fclose(t);
	remove("data.txt");
	rename("temp1.txt","data.txt");
	fclose(t);
	fclose(f);
	cout<<"\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!"<<endl;
	cout<<"\t\tPress any key: ";
	getch();
}
}
