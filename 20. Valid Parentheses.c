typedef struct stack stack;


struct stack{
    int value;
    stack *prevptr;  
};


bool isValid(char * s){
    stack *parenthess = NULL;
    int counter = 0;
    if ((int)(s[counter])!=0){
        if (s[counter] == '(' || s[counter] == '[' || s[counter] == '{'){
            parenthess = (stack*)malloc(sizeof(stack));
            (*parenthess).value = (int)(s[counter]);
            (*parenthess).prevptr = NULL;
        } 
        else{
            return false;
        }
        
    }
    counter += 1;
    while((int)(s[counter]) != 0){
        if (s[counter] == '(' || s[counter] == '[' || s[counter] == '{'){
            stack *tmp = (stack*)malloc(sizeof(stack));
            (*tmp).value = (int)(s[counter]);
            (*tmp).prevptr = parenthess;
            parenthess = tmp;
        }else{
            if(parenthess == NULL)
                    return false;
            if(s[counter] == ')'){
                if((char)(parenthess->value) == '('){
                    parenthess = parenthess->prevptr;
                }else{
                    return false;
                }
            }else if(s[counter] == ']'){
                if ((char)(parenthess->value) == '['){
                    parenthess = parenthess->prevptr;
                }else{
                    return false;
                }
            }else if(s[counter] == '}'){
                if ((char)(parenthess->value) == '{'){
                    parenthess = parenthess->prevptr;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        counter += 1;
    }
    if (parenthess == NULL){
        return true;
    }else{
        return false;
    }
}