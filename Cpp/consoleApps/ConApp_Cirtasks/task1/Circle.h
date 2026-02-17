#pragma once

class Circle{
    private:
        float radius;
    public:
        Circle(float r = 0.0f);
        
        float getRadius() const;
        float getLength() const;
        
        bool operator==(const Circle& other) const;
        bool operator>(const Circle& other) const;
        
        Circle& operator+=(float value);
        Circle& operator-=(float value);
        
        void display() const;
};