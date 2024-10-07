// ЛАБ3_2КУРС.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

int Select(int a, int b, char text[])
{
    int selection;
    do
    {
        printf("\n%s: ", text);
        scanf("%d", &selection);
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
public:
    friend int Select(int a, int b, char text[]);

    void Infromation()
    {
        cout << "Информация о еде " << this->name << endl
            << "Белки: " << this->proteins << endl
            << "Углеводы: " << this->carbohydrates << endl
            << "Жиры: " << this->fats << endl
            << "Вес: " << this->weight << endl
            << "Каллорий: " << this->calories << endl
            << "\n----------------------\n1.Заказать\n\n2.Отмена\n";
        int choice = Select(1, 2, "Выбор действия");
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
    Order()
    {
        sum = count = 0;
        number = 1;
    }
    void Korzinka(Food &order)
    {

    }
};
int main()
{
    setlocale(LC_ALL, "rus");

}
