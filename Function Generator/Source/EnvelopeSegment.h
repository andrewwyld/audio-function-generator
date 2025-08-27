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

class EnvelopeSegment
{
    public:
    EnvelopeSegment(EnvelopeSegmentType type, float start, float end, float duration);
    EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous, float end, float duration);
    EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous); // for sustain
    EnvelopeSegment(EnvelopeSegmentType type, float duration); // for delay

    private:
    const float start;
    const float end;
    const float duration;
    const EnvelopeSegmentType type ;
};
