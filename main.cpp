#include <iostream>
#include <string>
#include <ctime>


#include <iostream>
#include <vector>

#include <sstream>
#include <fstream>


#include<stdio.h>
#include<conio.h>
#include<math.h>

//#include <openssl/sha.h>  // Requires OpenSSL library
using namespace std;

// کلاس پایه شخص
class Person
{
protected:

    std::string nationalId;
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string gender;
    std::string joinDate;
    std::string password;
    bool isLogin;

public:
    Person(string _nationalId,
           string _password)
    {
        nationalId=_nationalId;
        password=_password;

    }

    Person(string _nationalId,
           string _firstName,
           string _lastName,
           string _dateOfBirth,
           string _gender,
           string _joinDate,
           string _password   )
    {

        nationalId=_nationalId;
        firstName=_firstName;
        lastName=_lastName;
        dateOfBirth=_dateOfBirth;
        gender=_gender;
        joinDate=_joinDate   ;
        password=_password  ;
    };


    bool getIsLogin()
    {
        return isLogin;
    }
    void setLogin( bool r)
    {
        isLogin=r;

    }
    std::string getNationalId() const
    {
        return nationalId;
    }

    std::string getFirstName() const
    {
        return firstName;
    }

    std::string getLastName() const
    {
        return lastName;
    }

    std::string getDateOfBirth() const
    {
        return dateOfBirth;
    }

    std::string getGender() const
    {
        return gender;
    }

    std::string getJoinDate() const
    {
        return joinDate;
    }

    // Setter methods
    void setPassword(const std::string& pass)
    {
        password = pass;
    }
    string getPassword()
    {
        return  password ;
    }
    // Other methods
    bool authenticate(const std::string& id, const std::string& pass) const
    {
        // setLogin(true);
        return (nationalId == id && password == pass);
    }

    void displayInfo()
    {
        cout << "Name: " << firstName << endl;
        cout << "ID: " << nationalId << endl;
    }

};

class Transaction
{
private:
    string description;  // Transaction description
    double amount;       // Transaction amount

public:
    Transaction(const string& desc, double amt) : description(desc), amount(amt) {}

    string getDescription() const
    {
        return description;
    }

    double getAmount() const
    {
        return amount;
    }
};

// کلاس حساب
class Account
{
private:
    string id;
    double balance;

    string accountType;

public:
    vector<Transaction> transactions;

    Account(string _id,double _balance,string _accountType)
    {
        id=_id;
        balance=_balance;
        accountType=_accountType;



    }

    string getId() const
    {
        return id;
    }

    double getBalance() const
    {
        return balance;
    }

    string getAccountType() const
    {
        return accountType;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            Transaction _trans("Deposit: +" + to_string(amount),amount);
            transactions.push_back(_trans);
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <=balance)
        {
            balance -= amount;
            Transaction _trans("Deposit: -" + to_string(amount),amount);
            transactions.push_back(_trans);
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }


    void displayInfo() const
    {
        cout << "Account ID: " << id << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    void displayTransactions() const
    {
        cout << "Transaction History: " << endl;


        for (int i=0 ; i<transactions.size(); i++)
        {

            cout<<transactions[i].getDescription()<<endl;

        }

    }


};


// کلاس وام
class Loan
{
private:
    int id;
    double interestRate;  // نرخ سود وام
    int amount;  // مفدار

public:
    Loan(int _id, double _interestRate, int _amount)
    {
        id = _id;
        interestRate = _interestRate;
        amount = _amount;
    }

    // Getter functions
    int getId()
    {
        return id;
    }

    double getInterestRate()
    {
        return interestRate;
    }

    int getAmount()
    {
        return amount;
    }
    void displayInfo()
    {
        cout << "id: " << id << endl;
        cout << "rate: " << interestRate << endl;
        cout << "amount: " << amount << endl;
        cout << "*****************"<< endl;
    }
};
// کلاس مشتری
class Customer:Person
{
private:



public:
    //Customer(const string& custName) : name(custName) {}
    vector<Account> accounts;
    vector<Loan> loans;

    void viewAccounts()
    {

        for (int i = 0; i < accounts.size(); i++)
        {

            accounts[i].displayInfo();



        }
    }


    void transferMoney(string sourceAccountid,Customer customer,string _accountid,double amount)
    {


        for (int i = 0; i < accounts.size(); i++)
        {

            if (accounts[i].getId()==sourceAccountid)
            {
                accounts[i].withdraw(amount);
                break;

            }

        }

        for (int i = 0; i < customer.accounts.size(); i++)
        {

            if (customer.accounts[i].getId()==_accountid)
            {
                customer.accounts[i].deposit(amount);
                break;

            }

        }


    }



    void viewAccountTransactions(string accountId)
    {



        for (int i = 0; i < accounts.size(); i++)
        {

            if (accounts[i].getId()==accountId)
            {
                accounts[i].displayTransactions();
                break;

            }

        }

    }




