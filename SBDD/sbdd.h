#pragma once

#include <map>
#include <vector>

class UniData;
class BoolFunction;

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

		void build(const UniData &data);

	private:
		void buildFunctionPrivate(const BoolFunction &function);
		int buildPrivate(BoolFunction function, int index);

		BoolFunction setZero(BoolFunction function, int index);
		BoolFunction setOne(BoolFunction function, int index);

	private:
		std::map<int, TableStr> table_;
		std::vector<std::string> fNames_;
		std::vector<int> fRoot_;
		int nextNum_;

	};	// class SBDD

}