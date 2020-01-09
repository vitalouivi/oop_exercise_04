#include <iostream>
#include <tuple>
#include <string>
#include <type_traits>
#include <vector>
#include "point.h"
#include "trapezoid.h"
#include "rectangle.h"
#include "rhombus.h"
#include "templates.h"

template<class T>
void running(std::istream& is, std::ostream& os) {
    if constexpr (is_figurelike_tuple<T>::value) {
        int ang;
        std::cout << "Input number of angles" << std::endl;
        std::cin >> ang;
        if (ang == 4) {
            point<double> A, B, C, D;
            is >> A >> B >> C >> D;
            auto object = std::make_tuple(A, B, C, D);
            print(os, object);
            os << area(object) << std::endl;
            os << center(object) << std::endl;
        }else if(ang == 3){
            point<double> A, B, C;
            is >> A >> B >> C;
            auto object = std::make_tuple(A, B, C);
            print(os, object);
            os << area(object) << std::endl;
            os << center(object) << std::endl;
        }
    }else {
        T object(is);
        print(os, object);
        os << '\n' << area(object) << std::endl;
        os << center(object) << std::endl;
    }
}
//additional classes
class Names {
public:
    std::string first;
    std::string last;
};

class WrongNames {
public:
    int first;
    int last;
};

int main() {
    char obj_type;
    std::cout << "Input figure type: 1 - trapezoid, 2 - rhombus, 3 - rectangle, 4 - tuple, 5 - to check additional task, or 'q' to quit" << std::endl;
    while (std::cin >> obj_type){
        if(obj_type == '4') {
            running<std::tuple<point<double>>> (std::cin, std::cout);
        }else if(obj_type == '1'){
	        running<trapezoid<double>>(std::cin, std::cout);
        }else if(obj_type == '2'){
	        running<rhombus<double>>(std::cin, std::cout);
        }else if(obj_type == '3'){
	        running<rectangle<double>>(std::cin, std::cout);
        }
        else if (obj_type == '5') {
            //additional task проверить являются ли поля класса first и last типа string
            std::cout << HasFL<Names>::value << std::endl;
            std::cout << HasFL<WrongNames>::value << std::endl;
            return 0;
        }
        else if(obj_type == 'q'){
	        return 0;
        }else{
	        std::cout << "Wrong. Try 1 - trapezoid, 2 - rhombus, 3 - rectangle, 4 - tuple or 'q' to quit" << std::endl;
        }
    }    
}
