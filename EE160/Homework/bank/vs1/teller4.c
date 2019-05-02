//Japhet Ye
//teller4.c
//this program is what a teller woould use to interface with
//the bank system
//it compiles

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 30
#define N 100

struct bankAccount{

	double number;
	char name[SIZE];
	double balance;
	int with;
	int numdeposits;
	int numoverdrafts;
	double fees;
	double interest;
	int servicecharge;
};

struct savingsAccount{
	struct bankAccount ba;
	int status;
};


//i changed some of the functions to work with an array of structs rather than a 
//pointer to a struct, so I included in the index of the struct array
//to be passed and that is the last thing I did, Still need to hypothetically
//change the original funnctions slighlty. If need be I will do them when we meet up//i also do not know how to work with malloc or struct pointers in this scenario 
//so rather just using an array should be better and easier potentially. I did not
//change anything from the original bankaccount2.c this is made from scratch
//probably best not to name this bankaccount3.c 
void createNewSavingsAccount(char* name, double balance, double interest, int index, struct savingsAccount sa[]);
void withdrawlSavings(double withdrawl, struct savingsAccount sa[], int index);
void depositSavings(double deposit, struct savingsAccount sa[], int index);
void createNewBankAccount(char* name, double balance, double interest, int index, struct bankAccount ba[]);
void deposit(double deposit, struct bankAccount ba[], int index);
void withdraw(double withdraw, struct bankAccount ba[], int index);
void calcinterest(struct bankAccount ba[], int index);
void monthlyprocess(struct bankAccount ba[], int index);
void printBankAccount(struct bankAccount ba[], int index);

void printBankAccount(struct bankAccount ba[], int index){

	printf("%lf\n", ba[index].number);
	printf("%s\n",ba[index].name);
	printf("%lf\n",ba[index].balance);
	printf("%d\n",ba[index].with);
	printf("%d\n",ba[index].numdeposits);
	printf("%d\n",ba[index].numoverdrafts);
	printf("%d\n",ba[index].servicecharge);
	printf("%lf\n",ba[index].fees);
	printf("%lf\n",ba[index].interest);

}

void createNewSavingsAccount(char* name, double balance, double interest,int index, struct savingsAccount sa[]){

	strcpy(sa[index].ba.name,name);
	sa[index].ba.balance = balance;
	sa[index].ba.interest = interest;
	sa[index].ba.numdeposits = 1;
	sa[index].ba.with = 0;
	sa[index].ba.numoverdrafts = 0;
	sa[index].ba.fees = 0;
	sa[index].ba.servicecharge = 0;

	if (balance < 25 && balance > 0){

		sa[index].status = 0;
	}

	if (balance >= 25){
		
		sa[index].status = 1;
	}
}

void depositSavings(double deposit, struct savingsAccount sa[], int index){

	if (deposit>0){
		sa[index].ba.balance+=deposit;
		sa[index].ba.numdeposits++;
	
		if (sa[index].ba.balance>=25){
	
			sa[index].status = 1;
		}
	}
}

void withdrawlSavings(double withdrawl, struct savingsAccount sa[], int index){

	if (withdrawl < sa[index].ba.balance && withdrawl > 0){
	
		sa[index].ba.balance-=withdrawl;
		sa[index].ba.with++;
	}
	else{
		printf("Cannot withdraw specified amount\n");
	}
	
	if (sa[index].ba.balance < 25){
	
		sa[index].status = 0;
	}
	
	if (sa[index].ba.balance < 0){
	
		sa[index].ba.numoverdrafts++;
	}
}

void createNewBankAccount(char* name, double balance, double interest, int index, struct bankAccount ba[]){

	if (balance > 0 && interest > 0){
		strcpy(ba[index].name,name);
		ba[index].balance = balance;
		ba[index].interest = interest;
		ba[index].numdeposits = 1;
		ba[index].with = 0;
		ba[index].numoverdrafts = 0;
		ba[index].fees = 0;
		ba[index].servicecharge = 0;
	}

}

