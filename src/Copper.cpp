#include "Copper.h"

double Copper::copperGap = 0;

/**
 * Copy object.
 * @param other The Copper object to be copied from. 
 */
void Copper::operator=(const Copper& other)
{
    this->lines_arcs = other.lines_arcs;
}