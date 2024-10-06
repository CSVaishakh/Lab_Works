package com.vaishakh.lab.coustom_exception;
class insufficient_fundsException extends Exception{
    public insufficient_fundsException(){
        super();
    }
    public insufficient_fundsException(String messages){
        super(messages);
    }
}
