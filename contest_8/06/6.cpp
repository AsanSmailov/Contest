Any::Any(int* data) {
    this->data = data;
    type = Type::INT;
}

Any::Any(double* data) {
    this->data = data;
    type = Type::DOUBLE;
}

Any::Any(std::string* data) {
    this->data = data;
    type = Type::STRING;
}

Any::Any(std::vector<Any*>* data) {
    this->data = data;
    type = Type::VECTOR_ANY_PTR;
}

Any::~Any() {
    if (type == Type::VECTOR_ANY_PTR) {
        std::vector<Any*>* vec = static_cast<std::vector<Any*>*>(data);
        for (Any* elem : *vec) {
            delete elem;
        }
        delete vec;
    } else {
        delete data;
    }
}

Any::operator int() {
    if (type == Type::INT){
        return *static_cast<int*>(data);
    } else throw "";
}

Any::operator double() {
    if (type == Type::DOUBLE){
        return *static_cast<double*>(data);
    } else throw "";
    
}

Any::operator std::string() {
    if (type == Type::STRING){
        return *static_cast<std::string*>(data);
    } else throw "";
    
}

Any::operator std::vector<Any*>*() {
    if (type == Type::VECTOR_ANY_PTR){
        return static_cast<std::vector<Any*>*>(data);
    } else throw "";
    
}

std::ostream& operator<<(std::ostream& out, const Any& val) {
    if (val.type == Any::Type::INT) {
        out << *static_cast<int*>(val.data);
    } else if (val.type == Any::Type::DOUBLE) {
        out << *static_cast<double*>(val.data);
    } else if (val.type == Any::Type::STRING) {
        out << *static_cast<std::string*>(val.data);
    } else if (val.type == Any::Type::VECTOR_ANY_PTR) {
        std::vector<Any*>* vec = static_cast<std::vector<Any*>*>(val.data);
        for (size_t i = 0; i < vec->size(); i++) {
            out << *(*vec)[i];
            if (i < vec->size() - 1) {
                out << ' ';
            }
        }
    }
    
    return out;
}