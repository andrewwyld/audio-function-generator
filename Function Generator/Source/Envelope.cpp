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

template <typename T> Envelope<T>::Envelope(std::vector<EnvelopeSegment<T>>& segments):
segments(segments)
{}

template <typename T> Envelope<T>::Envelope(EnvelopeType type, EnvelopeSegmentType segType, T* values):
segments(*constructFrom(type, segType, values))
{}

template <typename T> const std::vector<EnvelopeSegment<T>>* Envelope<T>::constructFrom(EnvelopeType type, EnvelopeSegmentType segType, T* values)
{
    std::vector<EnvelopeSegment<T>>* output = new std::vector<EnvelopeSegment<T>>();
    
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

template <typename T> const std::vector<EnvelopeSegment<T>>* Envelope<T>::constructAR(std::vector<EnvelopeSegment<T>>* output, EnvelopeSegmentType type, T* values)
{
    auto& attack = output->emplace_back(type, LOWEST, HIGHEST, values[0]);
    auto& sustain = output->emplace_back(SUSTAIN, attack);
    output->emplace_back(type, sustain, LOWEST, values[1]);
    return output;
}

template <typename T> const std::vector<EnvelopeSegment<T>>* Envelope<T>::constructADSR(std::vector<EnvelopeSegment<T>>* output, EnvelopeSegmentType type, T* values)
{
    auto& attack = output->emplace_back(type, LOWEST, HIGHEST, values[0]);
    auto& decay = output->emplace_back(type, attack, values[2], values[1]); // DECAY duration value comes before SUSTAIN value
    auto& sustain = output->emplace_back(SUSTAIN, decay);
    output->emplace_back(type, sustain, LOWEST, values[3]);
    return output;
}

template <typename T> const std::vector<EnvelopeSegment<T>>* Envelope<T>::constructDADSR(std::vector<EnvelopeSegment<T>>* output, EnvelopeSegmentType type, T* values)
{
    auto& delay = output->emplace_back(DELAY, values[0]);
    auto& attack = output->emplace_back(type, delay, HIGHEST, values[1]);
    auto& decay = output->emplace_back(type, attack, values[3], values[4]); // DECAY duration value comes before SUSTAIN value
    auto& sustain = output->emplace_back(SUSTAIN, decay);
    output->emplace_back(type, sustain, LOWEST, values[5]);
    return output;
}
