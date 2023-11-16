#include <iostream>
#include "map_generator.h"
#include <fstream>
/*
https://gamedev.ru/code/articles/levelgen1
*/

#include "test_svg.h"

int main() {
    std::ofstream file("test.svg");
    if (file.is_open())
    {
        testRooms(file);
    }
    file.close();

    return 0;
}
