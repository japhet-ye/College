//Japhet Ye
//teller5.c
//this program is what a teller woould use to interface with
//the bank system
//it compiles

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include"bank.h"

//moved most of the functions into bank.c, we can leave the print account stuff here
void printBankAccount(struct bankAccount ba[], int index);

void printBankAccount(struct bankAccount ba[], int index){

	printf("Number: %lf\n", ba[index].number);
	printf("Name: %s\n",ba[index].name);
	printf("Balance: %lf\n",ba[index].balance);
	printf("Number of Withdraws: %d\n",ba[index].with);
	printf("Number of Deposits: %d\n",ba[index].numdeposits);
	printf("Number of Overdrafts: %d\n",ba[index].numoverdrafts);
	printf("Service Charges: %d\n",ba[index].servicecharge);
	printf("Fees: %lf\n",ba[index].fees);
	printf("Interest Rate: %lf\n",ba[index].interest);

}
void printSavingsAccount(struct savingsAccount sa[], int index);

void printSavingsAccount(struct savingsAccount sa[], int index){

	printf("Number: %lf\n", sa[index].ba.number);
	printf("Name: %s\n",sa[index].ba.name);
	printf("Balance: %lf\n",sa[index].ba.balance);
	printf("Number of Withdraws: %d\n",sa[index].ba.with);
	printf("Number of Deposits: %d\n",sa[index].ba.numdeposits);
	printf("Number of Overdrafts: %d\n",sa[index].ba.numoverdrafts);
	printf("Service Charge: %d\n",sa[index].ba.servicecharge);
	printf("Fees: %lf\n",sa[index].ba.fees);
	printf("Interest Rate: %lf\n",sa[index].ba.interest);

}

