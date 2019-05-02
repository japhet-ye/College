//header for bank subs

#define SIZE 100
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


void createNewSavingsAccount(char* name, double balance, double interest, int index, int j, struct savingsAccount sa[]);

void withdrawSavings(double withdraw, struct savingsAccount sa[], int index);

void depositSavings(double deposit, struct savingsAccount sa[], int index);

void monthlyprocesssavings(struct savingsAccount sa[], int index);

void createNewBankAccount(char* name, double balance, double interest, int index, int j, struct bankAccount ba[]);

void deposit(double deposit, struct bankAccount ba[], int index);

void withdraw(double withdraw, struct bankAccount ba[], int index);

void calcinterest(struct bankAccount ba[], int index);

void calcinterestsavings(struct savingsAccount sa[], int index);

void monthlyprocess(struct bankAccount ba[], int index);

int searchBaccount(struct bankAccount ba[], double account); 

int searchSaccount(struct savingsAccount sa[], double account);

void sortbankaccount(struct bankAccount ba[],int size);

int maxbalancebankaccount(struct bankAccount ba[],int start, int size);

void sortsavingsaccount(struct savingsAccount sa[], int size);

int maxbalancesavingsaccount(struct savingsAccount sa[], int size);

void clear(void);

int findn(int n);

int randomNumber(int j, struct bankAccount ba[]);
