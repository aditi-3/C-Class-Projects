// There is a belief that if at any time a person looks at a digital clock (with standard time), and if the
// digits of the hours and minutes add up equally for the two parts, it is a good time, or a lucky time that
// will predict or is a forecast that whatever you were thinking/ wishing at that instant, might come true.
// For example, 12:03, 12:30, 4:04, 4:13, or 4:31 are considered as lucky times. (Note: In that belief, all
// other times should be viewed as “normal time”.)

// Besides that, three other special times also carry specific meanings:
// • If all digits are the same, like 4:44, 5:55, or 11:11. It predicts you might win a lottery.
// • If all digits are in ascending order, like 3:45, 4:56, or 12:34. It predicts all dreams will come true.
// • If all digits are in descending order, like 3:21, or 6:54. It predicts a challenging road is ahead.

// Write a C++ program that asks the user to enter a time in the format HH:MM (the format is strictly
// required, where the Hour could be either one or two digits. 3 points will be deducted for NOT
// using this format), then the program will tell if the time is a lucky time or just a normal time. And
// then, if the time carries a specific meaning, as described above, the corresponding meaning will be
// displayed along.

// Allow your program continuously run as long as the user wishes to test it at other times.
// Finally, your name as the programmer must be displayed on the screen as well at the end of the
// program (that meant ONE time only at the termination of execution of the program).
// Note: You’re not allowed to hardcode exactly the entered time and its corresponding meaning.
// Input validation: (3 points will be deducted for failing this input validation)
// Don’t accept unreasonable times, or junk values, which must be rejected, with an error message, and
// asked for another one. For example, 3.21, 3x30, 3:60, or 13:23 are considered unreasonable or junk
// values.

// Required Input/Output: (bold and red character(s) for Input)
// Enter a time (HH:MM): 12:56
// 12:56 is a normal time.
// Run again (y/n)? y
// Enter a time (HH:MM): 3:21
// 3:21 is a lucky time. -> DOWN! The challenging road is ahead.
// Run again (y/n)? y
// Enter a time (HH:MM): 4:56
// 4:56 is a normal time. -> UP! All dreams will come true.
// Run again (y/n)? y
// Enter a time (HH:MM): 5:55
// 5:55 is a normal time. -> BINGO! Go to buy a lottery ticket.
// Run again (y/n)? n
// Programmer: Your Full Name
// Goodbye! Press <Enter> key to ending the program...