    Customer( string _nationalId,
              string _firstName,
              string _lastName,
              string _dateOfBirth,
              string _gender,
              string _joinDate,
              string _password   ):Person( _nationalId,
                                               _firstName,
                                               _lastName,
                                               _dateOfBirth,
                                               _gender,
                                               _joinDate,
                                               _password )
    {

        nationalId=_nationalId;
        firstName=_firstName;
        lastName=_lastName;
        dateOfBirth=_dateOfBirth;
        gender=_gender;
        joinDate=_joinDate   ;
        password=_password  ;
    };



    std::string getNationalId() const
    {
        return nationalId;
    }

    std::string getFirstName() const
    {
        return firstName;
    }

    std::string getLastName() const
    {
        return lastName;
    }

    std::string getDateOfBirth() const
    {
        return dateOfBirth;
    }

    std::string getGender() const
    {
        return gender;
    }

    std::string getJoinDate() const
    {
        return joinDate;
    }

    string getPassword() const
    {
        return  password ;
    }
    void displayInfo()
    {
        cout << "ID: " << nationalId << endl;
        cout << "Name: " << firstName << endl;
        cout << "Lastname: " << lastName << endl;


    }

    void displayLoans()
    {


        for (int i=0; i<<i<loans.size(); i++)
        {
            loans[i].displayInfo();
        }



    }


    bool login(string id,string _password)
    {


        if (nationalId==id && password==_password)
        {


            return true;


        }
        else
        {

            return false;
        }

    }
};


// کلاس کارمند
class Employee:Person
{




public:

    Employee( string _nationalId,
              string _firstName,
              string _lastName,
              string _dateOfBirth,
              string _gender,
              string _joinDate,
              string _password   ):Person( _nationalId,
                                               _firstName,
                                               _lastName,
                                               _dateOfBirth,
                                               _gender,
                                               _joinDate,
                                               _password )
    {

        nationalId=_nationalId;
        firstName=_firstName;
        lastName=_lastName;
        dateOfBirth=_dateOfBirth;
        gender=_gender;
        joinDate=_joinDate   ;
        password=_password  ;
    };



    std::string getNationalId() const
    {
        return nationalId;
    }

    std::string getFirstName() const
    {
        return firstName;
    }

    std::string getLastName() const
    {
        return lastName;
    }

    std::string getDateOfBirth() const
    {
        return dateOfBirth;
    }

    std::string getGender() const
    {
        return gender;
    }
string getPassword() const
    {
        return  password ;
    }
    std::string getJoinDate() const
    {
        return joinDate;
    }
    void displayInfo()
    {
        cout << "Name: " << firstName << endl;
        cout << "ID: " << nationalId << endl;
    }



     bool login(string id,string _password)
    {


        if (nationalId==id && password==_password)
        {


            return true;


        }
        else
        {

            return false;
        }

    }


};



class Manager:Person
{


public :



    Manager( string _nationalId,

             string _password   ):Person( _nationalId,

                                              _password )
    {


        nationalId=_nationalId;
        password=_password;





    }


