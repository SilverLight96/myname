#pragma once
#include "OrderList.h"

class OrderManager {
public:
	OrderList myList;
	void start(); // �ֹ� �� ��⿭ �κ� ����
	int menu_orderNlist(); // �ֹ� �� ��⿭ �κ� �޴��� �б�
	void printOrderList(); // ��⿭ ��� �Լ�
	void menu_modifyList(); // ��⿭���� �޴�
	void listCancel(); // ��⿭ ����
	void listFinish(); // ��⿭ �Ϸ�
	void menu_selectDrink(); // �����ֹ� �޴��� �б�
};
void OrderManager::menu_modifyList() {
	string selectMenu;
	while (1) {
		// �޴� 
		cout << "[1] ��⿭ ���" << endl;
		cout << "[2] ��⿭ �Ϸ�" << endl;
		cin >> selectMenu;

		//if (nullRule(selectMenu)) { } // ���ڱ�Ģ Ȯ��
		if (stoi(selectMenu) < 1 || stoi(selectMenu) > 2) { // 1~2 ���� �������� �Ǵ�
			continue;
		}
		break;
	}

	int selectMenu_int = stoi(selectMenu);
	switch (selectMenu_int) {
	case 1: // ��⿭���
		listCancel();
		break;
	case 2: // ��⿭ �Ϸ�
		listFinish();
		break;
	}
}
void OrderManager::listCancel() {  // ��⿭���� >> ��Ҹ޴�
	string cancelNum;
	while (1) {
		cout << "����� ��⿭�� ��ȣ�� �Է����ּ���." << endl;

		cin >> cancelNum;
		//if(nullRule(cancelNum)) { } // ���ڱ�Ģ Ȯ��
		break; // TEST�� �ڵ�
		if (stoi(cancelNum) < 1 || stoi(cancelNum) > myList.size()) { // 1~��⿭�Ѱ��� ���� �������� �Ǵ�
			continue;
		}
		break;
	}
	int cancelNum_int = stoi(cancelNum) - 1;
	OrderNode *cancelNode;
	cancelNode = &myList.get(cancelNum_int);
	/*
	//���⼭ RecipeHandler�� � ��� �󸶳� ���̴��� �˾ƺ���
	//�״��� ResourceManager�� db���� �׸�ŭ ��Ḧ ����ֵ��� ����.
	*/
	myList.del(cancelNum_int);
}
void OrderManager::menu_selectDrink() { // �����ֹ� �޴�
	string drinkCode;
	//int drinkSize=getDrinkSize();  // ������� �� ����
	//printDrinkList(); //��������� ���
	while (1) {
		cout << "���� ������� ��ȣ�� �Է����ּ���." << endl;
		cin >> drinkCode;

		//if(nullRule(drinkCode)) { } // ���ڱ�Ģ Ȯ��
		/*
		if (stoi(drinkCode) < 1 || stoi(drinkCode) > drinkSize) { // 1~�����Ѱ��� ���� �������� �Ǵ�
		   continue;
		}
		break;
		*/
		break; // TEST�� �ڵ�
	}
	int drinkCode_int = stoi(drinkCode);

	/*** ������ ����ðڽ��ϱ� ***/
	string drinkCnt; // ����� ����
	while (1) {
		cout << "���� ���鲨�� : "; // TEST�� �ڵ�
//         cout << "������ ����ðڽ��ϱ�?? (�ִ� " << calMaxCnt(drinkCnt) << "��)" << endl;
		cin >> drinkCnt;

		//if(nullRule(drinkCnt)) { } // ���ڱ�Ģ Ȯ��
		/*
		if(stoi(drinkCnt) < 1 || stoi(drinkCnt) > maxCnt){
		   continue;
		}
		*/
		break; // TEST�� �ڵ�
	}
	int drinkCnt_int = stoi(drinkCnt);
	OrderNode *newNode = new OrderNode(drinkCode_int, drinkCnt_int);

	/*
	// �ش� ��� �������� recipe�� �ִ� (�ش��ȣ�� ��ῡ �ʿ��� �� x ��������� ��) ��ŭ resource.db ����
	*/
	myList.push(newNode);
}
void OrderManager::listFinish() { // ��⿭ ���� >> �Ϸ�޴�
	string finNum;
	while (1) {
		cout << "���� �Ϸ�� ��⿭�� ��ȣ�� �Է����ּ���." << endl;
		cin >> finNum;
		//if(nullRule(finNum)) { } // ���ڱ�Ģ Ȯ��
		break; // TEST�� �ڵ�
		if (stoi(finNum) < 1 || stoi(finNum) > myList.size()) { // 1~��⿭�Ѱ��� ���� �������� �Ǵ�
			continue;
		}
		break;
	}
	int finNum_int = stoi(finNum) - 1;
	myList.del(finNum_int);
}
int OrderManager::menu_orderNlist() { //��⿭ �� �����ֹ� ȭ��
	string selectMenu;
	while (1) {
		printOrderList();  // orderList ���

		/***** �޴� *****/
		cout << "[1] �����ֹ�" << endl;
		cout << "[2] ��⿭����" << endl;
		cout << "[3] �ڷΰ���" << endl;
		cin >> selectMenu;

		//if (nullRule(selectMenu)) { } // ���ڱ�Ģ Ȯ��
		if (stoi(selectMenu) < 1 || stoi(selectMenu) > 3) { // 1~3 ���� �������� �Ǵ�
			continue;
		}
		break;
	}
	int menu = stoi(selectMenu);
	return menu;
}
void OrderManager::printOrderList() { // �ֹ���������Ʈ ��� ���
	for (int i = 1; i <= myList.size(); i++) {
		cout << i << ". [" << myList.get(i - 1).drinkCode << "] " << myList.get(i - 1).drinkCnt << "��" << endl;
	}
	cout << endl;
}
void OrderManager::start() {
	while (1) {
		int menu;
		//���� menu_orderNlist�� �ѹ� ����... ���⼭ ���� ������;;
		menu = menu_orderNlist(); // 1~3 ������ ���ڸ� ���͸�
		switch (menu) {
		case 1: // 1.�����ֹ�
			menu_selectDrink();
			break;
		case 2: //2.��⿭����
			menu_modifyList();
			break;
		case 3: //3.�ڷΰ���
			return; //TEST�� �ڵ� 
			break;
		}
	}
}
