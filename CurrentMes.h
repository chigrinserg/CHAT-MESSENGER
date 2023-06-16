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
    std::string curTime(); //функция получения текущего времени
    void setMes(); // функция создания сообщений
    void setMesToAll(); // создание сообщений всем пользователям
    void getMes(); // функция получения сообщений
    void createPersonalMessages();//функция создания сообщений и созранения их в текстовый файл
    void createMessagesToAll(); // функция рассылки общих сообщений
    void searchPersonalMesssages();
    void searchMesssagesToAll();
    void getMessages(); // функция извлечения сообщений из текстового файла
    friend std::string getPhoneFromFile2(); //автоматическое получение имен респондентов в сообщениях 
                                            //из списка пользователей
    friend std::string getPhoneFromFile3(); //функция проверки телефонного номера при выборке сообщений
    static int countRecordsOfAll(const std::string name_file); /* подсчет строк в файле записи общих
                                                               сообщений*/
    static int countPersonalRecords(const std::string name_file); /*Подсчет числа строк во временном файле 
                                                                  персональных сообщений*/
    void getPersonalMessages(); //извлечение персональных сообщений в массив для вывода на консоль
    void cleanFile(); //очистка временного файла персональных сообщений
    void getMessagesToAll();// извлечение общих сообщений
    friend std::ostream& operator<< (std::ostream& out, const CurrentMessages& cm);
    friend std::istream& operator>> (std::istream& in, CurrentMessages& cm);
    std::string word; //переменная проверки телефона получателя
};

