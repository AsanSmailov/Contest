#include<math.h>

class Employee{
    public:
    std::string name;
    std::string post;
    int money;
    
    Employee(std::string name, std::string post, int money): name(name), post(post), money(money){}
    
    virtual int bonus(double percent) {
        return round(money * percent);
    }
    
    friend std::ostream& operator<<(std::ostream& os,  Employee& employee) {
        os << employee.name << " (" << employee.post << "): " << employee.money + employee.bonus(bonuses[employee.post]) ;
        return os;
    }
};

class Manager: public Employee{
    public:
    Manager(std::string name, int money = 16242)
    :Employee(name, "manager", money){}
    int bonus(double percent) override {
        double min_bonus = 0.1; 
        double actual_percent = std::max(percent, min_bonus); 
        return round(money * actual_percent);
    }
};