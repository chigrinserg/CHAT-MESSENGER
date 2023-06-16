#include <iostream>
#include<string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include<ios>
#include "User.h"


User::User() {}
User::User(std::string& phone, std::string& family, std::string& name, std::string& patr, std::string& log, std::string& pass)
    : m_phone{ phone }, m_family{ family }, m_name{ name }, m_patr{ patr }, m_log{ log }, m_pass{ pass }{}
User::~User() {}

void User::setUsers()
{
    std::cout << " �������: ";
    m_phone= autoPfone();
    std::cout << '\n';
    std::cout << " �������: ";
    std::cin >> m_family;
    std::cout << "     ���: ";
    std::cin >> m_name;
    std::cout << "��������: ";
    std::cin >> m_patr;
    std::cout << "���������� ���� ����� � ������. ������ �� ��������� ��" << '\n';
    std::cout << "   �����: ";
    std::cin >> m_log;
    std::cout << "  ������: ";
    std::cin >> m_pass;
    std::cout << '\n';
}
void User::getUsers()
{
    std::cout << "=========================================================================================" << '\n';
    std::cout << "  �������: " << m_phone << '\n';
    std::cout << "  �������: " << m_family << '\n';
    std::cout << "      ���: " << m_name << '\n';
    std::cout << " ��������: " << m_patr << '\n';
    std::cout << "    �����: " << m_log << '\n';
    std::cout << "   ������: " << m_pass << '\n';
    std::cout << "=========================================================================================" << '\n';
}

void User::getListUsers() //�������� ������������� ������ ���������
{
    std::cout << "=========================================================================================" << '\n';
    std::cout << "  �������: " << m_phone << '\n';
    std::cout << "  �������: " << m_family << '\n';
    std::cout << "      ���: " << m_name << '\n';
    std::cout << " ��������: " << m_patr << '\n';
    std::cout << "=========================================================================================" << '\n';
}

std::string User::getFamily() const
{    return m_family;}

std::string User::getName() const
{    return m_name;}

std::string User::getPatr() const
{    return m_patr;}

std::string User::getPhone() const
{    return m_phone;}

std::string User::getLog() const
{    return m_log;}

std::string User::getPass() const
{    return m_pass;}

bool User::operator==(const User& obj2) const
{
    if (this->getPhone().compare(obj2.getPhone()) == 0)
        return true;
    else
        return false;
}
std::ostream& operator<< (std::ostream& out, const User& user)
{
    out << user.m_phone << " " << user.m_family << " " << user.m_name << " " << user.m_patr << " " << " " << user.m_log << " " << user.m_pass; // ������ ��� ������� ����� ���������, � ���-������� �������� out � �������� ������������� ����
    return out;
}
std::istream& operator>> (std::istream& in, User& user)
{
    in >> user.m_phone;
    in >> user.m_family;
    in >> user.m_name;
    in >> user.m_patr;
    in >> user.m_log;
    in >> user.m_pass;
    return in;
}

int size2{ 1 };
std::vector<User> arr(size2);    //��������� ������ ����������� ������ User
User user;                      //��������� ������ ��������� ������

void User::FillArray() //������� �������� ������ �������������
{
    std::cout << "�����������  ������  ������������: " << '\n';
    std::cout << '\n';
    for (int i = 0; i < size2; ++i) 
    {
        arr[i].setUsers();
    }
    for (int j = 0; j < size2; ++j) /* ������ ���� ��������� ��������� ����� �������������
                                      ������������� ������ ������� ����� ������� push_back� */
    {
        int z{};
        std::cout << "�������� ������������? �� - 1, ��� - 0" << '\n';
        std::cin >> z;
        if (z == 1)
        {
            ++size2;
            user.setUsers();
            arr.push_back(user);
        }
        else
            break;
    }
    for (int i = 0; i < (end(arr) - begin(arr)); ++i) //������� ��������� ������ �� �������
    {
        arr[i].getUsers();
    }
    std::ofstream out("listOfUsers.txt", std::ios::app); //��������� ������ � ��������� ����
    for (int i = 0; i < (end(arr) - begin(arr)); ++i)
    {
        out << arr[i] << '\n';
    }
    std::cout << '\n';
}

int User::Get_records_in_file(const std::string name_file) /*������� ����� ����� � ����� ������ �������������
                                                           ��� �������� ����� ����� � �������� ������� �������
                                                           ������ ������ � �������*/
{
    int count = 0;
    std::ifstream input_file("listOfUsers.txt");
    std::string s;
    while (!input_file.eof())
    {
        getline(input_file, s);
        ++count;
    }
    input_file.close();
    return count;
}

void User::getListUsersFromFile() //������� ���������� �� ����� ������ ��������� ��� ������ � ������
{
    std::cout << "������ ��������� ���������: " << '\n';
    std::cout << '\n';
    std::vector<User> arr(User::Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    std::string str;
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> arr[i];
    }
    input_file.close();
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        arr[i].getListUsers();
    }
}

bool User::getIndLogPasswFromFile() //������� ���������� �� ����� ������� ������ � ������
{
    std::vector<User> arr(Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    std::string str;
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> arr[i];
    }
    input_file.close();
    std::string login;
    std::cout << "������� �����: ";
    std::cin >> login;
    std::string password;
    std::cout << "������� ������: ";
    std::cin >> password;
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        if (login == arr[i].getLog() && password == arr[i].getPass())
        {
            controlPhone = arr[i].getPhone();
            return true;
        }
        
    }
}




