#include "Application.h"

int main() {
    Application app;
}

// #include <iostream>
// #include <symengine/expression.h>
// #include <symengine/symbol.h>
// #include <symengine/solve.h>

// using namespace SymEngine;

// int main() {
//     RCP<const Symbol> x = symbol("x");
//     RCP<const Basic> equation = add(add(pow(x, integer(2)), mul(x, integer(3))), integer(2));
//     RCP<const Set> solutions = solve(equation, x);
//     std::cout << solutions->get_args().size() << std::endl;     // size
//     std::cout << solutions->get_args() << std::endl;            // all datas
//     std::cout << *solutions->get_args()[0] << std::endl;        // data1
//     std::cout << *solutions->get_args()[1] << std::endl;        // data2
// }
