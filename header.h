#pragma once
#include <bits/stdc++.h>
int getDigitCount(long long);
bool isLuhnCorrect(long long);
bool isNumberCorrect(long long);
void load(std::vector<std::string>);
void save(std::vector<std::string>);
int findAccount(long long, std::vector<std::string>);
bool addAccount(long long, std::vector<std::string>);
int getBalance(long long);
void balanceReplenishment(long long, int);