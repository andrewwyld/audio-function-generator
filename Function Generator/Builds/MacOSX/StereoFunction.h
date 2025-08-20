//
//  StereoFunction.h
//  Function Generator
//
//  Created by Andrew Wyld on 20/08/2025.
//  Copyright © 2025 Music Research Unit. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
#include "TimeConversion.h"

template <typename T> class StereoFunction: public TimeConversion
{
public:
    T left(int sample);
    T right(int sample);

protected:
    virtual void __preprocess(int sample) = 0;
    virtual T __left(int sample) = 0;
    virtual T __right(int sample) = 0;
    
private:
    bool __preprocessed = false;
    void preprocess(int sample);
};
