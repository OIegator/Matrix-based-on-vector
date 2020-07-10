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

Matrix::Matrix(int cols, int rows, bool type)
{
    this->rows=rows;
    this->cols=cols;
    v = new Vector[rows];
    if(type) {
        for(int i=0; i < this->rows; i++) {
           this->v[i] = Vector(this->cols, 1);
        }
    } else {
        for(int i=0; i < this->rows; i++) {
           this->v[i] = Vector(this->cols, 0);
        }
    }
}

Matrix::Matrix(Matrix &m){
    this->rows=m.rows;
    this->cols=m.cols;
    this->v=new Vector[rows];
    for (int i=0;i<rows;i++){
        this->v[i]=m.v[i];
    }
}

Matrix Matrix::smallermatr(int cols, int rows){
    Matrix c(cols,rows);
    for (int i=0;i<rows;i++){
        double *v1 = new double[cols];
        for (int j=0;j<cols;j++)
            v1[j]=this->v[i][j];
        Vector d(v1,cols);
        c.v[i]=d;
    }
    return c;
}

Matrix Matrix::trans(){
    Matrix c(this->cols,this->rows, 0);

    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
           c.v[j].setVal(i,this->v[i][j]);
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

int Matrix::getCol()
{
    return cols;
}

void Matrix::setVal(double value, int col, int row)
{
    v[row].setVal(col,value);
}

Matrix Matrix::reverse()
{
    Matrix reversed(cols, rows, 0);

    int deter = this->det(this->rows);
    if(deter){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < rows; j++){
                int m = rows - 1;
                Matrix temp(m, m);
                for(int k = 0; k < m; k++)
                    temp.v[k] = Vector(m, 0);;
                temp = this->getMatrixWithoutRowAndCol(i,j);
                reversed.v[i].setVal(j, pow(-1, i + j + 2) * temp.det(m) / deter);
            }
        }
        reversed = reversed.trans();
    } else {
        qWarning("The matrix is not square");
    }
    return reversed;
}

Matrix Matrix::getMatrixWithoutRowAndCol(int row, int col)
{
    Matrix newMatrix(this->cols-1, this->rows-1, 0);

    if(this->cols != this->rows) {
        qWarning("The matrix is not square");
        return newMatrix;
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

double Matrix::det(int size)
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

double Matrix::cofactor(int col, int row)
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

Matrix Matrix::operator+(const Matrix &m){
    if (rows!=m.rows && cols!=m.cols)
        qWarning("Invalid dimension of matrices");
    Matrix c(m.rows,m.cols);
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            c.v[i].setVal(j,v[i][j]+m.v[i][j]);
    return c;
}

Matrix Matrix::operator-(const Matrix &m){
    if (rows!=m.rows && cols!=m.cols)
        qWarning("Invalid dimension of matrices");
    Matrix c(m.rows,m.cols);
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            c.v[i].setVal(j,v[i][j]-m.v[i][j]);
    return c;
}

Matrix Matrix::operator*(int x){
    Matrix c(rows,cols);
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            c.v[i].setVal(j,v[i][j]*x);
    return c;
}

Matrix Matrix::operator*(const Matrix &m){
    if (cols!=m.cols){
        qWarning("Invalid dimension of matrices");
    }
    Matrix c(rows,cols);
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++){
            int s=0;
            for (int k=0; k<cols; k++)
               s+=v[i][k]*m.v[k][j];
            c.v[i].setVal(j,s);
        }
    return c;
}

Vector Matrix::operator*(Vector &v){
    Vector v1(v.getSize());
    for (int i=0; i<v.getSize(); i++){
        int s=0;
        for (int j=0; j<cols; j++)
            s+=this->v[j][i]*v[j];
        v1.setVal(i,s);
    }
    return v1;
}

bool Matrix::operator==(const Matrix &m){
    if (rows!=m.rows && cols!=m.cols)
        return false;
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            if (v[i][j] - m.v[i][j] > 1E-10)
                return false;
    return true;
}

bool Matrix::operator!=(const Matrix &m){
    if (rows!=m.rows && cols!=m.cols)
        return true;
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            if (v[i][j]!=m.v[i][j])
                return true;
    return false;
}

double Matrix::operator()(int x, int y){
    return v[x][y];
}
