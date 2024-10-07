package com.vaishakh.lab.coustomer_exception;
class insufficient_fundsException extends Exception{
    public insufficient_fundsException(){
        super();
    }
    public insufficient_fundsException(String messages){
        super(messages);
    }
}
