#pragma once
#include <bits/stdc++.h>
int getDigitCount(long long);//ok
bool isLuhnCorrect(long long);//ok
bool isNumberCorrect(long long);//ok
void load(std::vector<std::string>&);//ok
void save(std::vector<std::string>&);//no
int findAccount(long long, std::vector<std::string>&);//ok
bool addAccount(long long,std::vector<std::string>&database);// ok
int getBalance(long long,std::vector<std::string> &);//no
void balanceReplenishment(long long, int);//no

