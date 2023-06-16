#pragma once
#include <iostream>
#include<string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include<ios>
#include <algorithm>
#include <conio.h>
#include "Func.h"

class CurrentMessages;
class User
{
    std::string m_family;
    std::string m_name;
    std::string m_patr;
    std::string m_phone;
    std::string m_log;
    std::string m_pass;

public:
    User();
    User(std::string& phone, std::string& family, std::string& name, std::string& patr, std::string& log, std::string& pass);
    void setUsers();
    void getUsers();
    void getListUsers();
    std::string getFamily() const;
    std::string getName() const;
    std::string getPatr() const;
    std::string getPhone() const;
    std::string getLog() const;
    std::string getPass() const;
    void FillArray();
    static int Get_records_in_file(const std::string name_file);
    static std::string getPhoneFromFile2();
    static std::string getPhoneFromFile3(); //ôóíêöèÿ ïðîâåðêè òåëåôîííîãî íîìåðà ïðè âûáîðêå ñîîáùåíèé
    bool getIndLogPasswFromFile();
    void getListUsersFromFile();
    friend std::ostream& operator<< (std::ostream& out, const User& user);
    friend std::istream& operator>> (std::istream& in, User& user);
    bool operator==(const User& obj2) const;
    ~User();
    std::string controlPhone; //ïåðåìåííàÿ ïðîâåðêè òåëåôîíà îòïðàâèòåëÿ - èñï. â áëîêå main
};
