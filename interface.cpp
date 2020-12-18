#include "sortFunctions.h"
#include <cstdlib>
#include "index.h"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

string FirstNames[10] {"Andrey", "Alexey", "Ivan", "Vasiliy", "Igor", "Egor", "Oleg", "Vladimir", "Alexander", "Michael"};
string MiddleNames[10] {"Ivanov", "Frolov", "Ivlev", "Roslovtsev", "Privalenko", "Korotkov", "Novikov", "Romanov", "Demidov", "Svetov"};
string LastNames[10] {"Andreevich", "Alexeevich", "Ivanovich", "Vasilievich", "Igorievich", "Egorovich", "Olegovich", "Vladimirovich", "Alexandrovich", "Michaelovich"};

template <class T>
void getTimeSearchIndex(IndexDictionary<T> *ind_dict, T index)
{
    auto begin = chrono::steady_clock::now();
    cout << "Found value:" << ind_dict->get(index) << endl;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cout << "Time consumed: " << elapsed_ms.count() << " ms" << endl;
    return;
}

string randomFN()
{
    int i = rand() % 10;
    return FirstNames[i];
}
string randomMN()
{
    int i = rand() % 10;
    return MiddleNames[i];
}
string randomLN()
{
    int i = rand() % 10;
    return LastNames[i];
}
int randomBY()
{
    return 1920 + (rand() % 100);
}
Person enterPerson()
{
    string fn = "";
    string mn = "";
    string ln = "";
    int by = 0;
    cout << "Enter the FIRST NAME of the person" <<endl;
    cin >> fn;
    cout << endl;
    cout << "Enter the MIDDLE NAME of the person" <<endl;
    cin >> mn;
    cout << endl;
    cout << "Enter the LAST NAME of the person" <<endl;
    cin >> ln;
    cout << endl;
    cout << "Enter the BIRTH YEAR of the person" <<endl;
    cin >> by;
    cout << endl;
    return Person(fn, mn, ln, by);
}
void interface_index()
{
    IndexDictionary<string> *ind_dict;
    IndexDictionary<int> *ind_dict_INT;
    ArraySequence<Person> *seq = new ArraySequence<Person>();
    ofstream fout("out_index.txt");
    int choose = 0;
    int howManyPersons = 0;
    Person newPerson;
    string (Person::*getParam)() = NULL;
    int (Person::*getParamINT)() = NULL;
    int index_INT = 0;
    string index = "";

    cout << "DATA INDEXING" << endl;
    while(true)
    {
        cout << "Enter 1 to generate some random persons" << endl;
        cout << "Enter 2 to add a custom person" << endl;
        cout << "Enter 3 to index data" << endl;
        cout << "Enter a different number to quit" << endl;
        cin >> choose;
        cout << endl;

        switch (choose)
        {
            case 1:
                cout << "Enter how many persons to generate" << endl;
                cin >> howManyPersons;
                for (int i = 0; i < howManyPersons; i++)
                {
                    newPerson = Person(randomFN(), randomMN(), randomLN(), randomBY());
                    seq->append(newPerson);
                    cout << newPerson << endl;
                }
                cout << endl << howManyPersons << " persons have been generated" << endl << endl;
                break;
            case 2:
                seq->append(enterPerson());
                break;
            case 3:
                cout << "You need to choose a parameter to index data" << endl;
                cout << "1: INDEX = FIRST NAME" << endl;
                cout << "2: INDEX = MIDDLE NAME" << endl;
                cout << "3: INDEX = LAST NAME" << endl;
                cout << "4: INDEX = BIRTH YEAR" << endl;
                cout << "5: INDEX = FULL NAME" << endl;
                cout << "6: INDEX = FIO" << endl;
                cin >> choose;
                cout << endl;
                switch(choose)
                {
                    case 1:
                        getParam = Person::getFirstName;
                        break;
                    case 2:
                        getParam = Person::getMiddleName;
                        break;
                    case 3:
                        getParam = Person::getLastName;
                        break;
                    case 4:
                        getParamINT = Person::getBirthYear;
                        break;
                    case 5:
                        getParam = Person::getFullName;
                        break;
                    case 6:
                        getParam = Person::getFIO;
                        break;
                    default:
                        getParam = Person::getFirstName;
                        break;
                }

                if(getParam != NULL)
                {
                    ind_dict = new IndexDictionary<string>(*seq, getParam);
                } else ind_dict_INT = new IndexDictionary<int>(*seq, getParamINT);
                cout << "Indexed data:" << endl;
                if(getParam != NULL)
                {
                    ind_dict->print();
                } else ind_dict_INT->print();

                if(getParam != NULL)
                {
                    cout << "An amount of indexed persons: " << ind_dict->getCount() << endl;
                } else cout << "An amount of indexed persons: " << ind_dict_INT->getCount() << endl;

                cout << "To compare search speed enter an index" << endl;
                if(getParam != NULL)
                {
                    cin >> index;
                } else cin >> index_INT;
                cout << endl;
                if(getParam != NULL)
                {
                    getTimeSearchIndex(ind_dict, index);
                } else getTimeSearchIndex(ind_dict_INT, index_INT);
                cout << endl;

                break;
            default:
                fout.close();
                delete seq;
                delete ind_dict;
                return;
        }
    }
}

void interface()
{
    int choose = 0;

    cout << "Choose a task:" << endl;
    cout << "Enter 1 to test data indexing" << endl;
    cout << "Enter 2 to test" << endl;
    cout << "Enter 3 to test" << endl;
    cout << "Enter a different number to quit" << endl;
    cin >> choose;
    cout << endl;

    switch(choose)
    {
        case 1:
            interface_index();
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            return;
    }
}

int main(int argc, const char *argv[])
{
    srand(time(0));
    int choose = 0;
    interface();
	return 0;
}