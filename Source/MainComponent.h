#pragma once

/*
  ==============================================================================

   Juce Simple Menu Example
    Created: 15 Feb 2023
    Author:  Gene Brown

  ==============================================================================
*/


#include <JuceHeader.h>

enum GridType // can be used to set the grid type size.. not used in this example
{
    bar = 1,half,quarter,eighth,sixteenth,thirtysecond,rest,sixtyfourth
};



/**
 * This signature is used to set the boolean flag for the menu item to show that this item is the currently selected item.
   (the check mark).   It works by using an operator overload to see if one signature is equal to another.  If it is, then
   the menu item is checked.  If not, then it is not checked.

   The toString method is used to convert the signature to a string that can be displayed in the menu item.

   You could use this technique for any menu item that would need to have a check box selected shown.

   many thanks to @daniel and @Normalised on the JUCE Discord server for helping me with this.
 */
struct Signature
{
   
	//Signature(int n, int d) : num(n), den(d) {}
	int num, den;
	bool operator==( const Signature& other) const { return num == other.num && den == other.den; }
	juce::String toString() const { return juce::String(num) + "/" + juce::String(den); }
};

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
    int getGridType(int gridType);
    void setGridType(int gridType);

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

    /* the num and dem integers are used to populate the Signature current field in the the getMenuForIndex method*/
    int num = 4;
    int dem = 4;

    Signature current{ num,dem }; //default
    //Signature sig;
    std::unique_ptr<MenuBarComponent> menuBar;

    /**
     * The Signatures vector is initialized here with the target time signatures to test against for the Signatures struct.
     */
    std::vector<Signature> signatures = { {2,4}, {3, 4}, {4, 4}, {6, 8}, {8, 8}, {9, 8}, {12, 8} };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
