#pragma once

#include <map>

namespace sbdd {

	// ��������� ��� ������������� ������� �������.
	struct TableStr {
		int index;
		int left;
		int right;

		TableStr(int i = -1, int l = -1, int r = -1) { index = i; left = l; right = r; }

		bool operator == (const TableStr &tableStr)
		{
			if (index == tableStr.index && left == tableStr.left && right == tableStr.right) {
				return true;
			}
			else
				return false;
		}
	};

	class SBDD
	{
	public:
		// ���� constant = false, �� ����� ������ SBDD = 0, ����� 1.
		SBDD(bool constant = false);
		SBDD(const SBDD &sbdd);

		// ������� ��������.
		// ���������� �� ������ ���� � �������.
		bool member(const TableStr &tableStr);
		// ���������� ����� ���� � �������, ���� ������ ���� ��� �� -1.
		int lookup(const TableStr &tableStr);
		// ��������� ���� � ������� � ���������� ��� �����.
		int insert(const TableStr &tableStr);
		// ������� � ��������� ���� ����� ����� ����.
		int makeNode(int index, int left, int right);


	private:
		std::map<int, TableStr> table_;
		int nextNum_;

	};	// class SBDD

}