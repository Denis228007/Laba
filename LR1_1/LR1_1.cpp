#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

class Adressa {
private:
    char name[50];
    char street[50];
    int numbhouse;
public:
    Adressa(const char* _name, const char* _street, int _numbhouse) {
        cout << "Викликано конструктор з параметрами за адресою: " << this << endl;
        strcpy_s(name, _name);
        strcpy_s(street, _street);
        numbhouse = _numbhouse;
    }


    Adressa() {
        cout << "Викликано конструктор без параметрів за адресою: " << this << endl;
        strcpy_s(name, "Іван");
        strcpy_s(street, "Перемоги");
        numbhouse = 0;
    }


    Adressa(const Adressa& adressa) {
        cout << "Викликано конструктор копіювання для об'єкта за адресою: " << &adressa << " створено об'єкт за адресою: " << this << endl;
        strcpy_s(name, adressa.name);
        strcpy_s(street, adressa.street);
        numbhouse = adressa.numbhouse;
    }


    ~Adressa() {
        cout << "Викликано деструктор, вивільняється пам'ять з-під класу за адресою: " << this << endl;
    }


    void setName(const char* _name) {
        strcpy_s(name, _name);
    }

    const char* getName() {
        return name;
    }

    void setStreet(const char* _street) {
        strcpy_s(street, _street);
    }

    const char* getStreet() {
        return street;
    }

    void setNumbHouse(int _numbhouse) {
        numbhouse = _numbhouse;
    }

    int getNumbHouse() {
        return numbhouse;
    }


    void getAllInfo() {
        cout << "Ім'я: " << name << ", Вулиця: " << street << ", Номер будинку: " << numbhouse << "\n";
    }


    void setAllInfo(const char* _name, const char* _street, int _numbhouse) {
        strcpy_s(name, _name);
        strcpy_s(street, _street);
        numbhouse = _numbhouse;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Adressa adressa1("Денис", "Гучка", 10);
    adressa1.getAllInfo();
    cout << "\n";

    Adressa adressa2;
    adressa2.getAllInfo();
    cout << "\n";

    Adressa* adressa3 = new Adressa;
    adressa3->setAllInfo("Генадій Васильвич", "Тернопільська", 5);
    adressa3->getAllInfo();
    adressa3->setNumbHouse(15);
    adressa3->getAllInfo();
    cout << "\n";

    void (Adressa:: * p_fun)();
    p_fun = &Adressa::getAllInfo;
    (adressa1.*p_fun)();
    cout << "\n";

    Adressa gr_adressa[3] = {
        Adressa("Назар Назарович", "Київська", 25),
        Adressa("Олексій Федюк", "Лесі Українки", 34),
        Adressa("Артур Конончук", "Богдана Хмельницького", 17)
    };
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        gr_adressa[i].getAllInfo();
    }

    delete adressa3;
    return 0;
}