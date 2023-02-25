# CS210Journal
Upload for CS210 class

Summarize the project and what problem it was solving.
  This project creates a savings account that takes user inputs for initial Value, monthly increase, interest rate, and the length of time in years that the account will gain interest.
    
What did you do particularly well?
   I believe that I broke the program down into chunks of code that made it easier to develop and test by utilizing the SavingsAccount class.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
   There are a few places I could improve. In the loop that gets user inputs for their account the program could infinitely loop due to an error if a character is entered instead of a number value. I recognized this and tried to implement error handling but ultimately left it out due to it not working correctly. In a later project I solved this issue by checking for an error state in cin and then clearing that state while informing the user of the error and how to avoid it. I also could have set a the class variable as the default value for MonthlyIncrease in the getMonthlyInterest and getAnnualBalance functions to avoid needing seperate functions for unique values. This would reduce the code used and by allowing one code to perform both actions while also keeping their declarations the same.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  For this project, the most challenging part was probably getting the interest and balance function to work with the loop in the drawOutputTable function. It was mostly trial and error to get the values to increment correctly. Another thing that I did not overcome in this project itself was mentioned above, the error handling. I overcame that using google and trial and error. Looking at posts with similar issues led me toward cin's fail state and how to clear it. 

What skills from this project will be particularly transferable to other projects or course work?
  This was the first time I worked with class files in C++ outside of our learning material. It helped me with understanding how C++ classes differ from things like Python and Java. 

How did you make this program maintainable, readable, and adaptable?
  The code is seperated into a class, with a header file, and a main file, which helps with readability vs having all of the code in one file. The functions within the class are simple and small, performing one task per function. If the code were to be updated, this helps changing the code without having to change the entire project. There are comments throughout the code explaining what elements of the program do. The code also follows standards provided by the psuedo company that this project was being made for. 

