#include <iostream>
#include <set>

//sets: elements are sorted according to the values
//elements are all distinct value
// a container with a UNIQUE group sorted elements, only keeps one copy, no duplicates
//methods: size, empty, insert, erase
//find() returns the position of the first element equal to the provided value
        //you should always compare the value against the end of the container
        //it always returns a value, and if it can't find one it returns the end

int main()
{

    std::set<int> numbers;
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(30);

    //search for a value
    if(numbers.find(10) != numbers.end())//end() is not the last element but an extra byte at the end
    {
        std::cout << "10 is in numbers" << std::endl;
    }

    std::cout << "the set has " << numbers.size() << " elements" << std::endl;

    std::cout << "Iterators" << std::endl;
    for(auto it = std::begin(numbers); it != std::end(numbers); ++it)
    {
        std::cout<< *it << std::endl;
    }

    std::cout << "range based" << std::endl;
    for(const auto& value: numbers)
    {
        std::cout<< value << std::endl;
    }

    //or 

     std::cout << "also range based" << std::endl;
    for(const auto& value: numbers)
    {
        std::cout<< value << " ";
    }
    std::cout << std::endl;

}