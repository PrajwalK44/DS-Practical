# DS-Practical

**STACK**
**1. Infix to Postfix**
   a) Take a string
   b) while ('\0')
   c) if '(' --> push onto the stack
   d) else if ')' --->
                     1. while stack is not empty or stack!='(' pop into resultant j++
                     2. if top==-1 invalid
                     3. temp=pop(); i++
   e) else if digit or alpha --> directly in resultant i++ j++
   f) if operator then check if stack is not empty and opening paranthesis and getpriority
   g) if stack tops priority is higher than the one  in string pop it into resultant j++.
   h) then push
   i) else incorrect
   j) add null character
   k)to empty the stack pop it into resultant
   l) in getpriority for higher order operators return 1 else return 0

**2. Postfix Evaluation**
   a) Start a while loop on given postfix string
   b) If isdigit then push onto the stack (float)(ans[i)-'0')
   c) else it will be an operation hence pop two values op2 and op1.
   d) using switch carry out operation and store it in a variable 'val', push onto the stack.
   e) i++;
   f) return st[top]

**3. Decimal to binary**
  a) Start whille loop till n=0
  b) push n%2
  c) then n=n/2;
  d)display stack

**4. Paranthesis Checker**
  a) for a given expression till '\0'
  b) if an opening bravket push onto the stack
  c) if there is a closing bracket-->
                                    1. if Stack empty --> flag to 0
                                    2. else pop into temp variable
                                    3. if given closing bracket (from string) then temp shouldnt have any other type of opening bracket (check for '(', '{','[')
  d) outside loop if there is still something there on stack flag=0
  e) now if still flag==1 valid else invalid
  
**QUEUE**
Linear Queue-- Overflow -- rear==MAX-1
               Underflow-- front==-1 || front>rear

Circular Queue-- Overflow --- (rear==MAX-1 && front==0) || (rear==front-1)
                 Underflow--- (rear==front==-1)














