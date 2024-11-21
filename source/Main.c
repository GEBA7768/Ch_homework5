#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 11

void bubbleSort(int* const array, const int size); //P15
void bubbleSort2(int arr[], int size);
int binarySearch(int arr[], int low, int high, int key);
int cubeByValue(int n);
void cubeByReference(int* nPtr);
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);
void stringReverse(char* str);
int recursiveMaximum(int arr[], int size);
/*//P.05
int main(void)
{
	int a;
	int* aPtr;

	a = 7;
	aPtr = &a;

	printf("The address of a is %p"
		"\nThe value of aPtr is %p", &a, aPtr);

	printf("\n\nThe value of a is %d"
		"\nThe value of *aPtr is %d", a, *aPtr);

	printf("\n\nShowing that * and & are complements of "
		"each other \n&*aPtr = %p"
		"\n*aPtr = %p\n", &*aPtr, *&aPtr);
	system("Pause");
	return 0;
}
*/

/*//P06
int main(void)
{
	int number = 5;
	printf("The original value of number is %d", number);

	number = cubeByValue(number);

	printf("\nThe new value of number is %d\n", number);
	system("Pause");
	return 0;
}
*/

/*//P10
int main()
{
	int number = 5;
	printf("The original value of number is %d", number);

	cubeByReference(&number);

	printf("\nThe new value of number is %d\n", number);
	system("Pause");
	return 0;
}
*/

/*//P13
int main(void)
{
	int a[SIZE] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
	int i;

	printf("Data items in original order\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%4d", a[i]);
	}

	bubbleSort(a, SIZE);

	printf("\nData items in ascending order\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%4d", a[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
*/

/*//P19
int main(void)
{
	int b[] = { 10, 20, 30, 40 };
	int* bPtr = b;
	int i;
	int offset;

	printf("Array b printed with:\nArray subscript notation\n");
	for (i = 0; i < 4; i++)
	{
		printf("b[%d] = %d\n", i, b[i]);
	}

	printf("\nPointer/offset notation where\n"
		"the pointer is the array name\n");
	for (offset = 0; offset < 4; offset++)
	{
		printf("*(b + %d) = %d\n", offset, *(b + offset));
	}

	printf("\nPointer subscript notation\n");
	for (i = 0; i < 4; i++)
	{
		printf("bPtr[%d] = %d\n", i, bPtr[i]);
	}

	printf("\nPointer/offset notation\n");
	for (offset = 0; offset < 4; offset++)
	{
		printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));
	}

	system("pause");
	return 0;
}
*/

/*//P25
int main(void)
{
	const char* suit[4] = { "Hearts","Diamonds","Clubs","Spades" };
	const char* face[13] = { "Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	int deck[4][13] = { 0 };
	srand(time(0));
	shuffle(deck);
	deal(deck, face, suit);
	system("pause");
	return 0;
}
*/

/*
int main()//6.19
{
	int results[13] = { 0 };  // 用來儲存每種點數出現的次數，索引 0 和 1 不使用
	int dice1, dice2, sum;
	int rolls = 36000;  // 模擬投擲次數

	srand(time(0));  // 設定隨機數生成器的種子

	// 模擬投擲骰子
	for (int i = 0; i < rolls; i++) {
		dice1 = rand() % 6 + 1;  // 投擲第一顆骰子，點數範圍 1-6
		dice2 = rand() % 6 + 1;  // 投擲第二顆骰子，點數範圍 1-6
		sum = dice1 + dice2;     // 計算兩顆骰子的點數總和
		results[sum]++;          // 累加該點數的出現次數
	}

	// 印出結果
	printf("點數\t出現次數\t機率\n");
	for (int i = 2; i <= 12; i++) {
		printf("%d\t%d\t\t%.2f%%\n", i, results[i], (results[i] / (float)rolls) * 100);
	}

	return 0;
}
*/

