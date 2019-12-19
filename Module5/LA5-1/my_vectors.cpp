#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std;

int main()
{
    std::vector<int> vec;
    //add elements
    vec.push_back(100); //both front() and back() contain the 100 value
    vec.push_back(200); //front() =100 and back() = 200
    std::cout << "Front of vector: " << vec.front() << std::endl;
    std::cout << "Back of vector: " << vec.back() << std::endl;
    vec.push_back(300);
    //iterate over the vector
    std::cout << "Using index notation " << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }

    std::cout << "Using an iterator" << std::endl;
    for (auto it = std::begin(vec); it != std::end(vec); ++it)
    {
        std::cout << *it << std::endl; //must de-reference "it" to get the value "it" points to 
    }

    std::cout << "Using range based loop" << std::endl;
    for (const auto& value: vec)
    {
        std::cout << value << " ";
    }
    std::cout<<std::endl;

    //define and initialize vector, use { } with comma separated values
    std::vector<int> vec2 = {-1,-1,-1,-1,-1};

    for (int x : vec2)
    {
        std::cout << x << std::endl;
    }

    int max = 5;
     std::vector<int> vec3(max, 4);//vector constructor

    for (int xx : vec3)
    {
        std::cout << xx << " ";
    }
    std::cout<<std::endl;

    return 0;
}