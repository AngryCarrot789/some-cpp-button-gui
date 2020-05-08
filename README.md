# some-cpp-button-gui
my crap attempt at making a gui in c++. got a button to work but cant create a clicked event cus of stupid memory leaks ruining everything smh

## things
uses the win32 way of creating buttons and stuff; CreateWindow(L"BUTTON....). but clicking it doesnt do anything. 
though this project does have a nice event class which i made. it can be used for callbacks. 
tho they are probably the source of the memory leaks in the first place because unused void pointer xddddddddd
