//
//  StereoVoiceEnsemble.h
//  Function Generator
//
//  Created by Andrew Wyld on 20/08/2025.
//  Copyright © 2025 Music Research Unit. All rights reserved.
//

#include "StereoFunction.h"

template <typename T> class StereoVoiceEnsemble: public StereoFunction<T>
{
public:
    StereoVoiceEnsemble();
    
protected:
    virtual void __preprocess(int sample);
    virtual T __left(int sample);
    virtual T __right(int sample);

    
private:
    std::vector<StereoFunction<T>> voices;
    
    T leftSum = 0;
    T rightSum = 0;
};
