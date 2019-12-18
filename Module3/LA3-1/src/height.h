#pragma once

// Create your first class
class Height
{
    private:
        double inches_;
    public:
        
        // Constructor: build/create your object
        Height()  {inches_ = 0;} //don't need anything in .cpp file now since only one line
        Height(double inches) : inches_(inches){}
        //Height(double inches); //not included in class
        ~Height() {}

        // Getters
        double inches() const {return inches_ ;};  
  
        // Setters
        void set_inches(double inches)  {inches_ = inches;} //all this was in .cpp before

        //other methods
        friend void print_feet(Height h1);

};  // must have a ";" 