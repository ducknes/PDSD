#include <iostream>
#include <string>
#include <time.h>
using namespace std;

struct Set {
    int element;
    Set* next;
};

// F1  Создание пустого множества
Set* createEmptySet();

// F2 Проверка на пустоту множества
bool isEmptySet(Set* first);

// F3 Проверка элемента на принадлежность множеству
bool isSetHasElement(Set* first, int element); 

// F4 Добавление нового элемента в начало множества
Set* addNewElement(Set* first, int element); 

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Set* createNewSet(int quantity, int min, int max, char whichCreate); 

// F6 Мощность множества
int setPowers(Set* first); 

// F7 Вывод элементов множества
string setView(Set* first, char separator); 

// F8 Удаление множества (очистка занимаемой множеством памяти)
Set* deleteSet(Set* first);

// F9 Подмножестов А-B
bool isSubSet(Set* first, Set* second);

// F10 Равенство двух множеств А-В
bool isSetsEquals(Set* first, Set* second);

// F11 Объединение двух множеств
Set* unionOfSets(Set* first, Set* second);

// F12 Пересечение двух множеств
Set* intersectionsOfSets(Set* first, Set* second);

// F13 Разность множеств
Set* differenceOfSets(Set* first, Set* second);

// F14 Симметричная разность
Set* symmetricDifferenceOfSets(Set* first, Set* second);