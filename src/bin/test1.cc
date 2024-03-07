#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age = 0; // 在结构体内部提供默认值
};

int main() {
    // 使用默认初始化
    Person person1; // 使用默认值初始化
    Person person2{"Alice", 25}; // 使用自定义值初始化

    std::cout << "Person 1: Name = " << person1.name << ", Age = " << person1.age << std::endl;
    std::cout << "Person 2: Name = " << person2.name << ", Age = " << person2.age << std::endl;

    return 0;
}
