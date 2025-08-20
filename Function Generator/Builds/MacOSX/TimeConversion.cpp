//
//  TimeConversion.cpp
//  Function Generator
//
//  Created by Andrew Wyld on 20/08/2025.
//  Copyright © 2025 Music Research Unit. All rights reserved.
//

#include "TimeConversion.h"

void TimeConversion::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    this->sampleRate = sampleRate;
    this->expectedSamplesPerBlock = samplesPerBlock;
}

double TimeConversion::timeOf(int sample, int startSample)
{
    return (double) (sample - startSample) / sampleRate;
}

