﻿/*Простой текстовый редактор:
	Создайте консольное приложение,
	которое позволяет пользователю вводить текст, сохранять его в файл и открывать существующие файлы.
	Этот проект поможет вам научиться работать с файлами, строками и циклами.*/

/*
1)
Создание консольного приложения:

Создайте новый проект в вашей среде разработки (например, Visual Studio, Code::Blocks, или другая) с поддержкой C++.
Назовите проект, например, "TextEditor".
2)
Настройка основного цикла:

Создайте основной цикл приложения, который будет выполняться до тех пор, пока пользователь не решит выйти из редактора.
Меню пользователя:

Создайте меню для пользователя с опциями:
		Новый документ
		Открыть существующий документ
		Сохранить документ
		Выйти из редактора
		Обработка выбора пользователя:

Используйте условные операторы для обработки выбора пользователя и выполнения соответствующих действий.
*******************
Работа с текстом:

Для хранения текста, который пользователь будет вводить, используйте строки (строковый объект) из стандартной библиотеки C++.
Реализуйте функции для ввода и редактирования текста.
Работа с файлами:

Для сохранения и открытия файлов используйте потоки ввода и вывода (ifstream и ofstream) из стандартной библиотеки C++.
Создайте функции для сохранения и открытия документов.
Ввод текста:

Реализуйте функцию, которая позволяет пользователю вводить текст с консоли. Можно использовать цикл для построчного ввода.
Сохранение текста:

Реализуйте функцию для сохранения текущего текста в файле. Пользователь должен указать имя файла.
Открытие существующего файла:

Реализуйте функцию, которая позволяет пользователю открыть существующий текстовый файл. Запросите у пользователя имя файла.
Выход из редактора:

Реализуйте функцию, которая завершает работу приложения и выходит из основного цикла.
Обработка ошибок:

Добавьте обработку возможных ошибок, таких как неверные имена файлов, проблемы с потоками ввода/вывода и другие возможные ситуации.
Тестирование:

Тщательно протестируйте ваше приложение, вводя текст, сохраняя и открывая файлы, и проверьте, что оно работает корректно и без ошибок.
Документация:

Создайте краткую документацию, которая описывает функциональность вашего текстового редактора, а также как им пользоваться.
Завершение проекта:

Соберите ваш проект и убедитесь, что он готов к использованию.*/
#include <iostream>
#include <fstream>
#include <string>

void ShowMenu()
{
	std::cout << "Text Editor Menu:" << std::endl;
	std::cout << "New document" << std::endl;
	std::cout << "Open an existing document " << std::endl;
	std::cout << "Save the document" << std::endl;
	std::cout << "Exit" << std::endl;


}

int main()
{
	std::string document;
	int choice;
	do
	{
		ShowMenu();							//function ShowMenu
		std::cout << "Choose:";
		
		std::cin >> choice;

		switch (choice)
		{
			/*Новый документ
				Открыть существующий документ
				Сохранить документ
				Выйти из редактора*/
		case 1:
		{

			break;
		}

		case 2:
		{

			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{
			std::cout << "Exiting the text editor." << std::endl;
			return 0;
		}

		default:
			std::cout << "Invalid choice. Please choose again." << std::endl;
			break;
		}


	} while (true);

    return 0;
}