void deposit(double deposit, struct bankAccount ba[], int index){

	if (deposit>0){
		ba[index].balance = deposit + ba[index].balance;
		ba[index].numdeposits++;
	}
}
void withdraw(double withdraw, struct bankAccount ba[], int index){

	if (withdraw < ba[index].balance && withdraw > 0){
	
		ba[index].balance-=withdraw;
		ba[index].with++;
	}
	else{
		printf("Cannot withdraw specified amount\n");
	}
}

int main(){

	struct bankAccount baa[N];//regular bank account array
	struct savingsAccount saa[N];//savings account array
	char x,make,action,money,type;
	char name[SIZE];
	double account_num,deposit,withdraw,initial_dep,interestrate,accountnum;

	//variables needed to open a file and delim a line from file
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read ;
	char delim[]=",";
	char* token;
	int x1;
	int i = 0;//counter for tokenizing 
	int j=1;//counter for the amount of lines which equals the amount of 
		//existing customers

	//over here, the program opens the file with existing customers in them
	//then creates an interface for the bank teller
	//information that this will have will be the amount of already existing 
	//customers which we need to update the array

	fp = fopen("input.txt", "r");
	if (fp==NULL)
		printf("Can't Open file\n");

	//this part is not done yet because we do not know how to 
	//differentiate a regular account from a savings account when reading a line 
	//
	//the numbers are in oder as they are in the struct so we take
	//those numbers to calculate and call the functions
	//still need clarification
	while((read=getline(&line,&len,fp))!=-1){

		for(token=strtok(line,delim);token;token=strtok(NULL,delim)){

			//first part is the acc. nunmber
			if(i==0){
				//stores number in the array
				x1=atoi(token);
				baa[j].number = (double) x1;
				printf("acc num %.0lf\n", baa[j].number);
			}

			//second part is the name
			if(i==1){
				//strcpy token into the array
				strcpy(baa[j].name,token);
				printf("name %s\n",baa[j].name);

			}

			//third part is the initial balance
			if(i==2){
				//stores balance into the array
				x1=atoi(token);
				baa[j].balance = (double) x1;
				printf("balance %.2lf\n",baa[j].balance);
				//if we are doing savings accounts from a file, we would have a check for 
				//balance greater than 25 for this to initilize status
			}

			//fourth part is num of withdrawls
			if(i==3){
				//stores num of withdrawls into array			
				x1=atoi(token);
				baa[j].with = x1;
				printf("num withdrawls %d\n", baa[j].with);
			}
			
			//fifth part is num of deposits
			if(i==4){
				//stores num of deposits into array	
				x1=atoi(token);
				baa[j].numdeposits = x1;
				printf("num deposits %d\n", baa[j].numdeposits);
			}
			
			//sixth part is num of overdrafts
			if(i==5){
				//stores num of ovrdrafts into array
				x1=atoi(token);
				baa[j].numoverdrafts = x1;
				printf("over drafts %d\n", baa[j].numoverdrafts);
			}	
			
			//seventh part is fees of account
			if (i==6){
				//stores fees into array 
				x1=atof(token);
				baa[j].fees = x1;
				printf("fees %.2lf\n", baa[j].fees);
			}	
			
			//eighth part is interes
			if(i==7){
				//stores interst into array 
				x1=atof(token);
				baa[j].interest =  x1;
				printf("interest %lf\n", baa[j].interest);
			}
			
			//ninth part is servicecharge
			if(i==8){
				//stores servicecharge into array
				x1=atoi(token);
				baa[j].servicecharge = x1;
				printf("service charge %d\n", baa[j].servicecharge);
			}
			
			i++;//move the position of token
		}
		j++;//counting the lines i.e. the exsisting customers
		i=0;//reseting tokens postion 
	}

	//from here we would have the amount of customers already in the bank
	//and from there we can make more accounts if need be as long as j<N

		
	//teller interface
	//this is where we would do our test cases because what is scanned should
	//be all correct, what is going to be inputted will have the potential error
	printf("What would you ike to do?\n");
	printf("Deposit(D) Withdrawl (W) Make an new account (M)\n");
	scanf("%c", &x);

	if (x=='D' || x=='d' || x=='W' || x=='w'){

		printf("Savings(S) or Checking(C)?\n");
		scanf("%c", &type);
		
		if (type=='S' || type=='s'){
		
			printf("Would you like to input name(N) or account number(A)?\n");
			scanf("%c", &action);

			if (action=='A' || action=='a'){

				//search through the struct of arrays and 
				//finds the account info

				
			
				printf("Enter Account Number\n");
				scanf("%lf", &accountnum);
				
				//from here we would check the array for the first and only instance of the account number

				printf("Deposit(D) or Withdraw(W)\n");
				scanf("%c", &money);

				if (money=='D' || money=='d'){
		
					printf("Enter deposit amount\n");
					scanf("%lf", deposit);
					//calls deposit function
				}

				if (money=='W' || money=='w'){

					printf("Enter withdrawl amount\n");
					scanf("%lf", &withdraw);
					//calls withdraw function
				}

				else {
					printf("Not Valid Input\n");
				}

			}

			if (action=='N' || action=='n'){
				//search through the struct of arrays and 
				//finds the account info
				printf("Deposit(D) or Withdraw(W)\n");
				scanf("%c", &money);
				if (x=='D' || x=='d'){		
					printf("Enter deposit amount\n");
					scanf("%lf", deposit);
					//calls deposit function
				}

				if (money=='W' || money=='w'){

					printf("Enter withdrawl amount\n");
					scanf("%lf", &withdraw);
					//calls withdraw function

				}

				else {
					printf("Not Valid Input\n");
				}
			}
		}
		
		if (type=='C' || type=='c'){
		
			printf("Would you like to input name(N) or account number(A)?\n");
			scanf("%c", &action);

			if (action=='A' || action=='a'){

				//search through the struct of arrays and 
				//finds the account info
			
				printf("Enter Account Number\n");
				scanf("%lf", &accountnum);

				printf("Deposit(D) or Withdraw(W)\n");
				scanf("%c", &money);

				if (money=='D' || money=='d'){
		
					printf("Enter deposit amount\n");
					scanf("%lf", deposit);
					//calls deposit function
				}

				if (money=='W' || money=='w'){

					printf("Enter withdrawl amount\n");
					scanf("%lf", &withdraw);
					//calls withdraw function
				}

				else {
					printf("Not Valid Input\n");
				}

			}

			if (action=='N' || action=='n'){
				//search through the struct of arrays and 
				//finds the account info
				printf("Deposit(D) or Withdraw(W)\n");
				scanf("%c", &money);
				if (x=='D' || x=='d'){		
					printf("Enter deposit amount\n");
					scanf("%lf", deposit);
					//calls deposit function
				}

				if (money=='W' || money=='w'){

					printf("Enter withdrawl amount\n");
					scanf("%lf", &withdraw);
					//calls withdraw function

				}

				else {
					printf("Not Valid Input\n");
				}
			}
		}
		
	}

	if (x=='M' || x=='m'){
			
		printf("Savings(S) Or Checking(C)?\n");
		scanf("%c", &make);	

		if (make=='S' || make=='s'){

			//makes a new account and copies name into the struct
			printf("Input account holder's name\n");
			scanf("%s", name);
			
			//copies inital deposit into the struct	
			printf("Enter Deposit Amount\n");
			scanf("%lf", &initial_dep);

			printf("Enter interest rate\n");
			scanf("%lf", &interestrate);

			//from here we would pass the variables, array of structs, and the particular
			//index to create the new account. We need to make sure that the
			//particular index is saved.

			//we will need to generate an account number using
			//rand() for a long value and make sure that it is uniquue
		}

		if (make=='C' || make=='c'){
			
			//makes a new account and copies name into struct
			printf("Input account holder's name\n");
			scanf("%s", &name);
			
			//copies initial deposit into the struct
			printf("Enter deposit amount\n");
			scanf("%lf", &initial_dep);

			printf("Enter interest rate\n");
			scanf("%lf", &interestrate);

			//from here we would pass the variables, array of structs, and the particular
			//index to create the new account. We need to make sure that the
			//particular index is saved.
			
			//we will need to generate an account number using
			//rand() for a long value and make sure that it is unique
			
		}
	}

}
