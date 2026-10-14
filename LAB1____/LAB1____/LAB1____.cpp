//1,2,1
//#include <iostream>
//#include <thread>
//
//using namespace std;
//
//void Thread1()
//{
//    cout << "Thread1: 1" << endl;
//}
//
//void Thread2()
//{
//    cout << "Thread2: 2" << endl;
//}
//
//int main()
//{
//    thread t1(Thread1);
//    thread t2(Thread2);
//
//    cout << "Main thread finished." << endl;
//
//    return 0;
//}


//1,2,2

//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//void Thread1()
//{
//    cout << "Thread1: 1" << endl;
//}
//
//void Thread2()
//{
//    cout << "Thread2: 2" << endl;
//}
//
//int main()
//{
//    thread t1(Thread1);
//    thread t2(Thread2);
//
//    t1.detach();
//    t2.detach();
//
//    //даєм час щоб потоки відєднались
//    this_thread::sleep_for(chrono::milliseconds(100));
//
//    cout << "Main thread finished." << endl;
//
//    return 0;
//}

//1,2,3

//#include <iostream>
//#include <thread>
//#include <list>
//#include <windows.h>
//using namespace std;
//
//list<int> l;
//
//void AddToList(int value)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        int number = value + i;
//
//        l.push_back(number);
//
//        cout << "Added: " << number << endl;
//    }
//}
//
//void ListContains(int value)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        bool found = false;
//
//        for (int number : l)
//        {
//            if (number == value)
//            {
//                found = true;
//                break;
//            }
//        }
//
//        if (found)
//            cout << "Number " << value << " входить в список." << endl;
//        else
//            cout << "Number " << value << " не входить в список." << endl;
//    }
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int value = 10;
//
//    thread t1(AddToList, value);
//    thread t2(ListContains, value);
//
//    t1.join();
//    t2.join();
//
//    return 0;
//}

//1,2,4


//#include <iostream>
//#include <thread>
//#include <list>
//#include <mutex>
//#include <windows.h>
//using namespace std;
//
//list<int> l;
//mutex m;
//
//void AddToList(int value)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        int number = value + i;
//
//        m.lock();
//
//        l.push_back(number);
//
//        cout << "Added: " << number << endl;
//
//        m.unlock();
//    }
//}
//
//void ListContains(int value)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        m.lock();
//
//        bool found = false;
//
//        for (int number : l)
//        {
//            if (number == value)
//            {
//                found = true;
//                break;
//            }
//        }
//
//        if (found)
//            cout << "Number " << value << " входить в список." << endl;
//        else
//            cout << "Number " << value << " не входить в список." << endl;
//
//        m.unlock();
//    }
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int value = 10;
//
//    thread t1(AddToList, value);
//    thread t2(ListContains, value);
//
//    t1.join();
//    t2.join();
//
//    return 0;
//}

//1,2,5

//#include <iostream>
//#include <thread>
//#include <list>
//#include <mutex>
//#include <chrono>
//#include <windows.h>
//using namespace std;
//
//list<int> l;
//mutex m;
//
//void AddToList(int value)
//{
//    lock_guard<mutex> lock(m);
//
//    l.push_back(value);
//
//    cout << "Added: " << value << endl;
//}
//
//void ListContains(int value)
//{
//    lock_guard<mutex> lock(m);
//
//    bool found = false;
//
//    for (int number : l)
//    {
//        if (number == value)
//        {
//            found = true;
//            break;
//        }
//    }
//
//    if (found)
//        cout << "Number " << value << " входить в список." << endl;
//    else
//        cout << "Number " << value << " не входить в список." << endl;
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int startValue = 10;
//    int searchValue = 10;
//
//    for (int i = 0; i < 10; i++)
//    {
//        thread addThread(AddToList, startValue + i);
//        addThread.detach();
//
//        thread containsThread(ListContains, searchValue);
//        containsThread.detach();
//
//        this_thread::sleep_for(chrono::milliseconds(50));
//    }
//
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\nFinal list:" << endl;
//
//    for (int number : l)
//    {
//        cout << number << " ";
//    }
//
//    cout << endl;
//
//    return 0;
//}

//1,2,6


