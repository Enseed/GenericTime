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
#ifndef __GENERIC_TIME_TIMEPROFILER__
#define __GENERIC_TIME_TIMEPROFILER__

//==============================================================================
//	EXTERNAL DECLARATIONS
//==============================================================================
#include "Time.h"
#include "IntervalTimer.h"

#ifdef GENERIC_LAYER_NAMESPACE
namespace GENERIC_LAYER_NAMESPACE {
#endif

//==============================================================================
//	CLASS TimeProfiler
//==============================================================================
template<class _TIMER>
class TimeProfiler
{
public:
	TimeProfiler();
	TimeProfiler(const TimeProfiler &rhs);
	~TimeProfiler();
	TimeProfiler& operator=(const TimeProfiler &rhs);
	
	void start();
	void pause();
	void resume();
	void endCycle();
	void stop();
	
	Time averageTime();
	Time totalTime();
	int cycles();
	
private:
	IntervalTimer<_TIMER>	mTimer;
	bool					mIsCounting;
	Time					mCycleTime;
	Time					mTotalTime;
	int						mCycles;
};

#ifdef GENERIC_LAYER_NAMESPACE
}
#endif

#endif // __GENERIC_TIME_TIMEPROFILER__