/*//P6.33
int main()
{
	int results[SIZE];  // 用來儲存每種點數出現的次數，索引0對應點數2
	int dice1, dice2, sum;
	int rolls = 36000;  // 模擬投擲次數
	int i, key, index;

	// 初始化results陣列
	for (i = 0; i < SIZE; i++) {
		results[i] = 0;
	}

	srand(time(0));  // 設定隨機數生成器的種子

	// 模擬投擲骰子
	for (i = 0; i < rolls; i++) {
		dice1 = rand() % 6 + 1;  // 投擲第一顆骰子，點數範圍 1-6
		dice2 = rand() % 6 + 1;  // 投擲第二顆骰子，點數範圍 1-6
		sum = dice1 + dice2;     // 計算兩顆骰子的點數總和
		results[sum - 2]++;      // 累加該點數的出現次數，索引從0開始
	}

	// 對results陣列進行排序
	bubbleSort2(results, SIZE);

	// 印出排序後的結果
	printf("排序後的出現次數：\n");
	for (i = 0; i < SIZE; i++) {
		printf("%d ", results[i]);
	}
	printf("\n");

	// 進行二分搜尋
	printf("請輸入要搜尋的出現次數：");
	scanf_s("%d", &key);

	index = binarySearch(results, 0, SIZE - 1, key);

	if (index != -1) {
		printf("出現次數 %d 發現在索引 %d。\n", key, index);
	}
	else {
		printf("出現次數 %d 未在陣列中找到。\n", key);
	}

	return 0;
}
*/

/*//P6.36
int main() {
	char str[100]; // 假設最大字串長度為 99 個字符

	printf("請輸入一個字串：");
	if (fgets(str, sizeof(str), stdin) != NULL) {
		// 去掉換行符，如果有的話
		size_t len = strlen(str);
		if (len > 0 && str[len - 1] == '\n') {
			str[len - 1] = '\0';
		}

		stringReverse(str);
		putchar('\n'); // 打印換行符
	}

	return 0;
}
*/

/*//P6.37
int main() 
{
	int size;

	// 提示使用者輸入陣列的大小
	printf("Enter the number of elements in the array: ");
	scanf_s("%d", &size);

	// 使用 malloc 動態配置陣列
	int* arr = (int*)malloc(size * sizeof(int)); // 配置陣列的記憶體

	if (arr == NULL) {
		// 如果記憶體分配失敗，顯示錯誤訊息並退出程式
		printf("Memory allocation failed.\n");
		return 1;
	}

	// 提示使用者輸入陣列的元素
	printf("輸入陣列元素數目:\n", size);
	for (int i = 0; i < size; i++) {
		printf("元素 %d: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// 呼叫遞迴函式找出最大值並顯示結果
	int max = recursiveMaximum(arr, size);
	printf("陣列中最大的元素是: %d\n", max);

	// 釋放動態分配的記憶體
	free(arr);

	return 0;
}
*/


int cubeByValue(int n)
{
	return n * n * n;
}

void cubeByReference(int* nPtr)
{
	*nPtr = *nPtr * *nPtr * *nPtr;
}


void bubbleSort(int* const array, const int size)//P13
{
	void swap(int* element1Ptr, int* element2Ptr);
	int pass;
	int j;

	for (pass = 0; pass < size - 1; pass++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void swap(int* element1Ptr, int* element2Ptr)//P13
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

void bubbleSort2(int arr[], int size) //P6.33
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// 遞迴的二分搜尋函式
int binarySearch(int arr[], int low, int high, int key) {
	if (low > high) {
		return -1; // 未找到
	}
	else {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid; // 找到，返回索引
		}
		else if (arr[mid] > key) {
			return binarySearch(arr, low, mid - 1, key);
		}
		else {
			return binarySearch(arr, mid + 1, high, key);
		}
	}
}

void shuffle(int wDeck[][13])
{
	int row;
	int column;
	int card;
	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);
		wDeck[row][column] = card;

	}

}

void deal(const int wDeck[][13], const char* wFace[],
	const char* wSuit[])
{
	int card;
	int row;
	int column;

	for (card = 1; card <= 52; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row],
						card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

void stringReverse(char* str) {
	if (*str == '\0') {
		return;
	}
	stringReverse(str + 1);
	putchar(*str);
}

int recursiveMaximum(int arr[], int size) {
	// 基本情況：如果陣列只有一個元素，返回該元素
	if (size == 1) {
		return arr[0];
	}

	// 遞迴查找陣列剩下部分的最大值
	int maxInRest = recursiveMaximum(arr, size - 1);

	// 比較陣列最後一個元素和其餘部分的最大值
	if (arr[size - 1] > maxInRest) {
		return arr[size - 1];
	}
	else {
		return maxInRest;
	}
}
