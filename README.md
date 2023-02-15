# Encryption
Problem description
This is a trivial encryption program which works by
shuffling 70 selected characters in sequence:
 
The encryption scheme is controlled by 3 integers: Width(<=70), Height(<=70) and Skip.
The basic idea is that the scheme wraps the 70 characters (in sequence) above to a
rectangle of dimension WxH in clockwise order starting from the upper-left corner.
(You may assume 70£ W*H, no checking is needed). As an example, if W=12, H=6, S=0:

 
Then the characters are extracted in columns from left to right, top to bottom order
(and skipping all unused blanks):
AfedcbBg432aCh51ZDi6zYEj7)yXFk8(xWGl9?wVHm0!vUIn -uTJo.,tSKpqrsRLMNOPQ

The encryption works by replacing a character from the original sequence to a
character in the new sequence at the same position.

 
For example, ‘B’ (2nd character in the original sequence) is changed to ‘f’ (2nd character
in the new sequence). Likewise, the message “Hello” will be changed to “g8??H”.

The scheme, however has one problem – ‘A’ (upper-left) is always mapped to ‘A’.
Therefore the integer S is introduced. Instead of wrapping the 70 characters directly, each character is considered as being preceded by S unused blanks. (The original
scheme with no blank can be considered as S=0). As an example, if W=36, H=6, S=2:

 
Since S=2, character ‘A’ is preceded by 2 blanks and therefore it’s no longer the first
character. The new sequence (ignoring unused blanks) will be:
ZaxYAybwXBzcvWC1)duVD2(etUE3?fsTF4!grSG5-hqRH6,ipQI7.joPJ8 knOK90lmNLM
We assume 70*(1+S) £ W*H, no checking is needed.

Implementation
We will develop a program based on the template file.
In the file, there is a Codec class with the following private members:

 
The task is to complete the implementation of the following public items:

 
You may add in new variables and functions but you’re not allowed to change the
existing items in the template (e.g. changing the type or count of function input, or
changing public/private settings are not allowed). <string> library and string class are
not allowed. You may use <iostream> , <iomanip> and <cstring> whenever
appropriate.
The program will keep reading single-character commands (in uppercase)
until ‘Q’ (quit) is encountered.
‘C’ command is used to configure the encryption system, with integers W, H and S on
the same line.
‘S’ command is used to display the current setting (which could possibly be changed
by the ‘C’ command). Besides showing W, H, and S, it also displays the 2D matrix and
the new character sequence (of the 70 characters).
‘E’ and ‘D’ commands are used for encryption and decryption respectively. The
message is separated from the ‘E’ / ’D’ command by exactly one space character. The
message length is less than 1000 character and it may contain spaces or characters
outside the selected sequence of 70 characters.



 

 
