
/* Banking Application Project*/


#include<iostream>
using namespace std;
class Bank{
  public:	
	char name[50];
	long int accno;
	char type[25];
	float bal;
	float trans[3];
	int count=-1;
  public:
  	void getdata();
  	void getbal();
  	void withd();
  	void display();
    void transaction();
};
void Bank::getdata(){
	cout<<"\nENTER the name"<<endl ;
	cin>>name; 
	cout<<"ENTER the account number"<<endl;
	cin>>accno;
	cout<<"ENTER type of account"<<endl;
	cin>>type;
	cout<<"ENTER balance in account"<<endl;
	cin>>bal;
}
void Bank :: getbal(){
	float x;
	cout<<"Enter the balance"<<endl;
	cin>>x;
	bal=bal+x;
	count++;
	if(count>=3){
	  trans[0]=trans[1];
	  trans[1]=trans[2];
	  trans[2]=x;	
	}
	else{
		trans[count]=x;
	}
}
void Bank::withd(){
	if(bal<=1000)
	{
		cout<<"You can't withdroal money your balance is low"<<endl;
	}
	else{
		float x;
		cout<<"Enter the money you want to withdral"<<endl;
		cin>>x;
		if((bal-x)<=1000){
			cout<<"Sorry you Don't have sufficient Amount'"<<endl;
		}
		else{
			bal=bal-x;
				count++;
	if(count>=3){
	  trans[0]=trans[1];
	  trans[1]=trans[2];
	  trans[2]=-x;	
	}
	else{
		trans[count]=-x;
	}
		}
	}
}
void Bank :: display(){
	cout<<"Name of user:   \t"<<name<<endl;
	cout<<"Accoungt number:\t"<<accno<<endl;
	cout<<"type of account:\t"<<type<<endl;
	cout<<"Total balance:  \t"<<bal<<endl;
}
void Bank :: transaction(){
	int i;
	for(i=0;i<3;i++){
		if(trans[i]<0){
			cout<<"Amount Withdraw from Account is :"<<-(trans[i])<<endl;
		}
		else{
			cout<<"Amount Add in Account is :"<<trans[i]<<endl;
		}
	}
} 
int main(){
	Bank obj[100];
	int x,a,flag=0;
	int count=0,count1;
	char ch='y';
	cout<<"Following Option For Work \nEnter '1' For New Account \nEnter '2' For Adding Amount in Bank Account \nEnter '3' For Withdraw the Amount from Bank Account \nEnter '4' For Display The Complete Info for Bank Account \nEnter '5' For See Last 3 Transaction"<<endl;
   do{
              
      cout<<"Enter Work option"<<endl;
	  cin>>a;
	switch(a){
	
	case 1 : {
		   	
		obj[count].getdata();
		count++;
                
		break;
	}
    case 2 : {
    flag=0;
    cout<<"Enter the account Number to Add balance"<<endl;
    cin>>x;
    for(int i=0;i<count;i++){
         if(x== obj[i].accno) {
         		obj[i].getbal();
         		flag=1;
		 }   	
	}
	if(flag==0){
		cout<<"No Such Account is Found \n Please Add Proper Account Number"<<endl;
	}
		break;
	}
    case 3 : {
    flag=0;
   cout<<"Enter the account Number to remove balance"<<endl;
    cin>>x;
    for(int i=0;i<count;i++){
         if(x== obj[i].accno) {
         	obj[i].withd();
         	flag=1;
		 }    	
	}
	if(flag==0){
		cout<<"No Such Account is Found \n Please Add Proper Account Number"<<endl;
	}	            
		break;
	}
    case 4 : {
    flag=0;
   cout<<"Enter the account Number to display the info. "<<endl;
    cin>>x;
    for(int i=0;i<count;i++){
         if(x== obj[i].accno) {
         	obj[i].display();
         	flag=1;
		 }
   	}
	if(flag==0){
		cout<<"No Such Account is Found \n Please Add Proper Account Number"<<endl;
	}     		
                  
		break;
	}
	case 5 : {
	    flag=0;
   cout<<"Enter the account Number to See Last 3 Transaction "<<endl;
    cin>>x;
    for(int i=0;i<count;i++){
         if(x== obj[i].accno) {
         	obj[i].transaction();
         	flag=1;
		 }
   	}
	if(flag==0){
		cout<<"No Such Account is Found \n Please Add Proper Account Number"<<endl;
	}	
		break;
	}

  }
  cout<<"Do you want to continue For Work y/n"<<endl;
  cin>>ch;
 }while(ch=='y');
 
	return 0;
}