    bool login(string _nationalId,string _password)
    {


        if(_nationalId=="admin" && _password=="1234")
        {



            // mclass.currentManagerId="admin";


            cout<<"Login success..."<<endl;

            return true;

        }
        else
        {
            // mclass.currentManagerId=nullptr;
            return false;
            cout<<"Login fail..."<<endl;
        }




    }



};
/////////////////////////////////////////////menu


#include <limits>
class mainClass
{

public:
    vector <Person> persons;
    vector <Customer> customers;
    vector <Employee> emps;
    vector<Account> accounts;
    vector<Loan> loans;
    vector<string> requestacoounts;
    vector<string> requestadelete;
    vector<string> requestaLoan;
    string currentCustomerId="-0";
    string currentEmpId="-0";
    string currentManagerId;





};
void managerMenu(mainClass& mClass)
{
    int choice;
    bool running = true;

    while (running)
    {
        std::cout << "Manager Menu\n";
        std::cout << "0.  login \n";
        std::cout << "1.  add employee \n";
        std::cout << "2.  edit employee\n";
        std::cout << "3.  delete employee\n";
        std::cout << "4.  employee list\n";
        std::cout << "5.  search employee \n";
        //////////////////////////////////////////
        std::cout << "6.  add customer \n";
        std::cout << "7.  edit customer\n";
        std::cout << "8.  delete customer\n";
        std::cout << "9.  customer list\n";
        std::cout << "10. search customer \n";
        //////////////////////////////////////////
        std::cout << "11. add loan \n";
        std::cout << "12. delete loan\n";
        std::cout << "13. loan list\n";

        //////////////////////////////////////////
        std::cout << "14. transactions list  \n";
        std::cout << "15. search  transactions\n";


        //////////////////////////////////////////

        std::cout << "15. add account \n";
        std::cout << "16. delete  account\n";
        std::cout << "17. list  account  request\n";
        std::cout << "18. list  account  delete\n";
        cout<<"19. account list\n";



        /////////////////////////////////


        std::cout << "20. view  requests for loan \n";
        std::cout << "21. confirm   loan \n";


        std::cout << "30. Go back\n";


        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 0:
        {
            string username;
            string password;

            cout<<"enter manager username: "<<endl;
            cin>>username;

            cout<<"enter manager password: "<<endl;
            cin>>password;


            Manager manager(username,password);
            bool _login=false;
            _login=manager.login(username,password);
            if(_login==true)
            {

                mClass.currentManagerId="admin";
                std::cout << "login success......... \n";

            }
            else
            {

                mClass.currentManagerId="";
                std::cout << "login fail......... \n";

            }



            break;
        }

        case 1:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            std::cout << "National Id: ";
            std::string _nationalId;
            std::cin >> _nationalId;


            std::cout << "firstName: ";
            std::string _firstName;
            std::cin >> _firstName;



            std::cout << "lastName: ";
            std::string _lastName;
            std::cin >> _lastName;



            std::cout << "date Of birth: ";
            std::string _dateOfBirth;
            std::cin >> _dateOfBirth;




            std::cout << "gender ";
            std::string _gender;
            std::cin >> _gender;



            std::cout << "join date ";
            std::string _joinDate;
            std::cin >> _joinDate;




            std::cout << "password ";
            std::string _password;
            std::cin >> _password;


            Employee emp( _nationalId,
                          _firstName,
                          _lastName,
                          _dateOfBirth,
                          _gender,
                          _joinDate,
                          _password   );

            mClass.emps.push_back(emp);



            break;
        }

        case 2:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            string emp_number_to_delete;

            std::cout << "enter employee id to edit: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.emps.size(); i++)
            {
                if (mClass.emps[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.emps.erase(mClass.emps.begin() + i);
                    found = true;
                    break;
                }
            }

            std::cout << "National Id: ";
            std::string _nationalId;
            std::cin >> _nationalId;


            std::cout << "firstName: ";
            std::string _firstName;
            std::cin >> _firstName;



            std::cout << "lastName: ";
            std::string _lastName;
            std::cin >> _lastName;



            std::cout << "date Of birth: ";
            std::string _dateOfBirth;
            std::cin >> _dateOfBirth;




            std::cout << "gender ";
            std::string _gender;
            std::cin >> _gender;



            std::cout << "join date ";
            std::string _joinDate;
            std::cin >> _joinDate;




            std::cout << "password ";
            std::string _password;
            std::cin >> _password;


            Employee emp( _nationalId,
                          _firstName,
                          _lastName,
                          _dateOfBirth,
                          _gender,
                          _joinDate,
                          _password   );

            mClass.emps.push_back(emp);







            break;
        }

        case 3:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            string emp_number_to_delete;

            std::cout << "enter employee id to delete: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.emps.size(); i++)
            {
                if (mClass.emps[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.emps.erase(mClass.emps.begin() + i);
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "employee deleted successfully" << endl;
            }
            else
            {
                cout << "employee not found" << endl;
            }


            break;
        }

        case 4:
        {



            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }

            std::cout << "employee list.\n";
            std::cout << "---------------------\n";
            for(int i=0; i<mClass.emps.size(); i++)
            {

                mClass.emps[i].displayInfo();
                cout<<endl;
            }


            break;
        }
        case 5:
        {

            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            string emp_number_to_delete;
            std::cout << "enter employee id to search: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.emps.size(); i++)
            {
                if (mClass.emps[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.emps[i].displayInfo();
                    cout<<endl;
                    break;
                }
            }

            if (found)
            {
                cout << "employee find successfully" << endl;
            }
            else
            {
                cout << "employee not found" << endl;
            }


            break;
        }

        case 6:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            std::cout << "National Id: ";
            std::string _nationalId;
            std::cin >> _nationalId;


            std::cout << "firstName: ";
            std::string _firstName;
            std::cin >> _firstName;



            std::cout << "lastName: ";
            std::string _lastName;
            std::cin >> _lastName;



            std::cout << "date Of birth: ";
            std::string _dateOfBirth;
            std::cin >> _dateOfBirth;




            std::cout << "gender ";
            std::string _gender;
            std::cin >> _gender;



            std::cout << "join date ";
            std::string _joinDate;
            std::cin >> _joinDate;




            std::cout << "password ";
            std::string _password;
            std::cin >> _password;


            Customer emp( _nationalId,
                          _firstName,
                          _lastName,
                          _dateOfBirth,
                          _gender,
                          _joinDate,
                          _password   );

            mClass.customers.push_back(emp);

            break;
        }
        case 7:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            string emp_number_to_delete;

            std::cout << "enter customer id to edit: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.customers.erase(mClass.customers.begin() + i);
                    found = true;
                    break;
                }
            }

            std::cout << "National Id: ";
            std::string _nationalId;
            std::cin >> _nationalId;


            std::cout << "firstName: ";
            std::string _firstName;
            std::cin >> _firstName;



            std::cout << "lastName: ";
            std::string _lastName;
            std::cin >> _lastName;



            std::cout << "date Of birth: ";
            std::string _dateOfBirth;
            std::cin >> _dateOfBirth;




            std::cout << "gender ";
            std::string _gender;
            std::cin >> _gender;



            std::cout << "join date ";
            std::string _joinDate;
            std::cin >> _joinDate;




            std::cout << "password ";
            std::string _password;
            std::cin >> _password;


            Customer cust( _nationalId,
                           _firstName,
                           _lastName,
                           _dateOfBirth,
                           _gender,
                           _joinDate,
                           _password   );

            mClass.customers.push_back(cust);


            break;
        }

        case 8:
        {



            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }

            string emp_number_to_delete;

            std::cout << "enter customer id to delete: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.customers.erase(mClass.customers.begin() + i);
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "customer deleted successfully" << endl;
            }
            else
            {
                cout << "customer not found" << endl;
            }

            break;
        }
        case 9:
        {

            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            std::cout << "customers list.\n";
            std::cout << "---------------------\n";
            for(int i=0; i<mClass.customers.size(); i++)
            {

                mClass.customers[i].displayInfo();
                cout<<endl;
            }

            break;
        }

        case 10:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            string emp_number_to_delete;
            std::cout << "enter customer id to search: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.customers[i].displayInfo();
                    cout<<endl;
                    break;
                }
            }

            if (found)
            {
                cout << "customer find successfully" << endl;
            }
            else
            {
                cout << "customer not found" << endl;
            }


            break;
        }
        case 11:
        {

            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            std::cout << "loan Id: ";
            std::string _id;
            std::cin >> _id;


            std::cout << "loan amount: ";
            std::string _amount;
            std::cin >> _amount;



            std::cout << "loan rate: ";
            std::string _rate;
            std::cin >> _rate;


            Loan loan(stoi(_id),stod(_rate),stoi(_amount));
            mClass.loans.push_back(loan);
            break;
        }

        case 12:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            int emp_number_to_delete;

            std::cout << "enter loan id to delete: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.loans.size(); i++)
            {
                if (mClass.loans[i].getId() == emp_number_to_delete)
                {
                    mClass.loans.erase(mClass.loans.begin() + i);
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "loan deleted successfully" << endl;
            }
            else
            {
                cout << "loan not found" << endl;
            }
            break;
        }
        case 13:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            std::cout << "loans list.\n";
            std::cout << "---------------------\n";
            for(int i=0; i<mClass.loans.size(); i++)
            {

                mClass.loans[i].displayInfo();
                cout<<endl;
            }
            break;
        }

        case 14:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            for (int i = 0; i < mClass.customers.size(); i++)
            {

                for (int j = 0; j < mClass.customers[i].accounts.size(); j++)
                {
                    mClass.customers[i].accounts[j].displayTransactions();



                }
            }
            break;
        }
        case 15:
        {

            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            string aid;
            double abalance;
            string atype;
            string coustmer_nid;



            std::cout << "customer national  Id: ";

            std::cin >> coustmer_nid;
            std::cout << "account  Id: ";

            std::cin >> aid;


            std::cout << "account balance: ";

            std::cin >> abalance;



            std::cout << "account type: ";

            std::cin >> atype;
//Customer c;
//c.accounts.

            Account acc(aid,abalance,atype);
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == coustmer_nid)
                {
                    for (int j = 0; j < mClass.requestacoounts.size(); j++)
                    {
                        if(mClass.requestacoounts[j]==coustmer_nid)
                        {
                            mClass.requestacoounts.erase(mClass.requestacoounts.begin() + j);
                            break;
                        }

                    }


                    mClass.customers[i].accounts.push_back(acc);

                    break;
                }
            }

            std::cout << "You selected Option 1.\n";
            break;
        }

        case 16:
        {

            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            string account_id;

            std::cout << "account Id  for delete: ";

            std::cin >> account_id;

            for (int j=0; mClass.customers.size(); j++)
            {





                for (int i = 0; i < mClass.customers[j].accounts.size(); i++)
                {
                    if (mClass.customers[j].accounts[i].getId() == account_id)
                    {
                        mClass.customers[j].accounts.erase(mClass.customers[j].accounts.begin() + j);

                        break;
                    }
                }


            }


            for (int i = 0; i < mClass.requestadelete.size(); i++)
            {

                if (mClass.requestadelete[i]==account_id)
                {

                    mClass.requestadelete[i].erase(mClass.requestadelete[i].begin() + i);
                }
            }


            std::cout << "account deleted ...\n";
            break;
        }


        case 17:
        {


            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            std::cout << "requests for create account from customres.\n";

            for (int i=0; i<mClass.requestacoounts.size(); i++)
            {

                cout<<"customer id : "<<mClass.requestacoounts[i]<<endl;

            }


            break;
        }
        case 18:
        {
            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }

            std::cout << "requests for delete account from customres.\n";

            for (int i=0; i<mClass.requestadelete.size(); i++)
            {

                cout<<"account id : "<<mClass.requestadelete[i]<<endl;

            }


            break;
        }

        case 19:
        {
            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }

            for (int i=0; i<mClass.accounts.size(); i++)
            {



                mClass.accounts[i].displayInfo();

            }


            break;
        }

        case 20:

        {

            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }

            std::cout << "requests for a loan.\n";

            for (int i=0; i<mClass.requestaLoan.size(); i++)
            {

                //  cout<<"customer id : "<<mClass.requestaLoan[i]<<endl;


                std::vector<std::string> tokens;
                string input=(mClass.requestaLoan[i]);

                std::stringstream ss(input);
                std::string token;

                while (std::getline(ss, token, ','))
                {
                    tokens.push_back(token);
                }


                cout<<"customer national id : "<<tokens[0]<<"loan id"<<tokens[1]<<endl;


            }





            break;
        }




        case 21:
        {

            if( mClass.currentManagerId !="admin")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }

            string nationalid;
            string loanid;

            cout<<"enter customer national id : "<<endl;
            cin>>nationalid;

            cout<<"enter loan id  : "<<endl;
            cin>>loanid;




            for(int i=0; i<mClass.customers.size(); i++)
            {

                if (mClass.customers[i].getNationalId()==nationalid)
                {

                    for (int j=0; j<mClass.loans.size(); j++)
                    {

                        if (mClass.loans[j].getId()==stoi(loanid))
                        {
                            mClass.customers[i].loans.push_back(mClass.loans[j]);
                            break;


                        }
                    }
                }


            }
            break;
        }


        case 30:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        std::cout << "\n";
    }
}

