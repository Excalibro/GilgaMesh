/*
  ==============================================================================

    MainC_Main.cpp
    Created: 14 May 2017 12:25:46pm
    Author:  Robin

  ==============================================================================
*/

#include "MainC_Main.h"
#include "../../Storage/S_Input.h"

MainC_Main::MainC_Main()
{
	setSize(600, 400);
	m_viewPort.setBounds(0,0, getWidth(), getHeight());
	addAndMakeVisible(m_viewPort);
	m_leftShift = false;
	addKeyListener(this);
	setWantsKeyboardFocus(true);
}

MainC_Main::~MainC_Main()
{
}

void MainC_Main::paint(Graphics & g)
{

}

void MainC_Main::resized()
{
	m_viewPort.setBounds(0, 0, getWidth(), getHeight());
}

bool MainC_Main::keyPressed(const KeyPress & key, Component * originatingComponent)
{
	if(key == KeyPress::spaceKey)
	{
	m_leftShift = true;
	}
	return false;
}
