#include "std_lib_facilities.h"

class B {
	virtual void pvf() = 0;
};

class B1 {
public:
	virtual void vf() const { cout << "B1:vf()" << endl; }
	void f() const { cout << "B1:f()" << endl; }
	void pvf() const { cout << "B1:pvf()" << endl; }
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:
	void vf() const override { cout << "D1:vf()" << endl; }
	void f() const { cout << "D1:f()" << endl; }
	void pvf() const { cout << "D1:pvf()" << endl; }
};

class D21 : public B2 {
public:
	void pvf() { cout << "The value of the string is: " << text << endl; }
private:
	string text = "abc";
};

class D22 : public B2 {
public:
	void pvf() { cout << "The value of the int is: " << num << endl; }
private:
	int num = 55;
};

void call (const B1& bref){
	bref.vf();
	bref.f();
	bref.pvf();
}

void f (B2& b2ref){
	b2ref.pvf();
}

class D2 : public D1 {
public:
	void pvf() const { cout << "D2:pvf()" << endl; }
};

int main()
{
	B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	call (d1);

	b1.pvf();
	d1.pvf();

	// 6.
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	// 7.
	D21 d21;
	d21.pvf();
	D22 d22;

	f(d21);
	f(d22);
	
}