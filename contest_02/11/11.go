func isValidSudoku(bord [9][9] int) bool{
    for row:=0;row<9;row++{
        for col:=0;col<9;col++{
            for n:=1;n<9-col;n++{
                if bord[row][col]==bord[row][col+n]{
                return false
                }
            }
        }
    }
    for col:=0;col<9;col++{
        for row:=0;row<9;row++{
            for n:=1;n<9-row;n++{
                if bord[row][col]==bord[row+n][col]{
                return false
                }
            }
        }
    }
    for row:=0;row<3;row+=3{
        for col:=0;col<3;col+=3{
            for row:=0;row<3;row++{
                for col:=0;col<3;col++{
                    for n:=1;n<3-col;n++{
                        if bord[row][col]==bord[row][col+n]{
                        return false
                        }
                        if bord[row][col]==bord[row+n][col]{
                        return false
                        }
                        for m:=1;m<3-row;m++{
                           if bord[row][col]==bord[row+m][col+n]{
                        return false
                        } 
                        }
                    }
                }
            }
        }
    }
    return true
}