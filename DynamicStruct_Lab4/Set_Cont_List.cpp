#include "SetLab4_Antonov.h"

int main() {
    Set* A = new Set(6 + rand() % 3, 10, 99, 'A');
    Set* B = new Set(6 + rand() % 3, 10, 99, 'B');

    cout << "Множество A: " << A->setView(' ') << endl;
    cout << "Множество В: " << B->setView(' ') << "\n" << endl;

    cout << "Мощность А: " << A->setPowers() << endl;
    cout << "Мощность B: " << B->setPowers() << "\n" << endl;
    
    cout << "А подмножество В: " << boolalpha << A->isSubSet(B) << endl;
    cout << "А подмножество А: " << boolalpha << A->isSubSet(A) << "\n" << endl;

    cout << "А = B: " << boolalpha << A->isSetsEquals(B) << endl;
    cout << "А = A: " << boolalpha << A->isSetsEquals(A) << "\n" << endl;
    
    Set* C = A->unionOfSets(B);
    cout << "Объединённое множество С: " << C->setView(' ') << "\n" << endl;

    Set* D = A->intersectionsOfSets(B);
    cout << "Пересечение А и В: " << D->setView(' ') << "\n" << endl;

    Set* E = A->differenceOfSets(B);
    Set* E2 = B->differenceOfSets(A);
    cout << "Разность А-В: " << E->setView(' ') << endl;
    cout << "Разность B-A: " << E2->setView(' ') << "\n" << endl;

    Set* F = A->symmetricDifferenceOfSets(B);
    cout << "Симметричная разность А-В: " << F->setView(' ') << "\n" << endl;

    A->~Set();
    B->~Set();
    cout << "Множество А после удаления: " << A->setView(' ') << endl;
    cout << "Множество В после удаления: " << B->setView(' ') << endl;

    return 0;
}