/*
  ==============================================================================

    Envelope.cpp
    Created: 26 Aug 2025 12:30:44pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Envelope.h"

//==============================================================================

Envelope::Envelope(std::vector<EnvelopeSegment>& segments):
segments(segments)
{}

Envelope::Envelope(EnvelopeType type, EnvelopeSegmentType segType, float* values):
segments(*constructFrom(type, segType, values))
{}

const std::vector<EnvelopeSegment>* Envelope::constructFrom(EnvelopeType type, EnvelopeSegmentType segType, float* values)
{
    std::vector<EnvelopeSegment>* output = new std::vector<EnvelopeSegment>();
    
    switch (type)
    {
        case AR:
            return constructAR(output, segType, values);
                        
        case ADSR:
            return constructADSR(output, segType, values);

        case DADSR:
            return constructDADSR(output, segType, values);
    }
}

static const std::vector<EnvelopeSegment>* constructAR(std::vector<EnvelopeSegment>* output, EnvelopeSegmentType type, float* values)
{
    auto& attack = output->emplace_back(type, LOWEST, HIGHEST, values[0]);
    auto& sustain = output->emplace_back(SUSTAIN, attack);
    output->emplace_back(type, sustain, LOWEST, values[1]);
    return output;
}

static const std::vector<EnvelopeSegment>* constructADSR(std::vector<EnvelopeSegment>* output, EnvelopeSegmentType type, float* values)
{
    auto& attack = output->emplace_back(type, LOWEST, HIGHEST, values[0]);
    auto& decay = output->emplace_back(type, attack, values[2], values[1]); // DECAY duration value comes before SUSTAIN value
    auto& sustain = output->emplace_back(SUSTAIN, decay);
    output->emplace_back(type, sustain, LOWEST, values[3]);
    return output;
}

static const std::vector<EnvelopeSegment>* constructDADSR(std::vector<EnvelopeSegment>* output, EnvelopeSegmentType type, float* values)
{
    auto& delay = output->emplace_back(DELAY, values[0]);
    auto& attack = output->emplace_back(type, delay, HIGHEST, values[1]);
    auto& decay = output->emplace_back(type, attack, values[3], values[4]); // DECAY duration value comes before SUSTAIN value
    auto& sustain = output->emplace_back(SUSTAIN, decay);
    output->emplace_back(type, sustain, LOWEST, values[5]);
    return output;
}
