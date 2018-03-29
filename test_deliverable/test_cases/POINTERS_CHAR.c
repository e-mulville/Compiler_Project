int f(){
	char y = '5';
	char *x;
	x = &y;
	if (*x != '5'){
		return 1;
	}
	else if (*x == '5'){
		return 0;
	}
}
