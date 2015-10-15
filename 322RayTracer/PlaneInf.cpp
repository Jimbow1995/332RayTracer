#include "PlaneInf.h"
#include "math.h"

Intersect PlaneInf::Intersection(glm::vec3 ROrigin, glm::vec3 RDirection)
{
	float denominator = glm::dot(RDirection, Normal);
	if (abs(denominator) > 0.000001) {
		float t = glm::dot((Origin - ROrigin), Normal) / denominator;
		if (t >= 0) return Intersect(t,Normal);
	}

	return Intersect(-1, Normal);
}

glm::vec3 PlaneInf::PhongShading(float _t, glm::vec3 ROrigin, glm::vec3 RDirection, glm::vec3 CameraPos)
{
	glm::vec3 ContactPoint = ROrigin + _t*RDirection;
	glm::vec3 l = glm::normalize(light->Position - ContactPoint);
	return CalcAmbient() + CalcDiffuse(l, Normal) + CalcSpecular(l, Normal, CameraPos, ContactPoint);
}