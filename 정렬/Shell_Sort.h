#pragma once
void shell_sort1(int a[], int n) {// Shell sort알고리즘
	int h = 1;
	int i, j, x;
	while (h < n) { // 증가식
		h = 3 * h + 1;
	}	
	for (; h > 0; h /= 3) {// 감소식
		for (i = h; i < n; i++) { // insertion sort
			x = a[i];
			j = i;
			while (j >= h && a[j - h] > x) {
				a[j] = a[j - h];
				j -= h; // j는 h만큼 감소
			}
			a[j] = x;
		}
	}
}

void shell_sort2(int a[], int n) {// Shell sort알고리즘
	int h = 1;
	int i, j, x;
	while (h < n) {
		h = 3 * h;
	}
	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			x = a[i];
			j = i;
			while (j >= h && a[j - h] > x) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = x;
		}
	}
}

void shell_sort3(int a[], int n) {// Shell sort알고리즘
	int h = 1;
	int i, j, x;
	while (h < n) {
		h = 5 * h + 1;
	}
	for (; h > 0; h /= 5) {
		for (i = h; i < n; i++) {
			x = a[i];
			j = i;
			while (j >= h && a[j - h] > x) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = x;
		}
	}
}

void checkSort(int a[], int n) { // 정렬이 되었는지 확인하는 함수
	int sorted;
	sorted = true;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) { // 만약 앞의 원소가 더 크다면 = 정렬 안됨
			sorted = false;
		}
		if (!sorted) { // sorted가 false이면 탈출
			break;
		}
	}
	if (sorted)
		cout << "정렬 완료.\n";
	else
		cout << "정렬 오류!!.\n";
}

void print_shell_1(int size) {
	clock_t start, end;
	float result;
	cout << "증가식: 3h + 1, 감소식: h/3쉘 정렬 실행 시간 (N - " << size << "): ";
	int* arr = new int[size]; // size만큼 배열 선언
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1; // 1 ~ 100 난수 생성
	}
	start = clock();
	shell_sort1(arr, size); // 증가식1에 대한 shell_sort 알고리즘 수행시간 측정
	end = clock();
	result = (float)(end - start);

	cout << result << "ms\n"; // ms로 출력
	checkSort(arr, size); // 정렬 결과를 체크
	delete[] arr; // 메모리 삭제
}

void print_shell_2(int size) {
	clock_t start, end;
	float result;
	cout << "증가식: 3h, 감소식: h/3쉘 정렬 실행 시간 (N - " << size << "): ";
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1; // 1 ~ 100 난수 생성
	}
	start = clock();
	shell_sort2(arr, size);
	end = clock();
	result = (float)(end - start);

	cout << result << "ms\n";
	checkSort(arr, size);
	delete[] arr;
}

void print_shell_3(int size) {
	clock_t start, end;
	float result;
	cout << "증가식: 5h + 1, 감소식: h/5쉘 정렬 실행 시간 (N - " << size << "): ";
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1; // 1 ~ 100 난수 생성
	}
	start = clock();
	shell_sort3(arr, size);
	end = clock();
	result = (float)(end - start);

	cout << result << "ms\n";
	checkSort(arr, size);
	delete[] arr;
}
