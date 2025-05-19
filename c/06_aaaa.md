# Data Structures
## Linked List
─┌│┐└┘├┤┬┴┼═║╒╓╔╕╖╗╘╙╚╛╜╝╞╟╠╡╢╣╤╥╦╧╨╩╫╬▀▄█▌▐░▒▓

- **Initial State**
```c
    HEAD             TAIL
╔══════════╗     ╔══════════╗
║  Node 0  ║   ┌─╢  Node 1  ║
╟──────────╢   │ ╟──────────╢  
║ data = 4 ║   │ ║ data = 7 ║    ┌────┐
║ nextNode─╫───┘ ║ nextNode─╫────┤NULL│
╚══════════╝     ╚══════════╝    └────┘
```
- **Append Node** `set` `value = 3`
```c
    HEAD                              TAIL
╔══════════╗     ╔══════════╗     ╔══════════╗      
║  Node 0  ║   ┌─╢  Node 1  ║   ┌─║  Node 2  ║      
╟──────────╢   │ ╟──────────╢   │ ╟──────────╢   
║ data = 4 ║   │ ║ data = 7 ║   │ ║ data = 3 ║    ┌────┐
║ nextNode─╫───┘ ║ nextNode─╫───┘ ║ nextNode─╫────┤NULL│
╚══════════╝     ╚══════════╝     ╚══════════╝    └────┘
```
- **Insert Node After** `where` `data == 7` `and` `set` `value = 8`
```c
    HEAD                                               TAIL
╔══════════╗     ╔══════════╗     ╔══════════╗     ╔══════════╗      
║  Node 0  ║   ┌─╢  Node 1  ║   ┌─║  Node 3  ║   ┌─║  Node 2  ║   
╟──────────╢   │ ╟──────────╢   │ ╟──────────╢   │ ╟──────────╢  
║ data = 4 ║   │ ║ data = 7 ║   │ ║ data = 8 ║   │ ║ data = 3 ║    ┌────┐
║ nextNode─╫───┘ ║ nextNode─╫───┘ ║ nextNode─╫───┘ ║ nextNode─╫────┤NULL│
╚══════════╝     ╚══════════╝     ╚══════════╝     ╚══════════╝    └────┘
```
- **Delete Node** `where` `value == 4`
```c
    HEAD                              TAIL
╔══════════╗     ╔══════════╗     ╔══════════╗      
║  Node 1  ║   ┌─╢  Node 3  ║   ┌─║  Node 2  ║     
╟──────────╢   │ ╟──────────╢   │ ╟──────────╢   
║ data = 7 ║   │ ║ data = 8 ║   │ ║ data = 3 ║    ┌────┐
║ nextNode─╫───┘ ║ nextNode─╫───┘ ║ nextNode─╫────┤NULL│
╚══════════╝     ╚══════════╝     ╚══════════╝    └────┘
```
- **Delete Node** `where` `value == 3`
```c
    HEAD             TAIL
╔══════════╗     ╔══════════╗
║  Node 1  ║   ┌─╢  Node 2  ║
╟──────────╢   │ ╟──────────╢   
║ data = 7 ║   │ ║ data = 3 ║    ┌────┐
║ nextNode─╫───┘ ║ nextNode─╫────┤NULL│
╚══════════╝     ╚══════════╝    └────┘
```