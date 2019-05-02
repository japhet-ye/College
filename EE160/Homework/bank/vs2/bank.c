//driver for bank subs

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"bank.h"

void createNewSavingsAccount(char* name, double balance, double interest, int index, struct savingsAccount sa[]){

	if( balance > 0 && interest > 0){

		strcpy(sa[index].ba.name,name);
		sa[index].ba.balance = balance;
		sa[index].ba.interest = interest;
		sa[index].ba.numdeposits = 1;
		sa[index].ba.with = 0;
		sa[index].ba.numoverdrafts = 0;
		sa[index].ba.fees = 0;
		sa[index].ba.servicecharge = 0;

		if (balance < 25){
			sa[index].status = 0;
		}

		if (balance>= 25){
			sa[index].status = 1;
		}
		else{
			printf("Not a valid deposit input\n");
		}

	}

	else{
		printf("One or Multiple Input(s) are invalid\n");
	}

}

void withdrawSavings(double withdraw, struct savingsAccount sa[], int index){
	char neg;

	if (withdraw<sa[index].ba.balance && withdraw>0){
		sa[index].ba.balance-=withdraw;
		sa[index].ba.with++;

		if(sa[index].ba.balance>=25){
			sa[index].status=1;
		}
	}
	if (withdraw>sa[index].ba.balance){
		printf("Withdrawing more than balance do you wish to continue?(Y or N)\n");
		printf("Debug, after negative balance\n");
		clear();
		scanf("%c", &neg);
		printf("Debug neg %c\n", neg);
		if(neg=='Y'|| neg=='y'){
			sa[index].ba.balance-=withdraw;
			sa[index].ba.numoverdrafts++;
			sa[index].ba.with++;
		}
		else if(neg=='N' || neg=='n'){
			printf("cancelling transaction\n");
		}
		else{
			printf("Not a valid input, cancelling transaction\n");

		}

	}
	else{
		printf("Not a withdraw amount\n");
	}
}

void depositSavings(double deposit, struct savingsAccount sa[], int index){

	if (deposit>0){
		sa[index].ba.balance+=deposit;
		sa[index].ba.numdeposits++;

		if(sa[index].ba.balance>=25){
			sa[index].status=1;
		}
	}
	else{
		printf("Not a valid deposit input\n");
	}
}

void monthlyprocesssavings(struct savingsAccount sa[], int index){
	if(sa[index].ba.with > 4){
		int monthlyservicecharge =+ (sa[index].ba.with - 4) * sa[index].ba.servicecharge;


	}


}

void createNewBankAccount(char* name, double balance, double interest, int index, struct bankAccount ba[]){

	if (balance>0 && interest>0){
		strcpy(ba[index].name,name);
		ba[index].balance = balance;
		ba[index].interest = interest;
		ba[index].numdeposits = 1;
		ba[index].with = 0;
		ba[index].numoverdrafts = 0;
		ba[index].fees = 0;
		ba[index].servicecharge = 0;
	}
	else{
		printf("Input(s) are inavld\n");
	}
}

void deposit(double deposit, struct bankAccount ba[], int index){

	if(deposit>0){
		ba[index].balance = deposit + ba[index].balance;
		ba[index].numdeposits++;
	}
	else{
		printf("Not valid deposit amount\n");
	}
}

void withdraw(double withdraw, struct bankAccount ba[], int index){
	char neg;

	if(withdraw<ba[index].balance && withdraw > 0){
		ba[index].balance-=withdraw;
		ba[index].with++;
	}
	if(withdraw>ba[index].balance&& withdraw>0){
		printf("Withdrawing more than balance do you wish to continue?(Y or N)\n");
		clear();
		scanf("%c", &neg);
		if(neg=='Y' || neg=='y'){
			ba[index].balance-=withdraw;
			ba[index].with++;
			ba[index].numoverdrafts++;
		}
		if(neg=='N' || neg=='n'){
			printf("Cancelling transaction\n");
		}
		else{
			printf("Not a Valid Input, Cancelling transaction\n");
		}
	}
	else{
		printf("Not a valid withdraw amount\n");
	}
}

void calcinterest(struct bankAccount ba[], int index){
	double monthlyinterestrate = ba[index].interest/12;
	double monthlyinterest = ba[index].balance * monthlyinterestrate;
	ba[index].balance+=monthlyinterest;	

}

void monthlyprocess(struct bankAccount ba[], int index){
	ba[index].balance-=ba[index].servicecharge;
	calcinterest(ba,index);
	ba[index].numdeposits = 0;
	ba[index].with = 0;
	ba[index].servicecharge = 0;
}

int searchBaccount(struct bankAccount ba[], double account){
	int i;
	for (i=0;i<N;i++){
		if(ba[i].number == account){
			return i;
		}
	}
	return -1;
}

int searchSaccount(struct savingsAccount sa[], double account){
	int i;
	for (i=0;i<N;i++){
		if(sa[i].ba.number == account){
			return i;
		}
	}
	return -1;
}

void sortbankaccount(struct bankAccount ba[], int size){
	int i;
	for (i=0;i<size;i++){


	}
}

int maxbalancebankaccount(struct bankAccount ba[], int size){





}

void sortsavingsaccount(struct savingsAccount sa[], int size){




}

int maxbalancesavingsaccount(struct savingsAccount sa[], int size){




}

void clear(void){
	while(getchar()!='\n');
}


