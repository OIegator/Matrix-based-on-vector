#include "vector.h"
#include "math.h"

Vector::Vector()
{
    this->size=0;
    this->val=new int[0];
}

Vector::Vector(int s){
    this->size=s;
    this->val=new int[s];
}

Vector::Vector(int s, bool type)
{
    this->size=s;
    this->val=new int[s];
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

Vector::Vector(int *a, int s){
    this->size=s;
    this->val=new int[s];
    for (int i=0;i<s;i++){
        this->val[i]=a[i];
    }

}

Vector::Vector(const Vector &v){
    this->size=v.size;
    this->val=new int[v.size];
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

void Vector::setVal(int index, int x){
    this->val[index] = x;
}

Vector& Vector::operator = (const Vector &v1)
{
   delete[] val;

   size = v1.size;

   val = new int[size];

   std::copy(v1.val, v1.val + v1.size, val);

   return *this;
}

Vector Vector::operator+(const Vector &v1){
    if (size!=v1.size){

    }
    Vector c(v1.size);
    for (int i = 0; i < size; ++i) {
            c.val[i] = val[i] + v1.val[i];
        }
    return c;
}

Vector Vector::operator-(const Vector &v1){
    if (size!=v1.size){

    }
    Vector c(v1.size);
    for (int i = 0; i < size; ++i) {
            c.val[i] = val[i] - v1.val[i];
        }
    return c;
}

Vector Vector::operator*(int x){
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

int Vector::operator[](int x){
    if (x>this->size){

    }
    if (x<0){

    }
    return this->val[x];
}

void Vector::print(){
    QTextStream out(stdout);
    for (int i=0;i<size;i++){
        out << val[i] << " ";
    }
    out << Qt::endl;
}
