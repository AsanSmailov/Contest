#include <sstream>
Student make_student(std::string str){
    Student student;
    std::stringstream ss(str);
    std::getline(ss, student.name, ';');
    std::getline(ss, student.group);
    return student;
}
bool is_upper( Student s1, Student s2) {
     if(s1.group != s2.group){
        return s1.group < s2.group;
    } else {
        return s1.name < s2.name;
    }
}
void print(std::vector<Student> s){
     if(s.empty()){
        std::cout << "Empty list!\n";
        return;
    }
    std::string group0 = s[0].group;
    std::cout << group0 << '\n';
    for(const auto& s1: s){
        if(s1.group != group0){
            group0 = s1.group;
            std::cout << group0 << '\n';
        }
        std::cout << "- " << s1.name << '\n';
    }
}