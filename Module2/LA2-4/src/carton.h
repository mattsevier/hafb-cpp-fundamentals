

#pragma once

//create first class

class Carton
{
    private:
        double length_;//underscore indicates private variable
        double width_;
        double height_;

    public:

    //Static constants
    //static const double kMaxSize;
    static const double kMinLength;
    static const double kMinWidth;
    static const double kMinHeight;

        //constructor to build or create the object
        Carton();
        Carton(double length, double width, double height);
        ~Carton();//Destructor 

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
        void SetMeasurements(double length, double width, double height);
        double Volume() const;//making the function read only for what it can extract

        void WriteData(std::ostream &out) const;
        


};//must end with ;