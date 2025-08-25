//
//  MonoFunction.h
//  Function Generator
//
//  Created by Andrew Wyld on 20/08/2025.
//  Copyright © 2025 Music Research Unit. All rights reserved.
//

#pragma once

template <typename T> class MonoFunction: public TimeConversion
{
public:
    virtual T mono(int sample);
};
