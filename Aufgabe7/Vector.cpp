//
// Created by moritz on 04.05.2021.
//
#include <iostream>

class Vector3D {
private:
    const float x, y, z;
public:
    // a.
    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {
        /*
         this->x = x;
         this->y = y;
         this->z = z;
         */
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getZ() const {
        return z;
    }


    //+
    Vector3D operator+(const Vector3D &vector) const {
        return {this->x + vector.x, this->y + vector.y, this->z + vector.z};
    }

    Vector3D operator+(float factor) const {
        return {factor + x, factor + y, factor + z};
    }

    friend Vector3D operator+(float factor, const Vector3D &vector) {
        return {factor + vector.x, factor + vector.y, factor + vector.z};
    }

    //-
    Vector3D operator-(const Vector3D &vector) const {
        return {this->x - vector.x, this->y - vector.y, this->z - vector.z};
    }

    Vector3D operator-(float factor) const {
        return {factor - x, factor - y, factor - z};
    }

    friend Vector3D operator-(float factor, const Vector3D &vector) {
        return {factor - vector.x, factor - vector.y, factor - vector.z};
    }

    friend Vector3D operator-(const Vector3D &vector, float factor) {
        return {vector.x - factor, vector.y - factor, vector.z - factor};
    }

    //*
    float operator*(const Vector3D &vector) const {
        return this->x * vector.x + this->y * vector.y + this->z * vector.z;
    }

    Vector3D operator*(float factor) const {
        return {factor * x, factor * y, factor * z};
    }

    friend Vector3D operator*(float factor, const Vector3D &vector) {
        return {factor * vector.x, factor * vector.y, factor * vector.z};
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector3D &d) {
        os << "x: " << d.x << " y: " << d.y << " z: " << d.z;
        return os;
    }


};
