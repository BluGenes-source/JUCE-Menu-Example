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
		
		Signature current{ num, dem};

		int index = 1;
			for (const auto& sig : signatures)

		{
			menu.addItem(index++, sig.toString(), true, sig == current);
		}

	// above code replaces code like below..	
	//	menu.addItem(1, "2/4");
	//	menu.addItem(2, "4/4", true,true);
	//	menu.addItem(3, "6/8");
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
	else if (topLevelMenuIndex == 3 && menuItemID == 1)
	{
		num = 2;
		dem = 4;
	}
	else if (topLevelMenuIndex == 3 && menuItemID == 2)
	{
		num = 3;
		dem = 4;
	}
	else if (topLevelMenuIndex == 3 && menuItemID == 3)
	{
		num = 4;
		dem = 4;
	}
	else if (topLevelMenuIndex == 3 && menuItemID == 4)
	{
		num = 6;
		dem = 8;
	}
	else if (topLevelMenuIndex == 3 && menuItemID == 5)
	{
		num = 8;
		dem = 8;
	}
	else if (topLevelMenuIndex == 3 && menuItemID == 6)
	{
		num = 9;
		dem = 8;
	}
	else if (topLevelMenuIndex == 3 && menuItemID == 7)
	{
		num = 12;
		dem = 8;
	}
}

int MainComponent::getGridType(int gridType)
{
	switch (gridType)
	{
	case bar:
		// do something
		break;	
	case half:
		// do something
		break;
	
	case quarter:
			// do something
		break;
    case eighth:
	       // do something
        break;

	case sixteenth:
		  // do something
	    break;	
    case thirtysecond:
	      // do something
       break;
	case sixtyfourth:
		 // do something
	  break;

	default:
		break;
	}
	return gridType;
}

void MainComponent::setGridType(int gridType)
{
	// do something
}
