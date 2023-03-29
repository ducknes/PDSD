#include <iostream>
#include <string>
#include <time.h>
using namespace std;

struct Set {
    int element;
    Set* next;
};

//  Создание пустого множества
Set* createEmptySet();

//  Проверка на пустоту множества
bool isEmptySet(Set* first);

//  Проверка элемента на принадлежность множеству
bool isSetHasElement(Set* first, int element); 

//  Добавление нового элемента в начало множества
Set* addNewElement(Set* first, int element); 

//  Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Set* createNewSet(int quantity, int min, int max); 

//  Мощность множества
int setPowers(Set* first); 

//  Вывод элементов множества
string setView(Set* first, char separator); 

//  Удаление множества (очистка занимаемой множеством памяти)
Set* deleteSet(Set* first);

// Подмножестов А-B