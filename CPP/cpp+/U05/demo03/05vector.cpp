#include<iostream>
#include<vector>

int main(){
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "The first element: " << numbers[0] << std::endl;

    std::cout << "The current element count: " << numbers.size() << std::endl;

    for(int num : numbers){
        std::cout << num << " ";
    }

    return 0;
}