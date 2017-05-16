/*
  ==============================================================================

    W_Main.h
    Created: 14 May 2017 12:18:28pm
    Author:  Robin

  ==============================================================================
*/


#ifndef W_MAIN_H
#define W_MAIN_H

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../MainComponent/MainC_Main.h"

class W_Main : public DocumentWindow
{
public:
	W_Main(String name);

	void closeButtonPressed() override
	{
		JUCEApplication::getInstance()->systemRequestedQuit();
	}

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(W_Main)
};



#endif  // W_MAIN_H_INCLUDED
