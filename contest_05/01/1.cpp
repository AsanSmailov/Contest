#include <iostream>

using namespace std;

class Cat{
    public:
    	bool is_alive(){
        	return alive;
    	}
		void set_alive(bool state){
			alive=state;
		}
	private:
	bool alive = true;

};

class Box{
    public:
    Cat open(){
        Cat cat;
        cat.set_alive(rand()%2==0);
        return cat;
    }
};