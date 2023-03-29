#include "SetLab1_2_Antonov.h"

//  Создание пустого множества
Set* createEmptySet() {
    return new Set();
}

//  Проверка на пустоту множества
bool isEmptySet(Set* first) {
    return first == nullptr ? true : false;
}

//  Проверка элемента на принадлежность множеству
bool isSetHasElement(Set* first, int element) {
    if (isEmptySet(first)) {
        return false;
    } else {
        Set* current = first;
        while (current != NULL)
        {
            if (current -> element == element){
                return true;
            }
            current = current -> next;
        }
    }
    return false;
}

//  Добавление нового элемента в начало множества
Set* addNewElement(Set* first, int element) {
    if (!isSetHasElement(first, element)){
        Set* newSet = new Set;
        newSet->element = element;
        newSet->next = first;
        first = newSet;
    }
    return first;
}

//  Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Set* createNewSet(int size, int min, int max) {
    if (size <= 0) {
        return NULL;
    }

    Set* newSet = new Set;
    srand(time(NULL));
    int currentSize = 1;
    while (currentSize < size) {
        int temp = newSet->element;
        newSet = addNewElement(newSet, rand() % (max - min + 1) + min);
        if (temp != newSet->element) {
            currentSize++;
        }
    }

    return newSet;
}

//  Мощность множества
int setPowers(Set* first) {
    long count = 0;
    Set* currentSet = first;
    while (currentSet != NULL) {
        count++;
        currentSet = currentSet->next;
    }
    return count;
}

//  Вывод элементов множества
string setView(Set* first, char separator) {
    if (isEmptySet(first)) {
        return "";
    }
    Set* currentSet = first;
    string result = "";
    while (currentSet != NULL) {
        result += to_string(currentSet->element);
        if (currentSet->next != NULL){
            result += separator;
        }
        currentSet = currentSet->next;
    }
    return result;
}

//  Удаление множества (очистка занимаемой множеством памяти)
Set* deleteSet(Set* first) {
    while (first != NULL){
        Set* temp = first;
        first = first->next;
        delete temp;
    }
    return first;
}