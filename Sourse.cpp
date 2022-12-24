#include "header.h"
bool isLuhnCorrect(long long card){
    int temp_arr = 0;
    bool is_ok = false;
    std::string a = std::to_string(card);
    reverse(a.begin(),a.end());
    for (int i = 0; i < std::to_string(card).size(); ++i) {
        char temp = a[i];
        int temp2 =static_cast<int>(temp) - 48;
        if(i % 2 != 0 && i != 0){
            temp2 *= 2;
            if(std::to_string(temp2).size() == 2)
                temp2 = static_cast<int>(std::to_string(temp2)[0]) - 48 + static_cast<int>(std::to_string(temp2)[1]) - 48;
        }
        temp_arr += temp2;
    }
    std::string at = std::to_string(temp_arr);
    if(static_cast<int>(at[at.size() - 1]) - 48 == 0)
        is_ok = true;
    return is_ok;
}
int getDigitCount(long long card){
    return std::to_string(card).size();
}
bool isNumberCorrect(long long card){
   return  (isLuhnCorrect(card) == true && getDigitCount(card) == 16? true : false);
}
void load(std::vector<long long> accounts){
    for (int i = 0; i < accounts.size(); ++i) {
        std::cout << accounts[i] << "\n";
    }
}
bool addAccount(long long card, std::vector<std::string> database){
    if(isNumberCorrect(card)){
        std::string new_account = std::to_string(card) + ".txt";
        database.push_back(new_account);
        return 1;
    }
    return 0;
}
int findAccount(long long card, std::vector<std::string>database){
    std::string new_account = std::to_string(card) + ".txt";
    for (int i = 0; i < database.size(); ++i) {
        if(database[i] == new_account){
            return i;
        }
    }
  return -1;
}
void save(std::vector<std::string> account){
    std::vector<std::fstream> database(account.size());
    for (int i = 0; i < database.size(); ++i) {

    }
}