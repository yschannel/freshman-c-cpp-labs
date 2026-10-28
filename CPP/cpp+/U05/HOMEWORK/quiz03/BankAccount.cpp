#include"BankAccount.hpp"
#include<iostream>

int BankAccount::defaultBankAccount = 1000;
double BankAccount::totalBankReserve = 0.0;

BankAccount::BankAccount():id(defaultBankAccount++),balance(0.0){
    std::cout << "Account " << id << " created with initial balance: 0.0" << std::endl;
}

BankAccount::BankAccount(double initialbalance): id(defaultBankAccount++),balance(initialbalance){
    totalBankReserve += initialbalance;
    std::cout << "Account " << id << " created with initial balance: " << initialbalance << std::endl;
}

BankAccount::~BankAccount(){
    totalBankReserve -= balance;
    std::cout << "Account " << id << " destroyed. Balance removed from bank reserve." << std::endl;
    std::cout << "Now Total Bank Reserve: " << BankAccount::getTotalBankReserve() << std::endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        totalBankReserve += amount; 
        std::cout << "Deposited " << amount << " to account " << id << ". New balance: " << balance << std::endl;
    }
}

void BankAccount::withdraw(double amount){
    if(amount > 0 && amount <= balance){
        balance -= amount;
        totalBankReserve -= amount;
        std::cout << "Withdrew " << amount << " from account " << id << ". New balance: " << balance << std::endl;
    }else{
        std::cout << "Insufficient funds or invalid amount for account " << id << "." << std::endl;
        return;
    }
}

double BankAccount::getBalance() const{
    return balance;
}

double BankAccount::getTotalBankReserve(){
    return totalBankReserve;
}

int main(){
    BankAccount acc1(6000.0);
    BankAccount acc2;
    BankAccount acc3{200.0};

    std::cout << "Total Bank Reserve after creating 3 accounts: " << BankAccount::getTotalBankReserve() << std::endl;

    {
        BankAccount Acc4(520.0);
        std::cout << "Total Bank Reserve with Acc4 account: " << BankAccount::getTotalBankReserve() << std::endl;
    }

    return 0;
}