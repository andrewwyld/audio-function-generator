//
//  StereoFunction.cpp
//  Function Generator
//
//  Created by Andrew Wyld on 20/08/2025.
//  Copyright © 2025 Music Research Unit. All rights reserved.
//

#include "StereoFunction.h"

template <typename T> void StereoFunction<T>::preprocess(int sample)
{
    if (!__preprocessed)
    {
        __preprocess(sample);
        __preprocessed = true;
    }
}

template <typename T> T StereoFunction<T>::left(int sample)
{
    preprocess(sample);
    return __left(sample);
}

template <typename T> T StereoFunction<T>::right(int sample)
{
    preprocess(sample);
    return __right(sample);
}
