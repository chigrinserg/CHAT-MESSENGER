#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include "CurrentMes.h"


CurrentMessages::CurrentMessages() {}

    CurrentMessages::CurrentMessages(std::string& ctime, std::string& from, std::string& to, std::string& cend)
        : m_ctime{ ctime }, m_from{ from }, m_to{ to }, m_cend{ cend }{}

CurrentMessages::~CurrentMessages() {}



std::string User::getPhoneFromFile2() /* ������� ���������� �� ������ ������������� ��������, �������, �����, �������� � ������ ���
                                         ���������� ������� � ������� �������� ��������� � ������������� �����
                                         ������ ������������ � ���������*/
{
    std::vector<User> arr(Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    std::string controlString;
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> arr[i];
    }
    input_file.close();
    std::vector<User>::iterator it;
tryagain:
    std::string x = autoPfone();
    std::cout << '\n';
    it = std::find(arr.begin(), arr.end(), User(x, x, x, x, x, x));
    std::string gh;
    std::string gf;
    std::string gn;
    std::string gp;
    std::string string;
   
    if (it != arr.end())
    {
        gh = it->getPhone();
        gf = it->getFamily();
        gn = it->getName();
        gp = it->getPatr();
    }
    else
    {
        std::cout << '\n';
        std::cout << "����� ������� ����������� � ������ ���������. ������� ���������� �����" << '\n';
        std::cout << '\n';
        goto tryagain;
    }
    string = gh + " " + gf + " " + gn + " " + gp;
    
    return string;
}

std::string User::getPhoneFromFile3() /* ������� �������� ������������ ���������� ������ ������ �������
                                      ������� ������������ ���������*/
{
    std::vector<User> arr(Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> arr[i];
    }
    input_file.close();
    std::vector<User>::iterator it;
tryagain:
    std::string x = autoPfone();
    it = std::find(arr.begin(), arr.end(), User(x, x, x, x, x, x));
    std::string gh; //���������� �������� ������������ ������
    if (it != arr.end())
    {
        gh = it->getPhone();
    }
    else
    {
        std::cout << '\n';
        std::cout << "����� ������� ����������� � ������ ���������. ������� ���������� �����" << '\n';
        std::cout << '\n';
        goto tryagain;
    }
    return gh;
}
void CurrentMessages::setMes() /*������� �������� ��������� ����������� ��������*/
{
    m_ctime = curTime(); //�������������� ������� ������� ���� � �������
    std::cout << '\n';
    std::cout << "�� ����: ";
    m_from = User::getPhoneFromFile2(); //�������������� ������� ������ �����������
    std::cout << '\n';
    for (size_t i = (m_from.find(' ')); i != -1; i = m_from.find(' ')) m_from.replace(i, 1, "_");
    /*������ �������������� ������� ��� �������������� ������ �������� ��������� �������������. ���� � ���, 
    ��� ��� ���������� ��������� �� ���������� ����� ������� � ������ (��� ������������� ������ � �����
    ��������������� ��� ������������) ������� getline() �� �������� � ��������� � ��������� �� ���������*/
    std::cout << "   ����: ";
    m_to= User::getPhoneFromFile2(); //�������������� ������� ������ ��������
    for (size_t i = (m_to.find(' ')); i != -1; i = m_to.find(' ')) m_to.replace(i, 1, "_");
    std::cout << '\n';
    std::cout << "  ���������: ";
    std::getline(std::cin >> std::ws, m_cend);
    for (size_t i = (m_cend.find(' ')); i != -1; i = m_cend.find(' ')) m_cend.replace(i, 1, "_");
}

void CurrentMessages::setMesToAll() //������� �������� ����� ��������� ��� ���� �������������
{
    m_ctime = curTime();
    std::cout << "�� ����: ";
    m_from = User::getPhoneFromFile2();
    for (size_t i = (m_from.find(' ')); i != -1; i = m_from.find(' ')) m_from.replace(i, 1, "_");
    std::cout << "   ����: ";
    m_to = "����";
    std::cout << "���� ���������� ";
    std::cout << '\n';
    std::cout << "  ���������: ";
    std::getline(std::cin >> std::ws, m_cend);
    for (size_t i = (m_cend.find(' ')); i != -1; i = m_cend.find(' ')) m_cend.replace(i, 1, "_");
}


void CurrentMessages::getMes() //������� ������ ��������� �� �������
{
    std::cout << "==================================================================================================" << '\n';
    std::cout << "  ����������: " << m_ctime << '\n';
    std::cout << "     �� ����: " << m_from << '\n';
    std::cout << "        ����: " << m_to << '\n';
    std::cout << "   ���������: " << m_cend << '\n';
    std::cout << "==================================================================================================" << '\n';
}


std::ostream& operator<< (std::ostream& out, const CurrentMessages& cm)
{
    out << cm.m_ctime << " " << cm.m_from << " " << cm.m_to << " " << cm.m_cend;
    return out;
}

std::istream& operator>> (std::istream& in, CurrentMessages& cm)
{
    in >> cm.m_ctime;
    in >> cm.m_from;
    in >> cm.m_to;
    in >> cm.m_cend;
    return in;
}
CurrentMessages cm;

int size{ 1 };
std::vector<CurrentMessages>array(size); //������ �������� ��������� ���������

