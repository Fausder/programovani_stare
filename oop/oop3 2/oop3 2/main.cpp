#include <iostream>
#include "KeyValue.h"


using namespace std;


int main()
{
	KeyValue* kv1 = new KeyValue(1, 1.5);
	cout << kv1->CreateNext(2, 2.5)->GetKey() << endl;

	KeyValue* kv2 = kv1->GetNext();
	cout << kv2->GetKey() << endl;

    delete kv1;
    kv1 = nullptr;
    kv2 = nullptr;
    /*
    delete kv2;
    cout << kv1->GetKey() << endl;
    cout << kv2->GetKey() << endl;
    */

    //create loop
	cout << "----------------" << endl;
	cout << "create loop:" << endl;
	KeyValue* prvni = KeyValue::CreateLoop(6);
	delete prvni;
	cout << "----------------" << endl;


	//create recursive
	cout << "create recursive:" << endl;
	KeyValue* novy = KeyValue::CreateRecursive(4);
	delete novy;
    cout << "----------------" << endl;


	//grow loop
	cout << "grow loop:" << endl;
    KeyValue* p1 = new KeyValue(1, 1.5);
    KeyValue* p2 = p1->CreateNext(2, 2.5); 
	KeyValue* p3 = p2->CreateNext(3, 3.5);
	cout << "Puvodni:" << endl;
	p1->Print();

	cout << "Rozsireni:" << endl;
	p1->GrowLoop(p3, 3);
	p1->Print();
	delete p1;
	cout << "----------------" << endl;
	

	//grow recursive
	cout << "grow recursive:" << endl;
	KeyValue* l1 = new KeyValue(1, 1.5);
	KeyValue* l2 = l1->CreateNext(2, 2.5);
	KeyValue* l3 = l2->CreateNext(3, 3.5);
	cout << "Puvodni:" << endl;
	l1->Print();

	cout << "Rozsireni:" << endl;
	l1->GrowRecursive(l3, 3);
	l1->Print();
	delete l1;
	cout << "----------------" << endl;

	//get tail
	cout << "get tail:" << endl;
	KeyValue* m1 = KeyValue::CreateLoop(4);
	cout << "Tail:" << endl;
	KeyValue* tail = KeyValue::GetTail(m1);
	tail->Print();
	delete m1;
	cout << "----------------" << endl;

	//delete at pos
	cout << "delete at pos:" << endl;
	cout << "Puvodni:" << endl;
	KeyValue* o1 = KeyValue::CreateLoop(4);

	cout << "Smazani:" << endl;
	o1->DeleteAtPos(o1, 2);
	o1->Print();
	delete o1;
	cout << "----------------" << endl;
    getchar();


	return 0;
}
