/*Простой текстовый редактор:
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

void CreateNewDocument(std::string& document)
{
	std::string text;
	std::cout << "Enter your text. Type '##' on a new line to finish: " << std::endl;

	std::string line;
	while (getline(std::cin, line) && line != "##")
	{
		text += line + "\n";
	}
	// Сохраняем текст в текущий документ
	document = text;
}

void OpenExistingDocument(std::string& document)
{
	std::string filename;
	std::cout << "Enter the filename to open: ";
	std::cin >> filename;

	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string text;
		std::string line;
		while (getline(file, line))
		{
			text += line + "\n";
		}
		file.close();
		document = text;
	}
	else
	{
		std::cout << "Error: Unable to open the file." << std::endl;
	}
}

void SaveDocument(const std::string& text)
{
	std::string filename;
	std::cout << "Enter the filename to save: ";
	std::cin >> filename;

	// Добавляем ".txt" к имени файла, если его нет
	if (filename.rfind(".txt") == std::string::npos)
	{
		filename += ".txt";
	}

	std::ofstream file(filename);
	if(file.is_open())
	{
		file << text;
		file.close();
		std::cout << "Document saved successfully." << std::endl;
	}
	else
	{
		std::cout << "Error: Unable to save the file." << std::endl;
	}
}

void EditTheDocument(std::string &document)
{
	std::string newText;
	std::cout<<"Enter the new text to replace the current content.\nType '##' on a new line to finish: " << std::endl;
	std::string line;
	while (getline(std::cin, line) && line != "##")
	{
		newText += line + "\n";
	}
	document = newText;

	std::cout << "Document has been edited." << std::endl;
}

void ShowMenu()
{
	std::cout << "Text Editor Menu:" << std::endl << std::endl;
	std::cout << "Choose from these options:" << std::endl;
	std::cout << "1. New document" << std::endl;
	std::cout << "2. Open an existing document" << std::endl;
	std::cout << "3. Save the document" << std::endl;
	std::cout << "4. Edit document" << std::endl;
	std::cout << "5. Exit" << std::endl;
}
int main()
{
	std::string document;
	int choice;
	do
	{
		ShowMenu();							//function ShowMenu
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			CreateNewDocument(document);
			break;
		}

		case 2:
		{
			OpenExistingDocument(document);
			break;
		}
		case 3:
		{
			SaveDocument(document);
			break;
		}
		case 4:
		{
			EditTheDocument(document);
			break;
		}
		case 5:
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
