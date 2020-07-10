#include "matrix.h"

Matrix::Matrix()
{
    rows=0;
    cols=0;
    v=new Vector[0];
}

Matrix::Matrix(Vector *v,int cols,int rows){
    this->rows=rows;
    this->cols=cols;
    this->v=new Vector[rows];
    for (int i=0;i<rows;i++){
        this->v[i]=v[i];
    }
}

Matrix::Matrix(int rows,int cols)
{
    this->rows=rows;
    this->cols=cols;
    v=new Vector[rows];
}

Matrix Matrix::smallermatr(int cols, int rows){
    Matrix c(cols,rows);
    for (int i=0;i<rows;i++){
        int *v1=new int[cols];
        for (int j=0;j<cols;j++)
            v1[j]=this->v[i][j];
        Vector d(v1,cols);
        c.v[i]=d;
    }
    return c;
}

Matrix Matrix::trans(){
    Matrix c(this->cols,this->rows);
    for (int i=0;i<rows;i++){
        for (int j=i+1;j<cols;j++){
           c.v[i].setVal(j,this->v[j][i]);
        }
    }
    return c;
}

void Matrix::print()
{
    for (int i=0;i<this->rows;i++){
        this->v[i].print();
    }
}

void Matrix::setVal(int value, int col, int row)
{
    v[row].setVal(col,value);
}

Matrix Matrix::getMatrixWithoutRowAndCol(int row, int col)
{
    Matrix newMatrix(this->cols-1, this->rows-1);

    if(this->cols != this->rows) {
        qWarning("The matrix is not square");
        return newMatrix;
    }

    for(int i=0; i < newMatrix.rows; i++) {
       newMatrix.v[i] = Vector(newMatrix.cols, 0);
    }

    int offsetRow = 0; //Смещение индекса строки в матрице
    int offsetCol = 0; //Смещение индекса столбца в матрице

    for(int i = 0; i < this->cols-1; i++) {
        //Пропустить row-ую строку
        if(i == row) {
            offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
        }

        offsetCol = 0; //Обнулить смещение столбца
        for(int j = 0; j < this->cols-1; j++) {
            //Пропустить col-ый столбец
            if(j == col) {
                offsetCol = 1; //Встретили нужный столбец, проускаем его смещением
            }

            newMatrix.v[i].setVal(j, this->v[i + offsetRow][j + offsetCol]);
        }
    }
    return newMatrix;
}

int Matrix::det(int size)
{
    int det = 0;
    int degree = 1; // (-1)^(1+j) из формулы определителя

    //Условие выхода из рекурсии
    if(size == 1) {
        return v[0][0];
    }
    //Условие выхода из рекурсии
    else if(size == 2) {
        return v[0][0]*v[1][1] - v[0][1]*v[1][0];
    }
    else {
        Matrix newMatrix(cols-1,rows-1);
        //Раскладываем по 0-ой строке, цикл бежит по столбцам
        for(int j = 0; j < size; j++) {
            //Удалить из матрицы i-ю строку и j-ый столбец
            //Результат в newMatrix
            newMatrix = this->getMatrixWithoutRowAndCol(0, j);

            //Рекурсивный вызов
            //По формуле: сумма по j, (-1)^(1+j) * matrix[0][j] * minor_j (это и есть сумма из формулы)
            //где minor_j - дополнительный минор элемента matrix[0][j]
            det = det + (degree * v[0][j] * newMatrix.det(size-1));
            //"Накручиваем" степень множителя
            degree = -degree;
        }

        //Чистим память на каждом шаге рекурсии(важно!)
        delete [] newMatrix.v;
    }

    return det;
}

int Matrix::cofactor(int col, int row)
{
    return pow(-1, row + col)*this->getMatrixWithoutRowAndCol(row, col).det(this->rows-1);
}

Matrix &Matrix::operator=(const Matrix &m)
{
    delete [] v;

    cols = m.cols;
    rows = m.rows;

    v = new Vector[rows];

    for(int i=0; i < rows; i++) {
        v[i] = m.v[i];
    }

    return *this;
}
