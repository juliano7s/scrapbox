#pragma once

#include <vector>

#include "BoxysBeing.h"

class BeingCollision
{
    public:
        BeingCollision();
        BeingCollision(BoxysBeing &beingA, BoxysBeing &beingB);
        ~BeingCollision();

    private:
        BoxysBeing *mpBeingA;
        BoxysBeing *mpBeingB;
};

class PhyEngine
{
    public:
        PhyEngine(void);
        ~PhyEngine(void);

    private:
        std::vector<BeingCollision*> mBeingCollisionQueue;
        
};




