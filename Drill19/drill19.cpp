#include <iostream>
#include <vector>

using namespace std;

template<class T> struct S {
public:
	S(T value) : val(value) {}
	const T& get() const;
	T& get();
	void set(T setval);
	void operator=(const T&);
private:
	T val;
};

template<class T> const T& S<T>::get() const { return val; }

template<class T> T& S<T>::get() { return val; }

template<class T> void S<T>::set(T setval) { val = setval; }

template<class T> void S<T>::operator=(const T& x) {
	val = x;
}

template<class T> istream& operator>>(istream& is, S<T>& ss)
{
	T val;
	cin >> val;
	ss = val;
	return is;
}
template<class T> void read_val(T& v) { cin >> v; }

int main()
{
	S<int> s_int(3);
	s_int = 5;
	S<char> s_char('x');
	S<double> s_double(2.5);
	S<string> s_string("string"); 
	vector<int> int_vector;
	for (int i=0;i<10;i++)
		int_vector.push_back(i);
	S<vector<int>> s_vector(int_vector);


/* 4.
	cout << s_int.val << endl;
	cout << s_char.val << endl;
	cout << s_double.val << endl;
	cout << s_string.val << endl;
	for (int i=0; i <s_vector.val.size(); i++)
		cout << s_vector.val[i] << endl;
*/
	cout << s_int.get() << endl;
	cout << s_char.get() << endl;
	cout << s_double.get() << endl;
	cout << s_string.get() << endl;
	for (int i=0; i <s_vector.get().size(); i++)
		cout << s_vector.get()[i] << endl;

//	13.
	cout << "Give me an integer: ";
	read_val(s_int);
	cout << "The integer is: " << s_int.get() << endl;

	cout << "Give me a char: ";
	read_val(s_char);
	cout << "The char is: " << s_char.get() << endl;

	cout << "Give me a double: ";
	read_val(s_double);
	cout << "The double is: " << s_double.get() << endl;

	cout << "Give me a string: ";
	read_val(s_string);
	cout << "The string is: " << s_string.get() << endl;

	return 0;
}