#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace std;

int main()
{
    int a;
    std::cout << "Podaj a: ";
    std::cin >> a;

    int b;
    std::cout << "Podaj b: ";
    std::cin >> b;

    try {
        std::vector< int >               vec1(a, 0);
        std::variant< int, std::string > vec2;
        if (b % 2 == 0)
            vec2 = 42;
        else
            vec2 = "nieparzyste";

        std::cout << std::get< int >(vec2);
    }
    catch (std::bad_alloc const& ex) {
        std::cout << ex.what();
    }
    catch (std::bad_variant_access const& ex) {
        std::cout << ex.what() << "\nnieparzyste";
    }
}