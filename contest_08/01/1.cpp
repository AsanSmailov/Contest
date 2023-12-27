class Keeper2{
public:
    int trash;
    int secret;
};


int hack_it(Keeper &keeper){
    void *p = &keeper;
    Keeper2 *pb= static_cast<Keeper2*> (p);
    return pb ->secret;
}