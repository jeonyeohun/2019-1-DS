/*
Include the following line at the top of your every source file with your name signed.
On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Yeo Hun Jeon Section: 03 Student Number: 21500630
*/
//  listnode.cpp
//  Created by idebtor@gmail.com on December 12, 2018.
/*
* Description:	This program implements a simple linked list of nodes
* without a head structure and without sentinel nodes. It simply links
* node to node. The caller is responsible for maintaining the the first
* (head) element of the list. Most functions need the first node to work
* with the list and returns the first node of the list since the first
* may be changed inside of the function.
*/
#include <iomanip>
#include "listnode.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	pNode curr = p;
	while (curr != nullptr) {
		pNode prev = curr;
		curr = curr->next;
		cout << prev->item << " ";
		delete prev;
	}
	cout << "\tcleard \tHappy Coding~~\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	for (pNode c = p; c != nullptr; c = c->next, count++);
	return count;
}

// returns the last node of in the list.
pNode last(pNode p) {
	if (empty(p)) return nullptr;
	while (p->next != nullptr) p = p->next;
	return p;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
pNode push_front(pNode p, int val) {
	DPRINT(cout << "><push_front val=" << val << endl;);
	if (empty(p)){
		return new Node{val, nullptr}; // 리스트에 저장된 노드가 없다면 새로운 노드를 생성.
	}
	return new Node{val, p}; // 새로운 노드를 만들고 새 노드의 next에 현재 리스트의 첫 노드 (p)를 연결해준다.
}

// adds a new node with val at the end of the list and returns the
// first node of the list. This effectively increases the list size by one.
pNode push_back(pNode p, int val) {
	DPRINT(cout << "><push_back val=" << val << endl;);
	// 리스트가 비어있으면 새로운 노드를 만들어 리턴 //
	if (empty(p)){
		return new Node{val, nullptr};
	}
	// 새로운 노드 생성 및 초기화 //
	pNode node = new Node{val, nullptr};
	last(p)->next = node;
	// 첫번째 노드 리턴 //
	return p;
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
pNode push(pNode p, int val, int x) {
	if (empty(p)) return push_front(p, val);
	if (p->item == x) return push_front(p, val);

	pNode curr = p; // 현재 탐색하고 있는 노드
	pNode prev = nullptr; // 이전 탐색했던 노드
	pNode node = new Node{val, nullptr}; // 삽입할 노드 생성

	while(curr->item != x){ // 노드의 item 에 x가 저장되어 있을 때까지 커서를 이동하며 탐색
		prev = curr;	//
		curr = curr->next;
	}
	node->next = curr; // 새로 삽입할 노드의 next에 현재 커서가 가르키는 노드를 연결,
	prev->next = node; // 이전 노드의 next에 새로 만든 노드를 연결

	return p;
}

// adds N number of new nodes at the end of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
// Since it simply calls push_back() repeatedly, it is O(N^2).
pNode push_backN(pNode p, int N) {
	DPRINT(cout << "<push_backN N=" << size(p) << endl;);

	int range = N + size(p);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		int val = rand() % range;
		p = push_back(p, val); // N번 push_back을 하면 맨뒤로 N개만큼 노드가 계속 연결된다.
		cout << setw(7) << "\r\tinserting in [" << i << "]=" << val;
	}
	cout << "\n";

	DPRINT(cout << "<push_backN size=" << size(p) << endl;);
	return p;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by one.
pNode pop_front(pNode p) {
	DPRINT(cout << ">pop_front size=" << size(p) << endl;);

	pNode del = p; // 맨 앞 노드를 새로운 포인터 변수가 가르키게 한다.
	p=p->next; // p를 한 칸 뒤로 이동시킨다. 이제 이 녀석이 새로운 첫번째 노드

	delete del; // del이 가르키는 노드를 삭제한다.
	del = nullptr; // 안정성을 위해 삭제 이후 del에 nullptr 을 저장
	return p;
}

// removes the last node in the list, effectively reducing the
// container size by one. This destroys the removed node.
pNode pop_back(pNode p) {
	DPRINT(cout << ">pop_back size=" << size(p) << endl;);
	if (empty(p)) return nullptr;
	// 하나의 요소만 있을 경우에는 pop_front로 그냥 없애준다 //
	if (p->next == nullptr) {
		pop_front(p);
	}
	// 첫번째 노드를 기억할 포인터, 현재탐색중인 노드의 바로 전 노드를 기억할 포인터 선언 //
	pNode prev = p;
	pNode head = p;

	// 가장 마지막노드와 그 직전 노드 찾기 //
	while(p->next != nullptr){
		prev = p;
		p=p->next;
	}
	// 마지막 노드의 바로 전 노드의 next를 nullptr로 바꿔준다. //
	prev->next = nullptr;
	delete p; // 마지막 노드 삭제
	p = head; // p는 항상 첫번째 노드를 리턴해야한다.
	DPRINT(cout << "<pop_back size=" << size(p) << endl;);
	return p;
}

// deletes N number of nodes, starting from the end.
// It deletes all the nodes if N is zero which is the default or out of
// the range of the list.
// Since it simply calls pop_back() which is O(n) repeatedly, it is O(N^2).
pNode pop_backN(pNode p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);
	// N개의 데이터를 뒤에서부터 지우려면 pop_back 을 N번 반복하면 된다.
	for(int i = 0 ; i < N ; i++){
		p = pop_back(p);
	}
	DPRINT(cout << "<pop_backN size=" << size(p) << endl);
	return p;
}

// removes the first occurrence of the node with val from the list
pNode pop(pNode p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	if (empty(p)) return nullptr;    // nothing to delete
	if (p->item == val) return pop_front(p); // 지우려는 숫자가 리스트의 첫번째 노드에 있다면 pop_front로 삭제한다.

	pNode curr = p; // 현재 탐색중인 노드를 기억한다.
	pNode prev = nullptr; // 현재 탐색하는 노드의 이전노드를 기억.

	// 지우려는 노드 찾기 //
	while(curr->item != val){
		prev = curr;
		curr=curr->next;
	}

	prev->next = curr->next; // 지우려는 노드의 이전노드를 지우려는 노드의 다음 노드와 연결
	delete curr; // 노드 지우기
	curr = nullptr;

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than pmax * 2. If there are more than
// (pmax * 2) nodes, then it shows only pmax number of nodes from
// the beginning and the end in the list.
void show(pNode p, bool all) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	int pmax = 10;   // a magic number, max number of items per line
	pNode curr;
	const int N = size(p);

	// 현재 노드의 개수가 pmax*2 보다 작다면 그냥 전체 노드를 전부 출력
	if (all || N < pmax * 2) { // 모두 보여주기 옵션일 때이거나 다른 옵션일 때도 전체 노드가 pmax*2보다 작을 때
		for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
		return;
	}
	else{
		// print the first pmax items
		for (i = 1, curr=p ; i<=pmax ; i++, curr = curr->next){
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
		cout << "\n...left out...\n";
		// print the last pmax items
		// move the pointer to the place where pmax items are left.
		curr = p;
		// 커서를 전체 노드 개수 - pmax 위치로 이동시킨다.
		for (i=0 ; i<size(p)-pmax ; i++){
			curr = curr->next;
		}
		// pmax 만큼 노드 데이터 출력
		for (i = 1 ; i<=pmax ; i++, curr = curr->next){
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
	}
	cout << "\n";
}
