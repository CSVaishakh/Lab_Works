#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define size 30
int top =-1;
char stk[100],iexprsn[size],pexprsn[size];


//isFull function
bool isFull(){
    if (top == size-1){
        return true;
    }
    return false;
}
//isEmpty function
bool isEmpty(){
    if (top == -1){
        return true;
    }
    return false;
}
//push function
void  push(char item){
    if(isFull()){ //checks if the stack is full using the above defined isFull() function
        printf("Cannot push elements ans stack is full");
        exit(true);
    }
    else{
        top++;
        stk[top] = item;//if not full element is pushed into the stack
    }
}
//pop function
char pop(){
    if(isEmpty()){//checks if the stack is empty using the above defined isEmpty() function
        printf("Program is terminated as stack is empty");
        exit(true);
    }
    else{
        char item = stk[top];
        top--;//if stack is not full, element is popped by decrementing the top
        return item;
    }
}


bool checkoperator(char symbol){
    if(symbol == '^' || symbol == '*' ||     symbol == '/' || symbol == '+' || symbol == '-'){
        return true;
    }else{
        return false;
    }
}
// assgining precedence
int precedence(char operator){
    if(operator == '^'){
        return 3;
    }else if(operator == '*' || operator =='/'){
        return 2;
    }else if(operator == '+' || operator =='-'){
        return 1;
    }else{
        return 0;
    }
}

//function to convert infix expression to postfix expression
void infixTopostfix(char infixexprsn[size],char postexprsnrsn[size]){
    int i=0,j=0;
    char item,operator;
    
    // pushing '(' to the top of the stack such that it is the first element in the stk
    push('(');

	strcat(iexprsn,")");//concatenates ')' to the infix expression
    item = iexprsn[i];

    while (item !='\0'){
        if (item == '('){
            push(item); //if item ='()'/operators, pushes it into the stack
        }
        else if (isdigit(item) || isalpha(item)){
            //if item is an operand, it is added to the postfix expression
            postexprsnrsn[j] = item;
            j++;
        }
        else if(checkoperator(item)==true){
            operator = pop();
            while(checkoperator(operator)==1 && precedence(operator) >= precedence(item)){
                postexprsnrsn[j] = operator;
                j++;
                operator = pop();
            }
            push(operator);
            push(item);//pushes ther cureent symbol into the stack
        }
        else if(item == ')'){
            operator = pop();
            while(operator != '('){
                postexprsnrsn[j] = operator;
                j++;
                operator = pop();
            }
        }
        else{
            printf("invalid expession");
            getchar();
            exit(1);
        }
        i++;
        item = iexprsn[i];
    }

    if(top>0){
        printf("invalid expession");
            getchar();
            exit(1);
    }
    postexprsnrsn[j] = '\0';
}

//main function
int main(){

printf("\nEnter Infix expression : ");
fgets(iexprsn, size, stdin); //Reads the expression

infixTopostfix(iexprsn, pexprsn); //Calling InfixToPostfix function for conversion

printf("Postfix Expression: ");
puts(pexprsn); //Writes the expression

return 0;
}