int main(){

	srand(time(NULL));

	struct bankAccount baa[N];//regular bank account array
	struct savingsAccount saa[N];//savings account array
	char x,make,action,money,type;
	char name[SIZE];
	double account_num,deposited,withdrawed,initial_dep,interestrate,accountnum;
	int accindex,n,accnum;

	//variables needed to open a file and delim a line from file
	FILE * fp;
	FILE * dp;
	char * line = NULL;
	char * line2 = NULL;
	size_t len = 0;
	size_t len2 = 0;
	ssize_t read ;
	ssize_t read2;
	char delim[]=",";
	char* token;
	char* token2;
	int x1,msl;//msl=monthly service loop counter
	double x2;
	int i = 0;//counter for tokenizing 
	int j=0;//counter for the amount of lines which equals the amount of 
	//existing customers
	int js=0;//counter for savings accounts which there will be none in the file

	//over here, the program opens the file with existing customers in them
	//then creates an interface for the bank teller
	//information that this will have will be the amount of already existing 
	//customers which we need to update the array

	fp = fopen("bankaccount.txt", "r");
	if (fp==NULL)
		printf("Can't Open bankaccount.txt\n");

	dp = fopen("savingsaccount.txt","r");
	if (fp ==NULL)
		printf("Can't Open savings.txt\n");

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
				x2=atof(token);
				baa[j].number =  x2;
				//printf("acc num %.0lf\n", baa[j].number);
			}

			//second part is the name
			if(i==1){
				//strcpy token into the array
				strcpy(baa[j].name,token);
				//printf("name %s\n",baa[j].name);

			}

			//third part is the initial balance
			if(i==2){
				//stores balance into the array
				x2=atof(token);
				baa[j].balance =  x2;
				//printf("balance %.2lf\n",baa[j].balance);
				//if we are doing savings accounts from a file, we would have a check for 
				//balance greater than 25 for this to initilize status
			}

			//fourth part is num of withdrawls
			if(i==3){
				//stores num of withdrawls into array			
				x1=atoi(token);
				baa[j].with = x1;
				//printf("num withdrawls %d\n", baa[j].with);
			}

			//fifth part is num of deposits
			if(i==4){
				//stores num of deposits into array	
				x1=atoi(token);
				baa[j].numdeposits = x1;
				//printf("num deposits %d\n", baa[j].numdeposits);
			}

			//sixth part is num of overdrafts
			if(i==5){
				//stores num of ovrdrafts into array
				x1=atoi(token);
				baa[j].numoverdrafts = x1;
				//printf("over drafts %d\n", baa[j].numoverdrafts);
			}	

			//seventh part is fees of account
			if (i==6){
				//stores fees into array 
				x2=atof(token);
				baa[j].fees = x2;
				//printf("fees %.2lf\n", baa[j].fees);
			}	

			//eighth part is interes
			if(i==7){
				//stores interst into array 
				x2=atof(token);
				baa[j].interest =  x2;
				//printf("interest %lf\n", baa[j].interest);
			}

			//ninth part is servicecharge
			if(i==8){
				//stores servicecharge into array
				x1=atoi(token);
				baa[j].servicecharge = x1;
				//printf("service charge %d\n", baa[j].servicecharge);
			}

			i++;//move the position of token
		}
		j++;//counting the lines i.e. the exsisting customers
		i=0;//reseting tokens postion 
	}
	i=0;
	while((read2=getline(&line2,&len2,dp))!=-1){

		for(token2=strtok(line2,delim);token2;token2=strtok(NULL,delim)){

			//first part is the acc. nunmber
			if(i==0){
				//stores number in the array
				x2=atof(token2);
				//printf("token2 %s\n", token2);
				//printf("x1 %f\n", x2);
				saa[js].ba.number =  x2;
				//printf("acc num %.0lf\n", saa[js].ba.number);
			}

			//second part is the name
			if(i==1){
				//strcpy token into the array
				strcpy(saa[js].ba.name,token2);
				//printf("name %s\n",baa[j].name);

			}

			//third part is the initial balance
			if(i==2){
				//2stores balance into the array
				x2=atof(token2);
				saa[js].ba.balance = x2;
				//printf("balance %.2lf\n",baa[j].balance);
				//if we are doing savings accounts from a file, we would have a check for 
				//balance greater than 25 for this to initilize status
			}

			//fourth part is num of withdrawls
			if(i==3){
				//stores num of withdrawls into array			
				x1=atoi(token2);
				saa[js].ba.with = x1;
				//printf("num withdrawls %d\n", baa[j].with);
			}

			//fifth part is num of deposits
			if(i==4){
				//stores num of deposits into array	
				x1=atoi(token2);
				saa[js].ba.numdeposits = x1;
				//printf("num deposits %d\n", baa[j].numdeposits);
			}

			//sixth part is num of overdrafts
			if(i==5){
				//stores num of ovrdrafts into array
				x1=atoi(token2);
				saa[js].ba.numoverdrafts = x1;
				//printf("over drafts %d\n", baa[j].numoverdrafts);
			}	

			//seventh part is fees of account
			if (i==6){
				//stores fees into array 
				x2=atof(token2);
				saa[js].ba.fees = x2;
				//printf("fees %.2lf\n", baa[j].fees);
			}	

			//eighth part is interes
			if(i==7){
				//stores interst into array 
				x1=atof(token2);
				saa[js].ba.interest =  x1;
				//printf("interest %lf\n", baa[j].interest);
			}

			//ninth part is servicecharge
			if(i==8){
				//stores servicecharge into array
				x1=atoi(token2);
				saa[js].ba.servicecharge = x1;
				//printf("service charge %d\n", baa[j].servicecharge);
			}

			if(1==9){
				//stores the status of account into array
				x1=atoi(token2);
				saa[js].status = x1;
			}

			i++;//move the position of token
		}
		js++;//counting the lines i.e. the exsisting savings customers
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
	while(1){
		printf("What would you like to do?\n");
		printf("Deposit(D) Withdrawl (W) Make an new account (M) Proccess An Account(P)\n");
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
							scanf("%lf", &deposited);
							//calls savings deposit function
							depositSavings(deposited,saa,accindex);
							printf("Balance After Deposit %.2lf\n",saa[accindex].ba.balance);
						}

						if (x=='W' || x=='w'){

							printf("Enter withdrawl amount\n");
							scanf("%lf", &withdrawed);
							//calls savings withdraw function
							withdrawSavings(withdrawed,saa,accindex);
							printf("Balance After Withdraw %.2lf\n",saa[accindex].ba.balance);
						}
					}
					else{	
						printf("Account Not Found\n");
					}
				}

				else if (action=='N' || action=='n'){
					//search through the struct of arrays and 
					//finds the account info
					printf("Enter Name\n");
					clear();
					scanf(" %[^\n]s",&name);

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
					printf("name %s\n", name);
					accindex = temp;
					printf("accindex %d\n", accindex);
					//from here we have the accindex

					if(accindex!=-1){	

						if (x=='D' || x=='d'){		
							printf("Enter deposit amount\n");
							scanf("%lf", &deposited);
							//calls deposit function
							depositSavings(deposited,saa,accindex);
							printf("balance after deposit %lf\n", saa[accindex].ba.balance);
						}

						if (x=='W' || x=='w'){

							printf("Enter withdrawl amount\n");
							scanf("%lf", &withdrawed);
							//calls withdraw function
							withdrawSavings(withdrawed,saa,accindex);		
							printf("balance after withdraw %lf\n", saa[accindex].ba.balance);
						}
					}
					else{
						printf("Account not Found\n");
					}
				}
				else{
					printf("Invalid Input\n");
				}
			}

			else if (type=='C' || type=='c'){

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

					if (accindex != -1){

						if (x=='D' || x=='d'){

							printf("Enter deposit amount\n");
							scanf("%lf", &deposited);
							//calls deposit function
							deposit(deposited,baa,accindex);
							printf("balance after deposit %lf\n", baa[accindex].balance);
						}

						if (x=='W' || x=='w'){

							printf("Enter withdrawl amount\n");
							scanf("%lf", &withdrawed);
							//calls withdraw function
							withdraw(withdrawed,baa,accindex);
							printf("balance after withdraw %lf\n", baa[accindex].balance);
						}

					}
					else{
						printf("Account Not Found\n");
					}
				}

				else if (action=='N' || action=='n'){
					//search through the struct of arrays and 
					//finds the account info
					printf("Enter Name\n");
					clear();
					scanf(" %[^\n]s",&name);

					printf("\n");				
					printf("DEBUG search for name\n");
					printf("Name is ");
					for (int n=0;n<N;n++){
						printf("%c",name[n]);

					}
					printf("\n");
					int temp = -1;
					for (int l = 0; l<N;l++){
						if(!strcmp(name,baa[l].name)){
							temp = l;
							l=N-1;
						}
					}
					printf("temp = %d\n", temp);
					printf("name %s\n", name);
					accindex = temp;
					printf("accindex %d\n", accindex);
					if (accindex!=-1){

						if (x=='D' || x=='d'){		
							printf("Enter deposit amount\n");
							scanf("%lf", &deposited);
							//calls deposit function
							deposit(deposited,baa,accindex);
							printf("balance after deposit %lf\n", baa[accindex].balance);
						}

						if (x=='W' || x=='w'){

							printf("Enter withdrawl amount\n");
							scanf("%lf", &withdrawed);
							//calls withdraw function
							withdraw(withdrawed,baa,accindex);
							printf("balance after withdraw %lf\n", baa[accindex].balance);
						}
					}

				}
				else{
					printf("3Not a Valid Input\n");
				}

			}
		}

		else if (x=='M' || x=='m'){

			printf("Savings(S) Or Checking(C)?\n");
			clear();
			scanf("%c", &make);	

			if (make=='S' || make=='s'){

				accnum = rand();
				printf("account num before check %d\n",accnum);

				for(n = 0; n<=js;n++){
					if(accnum == saa[n].ba.number && accnum < 0){
						accnum = rand();
						n = 0;
					}
				}

				printf("account num after check %d\n",accnum);
				js++;
				saa[js].ba.number = accnum;
				//since there is no inital savings account we do not update js 
				//at the top, rather we update js at the bottom because we need
				//to initialize this array 
				//makes a new account and copies name into the struct
				printf("Input account holder's name\n");
				clear();
				scanf(" %[^\n]s",&name);

				//printf("\n");				
				//printf("DEBUG search for name\n");
				//printf("Name is ");
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
				//printf("temp = %d\n", temp);


				//copies inital deposit into the struct	
				printf("Enter Deposit Amount\n");
				scanf("%lf", &initial_dep);

				printf("Enter interest rate\n");
				scanf("%lf", &interestrate);

				//printf("Enter New Account Number\n");
				//scanf("%lf", &accountnum);

				createNewSavingsAccount(name,initial_dep,interestrate,js,js,saa);
				printSavingsAccount(saa,js);

			}

			else if (make=='C' || make=='c'){

				accnum = rand();
				printf("account num before check%d\n",accnum);

				for(n = 0; n<=j;n++){
					if(accnum == baa[n].number && accnum < 0){
						accnum = rand();
						n = 0;
					}
				}

				printf("account num after check %d\n",accnum);
				j++;
				baa[j].number = accnum;
				//makes a new account and copies name into struct
				printf("Input account holder's name\n");
				clear();
				scanf(" %[^\n]s",&name);
				//scanf("%s", &name);

				//copies initial deposit into the struct
				printf("Enter deposit amount\n");
				scanf("%lf", &initial_dep);

				printf("Enter interest rate\n");
				scanf("%lf", &interestrate);

				createNewBankAccount(name,initial_dep,interestrate,j,j-1,baa);

				printBankAccount(baa,j);

			}
		}

		else if(x=='P' || x=='p'){
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
						monthlyprocesssavings(saa,accindex);
						printSavingsAccount(saa,accindex);
					}
					else{	
						printf("Account Not Found\n");
					}
				}

				else if (action=='N' || action=='n'){
					//search through the struct of arrays and 
					//finds the account info
					printf("Enter Name\n");
					clear();
					scanf(" %[^\n]s",&name);

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
					printf("name %s\n", name);
					accindex = temp;
					printf("accindex %d\n", accindex);
					//from here we have the accindex

					if (accindex != -1){
						monthlyprocesssavings(saa,accindex);
						printSavingsAccount(saa,accindex);

					}
					else{
						printf("Account not Found\n");
					}
				}
				else{
					printf("Invalid Input\n");
				}
			}

			else if (type=='C' || type=='c'){

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

					if (accindex != -1){
						monthlyprocess(baa,accindex);
						printBankAccount(baa,accindex);
					}
					else{
						printf("Account Not Found\n");
					}
				}

				else if (action=='N' || action=='n'){
					//search through the struct of arrays and 
					//finds the account info
					printf("Enter Name\n");
					clear();
					scanf(" %[^\n]s",&name);

					printf("\n");				
					printf("DEBUG search for name\n");
					printf("Name is ");
					for (int n=0;n<N;n++){
						printf("%c",name[n]);

					}
					printf("\n");
					int temp = -1;
					for (int l = 0; l<N;l++){
						if(!strcmp(name,baa[l].name)){
							temp = l;
							l=N-1;
						}
					}
					printf("temp = %d\n", temp);
					printf("name %s\n", name);
					accindex = temp;
					printf("accindex %d\n", accindex);
					if (accindex!=-1){

						monthlyprocess(baa,accindex);
						printBankAccount(baa,accindex);
					}

				}
				else{
					printf("4Not a Valid Input\n");
				}

			}

		}

		else {
			printf("2Not a valid Input\n");
		}

		/*for (int m=0;m<j;m++){
		  printBankAccount(baa,m);

		  }*/

		//! we could do the service here, after we loop through the teller or after every
		//action
		clear();
	}
}
