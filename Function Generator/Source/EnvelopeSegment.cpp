/*
  ==============================================================================

    EnvelopeSegment.cpp
    Created: 26 Aug 2025 12:34:10pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#include "EnvelopeSegment.h"

// full values constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, T start, T end, T duration, T startTime):
startValue(start),
endValue(end),
duration(duration),
type(type),
startTime(startTime),
endTime(startTime + duration),
fixedTimeline(type != SUSTAIN)
{}

// initial delay constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, T duration, T startTime):
startValue(0.f),
endValue(0.f),
duration(duration),
type(type),
startTime(startTime),
endTime(startTime + duration),
fixedTimeline(type != SUSTAIN)
{}

// sequence constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous, T end, T duration):
startValue(previous.endValue),
endValue(end),
duration(duration),
type(type),
startTime(previous.fixedTimeline? previous.endTime : 0.f),
endTime(previous.fixedTimeline? previous.endTime + duration : 0.f),
fixedTimeline(previous.fixedTimeline && type != SUSTAIN)
{}

// sustain constructor
template <typename T> EnvelopeSegment<T>::EnvelopeSegment(EnvelopeSegmentType type, EnvelopeSegment previous):
startValue(previous.endValue),
endValue(previous.endValue),
duration(0.f), type(type),
startTime(previous.fixedTimeline? previous.endTime : 0.f),
endTime(previous.fixedTimeline? previous.endTime + duration : 0.f),
fixedTimeline(previous.fixedTimeline && type != SUSTAIN)
{}
