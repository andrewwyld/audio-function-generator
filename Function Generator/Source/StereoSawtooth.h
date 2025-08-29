/*
  ==============================================================================

    StereoSawtooth.h
    Created: 27 Aug 2025 4:44:11pm
    Author:  Andrew Wyld

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "StereoFunction.h"
#include "Envelope.h"

template <typename T> class StereoSawtooth: public StereoFunction<T>
{
    public:
    StereoSawtooth(const juce::MidiMessage& message);
    
    // routes method to this class, envelopes, modulators
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    
    protected:
    virtual void __preprocess(int sample) override;
    virtual T __left(int sample) override;
    virtual T __right(int sample) override;

    private:
    double __frequency(int sample);
    const int noteNumber;
    const double noteFrequency;
    
    const Envelope<T>* envelope;
    
};
