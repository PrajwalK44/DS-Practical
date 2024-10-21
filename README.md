# STACK

### 1. Infix to Postfix

a) Take a string  
b) while (`\0`)  
c) if `'('` --> push onto the stack  
d) else if `')'`  
   1. while stack is not empty or stack != `'('`, pop into resultant, j++  
   2. if top == -1, invalid  
   3. temp = pop(); i++  
e) else if digit or alpha --> directly in resultant i++, j++  
f) if operator, check if stack is not empty and opening parenthesis, and get priority  
g) if stack top's priority is higher than the one in string, pop it into resultant j++  
h) then push  
i) else incorrect  
j) add null character  
k) to empty the stack, pop it into resultant  
l) in get priority, for higher order operators return 1, else return 0  

### 2. Postfix Evaluation

a) Start a while loop on given postfix string  
b) If digit, then push onto the stack `(float)(ans[i]-'0')`  
c) Else, it will be an operation, hence pop two values `op2` and `op1`.  
d) Using switch, carry out the operation and store it in a variable 'val', push onto the stack.  
e) i++  
f) return st[top]  

### 3. Decimal to Binary

a) Start while loop till n=0  
b) push n % 2  
c) then n = n / 2  
d) display stack  

### 4. Parenthesis Checker

a) For a given expression till `\0`  
b) If an opening bracket, push onto the stack  
c) If there is a closing bracket:  
   1. If stack is empty --> flag = 0  
   2. Else pop into temp variable  
   3. If the given closing bracket (from string) doesn’t match the corresponding opening bracket (`'('`, `'{'`, `'['`), it's invalid  
d) Outside the loop, if there’s still something on the stack, flag = 0  
e) Now if flag == 1, it's valid; else, invalid  

# QUEUE

### Linear Queue

- Overflow: `rear == MAX - 1`  
- Underflow: `front == -1 || front > rear`  

### Circular Queue

- Overflow: `(rear == MAX - 1 && front == 0) || (rear == front - 1)`  
- Underflow: `rear == front == -1`

  ### Enqueue in Linear Queue
  a) check for overflow
  b) if inserting the very first element f=r=0
  c) normally `rear++`
  d) `q[rear]=val`

  ### Dequeue in Linear Queue
  a) if empty UNDERFLOW
  b) `val=q[front]`
  c) if(f>r) then `f=-1` and `r=-1`
  d) else `front++`

  ### Enqueue in Circular Queue
  a) check for overflow
  b) if inserting the very first element f=r=0
  c) to adjust rear from last to first
     `if(rear==MAX-1 && front!=0) rear=0`
  d) normal

  ### Dequeue in Circular Queue
  a) Underflow
  b) if front==rear ---empty
  c) adjusting from last to first
     `if (front==MAX-1) front=0;`
  d) else normal front++
  
