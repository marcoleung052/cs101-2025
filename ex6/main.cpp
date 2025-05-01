#include <iostream>
using namespace std;
class Animal{
    public:
    void sound(){
        cout<<"??"<<endl;
    }
};
class Cat : Animal{
    public:
    void sound(){
        cout<<"喵"<<endl;
    }
};
class Dog : Animal{
    public:
    void sound(){
        cout<<"汪"<<endl;
    }
    void sound(int i){
        for(int j=0;j<i;j++){
            cout<<"汪";
        }
        cout<<endl;
    }
    void sound(string s,int i){
        for(int j=0;j<i;j++){
            cout<<s;
        }
        cout<<endl;
    }
};
int main()
{
    Cat myCat;
    Dog myDog;
    myCat.sound();
    myDog.sound();
    myDog.sound(5);
    myDog.sound("喵汪~",3);
    return 0;
}
