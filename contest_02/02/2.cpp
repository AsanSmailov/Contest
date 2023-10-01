bool compare(const std::string& a, const std::string& b){
    int countA = std::count(a.begin(), a.end(), '1');
    int countB = std::count(b.begin(), b.end(), '1');
    if(countA != countB){
        return countA > countB;
    }
    else{
        int n{ std::stoi(a) };
        int m{ std::stoi(b) };
        return n < m;
    }
}