#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    vector<int> num;

    while (1) {
        int select; // 사용자가 입력하는 숫자 선언
        int com_num = 0; // 컴퓨터가 입력하는 숫자 초기화

        cout << "개수를 입력하세요 : ";
        cin >> select; //사용자 숫자 입력

        if (select < 1 || select > 3) {
            cout << "1~3 사이의 수를 입력하세요.  "<< endl; //1~3 외의 숫자가 입력되었을 때 출력
            continue;
        }

        if (num.size() + select > 31) {
            cout << "마지막 남은 숫자에 맞게 입력하세요. 현재 총 개수: " << num.size() << endl; // 마지막 31이 초과되지 않게 크기를 31로 제한
            continue;
        }

        cout << "사용자가 부른 숫자!" << endl;
        for (int i = 0; i < select; i++) { // 사용자가 입력한 수만큼 벡터에 push back해서 크기를 출력함으로써 사용자가 입력한 숫자를 표시
            num.push_back(select);
            cout << num.size() << endl;
        }

        if (num.size() >= 31) { // 승패 결정
            int last_input = num.back();

            if (last_input == 31) {
                cout << "게임 종료, 사용자 승" << endl;
            }
            else {
                cout << "게임 종료, 컴퓨터 승" << endl;
            }
            break;
        }

        srand(time(NULL)); // 컴퓨터가 랜덤한 숫자를 입력하게끔 선언
        com_num = rand() % 3 + 1; // 랜덤한 숫자를 1~3으로 제한

        if (num.size() + com_num > 31) {
            com_num = 31 - num.size(); // 컴퓨터가 입력한 숫자가 31이 넘지않게 제한
        }

        cout << "컴퓨터가 부른 숫자!" << endl; // 랜덤한 숫자가 입력되었을때 그 숫자만큼 벡터에 push back해서 크기를 출력함으로써 컴퓨터가 입력한 숫자를 표시
        for (int i = 0; i < com_num; i++) {
            num.push_back(com_num);
            cout << num.size() << endl;
        }

        if (num.size() >= 31) { // 승패 결정
            int last_input = num.back();

            if (last_input == 31) {
                cout << "게임 종료, 컴퓨터 승" << endl;
            }
            else {
                cout << "게임 종료, 사용자 승" << endl;
            }
            break;
        }
    }
    return 0;
}