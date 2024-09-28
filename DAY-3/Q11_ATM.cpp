#include <iostream>
#include <string>
using namespace std;
class Account{
private:
    double ownerPin=1234;
    string ac_no="1234567";
    string name="Mario";
    double bal=1000.0;
    void withdraw(double wd_amnt){
        bal-=wd_amnt;
    }
    void viewBal(){
        cout<<"Account Name : "<<name<<endl;
        cout<<"Account No : "<<ac_no<<endl;
        cout<<"Your Balance is : "<<bal<<endl;
    }
    void transfer(){
        double recptACno=978654;
        double acctotrans;
        cout<<"Enter the Acc no. to transfer: ";
        cin>>acctotrans;
        double wd_amnt;
        if(acctotrans==recptACno) {
            cout << "Enter transfer amount : ";
            cin >> wd_amnt;
            if (wd_amnt > bal) { cout << "Insufficient Funds!!"; }
            if (wd_amnt <= bal) { withdraw(wd_amnt); }
        }
            if(acctotrans==1234567){
                cout<<"Enter your deposit amount : ";
                cin>>wd_amnt;
                bal+=wd_amnt;
            }
            else if(acctotrans!=recptACno&&acctotrans!=1234567){
                cout<<"INVALID ACC NUMBER";
        }
    }
public:
    void pin(){
        double pin;
        cout<<"Enter your pin :";
        cin>>pin;
        int ch;
        if(pin==ownerPin) {
            while (ch != 4) {
                cout<<"-------------------------------------------"<<endl;
                cout << "ATM MENU\n-------------------------------------------\n1.View Balance\n2.Withdraw\n3.Transfer\n4.Exit" << endl;
                cout<<"-------------------------------------------"<<endl;
                cout << "Your choice : ";
                cin >> ch;
                switch (ch) {
                    case 1:
                        viewBal();
                        break;
                    case 2:
                        cout << "Enter Amount : ";
                        double wd_amnt;
                        cin >> wd_amnt;
                        if (wd_amnt > bal) { cout << "Insufficient Funds "; }
                        else {
                            withdraw(wd_amnt);
                            break;
                        }
                    case 3:
                        transfer();
                        break;
                    case 4:
                        cout << "EXITING.....";
                        break;
                    default:
                        cout << "INVALID";
                        break;
                }
            }
        }
        else{cout<<"INVALID PIN";}
            }
        };
int main(){
    Account obj;
    obj.pin();
}