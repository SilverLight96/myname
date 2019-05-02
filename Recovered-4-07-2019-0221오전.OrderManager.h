#pragma once
#include "OrderList.h"

class OrderManager {
public:
	OrderList myList;
	void start(); // 주문 및 대기열 부분 시작
	int menu_orderNlist(); // 주문 및 대기열 부분 메뉴와 분기
	void printOrderList(); // 대기열 출력 함수
	void menu_modifyList(); // 대기열수정 메뉴
	void listCancel(); // 대기열 수정
	void listFinish(); // 대기열 완료
	void menu_selectDrink(); // 음료주문 메뉴와 분기
};
void OrderManager::menu_modifyList() {
	string selectMenu;
	while (1) {
		// 메뉴 
		cout << "[1] 대기열 취소" << endl;
		cout << "[2] 대기열 완료" << endl;
		cin >> selectMenu;

		//if (nullRule(selectMenu)) { } // 숫자규칙 확인
		if (stoi(selectMenu) < 1 || stoi(selectMenu) > 2) { // 1~2 사이 숫자인지 판단
			continue;
		}
		break;
	}

	int selectMenu_int = stoi(selectMenu);
	switch (selectMenu_int) {
	case 1: // 대기열취소
		listCancel();
		break;
	case 2: // 대기열 완료
		listFinish();
		break;
	}
}
void OrderManager::listCancel() {  // 대기열수정 >> 취소메뉴
	string cancelNum;
	while (1) {
		cout << "취소할 대기열의 번호를 입력해주세요." << endl;

		cin >> cancelNum;
		//if(nullRule(cancelNum)) { } // 숫자규칙 확인
		break; // TEST용 코드
		if (stoi(cancelNum) < 1 || stoi(cancelNum) > myList.size()) { // 1~대기열총개수 사이 숫자인지 판단
			continue;
		}
		break;
	}
	int cancelNum_int = stoi(cancelNum) - 1;
	OrderNode *cancelNode;
	cancelNode = &myList.get(cancelNum_int);
	/*
	//여기서 RecipeHandler로 어떤 재료 얼마나 깎이는지 알아보기
	//그다음 ResourceManager로 db에서 그만큼 재료를 깎아주도록 하자.
	*/
	myList.del(cancelNum_int);
}
void OrderManager::menu_selectDrink() { // 음료주문 메뉴
	string drinkCode;
	//int drinkSize=getDrinkSize();  // 음료수의 총 개수
	//printDrinkList(); //음료수종류 출력
	while (1) {
		cout << "만들 음료수의 번호를 입력해주세요." << endl;
		cin >> drinkCode;

		//if(nullRule(drinkCode)) { } // 숫자규칙 확인
		/*
		if (stoi(drinkCode) < 1 || stoi(drinkCode) > drinkSize) { // 1~음료총개수 사이 숫자인지 판단
		   continue;
		}
		break;
		*/
		break; // TEST용 코드
	}
	int drinkCode_int = stoi(drinkCode);

	/*** 몇잔을 만드시겠습니까 ***/
	string drinkCnt; // 만드는 개수
	while (1) {
		cout << "몇잔 만들꺼냐 : "; // TEST용 코드
//         cout << "몇잔을 만드시겠습니까?? (최대 " << calMaxCnt(drinkCnt) << "잔)" << endl;
		cin >> drinkCnt;

		//if(nullRule(drinkCnt)) { } // 숫자규칙 확인
		/*
		if(stoi(drinkCnt) < 1 || stoi(drinkCnt) > maxCnt){
		   continue;
		}
		*/
		break; // TEST용 코드
	}
	int drinkCnt_int = stoi(drinkCnt);
	OrderNode *newNode = new OrderNode(drinkCode_int, drinkCnt_int);

	/*
	// 해당 노드 바탕으로 recipe에 있는 (해당번호의 재료에 필요한 양 x 만드는잔의 수) 만큼 resource.db 수정
	*/
	myList.push(newNode);
}
void OrderManager::listFinish() { // 대기열 수정 >> 완료메뉴
	string finNum;
	while (1) {
		cout << "서빙 완료된 대기열의 번호를 입력해주세요." << endl;
		cin >> finNum;
		//if(nullRule(finNum)) { } // 숫자규칙 확인
		break; // TEST용 코드
		if (stoi(finNum) < 1 || stoi(finNum) > myList.size()) { // 1~대기열총개수 사이 숫자인지 판단
			continue;
		}
		break;
	}
	int finNum_int = stoi(finNum) - 1;
	myList.del(finNum_int);
}
int OrderManager::menu_orderNlist() { //대기열 및 음료주문 화면
	string selectMenu;
	while (1) {
		printOrderList();  // orderList 출력

		/***** 메뉴 *****/
		cout << "[1] 음료주문" << endl;
		cout << "[2] 대기열수정" << endl;
		cout << "[3] 뒤로가기" << endl;
		cin >> selectMenu;

		//if (nullRule(selectMenu)) { } // 숫자규칙 확인
		if (stoi(selectMenu) < 1 || stoi(selectMenu) > 3) { // 1~3 사이 숫자인지 판단
			continue;
		}
		break;
	}
	int menu = stoi(selectMenu);
	return menu;
}
void OrderManager::printOrderList() { // 주문내역리스트 모두 출력
	for (int i = 1; i <= myList.size(); i++) {
		cout << i << ". [" << myList.get(i - 1).drinkCode << "] " << myList.get(i - 1).drinkCnt << "잔" << endl;
	}
	cout << endl;
}
void OrderManager::start() {
	while (1) {
		int menu;
		//여기 menu_orderNlist쪽 한번 보자... 여기서 뭐가 막히네;;
		menu = menu_orderNlist(); // 1~3 사이의 숫자만 필터링
		switch (menu) {
		case 1: // 1.음료주문
			menu_selectDrink();
			break;
		case 2: //2.대기열수정
			menu_modifyList();
			break;
		case 3: //3.뒤로가기
			return; //TEST용 코드 
			break;
		}
	}
}
