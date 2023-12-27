int* new_array(int len, int value){
    int* arr = new int[len];

    for (int i = 0; i < len; i++) {
        arr[i] = value;  
    }

    return arr;  
}    
    
int set_new_length(int** array, int old_len, int new_len) {
    int* tempArray = new int[new_len];
    for (int i = 0; i < old_len && i < new_len; i++) {
        tempArray[i] = (*array)[i];
    }
    for (int i = old_len; i < new_len; i++) {
        tempArray[i] = 0;
    }
    *array = tempArray;
    return new_len;  
}  

int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array){
    int* tempArray = new int[len_dest_array + len_src_array];
    for (int i = 0; i < len_dest_array; i++) {
        tempArray[i] = (*dest_array)[i];
    }
    for (int i = len_dest_array; i < len_src_array; i++) {
        tempArray[i] = src_array [i];
    }
    *dest_array = tempArray;
    return len_dest_array + len_src_array;  
}

int dot(const int* a, const int* b, int len){
    if (len == 0) return 0;
    int res = 0;
    for (int i = 0; i < len; i++){
        res += a[i] * b[i];
    }
    return res;
}

int* find(int* array, int len, int value){
    for (int i = 0; i < len; i++){
        if (array[i] == value) return &array[i];
    }
    return nullptr;
}

void delete_array(int** array){
    if(*array == nullptr) return;
    *array = nullptr;
}
