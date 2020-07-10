#include "vector.h"
#include "math.h"

Vector::Vector()
{
    this->size=0;
    this->val=new double[0];
}

Vector::Vector(int s){
    this->size=s;
    this->val=new double[s];
}

Vector::Vector(int s, bool type)
{
    this->size=s;
    this->val=new double[s];
    if(type) {
        for(int i=0;i<s;i++) {
            this->val[i]=1;
        }
    } else {
        for(int i=0;i<s;i++) {
            this->val[i]=0;
        }
    }
}

Vector::~Vector()
{
    delete [] val;
}

Vector::Vector(double *a, int s){
    this->size=s;
    this->val=new double[s];
    for (int i=0;i<s;i++){
        this->val[i]=a[i];
    }

}

Vector::Vector(const Vector &v){
    this->size=v.size;
    this->val=new double[v.size];
    for(int i=0;i<v.size;i++){
        this->val[i]=v.val[i];
    }
}

double Vector::length(){
    double result = 0;
        for (int i = 0; i < size; ++i) {
            result += pow(this->val[i],2);
        }

    return abs(sqrt(result));
}

int Vector::getSize(){
    return this->size;
}

void Vector::setVal(int index, double x){
    this->val[index] = x;
}

Vector& Vector::operator = (const Vector &v1)
{
   delete[] val;

   size = v1.size;

   val = new double[size];

   std::copy(v1.val, v1.val + v1.size, val);

   return *this;
}

Vector Vector::operator+(const Vector &v1){
    if (size!=v1.size){
        qWarning("Invalid index");
    }
    Vector c(v1.size);
    for (int i = 0; i < size; ++i) {
            c.val[i] = val[i] + v1.val[i];
        }
    return c;
}

Vector Vector::operator-(const Vector &v1){
    if (size!=v1.size){
        qWarning("Invalid index");
    }
    Vector c(v1.size);
    for (int i = 0; i < size; ++i) {
            c.val[i] = val[i] - v1.val[i];
        }
    return c;
}

Vector Vector::operator*(double x){
    for (int i = 0; i < size; ++i) {
            val[i] = val[i] * x;
        }
    return *this;
}

Vector Vector::operator*(const Vector &v1){
   int result = 0;
        for (int i = 0; i < size; ++i)
            result = result + (*this).val[i] * v1.val[i];
   return result;
}

double Vector::operator[](int x){
    if (x>this->size){
        qWarning("Invalid index. Vector is shorter");
    }
    if (x<0){
        qWarning("Invalid index");
    }
    return this->val[x];
}

void Vector::print(){
    QTextStream out(stdout);
    for (int i=0;i<size;i++){
        out << val[i] << "\t";
    }
    out << Qt::endl;
}
