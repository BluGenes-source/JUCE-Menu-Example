#pragma once

#include <JuceHeader.h>

//==============================================================================
class MainComponent  : public juce::Component,
                       private juce::MenuBarModel
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& /*menuName*/) override;
    void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;


private:
    //==============================================================================
    
    std::unique_ptr<MenuBarComponent> menuBar;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
