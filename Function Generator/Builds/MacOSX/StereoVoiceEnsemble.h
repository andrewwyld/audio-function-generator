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
    
private:
    std::vector<StereoFunction<T>> voices;
    
    T leftSum = 0;
    T rightSum = 0;
}
