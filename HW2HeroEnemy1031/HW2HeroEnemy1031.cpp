// HW2HeroEnemy1031.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
//#include <cstdlib>
#include "HEclass.h"
using namespace std;

const int MAX_NAME = 16;

int main()
{
	bool turn = false;
	char name[MAX_NAME] = { "" };
	int hp = 0;

	printf("ヒーロー名を入力\n > ");
	cin >> name;
	printf("HPを入力\n > ");
	cin >> hp;

	Hero hero(&name[0], hp);

	// ステータス表示
	hero.show();

	printf("エネミー名を入力\n > ");
	cin >> name;
	printf("HPを入力\n > ");
	cin >> hp;

	Enemy enemy(&name[0], hp);

	// ステータス表示
	enemy.show();


	int select = 0;
	while (true) {
		// プレイヤーターン
		printf("\n攻撃 : 1　, 回復 : 2\n > ");
		cin >> select;

		switch (select)
		{
		case 1:
			hero.attack(&enemy);
			break;
		case 2:
			hero.heal();
			break;
		default:
			break;
		}
		if (enemy.getHp() <= 0) { break; }

		// エネミーターン
		printf("攻撃 : 1　, 回復 : 2\n > ");
		cin >> select;

		switch (select)
		{
		case 1:
			enemy.attack(&hero);
			break;
		default:
			break;
		}
		if (hero.getHp() <= 0) { break; }
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
