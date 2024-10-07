// ЛАБ3_2КУРС.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

class Order;
class Food;

int Select(int a, int b, string text)
{
    int selection;
    do
    {
        cout << "\n" << text << " :";
        cin >> selection;
    } while (selection < a || selection > b);

    return selection;
}

class Food
{
private:
    string name;
    double
        weight,
        calories,
        proteins,
        carbohydrates,
        fats,
        price;
    int count,
        index;
public:
    friend Order;
   
    Food()
    {
        count = 0;
    }

    void Infromation()
    {
        cout << "Информация о еде " << this->name << endl
            << "Белки: " << this->proteins << endl
            << "Углеводы: " << this->carbohydrates << endl
            << "Жиры: " << this->fats << endl
            << "Вес: " << this->weight << endl
            << "Каллорий: " << this->calories << endl;
    }

    void First()
    {
        this->name = "Бургер";
    }
};

class Order
{
private:
    int
        count,
        number,
        sum;
public:
    friend int Select(int a, int b, char text[]);

    Order()
    {
        sum = count = 0;
        number = 1;
    }

    void Korzinka(Food &order)
    {
        cout << order.name << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");

    Food burger;
    Order zakaz;

    burger.First();
    zakaz.Korzinka(burger);
}
