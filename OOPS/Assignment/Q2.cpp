#include <iostream>
using namespace std;

class BankAccount{
private:
int accountNumber,balance;
public:
BankAccount(int num,int bal){
    this->accountNumber=num;
    this->balance =bal;
}

void deposit(int accountNumber ,int Amount){
if(this->accountNumber!=accountNumber){
    cout<<"Incorrect account number\n";
}
else{
    this->balance+=Amount;
    cout <<"Deposit successful Total Balance :" << this->balance<<"\n";
}
}

void withdraw(int accountNumber ,int Amount){
if(this->accountNumber!=accountNumber){
    cout<<"Incorrect account number\n";
}
else{
    this->balance-=Amount;
    cout <<"Withdraw successful Total Balance :" << this->balance<<"\n";
}
}

void getbalance(int accountNumber){
if(this->accountNumber!=accountNumber){
    cout<<"Incorrect account number\n";
}
else{
    cout <<"Total Balance :" << this->balance<<"\n";
}
}

};

int main() {
    BankAccount ba1(321,23000);

    ba1.deposit(231,210); // Incorrect
    ba1.deposit(321,210); // correct
    ba1.withdraw(321,2110);
    ba1.getbalance(231); //Incorrect
    ba1.getbalance(321); 
    
    return 0;
}