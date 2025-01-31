# organized  
## Goal of the project  
Code a shell based, data storage using linked lists  
## Flags  
Once the program is running you can use multiple commands :
- **`ADD`** : add elements to the list, they have to be formated like this <'type'> <'name'>  
type must be one of : [WIRE, ACTUATOR, DEVICE, PROCESSOR, SENSOR]  
example : **`ADD WIRE Bexample, ACTUATOR Cexample, DEVICE Aexample`**
  
- **`DISP`** : display the content of the list
  
- **`SORT`** : Sort the list using a merge sort (you can sort by TYPE, NAME, ID and use -r for reverse)  
example : **`SORT NAME -r`** Cexample->Bexample->Aexample
  
- **`DEL`** : delete elements of the list using their ID (ID = xth - 1 element added to the list)  
example : **`DEL 1, 2`** will delete ACTUATOR Cexample and DEVICE Aexample
  
- **`exit`** : ends the program 
## Usage
use **`make`** to create the **`organized`** exectuable  
**`./organized`** to run the shell
