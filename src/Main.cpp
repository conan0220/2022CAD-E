/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-10 18:32:35
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-14 23:39:28
 * @FilePath: /2022CAD-E/src/Main.cpp
 * @Description: 2022 ICCAD Problem E
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *                               神兽保佑            永无BUG
 */

// #include "Application.h"

// int main()
// {
//     Application app;
//     std::cin.get();
// }

#include "Application.h"

// int main()
// {
//     std::cout << bg::extra::getAngle(1, 1, 1) << std::endl;    // 45
//     std::cout << bg::extra::getAngle(Point2D(1, 1), Point2D(1, 0), 0) << std::endl; // 4.71
//     std::cout << bg::extra::getAngle(Point2D(1, 1), Point2D(1, 0), 1) << std::endl; // 270   
// }
int main()
{
    // Create an Arc object
    Point2D begin(0, 0);
    Point2D end(1, 1);
    Point2D center(0.5, 0.5);
    bool clockWise = true;
    Arc arc(begin, end, center, clockWise);

    // Test the getPositionOnArc() function
    double angle_t = 180; // 180 degrees
    int mode = 1; // Input angle is in radians
    std::vector<double> position = arc.getPositionOnArc(angle_t, mode);

    // Print the result
    std::cout << "The position on the arc at an angle of " << angle_t << " is (" << position[0] << ", " << position[1] << ")" << std::endl;

}


