/*
  ==============================================================================

    EnvelopeSegment.h
    Created: 26 Aug 2025 12:34:10pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#pragma once

enum EnvelopeSegmentType
{
    LINEAR,
    EXPONENTIAL,
    DELAY,
    SUSTAIN
};

template <typename T> class EnvelopeSegment
{
    public:
    EnvelopeSegment(EnvelopeSegmentType type, T start, T end, T duration);
    EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous, T end, T duration);
    EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous); // for sustain
    EnvelopeSegment(EnvelopeSegmentType type, T duration); // for delay

    private:
    const T start;
    const T end;
    const T duration;
    const EnvelopeSegmentType type ;
};
