

#pragma once

//create first class

class Carton
{
    private:
        double length_;//underscore indicates private variable
        double width_;
        double height_;

    public:
        //constructor to build or create the object
        Carton();
        Carton(double length, double width, double height);
        //Getters which are functions or at least act like functions
        double length(); 
        double width(); 
        double height(); 
        //Setters
        void set_length(double length);
        void set_width(double width);
        void set_height(double height);
        //Other methods
        void ShowInfo();
        


};//must end with ;