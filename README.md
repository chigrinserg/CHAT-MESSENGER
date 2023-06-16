# CHAT-MESSENGER
Работа программы основана на взаимодействии функций из двух классов: User и CurrentMes, разделенных на заголовочные файлы и файлы реализации. В классе User определены переменные: std::string m_family; - фамилия пользова-теля std::string m_name; - имя std::string m_patr; - отчество std::string m_phone; - телефон std::string m_log; - логин std::string m_pass; - пароль Регистрация поль-зователей осуществляется функцией FillArray() с помощью вложенной функции-геттера setUsers(). В этой функции список пользователей создается в виде мас-сива объектов класса типа vector - std::vector arr, в котором каждый новый объ-ект добавляется в массив с помощью метода push_back(). Это позволяет до-бавлять в массив неограниченное количество объектов. 
Внутри функции setUsers() (и далее везде, где требуется) для записи телефон-ного номера используется функция создания маски ввода - autoPfone() (код найден на сайте https://coding.likeflow.ru/2019/12/c_69.html), определенная в файле Func. В этом же файле определена функция установки текущей даты и времени curTime(). Далее, внутри функции FillArray() находится функция-геттер getUsers() для просмотра результатов записи списка, а также находится метод ofstream out для сохранения списка в текстовый файл listOfUsers.txt. Из этого файла список извлекается для просмотра с помощью функции getListUsersFromFile(). 
Размер массива, выводящего список на консоль, задается функцией Get_records_in_file(const std::string name_file), определенной как статическая и подсчитывающей число строк в текстовом файле. Причем список пользователй выводится без логинов и паролей с помощью вложенной функции getListUsers(). Таким образом, логины и пароли пользователей остаются закрытыми данными и недоступны для просмотра. Наконец, функция getIndLogPasswFromFile() с помощью вложенных функций-геттеров извлекает логины и пароли для сравнения с вводимыми логинами и паролями и контроля доступа в чат. 
Помимо этого, в классе определны функции-геттеры, извлекающие отдельные переменные-члены getFamily() const; getName() const; getPatr() const; getPhone() const; getLog() const; getPass() const; и являющиеся вспомогательными, возвращающими данные для других функций. Также определяются перегруженные операторы - ввода, вывода и равенства. Предварительно объявлен класс CurrentMes, что необходимо для работы двух дружественных этому классу функций - getPhoneFromFile2() и PhoneFromFile3(), извлекающих данные из списка пользователей для использования их при создании сообщений. 
Класс CurrentMessages имеет набор методов, осуществляющих написание со-общений в виде массива объектов класса, сохранение их в текстовых файлах и извлечение их оттуда для прочтения. Так, функция createPersonalMessages() с помощью вложенной в нее функции setMes(). В свою очередь, в функции setMes() переменная времени m_ctime инициализируется функцией curTime(), устанавливающей дату и время отправки сообщения и определенной в файле вспомогательных функций Func. 
Переменные m_from (отправитель) и m_to (получатель) инициализируются функцией getPhoneFromFile2(), определенной как дружественная в классе User. Эта функция извлекает из списка пользователей имя пользователя, соответ-ствующее введенным номерам телефонов, и автоматически вставляет их в текст сообщения. Наконец здесь введена функция автоматической замены пробелов на символы подчеркивания: for (size_t i = (m_from.find(' ')); i != -1; i = m_from.find(' ')) m_from.replace(i, 1, "_"); Это связано с тем, что функция getline() при наличии пробелов выводит записи на консоль в том виде, в каком они записаны в текстовом файле - все в одну строку. А вот выводить обратно в массив записи с пробелами категорически не хочет, и мне так и не удалось решить эту проблему.
 Общие сообщения создаются и сохраняются функцией createMessagesToAll(). Эта функция отличается от предыдущей тем, что во вложенной функции setMesToAll() переменная m_to уже инициализирована значением "Всем", что избавляет пользователя от лишнего ввода шаблона. Функции searchPersonalMesssages() и searchMesssagesToAll() осуществляют извлечение текстов сообщений из файлов хранения (соответственно персональных и об-щих) для вывода на консоль и прочтения, с помощью вложенных в них вспомо-гательных функций подсчета строк в файле, извлечения из файла потоком вы-вода и преобразования в массив, выводящийся на консоль. 
Однако функция searchPersonalMesssages() имеет то отличие, что внутри нее извлечение сообщений осуществляется в два этапа. Вначале сообщения отби-раются соответственно номеру телефона пользователя, который сравнивается с контрольными значениями переменных user.controlPhone и cm.word. Таким образом, пользователь может получить доступ только к сообщениям, которые писал сам и которые адресованы ему. Отобранные таким образом сообщения копируются в файл временного хранения TempPersonalMessages и уже оттуда выводятся на консоль. Так производится отделение выбранных сообщений от частной переписки других пользователей. После вывода на консоль записи в файле TempPersonalMessages стираются. Ну и наконец в блоке main находится пользовательский интерфейс управления программой. С уважением, С.В. Чигрин. Телефон для связи - 8918-390-16-08
