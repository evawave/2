#include <iostream>
#include <conio.h>
#include <clocale>

using namespace std;


struct comp
{
    int data;
    comp* next;
};
comp* top1 = NULL, * zad1 = NULL, * top2 = NULL, * zad2 = NULL;

void push1(int n)
{
    comp* p = new comp;
    p->data = n;
    p->next = NULL;
    if (top1 == NULL)
    {
        top1 = p;
        zad1 = p;
    }
    else
    {
        p->next = top1;
        top1 = p;
        zad1 = p;
    }

}

int pop1()
{
    int n = top1->data;
    comp* p = top1;
    top1 = top1->next;
    delete p;
    return n;
}

void print1()
{
    comp* c = top1;
    if (top1 == NULL) cout << "элементов нет";
    else
    {
        cout << "элементы очереди: ";
        while (c != NULL)
        {
            cout << c->data << " ";
            c = c->next;
        }
    }
    cout << endl;
}
comp* copy(int n) {
    comp* pv = new comp;
    pv->data = n;
    if (top2 == NULL)
    {
        top2 = pv;
        pv->next = NULL;
    }
    else
    {
        pv->next = top2;
        top2 = pv;
    }
    return pv;
}

void print2()
{
    comp* p = top2;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void push2(int n)
{
    comp* p = new comp;
    p->data = n;
    p->next = NULL;
    if (top2 == NULL)
    {
        top2 = p;
        zad2 = p;
    }
    else
    {
        top2->next = p;
        zad2 = p;
    }
}

int pop2()
{
    int n = top2->data;
    comp* p = top2;
    top2 = top2->next;
    delete p;
    return n;
}


int main()
{
    setlocale(LC_ALL, "ru");
    int num, n, g;
    while (1) {
        cout << "Выберите действие: \n";
        cout << "1 - Добавление элемента согласно правилам работы со структурой\n";
        cout << "2 - Удаление элемента\n";
        cout << "3 - Удаление всех элементов\n";
        cout << "4 - Отображение элементов структуры  в прямом порядке\n";
        cout << "5 - Удаление всех чисел кратных 7\n";
        cout << "6 - Выход из программы\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "Введите число от -20 до 60\n";
            cin >> n;
            while (!(n <= 60 && n >= -20)) {
                cout << "Вы ввели неправильное число, попробуйте ещё раз\n";
                cin >> n;
            }
            push1(n);
            g = n;
            break;
        case 2:
            pop1();
            cout << "Элемент <<" << g << ">> удалён\n";
            break;
        case 3:
            while (top1 != NULL)
                pop1();
            cout << "Все элементы удалены\n";
            break;
        case 4:
            print1();
            break;
        case 5:
            while (top1 != NULL) {
                if (top1->data % 7 == 0) {
                    pop1();
                }
                else {
                    n = top1->data;
                    copy(n);
                    pop1();
                }
            }
            while (top2 != NULL) {
                n = top2->data;
                push1(n);
                pop2();
            }
            print2();
            break;
        case 6:
            exit(0);
        default:
            cout << "Неверный номер действия\n";
            break;
        }
    }
}
