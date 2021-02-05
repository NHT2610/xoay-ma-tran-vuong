/* Viết chương trình xoay một ma trận (được nhập từ bàn phím), nếu ma trận là một ma phương thì xoay 180 độ,
nếu là ma trận thường thì xoay 90 độ. Biết ma phương là một ma trận có tổng các phần tử trên từng hàng, từng cột, 
đường chéo chính và đường chéo phụ là bằng nhau. */

#include<iostream>
using namespace std;

void fNhapMang(int a[10][10], int& m, int& n);
void fXuatMang(int a[10][10], int& m, int& n);
int fKTMaPhuong(int a[10][10], int& m, int& n);
void fXoayMaTran(int a[10][10], int& m, int& n);
void fDoiCho(int& x, int& y);

int main()
{
	int a[10][10], m = 0, n = 0;
	fNhapMang(a, m, n);
	fXuatMang(a, m, n);
	fXoayMaTran(a, m, n);
	cout << "Mang sau khi xoay" << endl;
	fXuatMang(a, m, n);
}

void fNhapMang(int a[10][10], int& m, int& n)
{
	cout << "Nhap mot ma tran vuong" << endl;
	do
	{
		cout << "Nhap so hang: "; cin >> m;
		cout << "Nhap so cot: "; cin >> n;
	} while (m <= 0 || m > 10 || n <= 0 || n > 10 || m != n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
		}
		cout << endl;
	}
}
void fXuatMang(int a[10][10], int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int fKTMaPhuong(int a[10][10], int& m, int& n)
{
	//Tính tổng các phần tử của hàng đầu tiên 
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + a[0][i];
	}
	//Kiểm tra các tổng của các hàng tiếp theo có bằng sum
	int count = 0;
	for (int i = 1; i < m; i++)
	{
		int sumR = 0;
		for (int j = 0; j < n; j++)
		{
			sumR = sumR + a[i][j];
		}
		if (sumR == sum)
		{
			count = count + 1;
			continue;
		}
		else
		{
			count = 0;
			break;
		}
	}
	//Kiểm tra tổng các cột có bằng sum 
	if (count == 0);
	else
	{
		count = 0;
		for (int i = 0; i < n; i++)
		{
			int sumC = 0;
			for (int j = 0; j < m; j++)
			{
				sumC = sumC + a[j][i];
			}
			if (sumC == sum)
			{
				count = count + 1;
				continue;
			}
			else
			{
				count = 0;
				break;
			}
		}
	}
	//Kiểm tra đường chéo chính và đường chéo phụ có bằng sum
	if (count == 0) return 0;
	else
	{
		int mSum = 0, eSum = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) { mSum = mSum + a[i][j]; }
				if (j == n - 1 - i) { eSum = eSum + a[i][j]; }
			}
		}
		if (mSum == sum && eSum == sum) return 1;
		else return 0;
	}
}
void fDoiCho(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
void fXoayMaTran(int a[10][10], int& m, int& n)
{
	int check = fKTMaPhuong(a, m, n);
	if (check == 1)
	//Ma trận là ma phương => Xoay ma trận 180 độ
	{
		//Đổi chỗ các phần tử trên mỗi hàng 
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				fDoiCho(a[i][j], a[i][n - 1 - j]);
			}
		}
		//Đổi chỗ các phần tử trong cùng một cột (tương đương việc đổi chỗ lại các hàng trong ma trận)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m / 2; j++)
			{
				fDoiCho(a[j][i], a[m - 1 - j][i]);
			}
		}
	}
	else
	//Ma trận không phải là ma phương => Xoay ma trận 90 độ
	{
		int b[10][10], k = n - 1;
		//Gán các cột của ma trận a vào các hàng của ma trận b
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[i][j] = a[j][k - i];
			}
		}
		//Gán lại ma trận b vào ma trận a => ta đã xoay ma trận a 90 độ
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
}