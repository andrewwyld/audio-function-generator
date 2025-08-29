/*
  ==============================================================================

    Envelope.h
    Created: 26 Aug 2025 12:30:44pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#pragma once

#include <vector>
#include <JuceHeader.h>
#include "EnvelopeSegment.h"
#include "TimeConversion.h"

#define HIGHEST 1.f
#define LOWEST 0.f

//==============================================================================
/*
*/
enum EnvelopeType
{
    AR, // attack-release
    ADSR, // attack-decay-sustain-release
    DADSR, // delay-attack-decay-sustain-release
};

template <typename T> class Envelope: public TimeConversion
{
public:
    Envelope(std::vector<EnvelopeSegment<T>>* segments);
    Envelope(EnvelopeType type, EnvelopeSegmentType segType, T* values);
    
    T process(int sample);
    
    bool isComplete();
    
private:
    const std::vector<EnvelopeSegment<T>>* segments;
    static const std::vector<EnvelopeSegment<T>>* constructFrom(EnvelopeType type, EnvelopeSegmentType segType, T* values);

    static const std::vector<EnvelopeSegment<T>>* constructAR(std::vector<EnvelopeSegment<T>>* output, EnvelopeSegmentType type, T* values);
    static const std::vector<EnvelopeSegment<T>>* constructADSR(std::vector<EnvelopeSegment<T>>* output, EnvelopeSegmentType type, T* values);
    static const std::vector<EnvelopeSegment<T>>* constructDADSR(std::vector<EnvelopeSegment<T>>* output, EnvelopeSegmentType type, T* values);
    
    int currentSegmentIdx;
    
    bool __isComplete;
};
