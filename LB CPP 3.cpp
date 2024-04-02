#include <iostream> 
#include <algorithm> 



class Rectangle {
private:
    float x, y;
    float width, height;
public:
    Rectangle(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) {}

    void move(float dx, float dy) {
        x += dx;
        y += dy;
    }

    void resize(float new_width, float new_height) {
        width = new_width;
        height = new_height;
    }

    static Rectangle minimumBoundingRectangle(const Rectangle& rect1, const Rectangle& rect2) {
        float min_x = std::min(rect1.x, rect2.x);
        float min_y = std::min(rect1.y, rect2.y);
        float max_x = std::max(rect1.x + rect1.width, rect2.x + rect2.width);
        float max_y = std::max(rect1.y + rect1.height, rect2.y + rect2.height);

        return Rectangle(min_x, min_y, max_x - min_x, max_y - min_y);
    }

    static Rectangle intersection(const Rectangle& rect1, const Rectangle& rect2) {
        float intersect_x1 = std::max(rect1.x, rect2.x);
        float intersect_y1 = std::max(rect1.y, rect2.y);
        float intersect_x2 = std::min(rect1.x + rect1.width, rect2.x + rect2.width);
        float intersect_y2 = std::min(rect1.y + rect1.height, rect2.y + rect2.height);

        if (intersect_x1 < intersect_x2 && intersect_y1 < intersect_y2) {
            return Rectangle(intersect_x1, intersect_y1, intersect_x2 - intersect_x1, intersect_y2 - intersect_y1);
        }
        else {
            return Rectangle(0, 0, 0, 0);
        }
    }

    void printInfo() const {
        std::cout << "Rectangle: (" << x << ", " << y << "), Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {

    Rectangle rect1(1, 1, 5, 3);
    Rectangle rect2(3, 2, 4, 4);

    rect1.printInfo();
    rect2.printInfo();

    rect1.move(2, 3);
    rect1.printInfo();

    rect2.resize(6, 6);
    rect2.printInfo();

    Rectangle bounding_rect = Rectangle::minimumBoundingRectangle(rect1, rect2);
    std::cout << "Bounding Rectangle: ";
    bounding_rect.printInfo();

    Rectangle intersect_rect = Rectangle::intersection(rect1, rect2);
    std::cout << "Intersection Rectangle: ";
    intersect_rect.printInfo();
}