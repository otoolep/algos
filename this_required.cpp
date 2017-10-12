#include <iostream>

class Foo {
public:
	Foo() {
		bar = 42;
	};
	~Foo() {};

	void Bar() {
		std::cout << bar << std::endl;
		std::cout << this->bar << std::endl;
	}
private:
	int bar;
};

int main() {
	Foo f = Foo();
	f.Bar();
	return 0;
}