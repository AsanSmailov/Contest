#include <sstream>


Course make_course(std::string& course_name, std::string& semester_str, std::string& finished_str){
    Course course;
    course.name = course_name;
    course.semester = std::stoi(semester_str);
    course.finished = (finished_str == "1");
    return course;
}

Student make_student (std::string& line){
    Student student;
    std::stringstream ss(line);
    std::getline(ss, student.name, ';');
    std::getline(ss, student.group, ';');

    std::string course_name;
    while (std::getline(ss, course_name, ';')) {
        std::string semester_str;
        std::getline(ss, semester_str, ';');
        std::string finished_str;
        std::getline(ss, finished_str, ';');
        student.courses.push_back(make_course(course_name, semester_str, finished_str));
    }


    return student;
}



bool is_upper(const Student& s1, const Student& s2) {
    if (s1.group != s2.group) {
        return s1.group < s2.group;
    } else {
        return s1.name < s2.name;
    }
}

bool is_debtor(const Student& student, int cur_semester, int max_debt){
    int debt_counter = 0;
    for (int i = 0; i < student.courses.size(); i++){
        if (student.courses[i].semester < cur_semester && student.courses[i].finished == false){
            debt_counter++;
        }
    }
    return debt_counter > max_debt;
}


void print(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Empty list!\n";
        return;
    }
    std::string current_group = students.front().group;
    std::cout << current_group << '\n';
    for (const auto& student : students) {
        if (student.group != current_group) {
            current_group = student.group;
            std::cout << current_group << '\n';
        }
        std::cout << "- " << student.name << '\n';
    }
}