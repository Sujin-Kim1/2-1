#include <iostream>
#include "Stack.h"

using namespace std;

int Priority(char c) {
    switch (c) {
        case ')':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
}


void toPostfix(Stack * s, char * str, char * result) {
    int i = 0, j = 0;
    s->Push('$');
    char token;
    while (str[i] != '$') {
        token = str[i++];
        if ('0' <= token && token <= '9') {
            result[j++] = token;
        }
        else if (token == '(') {
            s->Push(token);
        }
        else if (token == ')') {
            while (s->Top() != '(')
                result[j++] = s->Pop();
            s->Pop();  // delete '('
        }
        else { // if operator
            if (Priority(s->Top()) <= Priority(token))
                s->Push(token); //Push token
            else { 
                result[j++] = s->Pop();
                s->Push(token); // push token
            }
        }
    }
    while (s->Top() != '$') {
        result[j++] = s->Pop();
    }
}

int eval(char * str) {
    int op1, op2, i = 0;
    int stack[10];
    int top = -1;
    char token = str[i++];
    while (token != '\0') {
        if ('0' <= token && token <= '9') {
            stack[++top] = token - '0';
        }
        else {
            op2 = stack[top--];
            op1 = stack[top--];
            int temp;
            switch (token) {
                case '+':
                    temp = op1 + op2;
                    break;
                case '-':
                    temp = op1 - op2;
                    break;
                case '*':
                    temp = op1 * op2;
                    break;
                case '/':
                    temp = op1 / op2;
                    break;
            }
            stack[++top] = temp;
        }
        token = str[i++];
    }
    return stack[top];
}

int main() {
    Stack s(100);
    char ex[100] = "7*8-(2+3)$";
    char result[100];
    toPostfix(&s, ex, result);
    int i = 0;
    while (result[i] != '\0') {
        cout << result[i++];
    }
    cout << endl;
    cout << eval(result) << endl;
}