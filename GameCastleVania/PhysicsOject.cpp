#include "PhysicsOject.h"

PhysicsObject::PhysicsObject()
{
	setAx(0);
	// set trọng lực mặc định của đối tượng lấy từ GameConfiguration.cpp
	setAy(GLOBALS_D("object_default_ay"));
	setVx(0);
	setVy(0);
	// bật physics cho đối tượng
	setPhysicsEnable(true);
}

void PhysicsObject::onUpdate(float dt)
{
	if (getPhysicsEnable())
	{
		// v = v0 + at
		setVx(getVx() + getAx()*dt);
		setVy(getVy() + getAy()*dt);
		// x = x0 + vx*t = x0 + dx => dx = vx*t
		setDx(getVx()*dt);
		setDy(getVy()*dt);
	}
}

PhysicsObject::~PhysicsObject()
{
}

float PhysicsObject::getAx()
{
	return ax;
}

float PhysicsObject::getAy()
{
	return ay;
}

float PhysicsObject::getVx()
{
	return vx;
}

float PhysicsObject::getVy()
{
	return vy;
}

void PhysicsObject::setAx(float ax)
{
	this->ax = ax;
}

void PhysicsObject::setAy(float ay)
{
	this->ay = ay;
}

void PhysicsObject::setVx(float vx)
{
	this->vx = vx;
}

void PhysicsObject::setVy(float vy)
{
	this->vy = vy;
}

bool PhysicsObject::getPhysicsEnable()
{
	return physicsEnable;
}

void PhysicsObject::setPhysicsEnable(bool physicsEnable)
{
	this->physicsEnable = physicsEnable;
}
