#include <iostream>
#include <locale>
#include <string>
#include <Windows.h>

class Counter {
private:
	int count;
public:
	Counter(int countM = 0) : count(countM) {}
	void setCount(int countM) {
		if (count == 0)
		{
			count = countM;
		}
		else { std::cout << "Начальное значение счётчика уже установлено."; }
	}
	int increment()
	{
		return ++count;
	}
	int decrement()
	{
		return --count;
	}
	int getCount()
	{
		return count;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int num;
	char ch;
	std::string answer;
	Counter counter;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::getline(std::cin, answer);
	while ((answer != "да") && (answer != "нет"))
	{
		std::cout << "Введите да или нет: ";
		std::getline(std::cin, answer);
	}


	if (answer == "да")
	{
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> num;
		counter.setCount(num);
	}
	else { std::cout << "Начальное значение счётчика останется стандартным (0)" << std::endl; }
	std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
	std::cin >> ch;
	while (ch != 'x') 
	{ 
		switch (ch)
		{
		case '+':
			counter.increment();
			break;
		case '-': 
			counter.decrement();
			break;
		case '=':
			std::cout << counter.getCount() << std::endl;
			break;
		default:
			std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
			std::cin >> ch;
			break;
		}
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> ch;
	}
	std::cout << "До свидания!";
	return 0;
}
