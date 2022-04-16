#pragma once
#include <stack>
#include <map>
#include <vector>

class DeadLockProfiler
{
public:
	void PushLock(const char* name);
	void PopLock(const char* name);
	void CheckCycle();

private:
	void Dfs(int32 here);

private:
	unordered_map<const char* , int32 > _nameToId;
	unordered_map<int32 , const char*> _IdToName;
	stack<int>							_lockStack; //���� ��Ȳ�� �Ǻ�.
	//� lock�� ��� ��� lock�� ��Ҵ��� �� �Ǻ��ϴ� ��.
	//ex : 0�� 1���� lock�� ��ҵ��� ���� ������ ��� �δ� ��.
	map<int32, set<int32>>				_lockHistory;

	Mutex	_lock;

private:
	vector<int32>	_discoveredOrder; //��尡 �߰ߵ� ������ ���
	int32			_discoveredCount = 0;// ��尡 �߰ߵ� ����
	vector<bool>	_finished; //dfs(i)�� ����Ǿ����� ����
	vector<int32>	_parent; //�� ���� �迭 ���� 
};
