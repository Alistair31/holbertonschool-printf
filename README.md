# printf prototype
This project is recreation of the function Printf. 

## Installation
You only need to clone this repositories to be able to use this prototype.  
Then you have to add the library in your own program to use the function.
## Usage
To use this function, it has to respect this syntax:  

_printf("string with or without argument", source of the argument to print (1 per argument))  

exemple:  

_printf("this is an exemple") <-------- without any argument you can print a simple string.  
-> This is an exemple <--------------- so this is the output of the function.  



```
int a = 10  
char b = 'z'  
char *s = "hello"  
  
_printf("%s %c %d", s, b, a) <------- here you can use arguments that you pass after the string (between double quotes "") to variables.  
-> hello z 10  

_printf("%s %c %d", s, b, a) <--------- here you can use arguments that you pass  
-> hello z 10                ---------- after the string (between " ") to variables.
```
  -placeholder exemple with more arguments, custom one and also flags and modifiers-  

## Arguments

| arguments           | declaration | definition                     |   modifiers/flags   |     flag    |            description            | 
| :------------------ | :---------: | :----------------------------- | :-----------------: | :---------: | :-------------------------------- |
| character           |     %c      | print a single character       |       l             | +           | put sign of number (+ or -)       |
| string              |     %s      | print a string                 |       l             | " "         | put space before positive numbers |
| %                   |     %%      | print a simple %               |                     | #           | explicit base print (hex or octal |
| integer             |     %d      | print an integer               | +, " ", -, 0, l, h  | Field width | set minimal width                 |
| integer             |     %i      | print an integer               | +, " ", -, 0, l, h  | Precision   | number of character printed       |
| binary              |     %b      | print a binary                 |                     | 0           | print 0 instead of space          |
| unsigned decimal    |     %u      | print a number                 |    -, 0, l, h       | -           | align to the left                 |
| unsigned octal      |     %o      | print an octet                 |   #, -, 0, l, h     |             |                                   |
| unsigned hexadecimal|     %x      | print a hex number (lowercase) |   #, -, 0, l, h     | modifiers   | description                       |
| unsigned hexadecimal|     %X      | print a hex number (uppercase) |   #, -, 0, l, h     | l           | increase the type size ( ->long)  |
|                     |     %S      | print NPRC* to /x"hex" format  |                     | h           | reduce the type size ( ->short)   |
| pointer             |     %p      | print the adresse of pointer   |                     |
| reverse string      |     %r      | print the string in reverse    |                     |
| Rot13 string        |     %R      | print a converted rot13 string |                     |  

  NPRC* : Non PRintable Character (ex: "\n"  ->\<- is a Non PRintable Character)  
  -Not every arguments is included yet-  
## Flowchart
```mermaid
---
config:
  theme: default
  look: neo
---
flowchart TB
    Start@{ label: "_printf('Hello %d!', 42)" } --> Init["Initialisation<br>va_start<br>count=0, i=0"]
    Init --> Loop{"Parcourir<br>format[i]"}
    Loop -- Caractère normal --> Normal["_putchar<br>write(1, &amp;c, 1)"]
    Normal --> AddCount1["count++"]
    AddCount1 --> NextChar["i++"]
    Loop -- Trouve % --> Percent["i++<br>Lire specifier"]
    Percent --> Switch{"Quel<br>type?"}
    Switch -- %c --> Char["va_arg → char<br>_putchar"]
    Switch -- %s --> String["va_arg → char*<br>print_string<br>boucle _putchar"]
    Switch -- %% --> PercentSign@{ label: "_putchar('%')" }
    Switch -- %d ou %i --> Number["va_arg → int<br>print_number"]
    Number --> CheckNeg{"n &lt; 0?"}
    CheckNeg -- Oui --> PrintMinus@{ label: "_putchar('-')<br>num = -n" }
    CheckNeg -- Non --> SetNum["num = n"]
    PrintMinus --> Recursive{"num >= 10?"}
    SetNum --> Recursive
    Recursive -- Oui --> Recurse["print_number<br>num/10<br>RECURSION"]
    Recurse --> Digit@{ label: "_putchar<br>(num%10 + '0')" }
    Recursive -- Non --> Digit
    Char --> AddCount2["count += retour"]
    String --> AddCount2
    PercentSign --> AddCount2
    Digit --> AddCount2
    AddCount2 --> NextChar
    NextChar --> Loop
    Loop -- Fin \\0 --> End["va_end<br>return count"]
    End --> Output["Affichage complet"]

    Start@{ shape: rect}
    PercentSign@{ shape: rect}
    PrintMinus@{ shape: rect}
    Digit@{ shape: rect}
    style Start fill:#FFFFFF
    style Init fill:#FFFFFF
    style Loop fill:#FFFFFF
    style Normal fill:#FFFFFF
    style AddCount1 fill:#FFFFFF
    style NextChar fill:#FFFFFF
    style Percent fill:#FFFFFF
    style Switch fill:#FFFFFF
    style Char fill:#FFFFFF
    style String fill:#FFFFFF
    style PercentSign fill:#FFFFFF
    style Number fill:#FFFFFF
    style CheckNeg fill:#FFFFFF
    style PrintMinus fill:#FFFFFF
    style SetNum fill:#FFFFFF
    style Recursive fill:#FFFFFF
    style Recurse fill:#FFFFFF
    style Digit fill:#FFFFFF
    style AddCount2 fill:#FFFFFF
    style End fill:#FFFFFF,stroke:#FFFFFF
    style Output fill:#FFFFFF
    linkStyle 0 stroke:#FFFFFF,fill:none
    linkStyle 1 stroke:#FFFFFF,fill:none
    linkStyle 2 stroke:#FFFFFF,fill:none
    linkStyle 3 stroke:#FFFFFF,fill:none
    linkStyle 4 stroke:#FFFFFF,fill:none
    linkStyle 5 stroke:#FFFFFF,fill:none
    linkStyle 6 stroke:#FFFFFF,fill:none
    linkStyle 7 stroke:#FFFFFF,fill:none
    linkStyle 8 stroke:#FFFFFF,fill:none
    linkStyle 9 stroke:#FFFFFF,fill:none
    linkStyle 10 stroke:#FFFFFF,fill:none
    linkStyle 11 stroke:#FFFFFF,fill:none
    linkStyle 12 stroke:#FFFFFF,fill:none
    linkStyle 13 stroke:#FFFFFF,fill:none
    linkStyle 14 stroke:#FFFFFF,fill:none
    linkStyle 15 stroke:#FFFFFF,fill:none
    linkStyle 16 stroke:#FFFFFF,fill:none
    linkStyle 17 stroke:#FFFFFF,fill:none
    linkStyle 18 stroke:#FFFFFF,fill:none
    linkStyle 19 stroke:#FFFFFF,fill:none
    linkStyle 20 stroke:#FFFFFF,fill:none
    linkStyle 21 stroke:#FFFFFF,fill:none
    linkStyle 22 stroke:#FFFFFF,fill:none
    linkStyle 23 stroke:#FFFFFF
    linkStyle 24 stroke:#FFFFFF,fill:none
    linkStyle 25 stroke:#FFFFFF,fill:none
    linkStyle 26 stroke:#FFFFFF,fill:none
```
