# printf prototype
This project 

## Installation
You only need to clone this repositories to be able to use this prototype.  
Then you have to add the library in your own program to use the function.
## Usage
To use this function, it has to respect this syntax:  

_printf("string with or without argument", source of the argument to print (1 per argument))  

exemple:  

_printf("this is an exemple") <-------- without any argument you can print a simple string.  
-> This is an exemple <--------------- so this is the output of the function.  

int a = 10  
char b = 'z'  
char *s = "hello"  
  
_printf("%s %c %d", s, b, a) <------- here you can use arguments that you pass after the string (between double quotes "") to variables.  
-> hello z 10  

  -placeholder exemple with more arguments, custom one and also flags and modifiers-  

## Arguments

| arguments           | declaration |   modifiers/flags   | flag        |     description     | 
| :------------------ | :---------: | :-----------------: | :---------: | :------------------ |
| character           |     %c      |                     | +           |                     |
| string              |     %s      |                     | " "         |                     |
| %                   |     %%      |                     | #           |                     |
| integer             |     %d      |         l, h        | Field width |                     |
| integer             |     %i      |         l, h        | Precision   |                     |
| binary              |     %b      |                     | 0           |                     |
| unsigned decimal    |     %u      |         l, h        | -           |                     |
| unsigned octal      |     %o      |         l, h        |             |                     |
| unsigned hexadecimal|     %x      |         l, h        | modifiers   | description         |
| unsigned hexadecimal|     %X      |         l, h        | :---------: | :------------------ |
|                     |     %S      |                     | l           |                     |
| pointer             |     %p      |                     | h           |                     |
| reverse string      |     %r      |                     |
| Rot13 string        |     %R      |                     |  
  
## License
