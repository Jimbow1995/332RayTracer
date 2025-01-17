#pragma once
#include <iostream>
#include "Shape.h"
#include <glm.hpp>
#include "light.h"
class Triangle : public Shape
{
public:
	glm::vec3 Normal;
	glm::vec3 a;
	glm::vec3 b;
	glm::vec3 c;
	//Light* light;
	void CalculateNormal();
	Triangle(glm::vec3 Point1, glm::vec3 Point2, glm::vec3 Point3, glm::vec3 c, float _Ambient, float _Specular, bool _Reflective, float _Reflectivity, float _AmountOfBaseColour) :
		Shape(c,_Ambient,_Specular,_Reflective, _Reflectivity, _AmountOfBaseColour), a(Point1), b(Point2), c(Point3)
	{
		CalculateNormal();
	};
	virtual Intersect Intersection(glm::vec3 Origin, glm::vec3 Direction);
	virtual glm::vec3 PhongShading(float, glm::vec3, glm::vec3, glm::vec3, float, Shape*[], int numberofshapes);
	virtual glm::vec3 GetOrigin() { return glm::vec3(0, 0, 0); };
	virtual void SetOrigin(glm::vec3) {};
	//glm::vec3 CalcAmbient();
	//glm::vec3 CalcDiffuse(glm::vec3, glm::vec3);
	//glm::vec3 CalcSpecular(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
};
