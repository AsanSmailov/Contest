using namespace std;

class Water{
    private:
    int temp;
    public:
    Water (int temperature):
    temp(temperature){}
    
    int get_temperature(){
        return temp;
    }
    void temper(int amount){
        temp+=amount;
    }
    
};

class Teapot{
    private:
    Water&water;
    public:
    Teapot(Water&water):
    water(water){}
    bool is_boiling(){
        return water.get_temperature()>=100;
    }
    void heat_up(int amount){
        water.temper(amount);
    }
};