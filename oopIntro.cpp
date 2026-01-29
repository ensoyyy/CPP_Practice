#include <iostream>
#include <vector>
#include <cmath>

class Point{
    private:
        int x;
        int y;
    public:
        int getX() const { return x;}
        void setX(int newX) { x = newX;}
       
        int getY() const { return y;}
        void setY(int newY) { y = newY;}

        void print() const{
                std::cout << "(" << x << ", " << y << ")\n";
            }

            double distanceTo(const Point& other) const{
                int xDiff = x - other.x;
                int yDiff = y - other.y;
                return std::sqrt(xDiff * xDiff + yDiff * yDiff);
            }

        Point() = default;
        Point(int x, int y): x(x), y(y) {}

        static void printPoints(const std::vector<Point>& points){
            std::cout << "We are going to print " << points.size() <<" points:" << "\n";
            for(const auto& point : points){
                point.print();
            }
        }
        

};

int main(){
    // points are:
    //(0,1), (2,2) (2,3), (3,4),(4,5)

    std::vector<Point> points = {
        {0,1},
        {2,2},
        {2,3},
        {3,4},
        {4,5}
    };

    Point::printPoints(points);
    
    for(int i = 0; i < points.size(); ++i){
        points.at(i).print();
        if(i == 4) {
            std::cout << "No next point\n";
            break;
        }      
        std::cout << "Distance to next point: " << points.at(i).distanceTo(points.at(i+1)) << "\n";
    }

    Point p;
    p.setX(10);
    p.setY(20);

    std:: cout << p.getX() << ", " << p.getY() << "\n";
    

    return 0;
}