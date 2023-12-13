#ifndef PHYSICS_H
#define PHYSICS_H

void PhysicsEngine();
void ViewPhysicsMain();
void SimulateGravity(float gravity);
void SimulateBouncing(float gravity, float restitutionCoefficient);

#endif
