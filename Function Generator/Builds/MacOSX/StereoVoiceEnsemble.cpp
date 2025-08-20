//
//  StereoVoiceEnsemble.cpp
//  Function Generator
//
//  Created by Andrew Wyld on 20/08/2025.
//  Copyright © 2025 Music Research Unit. All rights reserved.
//

#include "StereoVoiceEnsemble.h"

template <typename T> StereoVoiceEnsemble<T>::StereoVoiceEnsemble():
voices(new std::vector<StereoFunction<T>>())
{};

template <typename T> T StereoVoiceEnsemble<T>::__preprocess(<#int sample#>)
{
    for (StereoFunction voice: voices)
    {
        leftSum += voice.left();
        rightSum += voice.right();
    }
}

template <typename T> T StereoVoiceEnsemble<T>::__left(<#int sample#>)
{
    return leftSum;
}

template <typename T> T StereoVoiceEnsemble<T>::__right(<#int sample#>)
{
    return rightSum;
}
