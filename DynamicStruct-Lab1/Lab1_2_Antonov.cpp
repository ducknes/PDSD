#include "SetLab1_2_Antonov.h"

int main(int argc, char **argv){
    setlocale(LC_ALL, "Russian");
    
    srand(time(NULL));
    
    Set* A = createNewSet(6 + rand() % 3, 10, 100, 'A');
    Set* B = createNewSet(6 + rand() % 3, 10, 100, 'B');
    
    cout << "Подмножество А: " << setView(A, ' ') << endl;
    cout << "Подмножество B: " << setView(B, ' ') << "\n" << endl;

    cout << "А подмножество B: " << boolalpha << isSubSet(A, B) << endl;
    cout << "А подмножество A: " << boolalpha << isSubSet(A, A) << "\n" << endl;

    cout << "A = B: " << boolalpha << isSetsEquals(A, B) << endl;
    cout << "A = A: " << boolalpha << isSetsEquals(A, A) << "\n" << endl;
    
    Set* C = unionOfSets(A, B);
    cout << "Объединенное множество: " << setView(C, ' ') << "\n" << endl;

    Set* D = intersectionsOfSets(A, B);
    cout << "Пересечение A и В: " << setView(D, ' ') << "\n" << endl;

    Set* E = differenceOfSets(A, B);
    cout << "Разность А - В: " << setView(E, ' ') << endl;
    Set* F = differenceOfSets(B, A);
    cout << "Разность B - A: " << setView(F, ' ') << "\n" << endl;

    Set* G = symmetricDifferenceOfSets(A, B);
    cout << "Симметричная разность A - B: " << setView(G, ' ') << "\n" << endl;

    return 0;
}