/*
  ==============================================================================

    EnvelopeSegment.h
    Created: 26 Aug 2025 12:34:10pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#pragma once

#include "TimeConversion.h"

enum EnvelopeSegmentType
{
    LINEAR,
    EXPONENTIAL,
    DELAY,
    SUSTAIN
};

template <typename T> class EnvelopeSegment: public TimeConversion
{
    public:
    EnvelopeSegment(EnvelopeSegmentType type, T startValue, T endValue, T duration, T startTime = 0.f);
    EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous, T end, T duration);
    EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous); // for sustain
    EnvelopeSegment(EnvelopeSegmentType type, T duration, T startTime = 0.f); // for delay
    
    bool isComplete(int sample);
    
    private:
    bool fixedTimeline;
    T startTime; // undefined if this segment occurs after a sustain segment
    T endTime; // undefined if this segment is, or occurs after, a sustain segment
    const T startValue;
    const T endValue;
    const T duration;
    const EnvelopeSegmentType type;
};
