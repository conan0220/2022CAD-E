#include "Assembly.h"
#include <variant>
#include <vector>

double Assembly::GAP = 0;

/**
 * Copy object.
 * @param other The Assembly object to be copied from. 
 */
void Assembly::operator=(const Assembly& other) {
    this->lines_arcs = other.lines_arcs;
}
