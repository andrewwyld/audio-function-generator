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

class Envelope
{
public:
    Envelope(std::vector<EnvelopeSegment>& segments);
    Envelope(EnvelopeType type, EnvelopeSegmentType segType, float* values);
    
private:
    const std::vector<EnvelopeSegment>& segments;
    static const std::vector<EnvelopeSegment>* constructFrom(EnvelopeType type, EnvelopeSegmentType segType, float* values);

    static const std::vector<EnvelopeSegment>* constructAR(std::vector<EnvelopeSegment>* output, EnvelopeSegmentType type, float* values);
    static const std::vector<EnvelopeSegment>* constructADSR(std::vector<EnvelopeSegment>* output, EnvelopeSegmentType type, float* values);
    static const std::vector<EnvelopeSegment>* constructDADSR(std::vector<EnvelopeSegment>* output, EnvelopeSegmentType type, float* values);
};
