//Калугин Кирилл М8О-207Б-19
//Разработать шаблоны классов согласно варианту задания.  Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат. 
//Классы должны иметь только публичные поля. В классах не должно быть методов, только поля.
//Фигуры являются фигурами вращения (равнобедренными), за исключением трапеции и прямоугольника. Для хранения координат фигур необходимо использовать шаблон  std::pair.
//Необходимо реализовать две шаблонных функции:
//1.Функция print печати фигур на экран std::cout  (печататься должны координаты вершин фигур).
//      Функция должна принимать на вход std::tuple с фигурами, согласно варианту задания (минимум по одной каждого класса).
//2.Функция square вычисления суммарной площади фигур. Функция должна принимать на вход std::tuple с фигурами, согласно варианту задания (минимум по одной каждого класса).
//Создать программу, которая позволяет:
//• Создает набор фигур согласно варианту задания (как минимум по одной фигуре каждого типа с координатами типа int и координатами типа double).
//• Сохраняет фигуры в std::tuple
//• Печатает на экран содержимое std::tuple с помощью шаблонной функции print.
//• Вычисляет суммарную площадь фигур в std::tuple и выводит значение на экран.

//Используемые фигуры: пяти-, шести- и восьмиугольник.

#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

template <typename T>//шаблон класса пятиугольника
class five {
	public:
		using type = T;
		pair <T, T> O;
		T R;
	    five (T x, T y, T r): O (x, y), R (r) {};
};

template <typename T>//шаблон класса шестиугольника
class six {
	public:
		using type = T;
		pair <T, T> O;
		T R;
	    six (T x, T y, T r): O (x, y), R (r) {};
};

template <typename T>//шаблон класса восьмиугольника
class eight {
	public:
		using type = T;
		pair <T, T> O;
		T R;
	    eight (T x, T y, T r): O (x, y), R (r) {};
};

template <int i = 0, class... Ts>//шаблон функции вывода вершин фигур
void points1 (tuple <Ts ...> t){
	if constexpr (i < tuple_size <decltype(t)> ::value) {
    		points2(get <i> (t));
    		cout << "-----------------------"<< endl;
    		points1 < i + 1, Ts ... > (t);
	}
}
 
template <int i = 0, class... Ts>//шаблон функции вывода общей площади
void s1 (tuple <Ts ...> t, double S){
	if constexpr (i < tuple_size <decltype(t)> ::value) {
    		S += s2 (get <i> (t));
    		s1 < i + 1, Ts ... > (t, S);
	}
		else {
		    cout << "Общая площадь фигур - " << S << endl;
	    }
}

template <typename T>//шаблон функции поиска площади пятиугольника
T s2 (five <T> x) {
    return (2.5 * pow (x.R, 2) * sin (72.0 / 180.0 * PI));
}

template <typename T>//шаблон функции поиска площади шестиугольника
T s2 (six <T> x) {
    return (1.5 * sqrt (3) * pow (x.R, 2));
}

template <typename T>//шаблон функции поиска площади восьмиугольника
T s2 (eight <T> x) {
    return (4 * pow (x.R, 2) * sin (PI / 4));
}

template <typename T>//шаблон функции поиска вершин пятиугольника
void points2 (five <T> x) {
    cout << "\nA = (" << (x.O).first << "," << (x.O).second + x.R << ")\n" << "B = (" 
         << (x.O).first + x.R * cos (28.0 / 180.0 * PI) << "," << (x.O).second + x.R * sin (28.0  / 180.0 * PI) 
         << ")\n" << "C = (" << (x.O).first + x.R * cos (- 44.0  / 180.0 * PI) << "," 
         << (x.O).second + x.R * sin (- 44.0  / 180.0 * PI) << ")\n" << "D = (" 
         << (x.O).first + x.R * cos (- 116.0  / 180.0 * PI) << "," << (x.O).second + x.R * sin (- 116.0  / 180.0 * PI) 
         << ")\n" << "E = (" << (x.O).first + x.R * cos (- 188.0  / 180.0 * PI) 
         << "," << (x.O).second + x.R * sin (- 188.0  / 180.0 * PI) << ")\n";
}

template <typename T>//шаблон функции поиска вершин шестиугольника
void points2 (six <T> x) {
    cout << "\nA = (" << (x.O).first << "," << (x.O).second + x.R << ")\n" << "B = (" 
         << (x.O).first + x.R * cos (PI / 6.0) << "," << (x.O).second + x.R * sin (PI / 6.0) 
         << ")\n" << "C = (" << (x.O).first + x.R * cos (- PI / 6.0) << "," 
         << (x.O).second + x.R * sin (- PI / 6.0) << ")\n" << "D = (" << (x.O).first << "," 
         << (x.O).second - x.R << ")\n" << "E = (" << (x.O).first + x.R * cos (- 5.0 * PI / 6.0) 
         << "," << (x.O).second + x.R * sin (- 5.0 * PI / 6.0) << ")\n" << "F = (" 
         << (x.O).first + x.R * cos (- 7.0 * PI / 6.0) << "," 
         << (x.O).second + x.R * sin (- 7.0 * PI / 6.0) << ")\n";
}

template <typename T>//шаблон функции поиска вершин восьмиугольника
void points2 (eight <T> x) {
    cout << "\nA = (" << (x.O).first << "," << (x.O).second + x.R << ")\n" << "B = (" 
         << (x.O).first + x.R * cos (PI / 4) << "," << (x.O).second + x.R * sin (PI / 4) 
         << ")\n" << "C = (" << (x.O).first + x.R << "," << (x.O).second << ")\n" 
         << "D = (" << (x.O).first + x.R * cos (- PI / 4) << "," << (x.O).second + x.R * sin (- PI / 4) 
         << ")\n" << "E = (" << (x.O).first << "," << (x.O).second - x.R << ")\n" 
         << "F = (" << (x.O).first + x.R * cos (- 3 * PI / 4) << "," << (x.O).second + x.R * sin (- 3 * PI / 4) 
         << ")\n" << "G = (" << (x.O).first - x.R << "," << (x.O).second << ")\n" << "H = (" 
         << (x.O).first + x.R * cos (- 5 * PI / 4) << "," << (x.O).second + x.R * sin (- 5 * PI / 4) << ") \n";
}

int main()
{
    five <int> f1 (0, 0, 6);//создание пятиугольника с заданными параметрами
    five <double> f2 (1.0, 1.0, 2.12);//создание пятиугольника с заданными параметрами
    six <int> si1 (0, 0, 8);//создание шестиугольника с заданными параметрами
    six <double> si2 (1.0, 1.0, 9.41);//создание шестиугольника с заданными параметрами
    eight <int> e1 (0, 0, 3);//создание восьмиугольника с заданными параметрами
    eight <double> e2 (1.0, 1.0, 5.05);//создание восьмиугольника с заданными параметрами


    tuple <five <int>, five <double>, six <int>, six <double>, eight <int>, eight <double> > t {f1, f2, si1, si2, e1, e2};//создание tuple'а фигур
    
    points1 (t);//вызов функции вывода вершин
	s1 (t, 0);///вызов функции подсчета общей площади 
    return 0;
}


