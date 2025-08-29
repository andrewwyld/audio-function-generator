/*
  ==============================================================================

    EnvelopeSegment.cpp
    Created: 26 Aug 2025 12:34:10pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#include "EnvelopeSegment.h"

template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, T start, T end, T duration)
: start(start), end(end), duration(duration), type(type)
{}

template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous, T end, T duration)
: start(previous.end), end(end), duration(duration), type(type)
{}

template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous)
: start(previous.end), end(previous.end), duration(0.f), type(type)
{}

template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, T duration)
: start(0.f), end(0.f), duration(duration), type(type)
{}
