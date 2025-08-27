/*
  ==============================================================================

    StereoSawtooth.h
    Created: 27 Aug 2025 4:44:11pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#pragma once

#include "StereoFunction.h"

template <typename T> class StereoSawtooth: public StereoFunction<T>
{
    public:
    
    protected:
    virtual void __preprocess(int sample) override;
    virtual T __left(int sample) override;
    virtual T __right(int sample) override;

    private:
    float __frequency(int sample);
};
