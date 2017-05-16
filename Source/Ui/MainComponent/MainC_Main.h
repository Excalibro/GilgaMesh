/*
  ==============================================================================

    MainC_Main.h
    Created: 14 May 2017 12:25:46pm
    Author:  Robin

  ==============================================================================
*/

#ifndef MAINC_MAIN_H_INCLUDED
#define MAINC_MAIN_H_INCLUDED


#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../MenuComponent/MenuC_Viewport_3D.h"


//==============================================================================
/*
This component lives inside our window, and this is where you should put all
your controls and content.
*/
class MainC_Main : public Component, public KeyListener
{
public:
	//==============================================================================
	MainC_Main();
	~MainC_Main();

	void paint(Graphics&) override;
	void resized() override;

	virtual bool keyPressed(const KeyPress & key,	Component * originatingComponent) override;

	bool m_leftShift;

private:

	MenuC_Viewport_3D m_viewPort;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainC_Main)
};


#endif  // MAINC_MAIN_H_INCLUDED
