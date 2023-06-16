#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include "Message.h"
#include "User.h"
#include "Func.h"


class CurrentMessages
{
    std::string m_ctime;
    std::string m_to;
    std::string m_from;
    std::string m_cend;
public:
    CurrentMessages();
    CurrentMessages(std::string& ctime, std::string& to, std::string& from, std::string& cend);
    ~CurrentMessages();
    std::string curTime(); //������� ��������� �������� �������
    void setMes(); // ������� �������� ���������
    void setMesToAll(); // �������� ��������� ���� �������������
    void getMes(); // ������� ��������� ���������
    void createPersonalMessages();//������� �������� ��������� � ���������� �� � ��������� ����
    void createMessagesToAll(); // ������� �������� ����� ���������
    void searchPersonalMesssages();
    void searchMesssagesToAll();
    void getMessages(); // ������� ���������� ��������� �� ���������� �����
    friend std::string getPhoneFromFile2(); //�������������� ��������� ���� ������������ � ���������� 
                                            //�� ������ �������������
    friend std::string getPhoneFromFile3(); //������� �������� ����������� ������ ��� ������� ���������
    static int countRecordsOfAll(const std::string name_file); /* ������� ����� � ����� ������ �����
                                                               ���������*/
    static int countPersonalRecords(const std::string name_file); /*������� ����� ����� �� ��������� ����� 
                                                                  ������������ ���������*/
    void getPersonalMessages(); //���������� ������������ ��������� � ������ ��� ������ �� �������
    void cleanFile(); //������� ���������� ����� ������������ ���������
    void getMessagesToAll();// ���������� ����� ���������
    friend std::ostream& operator<< (std::ostream& out, const CurrentMessages& cm);
    friend std::istream& operator>> (std::istream& in, CurrentMessages& cm);
    std::string word; //���������� �������� �������� ����������
};

