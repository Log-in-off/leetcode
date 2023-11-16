#include <vector>

class Map {
public:
    struct Room {
        int x, y, w, h;
        bool intersect(const Room &r) const;
    };
    
    Map(int width, int height): width_(width), height_(height) {
        data_.resize(width * height, 0);
    }
    void generate(int roomsCount);
    std::vector<Room>::iterator beginRooms();
    std::vector<Room>::iterator endRooms();
private:
    int width_, height_;     // dimensions of the map 
    std::vector<int> data_;   // final dates of the room
    std::vector<Room> rooms_;
};