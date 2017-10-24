//
//  main.cpp
//  ATM machine
//
//  Created by md. khan on 11/8/14.
//  Copyright (c) 2014 md khan. All rights reserved.
//

#include <iostream>

using namespace std;
void menuOptions();

int main()
{
    string loginIDArray[]={"one","two","three","four","five"};
    string passwordArray[]={"1111","2222","3333","4444","5555"};
    string accountHolderName[]={"Khan","Rohit","Noman","Sunny","Peter"};
    int accountNumber[]={123,456,789,1011,1213};
    double balance[]={20000.0,30000.0,40000.0,50000.0,60000.0};
    string loginID;
    string password;
    bool flag=false,accountFlag=false;
    int i=0,remainderValue;
    int accountTransfer1, accountTransfer2;
    int option=0;
    double amount=0.0;
    int position=0;
    char userChoice;
    cout<<"\n  ****** Welcome to my new ATM Machine project ********\n*****Please enter your User id & password to login*****:"<<endl;
    cout<<"\nEnter User id:";
    cin>>loginID;
    cout<<"\nEnter Password:"<<endl;
    cin>>password;
    
    for(i=0;i<5;i++){
        
        if(loginIDArray[i]==loginID && passwordArray[i]==password){
            flag=true;
            position=i;
            break;
        }
    }
    
    if(flag==false){
        cout<<"\nSorry! wrong login id & password"<<endl;
    }else{
        while(option!=5){
            menuOptions();
            cout<<"\nEnter your choice:"<<endl;
            cin>>option;
            switch(option){
                case 1: cout<<"Enter the amount:"<<endl;
                    cin>>amount;
                    if(balance[position]<amount){
                        cout<<"\nYou do not have sufficient balance to perform this transaction"<<endl;
                    }else{
                        balance[position]=balance[position]-amount;
                        cout<<"\nCash successfully withdrawn!!";
                        cout<<"\nDo you want print the receipt(y/n)?";
                        cin>>userChoice;
                        if(userChoice=='y'){
                            cout<<"\nAccount: #"<<accountNumber[position]<<endl;
                            cout<<"\nWithdrawn:"<<amount<<endl;
                            cout<<"\ncurrent Balance:"<<balance[position]<<endl;
                        }
                    }
                    break;
                case 2:cout<<"Enter the amount:"<<endl;
                    cin>>amount;
                    balance[position]=balance[position]+amount;
                    cout<<"\nCash successfully deposited!!";
                    cout<<"\nDo you want print the receipt(y/n)?";
                    cin>>userChoice;
                    if(userChoice=='y'){
                        cout<<"\nAccount: #"<<accountNumber[position]<<endl;
                        cout<<"\nDeposited:"<<amount<<endl;
                        cout<<"\n current Balance:"<<balance[position]<<endl;
                    }
                    break;
                    
                    
                case 3:cout<<"\nEnter the amount in multiples of 100"<<endl;
                    cin>>amount;
                    remainderValue=(int)amount % 100;
                    while(remainderValue!=0){
                        cout<<"Sorry! Please enter the amount in multiples of 100 only"<<endl;
                        cin>>amount;
                        remainderValue=(int)amount % 100;
                    }
                    cout<<"\nEnter the account number for the cash transfer:"<<endl;
                    cin>>accountTransfer1;
                    accountFlag=false;
                    for(i=0;i<5;i++){
                        if(accountTransfer1==accountNumber[i]){
                            cout<<"\nAccount Holder's name is : "<<accountHolderName[i]<<endl;
                            cout<<"\nConfirm account number:"<<endl;
                            cin>>accountTransfer2;
                            if(accountTransfer1==accountTransfer2){
                                balance[i]=balance[i]+amount;
                                balance[position]=balance[position]-amount;
                                cout<<"\nCash transferred successfully"<<endl;
                                cout<<"\ncurrent Balance:"<<balance[position]<<endl;
                            }else{
                                cout<<"\nBoth account numbers do not match"<<endl;
                            }
                            accountFlag=true;
                            break;
                        }
                    }
                    if(accountFlag==false){
                        cout<<"\n Given account number didn't found in database"<<endl;
                    }
                    break;
                    
                case 4: cout<<"\nAccount: #"<<accountNumber[position]<<endl;
                    cout<<"\ncurrent Balance:"<<balance[position]<<endl;
                    break;
                case 5:cout<<"Done! Thanks for using the bank services"<<endl;
                    break;
            }
        }
        
    }
}

void menuOptions(){
    cout<<"\n----**** main screen ****----"<<endl;
    cout<<"\n1---Withdraw Cash"<<endl;
    cout<<"\n2---Deposit Cash"<<endl;
    cout<<"\n3---Cash Transfer"<<endl;
    cout<<"\n4---Balance Inquiry"<<endl;
    cout<<"\n5---Exit"<<endl;
}
