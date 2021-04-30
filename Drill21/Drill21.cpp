#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>

template<typename Iter>
void print(Iter f, Iter e) {
    while (f != e) {
        std::cout << *f << " ";
        f++;
    }
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T,U>& p)
{
    return os << p.first << " " << p.second << std::endl;
}

template<typename T>
struct Map_sum {
    T operator()(T v, const std::pair<std::string, T>& p)
    {
        return v + p.second;
    }
};

struct Item {
    std::string name;
    int iid;
    double value;
    Item() :name(), iid(0), value(0) {}
    Item(std::string n, int i, double v) : name(n), iid(i), value(v) {}
};

void read_pair(std::map<std::string, int>& msi)
{
    std::string s;
    int i;
    std::cin >> s >> i;
    msi[s] = i;
}

std::istream& operator>>(std::istream& is, Item& it)
{
    std::string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    it = Item(name, iid, value);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Item& it)
{
    return os << "Name: " << it.name << " iid: " << it.iid << " Value: " << it.value << std::endl;
}

struct Compare_by_name {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.name < b.name;
    }
};

struct Compare_by_iid {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.iid < b.iid;
    }
};

struct Find_by_name
{
    std::string name;
    Find_by_name(const std::string& s) : name(s) {}
    bool operator()(const Item& it) const 
    {
        return it.name == name;
    }
};

