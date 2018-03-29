int f(){
	int x = 0;
start:
	x++;
	if (x < 5){
		goto start;
	}
	if (x == 5){
		return 0;
	}
	return 1;
}
