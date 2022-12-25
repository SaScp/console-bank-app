#include "header.h"
using namespace std;
int main() {
    vector<string> datebase;
    cout << "*******************************CARDS***************************************"<<endl;
    load( datebase);
    cout << "***************************************************************************"<<endl;
    string cmd;
    cout << "balance" << endl << "add" << endl << "update" <<endl<< "exit" <<endl;
    cin >> cmd;
    while (cmd != "exit") {
        long long account;
        cin >> account;
        if (cmd == "balance") {
            if (isNumberCorrect(account) && findAccount(account, datebase) != -1) {
                cout <<"your balancr:" << getBalance(account,datebase) << endl;
            }
            else cout << "Incorrect number" << endl;
        }
        if (cmd == "add") {
            if (addAccount(account, datebase)) {
                cout << "Done!" << endl;
            }
            else {
                cout << "Incorrect number" << endl;
            }
        }
        if (cmd == "update") {
            int delta;
            cin >> delta;
            if (isNumberCorrect(account)) {
                balanceReplenishment(account, delta);
                cout << "Done!" << endl;
            }
            else {
                cout << "Incorrect number" << endl;
            }
        }
        cout << "balance" << endl << "add" << endl << "update" <<endl<< "exit" <<endl;
        cin >> cmd;
    }
    save(datebase);
    cout << "Bye!";
    return 0;
}