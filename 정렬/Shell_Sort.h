#pragma once
void shell_sort1(int a[], int n) {// Shell sort�˰���
	int h = 1;
	int i, j, x;
	while (h < n) { // ������
		h = 3 * h + 1;
	}	
	for (; h > 0; h /= 3) {// ���ҽ�
		for (i = h; i < n; i++) { // insertion sort
			x = a[i];
			j = i;
			while (j >= h && a[j - h] > x) {
				a[j] = a[j - h];
				j -= h; // j�� h��ŭ ����
			}
			a[j] = x;
		}
	}
}

void shell_sort2(int a[], int n) {// Shell sort�˰���
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

void shell_sort3(int a[], int n) {// Shell sort�˰���
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

void checkSort(int a[], int n) { // ������ �Ǿ����� Ȯ���ϴ� �Լ�
	int sorted;
	sorted = true;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) { // ���� ���� ���Ұ� �� ũ�ٸ� = ���� �ȵ�
			sorted = false;
		}
		if (!sorted) { // sorted�� false�̸� Ż��
			break;
		}
	}
	if (sorted)
		cout << "���� �Ϸ�.\n";
	else
		cout << "���� ����!!.\n";
}

void print_shell_1(int size) {
	clock_t start, end;
	float result;
	cout << "������: 3h + 1, ���ҽ�: h/3�� ���� ���� �ð� (N - " << size << "): ";
	int* arr = new int[size]; // size��ŭ �迭 ����
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1; // 1 ~ 100 ���� ����
	}
	start = clock();
	shell_sort1(arr, size); // ������1�� ���� shell_sort �˰��� ����ð� ����
	end = clock();
	result = (float)(end - start);

	cout << result << "ms\n"; // ms�� ���
	checkSort(arr, size); // ���� ����� üũ
	delete[] arr; // �޸� ����
}

void print_shell_2(int size) {
	clock_t start, end;
	float result;
	cout << "������: 3h, ���ҽ�: h/3�� ���� ���� �ð� (N - " << size << "): ";
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1; // 1 ~ 100 ���� ����
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
	cout << "������: 5h + 1, ���ҽ�: h/5�� ���� ���� �ð� (N - " << size << "): ";
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1; // 1 ~ 100 ���� ����
	}
	start = clock();
	shell_sort3(arr, size);
	end = clock();
	result = (float)(end - start);

	cout << result << "ms\n";
	checkSort(arr, size);
	delete[] arr;
}
