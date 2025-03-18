// Function objects, constexpr








#include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;

struct Foo{
    int value;

    Foo(){}
    Foo(int value ): value(value){} //int copy c-tor
    Foo(std::initializer_list<int> il) : value(15){}


    void print() const{
        cout << "my value is "<< value << endl;
    }


    //default method; function object
    void operator() () const{
        cout << "my value is "<< value << endl;
    }
};


// template <typename T>
// void print_container(const T& container){ //this will not work with list we need something else
//     for(int i=0; i < container.size(); i++)
//         cout << container[i] << " ";
//     cout << endl;
    
// now this can work with both. For generic access code, we should use itertors. Array accesses are luxury
//They are random
// template <typename T>
// void print_container(const T& container){
//     for(auto iter = container.begin(); iter!= container.end(); iter++)
//         cout << *iter << " ";
//     cout << endl;
    
// }
//same thing in new dialect.
template <typename T>
void print_container(const T& container){
    for(const auto& item: container) //by default auto item is cloning from container instead we will use binding (&) const auto& is better. Now it will not copy it
    //optimizer will see this and say instead of reference if the type is primitive it will say ok go ahead and copy it
        cout << item << " ";
    cout << endl;
    
}



int main(int argc, char* argv[]){

    auto foo = Foo{}; //1 byte even if it'S empty for identification purposes
    auto foo2 = Foo{10};
    cout << sizeof(Foo) <<endl;
    cout<< foo2.value <<endl;
    foo2.print();
    foo2();

    auto v  = std::vector<float> {1.1f,1.2f,1.3f};
    print_container(v);
    auto v2 = std::list<int>{1,2,3};
    print_container(v2);


}