#include "SetLab1_2_Antonov.h"

// F1 Создание пустого множества
Set* createEmptySet() {
    return NULL;
}

// F2 Проверка на пустоту множества
bool isEmptySet(Set* first) {
    return first == nullptr ? true : false;
}

// F3 Проверка элемента на принадлежность множеству
bool isSetHasElement(Set* first, int element) {
    if (isEmptySet(first)) {
        return false;
    } 
    Set* current = first;
    while (current != NULL)
    {
        if (current -> element == element){
            return true;
        }
        current = current -> next;
    }
    return false;
}

// F4 Добавление нового элемента в начало множества
Set* addNewElement(Set* first, int element) {
    if (!isSetHasElement(first, element)){
        Set* newSet = new Set;
        newSet->element = element;
        newSet->next = first;
        first = newSet;
    }
    return first;
}

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Set* createNewSet(int size, int min, int max, char whichCreate) {
    if (size <= 0) {
        return NULL;
    }

    if (max < min) {
        return NULL;
    }

    if (size > max - min + 1) {
        return NULL;
    }

    Set* newSet = new Set{};    
    int currentSize = 1;
    srand(time(NULL));

    switch (whichCreate)
    {
    case 'A':
        newSet->element = ((min + 3) + rand() % ((max - min + 1))) / 3 * 3;
        while (currentSize < size) {
            int temp = newSet->element;
            newSet = addNewElement(newSet, ((min + 3) + rand() % ((max - min + 1))) / 3 * 3);
            if (temp != newSet->element) {
                currentSize++;
            }
        }
        break;
    case 'B':
        newSet->element = min + (rand() % ((max / 2 - min / 2))) * 2 + 1;
        while (currentSize < size) {
            int temp = newSet->element;
            newSet = addNewElement(newSet, min + (rand() % ((max - min) / 2)) * 2 + 1);
            if (temp != newSet->element) {
                currentSize++;
            }
        }
        break;
    default:
        break;
    }

    return newSet;
}

// F6 Мощность множества
int setPowers(Set* first) {
    long count = 0;
    Set* currentSet = first;
    while (currentSet != NULL) {
        count++;
        currentSet = currentSet->next;
    }
    return count;
}

// F7 Вывод элементов множества
string setView(Set* first, char separator) {
    if (isEmptySet(first)) {
        return "";
    }
    Set* currentSet = first;
    string result = "";
    while (currentSet != NULL) {
        result += to_string(currentSet->element) + separator;
        currentSet = currentSet->next;
    }

    return result.erase(result.size() - 1);
}

// F8 Удаление множества (очистка занимаемой множеством памяти)
Set* deleteSet(Set* first) {
    while (first != NULL){
        Set* temp = first;
        first = first->next;
        delete temp;
    }
    return first;
}

// F9 Подмножестов А-B
bool isSubSet(Set* first, Set* second) {
    if (isEmptySet(first)) {
        return true;
    }

    if (setPowers(first) > setPowers(second)) {
        return false;
    }
    
    Set* currentFirst = first;
    while (currentFirst != NULL) {
        if (!isSetHasElement(second, currentFirst->element)) {
            return false;
        }
        currentFirst = currentFirst->next;
    }

    return true;
}

// F10 Равенство двух множеств А-В
bool isSetsEquals(Set* first, Set* second) {
    return isSubSet(first, second) && isSubSet(second, first);
}

// F11 Объединение двух множеств
Set* unionOfSets(Set* first, Set* second) {

    Set* unionSet = createEmptySet();
    Set* currentFirst = first;
    Set* currentSecond = second;
    
    while (currentFirst != NULL) {
        unionSet = addNewElement(unionSet, currentFirst->element);
        currentFirst = currentFirst->next;
    }

    while (currentSecond != NULL) {
        unionSet = addNewElement(unionSet, currentSecond->element);
        currentSecond = currentSecond->next;
    }
    
    return unionSet;
}

// F12 Пересечение двух множеств
Set* intersectionsOfSets(Set* first, Set* second) {
    Set* current = first;
    Set* intersection = createEmptySet();

    while (current != NULL) {
        if (!isEmptySet(current)) {
            if (isSetHasElement(second, current->element)){
                intersection = addNewElement(intersection, current->element);
            }
            current = current->next;
        }
    }
    return intersection;
}

// F13 Разность множеств
Set* differenceOfSets(Set* first, Set* second) {
    Set* current = first;
    Set* intersection = createEmptySet();

    while (current != NULL) {
        if (!isEmptySet(current)) {
            if (!isSetHasElement(second, current->element)){
                intersection = addNewElement(intersection, current->element);
            }
            current = current->next;
        }
    }
    return intersection;
}

// F14 Симметричная разность
Set* symmetricDifferenceOfSets(Set* first, Set* second) {
    return differenceOfSets(unionOfSets(first, second), intersectionsOfSets(second, first));
}