void customerMenu(mainClass& mClass)
{
    int choice;
    bool running = true;

    while (running)
    {
        std::cout << "Customer Menu\n";
        std::cout << "0. login \n";
        std::cout << "1. request to add account \n";
        std::cout << "2. request to delete account \n";
        std::cout << "3. list account\n";
        std::cout << "4. tranfer \n";
        std::cout << "5. list transactions \n";
        std::cout << "6. request for loan \n";
        std::cout << "7. list loan details \n";
        std::cout << "8. view avilable loans \n";
        std::cout << "20. Go back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 0:
        {
            //  Customer.getNationalId
            string username;
            string password;

            cout<<"enter customer national id : "<<endl;
            cin>>username;

            cout<<"enter customer password: "<<endl;
            cin>>password;
            bool founds=false;
            for (int i=0 ; i<mClass.customers.size(); i++)
            {

                if (mClass.customers[i].login(username,password)==true)
                {

                    std::cout << "login success \n";
                    mClass.currentCustomerId=mClass.customers[i].getNationalId();
                    founds=true;
                    break;
                }

            }

            if(founds==false)
            {
                mClass.currentCustomerId="-0";

                std::cout << "login fail \n";
            }


            break;
        }

        case 1:
        {
            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }




            string  yesorno;

            std::cout << "for send reaquest for create account (y/n): ";
            std::cin >> yesorno;

            if (yesorno=="y")
            {

                mClass.requestacoounts.push_back(mClass.currentCustomerId);

                cout<<"request send"<<endl;


            }
            else
            {


            }
            break;
        }

        case 2:
        {
            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }


            string  yesorno;

            std::cout << "enter account id for delete: ";
            std::cin >> yesorno;

            if (yesorno=="y")
            {

                mClass.requestadelete.push_back(yesorno);

                cout<<"request send"<<endl;


            }
            else
            {


            }
            break;
        }

        case 3:
        {
            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == mClass.currentCustomerId)
                {
                    for (int j = 0; j < mClass.customers[i].accounts.size(); j++)
                    {
                        mClass.customers[i].accounts[j].displayInfo();

                    }


                    break;

                }





            }

            break;

        }
        case 4:
        {

            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }

            string sourceaccountid;
            string destaccountid;
            double amount;

            cout<<"enter source account id"<<endl;
            cin>>sourceaccountid;

            cout<<"enter destination account id"<<endl;
            cin>>destaccountid;

            cout<<"enter amount"<<endl;
            cin>>amount;

            for (int i = 0; i < mClass.customers.size(); i++)
            {


                for (int j = 0; j< mClass.customers[i].accounts.size(); j++)
                {

                    if(mClass.customers[i].accounts[j].getId()==sourceaccountid)
                    {

                        Transaction trans("withdraw - :",amount);

                        mClass.customers[i].accounts[j].withdraw(amount);
                        mClass.customers[i].accounts[j].transactions.push_back(trans);

                    }

                    if(mClass.customers[i].accounts[j].getId()==destaccountid)
                    {

                        Transaction trans("deposit + :",amount);

                        mClass.customers[i].accounts[j].deposit(amount);
                        mClass.customers[i].accounts[j].transactions.push_back(trans);

                    }





                }



            }



            std::cout << "transfer complete ........\n";
            break;
        }
        case 5:
        {
            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }
            std::cout << "your transactions list .\n";


            for (int i = 0; i < mClass.customers.size(); i++)
            {


                if (mClass.customers[i].getNationalId()==mClass.currentCustomerId)
                {

                    for (int j = 0; j< mClass.customers[i].accounts.size(); j++)
                    {

                        mClass.customers[i].accounts[j].displayTransactions();



                    }
                }

            }


            break;
        }
        case 6:
        {
            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }
            string  loanid;

            std::cout << "for send request for loan id : ";
            std::cin >> loanid;



            mClass.requestaLoan.push_back(mClass.currentCustomerId+","+loanid);

            cout<<"request send"<<endl;





        }
        case 7:
        {
            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }

            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == mClass.currentCustomerId)
                {
                    mClass.customers[i].displayLoans();

                }


                break;

            }
            break;
        }

        case 8:
            if( mClass.currentCustomerId=="-0")
            {

                std::cout << "please login  \n";
                std::cout << "***************************** \n";
                break;

            }
            cout<<"avialable loans......."<<endl;

            for (int i = 0; i < mClass.loans.size(); i++)
            {

                mClass.loans[i].displayInfo();




            }
        case 20:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        std::cout << "\n";
    }
}
void employeeMenu(mainClass& mClass)
{
    int choice;
    bool running = true;

    while (running)
    {

        std::cout << "Employee Menu \n";
        std::cout << "0.  login \n";
        std::cout << "1.  add customer \n";
        std::cout << "2.  edit customer\n";
        std::cout << "3.  delete customer\n";
        std::cout << "4.  customer list\n";
        std::cout << "5.  search customer \n";
        //////////////////////////////////////////
        std::cout << "6.  add loan \n";
        std::cout << "7.  delete loan\n";
        std::cout << "8.  loan list\n";

        //////////////////////////////////////////
        std::cout << "9.  transactions list  \n";
        std::cout << "10. search  transactions\n";


        //////////////////////////////////////////

        std::cout << "11. add account \n";
        std::cout << "12. delete  account\n";
        std::cout << "13. list  account  request\n";
        std::cout << "14. list  account  delete\n";



        std::cout << "20. Go back\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {


             case 0:
        {
            //  Customer.getNationalId
            string username;
            string password;

            cout<<"enter employee national id : "<<endl;
            cin>>username;

            cout<<"enter employee password: "<<endl;
            cin>>password;
            bool founds=false;
            for (int i=0 ; i<mClass.emps.size(); i++)
            {

                if (mClass.emps[i].login(username,password)==true)
                {

                    std::cout << "login success \n";
                    mClass.currentManagerId=mClass.emps[i].getNationalId();
                    founds=true;
                    break;
                }

            }

            if(founds==false)
            {
                mClass.currentManagerId="-0";

                std::cout << "login fail \n";
            }


            break;
        }




         case 1:
        {


            if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            std::cout << "National Id: ";
            std::string _nationalId;
            std::cin >> _nationalId;


            std::cout << "firstName: ";
            std::string _firstName;
            std::cin >> _firstName;



            std::cout << "lastName: ";
            std::string _lastName;
            std::cin >> _lastName;



            std::cout << "date Of birth: ";
            std::string _dateOfBirth;
            std::cin >> _dateOfBirth;




            std::cout << "gender ";
            std::string _gender;
            std::cin >> _gender;



            std::cout << "join date ";
            std::string _joinDate;
            std::cin >> _joinDate;




            std::cout << "password ";
            std::string _password;
            std::cin >> _password;


            Customer emp( _nationalId,
                          _firstName,
                          _lastName,
                          _dateOfBirth,
                          _gender,
                          _joinDate,
                          _password   );

            mClass.customers.push_back(emp);

            break;
        }
        case 2:
        {


              if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            string emp_number_to_delete;

            std::cout << "enter customer id to edit: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.customers.erase(mClass.customers.begin() + i);
                    found = true;
                    break;
                }
            }

            std::cout << "National Id: ";
            std::string _nationalId;
            std::cin >> _nationalId;


            std::cout << "firstName: ";
            std::string _firstName;
            std::cin >> _firstName;



            std::cout << "lastName: ";
            std::string _lastName;
            std::cin >> _lastName;



            std::cout << "date Of birth: ";
            std::string _dateOfBirth;
            std::cin >> _dateOfBirth;




            std::cout << "gender ";
            std::string _gender;
            std::cin >> _gender;



            std::cout << "join date ";
            std::string _joinDate;
            std::cin >> _joinDate;




            std::cout << "password ";
            std::string _password;
            std::cin >> _password;


            Customer cust( _nationalId,
                           _firstName,
                           _lastName,
                           _dateOfBirth,
                           _gender,
                           _joinDate,
                           _password   );

            mClass.customers.push_back(cust);


            break;
        }

        case 3:
        {


  if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            string emp_number_to_delete;

            std::cout << "enter customer id to delete: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.customers.erase(mClass.customers.begin() + i);
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "customer deleted successfully" << endl;
            }
            else
            {
                cout << "customer not found" << endl;
            }

            break;
        }
        case 4:
        {

             if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }





            std::cout << "customers list.\n";
            std::cout << "---------------------\n";
            for(int i=0; i<mClass.customers.size(); i++)
            {

                mClass.customers[i].displayInfo();
                cout<<endl;
            }

            break;
        }

        case 5:
        {


             if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }




            string emp_number_to_delete;
            std::cout << "enter customer id to search: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == emp_number_to_delete)
                {
                    mClass.customers[i].displayInfo();
                    cout<<endl;
                    break;
                }
            }

            if (found)
            {
                cout << "customer find successfully" << endl;
            }
            else
            {
                cout << "customer not found" << endl;
            }


            break;
        }
        case 6:
        {

             if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }





            std::cout << "loan Id: ";
            std::string _id;
            std::cin >> _id;


            std::cout << "loan amount: ";
            std::string _amount;
            std::cin >> _amount;



            std::cout << "loan rate: ";
            std::string _rate;
            std::cin >> _rate;


            Loan loan(stoi(_id),stod(_rate),stoi(_amount));
            mClass.loans.push_back(loan);
            break;
        }

        case 7:
        {


              if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }




            int emp_number_to_delete;

            std::cout << "enter loan id to delete: ";
            std::cin >> emp_number_to_delete;

            bool found = false;
            for (int i = 0; i < mClass.loans.size(); i++)
            {
                if (mClass.loans[i].getId() == emp_number_to_delete)
                {
                    mClass.loans.erase(mClass.loans.begin() + i);
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "loan deleted successfully" << endl;
            }
            else
            {
                cout << "loan not found" << endl;
            }
            break;
        }
        case 8:
        {

  if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }




            std::cout << "loans list.\n";
            std::cout << "---------------------\n";
            for(int i=0; i<mClass.loans.size(); i++)
            {

                mClass.loans[i].displayInfo();
                cout<<endl;
            }
            break;
        }

        case 9:
        {


            if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            for (int i = 0; i < mClass.customers.size(); i++)
            {

                for (int j = 0; j < mClass.customers[i].accounts.size(); j++)
                {
                    mClass.customers[i].accounts[j].displayTransactions();



                }
            }
            break;
        }
        case 10:
        {

            if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            string aid;
            double abalance;
            string atype;
            string coustmer_nid;



            std::cout << "customer national  Id: ";

            std::cin >> coustmer_nid;
            std::cout << "account  Id: ";

            std::cin >> aid;


            std::cout << "account balance: ";

            std::cin >> abalance;



            std::cout << "account type: ";

            std::cin >> atype;
//Customer c;
//c.accounts.

            Account acc(aid,abalance,atype);
            for (int i = 0; i < mClass.customers.size(); i++)
            {
                if (mClass.customers[i].getNationalId() == coustmer_nid)
                {
                    for (int j = 0; j < mClass.requestacoounts.size(); j++)
                    {
                        if(mClass.requestacoounts[j]==coustmer_nid)
                        {
                            mClass.requestacoounts.erase(mClass.requestacoounts.begin() + j);
                            break;
                        }

                    }


                    mClass.customers[i].accounts.push_back(acc);

                    break;
                }
            }

            std::cout << "You selected Option 1.\n";
            break;
        }

        case 11:
        {

           if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            string account_id;

            std::cout << "account Id  for delete: ";

            std::cin >> account_id;

            for (int j=0; mClass.customers.size(); j++)
            {





                for (int i = 0; i < mClass.customers[j].accounts.size(); i++)
                {
                    if (mClass.customers[j].accounts[i].getId() == account_id)
                    {
                        mClass.customers[j].accounts.erase(mClass.customers[j].accounts.begin() + j);

                        break;
                    }
                }


            }


            for (int i = 0; i < mClass.requestadelete.size(); i++)
            {

                if (mClass.requestadelete[i]==account_id)
                {

                    mClass.requestadelete[i].erase(mClass.requestadelete[i].begin() + i);
                }
            }


            std::cout << "account deleted ...\n";
            break;
        }


        case 12:
        {


           if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            std::cout << "requests for create account from customres.\n";

            for (int i=0; i<mClass.requestacoounts.size(); i++)
            {

                cout<<"customer id : "<<mClass.requestacoounts[i]<<endl;

            }


            break;
        }
        case 13:
        {
            if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }



            std::cout << "requests for delete account from customres.\n";

            for (int i=0; i<mClass.requestadelete.size(); i++)
            {

                cout<<"account id : "<<mClass.requestadelete[i]<<endl;

            }


            break;
        }

        case 14:
        {
             if( mClass.currentEmpId =="-0")
            {


                cout<<"please login then continue ...........................!"<<endl;
                cout<<" .....................................................!"<<endl;
                break;

            }


            for (int i=0; i<mClass.accounts.size(); i++)
            {



                mClass.accounts[i].displayInfo();

            }


            break;
        }

        case 20:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        std::cout << "\n";
    }
}


