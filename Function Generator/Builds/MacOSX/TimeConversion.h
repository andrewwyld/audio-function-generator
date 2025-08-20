//
//  TimeConversion.h
//  Function Generator
//
//  Created by Andrew Wyld on 20/08/2025.
//  Copyright © 2025 Music Research Unit. All rights reserved.
//

class TimeConversion
{
public:
    void prepareToPlay(double sampleRate, int samplesPerBlock);
    double timeOf(int sample, int startSample = 0);
private:
    double sampleRate;
    int expectedSamplesPerBlock;
};
