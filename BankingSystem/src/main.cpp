#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct customerInfo{
        string name;
        string birthday;
        string job;
        int age;
        int bankID;
};

class bankStructure{
    private:
    
    public:

    map <int, struct customerInfo> CustomerList;

    string bankintro(){
        string enter;
        cout << "would you like to enter TD?" << endl;
        cin >> enter;
        return enter;
    }

    int ModeSelection(int mode){
        cout << "hi, welcome to TD." << endl << "Please select from the following: " << endl;
        cout << "1) create account" << endl << "2) update information of an existing account" << endl << "3) view/manage transactions" << endl;
        cout << "4) check the details of an existing account" << endl << "5) remove existing account" << endl << "6) view customer list" << endl;
        cin >> mode;
        return mode;
    }

    map <int, struct customerInfo> newCustomer(customerInfo newCust, int key){
        //generate bank id
        newCust.bankID = (newCust.age*newCust.age);

        //insert into bank db
        CustomerList.insert({key, newCust});
        return CustomerList;
    }
    
};

class BankModes:public bankStructure{
private:
bankStructure TD;
public:
int nextIndex = 0;
customerInfo newcustomer;
map <int, struct customerInfo> createAccount(int &nextIndex){
    cout << "what is your name" << endl, cin >> newcustomer.name;
    cout << "how old are you" << endl, cin >> newcustomer.age;
    cout << "what is your birthday" << endl, cin >> newcustomer.birthday;
    cout << "how old are you" << endl, cin >> newcustomer.job;

    TD.CustomerList = TD.newCustomer(newcustomer, nextIndex);
    nextIndex++;

    for(auto elem : TD.CustomerList)
        {
        std::cout << elem.first << " " << elem.second.name << " " << elem.second.bankID << "\n";
        }
    return TD.CustomerList;
}


};

int main(){

    BankModes TD;
    int mode;
    string enter;
    int nextIndex = 0;
    
    //call teller intro
    enter = TD.bankintro();
    
    while (enter == "yes"){
        //select the bank teller mode
        mode = TD.ModeSelection(mode);

        switch (mode)
        {
        case 1: //create account
            TD.CustomerList = TD.createAccount(nextIndex);
            cout << nextIndex;
            break;
        
        default:
            break;
        }
    cout << "would you like to enter another mode?" << endl;
    cin >> enter;
    }

    return 0;

}