void mainMenu(mainClass& mClass)
{
    int choice;
    bool running = true;


    while (running)
    {
        std::cout << "Select Option\n";
        std::cout << "1. Bank Manager\n";
        std::cout << "2. Employee \n";
        std::cout << "3. Customer\n";
        std::cout << "4. Save & Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            managerMenu( mClass);
            break;
        case 2:
            employeeMenu( mClass);
            break;
        case 3:
            customerMenu( mClass);
            break;
        case 4:

        {

            //     std::ofstream filee("customer");



            std::ofstream filep("customer");

            std::ofstream filea("account");

            std::ofstream filecl("customerloan");



            if (!filep.is_open())
            {
                std::cerr << "Failed to open the file!\n";

            }
            else
            {



                for (int i = 0; i < mClass.customers.size(); i++)
                {

                    //   Customer.getNationalId

                    //Customer.getFirstName
                    // Customer.getLastName
                    //  Customer.getDateOfBirth
                    // Customer.getJoinDate
                    // Customer.password

                    //  Account.getAccountType
                    // Account.getBalance
                    //  Account.getId



                    Customer p=mClass.customers[i];

                    string st=(p.getNationalId())+ "," + p.getFirstName()+","+
                              (p.getLastName())+ "," + p.getDateOfBirth()+","+p.getGender()+","+
                              (p.getJoinDate())+ "," + p.getPassword();
                    filep <<st<<endl;



                    for( int j = 0; j < mClass.customers[i].accounts.size(); j++)
                    {

                        Account a= mClass.customers[i].accounts[j];
                        string st=p.getNationalId()+ ","+(a.getId())+ "," +to_string( a.getBalance())+","+(a.getAccountType());
                        filea<<st<<endl;


                    }


                    for( int j = 0; j < mClass.customers[i].loans.size(); j++)
                    {

                        Loan l= mClass.customers[i].loans[j];
                        string st=p.getNationalId()+to_string(l.getId())+ "," +to_string( l.getInterestRate())+","+to_string(l.getAmount());
                        filecl<<st<<endl;


                    }





                }




            }






            std::ofstream filee("employee");




            if (!filee.is_open())
            {
                std::cerr << "Failed to open the file!\n";

            }
            else
            {



                for (int i = 0; i < mClass.emps.size(); i++)
                {

                    //   Customer.getNationalId

                    //Customer.getFirstName
                    // Customer.getLastName
                    //  Customer.getDateOfBirth
                    // Customer.getJoinDate
                    // Customer.password

                    //  Account.getAccountType
                    // Account.getBalance
                    //  Account.getId



                    Employee p=mClass.emps[i];

                    string st=(p.getNationalId())+ "," + p.getFirstName()+","+
                              (p.getLastName())+ "," + p.getDateOfBirth()+","+p.getGender()+","+
                              (p.getJoinDate())+ "," + p.getPassword();
                    filee <<st<<endl;










                }




            }





            std::ofstream filel("loan");


            if (!filel.is_open())
            {
                std::cerr << "Failed to open the file!\n";

            }
            else
            {



                for (int i = 0; i < mClass.loans.size(); i++)
                {

                    //  Loan.getId
                    //  Loan.getInterestRate
                    //  Loan.getAmount

                    Loan p=mClass.loans[i];

                    string st=to_string(p.getId())+ "," +to_string( p.getInterestRate())+","+to_string(p.getAmount());

                    filel <<st<<endl;



                }



            }




            filea.close();
            filep.close();
            filel.close();
            filee.close();




            running = false;
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        std::cout << "\n";
    }
}



int main()

{
    mainClass mClass;
//load saved file...........................

 std::ifstream filee("employee");
    std::string linee;

    if (filee.is_open())
    {
        while (std::getline(filee, linee))
        {
            int po=0;

            std::istringstream iss(linee);
            std::vector<std::string> tokens;
            std::string token;

            while (std::getline(iss, token, ','))
            {
                tokens.push_back(token);
            }


            //std::cout << t << std::endl;
            if (tokens.size()>0)
            {

                string  nationalId;
                string firstName;
                string lastName;
                string dateOfBirth;
                string gender;
                string joinDate;
                string password;



                nationalId=tokens[0];
                firstName=tokens[1];
                lastName=tokens[2];
                dateOfBirth=tokens[3];
                gender=tokens[4];
                joinDate=tokens[5];
                password=tokens[6];




                Employee emp(nationalId,
                                  firstName,
                                  lastName,
                                  dateOfBirth,
                                  gender,
                                  joinDate,
                                  password
                                 );
                mClass.emps.push_back(emp);




            }





        }

    }

filee.close();



    std::ifstream filep("customer");
    std::string linep;

    if (filep.is_open())
    {
        while (std::getline(filep, linep))
        {
            int po=0;

            std::istringstream iss(linep);
            std::vector<std::string> tokens;
            std::string token;

            while (std::getline(iss, token, ','))
            {
                tokens.push_back(token);
            }


            //std::cout << t << std::endl;
            if (tokens.size()>0)
            {

                string  nationalId;
                string firstName;
                string lastName;
                string dateOfBirth;
                string gender;
                string joinDate;
                string password;



                nationalId=tokens[0];
                firstName=tokens[1];
                lastName=tokens[2];
                dateOfBirth=tokens[3];
                gender=tokens[4];
                joinDate=tokens[5];
                password=tokens[6];




                Customer customer(nationalId,
                                  firstName,
                                  lastName,
                                  dateOfBirth,
                                  gender,
                                  joinDate,
                                  password
                                 );
                mClass.customers.push_back(customer);




            }





        }

    }



    std::ifstream filea("account");
    std::string linea;

    if (filep.is_open())
    {
        while (std::getline(filea, linea))
        {
            int po=0;

            std::istringstream iss(linea);
            std::vector<std::string> tokens;
            std::string token;

            while (std::getline(iss, token, ','))
            {
                tokens.push_back(token);
            }


            //std::cout << t << std::endl;
            if (tokens.size()>0)
            {

                //   Account.getAccountType
                //     Account.getBalance
                //     Account.getId


                string  nationalId;
                string accountType;
                double balance;
                string id;




                nationalId=tokens[0];
                accountType=tokens[1];
                balance=stod(tokens[2]);
                id=tokens[3];





                Account acc(id,
                            (balance),
                            accountType
                           );


                for (int i=0; i<mClass.customers.size(); i++)
                {

                    if(mClass.customers[i].getNationalId()==nationalId)

                        mClass.customers[i].accounts.push_back(acc);

                }





            }





        }

    }








    mainMenu(mClass);
    return 0;
}
