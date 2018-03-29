int f(){
	short y = 5;
	short *x;
	x = &y;
	if (*x < 5){
		return 1;
	}
	else if (*x == 5){
		return 0;
	}
}
