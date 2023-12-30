func NewMatrix(rows, cols, value int) Matrix {
	matrix := Matrix{data: make([][]int, rows)}

	for i := 0; i < rows; i++ {
		matrix.data[i] = make([]int, cols)
		for j := 0; j < cols; j++ {
			matrix.data[i][j] = value
		}
	}

	return matrix
}

func (m *Matrix) Rows() int {
	return len(m.data)
}

func (m *Matrix) Cols() int {
	return len(m.data[0])
}

func (m *Matrix) Set(row, col, value int) {
	(*m).data[row][col] = value

}

func (m *Matrix) Get(row, col int) int {

	return (*m).data[row][col]
}

func (m *Matrix) Convolution(core *Matrix) Matrix {
	rows := len(m.data) - len(core.data) + 1
	cols := len(m.data[0]) - len(core.data[0]) + 1
	result := NewMatrix(rows, cols, 0)

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			sum := 0
			for k := 0; k < len(core.data); k++ {
				for l := 0; l < len(core.data[0]); l++ {
					sum += m.data[i+k][j+l] * core.data[k][l]
				}
			}
			result.data[i][j] = sum
		}
	}
	return result
}

func (a *Matrix) Multiplication(b *Matrix) *Matrix {
	result := NewMatrix(len((*a).data), len((*b).data[0]), 0)
	for i := 0; i < len((*a).data); i++ {
		for j := 0; j < len((*b).data[1]); j++ {
			sum := 0
			for k := 0; k < len((*a).data[1]); k++ {
				sum += (*a).data[i][k] * (*b).data[k][j]
			}
			result.data[i][j] = sum
		}
	}
	return &result
}

func (m *Matrix) AddRow(value int) {
	rows := len((*m).data)
	cols := len((*m).data[1])

	newm := NewMatrix(rows+1, cols, value)

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			newm.data[i][j] = (*m).data[i][j]
		}
	}

	*m = newm
}

func (m *Matrix) AddCol(value int) {
	rows := len((*m).data)
	cols := len((*m).data[1])

	newm := NewMatrix(rows, cols+1, value)

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			newm.data[i][j] = (*m).data[i][j]
		}
	}

	*m = newm
}

func (m *Matrix) String() string {
	str := ""
	for i := 0; i < len((*m).data); i++ {
		for j := 0; j < len((*m).data[1]); j++ {
			value := (*m).data[i][j]
			str += fmt.Sprintf("%d ", value)
			if j != len((*m).data[1])-1 {
				str += " "
			} else {
				str += "\n"
			}
		}
	}
	return str
}