/*
  ==============================================================================

    EnvelopeSegment.cpp
    Created: 26 Aug 2025 12:34:10pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#include "EnvelopeSegment.h"

// full values constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, T startValue, T endValue, T duration, T startTime):
type(type),
startValue(startValue),
endValue(endValue),
duration(duration),
startTime(startTime),
endTime(startTime + duration),
fixedTimeline(type != SUSTAIN)
{}

// initial delay constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, T duration, T startTime):
type(type),
startValue(0.f),
endValue(0.f),
duration(duration),
startTime(startTime),
endTime(startTime + duration),
fixedTimeline(type != SUSTAIN)
{}

// sequence constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous, T endValue, T duration):
type(type),
startValue(previous.endValue),
endValue(endValue),
duration(duration),
startTime(previous.fixedTimeline? previous.endTime : 0.f),
endTime(previous.fixedTimeline? previous.endTime + duration : 0.f),
fixedTimeline(previous.fixedTimeline && type != SUSTAIN)
{}

// sustain constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous):
type(type),
startValue(previous.endValue),
endValue(previous.endValue),
duration(0.f),
startTime(previous.fixedTimeline? previous.endTime : 0.f),
endTime(previous.fixedTimeline? previous.endTime + duration : 0.f),
fixedTimeline(previous.fixedTimeline && type != SUSTAIN)
{}

template <typename T> bool EnvelopeSegment<T>::isComplete(int sample)
{
    return timeOf(sample) > endTime;
}
