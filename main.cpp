
#include "header.h"
using namespace std;
int main() {

    vector<string> datebase;
    load(datebase);
    string cmd;
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
    save(datebase);
    cout << "Bye!";
    return 0;
}
