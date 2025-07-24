#include <iostream>
#include <string>
#include <locale>

class Calculator {
private:
    double num1;
    double num2;
public:
    double add() { return num1 + num2; }
    double multiply() { return num1 * num2; }
    double subtract_1_2() { return num1 - num2; }
    double subtract_2_1() { return num2 - num1; }
    double divide_1_2() { return num1 / num2; }
    double divide_2_1() { return num2 / num1; }
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else { return false; }
    }
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else { return false; }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Calculator calc;
    double num1, num2;
    bool num1_set = false;
    bool num2_set = false;
    while (true) {

        num1_set = false;
        num2_set = false;
        while (!num1_set)
        {
            std::cout << "Введите num1: ";
            std::cin >> num1;
            if (calc.set_num1(num1))
            {
                num1_set = true;
            }
            else
            {
                std::cout << "Неверный ввод!" << std::endl;
            }
        }
        while (!num2_set)
        {
            std::cout << "Введите num2: ";
            std::cin >> num2;
            if (calc.set_num2(num2))
            {
                num2_set = true;
            }
            else {
                std::cout << "Неверный ввод!" << std::endl;
            }
        }
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;

    }
    return 0;
}
