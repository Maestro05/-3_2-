// ЛАБ3_2КУРС.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include<iomanip>
#include <string>
using namespace std; 

class Order;
class Food;

int Select(int a, int b, string text)
{
    int selection;
    string check;
    do
    {
        cout << "\n" << text << " :";
        cin >> check;
        check.find_first_not_of("0123456789") == string::npos ? selection = stoi(check) : selection = 0;
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
    friend bool PassStats(Food* food, string name,
        double price, double calories, double weight,
        double proteins, double carbohydrates, double fats,
        int index, int size);

    friend Order;

    friend int Select(int a, int b, string text);

    Food()
    {
        this->count = this->index = 0;
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
            << string(18 + this->name.length(), '-') << endl;
    }

    void TakeCount(int &choice3,int size)
    {
        int choice , rezerv; 
        bool unchange = true;

        cout << "1.Выбрать" << endl << "2.Отмена" << endl;
        choice = Select(1, 2, "Выбор действия");

        if (choice == 1) { 
            for (int i = 0; i < size; i++)
            {
                if (this[i].index == this[size - 1].index) { rezerv = i; unchange = false; break; }
            }
            if(unchange) this[size - 1].count += Select(1, 100, "Количество");
            else this[rezerv].count += Select(1, 100, "Количество");
        }
        else choice3 = 5;
    }

    void MainDish(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Суп овощной", 360, 200, 330, 9, 15, 4.5, 11, key);
        else if (choice == 2) PassStats(this, "Стейк филе-миньон", 1300, 678, 230, 36.8, 11.5, 41.4, 12, key);
        else if (choice == 3) PassStats(this, "Пицца Пепперони", 579, 1291, 420, 48.3, 47.9, 41.4, 13, key);
        else PassStats(this, "Бурер Двойное мясо", 354.99, 1050, 367, 47, 57, 70, 14, key);
    }
    void Snack(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Картошка фри", 94, 310, 155, 5.5, 50, 5.5, 21, key);
        else if (choice == 2) PassStats(this, "Наггетсы (6 шт.)", 109, 290, 165, 13, 16, 14, 22, key);
        else if (choice == 3) PassStats(this, "Крылышки (1 шт.)", 60, 71, 33, 5.1, 1, 4.3, 23, key);
        else PassStats(this, "Стрипсы", 210, 460, 206, 31, 31, 24, 24, key);
    }
    void Dessert(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Чизкейк", 169, 330, 100, 6.9, 28.5, 22.1, 31, key);
        else if (choice == 2) PassStats(this, "Тирамису", 169, 269, 100, 3.2, 30.7, 11.1, 32, key);
        else if (choice == 3) PassStats(this, "Пирожное Муравейник", 60, 440, 100, 9.5, 16.5, 21.9, 33, key);
        else PassStats(this, "Горячий брауни", 125, 370, 80, 4, 31, 26, 34, key);
    }
    void Combo(int choice, int key)
    {
        if (choice == 1) PassStats(this, "5 за 200", 200, 400, 300, 25, 37, 20, 41, key);
        else if (choice == 2) PassStats(this, "5 за 300", 300, 450, 350, 30, 40, 23, 42, key);
        else PassStats(this, "5 за 350", 350, 500, 500, 32, 42, 26, 43, key);
    }
    void Drink(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Эвервесс Кола 0.5 л", 80, 220, 500, 0, 55.5, 0, 51, key);
        else if (choice == 2) PassStats(this, "Фрустайл Апельсин 0.5 л", 80, 220, 500, 0, 55.5, 0, 52, key);
        else if (choice == 3) PassStats(this, "Липтон Грин 0.5 л", 80, 220, 500, 0, 55.5, 0, 53, key);
        else PassStats(this, "Дюшес 0.5 л", 80, 220, 500, 0, 55.5, 0, 54, key);
    }
    void MilkShake(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Шоколадный Шейк 0.4 л", 90, 380, 400, 10, 72, 8, 61, key);
        else if (choice == 2) PassStats(this, "Шейк Пломбир 0.4 л", 90, 380, 400, 10, 72, 8, 62, key);
        else if (choice == 3) PassStats(this, "Клубничный Шейк 0.4 л", 90, 380, 400, 10, 72, 8, 63, key);
        else PassStats(this, "Ягодный Шейк 0.4 л", 90, 380, 400, 10, 72, 8, 64, key);
    }
    void Sous(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Томатный Соус", 60, 110, 25, 1.5, 25, 1, 71, key);
        else if (choice == 2) PassStats(this, "Соус Сырный", 60, 110, 25, 1.5, 25, 1, 72, key);
        else if (choice == 3) PassStats(this, "Соус Барбеню", 60, 110, 25, 1.5, 25, 1, 73, key);
        else PassStats(this, "Соус Чесночный", 60, 110, 25, 1.5, 25, 1, 74, key);
    }

    Food OneMore(const Food *dish, int &size)
    {
        if (dish[size - 1].count != 0)
        {
            Food* food = new Food[size + 1];

            for (int i = 0; i < size; i++)
            {
                food[i] = dish[i];
            }

            delete[] this;
            size++;
            return *food;
        }
    }
};

class Order
{
private:
    int
        number,
        sum;
public:
    friend int Select(int a, int b, string text);

    Order()
    {
        sum = 0;
        number = 1;
    }

    void Korzinka(const Food *food, int size)
    {
        if (food[0].count != 0)
        {
            cout << "Корзинка Чек №" << this->number << endl << endl;
            for (int i = 0; i < size; i++)
            {
                cout << food[i].name << setw(47 - food[i].name.length()) 
                    << food[i].count << " шт. х " << food[i].price << endl;

                this->sum += food[i].price;
            }
            cout << string(58, '-') << endl << "Общая сумма заказа:" << endl << this ->sum;
        }
        else
        {
            cout << endl << "В корзине пусто";
        }
    }

};

bool PassStats(Food* food, string name,
    double price, double calories, double weight,
    double proteins, double carbohydrates, double fats,
    int index,int size)
{
    if (size > 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (food[i].index == index) { return false; }
        }
    }

    food[size - 1].name = name;
    food[size - 1].price = price;
    food[size - 1].calories = calories;
    food[size - 1].weight = weight;
    food[size - 1].proteins = proteins;
    food[size - 1].carbohydrates = carbohydrates;
    food[size - 1].fats = fats;
    food[size - 1].index = index;

    return true;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Order zakaz;
    
    int choice1, 
        choice2, 
        choice3;

    int size;
    
    do
    {
        size = 1;
        Food *desk = new Food[size];
        cout << "Добро пожаловать в наше заведение!" << endl << endl
            << "1.Сделать заказ" << endl << endl
            << "2.Выйти" << endl;
        choice1 = Select(1, 2, "Выбор дейсвия");
        if (choice1 == 1)
        {
            do
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
                    << "9.На главное меню" << endl;
                choice2 = Select(1, 9, "Выбор дейсвия");
                if (choice2 == 1)
                {
                    do
                    {
                        system("cls");
                        cout << "Оформить Главное блюдо:" << endl << endl
                            << "1.Суп овощной" << endl << endl
                            << "2.Стейк филе-миньон" << endl << endl
                            << "3.Пицца Пепперони" << endl << endl
                            << "4.Бурер Двойное мясо" << endl << endl
                            << "5.Назад" << endl;
                        choice3 = Select(1, 5, "Выбор дейсвия");
                    } while (choice3 != 5);
                }
                else if (choice2 == 2)
                {
                    do
                    {
                        system("cls");
                        cout << "Оформить Закуски:" << endl << endl
                            << "1.Картошка фри" << endl << endl
                            << "2.Наггетсы" << endl << endl
                            << "3.Крылышки" << endl << endl
                            << "4.Стрипсы" << endl << endl
                            << "5.Назад" << endl;
                        choice3 = Select(1, 5, "Выбор дейсвия");
                    } while (choice3 != 5);
                }
                else if (choice2 == 3)
                {
                    do
                    {
                        system("cls");
                        cout << "Оформить Десерты:" << endl << endl
                            << "1.Чизкейк" << endl << endl
                            << "2.Тирамису" << endl << endl
                            << "3.Пирожное Муравейник" << endl << endl
                            << "4.Горячий брауни" << endl << endl
                            << "5.Назад" << endl;
                        choice3 = Select(1, 5, "Выбор дейсвия");
                    } while (choice3 != 5);
                }
                else if (choice2 == 4)
                {
                    do
                    {
                        system("cls");
                        cout << "Оформить Комбо:" << endl << endl
                            << "1.5 за 200" << endl << endl
                            << "2.5 за 300" << endl << endl
                            << "3.5 за 350" << endl << endl
                            << "4.Назад" << endl;
                        choice3 = Select(1, 4, "Выбор дейсвия");
                    } while (choice3 != 4);
                }
                else if (choice2 == 5)
                {
                    do
                    {
                        system("cls");
                        cout << "Оформить Напитки:" << endl << endl
                            << "1.Эвервесс Кола" << endl << endl
                            << "2.Фрустайл Апельсин" << endl << endl
                            << "3.Липтон Грин" << endl << endl
                            << "4.Дюшес" << endl << endl
                            << "5.Назад" << endl;
                        choice3 = Select(1, 5, "Выбор дейсвия");
                    } while (choice3 != 5);
                }
                else if (choice2 == 6)
                {
                    do
                    {
                        system("cls");
                        cout << "Оформить Милкшейки:" << endl << endl
                            << "1.Шоколадный Шейк" << endl << endl
                            << "2.Шейк Пломбир" << endl << endl
                            << "3.Клубничный Шейк" << endl << endl
                            << "4.Ягодный Шейк" << endl << endl
                            << "5.Назад" << endl;
                        choice3 = Select(1, 5, "Выбор дейсвия");
                    } while (choice3 != 5);
                }
                else if (choice2 == 7)
                {
                    do
                    {
                        system("cls");
                        cout << "Оформить Соус:" << endl << endl
                            << "1.Томатный Соус" << endl << endl
                            << "2.Соус Сырный" << endl << endl
                            << "3.Соус Барбеню" << endl << endl
                            << "4.Соус Чесночный" << endl << endl
                            << "5.Назад" << endl;
                        choice3 = Select(1, 5, "Выбор дейсвия");
                    } while (choice3 != 5);
                }
                else if (choice2 == 8)
                {
                    system("cls");
                    zakaz.Korzinka(desk, size);
                }
            } while (choice2 != 9);

            system("cls");
            /*delete[] desk;*/
        }
        delete[] desk;
    } while (choice1 != 2);

    cout << endl << "Спасибо!" << endl;
    return 0;
}
