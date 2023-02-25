#include "MainComponent.h"

//==============================================================================









MainComponent::MainComponent() 
{
	
	
	
	menuBar.reset(new MenuBarComponent(this));
	addAndMakeVisible(menuBar.get());

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
	menuBar->setBounds(0, 0, getWidth(), 25);
}

juce::StringArray MainComponent::getMenuBarNames()
{
	/** The names in the list will correspond to the row position in the array, 01,02,03 etc. */
    return { "File", "Edit", "View", "Signature"};
}

juce::PopupMenu MainComponent::getMenuForIndex(int topLevelMenuIndex, const String& /*menuName*/)
{
	PopupMenu menu;

	if (topLevelMenuIndex == 0)
	{
		menu.addItem(1, "New");
		menu.addItem(2, "Open");
		menu.addSeparator();
		menu.addItem(3, "Save");
		menu.addItem(4, "Save As...");
		menu.addSeparator();
		menu.addItem(5, "Exit");
	}
	else if (topLevelMenuIndex == 1)
	{
		menu.addItem(1, "Undo");
		menu.addItem(2, "Redo");
		menu.addSeparator();
		menu.addItem(3, "Cut");
		menu.addItem(4, "Copy");
		menu.addItem(5, "Paste");
	}
	else if (topLevelMenuIndex == 2)
	{
		menu.addItem(1, "Zoom In");
		menu.addItem(2, "Zoom Out");
		menu.addSeparator();
		menu.addItem(3, "Full Screen");
	}
	else if (topLevelMenuIndex == 3)
	{
		int index = 1;
	//	auto makeItem = [&](const Signature& sig)
	//	for (const auto& sig : signatures)
	//		makeItem(sig);
		
		
		menu.addItem(1, "2/4");
		menu.addItem(2, "4/4", true,true);
		menu.addItem(3, "6/8");
	}


	return menu;
}

void MainComponent::menuItemSelected(int menuItemID, int topLevelMenuIndex)
{
	if (topLevelMenuIndex == 0 && menuItemID == 5)
	{
		JUCEApplication::getInstance()->systemRequestedQuit();
	}
	//else if (topLevelMenuIndex == 1 && menuItemID == 1) {}

}

Signature::Signature()
{

}
