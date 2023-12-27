class Vector;

class Point{
public:
    int x;
    int y;
    Point (int x1, int y1){
        x=x1;
        y=y1;
    }
    void move(Vector dir);
};

class Vector{
public:
    int x;
    int y;
    Vector(Point p1,Point p2){
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
};

void Point::move(Vector dir){
    x = x + dir.x;
    y = y + dir.y;
}