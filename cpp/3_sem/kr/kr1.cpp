#include <cmath>
#include <iostream>
#include <fstream>

#define ARRAY_LENGTH 3

class Vector3
{
public:
   float x, y, z;

   Vector3(){};
   //~Vector3();

   Vector3(float e1, float e2, float e3)
   {
       x = e1;
       y = e2;
       z = e3;
   }

   Vector3 operator+(const Vector3 &vec);
   Vector3 operator-(const Vector3 &vec);
   
   Vector3 operator*(const float &t);
   
   float dot(const Vector3 &vec);
   Vector3 cross(const Vector3 &vec);
   
   float length() const;
   Vector3 unit();

};


Vector3 Vector3::operator+(const Vector3 &vec)
{
   return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector3 Vector3::operator-(const Vector3 &vec)
{
   return Vector3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

Vector3 Vector3::operator*(const float &t)
{
   return Vector3(this->x * t, this->y * t, this->z * t);
}

float Vector3::dot(const Vector3 &vec)
{
   return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Vector3 Vector3::cross(const Vector3 &vec)
{
   return Vector3((this->y * vec.z - this->z * vec.y), (this->x * vec.z - this->z * vec.x), (this->x * vec.y - this->y * vec.x));
}

float Vector3::length() const
{
   return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector3 Vector3::unit()
{
   return Vector3(this->x / this->length(), this->y / this->length(), this->z / this->length());
}

std::ostream &operator<<(std::ostream &stream, Vector3 vec){
   stream << " " << vec.x << " " << vec.y << " " << vec.z;
   return stream;
}

std::istream &operator>>(std::istream &stream, Vector3 &vec){
   stream >> vec.x >> vec.y >> vec.z;
   return stream;
}

void isCollinear(Vector3 *vecs)
{

   for (int i = 0; i < ARRAY_LENGTH - 1; i++)
   {
       for (int j = i + 1; j < ARRAY_LENGTH; j++)
       {
           if (vecs[i].cross(vecs[j]).length() == 0)
           {
               std::cout << "Vectors are collinear: " << std::endl;
               std::cout << vecs[i] << std::endl;
               std::cout << vecs[j] << std::endl;
           }
       }
   }
}


int main()
{
   Vector3 vec[ARRAY_LENGTH];

   for (int i = 0; i < ARRAY_LENGTH; i++)
   {
       std::cout << " Enter vector " << i << ": " << std::endl;
       Vector3 v;
       std::cin >> v;
       vec[i] = v;
   }

   isCollinear(vec);

   return 0;
}
