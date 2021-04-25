#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>

template<typename Iter1, typename Iter2>
Iter2 simple_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    while (f1 != e1) {
        *f2 = *f1;
        f1++;
        f2++;
    }
    return f2;
}

template<typename Iter, typename T>
void print(Iter f, Iter e, const T& name) {
    std::cout << name << " contains: { ";
    while (f != e) {
        std::cout << *f << " ";
        f++;
    }
        std::cout << " } " << std::endl;
}

int main()
{
    const int arr_size = 10;
    std::array<int, arr_size> arr= { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    /*
    print(arr.begin(), arr.end(), "arr");
    print(vec.begin(), vec.end(), "vec");
    print(lst.begin(), lst.end(), "lst");
    */

    std::array<int, arr_size> arr_copy = arr;
    std::vector<int> vec_copy = vec;
    std::list<int> lst_copy = lst;

    /*
    print(arr.begin(), arr.end(), "arr_copy");
    print(vec.begin(), vec.end(), "vec_copy");
    print(lst.begin(), lst.end(), "lst_copy");
    */

    for (std::array<int, arr_size>::iterator p = arr.begin(); p != arr.end(); p++)
        *p += 2;

    for (std::vector<int>::iterator p = vec.begin(); p != vec.end(); p++)
        *p += 3;

    for (std::list<int>::iterator p = lst.begin(); p != lst.end(); p++)
        *p += 5;

    std::cout << "Before copy: " << std::endl;
    print(arr.begin(), arr.end(),"arr");
    print(vec.begin(), vec.end(),"vec");
    print(lst.begin(), lst.end(),"lst");

    simple_copy(arr.begin(), arr.end(), vec.begin());
    simple_copy(lst.begin(), lst.end(), arr.begin());

    std::cout << "After copy: " << std::endl;
    print(arr.begin(), arr.end(), "arr");
    print(vec.begin(), vec.end(), "vec");
    print(lst.begin(), lst.end(), "lst");

    std::vector<int>::iterator vector_it = find(vec.begin(), vec.end(), 3);
    if (vector_it != vec.end())
        std::cout << "3 was found at index: " << vector_it - vec.begin() << std::endl;

    std::list<int>::iterator list_it = find(lst.begin(), lst.end(), 27);
    if (list_it != lst.end()) {
        //std::cout << "27 was found at index: " << list_it - lst.begin() << std::endl;
        int index = 0;
        for (std::list<int>::iterator it = lst.begin(); it != list_it; it++)
            index++;
        std::cout << "27 was found at index: " << index << std::endl;
    }
    else
        std::cout << "27 was not found in the list!" << std::endl;
}