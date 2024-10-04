#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class bank {
    int accno;
    char name[25];
    char fname[25];
    char cif[25];
    char pno[25];
    char email[25];
    float amount;
    int newamount;
    fstream file,file1,file2;

    string username,password;
    string searchusername,searchpassword;

public:
    int search;

    void createaccount(void);
    void depositaccount(void);
    void withdrawamount(void);
    void checkinfo(void);
};

int main() {
    bank obj;
    int choice;

    cout<<"-------::Dhruv's Bank::--------";
    cout<<"\n1 Login to Your Account";
    cout<<"\n2 Create a Account";
    cout<<"\n0 Exit";
    cout<<"\n-------------------------------";

    cout<<"\nChoose Your Desired Option=";
    cin>>choice;

    switch(choice) {
        case 1:
            cout<<"Enter Account Number=";
        cin>>obj.search;

            while(1) {
                cout<<"-----::Dhruv's Bank::-----";
                cout<<"\n1 Deposit Amount";
                cout<<"\n2 Withdraw Amount";
                cout<<"\n3 Check Info";
                cout<<"\n0 Exit";
                cout<<"\n--------------------------";

                cout<<"\nEnter your Desired Option-";
                cin>>choice;

                switch(choice) {
                    case 1:
                        obj.depositaccount();
                    break;

                    case 2:
                        obj.withdrawamount();
                    break;

                    case 3:
                        cin.ignore();
                    obj.checkinfo();
                    break;

                    case 0:
                        return 0;

                    default:
                        cout<<"Invalid Choice...!!";
                    break;
                }
            }
        case 2:
            cin.ignore();
            obj.createaccount();
        break;

        case 0:
            system("Exit");
        break;

        default:
            cout<<"Invalid Selection...!!";
        break;
    }
    return 0;
}

void bank::createaccount() {
    srand(time(0));
    accno=rand()*rand()+rand()*rand();

    cout<<"Create a Username:-";
    getline(cin,username);

    cout<<"Create Password:-";
    getline(cin,password);

    cout<<"Enter Your Name:-";
    cin>>name;

    cout<<"Enter Your Father's Name:-";
    cin>>fname;

    cout<<"Enter Your CIF Number:-";
    cin>>cif;

    cout<<"Enter Your Phone Number:-";
    cin>>pno;

    cout<<"Enter your Email Id:-";
    cin>>email;

    cout<<"Enter Your Amount:-";
    cin>>amount;

    cout<<"\nPlease Save it for future use";
    cout<<"This is your account number-"<<accno;
    cout<<"User Id:-"<<username;
    cout<<"Password:-"<<password;

    file.open("data.txt",ios::out|ios::app);
    file2.open("logindata.txt",ios::out|ios::app);

    file<<accno<<"\t"<<name<<"\t"<<fname<<"\t"<<cif<<"\t"<<pno<<"\t"<<email<<"\t"<<amount<<endl;
    file2<<username<<"*"<<password<<endl;

    file.close();
    file2.close();

}

void bank::depositaccount() {
    cout<<"Enter Amount to Deposit=";
    cin>>newamount;

    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>accno>>name>>fname>>cif>>pno>>email>>amount;

    while(!file.eof()) {
        if(accno==search) {
            cout<<"\nCurrent Amount="<<amount;
            amount=amount+newamount;
            cout<<"\nUpdated Amount="<<amount<<endl;

            file1<<accno<<"\t"<<name<<"\t"<<fname<<"\t"<<cif<<"\t"<<pno<<"\t"<<email<<"\t"<<amount<<endl;
        }else{
            file1<<accno<<"\t"<<name<<"\t"<<fname<<"\t"<<cif<<"\t"<<pno<<"\t"<<email<<"\t"<<amount<<endl;
        }
        file>>accno>>name>>fname>>cif>>pno>>email>>amount;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
}

void bank::withdrawamount() {
    cout<<"Enter Amount to Withdraw=";
    cin>>newamount;

    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>accno>>name>>fname>>cif>>pno>>email>>amount;

    while(!file.eof()) {
        if(accno==search) {
            cout<<"\nCurrent Amount="<<amount;
            amount=amount-newamount;
            cout<<"\nUpdated Amount="<<amount<<endl;

            file1<<accno<<"\t"<<name<<"\t"<<fname<<"\t"<<cif<<"\t"<<pno<<"\t"<<email<<"\t"<<amount<<endl;
        }else{
            file1<<accno<<"\t"<<name<<"\t"<<fname<<"\t"<<cif<<"\t"<<pno<<"\t"<<email<<"\t"<<amount<<endl;
        }
        file>>accno>>name>>fname>>cif>>pno>>email>>amount;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
}

void bank::checkinfo() {
    cout<<"Enter your Username-";
    getline(cin,searchusername);

    cout<<"Enter Your Password-";
    getline(cin,searchpassword);

    file2.open("logindata.txt",ios::in);
    getline(file2,username,'*');
    getline(file2,password,'\n');
    while(!file.eof()) {
        if(username==searchusername) {
            if(password==searchpassword) {
                cout<<"Valid Credentials";
                cout<<"\nAccount Login Successful"<<endl;

                file.open("data.txt",ios::in);
                file>>accno>>name>>fname>>cif>>pno>>email>>amount;
                while(!file.eof()){
                    if(accno==search) {
                        cout<<"\nAccount Number="<<accno;
                        cout<<"\nName="<<name;
                        cout<<"\nFather's Name="<<fname;
                        cout<<"\nCIF Number="<<cif;
                        cout<<"\nPhone Number="<<pno;
                        cout<<"\nEmail Id="<<email;
                        cout<<"\nCurrent Balance="<<amount<<endl;
                    }
                    file>>accno>>name>>fname>>cif>>pno>>email>>amount;
                }
                file.close();
            }else {
                cout<<"Invalid Credentials...!!";
            }
        }
        getline(file2,username,'*');
        getline(file2,password,'\n');
    }
    file2.close();
}
