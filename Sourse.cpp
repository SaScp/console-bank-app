#include "header.h"
bool isLuhnCorrect(long long card) {
    int temp_arr = 0;
    bool is_ok = false;
    std::string a = std::to_string(card);
    reverse(a.begin(), a.end());
    for (int i = 0; i < std::to_string(card).size(); ++i) {
        char temp = a[i];
        int temp2 = static_cast<int>(temp) - 48;
        if (i % 2 != 0 && i != 0) {
            temp2 *= 2;
            if (std::to_string(temp2).size() == 2)
                temp2 = static_cast<int>(std::to_string(temp2)[0]) - 48 + static_cast<int>(std::to_string(temp2)[1]) - 48;
        }
        temp_arr += temp2;
    }
    std::string at = std::to_string(temp_arr);
    if (static_cast<int>(at[at.size() - 1]) - 48 == 0)
        is_ok = true;
    return is_ok;
}
int getDigitCount(long long card) {
    return std::to_string(card).size();
}
bool isNumberCorrect(long long card) {
    return  (isLuhnCorrect(card) == true && getDigitCount(card) == 16 ? true : false);
}
void load(std::vector<std::string> &accounts) {
    accounts.clear();
    std::string emp;
    std::fstream fin;
    fin.open("temp.txt");
    while(!fin.eof()){
        fin >> emp;
        accounts.push_back(emp);
    }
    accounts.pop_back();
    for (auto &i : accounts){
        std::cout << i << "\n";
    }
}
    bool addAccount(long long card,std::vector<std::string>&database) {
    if(isNumberCorrect(card)){
        database.push_back(std::to_string(card));
        std::string temp = "D:\\untitled2\\filse_for_untitled2)\\"+std::to_string(card)+".txt";
        std::fstream fin(temp,std::fstream::app);
        fin << 0;
        fin.close();
        std::fstream fini("temp.txt",std::fstream::app);
        for (int i = 0; i < database.size(); i++) {
            fini << database[i] << std::endl;
        }
        fini.close();
        return 1;
    }
    return 0;
}
int findAccount(long long card, std::vector<std::string>&database) {
    std::string new_account = std::to_string(card);
    for (int i = 0; i < database.size(); ++i) {
        if (database[i] == new_account) {
            return i;
        }
    }
    return -1;
}
void save(std::vector<std::string> &database) {
    std::fstream fin("temp.txt",std::fstream::app);
    for (int i = 0; i < database.size(); i++) {
        fin << database[i] << std::endl;
    }
    fin.close();
}
int getBalance(long long card,std::vector<std::string> &account) {
    if(isNumberCorrect(card)){
        int temp;
        for (int i = 0; i < account.size(); ++i) {
            if(std::to_string(card) == account[i]){
                std::fstream fin;
                fin.open("D:\\untitled2\\filse_for_untitled2)\\" + account[i] + ".txt");
                while(!fin.eof()){
                    fin >> temp;
                }
            }
        }
       return static_cast<long long>(temp)<= 0? 0: static_cast<long long>(temp);
    }
    return -1;
}
void balanceReplenishment(long long card, int delta){
    std::string temp = "D:\\untitled2\\filse_for_untitled2)\\"+std::to_string(card)+".txt";
    std::fstream fin(temp);
    if(fin.eof()){
        std::cout << "this card is not listed"<<std::endl;
    }
    else{
        fin << delta;
        std::cout << "You put on the card: "<< delta << std::endl;
    }
}