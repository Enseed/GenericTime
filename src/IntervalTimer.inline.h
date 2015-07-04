/*******************************************************************************
 Copyright 2008 Enseed inc.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.

 Author: Gaspard Petit
*******************************************************************************/
//==============================================================================
//	EXTERNAL DECLARATIONS
//==============================================================================
#include "../IntervalTimer.h"

#ifdef GENERIC_LAYER_NAMESPACE
namespace GENERIC_LAYER_NAMESPACE {
#endif

//==============================================================================
//	CLASS IntervalTimer
//==============================================================================
template <class TIMER>
IntervalTimer<TIMER>::IntervalTimer()
:
	mStartTime(TIMER::stamp())
{}

//------------------------------------------------------------------------------
//
template <class TIMER>
IntervalTimer<TIMER>::~IntervalTimer()
{}

//------------------------------------------------------------------------------
//
template <class TIMER>
IntervalTimer<TIMER>::IntervalTimer(const IntervalTimer& rhs)
:
	mStartTime(rhs.mStartTime)
{}

//------------------------------------------------------------------------------
//
template <class TIMER>
IntervalTimer<TIMER>& IntervalTimer<TIMER>::operator=(const IntervalTimer<TIMER> &rhs)
{
	mStartTime = rhs.mStartTime;
	return *this;
}

//------------------------------------------------------------------------------
//
template <class TIMER>
void IntervalTimer<TIMER>::start()
{
	mStartTime = TIMER::stamp();
}

//------------------------------------------------------------------------------
//
template <class TIMER>
Time IntervalTimer<TIMER>::stop()
{
	return TIMER::elapsed(mStartTime, TIMER::stamp());
}

#ifdef GENERIC_LAYER_NAMESPACE
}
#endif