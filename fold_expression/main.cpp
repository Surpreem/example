#include <iostream>
#include <vector>


template <typename... Ts>
auto left_fold_mod(Ts... ts)
{
    return (... % ts);
}

template <typename... Ts>
auto right_fold_mod(Ts... ts)
{
    return (ts % ...);
}

template <typename T>
auto dummy(T val)
{
    return val;
}

template <typename T>
auto dummy_print(T val)
{
    std::cout << val << ", ";
    return val;
}

template <typename... Ts>
auto left_fold_mod2(Ts... ts)
{
    return (... % dummy(ts));
}

template <typename... Ts>
auto right_fold_mod2(Ts... ts)
{
    return (dummy(ts) % ...);
}

template <typename T, typename... Ts>
void left_fold_push_back(std::vector<T>& v, Ts... ts)
{
    (..., v.push_back(ts));
}

template <typename T, typename... Ts>
void right_fold_push_back(std::vector<T>& v, Ts... ts)
{
    (v.push_back(ts), ...);
}

template <typename T>
void print_vector(std::vector<T> const& v)
{
    for (auto e : v)
        std::cout << e << ", ";
    std::cout << '\n';
}

int main()
{
    auto f1{((100 % 7) % 3)};
    auto f2{(100 % (7 % 3))};

    std::cout
        << "left fold(manual): "
        << f1
        << ", right fold(manual): "
        << f2
        << '\n';

    std::cout
        << "left fold(mod1): "
        << left_fold_mod(100, 7, 3)
        << ", right fold(mod1): "
        << right_fold_mod(100, 7, 3)
        << '\n';

    std::cout
        << "left fold(mod2): "
        << left_fold_mod2(100, 7, 3)
        << ", right fold(mod2): "
        << right_fold_mod2(100, 7, 3)
        << '\n';


    std::vector<int> v1;
    ((v1.push_back(1), v1.push_back(2)), v1.push_back(3));
    std::cout << "left fold(v1): ";
    print_vector(v1);

    std::vector<int> v2;
    (v2.push_back(1), (v2.push_back(2), v2.push_back(3)));
    std::cout << "right fold(v2): ";
    print_vector(v2);

    std::vector<int> v3;
    left_fold_push_back(v3, 1, 2, 3);
    std::cout << "left fold(v3): ";
    print_vector(v3);

    std::vector<int> v4;
    right_fold_push_back(v4, 1, 2, 3);
    std::cout << "right fold(v4): ";
    print_vector(v3);

    std::cout << "left fold(comma): ";
    ((dummy_print(1), dummy_print(2)), dummy_print(3));
    std::cout << '\n';

    std::cout << "right fold(comma): ";
    (dummy_print(1), (dummy_print(2), dummy_print(3)));
    std::cout << '\n';

    std::cout << "left fold(&&): ";
    ((dummy_print(0) && dummy_print(2)) && dummy_print(3));
    std::cout << '\n';

    std::cout << "right fold(&&): ";
    (dummy_print(1) && (dummy_print(0) && dummy_print(3)));
    std::cout << '\n';

    return 0;
}
