/*
  ==============================================================================

    StereoSawtooth.cpp
    Created: 27 Aug 2025 4:44:11pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#include "StereoSawtooth.h"

template <typename T> StereoSawtooth<T>::StereoSawtooth(const juce::MidiMessage& message):
noteNumber(message.getNoteNumber()),
noteFrequency(juce::MidiMessage::getMidiNoteInHertz(message.getNoteNumber())),
envelope(new Envelope<T>(DADSR, EXPONENTIAL, {10.f, 0.f, 1.f, 0.f}))
{}

template <typename T> void StereoSawtooth<T>::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    TimeConversion::prepareToPlay(sampleRate, samplesPerBlock);
    envelope->prepareToPlay(sampleRate, samplesPerBlock);
}

template <typename T> void StereoSawtooth<T>::__preprocess(int sample)
{
    
}

template <typename T> T StereoSawtooth<T>::__left(int sample)
{
}

template <typename T> T StereoSawtooth<T>::__right(int sample)
{
}

template <typename T> double StereoSawtooth<T>::__frequency(int sample)
{
    return noteFrequency * envelope->process(sample);
}
