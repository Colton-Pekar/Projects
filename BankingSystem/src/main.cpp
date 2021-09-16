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
        cout << "1) create account" << endl << "2) update information of an existing account" << endl << "3) Make an account transaction" << endl;
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
    cout << "what is your new job?" << endl, cin >> newcustomer.job;

    TD.CustomerList = TD.newCustomer(newcustomer, nextIndex);
    nextIndex++;
    return TD.CustomerList;
}

map <int, struct customerInfo> modifyInformation(int customerKey){
    customerInfo tempCustomer;
    tempCustomer = TD.CustomerList.at(customerKey);
    bool save = false;
    //use temp for edits incase you discard
    cout << "what is your new name? " << endl, cin >> tempCustomer.name;
    cout << "what is your new  age? " << endl, cin >> tempCustomer.age;
    cout << "what is your new birthday? " << endl, cin >> tempCustomer.birthday;
    cout << "what is your new job? " << endl, cin >> tempCustomer.job;
    cout << "Press '1' to save these changes, press '0' to discard " << endl, cin >> save
    //store temp to database
    if save == true{
        TD.CustomerList.at(customerKey) = tempCustomer;
        return;
    }
    else{
        return;
    }
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
            //print each element of updated customer list
            for(auto elem : TD.CustomerList{
                std::cout << elem.first << " " << elem.second.name << " " << elem.second.bankID << "\n";
            }
            break;
                        
        case 2: //update customer information
            int key = 0;
            cout << "hi there, what is your database key? " << endl, cin >> key;
            TD.CustomerList = TD.modifyInformation(key);
            //print each element of updated customer list
            for(auto elem : TD.CustomerList{
                std::cout << elem.first << " " << elem.second.name << " " << elem.second.bankID << "\n";
            }
            break;
                
        case 3: //Make an account transaction
                
        default:
            break;
        }
    cout << "would you like to enter another mode?" << endl;
    cin >> enter;
    }

    return 0;

}