void CurrentMessages::createPersonalMessages() //������� �������� ������������ ���������
{
    for (int i = 0; i < size; ++i)
    {
        array[i].setMes();
    }
    for (int j = 0; j < size; ++j)
    {
        int a{};
        std::cout << "�������� ����� ���������? �� - 1, ��� - 0" << '\n';
        std::cin >> a;
        if (a == 1)
        {
            ++size;
            cm.setMes();
            array.push_back(cm);
        }
        else
            break;
    }
    for (int i = 0; i < (end(array) - begin(array)); ++i)
    {
        array[i].getMes();
    }
    std::ofstream out("PersonalMessages.txt", std::ios::app); //��������� ������ � ��������� ���� 
                                                              //������������ ���������
    for (int i = 0; i < (end(array) - begin(array)); ++i)
    {
        out << array[i] << '\n';
    }
}

void CurrentMessages::createMessagesToAll() //������� �������� ����� ��������� ��� ���� �������������
{
    for (int i = 0; i < size; ++i)
    {
        array[i].setMesToAll();
    }
    for (int j = 0; j < size; ++j)
    {
        int a{};
        std::cout << "�������� ����� ���������? �� - 1, ��� - 0" << '\n';
        std::cin >> a;
        if (a == 1)
        {
            ++size;
            cm.setMesToAll();
            array.push_back(cm);
        }
        else
            break;
    }
    for (int i = 0; i < (end(array) - begin(array)); ++i)
    {
        array[i].getMes();
    }
    std::ofstream out("AllMessages.txt", std::ios::app); //���������� ������� ��������� � ��������� ����
    for (int i = 0; i < (end(array) - begin(array)); ++i)
    {
        out << array[i] << '\n';
    }
}

void CurrentMessages::searchPersonalMesssages() //������� ������������ ���������
{
    int size{ 1 };
    std::vector<std::string>array2(size); //��������� ������ ������ ���������
    std::ifstream reader("PersonalMessages.txt");
    std::string tmp; //���������� ��������� ������
    word = User::getPhoneFromFile3(); //���������� ����� ������� - ����������� ������
    std::cout << std::endl;
    if (reader.good())
    {
        while (!reader.eof())
        {
            getline(reader, tmp);
            if (tmp.find(word) != std::string::npos)
            {
                for (int i = 0; i < size; ++i)
                {
                    array2[i] = tmp;
                }
                std::ofstream _out("TempPersonalMessages.txt", std::ios::app); //���������� ������� ��������� 
                                                                               //�� ��������� ��������� ����
                for (int i = 0; i < (end(array2) - begin(array2)); ++i)
                {
                    _out << array2[i] << '\n';
                }
            }
        }
        std::cout << '\n';
    }
    else std::cout << "������ ������ �����" << std::endl;
    reader.close();
}
int CurrentMessages::countPersonalRecords(const std::string name_file) // ������� ����� ����� �� ��������� 
                                                                       // ����� ������������ ���������
{
    int count = 0;
    std::ifstream input_file("TempPersonalMessages.txt");
    std::string s;
    while (!input_file.eof())
    {
        getline(input_file, s);
        ++count;
    }
    input_file.close();
    return count;
}

void CurrentMessages::getPersonalMessages() // ���������� ������������ ��������� �� ���������� ���������� 
                                            // ����� � ������ ��� ������ �� �������
{
    std::vector<CurrentMessages>array(countPersonalRecords("TempPersonalMessages.txt"));
    std::ifstream input_file("TempPersonalMessages.txt", std::ios::in);
    for (int i = 0; i < (countPersonalRecords("TempPersonalMessages.txt")); ++i)
    {
        input_file >> array[i];
    }
    input_file.close();
    for (int i = 0; i < (countPersonalRecords("TempPersonalMessages.txt")); ++i)
    {
        array[i].getMes();
    }
}

void CurrentMessages::cleanFile() // ������� ������� ����������� ���������� �����
{
    std::fstream fs;        
    fs.open("TempPersonalMessages.txt", std::ios::out); 
    fs.close();
}

void CurrentMessages::searchMesssagesToAll() //������� ����� ���������
{
    std::ifstream reader("AllMessages.txt");
    std::string tmp;
    std::string word = "����";
    std::cout << std::endl;
    if (reader.good())
    {
        while (!reader.eof())
        {
            getline(reader, tmp);
            if (tmp.find(word) != std::string::npos) std::cout << tmp << std::endl;
        }
    }
    else std::cout << "Some error occured" << std::endl;
    reader.close();
}

int CurrentMessages::countRecordsOfAll(const std::string name_file) // ������� ����� ����� � ����� 
                                                                    // ����� ���������
{
    int count = 0;
    std::ifstream input_file("AllMessages.txt");
    std::string s;
    while (!input_file.eof())
    {
        getline(input_file, s);
        ++count;
    }
    input_file.close();
    return count;
}

void CurrentMessages::getMessagesToAll() // ���������� ����� ��������� �� ���������� ����� � ������ ��� ������ �� �������
{
    std::vector<CurrentMessages>array(CurrentMessages::countRecordsOfAll ("AllMessages.txt"));
    std::ifstream input_file("AllMessages.txt", std::ios::in);
    for (int i = 0; i < (CurrentMessages::countRecordsOfAll("AllMessages.txt")); ++i)
    {
        input_file >> array[i];
    }
    input_file.close();
    for (int i = 0; i < (CurrentMessages::countRecordsOfAll("AllMessages.txt")); ++i)
    {
        array[i].getMes();
    }
}

