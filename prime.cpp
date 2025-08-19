// 判斷質數
bool Prime(int n) {
	if (n == 1 || n == 2)return true;
	bool check = true;
	for (int i= 2; i < n; i++) {
		if (n % i == 0)check = false;
	}
	return check;
}
