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
  -Not every arguments is included yet-  (not included are: %b; %o; %x; %X; %S; %p; %R) (%r still in developpement)
## Flowchart
```mermaid
flowchart TB
    Start(["_printf called"]) --> Init["Initialize va_start<br>count=0 i=0"]
    Init --> Loop{"Loop through<br>format i"}
    Loop -- Normal char --> Putchar1["_putchar"]
    Putchar1 --> Inc1["count++ i++"]
    Inc1 --> Loop
    Loop -- Find % --> ReadSpec["i++<br>Read specifier"]
    ReadSpec --> Handle["handle_specifier"]
    Handle --> Switch{"Check type"}
    Switch -- % c --> VaChar["va_arg int"]
    VaChar --> PrintC["_putchar"]
    PrintC --> AddCount["count += return"]
    Switch -- % s --> VaStr["va_arg char ptr"]
    VaStr --> PrintS["print_string<br>loop _putchar"]
    PrintS --> AddCount
    Switch -- %% --> PrintPercent["_putchar %"]
    PrintPercent --> AddCount
    Switch -- % d or i --> VaInt["va_arg int"]
    VaInt --> PrintNum["printnumber"]
    PrintNum --> InitNum["count = 0<br>i = 0<br>buf array"]
    InitNum --> IsNeg{"n less than 0?"}
    IsNeg -- Yes --> Minus["_putchar minus<br>count++"]
    Minus --> ConvertNeg["u = unsigned minus n"]
    IsNeg -- No --> ConvertPos["u = unsigned n"]
    ConvertNeg --> CheckZero{"u equals 0?"}
    ConvertPos --> CheckZero
    CheckZero -- Yes --> PrintZero["_putchar zero<br>return count+1"]
    PrintZero --> AddCount
    CheckZero -- No --> FillBuffer["While u greater 0:<br>buf i++ = zero + u mod 10<br>u divide 10"]
    FillBuffer --> PrintBuffer["While i greater 0:<br>_putchar buf minus minus i<br>count++"]
    PrintBuffer --> RetNum["return count"]
    RetNum --> AddCount
    AddCount --> Inc2["i++"]
    Inc2 --> Loop
    Loop -- End null --> Cleanup["va_end"]
    Cleanup --> Return["return count"]
    Return --> End(["End"])

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
    linkStyle 23 stroke:#FFFFFF,fill:none
    linkStyle 24 stroke:#FFFFFF,fill:none
    linkStyle 25 stroke:#FFFFFF,fill:none
    linkStyle 26 stroke:#FFFFFF,fill:none
    linkStyle 27 stroke:#FFFFFF,fill:none
    linkStyle 28 stroke:#FFFFFF,fill:none
    linkStyle 29 stroke:#FFFFFF,fill:none
    linkStyle 30 stroke:#FFFFFF,fill:none
    linkStyle 31 stroke:#FFFFFF,fill:none
    linkStyle 32 stroke:#FFFFFF,fill:none
    linkStyle 33 stroke:#FFFFFF,fill:none
    linkStyle 34 stroke:#FFFFFF,fill:none
    linkStyle 35 stroke:#FFFFFF,fill:none
```
## Roadmap
```mermaid
---
config:
  theme: default
  look: neo
---
flowchart TB
    C["printbinary (%b)"] --> n1["print_unsigned_octal (%o)"] & n11["print_unsigned_lwhex (%x)"] & n12["print_unsigned_uphex (%X)"]
    n11 --> n13@{ label: "set buffer for 'write'" }
    n1 --> n13
    n12 --> n13
    n13 --> n14["print_nprc_in_hex (%S)"]
    n14 --> n15["print_adress (%p)"]
    n15 --> n16@{ label: "add flag '+'" } & n17@{ label: "add flag ' ' (space)" } & n18@{ label: "add flag '#'" }
    n20@{ label: "add modifier 'l'" } --> n22@{ label: "add flag 'field width'" }
    n21@{ label: "add modifier 'h'" } --> n22
    n22 --> n23@{ label: "add flag 'precision'" }
    n23 --> n24@{ label: "add flag '0'" }
    n24 --> n25@{ label: "add flag '-'" }
    n25 --> n26["printreverse (%r)"]
    n26 --> n27["print_rot (%R)"]
    n18 --> n28["<br>"]
    n17 --> n28
    n16 --> n28
    n28 --> n20 & n21

    n13@{ shape: rect}
    n16@{ shape: rect}
    n17@{ shape: rect}
    n18@{ shape: rect}
    n20@{ shape: rect}
    n22@{ shape: rect}
    n21@{ shape: rect}
    n23@{ shape: rect}
    n24@{ shape: rect}
    n25@{ shape: rect}
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
    linkStyle 17 stroke:#FFFFFF
    linkStyle 18 stroke:#FFFFFF,fill:none
    linkStyle 19 stroke:#FFFFFF,fill:none
    linkStyle 20 stroke:#FFFFFF,fill:none
    linkStyle 21 stroke:#FFFFFF,fill:none
    linkStyle 22 stroke:#FFFFFF,fill:none
```
