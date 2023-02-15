# Menu Example

An example showing how to implement a simple menu system in JUCE.

## Introduction

This example shows how to implement a simple menu system in JUCE. This is a simpler example than the JUCE demo application, which shows how to implement a more complex menu system.

## Building the Example

Open the JUCER file and press the "Save and Open in IDE" button to build the project.

## Key things to note

The `MainComponent` class implements the `MenuBarModel` interface, which is used to provide the menu items to the application. The `getMenuBarNames()` method returns the names of the menus, and the `getMenuForIndex()` method returns the items for each menu. 
You must use a std::unique_ptr for the MenuBarComponent and include the MenubarModel in the contructor of the Class that is using it. This will automatically call the method to populate the menu bar names. The `menuItemSelected()` method is called when the user selects a menu item.

```cpp
std::unique_ptr<MenuBarComponent> menuBar;
```

## Overrides

These are the three methods that must be overridden:

```cpp
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& /*menuName*/) override;
    void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;
```

Once the object is created, the menu bar will be populated with the names returned by `getMenuBarNames()`. When the user selects a menu item, the `menuItemSelected()` method will be called with the ID of the selected item and the index of the menu that it was in.
