#include <iostream>
#include <vector>
#include <cmath>

class Point{
    protected:
        int x;
        int y;
    public:
        int getX() const { return x;}
        void setX(int newX) { x = newX;}
       
        int getY() const { return y;}
        void setY(int newY) { y = newY;}

        virtual void print() const{
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

class XYZPoint : public Point{
    private:
        int z;
    public:
        XYZPoint(int x, int y, int z): Point(x,y), z(z){}
        void print() const override{
            std::cout << "(" << x << ", " << y << ", " << z << ")\n";
            
        }

};

class City{
    private:
        Point location;
        std::string name;
        int population;
    public:
        City(): location(Point()), name("uknown"), population(0){}
        City(Point location, std::string name, int population): location(location), name(name), population(population){}

        const Point& getLocation() { return location; }
        void setLocation(const Point& newLocation) { location = newLocation;}
        std::string getName() const { return name; }
        void setName(const std::string& newName) { name = newName;}
        int getPopulation() const { return population; }
        void setPopulation(int newPopulation) { population = newPopulation;}
};

int main(){
    XYZPoint p1 = XYZPoint(10,20,30);
    Point p2 = Point(40,50);
    std::vector<Point*> points = {&p1, &p2};
    
    for(auto p : points){
        p->print();
    }
    
    return 0;
}