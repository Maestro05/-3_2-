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
    friend void PassStats(Food& food, string name,
        double price, double calories, double weight,
        double proteins, double carbohydrates, double fats,
        int index);

    friend Order;

    Food()
    {
        count = index = 0;
    }

    void Infromation()
    {
        cout << "Информация о еде " << this->name << ":" << endl << endl
            << "Каллорий: " << this->calories << endl
            << "Белки: " << this->proteins << endl
            << "Углеводы: " << this->carbohydrates << endl
            << "Жиры: " << this->fats << endl
            << "Вес: " << this->weight << endl
            << "Цена: " << this->price << endl
            << string (18 + this->name.length(), '-') << endl;
    }

    void First(int choice)
    {
        if(choice == 1) PassStats(*this, "Суп овощной", 360, 200, 330, 9, 15, 4.5, 11);
        else if (choice == 2) PassStats(*this, "Стейк филе-миньон", 1300, 678, 230, 36.8, 11.5, 41.4, 12);
        else if (choice == 3) PassStats(*this, "Пицца Пепперони", 579, 1291, 420, 48.3, 47.9, 41.4, 134);
        else PassStats(*this, "Бурер Двойное мясо", 354.99, 1050, 367, 47, 57, 70, 14);
    }
};

class Order
{
private:
    int
        number,
        sum;
    bool
        turn;
public:
    friend int Select(int a, int b, string text);

    Order()
    {
        sum = 0;
        number = 1;
    }

    void Korzinka(Food &order)
    {
        
    }

};

void PassStats(Food& food, string name,
    double price, double calories, double weight,
    double proteins, double carbohydrates, double fats,
    int index)
{
    food.name = name;
    food.price = price;
    food.calories = calories;
    food.weight = weight;
    food.proteins = proteins;
    food.carbohydrates = carbohydrates;
    food.fats = fats;
    food.index = index;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Order zakaz;
    Food burger;

    bool turn = true;
    int choice;

    do
    {
        cout << "Добро пожаловать в наше заведение!" << endl << endl
            << "1.Сделать заказ" << endl << endl
            << "2.Выйти" << endl;
        choice = Select(1, 2, "Выбор дейсвия");
        if (choice == 1)
        {
            system("cls");
            cout << "Оформить заказ" << endl << endl
                << "1.Главное блюдо" << endl << endl
                << "2.Закуски" << endl << endl
                << "3.Десерты" << endl << endl
                << "4.Комбо" << endl << endl
                << "5.Напитки" << endl << endl
                << "6.Милкшейки" << endl << endl
                << "7.Соусы" << endl << endl
                << "8.Перейти к корзинке" << endl << endl
                << "9.Выход" << endl << endl;
            choice = Select(1, 9, "Выбор дейсвия");
            if (choice == 1) {}
            else turn = false;
        }
        else turn = false;
    } while (turn);

    cout << "Спасибо!" << endl;
}
