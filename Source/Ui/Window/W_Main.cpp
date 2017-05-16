/*
  ==============================================================================

    W_Main.cpp
    Created: 14 May 2017 12:18:28pm
    Author:  Robin

  ==============================================================================
*/

#include "W_Main.h"

W_Main::W_Main(String name)
	: DocumentWindow(name,
		Colours::lightgrey,
		DocumentWindow::allButtons)
{
	setUsingNativeTitleBar(true);
	setContentOwned(new MainC_Main(), true);

	centreWithSize(getWidth(), getHeight());
	setVisible(true);

	setResizable(true, true);
}