/*
  ==============================================================================

    EnvelopeSegment.cpp
    Created: 26 Aug 2025 12:34:10pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#include "EnvelopeSegment.h"

EnvelopeSegment::EnvelopeSegment(EnvelopeSegmentType type, float start, float end, float duration)
: start(start), end(end), duration(duration), type(type)
{}

EnvelopeSegment::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous, float end, float duration)
: start(previous.end), end(end), duration(duration), type(type)
{}

EnvelopeSegment::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous)
: start(previous.end), end(previous.end), duration(0.f), type(type)
{}

EnvelopeSegment::EnvelopeSegment(EnvelopeSegmentType type, float duration)
: start(0.f), end(0.f), duration(duration), type(type)
{}
