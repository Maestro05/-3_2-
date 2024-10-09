// ЛАБ3_2КУРС.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
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
    friend void PassStats(Food* food, string name,
        double price, double calories, double weight,
        double proteins, double carbohydrates, double fats,
        int index, int size);

    friend Order;

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
            << string (18 + this->name.length(), '-') << endl;
    }

    void First(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Суп овощной", 360, 200, 330, 9, 15, 4.5, 11, key);
        else if (choice == 2) PassStats(this, "Стейк филе-миньон", 1300, 678, 230, 36.8, 11.5, 41.4, 12, key);
        else if (choice == 3) PassStats(this, "Пицца Пепперони", 579, 1291, 420, 48.3, 47.9, 41.4, 134, key);
        else PassStats(this, "Бурер Двойное мясо", 354.99, 1050, 367, 47, 57, 70, 14, key);
    }

    Food OneMore(const Food *dish, int *size)
    {
        Food* food = new Food[(*size) + 1];

        for (int i = 0; i < (*size); i++)
        {
            food[i] = dish[i];
        }

        delete[] this;
        (*size)++;
        return *food;
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

    void Korzinka(const Food *order)
    {
        
    }

};

void PassStats(Food *food, string name,
    double price, double calories, double weight,
    double proteins, double carbohydrates, double fats,
    int index,int size)
{
    food[size- 1].name = name;
    food[size - 1].price = price;
    food[size - 1].calories = calories;
    food[size - 1].weight = weight;
    food[size - 1].proteins = proteins;
    food[size - 1].carbohydrates = carbohydrates;
    food[size - 1].fats = fats;
    food[size - 1].index = index;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int choice1, 
        choice2, 
        choice3;

    int size = 1;

    do
    {
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
                            << "3.Муравейник" << endl << endl
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
                else if (choice2 == 8);
            } while (choice2 != 9);
            system("cls");
        }
    } while (choice1 != 2);

    cout << endl << "Спасибо!" << endl;

    /*delete[] desk;*/
 
    return 0;
}
