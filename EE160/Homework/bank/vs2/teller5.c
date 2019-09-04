//Japhet Ye
//teller5.c
//this program is what a teller woould use to interface with
//the bank system
//it compiles

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"bank.h"

//moved most of the functions into bank.c, we can leave the print account stuff here
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
int main(){

	struct bankAccount baa[N];//regular bank account array
	struct savingsAccount saa[N];//savings account array
	char x,make,action,money,type;
	char name[SIZE];
	double account_num,deposited,withdrawed,initial_dep,interestrate,accountnum;
	int accindex;

	//variables needed to open a file and delim a line from file
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read ;
	char delim[]=",";
	char* token;
	int x1,msl;//msl=monthly service loop counter
	int i = 0;//counter for tokenizing 
	int j=1;//counter for the amount of lines which equals the amount of 
		//existing customers
	int js=0;//counter for savings accounts which there will be none in the file

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
	//from here we must sort the regular bank account array by balance
	//j=existing customers for regular bank account

	//from here we would have the amount of customers already in the bank
	//and from there we can make more accounts if need be as long as j<N
	
	//we could loop the monthly process loop here or...!
		
	//teller interface
	//this is where we would do our test cases because what is scanned should
	//be all correct, what is going to be inputted will have the potential error
	printf("What would you ike to do?\n");
	printf("Deposit(D) Withdrawl (W) Make an new account (M)\n");
	scanf("%c", &x);

	if (x=='D' || x=='d' || x=='W' || x=='w'){

		printf("Savings(S) or Checking(C)?\n");
		clear();
		scanf("%c", &type);
		
		if (type=='S' || type=='s'){
		
			printf("Would you like to input name(N) or account number(A)?\n");
			clear();
			scanf("%c", &action);

			if (action=='A' || action=='a'){

				//search through the struct of arrays and 
				//finds the account info
				printf("Enter Account Number\n");
				scanf("%lf", &accountnum);
				
				accindex = searchSaccount(saa,accountnum);
				
				if (accindex != -1){

					if (x=='D' || x=='d'){
		
						printf("Enter deposit amount\n");
						scanf("%lf", deposited);
						//calls savings deposit function
						depositSavings(deposited,saa,accindex);
					}

					if (x=='W' || x=='w'){

						printf("Enter withdrawl amount\n");
						scanf("%lf", &withdrawed);
						//calls savings withdraw function
						withdrawSavings(withdrawed,saa,accindex);
					}
				}
				else{	
					printf("Account Not Found\n");
				}
			}

			if (action=='N' || action=='n'){
				//search through the struct of arrays and 
				//finds the account info
				scanf(" %[^\n]s",name);

				printf("\n");				
				printf("DEBUG search for name\n");
				printf("Name is ");
				for (int n=0;n<N;n++){
					printf("%c",name[n]);

				}
				printf("\n");
				int temp = -1;
				for (int l = 0; l<N;l++){
					if(!strcmp(name,saa[l].ba.name)){
						temp = l;
						l=N-1;
					}
				}
				printf("temp = %d\n", temp);

				//from here we have the accindex

				if (x=='D' || x=='d'){		
					printf("Enter deposit amount\n");
					scanf("%lf", &deposited);
					//calls deposit function
					depositSavings(deposited,saa,accindex);
					
				}

				if (x=='W' || x=='w'){

					printf("Enter withdrawl amount\n");
					scanf("%lf", &withdrawed);
					//calls withdraw function
					withdrawSavings(withdrawed,saa,accindex);		
				}

				else {
					printf("Not Valid Input\n");
				}
			}
		}
		
		if (type=='C' || type=='c'){
		
			printf("Would you like to input name(N) or account number(A)?\n");
			clear();
			scanf("%c", &action);

			if (action=='A' || action=='a'){

				//search through the struct of arrays and 
				//finds the account info
			
				printf("Enter Account Number\n");
				scanf("%lf", &accountnum);
				accindex = searchBaccount(baa,accountnum);
				printf("Debug accindex %d\n", accindex);
				accindex--;
				printf("Debug fixed accindex %d\n", accindex);

				if (accindex != -1){

					if (x=='D' || x=='d'){
		
						printf("Enter deposit amount\n");
						scanf("%lf", &deposited);
						//calls deposit function
						deposit(deposited,baa,accindex);
					}

					if (x=='W' || x=='w'){

						printf("Enter withdrawl amount\n");
						scanf("%lf", &withdrawed);
						//calls withdraw function
						withdraw(withdrawed,baa,accindex);
					}
				}
				else{
					printf("Account Not Found\n");
				}
			}

			if (action=='N' || action=='n'){
				//search through the struct of arrays and 
				//finds the account info
				scanf(" %[^\n]s",name);

				printf("\n");				
				printf("DEBUG search for name\n");
				printf("Name is ");
				for (int n=0;n<N;n++){
					printf("%c",name[n]);

				}
				printf("\n");
				int temp = -1;
				for (int l = 0; l<N;l++){
					if(!strcmp(name,saa[l].ba.name)){
						temp = l;
						l=N-1;
					}
				}
				printf("temp = %d\n", temp);


				if (x=='D' || x=='d'){		
					printf("Enter deposit amount\n");
					scanf("%lf", &deposited);
					//calls deposit function
					deposit(deposited,baa,accindex);
				}

				if (x=='W' || x=='w'){

					printf("Enter withdrawl amount\n");
					scanf("%lf", &withdrawed);
					//calls withdraw function
					withdraw(withdrawed,baa,accindex);

				}

				else {
					printf("Not Valid Input\n");
				}
			}
		}
		
	}

	if (x=='M' || x=='m'){
			
		printf("Savings(S) Or Checking(C)?\n");
		clear();
		scanf("%c", &make);	

		if (make=='S' || make=='s'){
			//since there is no inital savings account we do not update js 
			//at the top, rather we update js at the bottom because we need
			//to initialize this array 
			//makes a new account and copies name into the struct
			printf("Input account holder's name\n");
			scanf("%s", name);
			
			//copies inital deposit into the struct	
			printf("Enter Deposit Amount\n");
			scanf("%lf", &initial_dep);

			printf("Enter interest rate\n");
			scanf("%lf", &interestrate);

			createNewSavingsAccount(name,initial_dep,interestrate,js,saa);
			js++;
			//we will need to generate an account number using
			//rand() for a long value and make sure that it is unique
		}

		if (make=='C' || make=='c'){
			//adds new index for regular bank account array
			j++;
			//makes a new account and copies name into struct
			printf("Input account holder's name\n");
			scanf("%s", &name);
			
			//copies initial deposit into the struct
			printf("Enter deposit amount\n");
			scanf("%lf", &initial_dep);

			printf("Enter interest rate\n");
			scanf("%lf", &interestrate);

			createNewBankAccount(name,initial_dep,interestrate,j,baa);
			
			//we will need to generate an account number using
			//rand() for a long value and make sure that it is unique
			
		}
	}

	//! we could do the service here, after we loop through the teller or after every
	//action

}
