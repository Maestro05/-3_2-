// ЛАБ3_2КУРС.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include<iomanip>
#include <string>
#include<conio.h>
#define maxvalue 27
using namespace std; 

class Order;
class Food;

int Select(int a, int b, string text)
{
    int selection;
    string check;
    do
    {
        cout << "\n" << text << ": ";
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

    friend int Select(int a, int b, string text);

    Food()
    {
        this->count = this->index = 0;
    }

    void Infromation(int size)
    {
        bool check = true;

        int value = size - 1;

        for (int i = 0; i < size; i++)
        {
            if (this[i].index == this[size-1].index) { value = i; break; }
        }
        cout << endl << "Информация о " << this[value].name << ":" << endl << endl
            << "Каллорий: " << this[value].calories << endl
            << "Белки: " << this[value].proteins << endl
            << "Углеводы: " << this[value].carbohydrates << endl
            << "Жиры: " << this[value].fats << endl
            << "Вес: " << this[value].weight << endl
            << "Цена: " << this[value].price << endl
            << string(18 + this[value].name.length(), '-') << endl;
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
        else choice3 = -1;
    }

    void MainDish(int choice, int key)
    {
        if (choice == 1) PassStats(this, "Суп овощной", 360, 200, 330, 9, 15, 4.5, 11, key);
        else if (choice == 2) PassStats(this, "Стейк филе-миньон", 1300, 678, 230, 36.8, 11.5, 41.4, 12, key);
        else if (choice == 3) PassStats(this, "Пицца Пепперони", 579, 1291, 420, 48.3, 47.9, 41.4, 13, key);
        else PassStats(this, "Бургер Двойное мясо", 354.99, 1050, 367, 47, 57, 70, 14, key);
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

    void OneMore(Food *&dish,int &size)
    {
        if (dish[size - 1].count != 0)
        {
            Food* food = new Food[size + 1];
            
            for (int i = 0; i < size; i++)
            {
                food[i] = dish[i];
            }

            delete[] dish;

            dish = food;
            size++;
        }
    }
};

class Order
{
private:
    int
        number,
        sum,
        sumend,
        index;

    bool unchange;

    Food keep[maxvalue]{};
public:
    friend int Select(int a, int b, string text);

    Order()
    {
        sum = sumend = index = 0;
        number = 1;
    }

    void Korzinka(const Food* food, int size)
    {
        if (food[0].count != 0)
        {

            for (int i = 0; i < size; i++)
            {
                this->unchange = true;
                for (int j = 0; j < this->index + 1; j++)
                {
                    if (keep[j].index == food[i].index) {
                        keep[j].count += food[i].count;
                        this->unchange = false;
                        break;
                    }
                }
                if (unchange)
                {
                    keep[this->index].name = food[i].name;
                    keep[this->index].count += food[i].count;
                    keep[this->index].index = food[i].index;
                    keep[this->index].price = food[i].price;
                    this->index++;
                }
            }
            cout << "Корзинка Чек №" << this->number << endl << endl;
            for (int i = 0; i < size; i++)
            {
                if (food[i].count != 0 )
                {
                    cout << food[i].name << setw(47 - food[i].name.length())
                        << food[i].count << " шт. х " << food[i].price << endl;

                    this->sum += food[i].price * food[i].count;
                }
            }
            cout << string(60, '-') << endl << "Общая сумма заказа: " << this ->sum;
            
            this->sumend += this->sum;
            this->sum = 0;
            this->number++;
        }
        else
        {
            cout << "В корзине пусто";
        }
    }

    void FinalCount()
    {
        cout << "Общие итоги:" << endl << endl;

        for (int i = 0; i < this->index + 1; i++)
        {
            if (keep[i].count != 0)
            {
                cout << keep[i].name << setw(47 - keep[i].name.length())
                    << keep[i].count << " шт. х " << keep[i].price <<endl;
            }
            else break;
        }
        cout << string(60, '-') << endl << "Общая сумма заказа: " << this->sumend <<endl;
    }

};

void PassStats(Food* food, string name,
    double price, double calories, double weight,
    double proteins, double carbohydrates, double fats,
    int index,int size)
{
    bool check = true;

    if (size > 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (food[i].index == index) { check = false; break; }
        }
    }
    if (check)
    {
        food[size - 1].name = name;
        food[size - 1].price = price;
        food[size - 1].calories = calories;
        food[size - 1].weight = weight;
        food[size - 1].proteins = proteins;
        food[size - 1].carbohydrates = carbohydrates;
        food[size - 1].fats = fats;
    }
    food[size - 1].index = index;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Order zakaz;
    
    string zagadka = "Abuz";

    int choice1, 
        choice2, 
        choice3,
        mode;

    int size;
   
    char exit;

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
                        if (choice3 != 5)
                        {
                            desk->MainDish(choice3, size);
                            desk->Infromation(size);
                            desk->TakeCount(choice3, size);
                            desk->OneMore(desk,size);
                        }
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
                        if (choice3 != 5)
                        {
                            desk->Snack(choice3, size);
                            desk->Infromation(size);
                            desk->TakeCount(choice3, size);
                            desk->OneMore(desk,size);
                        }
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
                        if (choice3 != 5)
                        {
                            desk->Dessert(choice3, size);
                            desk->Infromation(size);
                            desk->TakeCount(choice3, size);
                            desk->OneMore(desk,size);
                        }
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
                        if (choice3 != 4)
                        {
                            desk->Combo(choice3, size);
                            desk->Infromation(size);
                            desk->TakeCount(choice3, size);
                            desk->OneMore(desk,size);
                        }
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
                        if (choice3 != 5)
                        {
                            desk->Drink(choice3, size);
                            desk->Infromation(size);
                            desk->TakeCount(choice3, size);
                            desk->OneMore(desk,size);
                        }
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
                        if (choice3 != 5)
                        {
                            desk->MilkShake(choice3, size);
                            desk->Infromation(size);
                            desk->TakeCount(choice3, size);
                            desk->OneMore(desk,size);
                        }
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
                        if (choice3 != 5)
                        {
                            desk->Sous(choice3, size);
                            desk->Infromation(size);
                            desk->TakeCount(choice3, size);
                            desk->OneMore(desk,size);
                        }
                    } while (choice3 != 5);
                }
                else if (choice2 == 8)
                {
                    system("cls");
                    cout << "Вы уверены ?:" << endl << endl << "1.Да" << endl << "2.Нет" << endl;
                    choice3 = Select(1, 2, "Выбор действия");
                    if (choice3 == 1)
                    {
                        system("cls");
                        zakaz.Korzinka(desk, size);
                        cout << endl;
                        do
                        {
                            cout << endl << "Нажмите на 1, чтобы вернуться в меню" << endl;
                        } while ((exit = _getch()) != '1');
                    }
                    else choice2 = -1;
                }
            } while (choice2 != 8 && choice2 != 9);
            system("cls");
        }
        delete[] desk;
    } while (choice1 != 2);
    cout << endl << "Спасибо!" << endl << endl;
    zakaz.FinalCount();
    return 0;
}
