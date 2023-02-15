#pragma once

/*
  ==============================================================================

   Juce Simple Menu Example
    Created: 15 Feb 2023
    Author:  Gene Brown

  ==============================================================================
*/


#include <JuceHeader.h>

/**
 * You must also include the MenuBarModel so that the constructor will call the override method getMenuBarNames to set up the menu.
 */
class MainComponent  : public juce::Component,
                       public juce::MenuBarModel
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    /**
     *  These three methods are required by the MenuBarModel class. The getMenuBarNames method is
     *  used to return the names of the menus that will appear at the top of the screen. This method is automatically executed by
     *  the MenuBarComponent class when it is created. The getMenuForIndex method is used to return the menu items that will appear
     *  in the menu that is selected by the user. The menuItemSelected method is used to handle the user's selection of a menu item.
     */
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& /*menuName*/) override;
    void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;


private:
    //==============================================================================
    
    /**
     * The MenuBarComponent class is used to create a menu bar at the top of the screen. The MenuBarComponent class is a subclass of
     * the Component class, so it can be added to the component hierarchy like any other component. The MenuBarComponent class
     * requires a MenuBarModel object to be passed to its constructor. The MenuBarModel class is an abstract base class that is used
     * to define the methods that are required to create a menu bar. The MenuBarModel class is used to define the names of the menus
     * that will appear at the top of the screen, the menu items that will appear in each menu, and the actions that will be
     * performed when the user selects a menu item. The MenuBarComponent class will automatically call the methods of the
     * MenuBarModel object that is passed to its constructor to determine the names of the menus, the menu items, and the actions
     * that will be performed when the user selects a menu item.
    */
    std::unique_ptr<MenuBarComponent> menuBar;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
