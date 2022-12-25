
#include "header.h"
using namespace std;
int main() {
    vector<fstream> datafilebase;
    vector<string> datebase;
    load(datebase);
    string cmd;
    cout << " balance""\n"
                      "add\n"
                      "update\n"
                      "exit\n"<<endl;

    cin >> cmd;
    while (cmd != "exit") {
        long long account;
        cin >> account;
        if (cmd == "balance") {
            if (isNumberCorrect(account) && findAccount(account, datebase) != -1) {
                cout << getBalance(account) << endl;
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
        cin >> cmd;
    }
    save(datebase,datafilebase);
    cout << "Bye!";
    return 0;
}
