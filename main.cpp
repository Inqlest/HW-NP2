#include <iostream>

class Figure {
protected:
	std::string name;
	int sides_count;
	int a, b, c, d;
	int A, B, C, D;
	Figure(std::string name, int sides_count, int a, int b, int c, int d, int A, int B, int C, int D){
		this->name = name;
		this->sides_count = sides_count;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
public:
	Figure() : Figure("Фигура", 0, 0, 0, 0, 0, 0, 0, 0, 0){}
	int get_a() { return a; } int get_b() { return b; } int get_c() { return c; } int get_d() { return d; }
	int get_A() { return A; } int get_B() { return B; } int get_C() { return C; } int get_D() { return D; }
	std::string get_name() { return name; }
	int get_sides_count() { return sides_count; }

	virtual bool chek() {
		if (get_sides_count() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual void print_info(Figure* figure) {
		std::cout << name << ":" << std::endl;
		if (chek() == true) { std::cout << "Правильно" << std::endl; } else { std::cout << "Неправильно" << std::endl; }
		std::cout << get_sides_count() << std::endl;
	}
	
};

class Triangle : public Figure {
protected:
	Triangle(std::string name, int a, int b, int c, int A, int B, int C): Figure(name, 3, a, b, c, d, A, B, C, D){}
public:
	Triangle(int a, int b, int c, int A, int B, int C) : Triangle("Труегольник", a, b, c, A, B, C){}
	
	bool chek() override{
		if (get_sides_count() == 3 && A + B + C == 180) {
			return true;
		}
		else {
			return false;
		}
	}
	void print_info(Figure* figure) override {
		std::cout << figure->get_name() << ": " << std::endl;
		if (chek() == true) { std::cout << "Правильно" << std::endl; } else { std::cout << "Неправильно" << std::endl; }
		std::cout << "Количество сторон: " << get_sides_count() << std::endl
		<< "Стороны: " << "a = " << figure->get_a() << " b = " << figure->get_b() << " c = " << figure->get_c() << std::endl
		<< "Углы: " << " A = " << figure->get_A() << " B = " << figure->get_B() << " C = " << figure->get_C() << std::endl << std::endl;
	}
};

class Right : public Triangle {
public:
	Right(int a, int b, int c, int A, int B) : Triangle("Прямоугольный треугольник", a, b, c, A, B, 90){}

	bool chek() override {
		if (C == 90 && Triangle::chek() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Isosceles : public Triangle {
public:
	Isosceles(int a, int b, int A, int B) : Triangle("Равнобедренный треугольник", a, b, a, A, B, A) {}
	bool chek() override {
		if (a == c && Triangle::chek() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Equilateral : public Triangle {
public:
	Equilateral(int a) : Triangle("Равносторонний треугольник", a, a, a, 60, 60, 60) {}
	bool chek() override {
		if (a == b == c && A == B == C == 60 && Triangle::chek() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Quadrangle : public Figure {
protected:
	Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D): Figure(name, 4, a, b, c, d, A, B, C, D) {}
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle("Четырехугольник", a, b, c, d, A, B, C, D){}
	void print_info(Figure* figure) override {
		std::cout << figure->get_name() << ": " << std::endl;
		if (chek() == true) { std::cout << "Правильно" << std::endl; } else { std::cout << "Неправильно" << std::endl; }
		std::cout << "Количество сторон: " << get_sides_count() << std::endl
		<< "Стороны: " << "a = " << figure->get_a() << " b = " << figure->get_b() << " c = " << figure->get_c() << " d = " << figure->get_d() << std::endl
		<< "Углы: " << " A = " << figure->get_A() << " B = " << figure->get_B() << " C = " << figure->get_C() << " D = " << figure->get_D() << std::endl << std::endl;
	}
	bool chek() override {
		if (sides_count == 4 && A + B + C + D == 360) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Rectangle : public Quadrangle {
public:
	Rectangle(int a, int b) : Quadrangle("Прямоугольник", a, b, a, b, 90, 90, 90, 90){}
	bool chek() override {
		if (a == c && b == d && A == B == C == D == 90 && Quadrangle::chek() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Square : public Quadrangle {
public:
	Square(int a) : Quadrangle("Квадрат", a, a, a, a, 90, 90, 90, 90){}
	bool chek() override {
		if (a == b == c == d && Quadrangle::chek() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle("Параллелограмм", a, b, a, b, A, B, A, B) {}
	bool chek() override {
		if (a == c && b == d && A == C && B == D && Quadrangle::chek() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Romb : public Quadrangle {
public:
	Romb(int a, int A, int B) : Quadrangle("Ромб", a, a, a, a, A, B, A, B) {}
	bool chek() override {
		if (a == b == c == d && Quadrangle::chek() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Figure* figure = new Figure;
	figure->print_info(figure);
	Figure* triangle = new Triangle(10, 20, 30, 50, 60, 70);
	triangle->print_info(triangle);
	Figure* right = new Right(10, 20, 30, 50, 60);
	right->print_info(right);
	Figure* isosceles = new Isosceles(10, 30, 50, 60);
	isosceles->print_info(isosceles);
	Figure* equilateral = new Equilateral(30);
	equilateral->print_info(equilateral);

	Figure* quadrangle = new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	quadrangle->print_info(quadrangle);
	Figure* rectangle = new Rectangle(10, 20);
	rectangle->print_info(rectangle);
	Figure* square = new Square(20);
	square->print_info(square);
	Figure* parallelogramm = new Parallelogram(20, 30, 30, 40);
	parallelogramm->print_info(parallelogramm);
	Figure* romb = new Romb(30, 30, 40);
	romb->print_info(romb);



	delete triangle;
	delete right;
	delete isosceles;
	delete equilateral;
	delete quadrangle;
	delete rectangle;
	delete square;
	delete parallelogramm;
	delete romb;
}