struct Find_by_iid
{
    int iid;
    Find_by_iid(const int& i) : iid(i) {}
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

int main()
{
    std::vector<Item> vi;
    std::list<Item> li;
    Item i;
    const std::string filename = "items.txt";

    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
        std::cout << "Couldn't open file" << std::endl;

    while (ifs >> i)
    {
        vi.push_back(i);
        li.push_back(i);
    }
    print(vi.begin(), vi.end());
    //print(li.begin(), li.end());

    //1.2
    std::cout << "\nSort by name:" << std::endl;
    std::sort(vi.begin(), vi.end(), Compare_by_name());
    print(vi.begin(), vi.end());

    /* list
    std::cout << "\nSort by name:" << std::endl;
    std::sort(li.begin(), li.end(), Compare_by_name());
    print(li.begin(), li.end());
    */

    //1.3
    std::cout << "\nSort by iid:" << std::endl;
    std::sort(vi.begin(), vi.end(), Compare_by_iid());
    print(vi.begin(), vi.end());

    /* list
    std::cout << "\nSort by iid:" << std::endl;
    std::sort(li.begin(), li.end(), Compare_by_iid());
    print(li.begin(), li.end());
    */

    //1.4
    std::cout << "\nSort by value:" << std::endl;
    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) {return a.value > b.value; });
    print(vi.begin(), vi.end());

    /* list
    std::cout << "\nSort by value:" << std::endl;
    std::sort(li.begin(), li.end(), [](const Item& a, const Item& b) {return a.value > b.value; });
    print(li.begin(), li.end());
    */

    //1.5
    std::cout << "\nInserting 2 items: " << std::endl;
    vi.insert(vi.end(), Item("horse shoe", 99, 12.34));
    vi.insert(vi.end(), Item("Canon S400", 9988, 499.95));
    print(vi.begin(), vi.end());

    /* list
    std::cout << "\nInserting 2 items: " << std::endl;
    li.insert(li.end(), Item("horse shoe", 99, 12.34));
    li.insert(li.end(), Item("Canon S400", 9988, 499.95));
    print(li.begin(), li.end());
    */

    //1.6
    std::string rname1 = "vase";
    std::string rname2 = "banana";
    std::cout << "\nRemoving 2 items by name: " << rname1 << " and " << rname2 << std::endl;
    std::vector<Item>::iterator v_it = find_if(vi.begin(), vi.end(), Find_by_name(rname1));
    vi.erase(v_it);
    v_it = find_if(vi.begin(), vi.end(), Find_by_name(rname2));
    vi.erase(v_it);
    print(vi.begin(), vi.end());

    /* list
    std::string rname1 = "vase";
    std::string rname2 = "banana";
    std::cout << "\nRemoving 2 items by name: " << rname1 << " and " << rname2 << std::endl;
    std::list<Item>::iterator l_it = find_if(li.begin(), li.end(), Find_by_name(rname1));
    li.erase(l_it);
    l_it = find_if(li.begin(), li.end(), Find_by_name(rname2));
    li.erase(l_it);
    print(li.begin(), li.end());
    */

    //1.7
    int riid1 = 106;
    int riid2 = 23;
    std::cout << "\nRemoving 2 items by iid: " << riid1 << " and " << riid2 << std::endl;
    v_it = find_if(vi.begin(), vi.end(), Find_by_iid(riid1));
    vi.erase(v_it);
    v_it = find_if(vi.begin(), vi.end(), Find_by_iid(riid2));
    vi.erase(v_it);
    print(vi.begin(), vi.end());

    /* list
    int riid1 = 106;
    int riid2 = 23;
    std::cout << "\nRemoving 2 items by iid: " << riid1 << " and " << riid2 << std::endl;
    l_it = find_if(li.begin(), li.end(), Find_by_iid(riid1));
    li.erase(l_it);
    l_it = find_if(li.begin(), li.end(), Find_by_iid(riid2));
    li.erase(l_it);
    print(li.begin(), li.end());
    */

    //2.1
    std::map<std::string, int> msi;

    //2.2
    msi["shampoo"] = 11;
    msi["speaker"] = 91;
    msi["glass"] = 512;
    msi["hairbrush"] = 4;
    msi["bed"] = 129;
    msi["towel"] = 92;
    msi["fork"] = 2635;
    msi["clock"] = 42;
    msi["lamp"] = 9;
    msi["pencil"] = 8263;

    //2.3
    std::cout << "\nContents of msi: " << std::endl;
    print(msi.begin(), msi.end());

    //2.4
    std::map<std::string, int>::iterator p = msi.begin();
    while (p != msi.end())
        p = msi.erase(p);

    std::cout << "\nContents of msi after erasing: " << std::endl;
    print(msi.begin(), msi.end());

    //2.6
    std::cout << "Enter 10 string int pairs: " << std::endl;
    for (int i = 0; i < 10; ++i)
        read_pair(msi);

    //2.7
    std::cout << "\nContents of msi after manually entering pairs: " << std::endl;
    print(msi.begin(), msi.end());

    //2.8
    int sum = 0;
    sum = std::accumulate(msi.begin(), msi.end(), sum, Map_sum<int>());
    std::cout << "The sum is: " << sum << std::endl;

    //2.9
    std::map<int, std::string> mis;

    //2.10
    for (p = msi.begin(); p != msi.end(); ++p)
        mis[p->second] = p->first;

    //2.11
    std::cout << "\nContents of mis: " << std::endl;
    print(mis.begin(), mis.end());

    //3.1
    std::vector<double> vd;
    double d;
    std::string filename2 = "floats.txt";
    std::ifstream ifs2(filename2.c_str());

    if (!ifs2.is_open())
        std::cout << "Couldn't open file!" << std::endl;

    while (ifs2 >> d)
        vd.push_back(d);

    //3.2
    std::cout << "\nContents of vd: " << std::endl;
    print(vd.begin(), vd.end());
    std::cout << std::endl;

    //3.3
    std::vector<int> vint(vd.size());
    copy(vd.begin(), vd.end(), vint.begin());

    //3.4
    std::cout << "Printing the two vectors as pairs: " << std::endl;
    for (int i = 0; i < vd.size(); ++i)
        std::cout << "(" << vd[i] << "," << vint[i] << ")" << std::endl;

    //3.5
    double vd_sum = 0;
    for (std::vector<double>::iterator p = vd.begin(); p != vd.end(); ++p)
        vd_sum += *p;
    std::cout << "The sum of the elements of vd is: " << vd_sum << std::endl;

    //3.6
    int vint_sum = 0;
    for (std::vector<int>::iterator p = vint.begin(); p != vint.end(); ++p)
        vint_sum += *p;
    std::cout << "The sum of the elements of vint is: " << vint_sum << std::endl;

    double sum_diff = vd_sum - vint_sum;
    std::cout << "The difference between the sum of the elements of vd and the sum of the elements of vint is: " << sum_diff << std::endl;

    //3.7
    std::cout << "Vd: " << std::endl;
    print(vd.begin(), vd.end());
    std::cout << std::endl;

    reverse(vd.begin(), vd.end());
    std::cout << "Vd reversed: " << std::endl;
    print(vd.begin(), vd.end());
    std::cout << std::endl;

    return 0;
}
