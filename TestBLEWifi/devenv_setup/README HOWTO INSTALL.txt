- import project Platformio
	- board: esp32dev

- import libraries into Platformio
	- TFT_eSPI - search in libraries "TFT_eSPI"

- setup screen definitions
	- in .pio\libdeps\esp32dev\TFT_eSPI\User_Setups copy "T10_V20_1C8.h"
	- change in "User_Setup_Select.h" comment out //#include <User_Setup.h>
									  set #include <User_Setups/T10_V20_1C8.h> 
	- OR
	- copy just .pio folder in this directory over everything in project root