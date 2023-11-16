#include "map_generator.h"

#include <algorithm>

bool Map::Room::intersect(const Room &r) const {
    return !(r.x >= (x + w) || x >= (r.x + r.w) || r.y >= (y + h) || y >= (r.y + r.h));
}

std::vector<Map::Room>::iterator Map::beginRooms()
{
    return rooms_.begin();
}
std::vector<Map::Room>::iterator Map::endRooms()
{
    return rooms_.end();    
}

void Map::generate(int roomsCount) {
    rooms_.clear();
    
    // второй цикл предотвращает залипание, в случае если на карту уже не помещается ни одной комнаты
    for (int i = 0; i < roomsCount; ++i) for (int j = 0; j < 1000; ++j) {
        // ширина и высота комнаты в пределах [10,40]
        const int w = 10 + rand() % 31, h = 10 + rand() % 31;
        // избегаем "прилипания" комнаты к краю карты
        const Room room = {3 + rand() % (width_ - w - 6), 3 + rand() % (height_ - h - 6), w, h};
        
        // найдем первую комнату, из уже существующих, которая пересекается с новой
        auto intersect = std::find_if(std::begin(rooms_), std::end(rooms_), [&room](const Room &r){
            return room.intersect(r);
        });
        
        // если новая комната не имеет пересечений - добавляем ее
        if (intersect == std::end(rooms_)) {
            rooms_.push_back(room);
            break;
        }
    }
}