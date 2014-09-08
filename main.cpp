#include "quaternion.hpp"
#include "qpose.hpp"
#include <iostream>
#include <ctgmath>


int main(void)
{
    Quaternion<float>* myQuat = new Quaternion<float>(1.0, 2.0, 3.0, 4.0);
    Quaternion<float> myOtherQuat(1.0, 1.0, 0.0, 2.0);

    std::cout << "My Quaternion: " << *myQuat << std::endl;
    std::cout << "My other Quaternion: " << myOtherQuat << std::endl;

    Quaternion<float> qMultProd = *myQuat * myOtherQuat;
    std::cout << "My Quaternion product: " << qMultProd << std::endl;

    std::cout << "Scalar multiplication: " << (2 * myOtherQuat) << std::endl;

    std::cout << "Unit quaternion: " << myOtherQuat.unit() << std::endl;

    myOtherQuat.normalize();
    std::cout << "Quaternion now normalized." << std::endl;
    std::cout << "normalized quaternion: " << myOtherQuat << std::endl;
    std::cout << "normalized quaternion magnitude: " << myOtherQuat.norm() 
              << std::endl;
    
    delete myQuat;

    /// Rotation storage tests:

    Quaternion<float> rotQuat;

    // encode a 180-deg rotation about the z-axis.
    rotQuat.encodeRotation(M_PI/2, 0, 0, 1);

    float rotQuatTheta, rotQuatX, rotQuatY, rotQuatZ;
    rotQuat.getRotation(rotQuatTheta, rotQuatX, rotQuatY, rotQuatZ);

    std::cout << "rotQuatTheta should be pi/2 and it's: " << rotQuatTheta 
              << std::endl;
    std::cout << "rotQuatX should be 0 and it's: " << rotQuatX << std::endl;
    std::cout << "rotQuatY should be 0 and it's: " << rotQuatY << std::endl;
    std::cout << "rotQuatZ should be 1 and it's: " << rotQuatZ << std::endl;



    QPose<float> myPose(1, 2, 3, 0, 0, 0);  // x, y, z, roll, pitch, yaw;

    float x, y, z;

    myPose.getTranslation(x, y, z);
    std::cout << "posX should be 1 and it's: " << x << std::endl;
    std::cout << "posY should be 2 and it's: " << y << std::endl;
    std::cout << "posZ should be 3 and it's: " << z << std::endl;

    return 0;
}
