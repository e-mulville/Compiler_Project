#include <stdlib.h>
#include <string.h>

int main(){
    char str[] = "3.14";
    float val;
    val = atof(str);
    if( val==3.14 ){
        return 0;
    }
    return 1;
}
