int f(int i){
    i=i-1;
    if (i>0)
        return f(i);
    else 
        return 0;
}

int g(){
    return f(5);
}
