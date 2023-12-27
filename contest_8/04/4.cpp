int** new_matrix(int rows, int cols, int value ) {
    int** matrix = new int*[rows];  

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];  
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;  
        }
    }

    return matrix;  
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows , int ccols ) {
    int** result = new int*[mrows - crows + 1];  

    int nrows = mrows - crows + 1;
    int ncols = mcols - ccols + 1;

    for (int i = 0; i < nrows; i++) {
        result[i] = new int[ncols];          
        for (int j = 0; j < ncols; j++) {
            int sum = 0;
            for (int k = 0; k < crows; k++) {
                for (int l = 0; l < ccols; l++) {
                    sum += matrix[i + k][j + l] * core[k][l];                 
                }
            }
            result[i][j] = sum;  
        }
    }

    return std::make_tuple(result, nrows, ncols);  
}

std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols) {
    int** result = new int*[arows];

    for (int i = 0; i < arows; i++) {
        result[i] = new int[bcols];
        for (int j = 0; j < bcols; j++) {
            int sum = 0;
            for (int k = 0; k < acols; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
    return std::make_tuple(result, arows, bcols);
}

std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value) {
    value = 1;
    int** newMatrix = new int*[rows + 1];

    for (int i = 0; i < rows + 1; i++) {
        newMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            if (i < rows) {
                newMatrix[i][j] = (*matrix)[i][j];
            } else {
                newMatrix[i][j] = value;
            }
       
        }
    }

    delete[] *matrix;

    *matrix = newMatrix;
    

    return std::make_tuple(rows + 1, cols);
}


std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value){
    value = 1;
    int** newMatrix = new int*[rows];
    cols += 1;

    for (int i = 0; i < rows; i++) {
        newMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            if (j<cols - 1) {
                newMatrix[i][j] = (*matrix)[i][j];
            }
            else {
                newMatrix[i][j] = value;
            }
        }
    }

    *matrix = newMatrix;
    return std::make_tuple(rows, cols);
}

void delete_matrix(int*** matrix, int rows){
    for (int i = 0; i < rows; i++) {
        delete[] (*matrix)[i];
    }
}

void print(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j];
            if (j != cols - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}