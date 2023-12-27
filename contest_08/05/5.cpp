class IntSharedPointer{
public:
    int* smth;
    int count;
    
    IntSharedPointer(int* p){
        smth = p;
        count++;
    }
    
    ~IntSharedPointer(){
        count--;
        if (count==0) smth = nullptr;
    }
    
    int& operator*() const {
        return *smth;
    }
    
    IntSharedPointer(const IntSharedPointer &p){
        smth = p.smth;
        count++;
    }
};