//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <string>
//
//using namespace std;
//
//class someData
//{
//public:
//    string name;
//    string surname;
//    string address;
//    int age;
//};
//
//class exchangePerson
//{
//private:
//    someData data;
//    mutex m;
//
//public:
//
//    exchangePerson(string name, string surname, string address, int age)
//    {
//        data.name = name;
//        data.surname = surname;
//        data.address = address;
//        data.age = age;
//    }
//
//    static void JohnDoe(exchangePerson& person)
//    {
//        lock_guard<mutex> lock(person.m);
//
//        person.data.name = "John";
//        person.data.surname = "Doe";
//        person.data.address = "Unknown";
//        person.data.age = 120;
//    }
//
//    static void JacobSmith(exchangePerson& person)
//    {
//        lock_guard<mutex> lock(person.m);
//
//        person.data.name = "Jacob";
//        person.data.surname = "Smith";
//        person.data.address = "Known";
//        person.data.age = 1;
//    }
//
//    static void Swap(exchangePerson& first, exchangePerson& second)
//    {
//        if (&first == &second)
//        {
//            cout << "Error: objects are the same!" << endl;
//            return;
//        }
//
//        // Захоплюємо обидва м'ютекси без deadlock
//        lock(first.m, second.m);
//
//        // М'ютекси вже захоплені, тому adopt_lock
//        lock_guard<mutex> lock1(first.m, adopt_lock);
//        lock_guard<mutex> lock2(second.m, adopt_lock);
//
//        swap(first.data.name, second.data.name);
//        swap(first.data.surname, second.data.surname);
//        swap(first.data.address, second.data.address);
//        swap(first.data.age, second.data.age);
//    }
//
//    void Print()
//    {
//        lock_guard<mutex> lock(m);
//
//        cout << "Name: " << data.name << endl;
//        cout << "Surname: " << data.surname << endl;
//        cout << "Address: " << data.address << endl;
//        cout << "Age: " << data.age << endl;
//    }
//};
//
//int main()
//{
//    exchangePerson person1("Person1", "Surname1", "Address1", 20);
//    exchangePerson person2("Person2", "Surname2", "Address2", 30);
//
//    // Встановлюємо John Doe
//    thread t1(exchangePerson::JohnDoe, ref(person1));
//
//    // Встановлюємо Jacob Smith
//    thread t2(exchangePerson::JacobSmith, ref(person2));
//
//    // Від'єднуємо потоки
//    t1.detach();
//    t2.detach();
//
//    // Даємо потокам час завершити роботу
//    this_thread::sleep_for(chrono::milliseconds(100));
//
//    cout << "BEFORE SWAP:" << endl;
//
//    cout << "\nPerson 1:" << endl;
//    person1.Print();
//
//    cout << "\nPerson 2:" << endl;
//    person2.Print();
//
//    // Запускаємо Swap в окремому потоці
//    thread swapThread(exchangePerson::Swap, ref(person1), ref(person2));
//
//    // Гарантуємо завершення Swap
//    swapThread.join();
//
//    cout << "\nAFTER SWAP:" << endl;
//
//    cout << "\nPerson 1:" << endl;
//    person1.Print();
//
//    cout << "\nPerson 2:" << endl;
//    person2.Print();
//
//    return 0;
//}

//1,2,7

#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

class someData
{
public:
    string name;
    string surname;
    string address;
    int age;
};

class exchangePerson
{
private:
    someData data;
    mutex m;

public:

    exchangePerson(string name, string surname, string address, int age)
    {
        data.name = name;
        data.surname = surname;
        data.address = address;
        data.age = age;
    }

    static void JohnDoe(exchangePerson& person)
    {
        lock_guard<mutex> lock(person.m);

        person.data.name = "John";
        person.data.surname = "Doe";
        person.data.address = "Unknown";
        person.data.age = 120;
    }

    static void JacobSmith(exchangePerson& person)
    {
        lock_guard<mutex> lock(person.m);

        person.data.name = "Jacob";
        person.data.surname = "Smith";
        person.data.address = "Known";
        person.data.age = 1;
    }

    static void Swap(exchangePerson& first, exchangePerson& second)
    {
        if (&first == &second)
        {
            cout << "Error: objects are the same!" << endl;
            return;
        }

        // Створюємо unique_lock, але поки не захоплюємо mutex
        unique_lock<mutex> lock1(first.m, defer_lock);
        unique_lock<mutex> lock2(second.m, defer_lock);

        // Одночасно безпечно захоплюємо обидва mutex
        lock(lock1, lock2);

        swap(first.data.name, second.data.name);
        swap(first.data.surname, second.data.surname);
        swap(first.data.address, second.data.address);
        swap(first.data.age, second.data.age);
    }

    void Print()
    {
        lock_guard<mutex> lock(m);

        cout << "Name: " << data.name << endl;
        cout << "Surname: " << data.surname << endl;
        cout << "Address: " << data.address << endl;
        cout << "Age: " << data.age << endl;
    }
};

int main()
{
    exchangePerson person1("Person1", "Surname1", "Address1", 20);
    exchangePerson person2("Person2", "Surname2", "Address2", 30);

    thread t1(exchangePerson::JohnDoe, ref(person1));
    thread t2(exchangePerson::JacobSmith, ref(person2));

    t1.detach();
    t2.detach();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "BEFORE SWAP:" << endl;

    cout << "\nPerson 1:" << endl;
    person1.Print();

    cout << "\nPerson 2:" << endl;
    person2.Print();

    thread swapThread(
        exchangePerson::Swap,
        ref(person1),
        ref(person2)
    );

    swapThread.join();

    cout << "\nAFTER SWAP:" << endl;

    cout << "\nPerson 1:" << endl;
    person1.Print();

    cout << "\nPerson 2:" << endl;
    person2.Print();

    return 0;
}