/*	Filename: bankaccount.c*
 *	Author: Sam Amonette
 *	Group: js
 *	date: 11-29-16
 *
 *	Description: This is the first version of bankaccount.c final project
 *	 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define SIZE 30

struct bankAccount{

	double number; // Account number, must be unique
	char name[SIZE];
	//char address[SIZE];
	//int account_type; // 0 for personal, 1 for business, 2 for savings
	double balance; // Current balance. Since this is a generic bankaccount, balance will be in later bank accounts in later structs
	int num_withdrawls; // Not limited
	int num_deposits; // This month
	int num_overdrafts;
	double fees; // Per month
	double interest; // Per month
	double average; // Average balance
	int service_charge; // Per month, $1 if balance below $5, no charge else

};

struct savingsAccount{
	
	struct bankAccount ba;
	int status;
	int numwithdrawls; // Charge if numwithdrawls
	//double number;
	//char name[SIZE];
	
};

void createNewSavingsAccount(char* name, double balance, double interest, struct savingsAccount* sa);
void withdrawlSavings(double withdrawl, struct savingsAccount* sa);
void depositSavings(double deposit, struct savingsAccount* sa);
// Creates a new savings account by passing a savings account
// by reference
void createNewSavingsAccount(char* name, double balance, double interest, struct savingsAccount* sa)
{
	sa->ba.num_deposits = 0;
	sa->numwithdrawls = 0;

	if (balance < 25)
	{
		sa->status = 0; //inactive status
	}

	else
		sa->status = 1; //active status
	
}

void withdrawlSavings(double withdrawl, struct savingsAccount* sa)
{

	if (sa->status == 1)
	{
		sa->ba.balance-=withdrawl;

	}

	else
	{
		printf("Cannot Withdraw. Low Balance\n");


	}


}

void depositSavings(double deposit, struct savingsAccount* sa){

	if (deposit > 0)
	{
		sa->ba.balance+=deposit;
		
		if (sa->ba.balance > 25)
		{
			sa->status = 1;

		}

	}

	else
	{
		printf("No Negative Deposits\n");

	}
}
	
void createNewBankAccount(char* name, double balance, double interest, struct bankAccount* ba);
void deposit(double balance, struct bankAccount* ba);
void withdraw(double withdrawl, struct bankAccount* ba);
void calcinterest(struct bankAccount* ba);
void monthlyprocess(struct bankAccount* ba);
/*
void withdraw(double withdrawl, bankAccount* ba);
void deposit(double deposit, struct bankAccount * ba);*/

// Creates a new bank account by passing a bankAccount by reference
void createNewBankAccount(char* name, double balance, double interest,struct bankAccount* ba)
{
	ba->num_deposits = 0;
	ba->num_withdrawls = 0;
	ba->service_charge = 0;
}

void deposit(double deposit, struct bankAccount* ba)
{
	if (deposit<=0)
		printf("Invalid deposit");
	else
		ba->balance+=deposit;
}

void withdraw(double withdrawl, struct bankAccount* ba)
{	
	if (withdrawl<=0)
		printf("Invalid withdrawl");
	else
		ba->balance+=withdrawl;
}

void calcinterest(struct bankAccount* ba)
{
	double monthlyinterestrate = (ba->interest)/12;
	double monthlyinterest = monthlyinterestrate*ba->balance;
	ba->balance+=monthlyinterest;
	
}

void monthlyprocess(struct bankAccount* ba)
{
	ba->balance-=ba->service_charge;
	calcinterest(ba);
}



void main()
{
	// Create instance of struct bankAccount
	struct bankAccount *aaa;
	aaa = (struct bankAccount *)malloc(sizeof(struct bankAccount));
	char name[] = "Alice";
	double balance = 100;
	double interest = .05;
	
	//opening a file variables
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char delim[] = ",";//only comma because the only delimeter is the ,
	char* token;
	int i=0;//counter for tokenizing line
	int x; //variable to change string to int
	int j = 0;

	//opening the file
	fp = fopen("input.txt", "r"); //will have to change name in future
	if (fp==NULL)
		printf("Can't Open input file\n");	                        
	//get each line
	while((read=getline(&line,&len,fp))!=-1){

		for(token=strtok(line,delim);token;token=strtok(NULL,delim)){

			//first part of line is the acc. number
			if (i==0){
				
				x = atoi(token);
				aaa[j].number = (double) x;
				//DEBUG
				printf("acc. number %.0f\n",aaa[j].number);
				//printf("token %s\n", token);
				//printf("i0 %d\n",i);
			}
			//second part of line is name
			if (i==1){

				strcpy(aaa[j].name,token);
				//DEBUG
				printf("name %s\n",aaa[j].name);
				//printf("token %s\n", token);
				//printf("i1 %d\n",i);
			}
			
			//third part is balance
			if (i==2){
				
				x = atoi(token);
				aaa[j].balance = (double) x;
				//DEBUG
				printf("balance %.0f\n",aaa[j].balance);
				//printf("token %s\n", token);
				//printf("i2 %d\n",i);
			}
			
			i = i + 1;
		}
	i = 0;//when getting a new line, reset position counter to 0
	j = j + 1;

	}
	// Call function
	createNewBankAccount(name,balance,interest,aaa);
	deposit(100,aaa);
	//printf("%.2lf\n",aaa->balance);
	withdraw(25,aaa);
	//printf("%.2lf\n",aaa->balance);
	//printf("%d\n",aaa->num_deposits);
	calcinterest(aaa);
}

