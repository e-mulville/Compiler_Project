int main(){
	int y = 5;
	int *x;
	x = &y;
	if (*x < 5){
		return 1;
	}
	else if (*x == 5){
		return 0;
	}
}
