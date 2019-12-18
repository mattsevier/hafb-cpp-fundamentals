

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
        //Getters which are functions or at least act like functions
        double length(); 
        double width(); 
        double height(); 


};//must end with ;