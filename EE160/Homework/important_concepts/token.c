int main(){

	FILE * fp;
	char * line = NULL;
	char * line2 = NULL;
	size_t len = 0;
	size_t len2 = 0;
	ssize_t read ;
	ssize_t read2;
	char delim[]=" ";
	char* token;
	double x2;
	int i = 0;//counter for tokenizing 
	int j=0;//counter for the amount of lines which equals the amount of 
	//existing customers

	fp = fopen("bankaccount.txt", "r");
	if (fp==NULL)
		printf("Can't Open bankaccount.txt\n");

	while((read=getline(&line,&len,fp))!=-1){
		for(token=strtok(line,delim);token;token=strtok(NULL,delim)){

			//first part
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

}
